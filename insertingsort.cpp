#include <iostream>
#include <vector>
using namespace std;
int insertionSort(vector<int>& arr) {
    int comparisons = 0;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int c = insertionSort(arr);
    for(int x:arr) cout<<x<<" ";
    cout<<"\nComparisons: "<<c;
}
