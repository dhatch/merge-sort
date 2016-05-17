package main

import "fmt"
import "os"
import "strconv"

func msort(values []int64) []int64 {
	l := values[:len(values)/2]
	r := values[len(l):]

	if !(len(l) <= 1 && len(r) <= 1) {
		l = msort(l)
		r = msort(r)
	}

	sorted := make([]int64, len(values))

	for i := 0; i < len(sorted); i++ {
		if len(l) == 0 {
			sorted[i], r = r[0], r[1:]
		} else if len(r) == 0 {
			sorted[i], l = l[0], l[1:]
		} else if l[0] < r[0] {
			sorted[i], l = l[0], l[1:]
		} else {
			sorted[i], r = r[0], r[1:]
		}
	}

	return sorted
}

func main() {
	values := make([]int64, len(os.Args)-1)
	for i, v := range os.Args[1:] {
		intV, err := strconv.ParseInt(v, 10, 64)
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}

		values[i] = intV
	}

	sorted := msort(values)
	for _, e := range sorted {
		fmt.Println(e)
	}
}
