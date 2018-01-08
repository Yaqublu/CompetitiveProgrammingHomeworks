#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int LPS(string str)
{
    int n=str.length();
        long long lps[n][n];
        int i, j;

        for(i=n-1; i>=0; i--)
            for(j=0; j<n; j++)
            {
                if(i==j)
                   lps[i][j]=1;
                else if(i>j)
                    lps[i][j]=0;
                else if(str[i]==str[j])
                    lps[i][j]=lps[i+1][j-1]+2;
                else
                    lps[i][j]=max(lps[i+1][j], lps[i][j-1]);

            }
    return lps[0][n-1];
}


int main()
{
    int t, T, i, j;
    cin>>T;
    for(t=0; t<T; t++)
    {
        string str;
        cin>>str;

        cout<<LPS(str)<<endl;
    }
    return 0;
}
