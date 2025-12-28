

# 1：螺旋矩阵

力扣原题：59：[螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

给你一个正整数 `n` ，生成一个包含 `1` 到 `n2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix` 。

![image-20251228161752344](C:\Users\yzc12\AppData\Roaming\Typora\typora-user-images\image-20251228161752344.png)

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2;           // 每个圈循环几次，如果n为奇数3
                                    // 那么loop=1,只是循环一圈
        int mid = n / 2;            // 矩阵中间的位置，例如：n为3，中间的位置就是（1,1）
        int count = 1;              // 用来给矩阵中每个空格位置赋值
        int offset = 1;             // 每一圈循环都需要控制每一条边的遍历长度
        int i, j;
        // 开始转圈填充
        while (loop--)
        {
            i = startx;
            j = starty;

            // 从下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右（左闭右开）
            for (j = starty; j < starty + n - offset; j++)
            {
                res[startx][j] = count++;
            }
            // 模拟填充左列从上到下（左闭右开）
            for (i = startx; i < startx + n - offset; i++)
            {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左（左闭右开）
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上（左闭右开）
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始的位置要各自加1
            // 例如，第一圈的起始位置是(0.0),第二圈的起始位置是（1,1）
            startx++;
            starty++;

            // offset 用于控制每一圈中每一条边遍历的长度

            offset += 2;
        }

        // 如果n为奇数，则需要单独为矩阵最中间的位置赋值
        if (n % 2)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};
```

# 2.删除链表元素(虚拟头节点)

力扣[203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)

描述：给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

![img](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //采用虚拟节点的方法
        ListNode* dummyHead = new ListNode(0);      //设置一个虚拟头节点
        dummyHead->next = head;             //将虚拟头节点指向head，方便后面执行删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL){
            if(cur->next->val == val){
                ListNode* temp = cur->next;
                cur ->next = cur->next->next;
                delete temp;    //使用c++时需要手动清理内存
            }else{
                cur = cur->next;
            }
            
        }
        head = dummyHead ->next;
        delete dummyHead;
        return head;
    }
};
```

# 3.反转链表

力扣[206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

描述：给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

## 1.双指针法

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;  //保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            //保存cur的下一个节点，因为接下来要改变cur->next的指向
            temp = cur ->next;
            cur ->next = pre;   //反转操作
            //更新pre和cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
```

## 2.递归法

```c++
class solution()
{
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == nullptr)  return pre;
        ListNode* temp = cur->next;
        cur -> next = pre;
        //可以与双指针法的代码对比，如下递归的代码，起始就是做了这两步
        //pre = cur;
        //cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head){
        //和双指针法的初始化是一样的逻辑
        //listNode* cur = head;
        //ListNode* pre = nullpter;
        return reverse(nullptr,head); 
    }
}
```

# 4.删除链表的倒数第N个结点

力扣[19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

描述：给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

![img](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

解决代码

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //用快慢双指针的方法处理，同时设置虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n-- && fast != nullptr){
            fast = fast->next;
        }

        //fast再提前移动一步，因为需要让slow指向删除节点的上一个节点
        fast = fast->next;
        while (fast != nullptr){
            fast = fast-> next;
            slow = slow->next;
        }
        slow ->next = slow->next->next;
        return dummyHead->next;
    }
};
```

# 5.环形链表

力扣[142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

描述：

给定一个链表的头节点  `head` ，返回链表开始入环的第一个节点。 *如果链表无环，则返回 `null`。*

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（**索引从 0 开始**）。如果 `pos` 是 `-1`，则在该链表中没有环。**注意：`pos` 不作为参数进行传递**，仅仅是为了标识链表的实际情况。

**不允许修改** 链表。

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```

难点1：判断是否有环

可以用快慢指针的方法，fast指针每次走两步，slow指针每次走一步，如果存在环，则fast指针和slow指针一定能在环中某节点相遇

难点2：寻找环的路口

让指针1从头节点出发，另一个指针2从相遇节点出发，这两个指针每次一起只移动一个节点，那么这两个指针相遇的节点就是环的入口节点。

```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            //快慢指针相遇，此时从head和相遇点同时查找直至相遇
            if(slow == fast){
                ListNode* index1 =fast;
                ListNode* index2 = head;
                while (index1!= index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;  //返回环的入口
            }

        } 
        return NULL;
    }
};
```

