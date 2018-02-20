#include <bits/stdc++.h>

using namespace std;


int table[27][27];
string s[101];
int n;
bool visited[27];
vector <int> new_alf;

void dfs(int v, int start)
{
    visited[v] = true;

    for(int i = 0; i < 26; i++)
    {
        if(table[v][i])
        {
            if(i == start && visited[i])
            {
                printf("Impossible");
                exit(0);
            }
            if(!visited[i])
                dfs(i, start);
        }
    }
    new_alf.push_back(v);
}

int main()
{

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];


    for(int i = 1; i < n; i++)
    {
            bool ok = false;
            for(int j = 0; j < min(s[i].length(), s[i-1].length()); ++j)
            {
                if(s[i][j] != s[i-1][j])
                {
                    int x = s[i-1][j] - 'a';
                    int y = s[i][j] - 'a';

                    table[x][y] = 1;
                    ok = true;
                    break;
                }
            }

            if(!ok && s[i-1].length() > s[i].length())
            {
                cout << "Impossible";
                exit(0);
            }
    }

    for(int i = 0; i < 26; i++)
    {
        if(!visited[i])
            dfs(i, i);
    }

    reverse(new_alf.begin(), new_alf.end());

    for(int i = 0; i < new_alf.size(); i++)
        cout << char(new_alf[i] + 'a');
    return 0;
}
