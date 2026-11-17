*This project has been created as part of the 42 curriculum by <login1>, <login2>.*

# push_swap

## Description

Sorts a stack of unique integers using a second stack and the 11 push_swap
operations, printing the smallest list of operations it can. Four strategies
are embedded: `--simple`, `--medium`, `--complex`, `--adaptive` (default), plus
`--bench` (stats on stderr).

| Flag | Algorithm | Class |
|---|---|---|
| `--simple` | Selection sort (min to `b`, shortest rotation) | O(n²) |
| `--medium` | Sliding-window chunks, width ≈ 1.5·√n | O(n√n) |
| `--complex` | Turk sort (cheapest-insertion between 2 stacks) | see note |
| `--adaptive` | disorder < 0.2 → simple, < 0.5 → medium, else complex | per regime |

## Instructions

```
make
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] 4 67 3 87 23
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

* **Doubly linked list** `t_list` (head, tail, size): every operation is O(1).
* **Simple**: push the minimum of `a` to `b` until 3 remain, `sort_three`, push back.
* **Medium**: rank = number of smaller values. Top rank ≤ pushed → `pb`+`rb`;
  ≤ pushed + w → `pb`; else `ra`. Then the max of `b` is rotated up and `pa`'d.
  ≤ n/w revolutions of ≤ n rotations in phase 1, ≤ w rotations per push in
  phase 2 → O(n√n) with w = Θ(√n).
* **Complex (Turk)**: push 2 to `b`, then repeatedly push from `a` to `b` the
  node with the lowest total cost (`rr`/`rrr` shared), keeping `b` in descending
  cyclic order; `sort_three`; push back with the same cost logic; final rotate.
  Each insertion costs ≤ n/2 rotations in the worst case, and in practice the
  total grows close to n log n (≈ 560 ops for 100, ≈ 5100 for 500).
  **Complexity claim for the defense: be ready to explain that the O(n log n)
  bound is empirical for this algorithm, not a proof.**
* **Disorder** = inversions / pairs, computed before any move.

## Contributions

* <login1>: …
* <login2>: …

## Resources

* push_swap subject v1.1, articles on the Turk algorithm and radix sort.
* **AI usage:** <describe honestly which parts were AI-assisted and what you
  reviewed / rewrote>.
