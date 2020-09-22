import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class QuickUnionUF
{
    private int[] id;
    
    public QuickUnionUF(int N)
    {
        id = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;
    }
    
    public void union(int a, int b)
    {
        int aRoot = root(a);
        int bRoot = root(b);
        
        id[aRoot] = bRoot;
    }
    
    public boolean connected(int a, int b)
    {
        return root(a) == root(b);
    }
    
    private int root(int a)
    {
        if (a == id[a])
            return a;
        return root(id[a]);
    }
    
    public static void main(String[] args)
    {
        try
        {
            File myFile = new File(args[0]);
            Scanner myReader = new Scanner(myFile);
            int N = myReader.nextInt();
            QuickUnionUF uf = new QuickUnionUF(N);
            while (myReader.hasNextLine())
            {
                int p = myReader.nextInt();
                int q = myReader.nextInt();
                if (!uf.connected(p, q))
                {
                    uf.union(p, q);
                    System.out.println(p + " " + q);
                }
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found!");
        }
    }
}