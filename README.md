# push_swap

A sorting algorithm project in C, built at École 42 (Brussels).

Sort a list of integers using two stacks (`a` and `b`) and a limited set of operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, ...), printing the shortest instruction sequence possible.

## Build and run

```bash
make
./push_swap 3 2 5 1 4
```

The program prints the list of operations that sorts the input. Invalid input (non-integers, duplicates, overflow) prints `Error`.
