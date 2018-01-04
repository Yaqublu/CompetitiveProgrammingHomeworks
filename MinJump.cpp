#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int Jump(int a[], int n)
{
    if(n<=1)
        return 0;

    if(a[0]==0)
        return -1;

    int maxx=a[0];
    int s=a[0]; //steps
    int count =1;

    for(int i=1; i<n; i++)
    {
        if(i==n-1)
            return count;

        s--;

        maxx=max(maxx, a[i]+i); // add i, because we want big number but at the same time it should be near to end

        if(s==0)
        {
            count++;
            if(i>=maxx)
                return -1;
            s=maxx-i; // max-i -> (a[i]+i)-j (j is current index for loop, i is the index of number that we jumped)

        }
    }
    return -1;
}


int main()
{
	int t, T;
	cin>>T;

	for(t=0; t<T; t++)
    {
	    int n, i;
	    cin>>n;

	    int a[n];
	    for(i=0; i<n; i++)
	        cin>>a[i];

	    cout<<Jump(a, n)<<endl;
	}
	return 0;
}
