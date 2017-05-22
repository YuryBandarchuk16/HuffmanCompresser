//
// Created by Юрий Бондарчук on 4/29/17.
//

#ifndef COMPRESSER_FILEWORKER_H
#define COMPRESSER_FILEWORKER_H


#include <cstdio>
#include <vector>
#include <stdexcept>

class FileWorker {
private:
    enum TYPE {
        WRITING,
        READING
    };
    const char * file_name;
    FILE * file;
    TYPE type;
public:
    FileWorker(const char * file_name, const char * mode);
    ~FileWorker();
    void append_int(int x, bool need_endl);
    bool read_block(size_t max_block_size, std::vector<unsigned char> &message);
    template <typename T> int next_token(T &token, const char * spec);
    template <typename T> void append_message(std::vector<T> &message, bool need_endl, const char *spec);
};


#endif //COMPRESSER_FILEWORKER_H
