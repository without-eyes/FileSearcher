# Application (App) to find file on Local Host - [C/C++ GL BaseCamp] Qualifying Technical Test 2024

## Task conditions
========================================================================================
1. App has to find file by "name".

2. Search has to be started from root "/" directory. (or Disk "C:\" on Windows OS)
 
3. To make this search faster - App creates new Searching Thread for each sub-directory in
root directory, but not more than 8 Execution Threads.

5. Thread who will find needed file has to print Full Path to the file and has to notify all
the rest threads to stop searching.

========================================================================================

- Logic "to search file" has to be placed into static library.
- Application just uses this library to find files in a fast way.
- Static Library compilation has to be done separately from Application. 
- Compiler: GCC or G++.
- Use Makefile for compilation/linking instructions.

========================================================================================

Things to Google: (Concurrency, Makefile, GCC, Static Library)

## Prerequisites
To use this application, you need to have the these prerequisites:
- g++
- make

## Installation and Usage
To install and use this application, you have to:

1. Clone this repository:
```
git clone without-eyes/FileSearcher
```

3. Use makefile to build application:
```
make
```

3. Run the application:
```
./FileSearcher <file_name>
```
`<file_name>`: The name of the file you want to find.

4. The application begins the file search from the root directory and display the full path to the first appearence of it. In case the file is not found, an appropriate message will be displayed.
