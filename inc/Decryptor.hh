#pragma once

#include <iostream>
#include <vector>
#include <Trie.hpp>

class Decryptor {
public:
    Decryptor(const std::string& filename, int max_key_size);
    long long GetValue(const std::string& key);

private:
    Trie<long long> trie_;
    const int max_key_size_;
    int word_number;
    void InsertWord(std::deque<std::string> &deque);
};
