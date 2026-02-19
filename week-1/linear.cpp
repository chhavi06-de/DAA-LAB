#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;   // number of test cases
    
    while(t--) {
        int n;
        cin >> n;
        
        int arr[10];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int key;
        cin >> key;
        
        int comparisons = 0;
        bool found = false;
        
        for(int i = 0; i < n; i++) {
            comparisons++;
            if(arr[i] == key) {
                cout << "Present " << comparisons << endl;
                found = true;
                break;
            }
        }
        
        if(!found) {
            cout << "NotPresent " << comparisons << endl;
        }
    }
    
    return 0;
}
