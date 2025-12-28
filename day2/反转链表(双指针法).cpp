class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp; // 保存cur的下一个节点
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur)
        {
            // 保存cur的下一个节点，因为接下来要改变cur->next的指向
            temp = cur->next;
            cur->next = pre; // 反转操作
            // 更新pre和cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
