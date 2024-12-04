<p align="center">
  <a href="https://github.com/umutsevdi/aoc-2024">
  <h1 align="center">Advent of Code 2024</h1>
  </a>
<p align="center"> 
A repository that contains Advent of Code 2024 Solutions in C programming
language. 
  <br/>
    <i>Developed by <a href="https://github.com/umutsevdi">Umut Sevdi</a></i>
<p align="center"><a href="https://umutsevdi.github.io/aoc-2024/md_README.html">
<strong> Explore the docs » </strong></a></p>
</strong></a></p>


## aoc CLI
aoc CLI can display questions, execute solutions on given inputs. aoc CLI can
query questions either by their code name or their day.
```sh
         ╒══════════════════════════════════════════╕
                      Usage: aoc [OPTIONS]
          Advent of Code 2024 Command Line Interface
         ╘══════════════════════════════════════════╛

Options:
  ┌─────────────────────────────────────────────────────────────┐
  │  -h/--help                 │   Shows this message           │
  │  -r/--read [day]           │   Prints the question of the   │
  │                            │day for the specified day       │
  │  -q/--question [day] [file]│   Solves the question of the   │
  │                            │day for the specified day       │
  │  --[question-name] [file]  │   Solves the question by its   │
  │                            │name (e.g. --turing-machine)    │
  └─────────────────────────────────────────────────────────────┘
Supports pipe operations.

Examples:
  aoc  -r 1                      │ Displays the question of Day 1
  aoc  -q 2 file.txt             │ Solves the question for Day 2 with file.txt as input
  aoc  -q 5 <<< "1 2 3 4 5 6"    │ Solves the question for Day 5 using given input
  aoc  --turing-machine file.txt │ Solves the question with the name "turing-machine"

Available Questions are:
--historian-hysteria, --red-nosed-reports, --mull-it-over,
--ceres-search,
```
## Installation
```sh
    sudo apt install doxygen # dependency for docs
    mkdir build
    cd build/
    cmake ..
    make
```
