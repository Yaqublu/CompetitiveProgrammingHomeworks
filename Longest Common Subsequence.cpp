#include <iostream>
#include <algorithm>

using namespace std;

/*
int LCS(int i, int j, string S1, string S2)
{
    if(i<0 || j<0)
        return 0;
    if(S1[i]==S2[j])
       return 1 + LCS(i-1, j-1, S1, S2);

    return max(LCS(i-1, j, S1, S2), LCS(i, j-1, S1, S2));
}

*/

int main()
{
    int t, T;
    cin>>T;
    for(t=0; t<T; t++)
    {
        int n, m, i, j;
        string S1, S2;
        cin>>n>>m;
        cin>>S1;
        cin>>S2;

        int lcs[n+1][m+1];

        for(i=0; i<=n; i++)
            lcs[i][0]=0;
        for(j=0; j<=m; j++)
            lcs[0][j]=0;

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                if(S1[i-1]==S2[j-1])  //index of string starts from 0 ends in n-1
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else if (lcs[i][j-1]>lcs[i-1][j])
                    lcs[i][j]=lcs[i][j-1];
                else
                    lcs[i][j]=lcs[i-1][j];
            }

        cout<<lcs[n][m]<<endl;

        //cout<<LCS(n-1, m-1, S1, S2)<<endl;
    }
    return 0;
}
