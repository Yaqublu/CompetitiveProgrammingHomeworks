#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int EditDistance(string str1, string str2, int n, int m)
{
	long long LP[m+1][n+1];
	int i, j;

	for(i=0; i<=n; i++)
		LP[0][i] = i;

	for(i=0; i<=m; i++)
		LP[i][0] = i;

	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(str1[j-1]==str2[i-1])
				LP[i][j]=LP[i-1][j-1];
			else
				LP[i][j] = min(LP[i-1][j-1], min(LP[i-1][j], LP[i][j-1])) + 1;
		}
	}
/*
	for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
            cout<<LP[i][j]<<" ";
        cout<<endl;
    }
*/
	return LP[m][n];
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    int t, T;
    cin>>T;

    for(t=0; t<T; t++)
    {
        int n, m;
        cin>>n>>m;

        string str1, str2;
        cin>>str1;
        cin>>str2;

        cout<<EditDistance(str1, str2, n, m)<<endl;
    }

    return 0;
}

/*
1
84 87
lrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoq
hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcaceh
*/
