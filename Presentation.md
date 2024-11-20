Intro:
    - An executable program runs as a process
    - Using a single core
    - Today processors are multicore
    - Using a single core on a multicore processor?

Parallel Programming:
    - Parallel programmig helps utilize all cores
    - Can boost performance
    - Different frameworks exist:
        * PThreads
        * OpenMP
        * CUDA
        ..., etc.

OpenMP:
    - High-level parallel programming framework
    - Support exists in most commercial compilers
    - Easy to get started
    - Working:
        * Creates multiple threads that run in parallel
        * Can partition your task among parallel threads
        * Potentially finishing quickly

OpenMP Syntax:
    - Tag parts of your code with ~**pragmas**
    - By defautl pragmas are ignored by compiler
    - Compile with `-fopenmp` flag for OpenMP pragmas
    - OpenMP pragmas syntax:
        #pragma omp **directive** **clauses**
    - Let's see an example (code_1.c)
