void sort(int n, double *a, int k)
{
    int i, j;
    double tmp;
    for (i = 1; i <= n - 1; i++)
    {
        for (j = i; 0 <= j; j--)
        {
            if (a[j] >= a[j - 1])
                break;
            else
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}