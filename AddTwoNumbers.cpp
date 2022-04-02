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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *tmp = new ListNode;
        ListNode *tmp1 = new ListNode;
        ListNode *tmp2 = new ListNode;
        tmp1=l1;
        tmp2=l2;
        int val2=-1,val1=-1;
        int index=0;
        while(tmp1!=NULL || tmp2!=NULL)
        {
            if(tmp1==NULL)
            {
                val1=0;
                val2=tmp2->val;
            }
            else if(tmp2==NULL)
            {
                val2=0;
                val1 = tmp1->val;
            }
            else
            {
                val2 = tmp2->val;
                val1 = tmp1->val; 
            }
            int sum = val2 + val1 + carry;
            carry=0;
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            cout<<val1<<val2<<carry<<" ";
            if(index==0)
            {
                tmp->val=sum;
                tmp->next=NULL;
                index=1;
            }
            else
            {
                ListNode *tmp3 = new ListNode;
                tmp3->val=sum;
                tmp3->next=NULL;
                ListNode *tmp4 = new ListNode;
                tmp4=tmp;
                while(tmp4->next!=NULL)
                {
                    tmp4=tmp4->next;
                }
                tmp4->next=tmp3;
            }
            if(tmp1!=NULL)
            {
            tmp1=tmp1->next;

            }
            if(tmp2!=NULL)
            {
                tmp2=tmp2->next;                
            }
        }
        if(carry!=0)
        {
         ListNode *tmp4 = new ListNode;
         tmp4=tmp;
         while(tmp4->next!=NULL)
         {
             tmp4=tmp4->next;
         }
          ListNode *tmp5 = new ListNode;
            tmp5->val = carry;
            tmp5->next=NULL;
            tmp4->next=tmp5;
        }
        return tmp;
    }
};
