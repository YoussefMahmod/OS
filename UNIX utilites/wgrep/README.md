# **wgrep**

a variant of the UNIX tool **`grep`**. This tool looks through a file, line by line, trying to find a
user-specified search term in the line. If a line has the word within it, the
line is printed out, otherwise it is not.

Here is how a user would look for the term **foo** in the file **bar.txt**:

```
prompt> ./wgrep foo bar.txt
this line has foo in it
so does this foolish line; do you see where?
even this line, which has barfood in it, will be printed.
```

**Details**

- program **`wgrep`** is always passed a search term and zero or
  more files to grep through (thus, more than one is possible). It will go
  through each line and see if the search term is in it; if so, the line
  will be printed, and if not, the line will be skipped.
- The matching is case sensitive. Thus, if searching for **`foo`**, lines
  with **`Foo`** will _not_ match.
- If **`wgrep`** is passed no command-line arguments, it will print
  "wgrep: searchterm [file ...]" (followed by a newline) and exit with
  status 1.
- If **`wgrep`** encounters a file that it cannot open, it will print
  "wgrep: cannot open file" (followed by a newline) and exit with status 1.
- In all other cases, **`wgrep`** will exit with return code 0.
- If a search term, but no file, is specified, **`wgrep`** will work,
  but instead of reading from a file, **`wgrep`** will read from
  - standard input\*. Doing so is easy, because the file stream **`stdin`**
    is already open;
