#include<iostream.h>
#include<conio.h>
int max(int x, int y)
{
	return ((x>y)?x:y);
}
void main()
{
	clrscr();
	int p[5] = {0,1,2,5,6};
	int wt[5] = {0,2,3,4,5};
	int m=8, n=4;
	int k[5][9];
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=m;w++)
		{
			if(i==0||w==0)
				k[i][w]=0;
			else if(wt[i] <= w)
				k[i][w] = max(k[i-1][w], k[i-1][w-wt[i]]+p[i]);
			else
				k[i][w] = k[i-1][w];
		}
	}
	for(i = 0;i<=n;i++){
		for(int j=0;j<=m;j++)
			cout<<k[i][j]<<"\t";
		cout<<endl;
	}
	//cout<<k[n][m];
	getch();
}