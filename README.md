# Finding the closest 2 values (N-array)

> **Analysis of Algorithm Assignment-1 (3rd year of University)**


# Assignment Part 1

In this assignment, the closest 2 values were found using 2 different methods.

- **a) Brute Force :** What is [Brute Force](https://www.javatpoint.com/brute-force-approach)? To found closest 2 values with Brute Force search in N-array. Code is [here](https://github.com/uguraltindal/Finding-the-closest-2-values-N-array-/blob/main/bruteforce.c).

<img src="images/Bruteforce_1a.PNG" width ="500" height = "250">

- **b) 2nd-way :** Sort array with complexity **MergeSort(n logn)** at first. The reason we sort the array is, if the array elements are in order, it means that the closest 2 elements are **located next to each other.** Therefore, while **Brute-Force has $O(n^2)$** complexity, for this method MergeSort is $O(n logn)$ followed by **n-1** comparisons to find the closest array elements. Code is [here](https://github.com/uguraltindal/Finding-the-closest-2-values-N-array-/blob/main/2nd-way.c).

<img src="images/mergesort_1b.PNG" width ="500" height = "250">

<img src="images/mergesort_1b_2.PNG" width ="500" height = "250">

# Assingment Part 2

**Von Neumann’s Neighborhood**

Code is [here](https://github.com/uguraltindal/Finding-the-closest-2-values-N-array/blob/main/VonNeumann.c).

<img src="images/VonNeumann.PNG" width ="500" height = "250">
