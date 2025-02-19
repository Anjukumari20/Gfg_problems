#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Create a min-heap (priority queue)
        auto cmp = [](Node* a, Node* b) {
            return a->data > b->data; // Min-heap based on node data
        };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> minHeap(cmp);

        // Push the head of each linked list into the min-heap
        for (Node* head : arr) {
            if (head) {
                minHeap.push(head);
            }
        }

        // Dummy node to help with the merged list
        Node* dummy = new Node(0);
        Node* tail = dummy;

        // While there are nodes in the min-heap
        while (!minHeap.empty()) {
            // Get the smallest node
            Node* smallestNode = minHeap.top();
            minHeap.pop();

            // Add it to the merged list
            tail->next = smallestNode;
            tail = tail->next;

            // If there is a next node in the list, push it into the min-heap
            if (smallestNode->next) {
                minHeap.push(smallestNode->next);
            }
        }

        // The merged list is in dummy's next
        Node* mergedHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return mergedHead;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Create example linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(4);
    list2->next = new Node(5);

    Node* list3 = new Node(5);
    list3->next = new Node(6);

    Node* list4 = new Node(7);
    list4->next = new Node(8);

    vector<Node*> arr = {list1, list2, list3, list4};

    Solution sol;
    Node* mergedHead = sol.mergeKLists(arr);

    // Print the merged linked list
    printList(mergedHead);

    // Clean up memory (not shown for brevity)
    return 0;
}