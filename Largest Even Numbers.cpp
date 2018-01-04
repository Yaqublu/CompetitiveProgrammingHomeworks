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
        int a[10];

        cin>>str;
        n=str.length();
        vector<int> v(str.begin(), str.end());


        int min_even=10;
        int min_odd=11;

        for(i=0; i<10; i++)
            a[i]=0;
        for(i=0; i<n; i++)
        {
            num=v[i]-48;

            if(num%2==0 && num<min_even)
                min_even=num;
            else if(num%2==1 && num<min_odd)
                min_odd=num;

                a[num]++;
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
           a[min_odd]--;
            for(j=9; j>=0; j--)
                for(i=0; i<a[j]; i++)
                    cout<<j;
            cout<<min_odd<<endl;
        }

    }


    return 0;
}
