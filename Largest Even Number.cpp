#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int i, t, T, n, num, j;


    cin>>T;
    for(t=0; t<T; t++)
    {
        string str;

        cin>>str;
        n=str.length();
        int num;
        vector<int> v(str.begin(), str.end());
        vector<int> a(10);


        int min_even=10;


        for(i=0; i<n; i++)
        {
            num=v[i]-48;
            a[num]++;
            if(num%2==0 && num<min_even)
                min_even=num;
        }

        if(min_even!=10)
        {
            a[min_even]--;
            for(j=9; j>=0; j--)
                for(i=0; i<a[j]; i++)
                    cout<<j;
            cout<<min_even<<endl;
        }
        else
        {
            for(j=9; j>=0; j--)
                for(i=0; i<a[j]; i++)
                    cout<<j;
            cout<<endl;
        }

    }


    return 0;
}
