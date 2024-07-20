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
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* dummy = new ListNode;
        ListNode* temp = dummy;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }   
        temp->next = list1 ? list1 : list2; 
        return dummy->next;
    }
};

 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1)
        {
            return list2;
        }
        if(!list2)
        {
            return list1;
        }

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoList(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoList(list1, list2->next);
            return list2;
        }
    }