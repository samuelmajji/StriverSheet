
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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int i=k;
        ListNode* temp1=head;
        while(i&&temp1){
            ListNode* dup=temp1;
            temp1=temp1->next;
            if(i-1==0) dup->next=NULL;
            i--;
        }
        if(i>0) {
            return head;
        }
        ListNode* temp2 = reverseList(temp);
        temp1 = reverseKGroup(temp1, k);
        head->next=temp1;
        return temp2;
    }
};