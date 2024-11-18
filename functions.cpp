#include "Functions.h"
#include <algorithm>
#include <vector>

using namespace std;

// Bucket Sort Implementation
void bucketSort(vector<int>& arr, int bucketSize) {
    if (arr.empty()) return;

    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int bucketIndex = (num - minValue) / bucketSize;
        buckets[bucketIndex].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// Helper function to merge two halves
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (k = 0; k < temp.size(); ++k) {
        arr[left + k] = temp[k];
    }
}

// Recursive Merge Sort Function
void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Merge Sort Wrapper
void mergeSort(vector<int>& arr) {
    mergeSortRecursive(arr, 0, arr.size() - 1);
}
