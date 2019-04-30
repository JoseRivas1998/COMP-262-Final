//
// Created by JoseR on 4/29/2019.
//
#include <omp.h>
#include <time.h>
#include "SkittlesBagStack.h"

SKITTLES_BAG *openBag() {
    int bagSize = 60;
    int red = rand() % (bagSize + 1);
    bagSize -= red;
    int orange = rand() % (bagSize + 1);
    bagSize -= orange;
    int yellow = rand() % (bagSize + 1);
    bagSize -= yellow;
    int green = rand() % (bagSize + 1);
    bagSize -= yellow;
    int purple = bagSize;

    return create_skittles_bag(red, orange, yellow, green, purple);

}

int main() {
    int totalBagsToOpen = 0;
    int totalData = 0;
    int openedBags;
    SKITTLES_BAG_STACK *stack;
    SKITTLES_BAG *skittlesBag;
    srand((unsigned) time(0));

    #pragma omp parallel shared(totalBagsToOpen, totalData) private(stack, openedBags, skittlesBag)
    {
        stack = create_skittles_bag_stack();
        openedBags = 0;
        while(true) {
            skittlesBag = openBag();
            print_skittles_bag(skittlesBag);
            destroy_skittles_bag(skittlesBag);
        }
    }

}
