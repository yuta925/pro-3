void insert(int n, double *a, int k)
{
    int i;
    double tmp;
    for (i = k; 0 <= i; i--)
    {
        if (a[i] >= a[i - 1])
            break;
        else
        {
            tmp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = tmp;
        }
    }
}