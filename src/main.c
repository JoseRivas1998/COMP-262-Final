//
// Created by JoseR on 4/29/2019.
//
#include <omp.h>
#include "SkittlesBagStack.h"

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
                destroy_skittles_bag(skittlesBag);
            } else {
                add_to_skittles_bag_stack(stack, skittlesBag);
            }
        }
    }

}
