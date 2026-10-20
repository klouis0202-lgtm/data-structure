#include <iostream>  // 提供 cin 和 cout
#include <vector>    // 提供 vector 動態陣列
#include <algorithm> // 提供 max 函式
using namespace std;

class Solution{
	public:
		
	// 計算不能選相鄰房子時，最多能取得多少金額
	// const：函式不會修改 nums
	// &：以參考方式傳入，避免複製整個陣列
	int rob(const vector<int>& nums) {
	    int n = nums.size(); // 房子的數量
	
	    // 沒有房子，能取得的金額就是 0
	    if (n == 0) {
	        return 0;
	    }
	
	    // dp[i] 表示「前 i 間房子」能取得的最大金額
	    // 需要 dp[0] 到 dp[n]，因此建立 n + 1 個元素
	    // 所有元素的初始值設為 0
	    vector<int> dp(n + 1, 0);
	
	    dp[0] = 0;       // 沒有房子時，金額為 0
	    dp[1] = nums[0]; // 只有第一間房子時，選它即可
	
	    // 從前 2 間房子開始，逐步計算到前 n 間
	    for (int i = 2; i <= n; i++) {
	
	        // 選擇一：不選目前這間
	        // 最佳結果等於前 i - 1 間的最佳結果
	        int skip = dp[i - 1];
	
	        // 選擇二：選目前這間
	        // 不能選前一間，所以加上前 i - 2 間的最佳結果
	        int take = dp[i - 2] + nums[i - 1];
	
	        // 比較兩種選擇，保留金額較大的結果
	        dp[i] = max(skip, take);
	    }
	
	    // 考慮完全部 n 間房子後的最佳結果
	    return dp[n];
	}
};

int main() {
    int n;

    // 輸入房子的數量
    cout << "Enter number of houses: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    // 建立 n 個元素的陣列，存放各間房子的金額
    vector<int> nums(n);

    cout << "Enter money for each house: ";

    // 依序輸入每間房子的金額，金額必須是非負整數
    for (int i = 0; i < n; i++) {
        if (!(cin >> nums[i]) || nums[i] < 0) {
            cout << "Invalid input." << endl;
            return 1;
        }
    }

    // 呼叫 rob 函式，計算最大金額
    Solution solution;
    int answer = solution.rob(nums);

    // 顯示答案
    cout << "Maximum money: " << answer << endl;

    return 0; // 正常結束程式
}