#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int visited[60][60];
vector <string> str;
int n, m, countt;

void travel(int i, int j)
{
    if(str[i][j]=='O')
    {
        visited[i][j]=1;
    }

    //if node is X and already visited then look for other 'X' neigbhours
    else if(str[i][j]=='X' && visited[i][j])
    {
        if(i<n-1)
        {
            visited[i+1][j]=1;
            travel(i+1, j);
        }

        if(j<m-1)
        {
            visited[i][j+1]=1;
            travel(i, j+1);
        }

        if(j>0 && !visited[i][j-1])
        {
            visited[i][j-1]=1;
            travel(i, j-1);
        }

        if(i>0 && !visited[i-1][j])
        {
            visited[i-1][j]=1;
            travel(i-1, j);
        }

    }
    // if node is 'X' and it hasn't been visited
    else if(str[i][j]=='X' && !visited[i][j])
    {
        visited[i][j]=1;
        bool rght = 0, btn = 0;

            if(i<n-1)
                if(str[i+1][j]=='X' && visited[i+1][j])
                    rght=1;

            if(j<m-1)
                if(str[i][j+1]=='X' && visited[i][j+1])
                    btn=1;


            if(rght==0 && btn==0)
            {
                //cout<<i<<" "<<j<<endl;
                countt++;
                if(i<n-1)
                {
                    visited[i+1][j]=1;
                    travel(i+1, j);
                }

                if(j<m-1)
                {
                    visited[i][j+1]=1;
                    travel(i, j+1);
                }
            }

            else
            {
                if(i<n-1)
                {
                    visited[i+1][j]=1;
                    travel(i+1, j);
                }

                if(j<m-1)
                {
                    visited[i][j+1]=1;
                    travel(i, j+1);
                }
            }

        }


}


int main()
{
    int t, T;

    cin>>T;

    for(t=0; t<T; t++)
    {
        int i, j;
        countt=0;
        cin>>n>>m;

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                visited[i][j]=0;

        string a;
        for(i=0; i<n; i++)
        {
            cin>>a;
            str.push_back(a);
        }

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(!visited[i][j])
                    travel(i, j);

        cout<<countt<<endl;
        str.clear();

    }


    return 0;
}
