#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list

//Constraints:
//The number of nodes in the list is the range[0, 5000].
//- 5000 <= Node.val <= 5000


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            curr = next;
        }
        return dummy->next;
    }
};

static vector<int> print(ListNode* head) {
    vector<int> ret;
    ListNode* curr = head;
    while (curr) {
        ret.push_back(curr->val);
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    return ret;
}

// Example1
//Input: head = [1, 2, 3, 4, 5]
//Output : [5, 4, 3, 2, 1]
TEST(reverseList, Example1) {
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 5; ++i) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    Solution s;
    ListNode* reverseHead = s.reverseList(head);
    const auto result = print(reverseHead);
    const vector<int> expected = { 5, 4, 3, 2, 1 };
    ASSERT_EQ(expected, result);
}

// Example2
//Input: head = [1, 2]
//Output : [2, 1]
TEST(reverseList, Example2) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    Solution s;
    ListNode* reverseHead = s.reverseList(head);
    const auto result = print(reverseHead);
    const vector<int> expected = { 2, 1 };
    ASSERT_EQ(expected, result);
}

//Example3
//Input: head = []
//Output : []
TEST(reverseList, Example3) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* reverseHead = s.reverseList(head);
    const auto result = print(reverseHead);
    const vector<int> expected = {};
    ASSERT_EQ(expected, result);
}
