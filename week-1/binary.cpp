#include <iostream>
using namespace std;

int main()
{
    int n, key;
    int arr[100];
    int low, high, mid;
    int comparisons = 0;
    bool found = false;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter key element to search: ";
    cin >> key;

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if(arr[mid] == key)
        {
            found = true;
            break;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found)
        cout << "Element found at position " << mid + 1 << endl;
    else
        cout << "Element not found" << endl;

    cout << "Total comparisons = " << comparisons << endl;

    return 0;
}