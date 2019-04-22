#include<iostream.h>
#include<conio.h>
float knapsack(int weight[], int val[], int n, int capacity)
{
	int currWeight = 0;
	float totalValue = 0.0;
	for(int i=0;i<n+1;i++)
	{       if(currWeight >=capacity) return totalValue;
		if((currWeight + weight[i]) < capacity)
		{
			currWeight += weight[i];
			totalValue += val[i];
		}
		else
		{
			int remain = capacity - currWeight;
			float frac = float(remain)/float(weight[i]);
			currWeight += remain;
			totalValue += float(val[i])*frac;
		}
	}
	return totalValue;
}
void main()
{
	clrscr();
	int weight[10], value[10], n, capacity;
	cout<<"\nEnter the capacity of bag(int):";
	cin>>capacity;
	cout<<"\nEnter no. of items(int)(max 10):";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nWeight "<<i+1<<": ";
		cin>>weight[i];
		cout<<"\nValue "<<i+1<<": ";
		cin>>value[i];
		cout<<"\nValue per unit weight: "<<float(value[i])/float(weight[i])<<endl;
	}
	for(i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{

			if((float(value[j])/float(weight[j])) < (float(value[j+1])/float(weight[j+1])))
			{
				cout<<"\ni = "<<i<<"\tj = "<<j<<endl;
				weight[j+1] += weight[j];
				weight[j] = weight[j+1] - weight[j];
				weight[j+1] -= weight[j];
				value[j+1] += value[j];
				value[j] = value[j+1] - value[j];
				value[j+1] -= value[j];

			}
		}
	}
	cout<<knapsack(weight, value, n ,capacity);
	getch();
}