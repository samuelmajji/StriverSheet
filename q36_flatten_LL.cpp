
#include <vector>
#include <algorithm>  // for std::count
using namespace std;

struct Node {
      int val;
       Node *next;
       Node *prev;
       Node *child;

      Node() : val(0), next(nullptr) {}
      Node(int x) : val(x), next(nullptr) {}
      Node(int x, Node *next) : val(x), next(next) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr) {
            // If no child, move to next node
            if (!curr->child) {
                curr = curr->next;
                continue;
            }

            // Save the next node
            Node* next = curr->next;

            // Flatten the child list in place
            Node* child = curr->child;
            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;

            // Find the tail of the child list
            Node* tail = child;
            while (tail->next) tail = tail->next;

            // Connect tail to the saved next
            tail->next = next;
            if (next) next->prev = tail;

            // Move to next node
            curr = curr->next;
        }

        return head;
    }
};