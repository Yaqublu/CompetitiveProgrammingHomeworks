#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


int computePrefix(string str, int n)
{
    int i, k=0;
    int maxx=0;
    vector <int> pi;
    pi.push_back(0);

    for(i=1; i<n; i++)
    {
        if(k>0 && str[k]!=str[i])
            k=0;

        if(str[k]==str[i])
            k=k+1;

        pi.push_back(k);
    }
    return k;
}

int main()
{
    int t, T;
    cin>>T;
    for(t=0; t<T; t++)
    {
        string str;
        cin>>str;
        int n;
        n=str.size();
        cout<<computePrefix(str, n)<<endl;
    }
    return 0;
}
