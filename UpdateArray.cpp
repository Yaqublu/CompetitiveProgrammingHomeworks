#include <iostream>
#include <vector>

using namespace std;

int main()
{

  std::ios_base::sync_with_stdio(false);

      int k, t, n, update_case, i, l, r, value, q, index;


    cin>>k;

    for(t=0; t<k; t++)
    {
        cin>>n;
        cin>>update_case;

        vector <long long> v(n+1);

        for(i=0; i<update_case; i++)
        {
            cin>>l;
            cin>>r;
            cin>>value;
            v[l] += value;
            v[r+1] += -value;
        }

        for(i=1; i<n; i++)
        {
            v[i] +=v[i-1];
        }

        cin>>q;
        for(i=0; i<q; i++)
        {
            cin>>index;
            cout<<v[index]<<endl;
        }
    }

    return 0;
}
