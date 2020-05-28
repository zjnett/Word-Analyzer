# Word Analyzer
This program performs analysis on a `.txt` file supplied by the user. The purpose of this project is to practice multithreaded programming and to analyze the performance changes when multithreaded implementations are invoked.

##  Performance Graphs
To be written.

## Performance Notes
To be written, some unstructured notes are below.
* multithreaded performance seems worse than single threaded
* multithreaded functionality verified by `htop` (CPU cores allocate appropriately)
* overhead of managing concurrent threads negatively impacts performance time
* passing large class w/ unordered map by value increases time (cannot be by reference)