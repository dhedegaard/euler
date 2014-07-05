package main

import "fmt"
import "os"

func main() {
	for c := 1000; c > 0; c-- {
		for b := c - 1; b > 0; b-- {
			for a := b; a > 0; a-- {
				if a+b+c == 1000 && a*a+b*b == c*c {
					fmt.Printf("%d^2 + %d^2 = %d^2\n", a, b, c)
					fmt.Printf("%d + %d + %d = 1000\n", a, b, c)
					fmt.Println("Product is", a*b*c)
					os.Exit(0)
				}
				if a+b+c < 1000 {
					break
				}
			}
		}
	}
	fmt.Println("No solution found!")
}
