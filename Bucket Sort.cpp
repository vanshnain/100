#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(vector<float>& arr){
    int n=arr.size();
    vector<vector<float>> b(n);
    for(float x:arr){
        int idx=n*x;
        b[idx].push_back(x);
    }
    for(int i=0;i<n;i++)
        sort(b[i].begin(),b[i].end());
    int k=0;
    for(auto &v:b)
        for(float x:v)
            arr[k++]=x;
}
int main(){
    int n; cin>>n;
    vector<float> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bucketSort(arr);
    for(float x:arr) cout<<x<<" ";
}
//input 5
//0.42 0.32 0.23 0.52 0.25
