import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class WeightedQuickUnionUF
{
    private int[] parent;
    private int[] size;
    private int count;
    
    public WeightedQuickUnionUF(int N)
    {
        parent = new int[N];
        size = new int[N];
        
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        
    }
    
    private int root(int a)
    {
        while (parent[a] != a)
        {
            a = parent[a];
        }
        return a;
    }
    
    public void union(int a, int b)
    {
        if (root(a) == root(b))
            return ;
        if (size[a] <= size[b])
        {
            parent[root(a)] = root(b);
            size[b] += size[a];
        }
        else
        {
            parent[root(b)] = root(a);
            size[a] += size[b];
        }
    }
    
    public int find(int a)
    {
        return root(a);
    }
    
    public boolean connected(int a, int b)
    {
        return root(a) == root(b);
    }
    
    // public static void main(String[] args)
    // {
    //     try
    //     {
    //         File myFile = new File(args[0]);
    //         Scanner myReader = new Scanner(myFile);
    //         int N = myReader.nextInt();
    //         WeightedQuickUnionUF uf = new WeightedQuickUnionUF(N);
    //         while (myReader.hasNextLine())
    //         {
    //             int p = myReader.nextInt();
    //             int q = myReader.nextInt();
    //             if (!uf.connected(p, q))
    //             {
    //                 uf.union(p, q);
    //                 System.out.println(p + " " + q);
    //             }
    //         }
    //     }
    //     catch(FileNotFoundException e)
    //     {
    //         System.out.println("File Not Found!");
    //     }
    // }
}
