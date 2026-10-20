#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 所有硬幣面額都是正整數
        // 如果能湊出 amount，所需硬幣數不可能超過 amount
        // 因此用 amount + 1 表示「目前無法湊出」
        int INF = amount + 1;

        // dp[i]：湊出金額 i 所需的最少硬幣數量
        // 建立 dp[0] 到 dp[amount]，先全部設為無法湊出
        vector<int> dp(amount + 1, INF);

        // 湊出金額 0 不需要任何硬幣
        dp[0] = 0;

        // 從小金額開始，依序計算到目標金額
        for (int i = 1; i <= amount; i++) {

            // 嘗試讓每一種硬幣成為最後拿的那枚
            for (int j = 0; j < (int)coins.size(); j++) {
                int coin = coins[j];

                // 硬幣面額比目前金額大，不能使用
                // 同時避免 i - coin 變成負數索引
                if (coin > i) {
                    continue;
                }

                // 剩餘金額無法湊出，就不能使用這個組合
                if (dp[i - coin] == INF) {
                    continue;
                }

                // 剩餘金額的最少硬幣數，加上目前這枚硬幣
                // 與原本結果比較，留下較小值
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        // 如果仍然是 INF，代表沒有任何組合能湊出目標金額
        if (dp[amount] == INF) {
            return -1;
        }

        // 回傳湊出目標金額所需的最少硬幣數量
        return dp[amount];
    }
};

int main() {
    int n;
    int amount;

    cout << "Enter number of coin types: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> coins[i]) || coins[i] <= 0) {
            cout << "Invalid input." << endl;
            return 1;
        }
    }

    cout << "Enter amount: ";
    if (!(cin >> amount) || amount < 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    Solution solution;
    int answer = solution.coinChange(coins, amount);

    cout << "Minimum coins: " << answer << endl;

    return 0;
}