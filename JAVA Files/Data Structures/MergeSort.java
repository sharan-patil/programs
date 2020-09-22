public class MergeSort
{
    private static int[] merge(int[] a, int[] b)
    {
        int l = a.length + b.length;

        int[] ans = new int[l];
        int p = 0;
        int q = 0;

        for (int i = 0; i < l; i++)
        {
            if (p >= a.length)
            {
                ans[i] = b[q];
                q++;
            }
            else if (q >= b.length)
            {
                ans[i] = a[p];
                p++;
            }
            else if (a[p] < b[q])
            {
                ans[i] = a[p];
                p++;
            }
            else
            {
                ans[i] = b[q];
                q++;
            }
        }
        return ans;
    }

    private static int[] helpSort(int[] a)
    {
        int l = a.length;
        int subL1 = l / 2;
        int subL2 = l - subL1;

        if (l == 1 || l == 0)
            return a;
        int[] newSub1 = new int[subL1];
        int[] newSub2 = new int[subL2];
        int tempSubL1 = subL1;

        for (int i = 0; i < subL1; i++)
            newSub1[i] = a[i];
        for (int i = 0; i < subL2; i++)
            newSub2[i] = a[tempSubL1++];
        return merge(helpSort(newSub1), helpSort(newSub2));
    }

    public static int[] sort(int[] a)
    {
        return helpSort(a);
    }

    public static void main(String[] args)
    {
        int[] arr = {5, 4, 3 ,2};
        int[] sorted = sort(arr);
        for (int a : sorted)
        {
            System.out.print(a + " ");
        }
    }
}
