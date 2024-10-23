#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printFirstNegativeInteger(vector<int>& arr, int k) {
    deque<int> dq;  // 用來存儲負數的索引
    int n = arr.size();

    // 處理前 k 個元素的窗口
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);  // 如果是負數，將其索引加入雙端隊列
        }
    }

    // 處理剩餘的窗口
    for (int i = k; i < n; i++) {
        // 如果雙端隊列不為空，則窗口的第一個負數為隊首的元素
        if (!dq.empty()) {
            cout << arr[dq.front()] << " ";
        } else {
            cout << "0 ";  // 如果沒有負數，則輸出 0
        }

        // 移動窗口，從隊列中移除不再屬於當前窗口的元素
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 將當前元素加入窗口（如果是負數）
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // 處理最後一個窗口
    if (!dq.empty()) {
        cout << arr[dq.front()] << endl;
    } else {
        cout << "0" << endl;
    }
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    printFirstNegativeInteger(arr, k);

    return 0;
}