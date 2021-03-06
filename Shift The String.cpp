#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int ComputePrefix(string P, int n, int *prefix)
{
    int q=0, i=1;
    prefix[0]=0;


    while(i<n)
    {
        if(P[i]==P[q])
        {
            q++;
            prefix[i]=q;
            i++;
        }
        else if(P[i]!=P[q])
        {
            if(q!=0)
                q=prefix[q-1];
            else
            {
                prefix[i]=0;
                i++;
            }
        }
    }
}

int KMP(string T, string P, int n)
{
    int prefix[n];
    ComputePrefix(P, n, prefix);

    int i=0, j=0;
    int max=0, index=-1;

    while(i<n)
    {
        if(P[j]==T[i])
        {
            i++;
            j++;
        }
        if(j>max)
        {
            index=i-j;
            max=j;
        }
        else if(i<n && P[j]!=T[i])
        {
            if(j!=0)
                j=prefix[j-1];
            else
                i=i+1;
        }
    }
    return index;
}

int main()
{
    int n;
    string a, b;
    cin>>n;
    cin>>a;
    cin>>b;
    b=b+b;

    cout<<KMP(b, a, n)<<endl;

    return 0;
}
