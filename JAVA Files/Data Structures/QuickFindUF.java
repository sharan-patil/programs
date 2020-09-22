import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class QuickFindUF
{
    private int[] id;
    private int count;

    public QuickFindUF(int N)
    {
        id = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;
        count = N;
    }

    public void union(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];

        for (int i = 0; i < id.length; i++)
        {
            if (id[i] == pid)
                id[i] = qid;
        }
        count--;
    }

    public int find(int p)
    {
        return id[p];
    }

    public boolean connected(int p, int q)
    {
        return id[p] == id[q];
    }

    public int count()
    {
        return count;
    }

    public static void main(String[] args)
    {
        try
        {
            File myFile = new File(args[0]);
            Scanner myReader = new Scanner(myFile);
            int N = myReader.nextInt();
            QuickFindUF uf = new QuickFindUF(N);
            while (myReader.hasNextLine())
            {
                int p = myReader.nextInt();
                int q = myReader.nextInt();
                if (!uf.connected(p, q))
                {
                    uf.union(p, q);
                    System.out.println(p + " " + q);
                }
                System.out.println("current component count: " + uf.count());
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File Not Found!");
        }
    }
}
