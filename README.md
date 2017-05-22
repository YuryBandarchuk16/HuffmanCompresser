# HuffmanCompresser
Console util for compressing and decompressing files using Huffman algorithm

To compress file you have execute the folliwng:

```{r, engine='bash', count_lines}
  ./ConsoleUtil <path_to_input_file> <path_to_output_file> cm
```

It compresses file <path_to_input_file> into <path_to_output_file>.

In order to decompress:
```{r, engine='bash', count_lines}
  ./ConsoleUtil <path_to_input_file> <path_to_output_file> dm
```

It decompresses file <path_to_input_file> into <path_to_output_file>.

Example:
```{r, engine='bash', count_lines}
  ./ConsoleUtil main.cpp encoded.txt cm
  ./ConsoleUtil encoded.txt main_decoded.cpp dm
  diff main.cpp main_decoded.cpp
```
diff - just to make sure everything works fine :)
