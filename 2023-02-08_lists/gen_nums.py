#! /usr/bin/env python
"""Generate output consisting of sys.argv[1] random numbers between 0 and 100."""

import sys
from random import randrange

print(int(sys.argv[1]))
for _ in range(int(sys.argv[1])):
    print(randrange(-100, 100))
