#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        int arr[100];
        for(int i=0;i<n;i++)
            cin >> arr[i];

        int k;
        cin >> k;

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] - arr[j] == k || arr[j] - arr[i] == k)
                    count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}