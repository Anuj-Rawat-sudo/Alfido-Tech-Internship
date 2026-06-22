#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    cout << "===== MERGE SORT =====\n\n";

    vector<int> sample = {38, 27, 43, 3, 9, 82, 10};

    cout << "Sample Input:\n";
    for(int x : sample) cout << x << " ";

    mergeSort(sample, 0, sample.size()-1);

    cout << "\n\nSorted Output:\n";
    for(int x : sample) cout << x << " ";

    cout << "\n\n----- Runtime Analysis -----\n";

    int sizes[] = {100, 1000, 10000};

    for(int size : sizes) {

        vector<int> arr(size);

        for(int i = 0; i < size; i++)
            arr[i] = rand() % 100000;

        auto start = high_resolution_clock::now();

        mergeSort(arr, 0, size - 1);

        auto stop = high_resolution_clock::now();

        auto duration =
        duration_cast<microseconds>(stop - start);

        cout << "Input Size = "
             << size
             << " | Runtime = "
             << duration.count()
             << " microseconds\n";
    }

    cout << "\nTime Complexity: O(n log n)\n";

    return 0;
}