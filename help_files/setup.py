from distutils.core import setup
from Cython.Build import cythonize

setup(
	name = 'integ_trap',
	ext_modules = cythonize('integ_trap.pyx'),
)
