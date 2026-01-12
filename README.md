# Uni-String & Multi-String Searching Algorithms

A clean and practical collection of four classic string‑matching algorithms, along with a **benchmark PDF** comparing their execution times on the same inputs.

This repository focuses on *understanding, implementing, and comparing* string-searching techniques — perfect for learning, performance analysis, and showcasing clean algorithmic skills.

---

##  Algorithms Implemented

### **1. Aho–Corasick**

* Multi-pattern matching
* Based on a trie + failure links
* Efficient for checking many patterns at once

### **2. Z-Function**

* Computes Z-array for pattern + text
* Useful for fast substring matching

### **3. KMP (Knuth–Morris–Pratt)**

* Preprocesses the pattern using LPS array
* Guarantees linear-time searching

### **4. Brute-Force Matching**

* Simple baseline approach
* Helps visualize why advanced algorithms matter

---

##  Project Structure

```
/String-Matching
├── Aho Corasick.cpp
├── Z Function.cpp
├── KMP Algo.cpp
├── Brute Solution.cpp
├── metrics.pdf               # benchmark results
└── README.md
```

> **Note:** Filenames contain spaces right now. You can rename them anytime for cleaner compiling (e.g., `Aho_Corasick.cpp`).

---

##  How to Compile

Example commands using `g++` (C++17):

```bash
g++ -std=c++17 -O2 -o aho "Aho Corasick.cpp"
g++ -std=c++17 -O2 -o zfunc "Z Function.cpp"
g++ -std=c++17 -O2 -o kmp "KMP Algo.cpp"
g++ -std=c++17 -O2 -o brute "Brute Solution.cpp"
```

The `-O2` flag enables compiler optimization so your benchmark timings are meaningful.

---

##  Running the Programs

Usage will depend on your implementation, but a typical run looks like:

```bash
./aho
./zfunc
./kmp
./brute
```

---

##  Benchmark Results (metrics.pdf)

The file **`metrics.pdf`** contains your complete performance comparison, including:

* Execution time for each algorithm
* Multiple test runs
* Same input across all algorithms
* Clear evidence of how each algorithm scales

## Complexity Comparison Table 
''' 
Algorithm      |	Best Case	| Average Case |	Worst Case | 	Notes
Aho–Corasick      O(n)	      O(n)	          O(n + m)     	Best for multi‑pattern searches
Z‑Function	      O(n)	      O(n)	          O(n)	        Great for pattern + text concat
KMP              	O(n)	      O(n)           	O(n)	        Zero backtracking
Brute Force	      O(n)	      O(n·m)	        O(n·m)	      Simple but slow
''' 
