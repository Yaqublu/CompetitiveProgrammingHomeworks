#include <iostream>

using namespace std;

int n;

int Merge(int a[], int first, int half, int last)
{
    int i, j, k;
    int counter=0;
    int b[(last-first)+1];
     i=first;
     j=half+1;
     k=0;

     while(i<=half && j<=last)
     {
         if(a[i]<a[j])
         {
            b[k]=a[i];
             i++;
             k++;
         }
         else
         {
            b[k]=a[j];
             j++;
             k++;
             counter += half-i+1;
         }
     }

     while(i<=half)
     {
            b[k]=a[i];
             i++;
             k++;
     }

     while(j<=last)
     {
            b[k]=a[j];
             j++;
             k++;
     }

     for(i=first; i<=last; i++)
        a[i]=b[i];

     return counter;

}

int MergeSort(int a[], int first, int last)
{
    if(first>=last)
        return 0;
    else
    {
        int half=(first+last)/2;

        int l = MergeSort(a, first, half);
        int r = MergeSort(a, half+1, last);

        return l + r + Merge(a, first, half, last);
    }
}

int main()
{
    int i, test, t;

    cin>>test;
    for(t=0; t<test; t++)
    {
        cin>>n;
        int a[n];
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }

        int counter = MergeSort(a, 0, n-1);

        cout<<"counter: "<<counter<<endl;
    }
    return 0;
}
