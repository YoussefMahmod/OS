# **Wzip and Wunzip**

a variant of the UNIX tool **`zip`**, **`unzip`**.

> `wzip` is a file compression tool, and the other `wunzip` is a file decompression tool

<br>

The type of compression used here is a simple form of compression called run-length encoding (RLE). RLE is quite simple: when you encounter n characters of the same type in a row, the compression tool (wzip) will turn that into the number n and a single instance of the character.

Thus, if we had a file with the following contents:

```
aaaaaaaaaabbbb
```

the tool would turn it (logically) into:

```
10a4b
```

However, the exact format of the compressed file is quite important; here, you will write out a 4-byte integer in binary format followed by the single character in ASCII. Thus, a compressed file will consist of some number of `5-byte` entries, each of which is comprised of a 4-byte integer (the run length) and the single character.

**Details**

- Correct invocation should pass one or more files via the command line to the program; if no files are specified, the program should exit with return code 1 and print `wzip`: file1 [file2 ...]" (followed by a newline) or `wunzip`: file1 [file2 ...]" (followed by a newline) for wzip and wunzip respectively.

- The format of the compressed file must match the description above exactly (a 4-byte integer followed by a character for each run).
- Do note that if multiple files are passed to `wzip`, they are compressed into a single compressed output, and when `unzipped`, will turn into a single uncompressed stream of text (thus, the information that multiple files were originally input into wzip is lost). The same thing holds for wunzip.
