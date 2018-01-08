#include <iostream>

using namespace std;



int main()
{
    int a[2100];
    int b[2100];
    int c[2100];
    int n, t, i, k;
    int alength=0;
    int blength=0;
    int clength=0;

    cin>>n;

    if(n==1)
    {
        cout<<2<<endl;
        return 0;
    }

    if(n==2)
    {
        cout<<3<<endl;
        return 0;
    }

    a[0]=2;     alength=1;
    b[0]=3;     blength=1;


    for(t=3; t<=n; t++)
    {
      int q=0;
      clength=blength;

            for(i=0; i<alength; i++)
            {
                k=q+a[i]+b[i];

                if(k<10)
                {
                    c[i]=k;
                    q=0;
                }
                else
                {
                    c[i]=k-10;
                    q=1;
                }
            }

            for(i=alength; i<blength; i++)
            {
                k=q+b[i];

                if(k<10)
                {
                    c[i]=k;
                    q=0;
                }
                else
                {
                    c[i]=0;
                    q=1;
                }
            }

            if(q==1)
            {
                c[blength]=1;
                clength=blength+1;
            }

            for(i=0; i<blength; i++)
                a[i]=b[i];
            alength=blength;

            for(i=0; i<clength; i++)
                b[i]=c[i];
            blength=clength;


        }
             for(i=clength-1; i>=0; i--)
                cout<<b[i];
             cout<<endl;




    return 0;
}


