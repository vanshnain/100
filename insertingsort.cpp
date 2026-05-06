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
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int c = insertionSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nComparisons: " << c << endl;
    return 0;
}

//input
//and Enter number of elements: 5
//Enter elements: 5 2 4 6 1
//    output
//    Sorted array: 1 2 4 5 6
//Comparisons: 8
    
