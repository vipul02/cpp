#include<iostream.h>
#include<conio.h>
//#include<limits.h>
void printPar(int i, int j, int n, int *bracket, char &name)
{
	if(i==j)
	{
		cout<<name++;
		return;
	}
	cout<<"(";
	printPar(i, *((bracket+i*n)+j), n, bracket, name);
	printPar(*((bracket+i*n)+j)+1, j, n, bracket, name);
	cout<<")";
}
void matrixChainOrder(int p[], int n)
{
	int m[5][5]={0};
	int bracket[10][10];
	//for(int i=1;i<n;i++)
	//	m[i][i] = 0;
	int j,min,q;
	for(int d=1;d<n-1;d++)
	{
		for(int i=1;i<n-d;i++)
		{
			j = i+d;
			min = 32767;
			for(int k=i; k<=j-1;k++)
			{
				cout<<"1:"<<m[i][k]<<" 2:"<<m[k+1][j]<<endl;
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				cout<<endl<<q<<endl;

				if(q<min)
				{
					min = q;

					//bracket[i][j] = k;
				}
				m[i][j]=min;
			}
		}
	}
	char name = 'A';
	cout<<"\nOptimal Parenthesization is :";
	printPar(1, n-1, n, (int *)bracket, name);
	cout<<"\nOptimal Cost is:"<<m[1][n-1];
}

void main()
{
	clrscr();
	int arr[] = {4, 2, 3, 5, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	matrixChainOrder(arr, n);
	getch();
}