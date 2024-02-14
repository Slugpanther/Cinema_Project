#pragma once
#include "SalleCinema.h"

class NodeRabais {
public:
    int value;
    int price; //rabais sur le billet
    NodeRabais* left;
    NodeRabais* right;

    NodeRabais(int value, int price);
};

class RabaisTreeGroupe {
public:
    RabaisTreeGroupe();
    ~RabaisTreeGroupe();
    void insertNode(int value, int price);
    int searchTree(int value);

private:
    NodeRabais* root;
};
[10:02 PM]
#include "RabaisTreeGroupe.h"

RabaisTreeGroupe::RabaisTreeGroupe() {
    root = NULL;
}

RabaisTreeGroupe::~RabaisTreeGroupe() {
    delete root;
}

void RabaisTreeGroupe::insertNode(int value, int price) {
    if (root == NULL) {
        root = new NodeRabais(value, price);
        return;
    }

    NodeRabais* current = root;
    while (true) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = new NodeRabais(value, price);
                return;
            }
            else {
                current = current->left;
            }
        }
        else if (value > current->value) {
            if (current->right == NULL) {
                current->right = new NodeRabais(value, price);
                return;
            }
            else {
                current = current->right;
            }
        }
        else {
            // Node with the same value already exists
            return;
        }
    }
}

int RabaisTreeGroupe::searchTree(int value) {
    NodeRabais* current = root;
    while (current != NULL) {
        if (current->value == value) {
            return current->price;
        }
        else if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return -1; // Node not found -> ne devrait jamais arriver si on cree les 10 nodes
}