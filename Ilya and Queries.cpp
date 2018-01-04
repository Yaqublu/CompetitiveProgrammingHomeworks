#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, n, sum=0, a, b;
    vector <int> v;
    string str;

    cin>>str;

    v.push_back(sum);
    for(i=1; i<str.length(); i++)
    {
        if(str[i]==str[i-1])
            sum += 1;

        v.push_back(sum);
    }

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a;
        cin>>b;
        cout<<v[b-1]-v[a-1]<<endl;
    }

    return 0;
}
