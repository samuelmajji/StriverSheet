
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* temp=head;
        while(temp){
            i++;
            temp=temp->next;
        }
        temp=head;
        if(i==0) return nullptr;
        if(i==1) return nullptr;
        if(i==n) {
            ListNode* temp1=head->next;
            temp->next=nullptr;
            return temp1;
        }
        for(int j=1;j<i-n;j++){
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        del->next=nullptr;
        return head;
    }
};