# wcat

The program **`wcat`** is a simple program. Generally, it reads a file as
specified by the user and prints its contents. A typical usage is as follows,
in which the user wants to see the contents of main.c, and thus types:

```
prompt> ./wcat main.c
#include <stdio.h>
...
```

As shown, **wcat** reads the file **main.c** and prints out its contents.
The "**./**" before the **wcat** above is a UNIX thing; it just tells the
system which directory to find **wcat** in (in this case, in the "." (dot)
directory, which means the current working directory).

To create the **wcat** binary, you'll be creating a single source file,
**wcat.c**, and writing a little C code to implement this simplified version
of **cat**. To compile this program, you will do the following:

```
prompt> gcc -o wcat wcat.c -Wall -Werror
prompt>
```

This will make a single _executable binary_ called **wcat** which you can
then run as above.
