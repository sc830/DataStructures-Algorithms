// Author : Shelby Cumings
//
// Serial Number : 12
//
//


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

void welcome();
int userInput();                            // arguments:
bool inputValidation(int);                  // user input
void populateCharArray(char[], int);        // char array, size
void populateIntArray(int[], int);          // char array, size
int randomValue(int, int);                  // min value, max value
void displayChar(char[], int);              // char array, size
void displayInt(int[], int);                // int array, size
void matchCharArray(char[], char[], int);   // char array to copy, copy, size
void matchIntArray(int[], int[], int);      // int array to copy, copy, size
void charSwap(char[], int, int);            // char array, index 1, index 2
void intSwap(int[], int, int);              // int array, index 1, index 2
int selectionSortChar(char[], int);        // char array, size
int selectionSortInt(int[], int);          // int array, size
int partInt(int[], int, int, int);   // int array, L index, R index, pivot value
int partIntForThird(int[], int, int, int);
// int array, L index, R index, pivot value
int partChar(char[], int, int, int);// char array, L index, R index, pivot value
int partCharForThird(char[], int, int, int);
// char array, L index, R index, pivot value
void quickSortMidChar(char[], int, int, int&);
// char array, L index, R index, counterer
void quickSortMidInt(int[], int, int, int&);
// int array, L index, R index, counter
void quickSortThirdElementChar(char[], int, int, int&);
// char arr, L index, R index, counter
void quickSortThirdElementInt(int[], int, int, int&);
// int arr, L index, R index, counter
int sequentialSearch(char[], int, char);
// char arr, size, search element
int binarySearch(char[], int, int, char, int&);
// char arr, L index, R index, search element, counter
clock_t displayClockInfo (clock_t);   // clock variable (start time)
int getSeconds(clock_t);       // clock variable
float getMil(clock_t);         // clock variable
void goodbye();


int main () {
    welcome();

    clock_t times[10];               // array to store times for each action
    clock_t timeClock;              // clock var
    srand(time(NULL));              // random seed
    int counter = 0;                // comparison counter
    char CHAR = 'P';                // named constant for search char

    int arraySize = userInput();

    if (inputValidation(arraySize) == true) {   // if input positive int > 9

        char charArr[arraySize] = {' '};
        int intArr[arraySize] = {0};     // initializing arrays of size (input)

        srand(time(NULL));  // random seed
        populateCharArray(charArr, arraySize);
        populateIntArray(intArr, arraySize);    // randomly populate arrays

        cout << "Character array elements are:  ";
        displayChar(charArr, arraySize);

        cout << "Integer array elements are:  ";
        displayInt(intArr, arraySize);
        cout << endl;


        char charCopy[arraySize] = {0};
        matchCharArray(charArr, charCopy, arraySize);
        // copy array for manipulation

        int intCopy[arraySize] = {0};
        matchIntArray(intArr, intCopy, arraySize);
        // copy array for manipulation


        cout << endl << "Character Array Selection Sort: " << endl << endl;
        timeClock = clock();                // set start time
        counter = selectionSortChar(charCopy, arraySize);
        times[0] = displayClockInfo(timeClock);
        cout << "Total number of Swaps: " << counter << endl;
        cout << "Sorted elements:  ";
        displayInt(intCopy, arraySize);
        cout << endl << endl;

        counter = 0;                    // reset swap counter

        cout << "Integer Array Selection Sort: " << endl << endl;
        timeClock = clock();                // set start time
        counter = selectionSortInt(intCopy, arraySize);
        times[] = displayClockInfo(timeClock);
        cout << "Total number of Swaps: " << counter << endl;
        cout << "Sorted elements:  ";
        displayChar(charCopy, arraySize);
        cout << endl << endl;




        matchCharArray(charArr, charCopy, arraySize); // reset copy
        matchIntArray(intArr, intCopy, arraySize);    // reset copy


        cout << "Character Array Quick Sort - Middle Element as pivot"
        << endl << endl;
        timeClock = clock();                // set start time
        quickSortMidChar(charCopy, 0, arraySize-1, counter);
        times[1] = displayClockInfo(timeClock);
        cout << "Number of Recursive Calls: " << counter << endl;
        cout << "Sorted elements:  ";
        displayChar(charCopy, arraySize);
        cout << endl << endl;

        counter = 0;                    // reset recursion counter

        cout << "Integer Array Quick Sort - Middle Element as pivot"
        << endl << endl;
        timeClock = clock();            // set start time
        quickSortMidInt(intCopy, 0, arraySize-1, counter);
        times[1] = displayClockInfo(timeClock);    // end time
        cout << "Number of Recursive Calls: " << counter << endl;
        cout << "Sorted elements:  ";
        displayInt(intCopy, arraySize);
        cout << endl << endl;



        matchCharArray(charArr, charCopy, arraySize); // reset copy
        matchIntArray(intArr, intCopy, arraySize);    // reset copy
        counter = 0;                    // reset recursion counter



        cout << "Character Array Quick Sort - Third Element as pivot"
        << endl << endl;
        timeClock = clock();            // set start time
        quickSortThirdElementChar(charCopy, 0, arraySize-1, counter);
        times[2] = displayClockInfo(timeClock);    // end time
        cout << "Number of Recursive Calls: " << counter << endl;
        cout << "Sorted elements:  ";
        displayChar(charCopy, arraySize);
        cout << endl << endl;

        counter = 0;                    // reset recursion counter

        cout << "Integer Array Quick Sort - Third Element as pivot"
        << endl << endl;
        timeClock = clock();            // set start time
        quickSortThirdElementInt(intCopy, 0, arraySize-1, counter);
        times[5] = displayClockInfo(timeClock);    // end time
        cout << "Number of Recursive Calls: " << counter << endl;
        cout << "Sorted elements:  ";
        displayInt(intCopy, arraySize);
        cout << endl << endl;

        counter = 0;                // reset comparison counter

        cout << "Sequential search: " << endl << endl;
        cout << "Searching for char " << CHAR << "." << endl;
        timeClock = clock();            // set start time
        counter = sequentialSearch(charCopy, arraySize, CHAR);
        times[6] = displayClockInfo(timeClock);    // end time
        cout << "Total Number of Comparisons: " << counter << endl;
        cout << endl << endl << endl;

        counter = 0;                    // reset recursion counter

        cout << "Binary search: " << endl << endl;
        cout << "Searching for char " << CHAR << "." << endl;
        timeClock = clock();            // set start time
        int index = binarySearch(charCopy, 0, arraySize-1, CHAR, counter);
        if (index == -1) {        // char not found
            cout << "Char P was not found." << endl;
        }
        else {                          // char found
            cout << "Char P was found at index " << index << endl;
        }
        times[7] = displayClockInfo(timeClock);    // end time
        cout << "Total Number of Comparisons: " << counter << endl;

    }
    else {      // if input invalid
        cout << "***Error: Invalid input (Size must be > 9)" << endl;
    }



    //              CPU TIME SUMMARY

    cout << "Actual CPU Time Summary:\n\n";


    cout << "Character array size: " << arraySize << endl;
    cout << "Selection sort time:\n"
    cout << getSeconds(times[0]) << "s " << getMil(times[0]) << endl;
    cout << "Quick sort time - Middle Element as Pivot\n";
    cout << getSeconds(times[1]) << "s " << getMil(times[1]) << endl;
    cout << "Quick sort time - Third Element as Pivot\n";
    out << getSeconds(times[2]) << "s " << getMil(times[2]) << endl;

    cout << "Integer array size: " << arraySize << endl;
    cout << "Selection sort time:\n"
    cout << getSeconds(times[0]) << "s " << getMil(times[0]) << endl;
    cout << "Quick sort time - Middle Element as Pivot\n";
    cout << getSeconds(times[1]) << "s " << getMil(times[1]) << endl;
    cout << "Quick sort time - Third Element as Pivot\n";
    out << getSeconds(times[2]) << "s " << getMil(times[2]) << endl;


    cout << endl << endl << endl;
    goodbye();

    return 0;
}

void welcome() {        // displays welcome message
    cout << "Searching / Sorting Benchmark \n\n";
}

// prompts, collects, and returns user input
int userInput() {
    int input = 0;
    cout << "Enter the size of the array ( Must be > 9 ):  ";
    cin >> input;
    cout << endl << endl;

    return input;
}

// returns true if input > 9, false if input <= 9
bool inputValidation(int input) {
    if (input < 10) {
        return false;
    }
    else {
        return true;
    }
}

void populateCharArray(char arr[], int arraySize) {
    int MIN = 'a';      // named constant, inclusive min value
    int MAX = 'z';      // named constant, inclusive max value

    for (int i = 0; i < arraySize; i++) {
        arr[i] = randomValue(MIN, MAX);
    }
}

void populateIntArray(int arr[], int arraySize) {
    int MIN = 1;      // named constant, inclusive min value
    int MAX = 25;      // named constant, inclusive max value

    for (int i = 0; i < arraySize; i++) {
        arr[i] = randomValue(MIN, MAX);
    }
}

// generates random value between low and high, inclusive
int randomValue(int low, int high) {
    return low + rand() % (high - low + 1);
}

void displayChar(char arr[], int arraySize) {
    if (arraySize < 20) {
        for (int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        for (int i = 0; i < 20; i++) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

void displayInt(int arr[], int arraySize) {
if (arraySize < 20) {
        for (int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        for (int i = 0; i < 20; i++) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

void matchCharArray(char original[], char newArr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        newArr[i] = original[i];
    }
}

void matchIntArray(int original[], int newArr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        newArr[i] = original[i];
    }
}

void charSwap(char arr[], int index1, int index2) {
    char temp = ' ';             // holds value during swap

    temp = arr[index2];          // temp = value from index2
    arr[index2] = arr[index1];    // index2 element = index1 element
    arr[index1] = temp;          // index1 element = index2 element
}

void intSwap(int arr[], int index1, int index2) {
    int temp = 0;             // holds value during swap

    temp = arr[index2];          // temp = value from index2
    arr[index2] = arr[index1];    // index2 element = index1 element
    arr[index1] = temp;          // index1 element = index2 element
}

int selectionSortChar(char arr[], int arraySize) {
    int mini = 0;      // index of minimum value
    int swaps = 0;      // counts number of swaps

    // runs n-1 times (by run n, the last element should be sorted)
    for (int j = 0; j < arraySize-1; j++) {
        mini = j;
        for (int i = j; i < arraySize; i++) {   // this loop finds minimum
            if (arr[i] < arr[mini]) {
                mini = i;
            }
        }
        charSwap(arr, j, mini);  // when minimum of unsorted elements is found,
        swaps++;                 // swaps it with next unsorted element
    }
    return swaps;
}

int selectionSortInt(int arr[], int arraySize) {
    int mini = 0;      // index of minimum value
    int swaps = 0;      // counts number of swaps

    // runs n-1 times (by run n, the last element should be sorted)
    for (int j = 0; j < arraySize-1; j++) {
        mini = j;
        for (int i = j; i < arraySize; i++) {   // this loop finds minimum
            if (arr[i] < arr[mini]) {
                mini = i;
            }
        }
        intSwap(arr, j, mini);  // when minimum of unsorted elements is found,
        swaps++;                 // swaps it with next unsorted element
    }
    return swaps;
}

// swaps values in array to correct side of pivot value
//
int partInt(int arr[], int left, int right, int pivot) {
    while (left <= right) { // left/right move toward each other until they meet
        while (arr[left] < pivot) { // finds first # > pivot on left side
            left++;
        }
        while (arr[right] > pivot) { // finds first # < pivot on right side
            right--;
        }
        if (left <= right) {
            intSwap(arr, left, right);  // swaps out of place elements
            left++;
            right--;
        }
        else {
            break;
        }
    }
    return left;    // returns index of first element > pivot
}

int partIntForThird(int arr[], int left, int right, int pivot) {
    while (left <= right) { // left/right move toward each other until they meet
        while (arr[left] < pivot) { // finds first # > pivot on left side
            left++;
        }
        while (arr[right] > pivot) { // finds first # < pivot on right side
            right--;
        }
        if (left < right) {
            intSwap(arr, left, right);  // swaps out of place elements
            left++;
            right--;
        }
        else {
            break;
        }
    }
    return left;    // returns index of first element > pivot
}

int partChar(char arr[], int left, int right, int pivot) {
    while (left <= right) { // left/right move toward each other until they meet
        while (arr[left] < pivot) { // finds first # > pivot on left side
            left++;
        }
        while (arr[right] > pivot) { // finds first # < pivot on right side
            right--;
        }
        if (left <= right) {
            charSwap(arr, left, right);  // swaps out of place elements
            left++;
            right--;
        }
        else {
            break;
        }
    }
    return left;    // returns index of first element > pivot
}

int partCharForThird(char arr[], int left, int right, int pivot) {
    while (left <= right) { // left/right move toward each other until they meet
        while (arr[left] < pivot) { // finds first # > pivot on left side
            left++;
        }
        while (arr[right] > pivot) { // finds first # < pivot on right side
            right--;
        }
        if (left < right) {
            charSwap(arr, left, right);  // swaps out of place elements
            left++;
            right--;
        }
        else {
            break;
        }
    }
    return left;    // returns index of first element > pivot
}

void quickSortMidChar(char arr[], int left, int right, int &counter) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left+right)/2];

    int point = partChar(arr, left, right, pivot);
    counter++;
    quickSortMidChar(arr, left, point-1, counter);
    quickSortMidChar(arr, point, right, counter);
}

void quickSortMidInt(int arr[], int left, int right, int &counter) {
    if (left >= right) {
        return;
    }

    int pivot = 0;

    pivot = arr[(left+right)/2];

    int point = partInt(arr, left, right, pivot);
    counter++;
    quickSortMidInt(arr, left, point-1, counter);
    quickSortMidInt(arr, point, right, counter);
}

void quickSortThirdElementChar(char arr[], int left, int right, int &counter) {
    if (left >= right) {
        return;
    }

    int pivot = 0;

    if ((right-left) < 2) {    // uses 3rd # of substring as pivot if available
        pivot = arr[right];
    }
    else {                     // otherwise, uses last # of substring
        pivot = arr[left+2];
    }
    int point = partCharForThird(arr, left, right, pivot);
    counter++;
    quickSortThirdElementChar(arr, left, point-1, counter);
    quickSortThirdElementChar(arr, point, right, counter);
}

void quickSortThirdElementInt(int arr[], int left, int right, int &counter) {
    if (left >= right) {
        return;
    }

    int pivot = 0;

    if ((right-left) < 2) {    // uses 3rd # of substring as pivot if available
        pivot = arr[right];
    }
    else {                     // otherwise, uses last # of substring
        pivot = arr[left+2];
    }
    int point = partIntForThird(arr, left, right, pivot);
    counter++;
    quickSortThirdElementInt(arr, left, point-1, counter);
    quickSortThirdElementInt(arr, point, right, counter);
}

int sequentialSearch(char arr[], int arraySize, char searchChar) {
    int i = 0;  // initialize i outside for use after loop
    for (i = 0; i < arraySize; i++) {
        if (arr[i] == searchChar) {
            break;      // breaks loop if char is found
        }
    }

    if (i < arraySize) {    // if i < arraySize, i is index of location
        cout << "Char " << searchChar << " was found at index " << i << endl;
    }
    else {       // if i = arraySize, traversed array without finding char
        cout << "Char " << searchChar << " was not found." << endl;
    }

    return i;
}

int binarySearch(char arr[], int left, int right, char searchChar, int &counter)
{
    int mid = (left+right)/2;
    if (left <= right) {
        counter++;
        if (arr[mid] == searchChar) {
            return mid;
        }
        else if (searchChar < arr[mid]) {
            return binarySearch(arr, left, mid-1, searchChar, counter);
        }
        else if (searchChar > arr[mid]) {
             return binarySearch(arr, mid+1, right, searchChar, counter);
        }
    }
    return -1;
}

clock_t displayClockInfo (clock_t timeClock) {
    clock_t endClock;
    endClock = clock();

    cout << "Start time:  " << fixed << setprecision(0) << getSeconds(timeClock)
     << "s " << setprecision(2) <<getMil(timeClock) << "ms" << endl;
    cout << "End time:  " << setprecision(0) << getSeconds(endClock)
    << "s " << setprecision(2) << getMil(endClock) << "ms" << endl;

    timeClock = (endClock - timeClock);

    cout << "Actual CPU Clock time:   " << getSeconds(timeClock)
    << "s " << getMil(timeClock) << "ms" << endl;

    return timeClock;
}

int getSeconds(clock_t clockVariable) {
    return (clockVariable/CLOCKS_PER_SEC);
}

float getMil(clock_t clockVariable) {
    return (float)(clockVariable - (clockVariable/CLOCKS_PER_SEC))/100;
}

void CPUSummary(clock_t times[]) {

}

void goodbye() {    // displays program termination msg
    cout << "\nNovember - 2022" << endl
    << "Searching / Sorting Benchmark by:\nShelby Cumings" << endl;
}
