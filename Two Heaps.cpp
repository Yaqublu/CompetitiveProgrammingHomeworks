#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, i, a[200];
    vector <pair <int, int> > v;
    cin>>n;
    for(i=0; i<2*n; i++)
    {
        cin>>a[i];
        v.push_back(std::make_pair(a[i], i));
    }

    sort(v.begin(), v.end());

    int count=0, heapArray[3], num=0;
    a[v[0].second]=1;
    a[v[1].second]=2;
    heapArray[0]=0;
    heapArray[1]=0;

    for(i=0; i<2*n; i++)
    {
        if(v[i].first!=v[i-1].first && v[i].first!=v[i+1].first)
        {
            a[v[i].second]=count%2;
            count++;
            heapArray[count%2]++;
        }
    }
    for(i=0; i<2*n; i++)
    {
        if(v[i].first==v[i-1].first || v[i].first==v[i+1].first)
        {
            a[v[i].second]=count%2;
            if(num!=v[i].first)
            {
                num=v[i].first;
                heapArray[count%2]++;
                heapArray[(count+1)%2]++;
            }
            count++;
        }

    }





    cout<<heapArray[0]*heapArray[1]<<endl;
    for(i=0; i<2*n; i++)
    {
        cout<<a[i]+1<<" ";
    }


    return 0;
}
