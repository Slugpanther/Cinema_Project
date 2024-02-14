#pragma once
#include "LinkedListFilm.h"
#include "Film.h"
using namespace std;


class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(Film film);
    void remove(Film film);
    void displayInOrder();
    void displayByTitle(string title);
    void displayByDuration(int duration);
    void displayByRating(char rating);
private:
    class NodeAVL {
    public:
        Film data;
        NodeAVL* left;
        NodeAVL* right;
        int height;
    };
    NodeAVL* root;

    void destroyTree(NodeAVL* node);
    int height(NodeAVL* node);
    int balanceFactor(NodeAVL* node);
    void updateHeight(NodeAVL* node);
    NodeAVL* rotateLeft(NodeAVL* node);
    NodeAVL* rotateRight(NodeAVL* node);
    NodeAVL* rotateLeftRight(NodeAVL* node);
    NodeAVL* rotateRightLeft(NodeAVL* node);
    NodeAVL* rebalance(NodeAVL* node);

    NodeAVL* insert(NodeAVL* node, Film film);
    NodeAVL* remove(NodeAVL* node, Film film);
    NodeAVL* findMin(NodeAVL* node);
    void displayInOrder(NodeAVL* node);
    void displayByTitle(NodeAVL* node, string title);
    void displayByDuration(NodeAVL* node, int duration);
    void displayByRating(NodeAVL* node, char rating);
};