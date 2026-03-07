#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        int arr[1000];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int comparisons = 0, swaps = 0;

        for(int i = 0; i < n - 1; i++) {
            int min = i;

            for(int j = i + 1; j < n; j++) {
                comparisons++;
                if(arr[j] < arr[min]) {
                    min = j;
                }
            }

            if(min != i) {
                swap(arr[i], arr[min]);
                swaps++;
            }
        }

        // Print sorted array
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}