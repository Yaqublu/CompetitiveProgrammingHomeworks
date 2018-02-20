#include <bits/stdc++.h>
using namespace std;

const int num = 200001;
int n, l[num], r[num], base[num], ans[num], bit[num];

int sum(int i)
{
	int ans = 0;
	while(i>0)
    {
		ans += bit[i];
		i -= (i & -i);
	}

	return ans;
}

void update(int i)
{
	while(i<=n)
    {
		bit[i]++;
		i += (i & -i);
	}
}

bool comp_r(int x, int y)
{
    return r[x]<r[y];
}

bool comp_l(int x, int y)
{
    return l[x]>l[y];
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
    {
		cin>>l[i]>>r[i];
		base[i]=i;
	}

	/*
	cout<<"ilk"<<endl;
	cout<<"base"<<endl;
    for(int i=1; i<=n; i++)
        cout<<base[i]<<" ";
    cout<<endl;
	cout<<"left"<<endl;
    for(int i=1; i<=n; i++)
        cout<<l[i]<<" ";
    cout<<endl;
	cout<<"right"<<endl;
    for(int i=1; i<=n; i++)
        cout<<r[i]<<" ";
    cout<<endl;
	*/

	sort(base+1, base+1+n, comp_r);

	/*
	cout<<endl<<"sort r"<<endl;
	cout<<"base"<<endl;
    for(int i=1; i<=n; i++)
        cout<<base[i]<<" ";
    cout<<endl;
	cout<<"left"<<endl;
    for(int i=1; i<=n; i++)
        cout<<l[i]<<" ";
    cout<<endl;
	cout<<"right"<<endl;
    for(int i=1; i<=n; i++)
        cout<<r[i]<<" ";
    cout<<endl;
	*/

	for(int i=1; i<=n; i++)
        r[base[i]] = i;

    /*
    cout<<endl<<"r[base] deyish"<<endl;
	cout<<"base"<<endl;
    for(int i=1; i<=n; i++)
        cout<<base[i]<<" ";
    cout<<endl;
	cout<<"left"<<endl;
    for(int i=1; i<=n; i++)
        cout<<l[i]<<" ";
    cout<<endl;
	cout<<"right"<<endl;
    for(int i=1; i<=n; i++)
        cout<<r[i]<<" ";
    cout<<endl;
    */

	sort(base+1,base+1+n, comp_l);

	/*
	cout<<endl<<"sort l"<<endl;
	cout<<"base"<<endl;
    for(int i=1; i<=n; i++)
        cout<<base[i]<<" ";
    cout<<endl;
	cout<<"left"<<endl;
    for(int i=1; i<=n; i++)
        cout<<l[i]<<" ";
    cout<<endl;
	cout<<"right"<<endl;
    for(int i=1; i<=n; i++)
        cout<<r[i]<<" ";
    */
	for(int i=1; i<=n; i++)
    {
		ans[base[i]] = sum(r[base[i]]);
		update(r[base[i]]);
	}

	for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;

	return 0;
}
