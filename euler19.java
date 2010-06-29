import java.util.Calendar;
import java.util.GregorianCalendar;

public final class euler19 {
	public static void main(String[] args) {
		int count = 0;
		GregorianCalendar cal = new GregorianCalendar();
		cal.set(Calendar.DAY_OF_MONTH, 1);
		for (int year = 1901; year <= 2000; year++) {
			cal.set(Calendar.YEAR, year);
			for (int month = Calendar.JANUARY; month <= Calendar.DECEMBER; month++) {
				cal.set(Calendar.MONTH, month);
				if (cal.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY)
					count++;
			}
		}
		System.out.println(count);
	}
}
