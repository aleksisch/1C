#pragma once

#include <unordered_map>
#include <queue>
#include <memory>

template <typename T>
class Trie {
    struct vertex {
        vertex(T value) : value(std::move(value)) {}
        T value;
        std::unordered_map<char, std::shared_ptr<vertex>> next;
    };
    std::shared_ptr<vertex> root;
public:
    explicit Trie(const std::vector<std::string>& inputStr = std::vector<std::string>()) {
        root = std::make_shared<vertex>(T());
    }

    void Add(const std::string& addStr, T value) {
        std::shared_ptr<vertex> currentNode = root;
        int currentIndex = 0;
        for (const auto &letter : addStr) {
            if (currentNode->next.count(letter) == 0) {
                auto tmp = std::make_shared<vertex>(value);
                currentNode->next[letter] = tmp;
            }
            currentNode = currentNode->next[letter];
        }
    }

    std::optional<T> Has(const std::string& checkStr) {
        std::shared_ptr<vertex> currentState = root;
        for (char i : checkStr) {
            if (currentState->next.count(i) == 0) {
                return std::nullopt;
            }
            currentState = currentState->next[i];
        }
        return currentState->value;
    }
};
