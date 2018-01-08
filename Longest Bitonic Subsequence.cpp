#include <iostream>
#include <vector>
using namespace std;

vector <int> lis;
vector <int> lds;
vector <int> lbs;


void LIS(int n, int a[])
{
    int max;
    lis.erase(lis.begin(), lis.end());

    lis.push_back(1);
    for(int i=1; i<n; i++)
    {
        max=0;
        for(int j=0; j<i; j++)
        {
            if(a[j]<a[i] && max<lis[j])
                max=lis[j];
        }
        lis.push_back(1+max);
    }
}

void LDS(int n, int a[])
{
    int max;
    lds.erase(lds.begin(), lds.end());

    lds.push_back(1);
    for(int i=n-2; i>=0; i--)
    {
        max=0;
        for(int j=n-1; j>i; j--)
        {
            if(a[j]<a[i] && max<lds[n-1-j])
                max=lds[n-1-j];
        }

        lds.push_back(1+max);
    }
}

int LBS(int n, int a[])
{
    lbs.erase(lbs.begin(), lbs.end());
    LIS(n, a);
    LDS(n, a);
    int i;
    for(i=0; i<n; i++)
    {
        lbs.push_back(lis[i]+lds[n-1-i]-1);
    }
    int max=0;
    for(i=0; i<n; i++)
        if(lbs[i]>max)
            max=lbs[i];

    return max;
}


int main()
{
    int T,t;
    cin>>T;
    for(t=0; t<T; t++)
    {
        int i, n;
        cin>>n;
        int a[n];

        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        cout<<LBS(n, a)<<endl;
    }
    return 0;
}
