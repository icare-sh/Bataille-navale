#include <stdio.h>

#include "color.h"

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void blue () {
  printf("\033[0;34m");
}

void yellow () {
  printf("\033[1;33m");
}

void violet () {
  printf("\033[0;35m");
}

void reset () {
  printf("\033[0m");
}
