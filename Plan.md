1.
Introduction & Background
OpenMP terms: Directives & Clauses
Open MP’s fork-join execution model 
Code 1: program with directive parallel with clause num_threads

2.
	Code 2: Parallelized Summation of first N integers
	Code 2 illustrates:
data/workload partitioning & the need for mutual exclusion	
mutual exclusion in openMP with directive critical 

3.
Parallelizing for-loops with OpenMP’s directive parallel for
Permitted forms of for loops
Loop-carried dependence
 

4.
	Code 3: Calculate PI by computing sum of a series
Code 3 is developed illustrating mistakes/pitfalls
	Forgetting to eliminate loop-carried dependence
	Forgetting to properly setup variable scopes (shared vs private)
	Forgetting mutual exclusion for summing partial sums
