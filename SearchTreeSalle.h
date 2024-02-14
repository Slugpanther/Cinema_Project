#pragma once
#include "SalleCinema.h"

class NodeSalle {
public:
    SalleCinema salle;
    NodeSalle* left;
    NodeSalle* right;

    NodeSalle(SalleCinema salle);
};

class SearchTreeSalle {
public:
    SearchTreeSalle();
    ~SearchTreeSalle();
    void insertRoom(SalleCinema maSalle);
    NodeSalle* searchRoom(int id);

private:
    NodeSalle* root;
    void destroyTree(NodeSalle* currentNode);
    void insertNode(NodeSalle* currentNode, NodeSalle* newNode);
    NodeSalle* searchNode(NodeSalle* currentNode, int id);
};