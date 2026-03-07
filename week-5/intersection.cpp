#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cin >> m;
    int A[1000];

    for(int i = 0; i < m; i++)
        cin >> A[i];

    cin >> n;
    int B[1000];

    for(int i = 0; i < n; i++)
        cin >> B[i];

    int i = 0, j = 0;

    while(i < m && j < n)
    {
        if(A[i] == B[j])
        {
            cout << A[i] << " ";
            i++;
            j++;
        }
        else if(A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return 0;
}