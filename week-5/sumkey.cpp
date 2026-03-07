#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1000];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;
    bool found = false;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(sum == key)
        {
            found = true;
            break;
        }
        else if(sum < key)
            left++;
        else
            right--;
    }

    if(found)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}