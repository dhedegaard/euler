package main

import "fmt"

type Position struct {
	x int
	y int
}

func Lattice(xcap int, ycap int) int {
	// make an empty cache
	cache := make(map[Position]int, 0)

	// make the positions
	pos := Position{0, 0}
	cap := Position{xcap, ycap}

	// put the cap result in the cache
	cache[cap] = 1

	// call recursive call and return the result
	return lattice(pos, cap, cache)
}

func lattice(pos Position, cap Position, cache map[Position]int) int {
	// check for a cachehit.
	if val, ok := cache[pos]; ok {
		return val
	}

	// iterate in each direction, and add the total count together.
	sum := 0
	if pos.x < cap.x {
		new_pos := Position{pos.x + 1, pos.y}
		sum += lattice(new_pos, cap, cache)
	}
	if pos.y < cap.y {
		new_pos := Position{pos.x, pos.y + 1}
		sum += lattice(new_pos, cap, cache)
	}

	// put the result in the cache, and return.
	cache[pos] = sum
	return sum
}

func main() {
	// Calculate for a 20x20 field.
	fmt.Println(Lattice(20, 20))
}
