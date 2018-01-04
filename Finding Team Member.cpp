#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct team
{
    int player1;
    int player2;
    int strength;
} ;

bool comparison (team a, team b)
{
    return a.strength>b.strength;
}

int main()
{
    int i, s, n, m, j, k=1;


    cin>>n;
    m=(1+(2*n-1))*(2*n-1)/2;

    vector <team> v(m+1);
    vector <int> t(2*n+1);

    for(i=2; i<2*n+1; i++)
    {
        for(j=1; j<i; j++)
        {
            cin>>s;
            v[k].player1=i;
            v[k].player2=j;
            v[k].strength=s;
            k++;
        }
    }


    sort(v.begin(), v.end(), comparison);




    for(i=0; i<m; i++)
        if(t[v[i].player1]==0 && t[v[i].player2]==0)
        {
            t[v[i].player1]=v[i].player2;
            t[v[i].player2]=v[i].player1;
        }

    for(i=1; i<=2*n; i++)
        cout<<t[i]<<" ";
    cout<<endl;



    return 0;
}
