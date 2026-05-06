#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void countSort(vector<int>& arr,int exp){
    int n=arr.size();
    vector<int> out(n);
    int count[10]={0};
    for(int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        out[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    arr=out;
}
void radixSort(vector<int>& arr){
    int mx=*max_element(arr.begin(),arr.end());
    for(int exp=1;mx/exp>0;exp*=10)
        countSort(arr,exp);
}
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    radixSort(arr);
    for(int x:arr) cout<<x<<" ";
}
//input 5
//170 45 75 90 802
