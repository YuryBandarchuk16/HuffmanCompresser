//
// Created by Юрий Бондарчук on 4/19/17.
//

#ifndef COMPRESSER_HUFFMANCOMPRESSER_H
#define COMPRESSER_HUFFMANCOMPRESSER_H

#include <vector>
#include <queue>

namespace HuffmanCompresser {

    const int MAX_CODE = 256;
    const size_t CONSECUTIVE_CHARS = 10000 * 10000 + 5;

    struct frequencies_accumulator {
        frequencies_accumulator();
        void add_string(const std::vector<unsigned char> &string);
        int frequency[MAX_CODE];
        frequencies_accumulator& operator=(frequencies_accumulator const&a);
    };

    class AbstractCompresserData {
    public:
        AbstractCompresserData();
    protected:
        void build_tree();
        frequencies_accumulator accumulator;
        static const int MAX_VERTEX_NUMBER = 2 * MAX_CODE + 1;
        int vertex_count;
        int values[MAX_VERTEX_NUMBER];
        int left_son[MAX_VERTEX_NUMBER];
        int right_son[MAX_VERTEX_NUMBER];
        std::vector<bool> table[MAX_CODE];
        void init_table(int current_vertex, std::vector<bool> &path);
        void init();
    private:
    };


    class Coder : public AbstractCompresserData {
    private:
    public:
        Coder(frequencies_accumulator const& accumulator);
        ~Coder();
        void get_tree(std::vector<int> &encoded_tree);
        void encode(const std::vector<unsigned char> &message, std::vector<unsigned char> &encoded_message);
    };

    class Decoder : private AbstractCompresserData {
    private:
        int last_vertex;
        std::queue<bool> buff;
    public:
        Decoder(const std::vector<int> &leafs_frequency);
        ~Decoder();
        void clear_buff();
        std::pair<bool, unsigned char> get_next_decoded_character(bool need, unsigned char value);
    };
}

#endif //COMPRESSER_HUFFMANCOMPRESSER_H
