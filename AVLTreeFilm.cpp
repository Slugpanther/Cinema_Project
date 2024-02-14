//Code basee sur example fourni par le prof et de la documentation en ligne

#pragma once
#include "AVLTreeFilm.h"
#include <iostream>

AVLTree::AVLTree() {
    root = NULL;
}
AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(NodeAVL* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    root = NULL;
}

int AVLTree::height(NodeAVL* node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

void AVLTree::updateHeight(NodeAVL* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

int AVLTree::balanceFactor(NodeAVL* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

//ONT DES OVERRIDES/CONSTRUCTEURS DIFFERENTS PLUS LOIN
void AVLTree::displayInOrder() {
    displayInOrder(root);
}

void AVLTree::displayByTitle(string title) {
    displayByTitle(root,title);
}

void AVLTree::displayByDuration(int duration) {
    displayByDuration(root, duration);
}

void AVLTree::displayByRating(char rating) {
    displayByRating(root, rating);
}


AVLTree::NodeAVL* AVLTree::rotateRight(NodeAVL* node) {
    NodeAVL* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLTree::NodeAVL* AVLTree::rotateLeft(NodeAVL* node) {
    NodeAVL* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLTree::NodeAVL* AVLTree::rotateLeftRight(NodeAVL* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLTree::NodeAVL* AVLTree::rotateRightLeft(NodeAVL* node) { //simplifier le call des 2 rotations
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

AVLTree::NodeAVL* AVLTree::rebalance(NodeAVL* node) { //c compliquer, mais c'est ce qui restructure l'arbre
    updateHeight(node);
    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->left) <= 0) {
            return rotateRight(node);
        }
        else {
            return rotateLeftRight(node);
        }
    }
    else if (balanceFactor(node) == 2) {
        if (balanceFactor(node->right) >= 0) {
            return rotateLeft(node);
        }
        else {
            return rotateRightLeft(node);
        }
    }

    return node;
}

//ceux void
void AVLTree::insert(Film film) {
    root = insert(root, film);
}

void AVLTree::remove(Film film) {
    root = remove(root, film);
}

AVLTree::NodeAVL* AVLTree::insert(NodeAVL* node, Film data) {
    if (node == NULL) {
        node = new NodeAVL{ data,0,NULL,NULL };
    }
    else if (data.titre < node->data.titre) {
        node->left = insert(node->left, data);
    }
    else if (data.titre > node->data.titre) {
        node->right = insert(node->right, data);
    }
    else { //si film existe deja dans le tree
        return node;
    }
    return rebalance(node);
    
}

AVLTree::NodeAVL* AVLTree::remove(NodeAVL* node, Film data) {
    if (node == NULL) {
        return NULL;
    }
    if (data.titre < node->data.titre) {
        node->left = remove(node->left, data);
    }
    else if (data.titre > node->data.titre) {
        node->right = remove(node->right, data);
    }
    else {
        if (node->left == NULL || node->right == NULL) { //node feuille
            delete node;
            node = NULL;
        }
        else if (node->left == NULL) { //node avec enfant a droite
            NodeAVL* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == NULL) // node avec enfant a gauche
        {
            NodeAVL* temp = node;
            node = node->left;
            delete temp;
        }
        else //node avec 2 enfants
        {
            NodeAVL* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
    }
    if (node != NULL) {
        return rebalance(node);
    }
    else
    {
        return node;
    }
    
}

AVLTree::NodeAVL* AVLTree::findMin(NodeAVL* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == nullptr) {
        return node;
    }

    return findMin(node->left);
}

void AVLTree::displayInOrder(NodeAVL* node) { //display dans l'ordre qu'ils sont dans l'arbre
    if (node == NULL)
    {
        return;
    }
    displayInOrder(node->left);
    cout << node->data.titre << " || " << node->data.duree << " minutes || " << node->data.ageRating << endl;
}

//ONLY DISPLAYS THOSE THAT FITS

void AVLTree::displayByTitle(NodeAVL* node, string title) {
    if (node == NULL)
    {
        return;
    }
    displayByTitle(node->left, title);
    if (node->data.titre == title)
    {
        cout << node->data.titre << " || " << node->data.duree << " minutes || " << node->data.ageRating << endl;
    }
    displayByTitle(node->right, title);
}

void AVLTree::displayByDuration(NodeAVL* node, int duration) {
    if (node == NULL)
    {
        return;
    }
    displayByDuration(node->left, duration);
    if (node->data.duree == duration)
    {
        cout << node->data.titre << " || " << node->data.duree << " minutes || " << node->data.ageRating << endl;
    }
    displayByDuration(node->right, duration);
}

void AVLTree::displayByRating(NodeAVL* node, char rating) {
    if (node == NULL)
    {
        return;
    }
    displayByRating(node->left, rating);
    if (node->data.ageRating == rating)
    {
        cout << node->data.titre << " || " << node->data.duree << " minutes || " << node->data.ageRating << endl;
    }
    displayByRating(node->right, rating);
}








