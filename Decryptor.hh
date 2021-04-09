#pragma once

#include <iostream>
#include <vector>
#include "Trie.hpp"

class Decryptor {
public:
    Decryptor(const std::string& filename, int max_key_size);
    int GetValue(const std::string& key);

private:
    Trie<int> trie_;
    std::unordered_map<std::string, int> map_;
    const int max_key_size_;
};
