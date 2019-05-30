

struct list_node {
    int data;
    list_node * next;
};

// 链表反转
list_node * linked_list_reversal(list_node *head);
// 链表存环检测
bool linked_list_detect_cycle(list_node *head);


// 链表反转
// 总结: 
// 需要3个指针，1.分别指向最近的头部prev，2.当前节点cur，3.当cur不为空时的下个节点tmp
// 步骤：
// 1.将头部赋值给prev，头部的下个节点（最开始时为第二个节点）赋值给cur节点。
// 2.如果cur不为空，将当前的节点的下个节点指向头部
// 3.此时，当前的节点在最头部，cur赋值给prev，将下个节点赋值给当前
// 4.循环
list_node * linked_list_reversal(list_node *head) {
    if(head == NULL) {
        return NULL;
    }

    list_node *prev = head;
    list_node *cur = head->next;
    while(cur != NULL) {
        // 当前节点cur下个节点会指向最前面的节点，需要使用tmp先保持后面的节点
        list_node *tmp = cur->next; 
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    // 反转到最后时，最后一个指向NULL
    head->next = NULL;
    return prev;
}

// 链表存环检测
// 总结：使用快慢两个指针，则使用不同步长(快2步，慢1步)的方式进行遍历，如果不会遇到环，则会遍历到最后（NULL），否则就会快慢节点会相遇
bool linked_list_detect_cycle(list_node *head) {
    if(head == NULL) {
        return NULL;
    }
    list_node *slow = head;
    list_node *fast = head->next;

    while(slow != NULL && fast != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        // 要注意next可能为空
        if (fast->next) {
            fast = fast->next->next;    
        }
        else {
            fast = fast->next; // NULL
        }
    }
    return false;
}

int main() {

    return 0;
}
