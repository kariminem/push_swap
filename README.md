*This project has been created as part of the 42 curriculum by ktaher, gbliard.*

# push_swap

A C program that sorts a stack of integers using a limited set of operations, outputting the minimum number of moves to achieve a sorted result.

---

## Description

push_swap takes a list of integers as command line arguments and prints the shortest sequence of stack operations that sorts them in ascending order. The challenge is that sorting can only be performed using two stacks (`a` and `b`) and exactly 11 allowed operations, no direct array access, no built-in sort functions.

The program implements four distinct sorting strategies, selectable at runtime, each targeting a different complexity class. An adaptive mode automatically selects the best strategy based on a disorder metric computed before sorting begins.

---

## Instructions

### Compilation

```bash
make        # builds push_swap binary
make bonus  # builds checker binary
make clean  # removes object files
make fclean # removes objects + binaries
make re     # fclean + all
```

### Usage

```bash
# basic usage (adaptive strategy by default)
./push_swap 5 3 1 4 2

# force a specific strategy
./push_swap --simple  5 3 1 4 2
./push_swap --medium  5 3 1 4 2
./push_swap --complex 5 3 1 4 2

# enable benchmark output (sent to stderr)
./push_swap --bench --simple 5 3 1 4 2

# pipe operations to checker
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

# test with random input
./push_swap $(shuf -i 0-999 -n 100) | wc -l
```

### Error handling

The program prints `Error` to stderr and exits on:
- Non-integer arguments
- Integers outside INT_MIN/INT_MAX range
- Duplicate values
- Unknown flags

### Benchmark mode

When `--bench` is passed, the following is printed to stderr after sorting:

```
[bench] disorder:  49.93 %
[bench] strategy:  medium / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 4840  rb: 1098  rr: 0  rra: 0  rrb: 1059  rrr: 0
```

---

## Algorithms

### Disorder metric

Before any sorting begins, a disorder score between 0.0 and 1.0 is computed:

```
disorder = number of inverted pairs / total pairs
```

An inversion is any pair (i, j) where i appears before j in the stack but i > j. A disorder of 0 means already sorted. A disorder of 1 means fully reversed.

### Strategy 1 — Simple O(n²) — `--simple`

**Algorithm:** Selection sort adaptation.

For each pass, find the minimum element in stack a, rotate it to the top using either `ra` or `rra` (whichever requires fewer moves), then push it to stack b. After all elements are in b, push everything back to a with `pa`.

**Why:** Natural fit for a stack, finding and extracting the minimum is O(n), doing it n times is O(n²). No wasted rotations.

**Threshold:** Used by adaptive mode when disorder < 0.2, nearly sorted input benefits from minimal moves.

### Strategy 2 — Medium O(n√n) — `--medium`

**Algorithm:** Bucket sort adaptation using value ranges.

Divides the value range `[min, max]` into √n equal chunks. Iterates through chunks from largest to smallest, pushing matching elements from a to b. Then pulls back from b to a by repeatedly finding the maximum in b and rotating it to the top.

**Why:** Each pass through the stack is O(n), and there are √n passes, giving O(n√n) total. Pushing from high chunks first ensures the pull-back phase produces a correctly sorted ascending stack.

**Threshold:** Used by adaptive mode when 0.2 ≤ disorder < 0.5.

### Strategy 3 — Complex O(n log n) — `--complex`

**Algorithm:** Initially, we developped a merge sort and then optimised it using existing runs in a timsort fashion. When this still did not pass the GOOD bar, I tried implementing a quicksort which had some of the same issues. In the end, RADIX was both simple to code and more efficient for highly disordered lists. This is the algorithm we settled on:

Starting at the first byte (index 0), the numbers are compared, those with a byte == 1 are kept in A by using ra, the others are pushed to B using pb. Then the stack of pb is pushed back onto stack A using pa. By using this iteratively, the smaller elements are placed on top and the larger on the bottom. Each pass does 3/2 * n operations with log2(n) passes.

**Threshold:** Used by adaptive mode when disorder ≥ 0.5.

### Strategy 4 — Adaptive — `--adaptive` (default)

Computes the disorder metric before sorting and selects the most efficient strategy for the given input:

| Disorder | Strategy | Complexity |
|---|---|---|
| < 0.2 | Simple (selection sort) | O(n²) |
| 0.2 – 0.5 | Medium (bucket sort) | O(n√n) |
| ≥ 0.5 | Complex (merge sort) | O(n log n) |

**Rationale:** For nearly sorted input, O(n²) actually generates fewer operations than O(n log n) because the constant factors are much lower. The thresholds were chosen empirically by benchmarking operation counts across disorder ranges.

---

## Contributions

| Login | Contributions |
|---|---|
| [https://profile-v3.intra.42.fr/users/ktaher] | Input parsing, simple sorting, medium sorting, bench flag, Bonus |
| [https://profile-v3.intra.42.fr/users/gbliard] | complex sorting, adaptive sorting, edge cases (two_stack , three_stack) |

---

## Resources

### Algorithm references
- [Visualgo — Sorting algorithms visualized](https://visualgo.net/en/sorting)
- [Wikipedia — Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Wikipedia — Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
- [Wikipedia — Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Medium — push_swap the least amount of moves](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI usage
- AI was only used to help format this README.
