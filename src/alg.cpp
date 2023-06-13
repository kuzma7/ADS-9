// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    std::string word;
    char ch;

    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
        } else if (!word.empty()) {
            tree.add(word);
            word.clear();
        }
    }

    file.close();
    return tree;
}
