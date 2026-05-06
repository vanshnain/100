#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int partition(vector<int>& arr,int l,int h,int &c){
    int pivot=arr[h],i=l-1;
    for(int j=l;j<h;j++){
        c++;
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
int randPart(vector<int>& arr,int l,int h,int &c){
    int p=l+rand()%(h-l+1);
    swap(arr[p],arr[h]);
    return partition(arr,l,h,c);
}
void quickSort(vector<int>& arr,int l,int h,int &c){
    if(l<h){
        int pi=randPart(arr,l,h,c);
        quickSort(arr,l,pi-1,c);
        quickSort(arr,pi+1,h,c);
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int c=0;
    quickSort(arr,0,n-1,c);
    cout << "Sorted array: ";
    for(int x:arr) cout<<x<<" ";
    cout << "\nComparisons: " << c;
}
//input 5
// 5 2 4 6 1
//output 1 2 4 5 6
//Comparisons: (may vary, e.g. 6–10)
