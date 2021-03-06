#include<iostream.h>
#include<conio.h>
#include<string.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}
void lcs(char *X, char *Y, int m, int n)
{
	int L[30][30];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	int index = L[m][n];
	char lcs[30];
	lcs[index] = ' ';
	int j=n; i=m;

	while(i>0 &&j>0)
	{
		if(X[i-1]==Y[j-1])
		{
			lcs[index-1] = X[i-1];
			i--;j--;index--;
		}
		else if(L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}

	cout<<"\nLCS of "<<X<<" and "<<Y<<" is "<<lcs<<" of length "<<L[m][n];
}


void main()
{
	clrscr();
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n =strlen(Y);
	lcs(X, Y, m, n);
	getch();
}