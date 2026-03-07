#include <iostream>
#include <cstdlib>
using namespace std;

int comparisons = 0;
int swaps = 0;

void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    swaps++;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        comparisons++;

        if(arr[j] <= pivot)
        {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }

    swapElements(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int random = low + rand() % (high - low + 1);
        swapElements(arr[random], arr[high]);

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[1000];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << "comparisons = " << comparisons << endl;
    cout << "swaps = " << swaps << endl;

    return 0;
}