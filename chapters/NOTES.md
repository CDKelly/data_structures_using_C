# Notes
<hr>
I'm not sure if this'll take off the way I plan, but I wanted to jot down some mental notes I took along the way. Many times I would stumble upon a concept when reading or completing an exercise that would set me on a path to learn something interesting - something worth remembering (big or small).

### chapter 1

Regex basics<br>
_source_: exercise 3<br>
* [match example](https://www.quora.com/How-do-I-use-regular-expressions-in-the-C-programming-language)<br>
* [`regcomp`](http://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html) - compiles a regular expression into a form that is suitable for subsequent `regexec()` searches; [linux man page](https://linux.die.net/man/3/regcomp)<br>
* [`regexec`](https://www.mkssoftware.com/docs/man3/regexec.3.asp) - compares a null-terminated string with a compiled regular expression<br>
* [`regfree`](https://www.gnu.org/software/libc/manual/html_node/Regexp-Cleanup.html) - free memory used by a compiled regex<br><br>

[Pointer arithmetic and arrays](http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Pointers.html)<br>
_source_: exercise 3<br>
* the name of an array is like a constant pointer to the 0th element in the array<br>
* if `int a[25]`, then `a[n]` is equivalent to `*(a+n)`<br>
    * where the intent of `a+n` is to compute the address equal to `a` (a pointer) plus `n` (an integer) times the size of whatever `a` points to (see section 3.7: Pointers and Arrays)
    * from pgs. 68-69: `A[k] = BA(A) + w(k - lower_bound)`, where `BA` is the base address of `A`, `w` is the size of one element in memory, and `k` is index of the element whose address we're calculating<br><br>

[`strtol`](https://en.cppreference.com/w/c/string/byte/strtol)<br>
_source_: exercise 23<br>
* convert str to long
* [example](https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm); [SO answer](https://stackoverflow.com/a/7021750)<br><br>

<hr>

### chapter 3

[Function pointers](https://www.geeksforgeeks.org/function-pointer-in-c/)<br>
_source_: example 8<br>
* point to code, not data; typically stores the start of executable code<br>
* the function's name itself can be used to get the function's address
* [qsort example](https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/)<br><br>

Returning an array in C<br>
_source_: example 15<br>
I made the rookie mistake of returning a locally defined variable within a called function. I received a warning similar to the one [seen here](https://www.geeksforgeeks.org/return-local-array-c-function/). The key takeaway is that memory reserved for locally defined variables is freed after the function call is over (i.e. pointers to these local variables will point to something you don't want). This can be fixed in one of 3 ways: [SO answer](https://stackoverflow.com/a/18041130). Looking for this solution allowed to me to learn more about how variables in C should be declared, defined, used, etc.
* data segment - stores `static` variables, which are unchangeable and whose lifespan is that of the entire program; used when the size and lifespan of variables is well known
* stack - used for variables whose size is small(er) and whose lifespan is well controlled
* heap - used for variables whose size and lifespan are dynamic<br><br>


Inserting values into a dynamically-defined multi-dimensional array<br>
_source_: example 18<br>
I had trouble inserting user input into a multi-dimensional array defined as such: `int *arr = (int *) malloc(rows * cols * sizeof(int))`. To humans, this is can be visualized as a _rows_ x _cols_ matrix. However, in memory this is simply a long chain of int values stored in row major order - everything in row 1 is stored sequentially, then row 2 starts where row 1 ended, and so on. As a result, giving `scanf` the address of `arr` to store user input required some calculation:<br>
```
	for(int i = 0; i < rows; i++) {
		printf("\nrow %d", i+1);
		for(int j = 0; j < cols; j++) {
			printf("\ncol %d : ", j+1);
			scanf("%d", &(arr[(cols * i) + j]));
		}
	}
```
* `(cols * i)` - what row do we want, or what chunk of columns are we interested in?<br>
* `+ j` - once we know what row we're in, we can decide which column we want<br>
* `arr[n]` - get me the value at index `n`<br>
* `&(thing)` - give me the address in memory of `thing`<br>
* see section 3.9: Two-dimensional arrays (more specifically: figure 3.29, the formaula(s) on pg. 95, and section 3.9.2)<br><br>

<hr>

### chapter 4

Reading string from user input<br>
_source_: example 5<br>
There a few ways to read a string from user input:<br>
1. `scanf()` - terminates as soon as it finds a blank space<br>
1. `gets()` - overcomes the above obstacle but has been removed from c11, which means you might get a warning<br>
1. `fgets()` - gathers any whitespace; does not trigger any warning<br>
1. using `getchar()`, `getch()`, or `getche()` function repeatedly
