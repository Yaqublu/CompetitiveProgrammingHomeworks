#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin>>str;

    int n = str.length();
    //char ch[n];

    int h=-1, e=-1, l1=-1, l2=-1, o=-1, i;

    for(i=n-1; i>=0; i--)
        if(str[i]=='o')
        {
           o=i;
           break;
        }

    for(i=o-1; i>=0; i--)
        if(str[i]=='l')
        {
           l2=i;
           break;
        }

    for(i=l2-1; i>=0; i--)
        if(str[i]=='l')
        {
           l1=i;
           break;
        }

    for(i=l1-1; i>=0; i--)
        if(str[i]=='e')
        {
           e=i;
           break;
        }

    for(i=e-1; i>=0; i--)
        if(str[i]=='h')
        {
           h=i;
           break;
        }


    if(h!=-1 && e!=-1 && l1!=-1 && l2!=-1 && o!=-1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
