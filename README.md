# libft

My own C standard library, started as the first 42 project and extended as the base of all my later C projects.

## Build

```bash
make            # produces libft.a
```

Then link it with `-I headers -L. -lft`.

## Contents

| Module | What it provides |
| --- | --- |
| `str`, `char`, `memory`, `convert` | Reimplementations of the libc string, character, memory and conversion functions |
| `list` | Singly linked list |
| `vector` | Growable generic array (`vec_new`, `vec_append`, `vec_insert`, `vec_pop`…) |
| `string` | Dynamic string type |
| `printf` | `ft_printf`, a reimplementation of `printf` |
| `get_next_line` | Reads a file descriptor line by line |
| `alloc`, `errno`, `time`, `math`, `write` | Allocation helpers, error codes, time utilities, maths, output |
| `mm256` | Small AVX2 helpers (bit shifts on `__m256i`) |

## What I learned

Designing a reusable API in C: consistent naming, ownership of allocated memory, and keeping a library small enough that other projects can depend on it.
