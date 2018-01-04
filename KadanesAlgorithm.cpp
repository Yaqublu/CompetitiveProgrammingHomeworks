#include <iostream>
using namespace std;

int main()
{
    int T, n, t, i, j;
    int sum=0, max=0, a[10001];

    cin>>T;

    for(t=0; t<T; t++)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }

        max=a[0];
        sum=0;

        for(i=0; i<n; i++)
        {
            sum+=a[i];
            if(sum>max)
                max=sum;
            if(sum<0)
                sum=0;
        }

        cout<<max<<endl;

    }
	return 0;
}
