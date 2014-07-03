package main

import "fmt"

func fibonacci_sequence() (c chan int) {
	c = make(chan int)
	go func() {
		a, b := 1, 0
		for {
			c <- a
			a, b = a+b, a
		}
		close(c)
	}()
	return
}

func main() {
	sum := 0
	for val := range fibonacci_sequence() {
		if val > 4000000 {
			break
		}
		if val%2 == 0 {
			sum += val
		}
	}
	fmt.Println(sum)
}
