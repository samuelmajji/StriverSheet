#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// Solution class
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;

        // Step 1: Create all nodes and store mapping
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];       // handles nullptr
            mp[curr]->random = mp[curr->random];   // handles nullptr
            curr = curr->next;
        }

        return mp[head];
    }
};

// Helper to print the list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Value: " << curr->val;
        cout << " | Random: " << (curr->random ? to_string(curr->random->val) : "NULL") << endl;
        curr = curr->next;
    }
    cout << "--------------------------" << endl;
}

// Main function to test
int main() {
    // Create original list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    // Set random pointers
    n1->random = n3; // 1 → 3
    n2->random = n1; // 2 → 1
    n3->random = nullptr;

    cout << "Original List:\n";
    printList(n1);

    // Clone the list
    Solution sol;
    Node* cloned = sol.copyRandomList(n1);

    cout << "Cloned List:\n";
    printList(cloned);

    return 0;
}