#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,i, j;
    cin>>n;


    vector < pair<int, string> > v(n);
    for(i=0; i<n; i++)
        cin>>v[i].second>>v[i].first;

    sort(v.begin(), v.end());

    int a[n+1];

    a[0]=150;

    for(i=0; i<n; i++)
    {
        if(v[i].first>i)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
        {
            for(j=0; j<i; j++)
            if(v[j].first>=v[i].first)
                v[j].first++;
        }
    }

    for(i=0; i<n; i++)
        cout<<v[i].second<<" "<<3001-v[i].first<<endl;


    return 0;
}
