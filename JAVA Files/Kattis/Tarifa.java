import java.util.Scanner;

public class Tarifa {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int answer = 0;
		int total = in.nextInt();
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int used = in.nextInt();
			answer += total - used;
		}
		System.out.println(answer + total);
	}
}