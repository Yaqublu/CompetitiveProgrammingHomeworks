#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meet
{
    int start;
    int finish;
    int index;
};

bool comparison(meet a, meet b)
{
    return a.finish < b.finish;
}

int main()
{
    int T, t;
    cin>>T;

    for(t=0; t<T; t++)
    {
        int n, i;
        cin>>n;
        int x;
        vector <meet> v(n);

        for(i=0; i<n; i++)
        {
            cin>>x;
            v[i].start = x;
            v[i].index = i+1;
        }

        for(i=0; i<n; i++)
        {
            cin>>x;
            v[i].finish = x;
        }

        sort(v.begin(), v.end(), comparison);

        int timeF = v[0].finish;
        cout<<v[0].index<<" ";
        for(i=1; i<n; i++)
        {
            if(v[i].start>=timeF)
            {
                cout<<v[i].index<<" ";
                timeF = v[i].finish;
            }
        }
        cout<<endl;
    }
    return 0;
}
