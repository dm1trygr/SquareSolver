#ifndef ROOTS_AMOUNT_HEADER
#define ROOTS_AMOUNT_HEADER

//!Enum with name of constants meaning amount of roots of equation

enum RootsAmount {
    NO_ROOTS = 0,  //!<Equation hasn't any solutions
    ONE_ROOT = 1,  //!<Equation has one root
    TWO_ROOTS = 2,  //!<Equation has two roots
    INF_ROOTS = 888  //!<The solution of equation is any number
};

#endif
