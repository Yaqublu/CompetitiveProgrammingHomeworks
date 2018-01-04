#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int i, n, population, x, y, people;
    double r, radius=-1;


    cin>>n>>population;

    vector<pair <double, int> > v;
    v.reserve(n);

    for(i=0; i<n; i++)
    {
        cin>>x;
        cin>>y;
        cin>>people;
        r=sqrt(x*x+y*y);
        v.push_back(std::make_pair(r, people));
    }

    sort(v.begin(), v.end());

    for(i=0; i<n; i++)
    {
        population +=v[i].second;
        if(population>=1000000)
        {
            radius=v[i].first;
            break;
        }
        else
            continue;
    }

    if(radius==-1)
        cout<<-1<<endl;
    else
    {
        cout.precision(8);
        cout<<radius;
    }



    return 0;
}
