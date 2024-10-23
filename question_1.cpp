#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> stack1, stack2;

    // 將元素推入 stack1
    stack1.push(31);
    stack1.push(30);
    stack1.push(29);
    stack1.push(28);

    // 將元素從 stack1 反向移動到 stack2
    while (!stack1.empty()) 
    {
        stack2.push(stack1.top());  // 將 stack1 的頂端元素推入 stack2
        stack1.pop();  // 從 stack1 彈出頂端元素
    }

    // 輸出 stack1 和 stack2 的內容
    cout << "the size of stack1: " << stack1.size() << endl;  // 應該是 0
    
    cout << "stack2: ";
    while (!stack2.empty()) 
    {
        cout << stack2.top() << " ";  // 輸出 stack2 的頂端元素
        stack2.pop();  // 彈出 stack2 的元素
    }
    cout << endl;

    return 0;
}