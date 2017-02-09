#ifndef VERLET1_H
#define VERLET1_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#include "prototypes.h"
#include "force.h"
#include "verlet2.h"

void velverlet(mdsys_t *sys);

#endif
