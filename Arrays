// Author : Shelby Cumings
//
// Serial Number : 12
//
// Due Date : 10/31/2022
// Programming Assignment Number 5
//
// Fall 2022 - CS 3358 - 001
//
// Instructor: Husain Gholoom.
//
// Program takes input from user and creates an array of size >= 5 and <= 20,
// otherwise displays error message and terminates.
// Program then utilizes recursive functions to perform various manipulations
// on integers, display integers in a certain order, and perform calculations.


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

void welcome();
int getArraySize();                 // arguments:
int raiseToPower (int, int);        // (base, power)
bool arraySizeCheck (int);          // (arraySize)
void populateArray (int[], int);     // (arr, arraySize)
void displayArray (int[], int);      // (arr, arraySize)
void displayReversed(int[], int);    // (arr, arraySize-1)
void displayIntsSquared (int, int); // (starting int, ending intx)
void displayVertical(int);          // (num)
bool digitsAscending (int);         // (num)
int reverseDigits(int);             // (num)
bool isPrime(int, int);             // (num)
void goodbye();


int main () {

    welcome();                              // displays program welcome msg

    int arraySize = getArraySize();         // asks for array size from user

    if (arraySizeCheck(arraySize) == true) {    // validates array size
        int arr[arraySize] = {0};

        populateArray(arr, arraySize);      // array population



        cout << "The generated array is : ";
        displayArray(arr, arraySize);       // base array display



        cout << "Reversed Array is : ";
        displayReversed(arr, arraySize-1);  // displays array backwards



        cout << arr[arraySize-1] << " raised to the 2nd power is: ";
        cout << raiseToPower(arr[arraySize-1], 2) << endl << endl;
                            // displays last array elem to 2nd power



        cout << "Table of square values 1 - " << arr[0] << endl << endl;
        cout << "N         N Squared\n";
        displayIntsSquared(1, arr[0]);
                            // displays squared ints from 1 to first array elem



        cout << arr[1] << " vertically: " << endl << endl;
        displayVertical(arr[1]);
                            // displays one digit of elem per row, from left




        cout << arr[2] << " is ";
        if (digitsAscending(arr[2]) != true) {
            cout << "not ";                 // executes if ascending != true
        }
        cout << "in increasing order. " << endl << endl;
                            // displays results of digitsAscending



        cout << "Reversed of " << arr[3] << " is ";
        cout << reverseDigits(arr[3]) << endl << endl;
                        // displays array elem with digits reversed in order



        cout << arr[4] << " is ";
        if (isPrime(arr[4], (arr[4]-1) != true)) {
            cout << "not ";                 // executes if prime != true
        }
        cout << "Prime :" << endl;


        cout << endl << endl;
    }

    goodbye();                          // displays program termination msg

}


void welcome() {        // displays welcome message
    cout << "*** Welcome to My Recursion APP *** \n\n";
}

int getArraySize() {    // asks user for # of elements in array
    int arraySize = 0;  // stores int value for size of array

    cout << "Enter The array size. ( Must be >= 5 and <= 20) "
    << char(26) << "  ";
    cin >> arraySize;
    cout << endl << endl;

    return arraySize;
}

// recursively calculates a number (base) raised to some power (exponent)
int raiseToPower (int base, int exponent) {
    if (exponent == 0) {            // any # to 0 power is 1
        return 1;
    }
    else {
        return (base*raiseToPower(base, exponent-1));
        // at end of recursion, multiplies base by itself (exponent) many times
        // ex: 10^5 = 10 * 10^4         10^4 = 10 * 10^3
        //      10^5 --> 10 * 10 * 10 * 10 * 10 * 1      (with 1 = 10^0)
    }
}

// returns true if array is valid size based on set parameters
// otherwise, displays error msg and returns false
bool arraySizeCheck (int arraySize) {
    int MIN = 5;        // named const for smallest array size
    int MAX = 20;       // named const for largest array size

    bool check;

    if ((arraySize < MIN) || (arraySize > MAX)) {
        cout << "Invalid arrays size. Size must >= " << MIN
        << " and <= " << MAX << "." << endl;
        check = false;
    }
    else {
        check = true;
    }

    return check;
}

// populates array with random ints within set range
void populateArray (int arr[], int arraySize) {
    int MAX = 499;      // named constant max value of array element (inclusive)
    int MIN = 21;       // named constant min value of array element (inclusive)

    srand(time(NULL));  // random seed

    for (int i = 0; i < arraySize; i++) {
        arr[i] = rand() % (MAX - MIN + 1) + MIN;
    }
}

// displays given array in standard order
void displayArray (int arr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

// recursively displays given array backwards
// **should be called with arguments (arr, arraySize-1)
void displayReversed(int arr[], int index) {
    if (index >= 0) {
        cout << arr[index] << " ";
        displayReversed(arr, index-1);  // recursive call to display element
                                        // at position [index-1]
    }
    else {
        cout << endl << endl;
    }
}

//recursively displays squares of integers 1->first element of array, inclusive
// should be called with arguments (starting integer, first array element)
void displayIntsSquared (int integer, int first) {
    if (integer <= first) {
        cout << left << setw(10) << integer;
        cout << left << setw(10) << raiseToPower(integer, 2) << endl;
        displayIntsSquared(integer+1, first);   // display next larger integer
    }
    if (integer == first) { // adds space after final recursion (formatting)
        cout << endl << endl;
    }
}

// recursively displays given number vertically by displaying only the
// largest digit in each row, then calling itself again
void displayVertical(int num) {
    int temp = num;         // copy num for manipulation
    int counter = 0;        // counts "place" of digit (tens, hundreds, etc)
    if (num > 0) {
        while (temp >= 10) {    // divide by 10 until we get the highest digit
            temp = temp / 10;
            counter++;
        }

        cout << temp << endl;
        if ((num < 100) && (num % 10) == 0) {
            cout << "0" << endl;
            num = num / 10;
        }
        else {
            num = num - (temp * (raiseToPower(10, counter)));

        displayVertical(num);       // recursive call for smaller num
        }

        // calculates the value of the largest digit in its decimal place
        // subtract this from num so that in next call,
        // we work with the num minus its largest digit.
        // ex: num = 746      display 7, calculate value of 7 in hundreds place
        // number to pass on = 746 - 700 = 46
    }
    if (num == 0) {             // adds space after last call (formatting)
        cout << endl;
    }
}

// recursively compares each adjacent set of digits to determine if
// its digits ascend from left to right
bool digitsAscending (int num) {
    if (num < 10) {             // if num is 1 digit, it is ascending
        return true;
    }
    else {
        int temp = num;
        int counter = 0;
        while (temp > 100) {    // divide by 10 until number is 2 digits
            temp = temp / 10;
            counter++;
        }
        int leftDigit = temp / 10;      // tens place digit
        int rightDigit = temp % 10;     // ones place digit

        if (leftDigit > rightDigit) {
            return false; // if any pair is not ascending, num is not ascending
        }
        else {
            num = num - (leftDigit * (raiseToPower(10, counter+1)));
            // num = num - value of left digit in its decimal place
            return digitsAscending(num);
        }
    }
}

// recursively computes integer with digits reversed from original number
int reverseDigits(int num) {
    int temp = num;     // copy num to manipulate
    int counter = 0;    // counts number of digits

    if (num == 0) {
        return 0;
    }
    while (temp > 10) {      // counter = how many digits num has
        temp = temp / 10;
        counter++;
    }

    return (((num%10) * raiseToPower(10, counter)) + reverseDigits(num/10));
    // (smallest digit * inverse place value) + reverseDigits(num-lowest digit)
}

// tests division by each int between # and 1 to determine if # is prime
// function should be called with arguments (num, num-1)
bool isPrime(int num, int div) {
    if (div == 1) {    // div == 1 signals we have reached the end of recursion
        return true;   // if no # > 1 has triggered "false," the input is prime
    }
    else {
        if (num % div == 0) {   // n % d == 0 means n is evenly divisible by d
            return false;
        }
        else {
            return isPrime(num, div - 1);   // call for next smaller integer
        }
    }
}

void goodbye() {    // displays program termination msg
    cout << "\nShelby Cumings - Programmer" << endl
    << "October 2022" << endl;
}
