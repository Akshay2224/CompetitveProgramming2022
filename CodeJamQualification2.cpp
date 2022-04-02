/*
Problem
You are part of the executive committee of the Database Design Day festivities. You are in charge of promotions and want to print three D's to create a logo of the contest. You can choose any color you want to print them, but all three have to be printed in the same color.

Illustration of Sample #1.

You were given three printers and will use each one to print one of the D's. All printers use ink from 4 individual cartridges of different colors (cyan, magenta, yellow, and black) to form any color. For these printers, a color is uniquely defined by 4 non-negative integers c, m, y, and k, which indicate the number of ink units of cyan, magenta, yellow, and black ink (respectively) needed to make the color.

The total amount of ink needed to print a single D is exactly 106 units. For example, printing a D in pure yellow would use 106 units of yellow ink and 0 from all others. Printing a D in the Code Jam red uses 0 units of cyan ink, 500000 units of magenta ink, 450000 units of yellow ink, and 50000 units of black ink.

To print a color, a printer must have at least the required amount of ink for each of its 4 color cartridges. Given the number of units of ink each printer has in each cartridge, output any color, defined as 4 non-negative integers that add up to 106, such that all three printers have enough ink to print it.

Sample Input
3
300000 200000 300000 500000
300000 200000 500000 300000
300000 500000 300000 200000
1000000 1000000 0 0
0 1000000 1000000 1000000
999999 999999 999999 999999
768763 148041 178147 984173
699508 515362 534729 714381
949704 625054 946212 951187


Sample Output
Case #1: 300000 200000 300000 200000
Case #2: IMPOSSIBLE
Case #3: 400001 100002 100003 399994

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int t)
{
    cout<<"Case #"<<t<<":";
    int top = 1000000;
    ll arr[4],arr1[4],arr2[4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i==0)
            {
                cin>>arr[j];
            }
            else if(i==1)
            {
                cin>>arr1[j];
            }
            else if(i==2)
            {
                cin>>arr2[j];
            }
        }
    }
    ll c,m,y,k;
    c = min(arr[0],min(arr1[0],arr2[0]));
    m = min(arr[1],min(arr1[1],arr2[1]));
    y = min(arr[2],min(arr1[2],arr2[2]));
    k = min(arr[3],min(arr1[3],arr2[3]));
    int sum = c+y+m+k;
    if(sum<top || (c==0 || y==0 || m==0 || k==0))
    {
        cout<<" IMPOSSIBLE"<<endl;
        return;
    }
    else if(sum==top)
    {
        cout<<" "<<c<<" "<<m<<" "<<y<<" "<<k<<endl;
        return;
    }
    else
    {
        ll arr4[4];
        arr[0]=c;arr[1]=m;arr[2]=y;arr[3]=k;
        ll div1 =  sum-top;
        int index=0;
        while(div1!=0 && index<4)
        {
            if(arr[index]-div1>0)
            {
                arr[index] =arr[index]-div1;
                div1=0;
            }
            else
            {
                ll val = abs(arr[index]-div1);
                val = val+1;
                ll now = div1-val;
                arr[index] = arr[index]-now;
                div1= div1-now;
            }
            index++;
        }
        cout<<" ";
        for(int i=0;i<4;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
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
