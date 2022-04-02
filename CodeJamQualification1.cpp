/* 
Problem
A secret team of programmers is plotting to disrupt the programming language landscape and bring punched cards back by introducing a new language called Punched Card Python that lets people code in Python using punched cards! Like good disrupters, they are going to launch a viral campaign to promote their new language before even having the design for a prototype. For the campaign, they want to draw punched cards of different sizes in ASCII art.

Example Punched Card.

The ASCII art of a punched card they want to draw is similar to an R×C matrix without the top-left cell. That means, it has (R⋅C)−1 cells in total. Each cell is drawn in ASCII art as a period (.) surrounded by dashes (-) above and below, pipes (|) to the left and right, and plus signs (+) for each corner. Adjacent cells share the common characters in the border. Periods (.) are used to align the cells in the top row.

For example, the following is a punched card with R=3 rows and C=4 columns:

..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
There are more examples with other sizes in the samples below. Given the integers R and C describing the size of a punched card, print the ASCII art drawing of it as described above.
  
  
Sample Input-:
3
3 4
2 2
2 3

Sample Output-:
Case #1:
..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
Case #2:
..+-+
..|.|
+-+-+
|.|.|
+-+-+
Case #3:
..+-+-+
..|.|.|
+-+-+-+
|.|.|.|
+-+-+-+

*/


#include<bits/stdc++.h>
using namespace std;

void solve(int t)
{
    int n,m;
    cin>>n>>m;
    cout<<"Case #"<<t<<":"<<endl;
    int p=2*n+1;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                cout<<"..+";
                }
                else if(j>0)
                {
                    cout<<"-+";
                }
            }
            else if(i==1)
            {
                if(j==0)
                {
                cout<<"..|";
                }
                else if(j>0)
                {
                    cout<<".|";
                }
            }
            else if(i%2==0 && j==0)
            {
                cout<<"+";
            }
            else if(i%2!=0 && j==0)
            {
                cout<<"|";
            }
            if(i%2==0 && i>1)
            {
                cout<<"-+";
            }
            else if(i>1)
            {
                cout<<".|";
            }
        }
        cout<<endl;
    }
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
 
