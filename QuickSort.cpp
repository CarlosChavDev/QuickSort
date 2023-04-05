// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void Print(int *array,int size);

void QuickSort(int *array, int start, int end);
int Partition(int *array, int start, int end);

void swap(int &a, int &b);

int main()
{
    cout << "In this solution, we implement QuickSort." << endl;

    int myArray[] = { 7,2,1,6,8,5,3,4 };
    Print(myArray, 8);

    QuickSort(myArray, 0, 7);

    Print(myArray, 8);

    return 0;
}

void Print(int *array, int size) {
    for (int i = 0; i < size;i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void QuickSort(int *array, int start, int end) {
    if (start < end) {
        int pIndex = Partition(array, start, end);
        QuickSort(array, start, pIndex - 1);
        QuickSort(array, pIndex + 1, end);
    }
}

int Partition(int *array, int start, int end) {
    int pIndex = start; //to be swapped 

    for (int i = start; i < end;i++) { //traverse through all values in array
        if (array[i] <= array[end]) { //if value at array is less than pivot
            swap(array[i], array[pIndex]);//swap with pIndex
            pIndex++; //increment pIndex
        }//values left of pIndex  will always be lesser than pivot value...
    }
    swap(array[pIndex],array[end]); //Finally, swap where pivot is supposed to go
    
    return pIndex;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
