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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode *prev=NULL,*ans;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            ListNode *currnode=curr.second;
            if(prev){
                prev->next=currnode;
            }
            else{
                ans=currnode;
            }
            prev=currnode;
            if(currnode->next){
                pq.push({currnode->next->val,currnode->next});
            }
        }
        return ans;
    }
};
