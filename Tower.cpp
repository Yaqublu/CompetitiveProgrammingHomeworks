#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int i, n, amount, diff_num, number, max;
    int a[1001];

        cin>>n;

        vector <int> v;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            v.push_back(a[i]);
        }


        std::sort(v.begin(),v.end());



        number=-1;
        diff_num=0;
        amount=0;
        max=0;

        while(!v.empty())
        {
            if(v.back()!=number)
            {
                amount=1;
                number=v.back();
                v.pop_back();
                diff_num++;
            }
            else
            {
                amount++;
                v.pop_back();
            }

            if(amount>max)
                max=amount;
        }

        cout<<max<<" "<<diff_num<<endl;
    return 0;
}
