//
// Created by JoseR on 4/29/2019.
//
#include <omp.h>
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
    int purple = bagSize > 0 ? bagSize : 0;

    return create_skittles_bag(red, orange, yellow, green, purple);

}

int main() {
    int totalBagsToOpen = 0;
    int totalData = 0;
    int openedBags = 0;
    SKITTLES_BAG_STACK *stack;
    SKITTLES_BAG *skittlesBag;
    srand(time(0));

#pragma omp parallel shared(totalBagsToOpen, totalData) private(openedBags, stack, skittlesBag)
    {
        stack = create_skittles_bag_stack();
        openedBags = 0;
        while (true) {
            openedBags++;
            skittlesBag = create_skittles_bag();
            if (is_empty(stack)) {
                add_to_skittles_bag_stack(stack, skittlesBag);
            } else if (is_in_skittles_bag_stack(stack, skittlesBag)) {
                totalBagsToOpen += openedBags;
                totalData++;
                double average = (double) totalBagsToOpen / totalData;
                printf("Found duplicate after %d bags, current average: %lf\n", openedBags, average);
                openedBags = 0;
                clear_skittles_bag_stack(stack);
            } else {
                add_to_skittles_bag_stack(stack, skittlesBag);
            }
        }
    }

}
