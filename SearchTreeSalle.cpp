
#include "SearchTreeSalle.h"

NodeSalle::NodeSalle(SalleCinema maSalle) {
	salle = maSalle;
	left = NULL;
	right = NULL;
}

SearchTreeSalle::SearchTreeSalle() {
	root = NULL;
}
SearchTreeSalle::~SearchTreeSalle() {
	destroyTree(root);
}

void SearchTreeSalle::destroyTree(NodeSalle* currentNode) {
	if (currentNode != NULL)
	{
		destroyTree(currentNode->left);
		destroyTree(currentNode->right);
		delete currentNode;
	}
}



void SearchTreeSalle::insertRoom(SalleCinema maSalle) {
	NodeSalle* newNode = new NodeSalle(maSalle);
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		insertNode(root, newNode);
	}
}

NodeSalle* SearchTreeSalle::searchRoom(int id) {
	return searchNode(root, id);
}

void SearchTreeSalle::insertNode(NodeSalle* currentNode, NodeSalle* newNode) {
	if (newNode->salle.salleID < currentNode->salle.salleID)
	{
		if (currentNode->left == NULL)
		{
			currentNode->left - newNode;
		}
		else
		{
			insertNode(currentNode->left, newNode);
		}
	}
	else
	{
		if (currentNode->right == NULL)
		{
			currentNode->right - newNode;
		}
		else
		{
			insertNode(currentNode->right, newNode);
		}
	}
}

NodeSalle* SearchTreeSalle::searchNode(NodeSalle* currentNode, int id) {
	if (currentNode == NULL)
	{
		return NULL;
	}
	else if (currentNode->salle.salleID == id)
	{
		return currentNode;
	}
	else if (id < currentNode->salle.salleID)
	{
		return searchNode(currentNode->left, id);
	}
	else
	{
		return searchNode(currentNode->right, id);
	}
}

