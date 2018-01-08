#include <iostream>
#include <string.h>

using namespace std;

/*
bool subsetSum(int i, int v, int a[])
{
    if(v<0 || i<0) return false;
    if(v==0) return true;
    if(i==0) return false;
    return (subsetSum(i-1, v, a) || subsetSum(i-1, v-a[i], a));
}
*/

int main()
{
    int T, t;
    cin>>T;
    for(t=0; t<T; t++)
    {
        int n, i, sum=0;
        cin>>n;
        int a[n];
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        if(sum%2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }

        int value=sum/2;

        bool M[n+1][value+1];

        for(i=0; i<=n; i++)
            M[i][0]=1;

        for(i=1; i<=n; i++)
            for(int v=1; v<=value; v++)
                if(v<a[i-1])
                    M[i][v] = M[i-1][v];
                else
                    M[i][v] = (M[i-1][v] || M[i-1][v-a[i]]);

        if(M[n][value])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        memset(M, 0, sizeof(M));
        memset(a, 0, sizeof(a));

    }
    return 0;
}



