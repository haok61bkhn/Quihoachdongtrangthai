#include<bits/stdc++.h>
#define Nmax int(1e5)+100

using namespace std;
long int f[20][Nmax],s,a[5][Nmax];
int i,j,k,n,b[8]  ={0,1,2,4,5,8,9,10};
//====================================
int Find(int s,int i)
{
	return((s>>i) & 1);
}
//===================================
int Kt(int i,int j)
{
	for(int k=0;k<4;k++)
	  if(Find(i,k)*Find(j,k)==1) return 0;
	return(1);
}	
//==========================================
long int Sum(int s,int j)
{ long int s1=0;
	for(int i=0;i<=3;i++)
	   if(Find(s,i)==1) s1+=a[i+1][j];// find(s,i) tim bit thu i cua trang thai s;
	return s1;  
}
//========================================
void Init()
{  //freopen("int.txt","r",stdin);
	cin>>n;
	long kq=-100000;
	for(i=1;i<=4;i++)
	  for(j=1;j<=n;j++)
	    {
	     cin>>a[i][j];
	     kq=max(kq,a[i][j]);
	    }
	int last=8;
	 for(i=1;i<=n+1;i++)
	    for(j=0;j<last;j++)
	      { s=Sum(b[j],i);//tong trang thai j cua cot i;
	        f[b[j]][i]=-1000000;// fij trang thai j cua cot i;
	      	for(k=0;k<last;k++)
	          if(Kt(b[j],b[k])) // kiemtra (Trang thai j va trang thai k) 
			      f[b[j]][i]=max(f[b[j]][i],s+f[b[k]][i-1]);
		  }
   f[0][n+1]==0? cout<<kq:cout<<f[0][n+1];
		
}
//==========================================
main()
{
	Init();
}
