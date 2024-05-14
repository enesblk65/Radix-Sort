#include <iostream>

using namespace std;

//This function is used to find the number of digits of the biggest number in the array.
int findMaxDigit(int array[], int size) {

    int maxElement = array[0];
    int maxDigit = 0;

    for (int i = 1; i < size; i++) {  //This for loop finds the biggest element.
        if (array[i] > maxElement)
            maxElement = array[i];

    }

    for (int i = 1; i < maxElement; i *= 10) {  //This for loop finds the number of digits of the biggest element.
        if (maxElement / i != 0)
            maxDigit++;
    }

    return maxDigit;
}

//This function is used to output the array.
void outputArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

//This function swap the parameters.
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//This function sorts the array using Bubble Sort.
void bubbleSort(int array[], int array2[], int size) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (array[j] > array[j + 1]) {

                swap(array[j], array[j + 1]);  //This step digits swap places.
                swap(array2[j], array2[j + 1]);  //This step numbers swap places.

            }
        }
    }
}

//This function separates the elements in the array into digits and saves them in a different array.
void radixSort(int array[], int size, int maxDigit) {

    int* temp = new int[size];  //This array saves the digits of the elements.
    int* temp2 = array;  //This array saves the sorted elements.
    int j = 1;

    for (int meter = 1; meter <= maxDigit; meter++) {

        for (int i = 0; i < size; i++) {

            int digit = (array[i] / j) % 10;
            temp[i] = digit;

        }

        cout << meter << ". Iteration Result : ";

        bubbleSort(temp, temp2, size);
        outputArray(temp2, size);

        j *= 10;
    }
}

int main() {

    int array[] = { 18,108,5,6,4,88,40,665,10 };
    int size = sizeof(array) / sizeof(array[0]);
    int maxDigit = findMaxDigit(array, size);

    cout << "Array Before Radix Sort  : ";
    outputArray(array, size);
    cout << endl;
    radixSort(array, size, maxDigit);

    cout << "\nArray After Radix Sort : ";
    outputArray(array, size);

    return 0;
}
