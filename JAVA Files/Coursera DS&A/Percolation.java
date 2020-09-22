import java.lang.IllegalArgumentException;

public class Percolation {

    private int[][] grid;
    private WeightedQuickUnionUF uf;

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) throws IllegalArgumentException
    {
        if (n <= 0)
            throw new IllegalArgumentException();
        grid = new int[n][n];
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) throws IllegalArgumentException
    {
        if (row <= 0 || row > grid.length)
            throw new IllegalArgumentException();
        if (col <= 0 || row > grid.length)
            throw new IllegalArgumentException();
        grid[--row][--col] = 1;
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) throws IllegalArgumentException
    {
        if (row <= 0 || row > grid.length)
            throw new IllegalArgumentException();
        if (col <= 0 || row > grid.length)
            throw new IllegalArgumentException();
        if (grid[--row][--col] == 1)
        {
            return true;
        }
        return false;
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) throws IllegalArgumentException
    {
        if (row <= 0 || row > grid.length)
            throw new IllegalArgumentException();
        if (col <= 0 || row > grid.length)
            throw new IllegalArgumentException();    
        percolates();
        if (uf.connected(convert(row, col), 0))
            return true;
        return false;
    }

    // returns the number of open sites
    public int numberOfOpenSites()
    {
        int count = 0;
        
        for (int i = 1; i <= grid.length; i++)
        {
            for (int j = 1; j <= grid.length; j++)
            {
                if (isOpen(i, j))
                    count++;
            }
        }
        return count;
    }

    private int convert(int a, int b)
    {
        int res = a - 1;
        res *= grid.length;
        res += b;
        return res;
    }

    private boolean isValid(int a, int b)
    {
        if (a >= 1 && a <= grid.length)
            if (b >= 1 && b <= grid.length)
                return true;
        return false;
    }

    // does the system percolate?
    public boolean percolates()
    {
        uf = new WeightedQuickUnionUF(grid.length * grid.length + 2);
        
        if (grid.length == 1)
        {
            if (isOpen(1, 1))
                return true;
            else
                return false;
        }
        
        for (int i = 1; i <= grid.length; i++)
        {
            for (int j = 1; j <= grid.length; j++)
            {
                if (i == 1)
                {
                    uf.union(convert(1, j), 0);
                }
                if (i == grid.length)
                {
                    uf.union(convert(i, j), grid.length * grid.length + 1);
                }
                if (isOpen(i, j))
                {
                    if (isValid(i - 1, j))
                        if (isOpen(i - 1, j))
                            uf.union(convert(i, j), convert(i - 1, j));
                    if (isValid(i + 1, j))
                        if (isOpen(i + 1, j))
                            uf.union(convert(i, j), convert(i + 1, j));
                    if (isValid(i, j + 1))
                        if (isOpen(i, j + 1))
                            uf.union(convert(i, j), convert(i, j + 1));
                    if (isValid(i, j - 1))
                        if (isOpen(i, j - 1))
                            uf.union(convert(i, j), convert(i, j - 1));
                }
            }
        }
        
        if (uf.connected(0, grid.length * grid.length + 1))
            return true;
        else
            return false;
    }

    // test client (optional)
    public static void main(String[] args)
    {
        
    }
}
