
#include <omp.h>
#include "SkittlesBagStack.h"

int main() {
    int totalBagsToOpen = 0;
    int totalData = 0;
    int openedBags = 0;
    SKITTLES_BAG_STACK *stack;
    SKITTLES_BAG *skittlesBag;
    srand((unsigned int) time(0));

#pragma omp parallel shared(totalBagsToOpen, totalData) private(openedBags, stack, skittlesBag)
    {
        stack = create_skittles_bag_stack(); // Initialize the stack
        while (true) {
            // Open a skittles bag
            openedBags++;
            skittlesBag = create_skittles_bag();
            if (is_empty(stack)) {
                // If the stack is empty, just push and move on
                add_to_skittles_bag_stack(stack, skittlesBag);
            } else if (is_in_skittles_bag_stack(stack, skittlesBag)) { // Duplicate found
                // Add the current data to the shared data
                totalBagsToOpen += openedBags;
                totalData++;
                double average = (double) totalBagsToOpen / totalData;
                if (totalData % 50 == 0) {
                    // Only print the current average ever 50 times we find an average
                    printf("Current average: %.2lf\n", average);
                }
                // Reset the stack and the count of opened bags
                openedBags = 0;
                clear_skittles_bag_stack(stack);
                destroy_skittles_bag(skittlesBag);
            } else {
                // If a duplicate was not found, add the bag to the stack and move on
                add_to_skittles_bag_stack(stack, skittlesBag);
            }
        }
    }

}
