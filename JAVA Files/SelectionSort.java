import java.util.ArrayList;

public class SelectionSort
{
	private ArrayList<Integer> array;
	
	public SelectionSort(ArrayList<Integer> array)
	{
		this.array = array;
	}
	
	public ArrayList<Integer> sort()
	{
		int swapper;
		int smallest;
		int smallestIndex;
		
		for (int i = 0; i < this.array.size(); i++)
		{
			smallest = Integer.MAX_VALUE;
			smallestIndex = -1;
			for (int j = i; j < this.array.size(); j++)
			{
				if (this.array.get(j) < smallest)
				{
					smallestIndex = j;
					smallest = this.array.get(j);
				}
			}
			swapper = this.array.get(i);
			this.array.set(i, smallest);
			this.array.set(smallestIndex, swapper);
		}
		return this.array;
	}
	
	public static void main(String[] args)
	{
		ArrayList<Integer> eles = new ArrayList<Integer>();
		eles.add(5);
		eles.add(4);
		eles.add(3);
		SelectionSort sorter = new SelectionSort(eles);
		System.out.println(sorter.sort());
	}
}
