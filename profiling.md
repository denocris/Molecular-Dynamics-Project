#Profiling

To profile our code we used one of our latop and gperf.

We aslo used the function "time" to time the computation without the added flag -pg which, with millions functions calls, can slow things down a bit:

1) is used for the example with 108 atoms
2) is used for the example with c.a. 2000 atoms


Before modifying the code we profiled using the following compiling options:

 - no options
 - -O3 (strong optimization)
 - -march=native (aggressive optimization specific for current CPU)
 - H stands for "half": using newton 3rd law we use half the number of atoms
 - E stands for "exponential": it means the code was re-written to avoid calls to exp/sqrt which are expensive
 
