import java.util.Scanner;

public class Spavanac {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int hour = in.nextInt();
		int min = in.nextInt();
		if (hour == 0)
			hour = 23;
		else
			hour -= 1;
		if (min < 45)
			min += 15;
		else {
			min -= 45;
			hour += 1;
		}
		if (hour == 24)
			hour = 0;
		System.out.println(hour + " " + min);
	}
}