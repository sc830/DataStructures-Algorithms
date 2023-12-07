// Author : Shelby Cumings
//
// Serial number : 12
//
// Due Date : 10/10/2022
// Programming Assignment Number 4
// Fall 2022 - CS 3358 - 001
//
// Instructor: Husain Gholoom.
//
// This program uses a Node struct to imitate the format and operations of
// Stacks & Queues via class functions. The program will randomly populate
// a stack and a queue of length 7 with integers within a given range,
// then perform operations on them.


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;



class Stack {
    struct Node {
    int data;
    Node *next;
    };

    Node* stackHead;
public:
    Stack();
    void addNode();
    void stackPush(int);
    int stackPop();
    void buildStack();
    void display();
    void deleteStack();
    ~Stack();
};

class Queue {
    struct Node {
    int data;
    Node *next;
    };
    Node *queueHead;
    Node *queueTail;
public:
    Queue();
    void addNode();
    void buildQueue();
    void enqueue(int);
    void insertAtPosition(int, int);
    int dequeue();
    int returnPosition(int);
    int findMax();
    int findMin();
    void display();
    int returnTail();
    void deleteQueue();
    ~Queue();
};


void welcome();
int yesOrNo();
void goodbye();


int main () {
    Stack* myStack = new Stack;
    Queue* myQueue = new Queue;

    int run = 0;     // 0 - run program    2 - terminate program    3 - error

    welcome();

    while (run == 0) {
        cout << "A. Stack Elements :" << endl;
        myStack->buildStack();
        myStack->display();

        cout << "B. Queue Elements :" << endl;
        myQueue->buildQueue();
        myQueue->display();

        cout << "C. Inserting -20 in stack" << endl;
        myStack->stackPush(-20);
        myStack->display();

        cout << "D. Removing top 2 elements from stack" << endl;
        myStack->stackPop();
        myStack->stackPop();
        myStack->display();

        cout << "E. Inserting -500 in the queue" << endl;
        myQueue->enqueue(-500);
        myQueue->display();

        cout << "F. Inserting -200 in the 3rd location of the queue" << endl;
        myQueue->insertAtPosition(-200, 3);
        myQueue->display();


        cout << "G. Removing first element from the queue" << endl;
        myQueue->dequeue();
        myQueue->display();

        cout << "H. Removing element in location 4 from queue" << endl;
        myQueue->returnPosition(4);
        myQueue->display();

        cout << "I. Finding the minimum element in the queue      "
        << myQueue->findMin() << endl << endl;

        cout << "J. Finding the maximum element in the queue      "
        << myQueue->findMax() << endl << endl;

        cout << "K. Deleting the entire stack" << endl << endl;
        myStack->deleteStack();

        cout << "L. Removing first element of stack" << endl;
        myStack->stackPop();

        cout << "M. Deleting the entire queue" << endl << endl;
        myQueue->deleteQueue();

        cout << "Removing last element of queue." << endl;
        myQueue->returnTail();




        run = yesOrNo();        // first user prompt to run or close
        if (run != 0) {
            break;
        }

        myStack->deleteStack();
        myQueue->deleteQueue();
    }

    goodbye();

}

// ******* STACK MEMBER FUNCTIONS *********

Stack::Stack() {
    stackHead = NULL;
}

void Stack::addNode() {
    Node *temp = NULL;

    temp = stackHead;
    stackHead = new Node;
    stackHead->data = 0;
    stackHead->next = temp;
}

void Stack::stackPush (int element) {
    Node *temp = NULL;

    temp = stackHead;
    stackHead = new Node;
    stackHead->data = element;
    stackHead->next = temp;
}

int Stack::stackPop () {
    int value = 0;
    Node *temp = stackHead;

    if (temp == NULL) {
        cout << "***ERROR: Stack is empty***" << endl << endl;
    }
    else {
        value = stackHead->data;
        stackHead = stackHead->next;
        delete temp;
    }

    return value;
}

void Stack::buildStack() {
    int maximum = 65;
    int minimum = 60;
    int number = 0;

    srand(time(NULL));

    Node *temp = NULL;

    for (int i = 0; i < 7; i++) {
        number = rand() % (maximum - minimum + 1) + minimum;
        stackPush(number);
    }
}

void Stack::display () {
    Node *temp = NULL;
    temp = stackHead;

    while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
    }
    cout << endl << endl;
}

void Stack::deleteStack() {
    Node *temp = stackHead;

    while (temp != NULL) {
        stackHead = stackHead->next;
        delete temp;
        temp = stackHead;
    }
    stackHead = NULL;
}

Stack::~Stack() {
    Node *temp = stackHead;

    while (temp != NULL) {
    stackHead = stackHead->next;
        delete temp;
        temp = stackHead;
    }
}


// ******* QUEUE MEMBER FUNCTIONS *********

Queue::Queue() {
    queueHead = NULL;
    queueTail = NULL;
}

void Queue::addNode() {
    Node *newNode = new Node;
    newNode->data = 0;
    newNode->next = NULL;

    if (queueHead == NULL) {
        queueHead = newNode;
        queueTail = newNode;
    }
    else {
        queueTail->next = newNode;
        queueTail = queueTail->next;
    }
}

void Queue::buildQueue() {
    int maximum = 110;
    int minimum = 105;
    int number = 0;

    srand(time(NULL));

    for (int i = 0; i < 7; i++) {
        number = rand() % (maximum - minimum + 1) + minimum;
        enqueue(number);
    }
}

void Queue::enqueue(int element) {
    Node *newNode = new Node;
    newNode->data = element;
    newNode->next = NULL;

    if (queueHead == NULL) {
        queueHead = newNode;
        queueTail = newNode;
    }
    else {
        queueTail->next = newNode;
        queueTail = queueTail->next;
    }
}

void Queue::insertAtPosition (int element, int position) {
    Node *temp = queueHead;
    Node *before = NULL;
    Node *newNode = new Node;

    for (int i = 0; i < (position-1); i++) {
        temp = temp->next;
    }
    before = temp;
    temp = temp->next;

    before->next = newNode;
    newNode->next = temp;

    newNode->data = element;
}

int Queue::dequeue () {
    int value = 0;

    Node *temp = queueHead;
    value = queueHead->data;
    queueHead = queueHead->next;
    delete temp;

    return value;
}

int Queue::returnPosition (int position) {
    int value = 0;
    Node *temp = queueHead;
    Node *before = NULL;

    for (int i = 0; i < (position - 1); i++) {
        temp = temp->next;
    }

    before = temp;
    temp = temp->next;
    before->next = temp->next;

    value = temp->data;
    delete temp;

    return value;
}

int Queue::findMax () {
    int maximum = 0;
    Node *temp = queueHead;

    while (temp != NULL) {
        if (temp->data > maximum) {
            maximum = temp->data;
        }
        temp = temp->next;
    }
    return maximum;
}

int Queue::findMin () {
    int minimum = 200;
    Node *temp = queueHead;

    while (temp != NULL) {
        if (temp->data < minimum) {
            minimum = temp->data;
        }
        temp = temp->next;
    }
    return minimum;
}

void Queue::display () {
    Node *temp = NULL;
    temp = queueHead;
    while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
    }
    cout << endl << endl;
}

int Queue::returnTail() {
    int value = 0;
    if (queueHead == NULL) {
        cout << "***ERROR: Queue is empty***" << endl << endl;
    }
    else {
        value = queueTail->data;
    }
    return value;
}

void Queue::deleteQueue() {
    Node *temp = queueHead;

    while (temp != NULL) {
        queueHead = queueHead->next;
        delete temp;
        temp = queueHead;
    }
}

Queue::~Queue() {
    Node *temp = queueHead;

    while (temp != NULL) {
        queueHead = queueHead->next;
        delete temp;
        temp = queueHead;
    }
}


// ******* NON-MEMBER FUNCTIONS *********

void welcome() {
    cout << "Welcome to my ADT Linked List Program. \n\n";
}

int yesOrNo() {

    string user = "";
    int value = 3;

    cout << "Enter X to terminate : " << endl;
    cout << "Enter anything else to run again.       --->    ";
    cin >> user;
    cout << "\n";

    if (user == "X") {
        value = 2;                      // terminate program
    }
    else {
        value = 0;                      // run program
    }
    return value;
}

void goodbye() {
    cout << "\nThis LL / Stack & Queue program"
    << " is implemented By : Shelby Cumings - October 2022" << endl;
}
