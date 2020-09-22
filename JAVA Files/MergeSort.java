import java.util.Arrays;

public class MergeSort
{
	private int[] ray;
	
	public MergeSort(int[] ray)
	{
		this.ray = ray;
	}
	
	public int[] sort()
	{
		mergeSortRecurse(ray);
		return ray;
	}
	
	private void mergeSortRecurse(int[] array)
	{
		if (array.length <= 1)
			return ;
		int[] left = new int[array.length / 2];
		int[] right = new int[array.length - array.length / 2];
		for (int i = 0; i < left.length; i++)
			left[i] = array[i];
		for (int i = 0; i < right.length; i++)
			right[i] = array[left.length + i];
		System.out.println(left.length + " " + right.length);
		System.out.println(Arrays.toString(left) + " " + Arrays.toString(right));
		mergeSortRecurse(left);
		mergeSortRecurse(right);
		int leftCount = 0;
		int rightCount = 0;
		for (int i = 0; i < array.length; i++)
		{
			if (leftCount >= left.length && rightCount < right.length)
			{
				array[i] = right[rightCount];
				rightCount++;
			}
			else if (leftCount < left.length && rightCount >= right.length)
			{
				array[i] = left[leftCount];
				leftCount++;
			}
			else if (left[leftCount] < right[rightCount])
			{
				array[i] = left[leftCount];
				leftCount++;
			}
			else
			{
				array[i] = right[rightCount];
				rightCount++;
			}
		}
	}
	
	public static void main(String[] args)
	{
		int[] arr = {5, 4, 3, 2 ,1};
		MergeSort sorter = new MergeSort(arr);
		System.out.println(Arrays.toString(sorter.sort()));
	}
}