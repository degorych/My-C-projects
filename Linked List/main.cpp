#include <iostream>
#include <stdlib.h>

using namespace std;

class Node {
private:
    int number;
    Node* previous;
    Node* next;

public:
    /* --- SET --- */
    void setNumber(int number) {
        this->number = number;
    }
    void setPrevious(Node* previous) {
        this->previous = previous;
    }
    void setNext(Node* next) {
        this->next = next;
    }
    void setValues(int number, Node* previous, Node* next) {
        setNumber(number);
        setPrevious(previous);
        setNext(next);
    }

    /* --- GET --- */
    int getNumber() {
        return number;
    }
    Node* getPrevious() {
        return previous;
    }
    Node* getNext() {
        return next;
    }
};

class LinkedList {
public:

    /* --- Create first node --- */
    void firstNode (int number, Node* firstNode) {
        firstNode->setValues(number, NULL, NULL);
    }

    /* --- Add new node to end --- */
    void addNode(int addNumber, Node* newNode) {
        if (newNode->getNext() == NULL) {
            Node* temp = new Node;

            temp->setValues(addNumber, newNode, NULL);
            newNode->setNext(temp);
        }
        else {
            newNode = newNode->getNext();
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
                previousNode = newNode->getPrevious();
                newNode = newNode->getNext();
            }
            Node* temp = new Node;
            temp->setValues(addNumber, previousNode, currentNode);
            currentNode->setPrevious(temp);
            if (previousNode != NULL) {
                previousNode->setNext(temp);
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
                previousNode = delNode->getPrevious();
                currentNode = delNode;
                delNode = delNode->getNext();
            }
            previousNode->setNext(delNode);
            delNode->setPrevious(previousNode);
            delete currentNode;
        }
    }

    /* --- Show all nodes value --- */
    void show (Node* obj) {
        Node* nodeList = obj;
        while(nodeList) {
		cout << nodeList->getNumber() << " ";
		nodeList = nodeList->getNext();
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
                obj = obj->getNext();
            }
            cout << index << " node is " << currentNode->getNumber() << endl;
        }
    }

    /* --- Nodes counter --- */
    int nodeCounter(Node* obj) {
        Node* nodeList = obj;
        int nodesNumber = 0;
        while(nodeList) {
		nodeList = nodeList->getNext();
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

    /* --- Clean memory --- */
    void cleanMenory(Node* obj) {
        Node* deleteObjects = obj;
        while(deleteObjects) {
		delete deleteObjects->getPrevious();
		deleteObjects = deleteObjects->getNext();
        }
    }
};

int main() {
    LinkedList* objLinList = new LinkedList;
    Node* obj = new Node;

    cout << "\n------------------- Add new nodes --------------------" << endl;
    objLinList->firstNode(10, obj);
    objLinList->addNode(20, obj);
    objLinList->addNode(30, obj);
    objLinList->addNode(40, obj);
    objLinList->addNode(50, obj);
    objLinList->addNode(60, obj);
    objLinList->show(obj);
    cout << "------------------------------------------------------\n" << endl;

    cout << "\n-------------- Add new node to 2 index ---------------" << endl;
    objLinList->addNodeToIndex(55, 2, obj);
    objLinList->show(obj);
    cout << "------------------------------------------------------\n" << endl;

    cout << "\n--------------- Delete node to 4 index ---------------" << endl;
    objLinList->deleteNodeToIndex(4, obj);
    objLinList->show(obj);
    cout << "------------------------------------------------------\n" << endl;

    cout << "\n------------ Show node value to 2 index --------------" << endl;
    objLinList->showToIndex(2, obj);
    cout << "------------------------------------------------------\n" << endl;

    objLinList->cleanMenory(obj);
    delete objLinList;

    return 0;
}
