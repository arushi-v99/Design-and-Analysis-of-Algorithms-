#include <stdio.h>
int main() {
	int m,n;
	scanf("%d %d", &m, &n);
	int A[m][n];
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	int r,p;
	scanf("%d %d",&r,&p);
	if (n!=r) {
		printf("Invalid input");
		return 0;
	}
	int B[r][p];
	for (int i=0;i<r;i++)
		for (int j=0;j<p;j++)
			scanf("%d",&B[i][j]);
	int C[m][p];
	for (int i=0;i<m;i++) {
		for (int j=0;j<p;j++) {
			C[i][j]=0;
			for (int k=0;k<n;k++) 
				C[i][j] += A[i][k]*B[k][j];
		}
	}
	for (int i=0;i<m;i++) {
		for (int j=0;j<p;j++)
			printf("%d ",C[i][j]);
		printf("\n");
	}
	return 0;
}