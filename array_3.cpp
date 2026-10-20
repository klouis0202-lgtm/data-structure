#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // dp[i]：s 的前 i 個字元是否能完整拆成字典中的單字
        // 建立 dp[0] 到 dp[n]，一開始全部設為 false
        vector<bool> dp(n + 1, false);

        // 空字串可以組成，作為動態規劃的起點
        dp[0] = true;

        // 依序判斷前 1 個、前 2 個……前 n 個字元
        for (int i = 1; i <= n; i++) {

            // 檢查字典中的每一個單字
            for (int j = 0; j < (int)wordDict.size(); j++) {
                const string& word = wordDict[j];
                int len = word.size();

                // 單字比目前考慮的字串還長，不可能放在結尾
                if (len > i) {
                    continue;
                }

                // 假設目前單字放在結尾，它的起始索引就是 i - len
                int start = i - len;

                // 前面的部分必須已經能成功拆分
                // 否則即使結尾符合目前單字，整段仍然不能成立
                if (!dp[start]) {
                    continue;
                }

                // 比較 s 從 start 開始、長度為 len 的部分與 word
                // compare 回傳 0，代表兩段文字完全相同
                if (s.compare(start, len, word) == 0) {
                    dp[i] = true;

                    // 已找到一種可行拆法，不必再檢查其他單字
                    break;
                }
            }
        }

        // 前 n 個字元就是整個字串
        return dp[n];
    }
};

int main() {
    string s;
    int count;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of words: ";
    if (!(cin >> count) || count < 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    vector<string> wordDict(count);

    cout << "Enter dictionary words: ";
    for (int i = 0; i < count; i++) {
        cin >> wordDict[i];
    }

    Solution solution;
    bool answer = solution.wordBreak(s, wordDict);

    cout << (answer ? "true" : "false") << endl;

    return 0;
}