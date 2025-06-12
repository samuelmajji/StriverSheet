
#include <vector>
#include <algorithm>  // for std::count
using namespace std;

struct ListNode {
      int val;
       ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head; 
        if(!head) return head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return slow;
        }
        return fast?fast->next:fast;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = hasCycle(head);
        if(fast==NULL) return fast;
        ListNode *slow = head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};