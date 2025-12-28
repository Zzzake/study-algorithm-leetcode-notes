class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 用快慢双指针的方法处理，同时设置虚拟头节点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }

        // fast再提前移动一步，因为需要让slow指向删除节点的上一个节点
        fast = fast->next;
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};