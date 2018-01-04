#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct myTree
{
	int degree;
	int xorSum;
};

bool comparison(myTree a, myTree b)
{
	return a.degree<b.degree;
}

int main()
{
    int n, i, d, s, k=0, m=0;
	cin>>n;
	vector <myTree> v(n);
	int leaf[n-1];

	for(i=0; i<n; i++)
	 {
	 	cin>>d>>s;
	 	m += d;
	 	v[i].degree=d;
	 	v[i].xorSum=s;

	 	if(d==1)
        {
            leaf[k]=i;
            k++;
        }
	 }

	 cout<<m/2<<endl;


	for(i=0; i<k; i++)
	{
        int index = leaf[i];
		if(v[index].degree==1)
		{
		    cout<<index<<" "<<v[index].xorSum<<endl;
			v[v[index].xorSum].xorSum = v[v[index].xorSum].xorSum^index;
			v[v[index].xorSum].degree--;

			if(v[v[index].xorSum].degree==1)
                leaf[k++]=v[index].xorSum;
		}
	}

	return 0;
}
