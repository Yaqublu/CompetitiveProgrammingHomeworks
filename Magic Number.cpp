#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int i, n;

    n=str.length();

    if(str[0]=='4')
    {
        cout<<"NO"<<endl;
        return 0;
    }

    for(i=n-1; i>=0; i--)
    {
        if(str[i]=='4')
        {
            if(str[i-1]=='4' && str[i-2]=='1')
                i -= 2;

            else if(str[i-1]=='1')
                i--;

            else
            {
            cout<<"NO"<<endl;
            return 0;
            }
        }

        else if(str[i]=='1')
            continue;

        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

        cout<<"YES"<<endl;

    return 0;
}
