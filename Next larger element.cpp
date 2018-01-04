#include <iostream>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;


int main()
{
    int T, t, i, n, next, element;


    cin>>T;
    for(t=0; t<T; t++)
    {
        cin>>n;

        stack <int> s;
        int a[1001];

        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }

        s.push(0);

        for(i=1; i<n; i++)
        {
            next=i;

            while(!s.empty())
            {
                element=s.top();
                s.pop();
                if(a[next]>a[element])
                {
                    a[element]=a[next];
                }
                else
                {
                    s.push(element);
                    break;
                }
            }

            s.push(next);

        }

        while(!s.empty())
        {
            element=s.top();
            s.pop();
            a[element]=-1;
        }

        for(i=0; i<n; i++)
            cout<<a[i]<<" ";
         cout<<endl;
    }

    return 0;
}
