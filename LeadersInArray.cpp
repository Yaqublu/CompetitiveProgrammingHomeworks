#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T, n, t, i, max;
    int a[101];
    cin>>T;

    for(t=0; t<T; t++)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }

        stack <int> s;

        max=-1;
        for(i=n-1; i>=0; i--)
        {
            if(a[i]>max)
            {
                s.push(a[i]);
                max=a[i];
            }
        }

        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
	return 0;
}
