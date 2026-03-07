#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if(low <= high)
    {
        int pi = partition(arr, low, high);

        if(pi == k)
            return arr[pi];
        else if(pi > k)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        int arr[1000];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if(k > n)
        {
            cout << "not present" << endl;
        }
        else
        {
            int result = quickSelect(arr, 0, n - 1, k - 1);
            cout << result << endl;
        }
    }

    return 0;
}