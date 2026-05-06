#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& arr,int n,int i,int &c){
    int largest=i;
    int l=2*i+1,r=2*i+2;
    if(l<n){ c++; if(arr[l]>arr[largest]) largest=l; }
    if(r<n){ c++; if(arr[r]>arr[largest]) largest=r; }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest,c);
    }
}
int heapSort(vector<int>& arr){
    int c=0,n=arr.size();
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i,c);
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0,c);
    }
    return c;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int c = heapSort(arr);
    cout << "Sorted array: ";
    for(int x:arr) cout<<x<<" ";
    cout << "\nComparisons: " << c;
}
//input 5
//5 2 4 6 1
//output 1 2 4 5 6
//Comparisons: 10
