#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    cin>>n;
    string str;
    cin>>str;

    int s=1; // for '10101' we will find 4 where str[i]!=str[i-1]. But lenght is 5. So we initialize s=1.

    for(i=1; i<n; i++)
        if(str[i]!=str[i-1])
            s++;
    cout<<min(n, s+2)<<endl;

    return 0;
}
