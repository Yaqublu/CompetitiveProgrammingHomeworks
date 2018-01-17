#include <iostream>
#include <algorithm>
#include <cmath>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int sqn;

struct query
{
	int left, right, index;
} Q[200002];

bool comp(query A, query B)
{
	if( A.left/sqn < B.left/sqn )
		return true;

	if( A.left/sqn > B.left/sqn )
		return false;

	return A.right < B.right;
}

long long int A[200002], K[1000002];
long long int ans[200002], answer = 0;
int l, r;

void add(int i)
{
	answer += 2 * K[A[i]] * A[i] + A[i];
	K[A[i]]++;
	//cout<<"i="<<i<<"   a[i]="<<A[i]<<"   add K[a[i]] "<<K[A[i]]<<"     answer is "<<answer<<endl;
}

void remove(int i)
{

	K[A[i]]--;
	answer -= 2 * K[A[i]] * A[i] + A[i];
	//cout<<"i="<<i<<"   a[i]="<<A[i]<<"   remove K[a[i]] "<<K[A[i]]<<"     answer is "<<answer<<endl;

}

long long int Calculate(int i)
{
	while(l<Q[i].left )
    {
		remove(l);
		l++;
	}

	while(l>Q[i].left)
	{
		l--;
		add(l);
	}

	while(r<Q[i].right)
	{
		r++;
		add(r);
	}

	while(r>Q[i].right)
	{
		remove(r);
		r--;
	}
	return answer;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int i, n, t;
	cin>>n>>t;
	sqn = sqrt(n);

	for(i=1; i<=n; i++)
		cin>>A[i];

	for(i=1; i<=t; i++)
    {
		cin>>Q[i].left>>Q[i].right;
		Q[i].index = i;
	}

	sort( Q+1, Q+t+1, comp);

	for(i=1; i<=t; i++)
		ans[Q[i].index] = Calculate(i);

	for(i=1; i<=t; i++)
		cout<<ans[i]<<endl;


	return 0;

}
