package Sorts;

public class SelectionSort {
	
	private int[] array;
	
	public SelectionSort(int[] array)
	{
		this.array = array;
	}
	
	public int[] sort()
	{	
		for (int i = 1; i < this.array.length; i++)
		{
			for (int j = i - 1; j > -1; j--)
			{
				if (this.array[i] < this.array[j])
				{
					int temp = this.array[i];
					this.array[i] = this.array[j];
					this.array[j] = temp;
				}
				
			}
		}
		return this.array;
	}
	
	public static void main(String[] args)
	{
		int[] array = {3, 2, 1};
		SelectionSort sort = new SelectionSort(array);
		sort.sort();
		for (int i = 0; i < 3; i++)
		{
			System.out.println(array[i]);
		}
	}
}
