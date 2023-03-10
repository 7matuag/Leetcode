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
class Solution {
public:
    ListNode *head1;
    int len=0;
    Solution(ListNode* head) {
        head1=head;
        ListNode *curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
    }
    int getRandom() {
        int n=rand()%len;
        ListNode *curr=head1;
        for(int i=0;i<n;i++){
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
