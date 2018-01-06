#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<double, int> > obj;

int main()
{
    int t, T;
    cin>>T;
    for(t=0; t<T; t++)
    {
        int n, W, i, j, maxValue=0, weight=0;
        cin>>n;
        cin>>W;

        int v[n+1], w[n+1];
        for(i=1; i<=n; i++)
            cin>>v[i];
        for(i=1; i<=n; i++)
            cin>>w[i];

        int KS[n+1][W+1];
//v[] and w[] starts from 1...n so below we dont need to write w[i-1]
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=W; j++)
            {
               if (i==0 || j==0)
                   KS[i][j] = 0;
               else if (w[i] <= j)
                     KS[i][j] = max(v[i] + KS[i-1][j-w[i]],   KS[i-1][j]);
               else
                     KS[i][j] = KS[i-1][j];
            }
        }


        cout<<KS[n][W]<<endl;


    }
    return 0;
}
