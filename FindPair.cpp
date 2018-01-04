#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    long long i, n, k, l, m, amount;
    long long a;
    vector <long long> v;

    cin>>n;
    cin>>k;

    for(i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    k=k-1;//because a[] starts from i=0
    l=k/n;

    amount=count(v.begin(), v.end(), v[l]);

    if(amount==1)
    {
        m=k%n;
    }
    else
    {
        for(i=0; i<n; i++)
            if(v[i]==v[l])
                break;
        m=(k-(i*n))/amount;
    }


    cout<<v[l]<<" "<<v[m]<<endl;

    return 0;
}
