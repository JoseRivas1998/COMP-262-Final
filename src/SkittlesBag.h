#ifndef OPENMPTEST_SKITTLESBAG_H
#define OPENMPTEST_SKITTLESBAG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * Structural representation of a skittles bag.
 */
typedef struct skittles_bag SKITTLES_BAG;

SKITTLES_BAG *create_skittles_bag();

int skittles_in_bag(SKITTLES_BAG *this);

bool skittles_bags_equal(SKITTLES_BAG *bag1,SKITTLES_BAG *bag2);

void print_skittles_bag(SKITTLES_BAG *this);

void destroy_skittles_bag(SKITTLES_BAG *this);

#endif //OPENMPTEST_SKITTLESBAG_H
