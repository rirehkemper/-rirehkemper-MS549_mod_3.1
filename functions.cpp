#include "Functions.h"
#include <algorithm> 

using namespace std;

void bucketSort(vector<int>& arr, int bucketSize) {
	if (arr.empty()) return;

	//range input and output values
	int minValue = *min_element(arr.begin(), arr.end());
	int maxValue = *max_element(arr.begin(), arr.end());

	//I used mathematics to determin the number of buckets seen below:
	//calculate the number of buckets considering the total number of values. We must have at least one
	int bucketCount = (maxValue - minValue) / bucketSize + 1;
	vector<vector<int>> buckets(bucketCount);

	//this is for distributing the array elements into the buckets
	for (int num : arr) {
		int bucketIndex = (num - minValue) / bucketSize;
		//adds the element to the end of the vector
		buckets[bucketIndex].push_back(num);
	}

	//sort the individual buckets, then combine (concatenate) them
	arr.clear();
	for (auto& bucket : buckets) {
		sort(bucket.begin(), bucket.end());
		arr.insert(arr.end(), bucket.begin(), bucket.end());
	}
}