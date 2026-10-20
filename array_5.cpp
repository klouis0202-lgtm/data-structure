#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 搜尋範圍包含 left 和 right
        // 先轉成 int 再減 1，空陣列時 right 就會是 -1
        int left = 0;
        int right = (int)nums.size() - 1;

        // 只要搜尋範圍內還有元素，就繼續搜尋
        while (left <= right) {
            // 找到中間索引，避免直接相加 left + right
            int mid = left + (right - left) / 2;

            // 找到目標，回傳它在目前陣列中的索引
            if (nums[mid] == target) {
                return mid;
            }

            // 左半邊有序：nums[left] 到 nums[mid] 由小到大
            // 等號也涵蓋 left == mid、左半邊只有一個元素的情況
            if (nums[left] <= nums[mid]) {

                // 目標落在左半邊的數值範圍內
                // mid 已檢查過，所以不包含 nums[mid]
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    // 目標不可能在左半邊，改搜尋右半邊
                    left = mid + 1;
                }

            } else {
                // 左半邊無序，因此右半邊一定有序

                // 目標落在右半邊的數值範圍內
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    // 目標不可能在右半邊，改搜尋左半邊
                    right = mid - 1;
                }
            }
        }

        // 搜尋範圍已空，代表目標不存在
        return -1;
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    vector<int> nums(n);

    cout << "Enter rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> nums[i])) {
            cout << "Invalid input." << endl;
            return 1;
        }
    }

    int target;

    cout << "Enter target: ";
    if (!(cin >> target)) {
        cout << "Invalid input." << endl;
        return 1;
    }

    Solution solution;
    int answer = solution.search(nums, target);

    cout << "Index: " << answer << endl;

    return 0;
}