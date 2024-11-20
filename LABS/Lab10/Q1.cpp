#include <iostream>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(const vector<int>& nums, int k) {
    vector<int> result;
    vector<int> deque; // A deque-like vector to store indices

    for (int i = 0; i < nums.size(); ++i) {
        if (!deque.empty() && deque.front() <= i - k) {
            deque.erase(deque.begin());
        }

        while (!deque.empty() && nums[deque.back()] <= nums[i]) {
            deque.pop_back();
        }
        deque.push_back(i);

        // Add the maximum value to the result once the first window is complete
        if (i >= k - 1) {
            result.push_back(nums[deque.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMax(nums, k);
    cout << "Sliding window maximums: ";
    for (int maxVal : result) {
        cout << maxVal << " ";
    }
    cout << endl;

    return 0;
}
