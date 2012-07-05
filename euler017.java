import java.security.InvalidParameterException;

public class euler017 {
	/**
	 * For all % 10's.
	 */
	public static final String[] ONES = { "Zero", "One", "Two", "Three",
			"Four", "Five", "Six", "Seven", "Eight", "Nine" };
	/**
	 * For all % 100's, except == 10 && < 20.
	 */
	public static final String[] TENS = { null, "Ten", "Twenty", "Thirty",
			"Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	/**
	 * For all 11-19 as [1]-[9].
	 */
	public static final String[] TEN_TWENTY = { TENS[1], "Eleven", "Twelve",
			"Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
			"Eighteen", "Nineteen" };
	public static final String HUNDRED = "Hundred";
	public static final String THOUSAND = "Thousand";
	public static final String AND = "And";

	public static String getNumber(int i) {
		if (i < 1)
			throw new InvalidParameterException("i cannot be less than 1.");
		if (i > 1000)
			throw new InvalidParameterException("i cannot be more than 1000.");
		StringBuffer buffer = new StringBuffer();
		while (i > 0) {
			if (i >= 1000) {
				int a = i / 1000;
				buffer.append(ONES[a] + THOUSAND);
				i += -(a * 1000);
				if (i > 0)
					buffer.append(AND);
			} else if (i >= 100) {
				int a = i / 100;
				buffer.append(ONES[a] + HUNDRED);
				i += -(a * 100);
				if (i > 0)
					buffer.append(AND);
			} else if (i >= 20) {
				int a = i / 10;
				buffer.append(TENS[a]);
				i += -(a * 10);
			} else if (i >= 10 && i <= 19) {
				buffer.append(TEN_TWENTY[i - 10]);
				i = 0;
			} else if (i > 0) {
				buffer.append(ONES[i]);
				i = 0;
			}
		}
		return buffer.toString();
	}

	public static int countTo(int lastNumber) {
		if (lastNumber < 1)
			throw new InvalidParameterException("lastNumber is less than 1.");
		int count = 0;
		for (int i = 1; i <= lastNumber; i++)
			count += getNumber(i).length();
		return count;
	}

	public static void main(String[] args) {
		if (getNumber(342).length() != 23)
			throw new RuntimeException(String.valueOf(getNumber(342).length()));
		if (getNumber(115).length() != 20)
			throw new RuntimeException(String.valueOf(getNumber(115).length()));
		if (args.length == 1)
		    try {
			System.out.println(countTo(Integer.valueOf(args[0])));
		    } catch (NumberFormatException e) {
			System.err.println(String.format("NumberFormatException: Argument not valid because: %s", e.getMessage()));
			System.exit(1);
		    } catch (InvalidParameterException e) {
			System.err.println(String.format("InvalidParameterException: Argument supplied is not within valid range: %s", e.getMessage()));
			System.exit(1);
		    }
		else
		    System.out.println(countTo(1000));
	}
}
