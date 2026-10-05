#include <stdio.h>
void main()
{
    int n, capacity;
    scanf("%d", &n);

    int value[n], weight[n];
    
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
            {
                int include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];

                dp[i][w] = include > exclude ? include : exclude;
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("%d", dp[n][capacity]);
}
