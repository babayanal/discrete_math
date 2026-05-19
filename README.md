# Articulation Points Finder

A C++ program that finds **articulation points** (cut vertices) in an undirected graph using DFS traversal, and visualizes the result using Graphviz.

## Terms

- **Graph** — a structure made of vertices and edges.
- **Articulation Point** — a vertex whose removal from the graph increases its number of connected components.

## How It Works

1. Reads a graph from `Code/input.txt`
2. Builds an adjacency list and adjacency matrix
3. Finds articulation points using a DFS-based algorithm (Tarjan's approach)
4. Generates a Graphviz file (`new.gv`) with articulation points highlighted in green
5. Renders the graph as a PNG image and displays it with `feh`

## Input Format

The input file (`Code/input.txt`) follows this format:

```
<number_of_vertices>
<vertex1> <vertex2>
<vertex1> <vertex2>
...
```

- First line: number of vertices (maximum 999)
- Subsequent lines: edges defined as pairs of vertex numbers separated by a space

### Example (`input.txt`)

```
12
1 2
2 3
3 4
4 6
3 5
5 7
7 8
7 9
9 10
7 11
1 12
```

## Project Structure

```
Code/
├── main.cpp                    # Entry point
├── findArticulationPoints.cpp  # DFS-based articulation point algorithm
├── findArticulationPoints.hpp  # Header for articulation point functions
├── getDataFromFile.cpp         # File I/O and graph construction
├── getDataFromFile.hpp         # Header for file I/O functions
├── input.txt                   # Graph input data
└── makefile                    # Build automation
```

## Prerequisites

Requires a **UNIX/Linux** operating system with the following tools:

| Tool | Install Command |
|------|----------------|
| **g++** | `sudo apt install g++` |
| **graphviz** | `sudo apt install graphviz` |
| **feh** | `sudo apt install feh` |

## How To Run

Navigate to the `Code/` directory, then:

```bash
# Compile the program
make

# Run the program (finds articulation points and displays the graph)
make run

# Clean generated files (executable, .png, .gv)
make clean
```

## Output

- Articulation points are printed to the terminal (highlighted in color)
- A graph visualization (`new.png`) is generated and displayed, with articulation points colored **green** and other vertices colored **red**





