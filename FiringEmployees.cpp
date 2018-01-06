#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool prime[100001]={0};
    for(int i=2;i*i<=100000;i++)
        if(!prime[i])
            for(int j=i*i;j<=100000;j+=i)
                prime[j]=1;

    int T, t;
    cin>>T;
    for(t=0; t<T; t++)
    {
        int n;
        cin>>n;
        vector<int> v[n+1];

        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            v[a].push_back(i);
        }

        int Mr_Alfred=v[0][0];

        queue<int> q;
        q.push(Mr_Alfred);

        int employee[n+1];
        employee[Mr_Alfred]=0; //Mr. Alfred has no senior

        int ans=0;
        while(!q.empty())
        {
            int curr_emp=q.front();

            if(!prime[curr_emp+employee[curr_emp]] && curr_emp!=Mr_Alfred)
                ans++;
            q.pop();
            for(int i=0;i<v[curr_emp].size();i++)
            {
                employee[v[curr_emp][i]]=employee[curr_emp]+1;
                q.push(v[curr_emp][i]);
            }
        }
        cout<<ans<<endl;
    }
}
