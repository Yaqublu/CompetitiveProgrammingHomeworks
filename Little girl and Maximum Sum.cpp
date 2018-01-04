#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  std::ios_base::sync_with_stdio(false);
    int n, i, t, l, r;

    cin>>n>>t;

    int a;
    long long sum=0;
    vector <long long> count(n);
    vector <int> array;

    for(i=0; i<n; i++)
    {
         cin>>a;
         array.push_back(a);
    }

    count.push_back(0);
    for(i=0; i<t; i++)
    {
        cin>>l>>r;
        count[l-1]++;
        count[r]--;
    }


    for(i=1; i<n; i++)
    {
        count[i] +=count[i-1];
    }


    sort(count.begin(), count.end()-1);
    sort(array.begin(), array.end());


    for(i=0; i<n; i++)
    {
        sum += count[i]*array[i];
    }
    cout<<sum<<endl;

    return 0;
}
