#include <iostream>

using namespace std;

int main()
{
    long long i, n;

    char side;
    cin>>n;
    long long x[n], h[n];

    for(i=0; i<n; i++)
    {
        cin>>x[i];
        cin>>h[i];
    }

    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }

    int result=2;

    for(i=1; i<n-1; i++)
    {

        if(x[i]-h[i]>x[i-1])
            result ++;

        else if(x[i]+h[i]<x[i+1])
        {
            result ++;
            x[i] += h[i];
        }
    }

    cout<<result<<endl;
 return 0;
}
