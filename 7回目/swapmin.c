void swapmin(int n, double *a, int k)
{
    int i, min = k;
    double tmp;

    for (i = k; i < n; i++)
    {
        if (a[min] > a[i])
            min = i;
    }
    tmp = a[k];
    a[k] = a[min];
    a[min] = tmp;
}
