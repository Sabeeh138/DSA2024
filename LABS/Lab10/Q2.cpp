#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kLargestElements(const vector<int>& nums, int k) {
    if (k == 0 || nums.empty()) return {};

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else if (num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 3;

    vector<int> result = kLargestElements(nums, k);

    cout << "The " << k << " largest elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
