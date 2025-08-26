#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode();
        ListNode* current = node;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; 
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; 
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        ListNode* result = node->next;
        delete node;
        return result;
    }
};

ListNode* createList(int numbers[], int size) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int i = 0; i < size; ++i) {
        current->next = new ListNode(numbers[i]);
        current = current->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;
    
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    std::cout << "List 1: ";
    printList(l1);
    
    std::cout << "List 2: ";
    printList(l2);

    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    std::cout << "\nSum of the two lists: ";
    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);
    
    return 0;
}