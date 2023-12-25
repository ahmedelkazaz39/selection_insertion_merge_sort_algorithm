#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n, int &comparisons, int &iterations) {
    for (int i = 0; i < n - 1; i++) {  /// 5 2 1 4 6
        for (int j = i + 1; j < n; j++) {//this loop for min number of array
            comparisons++;
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
        iterations++;
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &iterations) {
    for (int i = 1; i < n; i++) {   /// 5 |2 1 4 6
        int key = arr[i]; ///2
        int j = i - 1;  /// 0
        iterations++;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];   ///5
            j = j - 1;   ///-1
            comparisons++;
        }
        arr[j + 1] = key;  ///2
    }
}

void merge(int arr[], int left, int mid, int right, int &comparisons, int &iterations) {
    int n1 = mid - left + 1; ///size of first sub array arr[left ... min]
    int n2 = right - mid;    /// size of second sub array [min +1 ... right]


     ///create new  two array
    int L[n1], R[n2];


    ///store left sub array
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    ///store right sub array
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }


    ///merge two array
    int i = 0, j = 0, k = left; ///k=>reverence


    /// compare left and right
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;

    }
////    العناصر الباقية من بعد عملية المقارنه

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

    }
}

void mergeSort(int arr[], int left, int right, int &comparisons, int &iterations) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        iterations++;

        mergeSort(arr, left, mid, comparisons, iterations);// merge left sub array
        mergeSort(arr, mid + 1, right, comparisons, iterations); // merge right sub array

        merge(arr, left, mid, right, comparisons, iterations); //
    }
}


int main() {
    char continueSorting;
    do {
        int n, choice;
        cout << "Enter the number of elements you want to sort: ";
        cin >> n;
        int elements[n];
        cout << "Choose a sorting algorithm:" << endl;
        cout << "1. Selection Sort " << endl << "2. Insertion Sort" << endl << "3. Merge Sort" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "Enter the elements you want to sort:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Element " << i + 1 << ": ";
            cin >> elements[i];
        }
        int comparisons = 0;
        int iterations = 0;
        switch (choice) {
            case 1:
                selectionSort(elements, n, comparisons, iterations);
                break;
            case 2:
                insertionSort(elements, n, comparisons, iterations);
                break;
            case 3:
                mergeSort(elements, 0, n - 1, comparisons, iterations);
                break;
            default:
                cout << "Invalid choice. Exiting program." << endl;
                return 1;
        }
        cout << "The elements after sorting with choice " << choice << " are:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
        cout << "Number of comparisons: " << comparisons << endl;
        cout << "Number of iterations: " << iterations << endl;

        cout << "Do you want to sort another set of elements? (y/n): ";
        cin >> continueSorting;

    } while (continueSorting == 'y' || continueSorting == 'Y');

    return 0;
}