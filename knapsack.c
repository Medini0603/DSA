#include <stdio.h>
#include <stdlib.h>

typedef struct knap
{
    int wt, val;
} knap;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int knapsack(knap item[], int n, int w, int optimal[])
{
    int a[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else
            {
                int index = j - item[i].wt;
                if (index < 0)
                    a[i][j] = a[i - 1][j];
                else
                    a[i][j] = max(a[i - 1][j], (item[i].val + a[i - 1][index]));
            }
        }
    }

    printf("The value matrix\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

    int rc = w, i = n, j = 0;
    int opt = 0;
    while (rc != 0 && i >= 1)
    {
        if (a[i][rc] != a[i - 1][rc])
        {
            rc = rc - item[i].wt;
            optimal[j] = i;
            opt = opt + item[i].val;
            j++;
        }
        i--;
    }

    return opt;
}

int knapsack2(knap item[], int n, int w, int optimal[])
{
    int a[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
    }

    int mf(int i, int j)
    {
        int value;
        if (a[i][j] == -1)
        {
            int index = j - item[i].wt;
            if (index < 0)
                value = mf(i - 1, j);
            else
                value = max(mf(i - 1, j), item[i].val + mf(i - 1, index));

            a[i][j] = value;
        }
        return a[i][j];
    }

    int rc = w, i = n, j = 0;
    int opt = 0;
    while (rc != 0 && i >= 1)
    {
        if (mf(i, rc) != mf(i - 1, rc))
        {
            rc = rc - item[i].wt;
            opt = opt + item[i].val;
            optimal[j] = i;
            j++;
        }
        i--;
    }

    printf("The value matrix\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            printf("%d\t", a[i][j]);
        }

        printf("\n");
    }
    return opt;
}

void main()
{
    int n;
    printf("Enter number of items\n");
    scanf("%d", &n);
    knap item[n + 1];
    printf("Enter weight and value of items one by one\n");
    int optimal[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &item[i].wt, &item[i].val);
        optimal[i] = 0;
    }
    int w;
    printf("Enter knap wieght\n");
    scanf("%d", &w);
    int sum = knapsack(item, n, w, optimal);
    printf("Optimal value= %d\n", sum);
    for (int i = 0; i < n; i++)
    {
        if (optimal[i] == 0)
            break;
        printf("%d\t", optimal[i]);
    }
    printf("\n");

    int sum2 = knapsack2(item, n, w, optimal);
    printf("Optimal value= %d\n", sum2);
    for (int i = 0; i < n; i++)
    {
        if (optimal[i] == 0)
            break;
        printf("%d\t", optimal[i]);
    }
    printf("\n");
}
