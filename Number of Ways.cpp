#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    std::ios_base::sync_with_stdio(false);

    long long n, i, count=0;
    cin>>n;
    long long a[n], sum=0;
    vector <long long> c(n, 0);

    for(i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }


    if(sum%3!=0 || n<3)
    {
        cout<<"0"<<endl;
        return 0;
    }

    if(n==3 && a[0]!=a[1])
    {
       cout<<"0"<<endl;
        return 0;
    }

    long long prefix=0, suffix=0;


    for(i=n-1; i>=0; i--)
    {
        suffix += a[i];
        if(suffix == sum/3)
            c[i]=1;
    }



    //suffix of c[]
    for(i=n-2; i>=0; i--)
        c[i] += c[i+1];


    for(i=0; i<n-2; i++)
    {
        prefix += a[i];
        if(prefix == sum/3)
            count += c[i+2];
    }




    cout<<count<<endl;
    return 0;
}
