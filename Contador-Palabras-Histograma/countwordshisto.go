package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"math"
	"time"
)

const max_length_word = 40
const sample = 5

var histograma [max_length_word]int

func searchWhiteSpace(str *string, idx int, end int) int {
	for i := idx; i < len(*str); i++ {
		if (*str)[i] == ' ' {
			return i
		}
	}
	return end
}

func porcessFile(str *string, start int, end int, tam chan int) {
	//fmt.Print(start, " ", end, "\n")
	var idx int
	var word_size int
	for start < end {
		//fmt.Print("entro")
		word_size = 0

		idx = searchWhiteSpace(str, start, end)

		word_size = idx - start
		//fmt.Print(idx, " ", start, " ", word_size, "\n")
		start = idx + 1
		//fmt.Print(word_size, "\n")
		tam <- word_size
		//histograma[word_size-1]++
	}
}

func recaluloSize(size int, str *string, end int) int {
	if (*str)[size] == ' ' && (*str)[end] != (*str)[size] {
		return size
	}
	var cont int = 0
	for i := 0; i < end; i++ {
		if (*str)[i] == ' ' {
			cont = i
			return cont
		}
	}
	return 0
}

func header() {
	fmt.Printf("Cores\tScale\tTime\n")
}

func execute(end int, num_processors int, str string) {
	var size int = end / num_processors
	ch := make(chan int)

	var start_index int = 0
	var end_index int = 0

	//fmt.Print(size, "\n", end, "\n")
	//fmt.Print(string(str[size]))

	for i := 0; start_index < end; i++ {
		//fmt.Print(str[size], "\n")
		if end_index < end {
			size := recaluloSize(size, &str, end_index)
			end_index = int(math.Min(float64(start_index+size), float64(end)))
			end_index = searchWhiteSpace(&str, end_index, end)
		}
		//fmt.Print(str[start_index+size], "\n")
		//fmt.Print(str[end_index], "\n")

		go porcessFile(&str, start_index, end_index, ch)

		histograma[(<-ch)-1]++

		start_index = end_index + 1
	}
}

func main() {

	f, err := ioutil.ReadFile("archiv.txt")
	if err != nil {
		log.Fatal(err)
	}
	str := string(f)
	var end int = len(str)
	var original_time float64 = 0 

	for i := 0; i < sample; i++ {
		start := time.Now()
		execute(end-1, 1, str)
		fi := time.Now()
		original_time += fi.Sub(start).Seconds()
	}
	original_time /= sample
	fmt.Printf("Single thread time %f\n", original_time)

	fmt.Printf("Weak scalability test\n")
	header()
	for num_proc1 := 1; num_proc1 <= 16; num_proc1++ {
		var elapsed_time1 float64 = 0
		for i := 0; i < sample; i++ {
			start := time.Now()
			execute(end*(num_proc1/16), num_proc1, str)
			fi := time.Now()
			elapsed_time1 += fi.Sub(start).Seconds()
		}

		elapsed_time1 /= sample
		fmt.Printf("%d \t %f \t %f\n", num_proc1, original_time/elapsed_time1, elapsed_time1)
	}

	fmt.Printf("Strong scalability test\n")
	header()
	for num_proc := 2; num_proc <= 16; num_proc++ {
		var elapsed_time float64 = 0
		var num_proc int = 2
		for i := 0; i < sample; i++ {
			start := time.Now()
			execute(end, num_proc, str)
			fi := time.Now()
			elapsed_time += fi.Sub(start).Seconds()
		}

		elapsed_time /= sample
		fmt.Printf("%d \t %f \t %f\n", num_proc, original_time/elapsed_time, elapsed_time)
	}

	for i := 0; i < 20; i++ {
		fmt.Print("Words with ", i+1, " characters: ", histograma[i], "\n")
	}

}
