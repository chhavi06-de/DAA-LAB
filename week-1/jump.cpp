#include <iostream>
using namespace std;

int main()
{
    int n, key;
    int arr[100];
    int comparisons = 0;
    bool found = false;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> key;

    int step = 2;
    int prev = 0;

    for(int i = 0; i < n; i += step)
    {
        comparisons++;

        if(arr[i] == key)
        {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }

        if(arr[i] > key)
        {
            for(int j = prev; j < i; j++)
            {
                comparisons++;
                if(arr[j] == key)
                {
                    cout << "Element found at index " << j << endl;
                    found = true;
                    break;
                }
            }
            break;
        }

        prev = i;
    }

    if(!found)
    {
        for(int j = prev; j < n; j++)
        {
            comparisons++;
            if(arr[j] == key)
            {
                cout << "Element found at index " << j << endl;
                found = true;
                break;
            }
        }
    }

    if(!found)
        cout << "Element not found" << endl;

    cout << comparisons << endl;

    return 0;
}