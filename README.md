# Interfacing a shared core codebase in C++ with Python and R

## Python

Numpy arrays can be mapped using `pybind11` to `Eigen` interface. Then, core function `myfunc` can be executed on the mapped matrix.

To execute the test function and profile memory usage, run
```
/usr/bin/time -v python test.py
```

## R

`RcppEigen` can map an R matrix object to `Eigen` without copying. Then, core function `myfunc` can be executed on the mapped matrix

To execute the test function and profile memory usage, run
```
/usr/bin/time -v Rscript test.R
```

## `myfunc` template code

`myfunc` is written in template code so that the instantiated type can change depending on how it is compiled. Due to differences in Python vs. R storage order and interface package, the input type cannot be constrained further.