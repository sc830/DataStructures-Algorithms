// Author : Shelby Cumings
// Serial Number :
// Due Date : 9/5/2022
// Programming Assignment Number 1
// Fall 2022 - CS 3358 - Section 001
//
// Instructor: Husain Gholoom.
//
// This program creates 3 x 3 arrays, populates them, and performs various
// manipulations on them and displays the results. Then the program
// determines whether or not the array generated is a special array,
// and repeats the program until the user terminates it.


void welcome();
void display (int[][3]);
void populateArray (int[][3]);
void sumArrays (int[][3], int[][3], int[][3]);
void productArrays(int[][3], int[][3], int[][3]);
void showTranspose (int[][3]);
void showDeterminant (int[][3]);
void sumCols(int[][3], int[][3], int);
void sumRows(int[][3], int[][3], int);
void sumDiagonal (int[][3], int[][3], int);
void specialArray (int[][3], int[][3], int);
int repeat (int);
void goodbye();

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;


int main () {

    int arr1[3][3] = {{0, 0, 0}, {0, 0, 0,}, {0, 0, 0}};
    int arr2[3][3] = {{0, 0, 0}, {0, 0, 0,}, {0, 0, 0}};
    int arr3[3][3] = {{0, 0, 0}, {0, 0, 0,}, {0, 0, 0}};

    int special[3][3] = {{0, 0, 0}, {0, 0, 0,}, {0, 0, 0}};
    // this array stores the sums of 3s, 3umns, and diagonals
    // to compare to the special number


    int choice = 1;        // repeat variable (indicates user choice)
                            // 0 = no   1 = yes   2 = invalid

    welcome();

    while (choice != 0) {

        populateArray(arr1);
        populateArray(arr2);

        cout << "Array_1 :" << endl << endl << endl;
        display(arr1);
        cout << "Array_2 :" << endl << endl << endl;
        display(arr2);

        cout << "Sum of Array 1 and Array 2 :" << endl << endl << endl;
        sumArrays(arr1, arr2, arr3);
        display(arr3);

        cout << "Product of Array 1 and Array 2 : " << endl << endl << endl;
        productArrays(arr1, arr2, arr3);
        display(arr3);

        cout << "Transpose of Array 1 : " << endl << endl << endl;
        showTranspose(arr1);

        cout << "Determinant of Array 1  = ";
        showDeterminant(arr1);

        sumRows(arr1, special, 1);

        sumCols(arr1, special, 1);

        sumDiagonal(arr1, special, 1);

        specialArray(arr1, special, 1);

        choice = repeat(choice);

        while ((choice != 1) && (choice != 0)) {
            choice = repeat(choice);
        }

    }

    goodbye();
    return 0;

}


void welcome() {
    cout << "Welcome to my Array program ." << endl <<
            " The function of the program is to :" << endl <<
            "1. Create an 2 Arrays ( Array_1 , Array_2 )." << endl <<
            "  Each Array is of size 3 x 3." << endl <<
            "2. Populate both Arrays with distinct random numbers"
            << "that are between 1 and 12. \nDisplay both Arrays." << endl <<
            "3. Adding and multiplying Array_1 and Array_2." << endl <<
            "4. Displaying the transposed and the determinate of Array_1 ."
            << endl <<
            "5. Displaying the sum of elements of each 3 of Array_1," <<
            " displaying the sum of elements of each 3umn of Array_1 ," <<
            " displaying the sum of both diagonal elements of Array_1."
            << endl <<
            "6. Finally , determining whether or not Array_1 is special array."
            << endl << "7. Repeating the above steps until the user" <<
            " terminates the program."
            << endl << endl << endl;
}


void display(int arr[][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << endl << endl;
    }
    cout << endl << endl << endl;
}


void populateArray (int arr[][3]) {

    srand(time(NULL));

    for (int i = 0; i < 3; i++) {            // populate numbers 1-12
        for (int j = 0; j < 3; j++) {
            arr[i][j] = rand() % 13;

            for (int k = 0; k < i; k++) {      // check for repeated numbers
                for (int l = 0; l < j; l++) {

                    if (arr[i][j] == arr[k][l]) {
                        arr[i][j] = rand() % 13;
                        k = 0;
                        l = 0;
                    }
                }
            }
        }
    }
}


void sumArrays (int arr1[][3], int arr2[][3], int arr3[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}


void productArrays (int arr1[][3], int arr2[][3], int arr3[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}


void showTranspose (int arr[][3]) {
    int transpose[][3] = {{0, 0, 0}, {0, 0, 0,}, {0, 0, 0}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = arr[i][j];
        }
    }
    display(transpose);
}


void showDeterminant (int arr[][3]) {
    int determinant = 0;
    int termA = 0;      // value for a(ei - fh) portion of formula
    int termB = 0;      // value for b(di - fg) portion of formula
    int termC = 0;      // value for c(dh - eg) portion of formula
                    // these variables for ease of use/readability

    termA = arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]));
    termB = arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0]));
    termC = arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0]));

    determinant = termA - termB + termC;

    cout << determinant << endl << endl;


}



void sumRows(int arr[][3], int special[][3], int arrayNumber) {

    cout << endl << endl;
    int x = 0;      // used to reference variable i outside of for loop

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            special[1][j] = special[1][j] + arr[i][j];
            x++;
        }
        cout << "Sum of numbers in Row   #  " << (x+1) << "  in Array "
        << arrayNumber << "   =   " << special[1][j] << endl << endl;
        x = 0;
    }

}



void sumCols(int arr[][3], int special[][3], int arrayNumber) {

    cout << endl << endl << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            special[0][i] = special[0][i] + arr[i][j];
        }

        cout << "Sum of numbers in Column   #  " << (i+1) << "  in Array "
        << arrayNumber << "   =   " << special[0][i] << endl << endl;


    }
    cout << endl << endl << endl;
}


void sumDiagonal (int arr[][3], int special[][3], int arrayNumber) {

    int i = 0;
    for (int j = 0; j < 3; j++) {         // sum first diag
        special[2][0] = special[2][0] + arr[i][j];
        i += 1;
    }

    i = 0;
    for (int j = (3-1); j < 3; j++) {   // sum second diag
        special[2][1] = special[2][1] + arr[i][j];
        i += 1;
    }

    cout << "Sum of numbers in first diagonal in Array " << arrayNumber
    << "   =   " << special[2][0] << endl << endl;

    cout << "Sum of numbers in second diagonal in Array " << arrayNumber
    << "   =   " << special[2][1] << endl << endl;

    cout << endl << endl << endl;
}


void specialArray(int arr[][3], int special[][3], int arrayNumber) {
    int specialNumber = 0;
    bool spec = true;

    specialNumber = (3 * ((3 * 3) + 1)) / 2;

    cout << "The special number for Array " << arrayNumber << " is "
    << specialNumber << endl << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < (3-1); j++) {
            if (special[i][j] != specialNumber) {
                spec = false;
            }
        }
    }

    if (spec == true) {
        cout << "The above is a special Array";
    }
    if (spec == false) {
        cout << "The above is not a special Array";

    cout << endl << endl << endl << endl << endl;
    }
}


int repeat (int choice) {
    string input = "";

    cout << "Would you like to check another Array - Enter y or Y" <<
    " or n | N for no ----->  ";
    cin >> input;

    if ((input == "N") || (input == "n")) {
        choice = 0;
        cout << endl << endl << endl << endl;
    }
    else if ((input == "Y" || input == "y")) {
        choice = 1;
        cout << endl << endl << endl << endl;
    }
    else {
        cout << "Error *** Invalid choice - Must enter " <<
        "y | Y | n | N" << endl << endl << endl;
        choice = 2;
    }

    return choice;
}


void goodbye() {
    cout << "This algorithm is implemented By Shelby Cumings" << endl
    << "September - 2022" << endl;
}
