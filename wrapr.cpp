#include <RcppEigen.h>
#include <iostream>
// #include <Eigen/Core>
// #include <Eigen/Dense>
#include <Eigen/Sparse>
// #include "core.hpp"

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
void myfunc_wrapper(Eigen::Map<Eigen::MatrixXd> M, double multiplier){
    myfunc(M, multiplier);
}

// [[Rcpp::export]]
void sparse(
    Eigen::Map<Eigen::MatrixXd> M, 
    Eigen::Map<Eigen::SparseMatrix<double> > Msp,
    double multiplier)
{
    Rcpp::Rcout << "M:\n" << M << std::endl;
    Rcpp::Rcout << "Msp:\n" << Msp << std::endl;
    sparse_core(M, Msp, multiplier);
}

using namespace Rcpp;

namespace impl {

template <typename Derived, typename SparseDerived>
void sparse_core(
    Eigen::MatrixBase<Derived> &D, 
    Eigen::SparseMatrixBase<SparseDerived> &Dsp, 
    double multiplier)
{
    D *= multiplier;
    Dsp *= multiplier;
    D += Dsp;
    Rcpp::Rcout << "D:\n" << D << std::endl;
    Rcpp::Rcout << "Dsp:\n" << Dsp << std::endl;
    Rcpp::Rcout << "Dsp.bottomRows(1):\n" << Dsp.bottomRows(1) << std::endl;
    Rcpp::Rcout << "D.diagonal():\n" << D.diagonal() << std::endl;
    // std::cout << Dsp << cout::endl;
    
}

} // impl

// SEXP ends(SEXP x, int n = 6) {
// [[Rcpp::export]]
SEXP ends(
    Eigen::Map<Eigen::MatrixXd> M, 
    Eigen::Map<Eigen::SparseMatrix<double> > Msp,
    SEXP xx) {
// SEXP ends(Rcpp::NumericMatrix xx, int n = 6) {

    Eigen::Map<Eigen::MatrixXd> x(Rcpp::as<Eigen::Map<Eigen::MatrixXd> >(xx));
    
    // Eigen::Map<Eigen::VectorXd> XS(Rcpp::as<Eigen::Map<Eigen::VectorXd> >(X)); 
    // return true;
    
    // NumericMatrix xx(x);
    Rcout << x << std::endl;
    Rcout << x.rows() << x.cols() << std::endl;
    
    Eigen::MatrixXd asdf = Eigen::MatrixXd::Constant(3, 3, (double)6);
    Rcout << asdf << std::endl;
    
    return(Rcpp::wrap(asdf));
}