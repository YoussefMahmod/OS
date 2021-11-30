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
  more files to grep through (thus, more than one is possible). It should go
  through each line and see if the search term is in it; if so, the line
  should be printed, and if not, the line should be skipped.
- The matching is case sensitive. Thus, if searching for **`foo`**, lines
  with **`Foo`** will _not_ match.
- Lines can be arbitrarily long (that is, you may see many many characters
  before you encounter a newline character, \\n). **`wgrep`** should work
  as expected even with very long lines. For this, you might want to look
  into the **`getline()`** library call (instead of **`fgets()`**), or roll your
  own.
- If **`wgrep`** is passed no command-line arguments, it should print
  "wgrep: searchterm [file ...]" (followed by a newline) and exit with
  status 1.
- If **`wgrep`** encounters a file that it cannot open, it should print
  "wgrep: cannot open file" (followed by a newline) and exit with status 1.
- In all other cases, **`wgrep`** should exit with return code 0.
- If a search term, but no file, is specified, **`wgrep`** should work,
  but instead of reading from a file, **`wgrep`** should read from
  - standard input\*. Doing so is easy, because the file stream **`stdin`**
    is already open; you can use **`fgets()`** (or similar routines) to
    read from it.
- For simplicity, if passed the empty string as a search string, **`wgrep`**
  can either match NO lines or match ALL lines, both are acceptable.
