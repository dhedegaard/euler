package main

import "math/big"
import "fmt"
import "strconv"

func main() {
	bignum := big.NewInt(1)
	for a := 100; a >= 1; a-- {
		bignum.Mul(big.NewInt(int64(a)), bignum)
	}
	sum := 0
	for _, char := range bignum.String() {
		digit, _ := strconv.ParseInt(string(char), 0, 0)
		sum += int(digit)
	}
	fmt.Println(sum)
}
