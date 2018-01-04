#include <iostream>

using namespace std;

int main()
{
    long long n, count=0, i;
    cin>>n;
    long long a[n];

    for(i=0; i<n; i++)
        cin>>a[i];

    if(a[0]<0)
        count=-a[0];
    else
        count=a[0];


    for(i=1; i<n; i++)
    {
        if(a[i]<a[i-1])
            count += a[i-1]-a[i];
        else if(a[i]>a[i-1])
            count += a[i]-a[i-1];
    }

    cout<<count<<endl;


    return 0;
}
