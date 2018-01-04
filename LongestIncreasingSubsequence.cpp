#include <iostream>

using namespace std;

int LIS(int n, int a[])
{
    int lib[n], max;

    lib[0]=1;
    for(int i=1; i<n; i++)
    {
        max=0;
        for(int j=0; j<i; j++)
        {
            if(a[j]<a[i] && max<lib[j])
                max=lib[j];
        }
        lib[i]=1+max;
    }

    max=0;
    for(int i=0; i<n; i++)
        if(lib[i]>max)
            max=lib[i];

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

        cout<<LIS(n, a)<<endl;

    }
    return 0;
}
