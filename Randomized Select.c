#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int partition(vector<int>& arr,int l,int h){
    int pivot=arr[h], i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
int randSelect(vector<int>& arr,int l,int h,int k){
    if(l==h) return arr[l];
    int p=l+rand()%(h-l+1);
    swap(arr[p],arr[h]);
    int pi=partition(arr,l,h);
    int cnt=pi-l+1;
    if(k==cnt) return arr[pi];
    else if(k<cnt) return randSelect(arr,l,pi-1,k);
    else return randSelect(arr,pi+1,h,k-cnt);
}
int main(){
    int n,k; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>k;
    cout<<randSelect(arr,0,n-1,k);
}
//input 5
//7 10 4 3 20
//3
