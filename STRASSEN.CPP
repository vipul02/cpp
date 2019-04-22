#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int X[2][2], Y[2][2], Z[2][2], M[7];
	cout<<"\nEnter elements of first matrix:\n";
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			cin>>X[i][j];
	cout<<"\nEnter elements of second matrix:\n";
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			cin>>Y[i][j];
	M[0] = X[0][0]*(Y[0][1] - Y[1][1]);
	M[1] = Y[1][1]*(X[0][0] + X[0][1]);
	M[2] = Y[0][0]*(X[1][0] + X[1][1]);
	M[3] = X[1][1]*(Y[1][0] - Y[0][0]);
	M[4] = (X[0][0]+X[1][1])*(Y[0][0] + Y[1][1]);
	M[5] = (X[0][1]-X[1][1])*(Y[1][0] + Y[1][1]);
	M[6] = (X[0][0]-X[1][0])*(Y[0][0] + Y[0][1]);
	Z[0][0] = M[5] + M[4] + M[3] - M[1];
	Z[0][1] = M[0] + M[1];
	Z[1][0] = M[2] + M[3];
	Z[1][1] = (M[0] + M[4]) - (M[2] + M[6]);
	cout<<"\nMatrix Multiplication(X * Y):\n";
	for(i=0;i<2;i++){
		for(j=0;j<2;j++)
			cout<<Z[i][j]<<"\t";
		cout<<"\n";
	}
	getch();
}