#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(vector<int>& arr) {
    stack<int> s;
    int n = arr.size();
    vector<int> nge(n, -1);  // 預設所有元素的 NGE 為 -1

    // 從後往前遍歷陣列
    for (int i = n - 1; i >= 0; i--) {
        // 移除所有比當前元素小的堆疊元素
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // 如果堆疊不為空，則當前元素的 NGE 為堆疊頂部元素
        if (!s.empty()) {
            nge[i] = s.top();
        }

        // 將當前元素推入堆疊
        s.push(arr[i]);
    }

    // 輸出結果
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    printNGE(arr);

    return 0;
}