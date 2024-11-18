// For this lesson I'll be collecting the amount of time using a bucket sort method and merge sort. 
// I'll run this test in four different array sizes: 100, 1000, 10000, and 100000. The output times 
// will be charted on a separate sheet and included with this submission. 
//
// I did a lot of research as to the best way to write this code. I took elements and ideas from 
// GeeksforGeeks.com, Simplilearn.com, programiz.com, and stack overflow then used elements from 
// each to come up with the final code. This added about 2 hours to this project. 
// Total Time was 6 hours.

#include <iostream>
#include <vector>
// prefer chrono for timing
#include <chrono>
#include "functions.h"

void arrayRandomValues(std::vector<int>& arr, int size, int minValue = 0, int maxValue = 1000) {
    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % (maxValue - minValue + 1) + minValue);
    }
}

int main() {
    // create random numbers for generating
    srand(static_cast<unsigned>(time(0)));

    // Array sizes for testing
    std::vector<int> sizes = { 100, 1000, 10000, 100000 };

    for (int size : sizes) {
        std::vector<int> arrBucket, arrMerge;
        arrayRandomValues(arrBucket, size);
        arrMerge = arrBucket; // Copy for merge sort to keep the dataset identical

        // Measure time taken for bucket sort
        auto startBucket = std::chrono::high_resolution_clock::now();
        bucketSort(arrBucket);
        auto endBucket = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedBucket = endBucket - startBucket;

        // Measure time taken for merge sort
        auto startMerge = std::chrono::high_resolution_clock::now();
        mergeSort(arrMerge);
        auto endMerge = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedMerge = endMerge - startMerge;

        // Output the results
        std::cout << "Bucket sort for " << size << " elements took "
            << elapsedBucket.count() << " seconds.\n";

        std::cout << "Merge sort for " << size << " elements took "
            << elapsedMerge.count() << " seconds.\n";
    }

    return 0;
}
