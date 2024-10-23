#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size() / 2; // 獲取隊列的一半長度
    queue<int> firstHalf;

    // 將隊列的前半部分推入 firstHalf 隊列中
    for (int i = 0; i < n; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // 交錯插入 firstHalf 和第二半部分的元素
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // 輸入元素推入隊列
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // 交錯排列
    interleaveQueue(q);

    // 輸出隊列中的元素
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}