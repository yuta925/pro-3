void sort(int n, double *a)
{
    int l, r;
    double p, tmp;
    /* a[0]〜a[n-1] を分割: p 以下の要素を a[] の前半に, p 以上の要素を後半に集める */
    l = 0;     /* 左端 */
    r = n - 1; /* 右端 */
    p = a[0];  /* p として先頭要素を選ぶ */
    // l ≤ r である間繰り返す
    while (l <= r)
    {
        // a[l] < p である間 l を 1 増やす;
        while (a[l] < p)
            l++;
        // a[r] > p である間 r を1 減らす;
        while (a[r] > p)
            r--;
        if (l <= r)
        {
            tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            l++;
            r--;
        }
    }
    /* 分割の結果, a[0]〜a[r] が p 以下, a[l]〜a[n-1] が p 以上になっている */

    if (0 < r)
        sort(r, a);
    if (l < n - 1)
        sort(n - l, a);
}