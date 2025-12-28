//单链表
struct ListNode{
    int val;  //节点上存储的元素
    ListNode *next;   //指向下一个节点的指针
    ListNode (int x) : val(x) , next(nullptr) {}  //节点的构造函数
}

//通过自定义构造函数初始化节点
ListNode* head = new ListNode(5);

//使用默认构造函数初始化节点
ListNode* head = new ListNode();
head->val = 5;