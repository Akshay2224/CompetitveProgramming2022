/*

Problem
While the most typical type of dice have 6 sides, each of which shows a different integer 1 through 6, there are many games that use other types. In particular, a dk is a die with k sides, each of which shows a different integer 1 through k. A d6 is a typical die, a d4 has four sides, and a d1000000 has one million sides.

Dice from sample case 1

In this problem, we start with a collection of N dice. The i-th die is a dSi, that is, it has Si sides showing integers 1 through Si. A straight of length ℓ starting at x is the list of integers x,x+1,…,x+(ℓ−1). We want to choose some of the dice (possibly all) and pick one number from each to form a straight. What is the longest straight we can form in this way?

Sample Input
4
4
6 10 12 8
6
5 4 5 4 4 4
10
10 10 7 6 7 4 4 5 7 4
1
10


Sample Output
Case #1: 4
Case #2: 5
Case #3: 9
Case #4: 1


*/

#include<bits/stdc++.h>
using namespace std;

void solve(int t)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int max1=0;
    int l=0;
    for(int i=0;i<n;i++)
    {
        if((max1+1)<=arr[i])
        {
            max1++;
        }
    }
    cout<<"Case #"<<t<<": ";
    cout<<max1;
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve(i+1);
    }
}
