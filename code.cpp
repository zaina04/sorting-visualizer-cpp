#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int step = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        cout << "Step " << step++ << ": ";
        printArray(arr, n);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int step = 1;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        cout << "Step " << step++ << ": ";
        printArray(arr, n);
    }
}

int main() {
    int n, choice;
    int arr[100], original[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        original[i] = arr[i]; // save original
    }

    do {
        cout << "\n--- Sorting Visualizer Menu ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Show Original Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // restore original array before sorting
        for (int i = 0; i < n; i++) {
            arr[i] = original[i];
        }

        switch (choice) {
        case 1:
            cout << "\nBubble Sort Process:\n";
            bubbleSort(arr, n);
            cout << "Final Sorted Array: ";
            printArray(arr, n);
            break;

        case 2:
            cout << "\nSelection Sort Process:\n";
            selectionSort(arr, n);
            cout << "Final Sorted Array: ";
            printArray(arr, n);
            break;

        case 3:
            cout << "\nOriginal Array: ";
            printArray(original, n);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
