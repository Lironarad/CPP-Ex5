# CPP-ITERATORS

This project is a C++ language project that demonstrate "container-like" technique, which can be run in the loop even though they do not take up space In memory. 
The official name for this type of structure is iterable

to clone the project to your local machine:
```
git clone https://github.com/Lironarad/CPP-ITERATORS.git
```

### Installing an running the program
From the project directory on your local machine, write the following command in the terminal:
```
make demo && ./demo 
make test && ./test
```

 short brif about the project files:

1. range :
	represents a range of objects. For example, the (a, b) range, where a and b are integers, represents
  The integers from a to b, including a and not including b. For example, (5,9) range represents the numbers
  5,6,7,8

2. chain : 
  represents a concatenation of two container-like. For example, chain(range(5,9),range(1,4))
  Represents the numbers 5,6,7,8,1,2,3. 
  Note: Each container in particular is also container-like. In particular, string as well
  (String) is a container-like, so chain should work on it too, for example, the phrase:
  chain (range ('a', 'd'), string ("hello")).
  a, b, c, h, e, l, l, o
  
3. zip : 
 represents a parallel connection of two container-like. 
 They can be assumed to be the same length. For example, the phrase:
 zip (range (1,6), string ("hello"))
 Represents a series of five arranged pairs:
 1,h 2,e 3,l 4,l 5,o
  
4. product : 
 represents a Cartesian multiplication of two container-like (not exactly the same length). 
 for example:
 product (range (1ת4), string ("helo"))
 Represents 12 arranged pairs:
  1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o
  
5. powerset : 
  Represents all container-like subgroups. 
  for example:
  powerset (string ("abc")) represents 8 Subgroups
  {}, {a}, {b}, {a, b}, {c}, {a, c}, {b, c}, {a, b, c}
  
 5. Makefile :
  File to create the sample program and test program.
  
 6. Demo.cpp :
	Sample master plan.
