## Linux Tree Traversal

Tried implementing the functionality of the linux tree function. 

The core logic is very simple, you open a path, check if the object is a directory or if it is a file. If the latter, you print it to standard out, if the former, you call the traversal recursively. 

It was pretty interesting to look at the actual posix specifications of opendir/readdir/walkdir. The same can be found at the following sites -
  1. Readdir  - [link](https://pubs.opengroup.org/onlinepubs/009604599/functions/readdir.html)
  2. Opendir  - [link](https://pubs.opengroup.org/onlinepubs/009604599/functions/opendir.html)

#### Planned extensions

Thinking of actually working on rendering functionality, i.e. the arrows and how the tree function allows imposing a limit on the actual expansion.
