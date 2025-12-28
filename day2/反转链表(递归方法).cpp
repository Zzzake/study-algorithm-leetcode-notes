// 单链表
struct ListNode
{
    int val;                                   // 节点上存储的元素
    ListNode *next;                            // 指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 节点的构造函数
}

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