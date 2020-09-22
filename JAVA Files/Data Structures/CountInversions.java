public class CountInversions
{
    private static int inversions;

    private static int[] merge(int[] a, int[] b)
    {
        int[] c = new int[a.length + b.length];
        int p = 0;
        int q = 0;

        for (int i = 0; i < c.length; i++)
        {
            if (p >= a.length)
            {
                c[i] = b[q];
                q++;
            }
            else if (q >= b.length)
            {
                c[i] = a[p];
                p++;
            }
            else if (a[p] < b[q])
            {
                c[i] = a[p];
                p++;
            }
            else
            {
                c[i] = b[q];
                q++;
                inversions += (a.length - p);
            }
        }
        return c;
    }

    private static int[] helperCount(int[] arr)
    {
        int l = arr.length;

        int[] arrA = new int[l / 2];
        int[] arrB = new int[l - (l / 2)];

        if (arr.length <= 1)
            return arr;
        for (int i = 0; i < l; i++)
        {
            if (i < (l / 2))
                arrA[i] = arr[i];
            else
                arrB[i - (l / 2)] = arr[i];
        }
        return merge(helperCount(arrA), helperCount(arrB));
    }

    public static int count(int[] arr)
    {
        helperCount(arr);
        return inversions;
    }

    public static void main(String[] args)
    {
        int[] a = {1, 3, 5, 2, 4, 6};
        System.out.println(count(a));
    }
}
