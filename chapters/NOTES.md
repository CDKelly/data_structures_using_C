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

[Pointer arithemtic and arrays](http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Pointers.html)<br>
_source_: exercise 3<br>
* the name of an array is like a constant pointer to the 0th element in the array<br>
* if `int a[25]`, then `a[n]` is equivalent to `*(a+n)`<br>
    * where the intent of `a+n` is to compute the address equal to `a` (a pointer) plus `n` (an integer) times the size of whatever `a` points to<br><br>
