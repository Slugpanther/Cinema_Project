#include <iostream>
using namespace std;

//Node for Singly Linked List
class Node {
public:
    int data; //CHANGER LE TYPE ICI POUR CELUI QU'ON VEUT =====> Film data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    void insert(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void remove(int data) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        if (prev == NULL) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    //Insert at Beginning: This function is used to insert a new node
    //at the beginning of the list.
    void insertAtBeginning(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    //Insert at Position: This function is used to insert a new node 
    //at a specific position in the list.
    void insertAtPosition(int data, int position) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
        }
        else {
            Node* temp = head;
            Node* prev = NULL;
            int count = 0;
            while (temp != NULL && count < position) {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if (prev == NULL) {
                new_node->next = head;
                head = new_node;
            }
            else {
                prev->next = new_node;
                new_node->next = temp;
            }
        }
    }
    //Get Node at Position: This function is used to get the node at
    //a specific position in the list.
    Node* getNodeAtPosition(int position) {
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
        }
        return temp;
    }
    //Get Length: This function is used to get the number of nodes in the list.
    int getLength() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    //Clear List: This function is used to delete all the nodes in the list.
    void clear() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }

};