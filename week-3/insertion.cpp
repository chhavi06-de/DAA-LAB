#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100];
    int comparisons = 0, shifts = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0) {
            comparisons++;

            if(arr[j] > key) {
                arr[j + 1] = arr[j]; // shift
                shifts++;
                j--;
            }
            else {
                break;
            }
        }

        arr[j + 1] = key;
    }

    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNumber of comparisons: " << comparisons;
    cout << "\nNumber of shifts: " << shifts;

    return 0;
}