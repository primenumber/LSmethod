bin_PROGRAMS = lsmethod
lsmethod_SOURCES = level0.hpp \
									 level1.hpp level1.cpp \
									 level2.cpp level2.hpp \
									 matrix.hpp \
									 main.cpp \
									 make_csr.cpp make_csr.hpp \
									 solver.hpp solver.cpp

lsmethod_CPPFLAGS = -Og -g -std=c++14 -march=native -mtune=native \
										-Wl,--no-as-needed -I${MKLROOT}/include -m64
LDADD = -L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -ldl -lpthread -lm
