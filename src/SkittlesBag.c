//
// Created by JoseR on 4/30/2019.
//
#include "SkittlesBag.h"

typedef struct skittles_bag {
    int red;
    int orange;
    int yellow;
    int green;
    int purple;
} SKITTLES_BAG;

void construct_skittles_bag(SKITTLES_BAG *this, int red, int orange, int yellow, int green, int purple) {
    this->red = red;
    this->orange = orange;
    this->yellow = yellow;
    this->green = green;
    this->purple = purple;
}

SKITTLES_BAG *create_skittles_bag(int red, int orange, int yellow, int green, int purple) {
    SKITTLES_BAG *instance = calloc(1, sizeof(SKITTLES_BAG));
    construct_skittles_bag(instance, red, orange, yellow, green, purple);
    return instance;
}


bool skittles_bags_equal(SKITTLES_BAG *bag1, SKITTLES_BAG *bag2) {
    if (bag1 == NULL || bag2 == NULL) {
        return false;
    }
    return (
            bag1->red == bag2->red &&
            bag1->orange == bag2->orange &&
            bag1->yellow == bag2->yellow &&
            bag1->green == bag2->green &&
            bag1->purple == bag2->purple
    );
}

void print_skittles_bag(SKITTLES_BAG *this) {
    if(!this) {
        return;
    }
    printf("{Red: %d, Orange: %d, Yellow: %d, Green: %d, Purple: %d}\n",
            this->red,
            this->orange,
            this->yellow,
            this->green,
            this->purple);
}

void destruct_skittles_bag(SKITTLES_BAG *this) {
    /*empty*/
}

void destroy_skittles_bag(SKITTLES_BAG *this) {
    destruct_skittles_bag(this);
    free(this);
}
