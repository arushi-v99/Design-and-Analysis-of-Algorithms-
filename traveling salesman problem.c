#include <stdio.h>
int n, cost[10][10],visited[10];
int mincost=999999;
void tsp(int city,int count, int total) {
	int i;
	if (count==n) {
		if (cost[city][0]!=-1) {
			total+=cost[city][0];
			if (total<mincost)
				mincost=total;
		}
		return;
	}
	for (i=0;i<n;i++) {
		if (!visited[i] && cost[city][i]!=-1) {
			visited[i]=1;
			tsp(i,count+1,total+cost[city][i]);
			visited[i]=0;
		}
	}
}
void main() {
	int i,j;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	visited[0]=1;
	tsp(0,1,0);
	printf("%d",mincost);
}