public class InsertionSort
{
    public static void sort(int[] a)
    {
        for (int i = 1; i < a.length; i++)
        {
            int tempI = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[tempI] < a[j])
                {
                    int temp = a[tempI];
                    a[tempI] = a[j];
                    a[j] = temp;
                    tempI--;
                }
            }
        }
    }

    public static void main(String[] ar)
    {

        int[] test = {3, 2, 1};
        InsertionSort.sort(test);
        for (int s : test)
        {
            System.out.print(s + " ");
        }
    }
}
