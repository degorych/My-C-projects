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
        checkIndex(index, newNode);
        if (index == 0) {
            Node* currentNode = newNode;
            Node* previousNode = newNode->getPrevious();
            Node* temp = new Node;

            temp->setValues(addNumber, previousNode, currentNode);
            currentNode->setPrevious(temp);

            if (previousNode != NULL) {
                previousNode->setNext(temp);
            }
        }
        else {
            index--;
            newNode = newNode->getNext();
            addNodeToIndex(addNumber, index, newNode);
        }
    }

    /* --- Delete node to index --- */
    void deleteNodeToIndex(int index, Node* delNode) {
        checkIndex(index, delNode);
        if (index == 0) {
            Node* previousNode = delNode->getPrevious();
            Node* nextNode = delNode->getNext();

            previousNode->setNext(nextNode);
            nextNode->setPrevious(previousNode);
            delete delNode;
        }
        else {
            index--;
            delNode = delNode->getNext();
            deleteNodeToIndex(index, delNode);
        }
    }

    /* --- Show all nodes values --- */
    void show(Node* obj) {
        cout << obj->getNumber() << " ";

        if (obj->getNext() != NULL) {
		obj = obj->getNext();
		show(obj);
        }
    }

    /* --- Get node number to user index --- */
    int getNumberToIndex(int index, Node* obj) {
        checkIndex(index, obj);
        if (index == 0) {
            return obj->getNumber();
        }
        else {
            obj = obj->getNext();
            index--;
            getNumberToIndex(index, obj);
        }
    }

    /* --- Show node value to index --- */
    void messegeGetNumberToIndex(int index, Node* obj) {
        int number = getNumberToIndex(index, obj);
        cout << index << " node is " << number << endl;
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
    void checkIndex(int index, Node* obj) {
        int nodesNumber = nodeCounter(obj);
        if (index < 0) {
            cout << "Index may be >= 0" << endl;
            exit(-1);
        }
        else if (index >= nodesNumber) {
            cout << "Index may be less then " << nodesNumber << endl;
            exit (-2);
        }
    }

    /* --- Clean memory --- */
    void cleanMenory(Node* obj) {
        while(obj) {
		delete obj->getPrevious();
		obj = obj->getNext();
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
    cout << "\n------------------------------------------------------\n" << endl;

    cout << "\n-------------- Add new node to 2 index ---------------" << endl;
    objLinList->addNodeToIndex(55, 2, obj);
    objLinList->show(obj);
    cout << "\n------------------------------------------------------\n" << endl;

    cout << "\n--------------- Delete node to 4 index ---------------" << endl;
    objLinList->deleteNodeToIndex(4, obj);
    objLinList->show(obj);
    cout << "\n------------------------------------------------------\n" << endl;

    cout << "\n------------ Show node value to 2 index --------------" << endl;
    objLinList->messegeGetNumberToIndex(2, obj);
    cout << "------------------------------------------------------\n" << endl;

    objLinList->cleanMenory(obj);
    delete objLinList;

    return 0;
}
