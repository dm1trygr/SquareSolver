# SquareSolver
This small program can solve square equations!


## How to install

This guide is written for Windows, but the algorithm 
is similar on other operating systems.

1. Download this repo from Github. On the main page,
   press button "Code", then "Download ZIP"

![Step 1](https://github.com/dm1trygr/SquareSolver/assets/103391790/6d838aea-6d26-4f32-a398-739e1789db23)

2. Extract downloaded ZIP archive

![Step 2](https://github.com/dm1trygr/SquareSolver/assets/103391790/07367017-75a1-4596-a996-3048170d698f)

3. Go to folder with source code files and launch
   Terminal

![Step 3](https://github.com/dm1trygr/SquareSolver/assets/103391790/4c27cbe3-1d15-44b5-8047-2d3036cfb191)

4. Enter comand "make" in terminal to compile source
   code files

![Step 4](https://github.com/dm1trygr/SquareSolver/assets/103391790/0a619153-9ab7-4740-9d98-4e7a92da4c94)

5. Done!

> Instead of this, you can just download .exe file from
> Releases sections, but this works only on Windows

## How to use

1. Go to folder with binary file and launch Terminal

![Launch](https://github.com/dm1trygr/SquareSolver/assets/103391790/8f73bc9e-2b86-4530-b394-7ec55136a658)

2. To show full information about this program, write
   in terminal "[name-of-binary-file] -h". The program
   will show all information about itself, how to use
   it and its flags

![Help](https://github.com/dm1trygr/SquareSolver/assets/103391790/39fe42e4-8c7d-4caf-b329-d6414afab038)

3. To solve a square equation, write in terminal
   "[name-of-binary-file] -s". The program will ask you
   for 3 coefficients in turn, and then it will display
   solutions of the equation given by these coefficients
   If you want to stop, just enter "0" when program
   will ask "Do you want to continue?"

![Square](https://github.com/dm1trygr/SquareSolver/assets/103391790/e25db5d5-0db7-40ba-b8b5-d85be79ff4d0)

5. To solve a linear equation, write in terminal
   "[name-of-binary-file] -l". The actions are similar
   to those in paragraph 2, but you need to enter
   2 coefficients instead of 3.

![Linear](https://github.com/dm1trygr/SquareSolver/assets/103391790/3e71f0bf-a283-4010-87ce-1c3a70ebeb1b)

6. To solve an equations equations with coefficients
   written to a file and print solutions to file,
   write in terminal "[name-of-binary-file] -f
   [input file] [output file]".

![File-CMD](https://github.com/dm1trygr/SquareSolver/assets/103391790/da4ba9dc-2313-4bba-9ef9-6e78b3e6dc21)

  This is input:
  
![File-INPUT](https://github.com/dm1trygr/SquareSolver/assets/103391790/01abee63-d78b-49f7-be18-0132bae1f0ce)

  And output:
  
![File-OUTPUT](https://github.com/dm1trygr/SquareSolver/assets/103391790/17fdcf80-9409-4eec-ab8b-dc1997bdfebd)

7. The program can also test itself! To do it,
   write in terminal "[name-of-binary-file] -t",
   and program will print results of tests.

![Tests](https://github.com/dm1trygr/SquareSolver/assets/103391790/5c680823-e784-4dd8-b0fb-9ef8f5177914)
   
## Short information about flags

-s = solves square equation

-l = solves linear equation

-f [input file] [output file] = reads coefficients from
file and writes solutions to other file

-t = runs unit tests

-h = shows full information about program
