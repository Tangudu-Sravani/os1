#include<iostream>
using namespace std;
int main()
{
	//fcfs
	int size;
	cout<<"  Enter the size of the array  "<<"\t";
	cin>>size;
	//input the arrival and brust time
	int a[size],b[size],p[size],ct[size],tat[size],wt[size],sum_wt=0,avg_tat,sum_tat=0;
	cout<<"arrival time of the process "<<endl;
	for(int i=0;i<size; i++)
	{
		cout<<" arrival time "<<i+1<<"\t";
		cin>>a[i];
		cout<<" burst time "<<i+1<<"\t";
		cin>>b[i];
		p[i]=i+1;
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
		  if(a[j]>a[j+1])
		  {
		  	swap(a[j],a[j+1]);
		  	swap(p[j],p[j+1]);
		  	swap(b[j],b[j+1]);
		  }
		}
	}
	ct[0]=a[0]+b[0];
	tat[0]=ct[0]-a[0];
	wt[0]=tat[0]-b[0];
	cout<<"FCFS algorithm   "<<endl;
	cout<<"process"<<"\t   "<<"arrival time"<<"\t"<<"burst time"<<"\t"<<"completion"<<"\t"<<"turn around"<<"\t"<<"waiting time"<<endl;
	for(int i=0; i<size; i++)
	{
		if(i!=0)
		{
			ct[i]=ct[i-1]+b[i];
			tat[i]=ct[i]-a[i];
			wt[i]=tat[i]-b[i];
			sum_wt+=wt[i];
			sum_tat+=tat[i];
		}
		sum_wt+=wt[0];
		cout<<p[i]<<"\t"<<"\t"<<a[i]<<"\t"<<"\t"<<b[i]<<"\t"<<ct[i]<<"\t"<<"\t"<<tat[i]<<"\t"<<"\t"<<wt[i]<<endl;		
	}
	float avg_wt;
	avg_wt=float(sum_wt)/size;
	avg_tat=float(sum_wt)/size;
	cout<<"Total waiting time = "<<sum_wt<<endl;
	cout<<"Average waiting time = "<<avg_wt<<endl;
	
	//sjf
	sum_wt=0;
	avg_wt=0;
	int sjf_avg_tat,sjf_avg_wt,sjf_ct[size],store=0,sjf_wt[size],sjf_tat[size],com=0;
//	for(int i=0;i<size;i++)
//	{
//		sjf_com[0]=a[0]+b[0];
//		sjf_tat[0]=sjf_com[0]-a[0];
//		sjf_wt[0]=sjf_tat[0]-b[0];
//		 
//	}
int i=0,j,k,small,i_d;
while(i< size)
{
	if(a[i]<=com)
	{
		j=i,store=0;
		while(a[j]<=com&& j<size)
		{
			if(a[j]<=com)
			{
				store+=1;
				j++;
			}
		}
	}
	else
	{
		a[i]=com;
		continue;
	}
	if(store==1)
	{
		com+=b[i];
		sjf_ct[i]=com;
	}
	else
	{
		k=i,small=b[i];
		i_d=k;
		for(k=i;k<j;k++)
		{
			if(b[k]<small)
			{
				small=b[k];
				i_d=k;
			}
		}
		com+=b[i_d];
		sjf_ct[i]=com;
		store=a[i];
		a[i]=a[i_d];
		a[i_d]=store;
		store=b[i];
		b[i]=b[i_d];
		b[i_d]=store;
		store=p[i];
		p[i]=p[i_d];
		p[i_d]=store;
		store=ct[i];
		ct[i]=ct[i_d];
		ct[i_d]=store;
		store=tat[i];
		tat[i]=tat[i_d];
		tat[i_d]=store;
		store=wt[i];
		wt[i]=wt[i_d];
		wt[i_d]=store;
		
		
	}
	
	 sjf_tat[i] = sjf_ct[i] - a[i];
        sjf_avg_tat += float(sjf_tat[i]) / size;
        sjf_wt[i] = sjf_tat[i] - b[i];
        sjf_avg_wt += float(sjf_wt[i]) / size;
	i++;
}
for(int i=0;i<size;i++)
{
			cout<<p[i]<<"\t"<<"\t"<<a[i]<<"\t"<<"\t"<<b[i]<<"\t"<<sjf_ct[i]<<"\t"<<"\t"<<sjf_tat[i]<<"\t"<<"\t"<<sjf_wt[i]<<endl;		

}
			
}
