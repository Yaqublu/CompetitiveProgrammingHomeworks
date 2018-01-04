#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int T, n, t, i, j, k;
    int a[101];
    cin>>T;

    for(t=0; t<T; t++)
    {
        cin>>n; cin>>k;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }

        deque <int> d(k);

        for(i=0; i<k; i++)
        {
           while((!d.empty()) && a[i]>=a[d.back()])
            {
                d.pop_back();
            }
            d.push_back(i);
        }

        for(i=k; i<n; i++)
        {
            cout<<a[d.front()]<<" ";

            while((!d.empty()) && d.front()<=i-k)
            {
                d.pop_front();
            }

            while((!d.empty()) && a[i]>=a[d.back()])
            {
                d.pop_back();
            }

            d.push_back(i);

        }

        cout<<a[d.front()]<<endl;


    }
    return 0;


}
