void sort(int n, double *a)
{
    int k, i, min;
    double tmp;
    for (k = 0; k <= n - 2; k++)
    {
        min = k;
        for (i = k + 1; i < n; i++)
        {
            if (a[min] > a[i])
                min = i;
        }
        tmp = a[k];
        a[k] = a[min];
        a[min] = tmp;
    }
}