#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double pow(double a, int n)
{ 
	 if(n == 0) return 1; 
	 if(n == 1) return a; 
	 double t = pow(a, n/2); 
	 return t * t * pow(a, n%2); 
}
 
int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		long long n,k, num=10, count=0, ext, curr, pre, mode, diff, ext1, loop, b=1;
        cin>>n>>k;
        if(k==0)
        {
        	cout<<9<<endl;
        	continue;
		}
        b=pow(10,n);
        cout<<b<<endl;
        while(num<=b)
        {   long long countN=1, countK=0; 
			ext1=num;
			ext=num; 
			 
	        while(ext1>=10)
	        {
	        	ext1=ext1/10;
	        	++countN;
	        	
	        	curr=ext%10;
	        	ext=ext/10;
				pre=ext%10;
				diff=curr-pre;
				if(diff<0)
				diff=diff*(-1);
					
				if(diff<=k)
				{
					countK++;
				}
                else
                break;	
			}
 
	        if(countN==n)
	        {
			
				if(countK==(n-1))
				{
				   ++count;
			    }
		
			}
			
			++num;
			         
 
	   }
          cout<<count%1000000007<<endl;
	}
} 