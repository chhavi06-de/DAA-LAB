#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==key) return m;
        else if(arr[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(){
    int T;
    cin>>T;

    for(int t=0;t<T;t++){
        int n;
        cin>>n;

        int arr[100];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        bool found=false;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                int k=binarySearch(arr,n,sum);

                if(k!=-1){
                    cout<<i<<","<<j<<","<<k<<endl;
                    found=true;
                    break;
                }
            }
            if(found) break;
        }

        if(!found)
            cout<<"No sequence found"<<endl;
    }

    return 0;
}