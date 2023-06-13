// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>

template<typename T>
class BST {
private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;

        explicit Node(const T& val)
            : value(val), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* addNode(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = addNode(node->left, value);
        } else if (value > node->value) {
            node->right = addNode(node->right, value);
        } else {
            node->count++;
        }

        return node;
    }

    int searchT(const Node* node, const T& value) const {
        if (node == nullptr) {
            return 0;
        }

        if (value < node->value) {
            return searchT(node->left, value);
        } else if (value > node->value) {
            return searchT(node->right, value);
        } else {
            return node->count;
        }
    }

    int depth(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }

        return 1 + std::max(depth(node->left), depth(node->right));
    }

public:
    BST() : root(nullptr) {}

    void add(const T& value) {
        root = addNode(root, value);
    }

    int depth() const {
        if (root == nullptr) {
            return 0;
        }

        return depth(root) - 1;
    }

    int search(const T& value) const {
        return searchT(root, value);
    }

    BST<std::string> createTree(const char* filename);
};

#endif  // INCLUDE_BST_H_
