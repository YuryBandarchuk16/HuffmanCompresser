//
// Created by Юрий Бондарчук on 4/19/17.
//

#include "HuffmanCompresser.h"
#include <string.h>
#include <cstdlib>

void HuffmanCompresser::AbstractCompresserData::init() {
    vertex_count = 0;
    for (int i = 0; i < MAX_VERTEX_NUMBER; ++i) {
        left_son[i] = right_son[i] = values[i] = -1;
    }
}

HuffmanCompresser::AbstractCompresserData::AbstractCompresserData() {
}

void HuffmanCompresser::AbstractCompresserData::init_table(int current_vertex, std::vector<bool> &path) {
    if (left_son[current_vertex] == -1 && right_son[current_vertex] == -1) {
        for (size_t i = 0; i < path.size(); ++i) {
            bool tmp = path[i];
            table[current_vertex - 1].push_back(tmp);
        }
        return;
    }
    if (left_son[current_vertex] != -1) {
        path.push_back(false);
        init_table(left_son[current_vertex], path);
        path.pop_back();
    }
    if (right_son[current_vertex] != -1) {
        path.push_back(true);
        init_table(right_son[current_vertex], path);
        path.pop_back();
    }
}

void HuffmanCompresser::AbstractCompresserData::build_tree() {
    std::priority_queue< std::pair<int, int> > pq;
    vertex_count = 0;
    for (int i = 0; i < MAX_CODE; ++i) {
        pq.push(std::make_pair(accumulator.frequency[i], ++vertex_count));
    }
    std::pair<int, int> fp;
    std::pair<int, int> sp;
    while (pq.size() > 1) {
        fp = pq.top();
        pq.pop();
        sp = pq.top();
        pq.pop();
        int new_vertex_id = ++vertex_count;
        int new_frequency_value = fp.first + sp.first;
        left_son[new_vertex_id] = fp.second;
        right_son[new_vertex_id] = sp.second;
        pq.push(std::make_pair(new_frequency_value, new_vertex_id));
    }
    if (pq.size() == 1) {
        pq.pop();
    }
    std::vector<bool> vector_for_path;
    init_table(vertex_count, vector_for_path);
}

void HuffmanCompresser::Coder::get_tree(std::vector<int> &encoded_tree) {
    encoded_tree.clear();
    for (int code = 0; code < MAX_CODE; ++code) {
        encoded_tree.push_back(accumulator.frequency[code]);
    }
}

void HuffmanCompresser::Coder::encode(const std::vector<unsigned char> &message,
                                      std::vector<unsigned char> &encoded_message) {
    encoded_message.clear();
    std::vector<bool> almost_encoded_message;
    for (size_t i = 0; i < message.size(); ++i) {
        int code = static_cast<int>(message[i]);
        for (size_t j = 0; j < table[code].size(); ++j) {
            bool tmp = table[code][j];
            almost_encoded_message.push_back(tmp);
        }
    }
    for (size_t i = 0; i < almost_encoded_message.size(); i += 8) {
        int value = 0;
        int current_power_of_two = (1 << 7);
        for (size_t j = i; j < i + 8 && j < almost_encoded_message.size(); ++j) {
            if (almost_encoded_message[j]) {
                value += current_power_of_two;
            }
            current_power_of_two >>= 1;
        }
        encoded_message.push_back(static_cast<unsigned char>(value));
    }

}

HuffmanCompresser::Coder::~Coder() {
    for (int i = 0; i <= MAX_CODE; ++i) {
        table[i].clear();
    }
}

HuffmanCompresser::Coder::Coder(const HuffmanCompresser::frequencies_accumulator &accumulator) {
    init();
    this -> accumulator = frequencies_accumulator();
    for (int i = 0; i < MAX_CODE; ++i) {
        this -> accumulator.frequency[i] = accumulator.frequency[i];
    }
    build_tree();
}


HuffmanCompresser::Decoder::~Decoder() {
    while (buff.size() > 0) buff.pop();
}

std::pair<bool, unsigned char> HuffmanCompresser::Decoder::get_next_decoded_character(bool need, unsigned char value) {
    if (need) {
        int int_value = static_cast<int>(value);
        for (int i = 7; i >= 0; --i) {
            bool f = (int_value & (1 << i)) != 0;
            buff.push(f);

        }
    }
    last_vertex = (last_vertex == -1 ? vertex_count : last_vertex);
    while (!buff.empty()) {
        bool nxt = buff.front();
        buff.pop();
        if (!nxt) {
            last_vertex = left_son[last_vertex];
        } else {
            last_vertex = right_son[last_vertex];
        }
        if (left_son[last_vertex] == right_son[last_vertex] && left_son[last_vertex] == -1) {
            unsigned char result = static_cast<unsigned char>(last_vertex - 1);
            last_vertex = -1;
            return std::make_pair(true, result);
        }
    }
    return std::make_pair(false, 0);
}

void HuffmanCompresser::Decoder::clear_buff() {
    while (buff.size() > 0) buff.pop();
}

HuffmanCompresser::Decoder::Decoder(const std::vector<int> &leafs_frequency) {
    init();
    last_vertex = -1;
    for (size_t i = 0; i < leafs_frequency.size(); i++) {
        accumulator.frequency[i] = leafs_frequency[i];
    }
    build_tree();
}

void HuffmanCompresser::frequencies_accumulator::add_string(const std::vector<unsigned char> &string) {
    for (size_t i = 0; i < string.size(); ++i) {
        --frequency[string[i]];
    }
}

HuffmanCompresser::frequencies_accumulator&
HuffmanCompresser::frequencies_accumulator::operator=(const HuffmanCompresser::frequencies_accumulator &a) {
    for (int i = 0; i < MAX_CODE; ++i) {
        frequency[i] = a.frequency[i];
    }
    return *this;
}

HuffmanCompresser::frequencies_accumulator::frequencies_accumulator() {
    for (int i = 0; i < MAX_CODE; ++i) {
        frequency[i] = 0;
    }
}
