
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        while(node->next->next){
            node=node->next;
            node->val=node->next->val;
        }
        node->next=NULL;
    }
};