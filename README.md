# Compilation Project for the MiniVision Language Using FLEX and BISON Tools

## 1. Introduction

The goal of this project is to create a mini-compiler that goes through the various phases of compilation, including lexical analysis using the FLEX tool and syntax-semantics analysis using the BISON tool. Intermediate code generation, optimization, as well as machine code generation, will be done in the C language.

Parallel processing related to symbol table management and handling various errors should also be implemented during the compilation process.

## 2. Description of the MiniVision Language

The MiniVision language is a simple programming language designed for visualization. It is based on the Python language.

## Here are some examples of MiniVision programs:

```python
import numpy as np
import matplotlib.pyplot as plt

# Load the image as a numpy array
img = np.array([[255, 100, 50], [200, 150, 75], [100, 50, 25]])

# Invert the image (negative to positive)
img = 255 - img

# Display the image with the 'viridis' colormap
plt.imshow(img, cmap="viridis")
plt.show()
```

## Notes

The project is not yet finished; the part related to quads and optimization is still in progress, and the object code generation is not completed.

### Compilation Steps:
1. `flex lexical.l`
2. `bison -d syntax.y`
3. `gcc lex.yy.c syntax.tab.c -o TP -ll -ly` (Use `-lfl` for Windows)
4. `./TP < programme.txt`

## Debugging Tools:
- To generate verbose parsing information: `bison -v grammar.y -o parser.c > output.txt`
