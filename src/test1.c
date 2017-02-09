#include "test1.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prototypes.h"
#include "utilities.h"
#include "force.h"

int tollerance(double a, double b){
  if(abs(a-b) < 1e-12)
    return 1;
  return 0;
}


void test_few_atoms(){

    /* Testing a one dimensional system */

    mdsys_t sys;

    /* read input file */
    sys.natoms=2;
    sys.mass=39.948;
    sys.epsilon=0.2379;
    sys.sigma=3.405;
    sys.rcut=8.5;
    sys.box=17.1580;
    sys.nsteps=1;
    sys.dt=5;

    sys.rx=(double *)malloc(sys.natoms*sizeof(double));
    sys.ry=(double *)malloc(sys.natoms*sizeof(double));
    sys.rz=(double *)malloc(sys.natoms*sizeof(double));
    sys.vx=(double *)malloc(sys.natoms*sizeof(double));
    sys.vy=(double *)malloc(sys.natoms*sizeof(double));
    sys.vz=(double *)malloc(sys.natoms*sizeof(double));
    sys.fx=(double *)malloc(sys.natoms*sizeof(double));
    sys.fy=(double *)malloc(sys.natoms*sizeof(double));
    sys.fz=(double *)malloc(sys.natoms*sizeof(double));


    azzero(sys.rx, sys.natoms);
    azzero(sys.ry, sys.natoms);
    azzero(sys.rz, sys.natoms);
    azzero(sys.vx, sys.natoms);
    azzero(sys.vy, sys.natoms);
    azzero(sys.vz, sys.natoms);

    sys.rx[0] = 1;
    sys.rx[1] = 1+sys.sigma;

    sys.vx[0] = 10.0;
    sys.vx[1] = 5.0;

    force(&sys);
    //printf("Potential Energy: %f\n", sys.epot);
    //printf("Force 0: %f\n", sys.fx[0]);
    //printf("Force 1: %f\n", sys.fx[1]);


    /* For a two particles system, the forces must be equal and opposite */
    if(tollerance(sys.fx[0], -sys.fx[1]))
      printf("Equal and opposite force test: OK \n");
    else
      printf("Equal and opposite force test: FAILED \n");
      

    /* At r = sigma the potential energy must be zero */
    if(tollerance(sys.epot,0))
      printf("Zero potential energy test: OK \n");
    else
      printf("Zero potential energy test: FAILED \n");


    free(sys.rx);
    free(sys.ry);
    free(sys.rz);
    free(sys.vx);
    free(sys.vy);
    free(sys.vz);
    free(sys.fx);
    free(sys.fy);
    free(sys.fz);

}
