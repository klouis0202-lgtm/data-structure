#include <iostream>  
#include <vector>    
using namespace std;

class Solution {
public: // 讓外部可以呼叫 searchMatrix 函式

    // 在 matrix 中尋找 target(要找的值)
    // 找到回傳 true，找不到回傳 false(即布林值bool)
    // 以二為整數陣列傳入
    bool searchMatrix(vector<vector<int> >& matrix, int target) {

        // 如果矩陣沒有任何列，或第一列沒有元素，就沒有數字可搜尋
        // || 具有短路求值：左邊為 true 時，不會存取右邊的 matrix[0]
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();    // 矩陣的rows數
        int n = matrix[0].size(); // 矩陣的columns數

        int left = 0;            // 搜尋範圍的左邊界(第一個元素=0)
        int right = m * n - 1;   // 搜尋範圍的右邊界(最後一個元素位置)

        // left == right 時，仍有一個元素需要檢查
        // left > right 時，表示搜尋範圍內已經沒有元素
        while (left <= right) {

            // 計算目前搜尋範圍的中間索引
            // 此寫法可避免直接計算 left + right 造成整數溢位
            int mid = left + (right - left) / 2;

            // 將一維索引換成二維矩陣的位置：
            // mid / n 是列索引，mid % n 是欄索引
            // 例如 n = 4、mid = 5，對應 matrix[1][1]
            int value = matrix[mid / n][mid % n];

            if (value == target) {
                // 中間值就是目標，直接結束函式並回傳 true
                return true;

            } else if (value < target) {
                // 中間值太小，左半邊的值也不可能是目標
                // 排除中間位置及其左邊，繼續搜尋右半邊
                left = mid + 1;

            } else {
                // 中間值太大，右半邊的值也不可能是目標
                // 排除中間位置及其右邊，繼續搜尋左半邊
                right = mid - 1;
            }
        }

        // 搜尋範圍已經沒有元素，且過程中沒有找到目標
        return false;
    }
};

int main() {
    // 程式從 main 函式開始執行

    // 建立題目中的測試資料：3 列、4 欄
    int data[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    // 建立有 3 列的二維 vector
    // 每一列都是包含 4 個整數的 vector，初始值皆為 0
    // > > 之間留空格，是為了相容較舊的 C++ 標準
    vector<vector<int> > matrix(3, vector<int>(4));

    // 將 data 的數字逐一複製到 matrix
    for (int i = 0; i < 3; i++) {       // i 是列索引：0、1、2
        for (int j = 0; j < 4; j++) {   // j 是欄索引：0、1、2、3
            matrix[i][j] = data[i][j];
        }
    }

    int target; // 儲存使用者想搜尋的數字

    // 顯示提示，並讀取使用者輸入的整數
    cout << "Enter target: ";
    cin >> target;

    // 建立 Solution 類別的物件，名稱為 solution
    Solution solution;

    // 呼叫搜尋函式，傳入矩陣和目標值
    // 將搜尋結果（true 或 false）存入 found
    bool found = solution.searchMatrix(matrix, target);

    // 根據搜尋結果顯示文字
    if (found) {
        cout << "true" << endl;  // 找到目標，輸出 true 並換行
    } else {
        cout << "false" << endl; // 找不到目標，輸出 false 並換行
    }

    return 0; // 結束程式，0 代表正常結束
}