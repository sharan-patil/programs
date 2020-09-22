public class SelectionSort
{
    public static void sort(int[] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            int minIndex = i;
            int minValue = a[i];
            for (int j = i; j < a.length; j++)
            {
                if (a[j] < minValue)
                {
                    minValue = a[j];
                    minIndex = j;
                }
            }
            int temp = a[i];
            a[i] = minValue;
            a[minIndex] = temp;
        }
    }

    public static void main(String[] ar)
    {
        int[] test = {3, 2, 1};
        SelectionSort.sort(test);
        for (int a : test)
        {
            System.out.print(a + " ");
        }
    }
}
