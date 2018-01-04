#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i, j;
    vector <int> alice;
    int sum_a=0, sum_b;

    cin>>n;

    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(i=0; i<n; i++)
    {
        sum_a +=a[i];
        alice.push_back(sum_a);
    }



    i=0; j=n-1;
    sum_b=a[n-1];

    while(i<j-1)
    {
        if(alice[i]<=sum_b)
            i++;
        else
        {
            j--;
            sum_b += a[j];
        }
    }

    cout<<i+1<<" "<<n-1-i<<endl;

    return 0;
}
