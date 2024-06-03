# 15 puzzle

Simple implementation of 15 puzzle in C++ using `ncurses`.

Goal is get all numbers rearranged into numerical order from left to right, top to bottom.

![](assets/example.gif)

## Build & Run
Before installation, ensure that you have installed `ncurses` library
```shell
$ sudo apt install libncurses5-dev libncursesw5-dev # ubuntu
    
$ sudo dnf install ncurses-devel # fedora
```

```shell
$ git clone git@github.com:CheckSelfy/15puzzle.git
$ cd 15puzzle
$ cmake -S . -B build 
$ cd build
$ make
$ ./15game # run the game
```
