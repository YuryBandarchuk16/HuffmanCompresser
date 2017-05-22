//
// Created by Юрий Бондарчук on 4/29/17.
//

#include "FileWorker.h"
#include <cstring>

FileWorker::FileWorker(const char *file_name, const char *mode) {
    file = fopen(file_name, mode);
    this -> file_name = file_name;
    if (file == NULL) {
        if (mode[0] == 'r') {
            throw std::invalid_argument("error while reading file");
        } else {
            throw std::invalid_argument("error while creating file");
        }
    }
    if (mode[0] == 'r') {
        this -> type = READING;
    } else {
        this -> type = WRITING;
    }
}

bool FileWorker::read_block(size_t max_block_size, std::vector<unsigned char> &message) {
    if (this -> type == WRITING) {
        throw std::invalid_argument((std::strcat((char *)this -> file_name, " is not for reading")));
    }
    message.clear();
    unsigned char next_char;
    while (fscanf(file, "%c", &next_char) > 0) {
        message.push_back(next_char);
        if (message.size() == max_block_size) {
            break;
        }
    }
    return message.size() > 0;
}

FileWorker::~FileWorker() {
    fclose(file);
}

void FileWorker::append_int(int x, bool need_endl) {
    if (this -> type == READING) {
        throw std::invalid_argument((std::strcat((char *)this -> file_name, " is not for writing")));
    }
    fprintf(file, "%d", x);
    if (need_endl) {
        fprintf(file, "\n");
    }
}

template<typename T>
void FileWorker::append_message(std::vector<T> &message, bool need_endl, const char *spec) {
    if (this -> type == READING) {
        throw std::invalid_argument((std::strcat((char *)this -> file_name, " is not for writing")));
    }
    for (size_t i = 0; i < message.size(); ++i) {
        fprintf(file, spec, message[i]);
        if (need_endl) {
            fprintf(file, "\n");
        }
    }
}

template<typename T>
int FileWorker::next_token(T &token, const char * spec) {
    if (this -> type == WRITING) {
        throw std::invalid_argument((std::strcat((char *)this -> file_name, " is not for reading")));
    }
    T code;
    int result = fscanf(file, spec, &code);
    if (result > 0) {
        token = code;
    }
    return result;
}

template int FileWorker::next_token(int &token, const char *spec = "%d");
template int FileWorker::next_token(unsigned char &token, const char *spec = "%c");
template void FileWorker::append_message(std::vector<int> &message, bool need_endl, const char *spec = "%d");
template void FileWorker::append_message(std::vector<unsigned char> &message, bool need_endl, const char *spec = "%c");



