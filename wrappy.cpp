<%
cfg['compiler_args'] = ['-std=c++11']
cfg['include_dirs'] = ['eigen-3.3.7']
setup_pybind11(cfg)
%>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "core.hpp"

namespace py = pybind11;

void myfunc_wrapper(py::EigenDRef<Eigen::MatrixXd> K, double m) {
    myfunc(K, m);
}

PYBIND11_MODULE(wrappy, m) {
    m.def("myfunc_wrapper", &myfunc_wrapper);
}