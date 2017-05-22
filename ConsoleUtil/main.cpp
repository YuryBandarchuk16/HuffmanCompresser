//
// Created by Юрий Бондарчук on 4/19/17.
//

#include "../HuffmanCompresser/HuffmanCompresser.h"
#include "FileWorker.h"
#include <iostream>
#include <string.h>

static void compress(const char * input_file_name, const char * output_file_name) {
    printf("compress mode....\n");
    printf("Characters in one block: %lu\n", HuffmanCompresser::CONSECUTIVE_CHARS);
    int total_length = 0;
    HuffmanCompresser::frequencies_accumulator accumulator;
    std::vector<unsigned char> message;
    {
        FileWorker input_file(input_file_name, "rb");
        int blocks_added = 0;
        while (input_file.read_block((size_t)HuffmanCompresser::CONSECUTIVE_CHARS, message)) {
            accumulator.add_string(message);
            total_length += (int) message.size();
            printf("blocks added: %d\n", ++blocks_added);
        }
    }
    HuffmanCompresser::Coder encoder(accumulator);
    FileWorker input_file(input_file_name, "rb");
    FileWorker output_file(output_file_name, "wb");
    std::vector<unsigned char> encoded_message;
    std::vector<int> encoded_tree;
    encoder.get_tree(encoded_tree);
    output_file.append_int(total_length, true);
    output_file.append_message(encoded_tree, true, "%d");
    int blocks_read = 0;
    while (input_file.read_block((size_t)HuffmanCompresser::CONSECUTIVE_CHARS, message)) {
        encoder.encode(message, encoded_message);
        output_file.append_message(encoded_message, false, "%c");
        printf("blocks processed: %d\n", ++blocks_read);
    }
}

static void decompress(const char * input_file_name, const char * output_file_name) {
    printf("decompress mode....\n");
    printf("Characters in one block: %lu\n", HuffmanCompresser::CONSECUTIVE_CHARS);
    int total_length;
    std::vector<int> frequencies;
    FileWorker input_file = FileWorker(input_file_name, "rb");
    int cnt_read = input_file.next_token(total_length, "%d");
    if (total_length < 0 || cnt_read == 0) {
        throw std::invalid_argument("the first line should contain non-negative integer: the overall length of encoded file");
    }
    int calculated_total_length = 0;
    for (int i = 0; i < HuffmanCompresser::MAX_CODE; ++i) {
        int x;
        cnt_read = input_file.next_token(x, "%d");
        if (cnt_read == 0) {
            throw std::invalid_argument("invalid file to decompress");
        }
        if (x > 0) {
            throw std::logic_error("frequency should be not greater than zero");
        }
        calculated_total_length -= x;
        frequencies.push_back(x);
    }
    if (calculated_total_length != total_length) {
        throw std::logic_error("the given sum of frequency in the beginning of the file does not equal to absolute value of sum of frequenices");
    }
    unsigned char next_line;
    input_file.next_token(next_line, "%c");
    if (next_line != '\n') {
        throw std::invalid_argument("invalid file to decompress");
    }
    HuffmanCompresser::Decoder decoder(frequencies);
    FileWorker output_file = FileWorker(output_file_name, "wb");
    std::vector<unsigned char> message;
    while (total_length > 0) {
        int can_process = HuffmanCompresser::CONSECUTIVE_CHARS;
        unsigned char code;
        bool end_of_file = false;
        while (can_process > 0) {
            std::pair<bool, unsigned char> tmp;
            while (can_process > 0 && total_length > 0) {
                tmp = decoder.get_next_decoded_character(false, 0);
                if (tmp.first) {
                    --can_process;
                    --total_length;
                    message.push_back(tmp.second);
                } else {
                    break;
                }
            }
            if (can_process == 0 || total_length == 0) {
                decoder.clear_buff();
                break;
            }
            if (input_file.next_token(code, "%c") > 0) {
                tmp = decoder.get_next_decoded_character(true, code);
                if (tmp.first) {
                    --can_process;
                    --total_length;
                    message.push_back(tmp.second);
                }
            } else {
                end_of_file = true;
                break;
            }
            if (can_process == 0 || total_length == 0) {
                decoder.clear_buff();
                break;
            }
        }
        output_file.append_message(message, false, "%c");
        message.clear();
        if (end_of_file || total_length == 0) {
            break;
        }
    }
    if (total_length > 0) {
        throw std::logic_error("the overall amount of characters decoded does not equal to sum of frequecnies given in the first line of the file");
    }
}

static void check_files(char const * input_file_name, char const * output_file_name) {
    try {
        FileWorker input_file = FileWorker(input_file_name, "rb");
        FileWorker output_file = FileWorker(output_file_name, "wb");
    } catch (const std::invalid_argument& e) {
        throw;
    }
}

int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("wrong number of arguments : <input_file> <output_file> <mode = cm|dm>\n");
        return 0;
    }
    char const * mode = argv[3];
    char const * input_file_name = argv[1];
    char const * output_file_name = argv[2];
    try {
        check_files(input_file_name, output_file_name);
    } catch (std::invalid_argument e) {
        printf("some error occured while opening files\n");
        return 0;
    }
    if (strlen(mode) == 2 && strncmp(mode, "cm", 2) == 0) {
        compress(input_file_name, output_file_name);
        printf("successfully compressed from file %s to file %s", input_file_name, output_file_name);
    } else if (strlen(mode) == 2 && strncmp(mode, "dm", 2) == 0) {
        try {
            decompress(input_file_name, output_file_name);
        } catch (const std::invalid_argument& e) {
            printf("wrong format of file, impossible to decompress\n");
            std::cout << e.what() << std::endl;
            return 0;
        } catch (const std::logic_error& e) {
            std::cout << e.what() << std::endl;
            return 0;
        }
        printf("successfully decompressed from file %s to file %s\n", input_file_name, output_file_name);
    } else {
        printf("unknown mode\n");
    }
    return 0;
}