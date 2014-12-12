import java.util.stream.IntStream;
import java.util.stream.Stream;

public class euler001 {
    public static void main(String[] args) {
        System.out.println(IntStream.range(1, 1000).filter(i -> i % 3 == 0 || i % 5 == 0).sum());
    }
}