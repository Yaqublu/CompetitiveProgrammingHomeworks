import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		 Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        int[] a = new int[100];
        int i, t;
        int[] answ = new int[101];


        
        for(t=1; t<=T; t++)
        {
            int n = s.nextInt();
            int sum_water=0;
            
            for(i=1; i<=n; i++)
            {
                a[i] = s.nextInt();
            }
            
            int index_top=1, index_last=n, lenth=0;
            
            i=0;
            
            while(true)
            {                    

                if(a[index_top]<a[index_last] && a[index_top]>=lenth)
                {
                    sum_water += (a[index_top]-lenth)*n-a[index_top];
                    lenth=a[index_top];
                    index_top++;                    
                    n--;
                }
                else if(a[index_top]>=a[index_last] && a[index_last]>=lenth)
                {
                    sum_water += (a[index_last]-lenth)*n-a[index_last];
                    lenth=a[index_last];
                    index_last--;
                    n--;
                }
                else if(a[index_top]<=a[index_last])
                {
                    sum_water -= a[index_top];
                    index_top++;
                    n--;
                }
                else
                {
                    sum_water -= a[index_last];
                    index_last--;
                    n--;
                }    
                
                
                if(index_last==index_top)
                {  
                    sum_water -= lenth;
                    break;
                }
                
            }
            
            System.out.println(sum_water);
        }
        
	}
}