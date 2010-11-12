import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class euler29 {
	public static void main(String[] args) {
		Map<BigInteger, Object> hash = new HashMap<BigInteger, Object>();
		for (int a = 2;a <= 100;a++)
			for (int b = 2;b <= 100;b++) {
				BigInteger rc = new BigInteger(String.valueOf(a)).pow(b);
				if (!hash.containsKey(rc))
					hash.put(rc, new Object());
			}
		System.out.println(hash.keySet().size());
	}
}
