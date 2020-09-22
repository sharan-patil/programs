import java.util.Scanner;

public class Autori {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		int n = 0;
		
		System.out.print(line.charAt(0));
		while (true)
		{
			n = line.indexOf('-', ++n);
			if (n == -1)
				break ;
			System.out.print(line.charAt(n + 1));
		}
	}
}