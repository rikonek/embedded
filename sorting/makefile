cc = gcc -g -Wall -std=c99

all: function.o random.o bubble shellsort quicksort

function.o: function.c
	$(cc) -c -o function.o function.c

random.o: random.c
	$(cc) -c -o random.o random.c

bubble: function.o random.o bubble_sorting.c
	$(cc) -o bubble_sorting.out function.o random.o bubble_sorting.c

shellsort: function.o random.o shellsort_sorting.c
	$(cc) -o shellsort_sorting.out function.o random.o shellsort_sorting.c

quicksort: function.o random.o quicksort_sorting.c
	$(cc) -o quicksort_sorting.out function.o random.o quicksort_sorting.c

clean:
	rm -f *.out *.o