fn main() {
    let mut sum = 0u;
    let (mut a, mut b) = (2u, 1u);
    while a < 4_000_000u {
        // Add to sum, if valid.
        if a % 2 == 0 {
            sum += a;
        }

        // iterate to the next number.
        let tmp = a;
        a = a + b;
        b = tmp;
    }
    println!("{}", sum);
}