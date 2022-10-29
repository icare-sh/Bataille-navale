//implement the naval battle game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

#define MAX 100

int main()
{
    int plateau[5][5];
    debutplateau(plateau);
    afficheplateau(plateau);
    return 0;
}
