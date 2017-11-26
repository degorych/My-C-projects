#include <iostream>
#include <stdlib.h>

using namespace std;

class Node {
private:
    int number;
    Node* previous;
    Node* next;

public:
    /* --- Create first node --- */
    void firstNode (int n, Node* firstNode) {
        firstNode->number = n;
        firstNode->next = NULL;
        firstNode->previous = NULL;
    }

    /* --- Add new node to end --- */
    void addNode(int addNumber, Node* newNode) {
        if (newNode->next == NULL) {
            Node* temp = new Node;
            temp->number = addNumber;
            temp->next = NULL;
            temp->previous = newNode;
            newNode->next = temp;
        }
        else {
            newNode = newNode->next;
            addNode(addNumber, newNode);
        }
    }

    /* --- Add new node to index --- */
    void addNodeToIndex(int addNumber, int index, Node* newNode) {
        int checkIndexInShow = checkIndex(index, newNode);
        int i;
        Node* currentNode;
        Node* previousNode;
        if (checkIndexInShow == 1) {
            for (i = 0; i <= index; i++) {
                currentNode = newNode;
                previousNode = newNode->previous;
                newNode = newNode->next;
            }
            Node* temp = new Node;
            temp->number = addNumber;
            temp->previous = previousNode;
            temp->next = currentNode;

            currentNode->previous = temp;
            if (previousNode != NULL) {
                previousNode->next = temp;
            }
        }
    }

    /* --- Delete node to index --- */
    void deleteNodeToIndex(int index, Node* delNode) {
        int checkIndexInShow = checkIndex(index, delNode);
        int i;
        Node* previousNode;
        Node* currentNode;
        if (checkIndexInShow == 1) {
            for (i = 0; i <= index; i++) {
                previousNode = delNode->previous;
                currentNode = delNode;
                delNode = delNode->next;
            }
            previousNode->next = delNode;
            delNode->previous = previousNode;
            delete currentNode;
        }
    }

    /* --- Show all nodes value --- */
    void show (Node* obj) {
        Node* nodeList = obj;
        while(nodeList) {
		cout << nodeList->number << " ";
		nodeList = nodeList->next;
        }
        cout << endl;
    }

    /* --- Show node value to index --- */
    void showToIndex(int index, Node* obj) {
        int checkIndexInShow = checkIndex(index, obj);
        int i;
        Node* currentNode;
        if (checkIndexInShow == 1) {
            for (i = 0; i <= index; i++) {
                currentNode = obj;
                obj = obj->next;
            }
            cout << index << " node is " << currentNode->number << endl;
        }
    }

    /* --- Nodes counter --- */
    int nodeCounter(Node* obj) {
        Node* nodeList = obj;
        int nodesNumber = 0;
        while(nodeList) {
		nodeList = nodeList->next;
		nodesNumber++;
        }
        return nodesNumber;
    }

    /* --- Check index to correct value --- */
    int checkIndex(int index, Node* obj) {
        int nodesNumber = nodeCounter(obj);
        if (index < 0) {
            cout << "Index may be >= 0" << endl;
            exit(-1);
        }
        else if (index >= nodesNumber) {
            cout << "Index may be less then " << nodesNumber << endl;
            exit (-2);
        }
        else {
            return 1;
        }
    }
};

int main() {
    Node* obj = new Node;

    cout << "\n------------------- Add new nodes --------------------" << endl;
    obj->firstNode(10, obj);
    obj->addNode(20, obj);
    obj->addNode(30, obj);
    obj->addNode(40, obj);
    obj->addNode(50, obj);
    obj->addNode(60, obj);
    obj->show(obj);
    cout << "------------------------------------------------------\n" << endl;

    cout << "\n-------------- Add new node to 2 index ---------------" << endl;
    obj->addNodeToIndex(55, 2, obj);
    obj->show(obj);
    cout << "------------------------------------------------------\n" << endl;

    cout << "\n--------------- Delete node to 4 index ---------------" << endl;
    obj->deleteNodeToIndex(4, obj);
    obj->show(obj);
    cout << "------------------------------------------------------\n" << endl;

    cout << "\n------------ Show node value to 2 index --------------" << endl;
    obj->showToIndex(2, obj);
    cout << "------------------------------------------------------\n" << endl;

    return 0;
}
