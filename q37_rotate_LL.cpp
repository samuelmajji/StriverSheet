
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
    ListNode* rotateRight(ListNode* head, int k) {
        int c=1;
        if(!head) return head;
        if(!head->next) return head;
        ListNode* tail = head;
        ListNode* pt = head;
        while(tail->next) {
            c++;
            tail=tail->next;
        }
        k = k % c;
        if(k==0) return head;
        int i = c - k - 1;
        while(i){
            pt = pt->next;
            i--;
        }
        ListNode* ans = pt->next;
        pt->next = nullptr;
        tail->next=head;
        return ans;
        
    }
};