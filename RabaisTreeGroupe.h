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