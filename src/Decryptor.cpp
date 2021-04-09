#include <fstream>
#include <sstream>
#include "Decryptor.hh"

Decryptor::Decryptor(const std::string& filename, int max_key_size) : max_key_size_(max_key_size) {
    std::ifstream f(filename);
    std::deque<std::string> words;
    word_number = 1;
    while (f) {
        std::string current_word;
        f >> current_word;
        words.emplace_back(current_word);
        if (words.size() == max_key_size_) {
            InsertWord(words);
        }
    }
    while (!words.empty()) {
        InsertWord(words);
    }
}

void Decryptor::InsertWord(std::deque<std::string>& words) {
    std::string res;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].size() < i) {
            break;
        }
        res += words[i][i];
    }
    trie_.Add(res, word_number);
    word_number++;
    words.pop_front();
}

long long Decryptor::GetValue(const std::string& key) {
    auto res = trie_.Has(key);
    if (!res) {
        return -1;
    } else {
        return *res;
    }
}
