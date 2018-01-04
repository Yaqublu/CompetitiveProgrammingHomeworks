#include <iostream>
using namespace std;

int main() {
    int T, n, t, i, sum, a, summ;
    cin>>T;

    for(t=0; t<T; t++)
    {
        sum=0;
        cin>>n;
        for(i=0; i<n-1; i++)
        {
            cin>>a;
            sum+=a;
        }

        summ=(1+n)*n/2;

        cout<<summ-sum<<endl;
    }
	return 0;
}