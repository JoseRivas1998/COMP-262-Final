//
// Created by JoseR on 4/30/2019.
//

#ifndef OPENMPTEST_SKITTLESBAGSTACK_H
#define OPENMPTEST_SKITTLESBAGSTACK_H

#include "SkittlesBag.h"

typedef struct skittles_bag_stack SKITTLES_BAG_STACK;

SKITTLES_BAG_STACK *create_skittles_bag_stack();

bool is_empty(SKITTLES_BAG_STACK *this);

bool is_in_skittles_bag_stack(SKITTLES_BAG_STACK *this, SKITTLES_BAG *val);

void add_to_skittles_bag_stack(SKITTLES_BAG_STACK *this, SKITTLES_BAG *newValue);

void print_skittles_bag_stack(SKITTLES_BAG_STACK *this);

void destroy_skittles_bag_stack(SKITTLES_BAG_STACK *this);

#endif //OPENMPTEST_SKITTLESBAGSTACK_H