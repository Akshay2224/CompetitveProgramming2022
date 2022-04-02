/*

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int size1 = n+m;
        int first=-1;
        int second=-1;
        if(size1%2==0)
        {
            first = size1/2;
            second = first;
            first = first-1;
        }
        else
        {
            first=size1/2;
            first = first;
        }
        auto it = nums1.begin();
        auto it1 = nums2.begin();
        int index=0;
        int firstVal=-1,secondVal=-1;
        int l,t;
        l=n/2;t=m/2;
        while(n!=0 || m!=0)
        {
            int val,val1;
            if(n==0 || m==0)
            {
                if(n==0)
                {
                    val=INT_MAX;
                    val1 = *it1;
                }
                else if(m==0)
                {
                    val1=INT_MAX;
                    val = *it;
                }
            }
            else
            {
                val = *it;
                val1 = *it1;
            }
            if(index == first)
            {
                firstVal = min(val,val1);
                
                if(second==-1)
                {
                    break;
                }
            }
            else if(index == second)
            {            

                   secondVal = min(val,val1);
                    break;
            }
            if(val<val1)
            {
                n--;
                if(n!=0)
                {
                    it++;
                }
            }
            else
            {
                m--;
                if(m!=0)
                {
                    it1++;
                }
            }
            index++;
        }
        if(secondVal!=-1)
        {
            double sum =firstVal+secondVal;
            return double(sum/2);
        }
        else
        {
            return double(firstVal);
        }
     }
};
