// 单链表
struct ListNode
{
    int val;                                   // 节点上存储的元素
    ListNode *next;                            // 指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 节点的构造函数
}

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 采用虚拟节点的方法
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头节点
        dummyHead->next = head;                // 将虚拟头节点指向head，方便后面执行删除操作
        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp; // 使用c++时需要手动清理内存
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};