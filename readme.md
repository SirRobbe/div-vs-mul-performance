# Division vs Multiplication Performance test

This sample is the reference code for my [blog post](https://sirrobbe.dev/blog/0004-div-vs-mul-performance).

Aim of the article was to investigate if there is a significant performance increase when using the multiplicative inverse instead of doing a regular division.

It is tested on gcc and clang.

Run to build:
`g++ main.cpp -O2 -Wall`
or
`clang++ main.cpp -O2 -Wall`
