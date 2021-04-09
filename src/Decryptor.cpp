#include <fstream>
#include <sstream>
#include "Decryptor.hh"

Decryptor::Decryptor(const std::string& filename, int max_key_size) : max_key_size_(max_key_size) {
    std::ifstream f(filename);
    std::deque<std::string> words;
    int word_number = 0;
    while (f) {
        std::string current_word;
        f >> current_word;
        words.emplace_front(std::string(1, current_word[0]));
        if (current_word.size() > words.size()) {
            current_word = current_word.substr(0, words.size());
        }
        for (int i = 1; i < current_word.size(); i++) {
            words[i] += current_word[i];
        }
        for (const auto &word : words) {
            trie_.Add(word, word_number);
        }
        if (words.size() == max_key_size) {
            words.pop_back();
        }
        ++word_number;
    }
}

size_t Decryptor::GetValue(const std::string& key) {
    auto res = trie_.Has(key);
    if (!res) {
        return -1;
    } else {
        return *res - key.size() + 2;
    }
}
