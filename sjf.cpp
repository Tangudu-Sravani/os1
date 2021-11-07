#include<iostream>
using namespace std;
int shorting(int a[],int b[],int n,int p[], int c[])
{
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
		}
	}
	cout<<endl<<endl;
	c[0]=a[0]+b[0];
	cout<<" arrival time  "<<a[0]<<"  burst time "<<b[0]<<" completion time  "<<c[0]<<endl;
	int br;
	b[0]=br;
	
//	for(int i=0; i<5; i++){
//		cout<<a[i]<<endl;
//	}
	for(int i=0; i<n; i++){
		for(int j=0; j<5-i-1; j++)
		{
			if(b[j]>b[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
		}
	}
  	for(int i=0; i<n; i++){
  		if(b[i]==br)
  		{
  			//cout<<endl;
		  }
		  else{
		  	c[i]=c[i-1]+b[i];
		cout<<" Arrrival time  "<<a[i]<<" Burst time  "<<b[i]<<"completion time "<<c[i]<<endl;

		  }
	//	cout<<" Arrrival time  "<<a[i]<<" Burst time  "<<b[i]<<endl;

}
}
int main(){
	int n;
	cout<<"Enter the number of process "<<"\t";
	cin>>n;
	int a[n],c[n],t[n],p[n],w[n],b[n];
	for(int i=0; i<n; i++)
	{
		p[i]=i;
		cout<<"Arrival time  of  process  "<<p[i]<<"\t";
		cin>>a[i];         
	}
	for(int i=0;i<n;i++){
		cout<<"Enter the process burst time  "<<p[i]<<"\t";
		cin>>b[i];
	}
	shorting(a,b,n,p,c);
}
