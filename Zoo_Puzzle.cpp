#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010],b[200010];
int main()
{
	ll n,i,x,y,t;
	cin>>t;
	ll qrs=1;
	while(t--)
	{
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)x=i;
	}
	for(i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1)y=i;
	}
	for(i=1;i<=n;i++){
		if(!a[x])++x; if(!b[y])++y;
		if(x>n)x=1; if(y>n)y=1;
		if(a[x]!=b[y])
		break;
		++x; ++y;
		if(x>n)x=1; if(y>n)y=1;
	}
	if(i>n)
	cout<<"YES"<<endl;
	else 
	cout<<"NO"<<endl;
	}
	cout<<"changed";
}
