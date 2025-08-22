# 1337 School – C++ Modules (CPP00 → CPP09)

A practical, testable README that you can drop at the root of your C++ modules repository. It summarizes each module’s goals, exercises, build/run instructions, and evaluation tips.

> **Standard & Flags**: All modules are compiled with **C++98** and the usual flags: `-Wall -Wextra -Werror -std=c++98`.

> **Style**: Follow Orthodox Canonical Form (OCF: default constructor, copy constructor, copy assignment, destructor) when a class manages a resource; prefer `const` correctness; separate headers/impl; avoid unused includes; keep functions small.

---

## Table of Contents

1. [Structure](#structure)
2. [Common Build & Run](#common-build--run)
3. [CPP00 — Basics: I/O, Strings, Classes](#cpp00--basics-io-strings-classes)
4. [CPP01 — Memory, Pointers/Refs, New/Delete](#cpp01--memory-pointersrefs-newdelete)
5. [CPP02 — Ad-hoc Polymorphism, Canonical Form, Fixed Point](#cpp02--ad-hoc-polymorphism-canonical-form-fixed-point)
6. [CPP03 — Inheritance](#cpp03--inheritance)
7. [CPP04 — Subtype Polymorphism, Abstract Classes, Interfaces](#cpp04--subtype-polymorphism-abstract-classes-interfaces)
8. [CPP05 — Exceptions](#cpp05--exceptions)
9. [CPP06 — Casts](#cpp06--casts)
10. [CPP07 — Templates](#cpp07--templates)
11. [CPP08 — Templated Containers, Iterators, Algorithms](#cpp08--templated-containers-iterators-algorithms)
12. [CPP09 — STL & Algorithms on Real Tasks](#cpp09--stl--algorithms-on-real-tasks)
13. [Testing Tips](#testing-tips)
14. [Evaluation Checklist](#evaluation-checklist)
15. [Makefile Template](#makefile-template)

---

## Structure

```
.
├── CPP00/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP01/
│   ├── ex00/ ...
...
└── CPP09/
    ├── ex00/
    ├── ex01/
    └── ex02/
```

Each `exNN` is self-contained (sources, headers, its own `Makefile`, and a `main.cpp` when required by the subject).

---

## Common Build & Run

```bash
# Build default target in an exercise directory
make
# Build with recompile
make re
# Clean objects / full clean
make clean
make fclean
# Run (target name may vary per exercise)
./program [args]
```

**Makefile contract** (expected in 42): targets `all`, `clean`, `fclean`, `re`; variables `CXX`, `CXXFLAGS`, `NAME`, `SRCS`, `OBJS`, `INCS`.

---

## CPP00 — Basics: I/O, Strings, Classes

**Focus:** `iostream`, basic classes, member functions, std::string, stream formatting.

**Typical exercises**

* **ex00 – Megaphone**: Read arguments, print as uppercase to `stdout`. Edge cases: no args, non-ASCII chars.
* **ex01 – PhoneBook**: Fixed-size phonebook (8 contacts), add/search with table formatting, truncation to width 10, index selection, input validation.
* **ex02 – Account** *(if required by your subject)*: Implement provided tests for an `Account` class (static members, timestamps, aggregate info).

**Build**

```bash
cd CPP00/ex00 && make && ./megaphone "shhhhh... I think the students are asleep"
cd CPP00/ex01 && make && ./phonebook
```

**Key points**

* Use `std::setw`, `std::right/left`, truncation with `substr`.
* No dynamic allocation needed in ex01 (use fixed array of 8 contacts).

---

## CPP01 — Memory, Pointers/Refs, New/Delete

**Focus:** Stack vs heap, references, `new`/`delete`, basic resource management, `std::getline`.

**Typical exercises**

* **ex00 – Zombie**: Functions creating zombies on stack/heap; naming; announce method.
* **ex01 – ZombieHorde**: Allocate an array of N zombies; delete with `delete[]`.
* **ex02 – Pointers and References**: Show addresses/values of a string via pointer and reference.
* **ex03 – Weapon/HumanA/HumanB**: Reference vs pointer members, lifetime considerations.
* **ex04 – Sed is for losers**: Simple file replace: read whole file, replace s1 → s2, write `.replace` file.
* **ex05/ex06 – Harl 2.0 / switch-like**: Map message levels to outputs via function pointers or arrays.

**Key points**

* Avoid leaks; match `new` with `delete` and `new[]` with `delete[]`.
* `const` where appropriate; pass by reference to avoid copies.

---

## CPP02 — Ad-hoc Polymorphism, Canonical Form, Fixed Point

**Focus:** Operator overloading, Orthodox Canonical Form (OCF), copying semantics, fixed-point arithmetic.

**Typical exercises**

* **ex00 – Fixed**: Class with raw fixed-point value; OCF; shifts for fractional bits.
* **ex01 – Fixed arithmetic**: Implement `+ - * /`, comparison, increment/decrement, `min/max` (const and non-const), `toInt`, `toFloat`.
* **ex02 – bsp**: Point-in-triangle (Barycentric) using `Fixed` type; immutable `Point` class.

**Key points**

* Respect OCF; ensure `operator<<` prints floats with `toFloat()`.
* Carefully implement arithmetic to avoid precision/overflow.

---

## CPP03 — Inheritance

**Focus:** Simple inheritance, access specifiers, virtual vs non-virtual, diamond issues intro.

**Typical exercises**

* **ex00 – ClapTrap**: Energy/hit/attack with constraints; clear logging.
* **ex01 – ScavTrap**: Derive from ClapTrap; add guardGate.
* **ex02 – FragTrap**: Derive; add highFivesGuys.
* **ex03 – DiamondTrap**: Multiple inheritance (ScavTrap+FragTrap) → resolve ambiguity; `whoAmI()`.

**Key points**

* Virtual inheritance where required by subject; initialize bases correctly; avoid duplicate base subobjects.

---

## CPP04 — Subtype Polymorphism, Abstract Classes, Interfaces

**Focus:** Virtual destructors, pure virtual functions, deep copying, Rule of Three.

**Typical exercises**

* **ex00 – Animal**: Base with virtual `makeSound`; derived `Dog/Cat`.
* **ex01 – Brain**: Composition; deep copy (Rule of Three) to manage `Brain*`.
* **ex02 – WrongAnimal**: Show what happens without virtuals (polymorphism fails).
* **ex03 – Materia**: Interfaces `IMateriaSource`, `ICharacter`; classes `AMateria`, `Ice`, `Cure`, `Character`, `MateriaSource`.

**Key points**

* Always a **virtual destructor** in polymorphic bases.
* Implement deep copy when owning heap memory.

---

## CPP05 — Exceptions

**Focus:** Exceptions, nested classes, RAII with failures, grade checks.

**Typical exercises**

* **ex00 – Bureaucrat**: Grade range \[1..150], increment/decrement with exceptions.
* **ex01 – Form**: Signable by bureaucrat with sufficient grade; immutable name/grade requirements.
* **ex02 – Shrubbery/Robotomy/Presidential**: Concrete forms with `execute` behavior and required grades.
* **ex03 – Intern**: Factory that creates forms by name.

**Key points**

* Throw specific exceptions; override `what()`.
* Check signature before execution; log success/failure.

---

## CPP06 — Casts

**Focus:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, scalar conversion, serialization.

**Typical exercises**

* **ex00 – ScalarConverter**: Parse a string and print as `char`, `int`, `float`, `double`; handle nan/inf.
* **ex01 – Serializer**: Serialize/deserialize pointer via `uintptr_t`.
* **ex02 – RTTI**: Identify derived types at runtime via `dynamic_cast`.

**Key points**

* No exceptions for normal flow in ex00; robust parsing; printing formats.

---

## CPP07 — Templates

**Focus:** Function/class templates, specialization, template constraints (informal with C++98), const-correctness.

**Typical exercises**

* **ex00 – `swap`, `min`, `max`**: Generic with references; test multiple types.
* **ex01 – `iter`**: Apply function to array elements (const and non-const overloads).
* **ex02 – `Array<T>`**: Bounds-checked dynamic array; deep copy; `operator[]` const/non-const.

**Key points**

* Implement in headers (templates need definitions visible to translation units).

---

## CPP08 — Templated Containers, Iterators, Algorithms

**Focus:** STL usage, iterators, algorithmic thinking with containers.

**Typical exercises**

* **ex00 – `easyfind`**: Find integer in container; throw if not found; support vector/list/deque.
* **ex01 – `Span`**: Store numbers, compute shortest/longest span; range insert; exceptions on overflow/underflow.
* **ex02 – `MutantStack`**: Stack with iterators by deriving/adapting underlying container.

**Key points**

* Prefer exceptions for invalid operations; complexity matters (O(n) spans, not O(n²)).

---

## CPP09 — STL & Algorithms on Real Tasks

**Focus:** Parsing, validation, performance with standard containers/algorithms.

**Typical exercises**

* **ex00 – BitcoinExchange**: Parse database of date→price; compute values from input; validate dates; handle errors line-by-line.
* **ex01 – RPN**: Evaluate Reverse Polish Notation with a stack; input validation; integer ops.
* **ex02 – PmergeMe**: Implement Ford–Johnson merge-insert sort; measure time on `std::vector` and `std::deque`; identical outputs.

**Key points**

* Robust error handling without aborting the whole program.
* For `PmergeMe`, ensure the same sorted result across containers and print timings as required.

---

## Testing Tips

* **Deterministic output**: Match the subject’s expected format exactly (spacing, punctuation, newlines).
* **Edge cases**: empty input, invalid indices, overflow/underflow, boundary grades, NaN/Inf tokens, duplicate elements.
* **Memory checks**: Use `valgrind` (if allowed) or double-check all `new`/`delete` pairs; no leaks, no double-frees.
* **Const correctness**: Provide const overloads for accessors and `operator[]` when needed.
* **Exceptions**: Catch by `const std::exception&` and never let them crash the tester.

---

## Evaluation Checklist

* ✅ **Compiles with** `-Wall -Wextra -Werror -std=c++98`
* ✅ **Makefile** has `all`, `clean`, `fclean`, `re`; uses variables; relinks only when needed
* ✅ **No forbidden functions**; no `using namespace std;`
* ✅ **Headers**: include guards, minimal includes, forward declarations where possible
* ✅ **Classes**: OCF present when owning resources; Rule of Three/Five applied appropriately
* ✅ **Polymorphism**: virtual destructors in polymorphic bases; correct override qualifiers (commented since C++98 has no `override` keyword)
* ✅ **I/O**: exact formatting per subject
* ✅ **STL**: use correct iterators/algorithms; avoid quadratic behavior when a linear/`n log n` option exists
* ✅ **Error handling**: clear messages; no abrupt `exit(1)` unless subject demands

---

## Makefile Template

```Makefile
# Generic 42 Makefile for an exercise

NAME    := program
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

INCS    := ./include
SRCS    := main.cpp \
# add your .cpp files here

OBJS    := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INCS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```
