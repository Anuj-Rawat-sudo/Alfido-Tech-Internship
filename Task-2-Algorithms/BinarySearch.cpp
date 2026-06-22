#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int binarySearch(vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {

    cout << "===== BINARY SEARCH =====\n\n";

    vector<int> sample = {2, 5, 8, 12, 16, 23, 38, 56};
    int key = 23;

    cout << "Sample Array:\n";
    for(int x : sample)
        cout << x << " ";

    cout << "\n\nSearch Key: " << key << endl;

    int result = binarySearch(sample, key);

    if(result != -1)
        cout << "Output: Element found at index " << result << endl;
    else
        cout << "Output: Element not found" << endl;

    cout << "\n----- Runtime Analysis -----\n";

    int sizes[] = {100, 1000, 10000};

    for(int size : sizes) {

        vector<int> arr(size);

        for(int i = 0; i < size; i++)
            arr[i] = i + 1;

        int searchKey = size / 2;

        auto start = high_resolution_clock::now();

        binarySearch(arr, searchKey);

        auto stop = high_resolution_clock::now();

        auto duration =
        duration_cast<microseconds>(stop - start);

        cout << "Input Size = "
             << size
             << " | Runtime = "
             << duration.count()
             << " microseconds\n";
    }

    cout << "\nTime Complexity: O(log n)\n";

    return 0;
}