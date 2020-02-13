template <typename Derived>
void myfunc(Eigen::MatrixBase<Derived>& b, double multiplier){
    b *= multiplier;
}

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
