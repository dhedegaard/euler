package main

import (
	"fmt"
	"time"
)

func Iterate(total int) int {
	return iterate(total-1, 0, total)
}

func iterate(currentNum, currentTotal, total int) int {
	if currentTotal == total {
		return 1
	} else if currentTotal > total {
		panic("WTF")
	}

	result := 0
	for i := currentNum; i > 0; i-- {
		if i+currentTotal <= total {
			result += iterate(i, currentTotal+i, total)
		}
	}
	return result
}

func main() {
	fmt.Println("Result for the example with 5:", Iterate(5))
	before := time.Now()
	fmt.Println("Result for 100:", Iterate(100), "took:", time.Now().Sub(before))
}
