#pragma once

#include <iostream>
#include <vector>
#include "Trie.hpp"

class Decryptor {
public:
    Decryptor(const std::string& filename, int max_key_size);
    size_t GetValue(const std::string& key);

private:
    Trie<int> trie_;
    const int max_key_size_;
};
