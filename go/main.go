package main

func main() {
	arr := [3]int{1, 2, 3}
	slice1 := arr[0:]
	slice2 := slice1
	slice1 = append(slice1, 4)
	slice1[0] = 2
	print(slice2[0])
}
