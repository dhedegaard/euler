package main

import "fmt"

func collatz(number int, cache map[int]int) int {
	if val, ok := cache[number]; ok {
		return val
	}
	if number%2 == 0 {
		number /= 2
	} else {
		number = number*3 + 1
	}
	val := collatz(number, cache)
	cache[number] = val + 1
	return val + 1
}

func main() {
	cache := map[int]int{
		1: 1,
	}
	max_count := 0
	max_i := -1
	for i := 1; i < 1000000; i++ {
		count := collatz(i, cache)
		if max_count < count {
			max_i = i
			max_count = count
		}
	}
	fmt.Println("max_count", max_count)
	fmt.Println("max_i", max_i)
}
