import numpy as np
import cppimport

# cppimport.set_quiet(False)
# cppimport.force_rebuild()
gconcord = cppimport.imp("wrappy")

A = np.ones((2, 3))
m = 3.2

gconcord.myfunc_wrapper(A, m)
print(A[0,0], 'should be equal to', m)
