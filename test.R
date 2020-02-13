#!/usr/bin/env Rscript
library("optparse")
 
option_list = list(
    make_option(c("-s", "--size"), type="character", default='3x5', 
              help="test matrix size in 'nxp' format [default = %default]", metavar="character"),
    make_option(c("-f", "--func_name"), type="character", default='wrapper_1', 
              help="function name to run [default = %default]", metavar="character"),
    make_option(c("-m", "--multiplier"), type="numeric", default=1.23, 
              help="default multiplier value [default = %default]", metavar="numeric"),
    make_option(c("-d", "--dense"), action='store_true', default=TRUE, 
              help="input matrix is dense [default = %default]", metavar="logical")
); 
 
opt_parser = OptionParser(option_list=option_list);
opt = parse_args(opt_parser);

library(RcppEigen)
library(Matrix)

size = strsplit(opt$size, 'x')[[1]]
n = as.integer(size[1])
p = as.integer(size[2])
m = opt$multiplier

if (opt$dense) {
    A = matrix(1, n, p)
} else {
    A = Matrix(c(0, 0, 2:0), n, p)
}

## Asp = Matrix(, n, p)

Rcpp::sourceCpp('wrapr.cpp')

get(opt$func_name)(A, m)

cat('Size of matrix A is', n, 'x', p, '\n')
cat('First value of A is', A[n, p], '\n')
cat(A[1,1], 'should be equal to', m, '\n')