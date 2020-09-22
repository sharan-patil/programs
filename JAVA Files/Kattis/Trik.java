import java.util.Scanner;

public class Trik {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int ballPos = 1;
		String line = in.nextLine();
		for (int i = 0; i < line.length(); i++) {
			char c = line.charAt(i);
			if (c == 'A' && ballPos == 1) {
				ballPos = 2;
			} else if (c == 'A' && ballPos == 2) {
				ballPos = 1;
			} else if (c == 'B' && ballPos == 2) {
				ballPos = 3;
			} else if (c == 'B' && ballPos == 3) {
				ballPos = 2;
			} else if (c == 'C' && ballPos == 1) {
				ballPos = 3;
			} else if (c == 'C' && ballPos == 3) {
				ballPos = 1;
			}
		}
		System.out.println(ballPos);
	}
}