
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find midpoint
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle node in odd-length list
        if (fast) slow = slow->next;

        // Reverse second half
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        // Compare halves
        while (secondHalf) {
            if (secondHalf->val != firstHalf->val)
                return false;
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }

        return true;
    }
};