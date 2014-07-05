package main

import (
	"fmt"
	"math"
)

func eratosthenes(cap int) []int {
	A := make([]bool, cap)
	for i := 0; i < cap; i++ {
		A[i] = true
	}

	for i := 2; i < int(math.Sqrt(float64(cap))); i++ {
		if A[i] {
			for j := i * i; j < cap; j += i {
				A[j] = false
			}
		}
	}

	result := make([]int, 0)
	for i, val := range A {
		if i >= 2 && val {
			result = append(result, i)
		}
	}
	return result
}

func main() {
	sum := 0
	for _, val := range eratosthenes(2000000) {
		sum += val
	}
	fmt.Println(sum)
}
