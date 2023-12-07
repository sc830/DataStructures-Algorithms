// Author : Shelby Cumings
// Serial Number : 12
// Due Date : 9/19/2022
// Programming Assignment Number 2
// Fall 2022 - CS 3358 - Section 001
//
// Instructor: Husain Gholoom.
//
// description
//
//
//



#include <iostream>
#include <cstdlib>
//#include <cmath>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

void welcome();
int getArraySize();
int run();
void populateVector(vector<int> &);
void display(vector<int>);
void removeDuplicates(vector<int> &);
void sortVector(vector<int>, vector<int> &);
int countNum(vector<int> &, int);
void displaySortedOccurrence(vector<int> &);
void goodbye();

int main() {
    vector<int> myVector;
    vector<int> sorted;

    int arraySize = -1;
    int quit = 10;       // runs when 0, quits when 1, invalid input when 2

    bool inputValid = false;

    while (quit != 1) {         // runs until user input is "9"

        quit = run();

        while (quit == 2) {     // runs until input is "1" or "9"

            quit = run();

            if ((quit == 1) || (quit == 0)) {
                break;
            }
            else {
                cout << "Invalid Selection" << endl << endl;
            }

        }

        if (quit == 0) {
            arraySize = getArraySize(); // asks user for size, returns int size
        }

        if ((arraySize != -1) && ((arraySize <= 0 || arraySize > 30))) {
            cout << "INVALID SIZE MSG" << endl;
        }
        if ((quit == 1)) {
            break;
        }

        if ((arraySize > 0) && (arraySize <= 30)) {
            for (int i = 0; i < arraySize; i++) {
                myVector.push_back(0);
                sorted.push_back(0);
            }

            populateVector(myVector);
            display(myVector);

            sortVector(myVector, sorted);

            cout << "display sorted***** " << endl;
            display(sorted);

            displaySortedOccurrence(sorted);
        }
    }
}

void welcome() {

}

string choice() {            // asks user to run, returns input as string

    string input = "";

    cout << "Select one of the following:" << endl << endl;
    cout << "1 - Generate the Array. \n9 - Exit the App." << endl << endl;
    cout << "Enter Your Choice: ";
    cin >> input;

    return input;
}

int getArraySize() {

    int input = 40;

    cout << "Enter the size of the array : ";
    cin >> input;

    return (input);
}

int run() {            // uses choice() to ask user to run, returns int value

    string input = "";
    int value;

    input = choice();

    if (input == "1") {
        value = 0;
    }
    if (input == "9") {
        value = 1;
    }
    else if ((input != "1") && (input != "9")){
        value = 2;
    }

    return value;
}


void populateVector(vector<int> &myVector) {

    int number = 0;
    srand(time(NULL));

    for (int i = 0; i < myVector.size(); i++) {

        number = rand() % 8;

        myVector[i] = number;
    }
}


void display(vector<int> myVector) {


    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << " ";
    }
    cout << endl << endl;
}


void removeDuplicates(vector<int> &myVector) {

    for (int i = 0; i < myVector.size(); i++) {
        for (int j = 0; j < myVector.size(); j++)
            if (myVector[i] == myVector[j]) {
                myVector.erase(myVector.begin(), myVector.begin()+j);
                j--;
            }
    }
}


void sortVector(vector<int> myVector, vector<int> &sorted) {

    int compare = 10;
    int duplicates = 0;     // stores how many of the number are in the vector


    for (int x = 0; x < myVector.size(); x++) {
        for (int i = 0; i < myVector.size(); i++) {
            if (myVector[i] < compare) {
                compare = myVector[i];
                duplicates = 0;
            }
            if (myVector[i] == compare) {
                duplicates++;
            }
        }
        for (int j = 0; j <= duplicates; j++) {
            sorted.push_back(compare);
        }
    }
}

int countNum(vector<int> &sorted, int counting) {

    int num = 0;

    for (int i = 0; i < sorted.size(); i++) {

        if (sorted[i] == counting) {
            num++;
        }
    }

    return num;
}

void displaySortedOccurrence(vector<int> &sorted) {

    int occurrences = 0;
    int counting = 0;

    cout << "HEADER" << endl;

    for (int i = (sorted.size()-1); i > 0; i--) {
        cout << "DISPLAY LOOP  " << i << endl;
        counting = sorted.at(i);
        cout << "SORTED.AT   " << sorted.at(i);
        cout << "   " << counting << endl;
        occurrences = countNum(sorted, counting);

        cout << sorted.at(i) << "    " << occurrences;
        i = i - occurrences;
    }
    cout << endl << endl;
}

void goodbye() {

    cout << "Thank you for using the Vector APP" << endl
    << "Shelby Cumings" << endl << "9 - 19 - 2022" << endl;
}

