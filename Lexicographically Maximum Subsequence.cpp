#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    long long n=0, i;
    char max;

    cin>>str;

    n=str.length();
    char suffixMax[n];
    int k=0;
    max=str[n-1];

    for(i=n-1; i>=0; i--)
    {
        if(str[i]>=max)
        {
            max=str[i];
            suffixMax[k]=max;
            k++;
        }

    }


    for(i=k-1; i>=0; i--)
            cout<<suffixMax[i];
    cout<<endl;

    return 0;
}
