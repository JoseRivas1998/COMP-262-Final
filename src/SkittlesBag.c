
#include "SkittlesBag.h"

typedef struct skittles_bag {
    int red;
    int orange;
    int yellow;
    int green;
    int purple;
} SKITTLES_BAG;

int randInt(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

// This is the "constructor" of a skittles bag
void construct_skittles_bag(SKITTLES_BAG *this) {
    // Ideally, there should be 12 of each color
    int idealPerColor = 60 / 5;
    // Let's assume the maximum deviance is 5 skittles more than or less than 12
    int deviation = 5;
    int min = idealPerColor - deviation;
    int max = idealPerColor + deviation;
    // Fill the bag randomly, should be uniformly distributed and averages 60 per bag
    this->red = randInt(min, max);
    this->orange = randInt(min, max);
    this->yellow = randInt(min, max);
    this->green = randInt(min, max);
    this->purple = randInt(min, max);
}

/**
 * This is the equivalent to using the "new" keyword in Java. It allocates the memory
 * with everything set to zero, calls the constructor on that allocated space, and return the address.
 * @return A pointer to the newly constructed skittles bag
 */
SKITTLES_BAG *create_skittles_bag() {
    SKITTLES_BAG *instance = calloc(1, sizeof(SKITTLES_BAG));
    construct_skittles_bag(instance);
    return instance;
}

/**
 *
 * @param this the skittles bag to count
 * @return The number of skittles in the bag
 */
int skittles_in_bag(SKITTLES_BAG *this) {
    return this->red + this->orange + this->yellow + this->green + this->purple;
}

/**
 * Equivalent to an "equals" method in an OO language.
 * @param bag1
 * @param bag2
 * @return True if the amount of skittles per color in each bag are equal
 */
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

/**
 * Used to debug skittles bags
 * @param this
 */
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

/**
 * This is a destructor function, it is good practice to have it in here just in case we wanted to add
 * anything that we many need to free to the bag itself
 */
void destruct_skittles_bag(SKITTLES_BAG *this) {
    /*empty*/
}

/**
 * This frees the given skittles bag, calls the destructor to make sure that everything in the bag is freed,
 * frees the bag itself as well.
 * @param this
 */
void destroy_skittles_bag(SKITTLES_BAG *this) {
    destruct_skittles_bag(this);
    free(this);
}
