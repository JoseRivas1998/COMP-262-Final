//
// Created by JoseR on 4/29/2019.
//
#include "SkittlesBagStack.h"

int main() {
    SKITTLES_BAG_STACK *stack = create_skittles_bag_stack();

    int red = 1;
    int orange = 2;
    int yellow = 3;
    int green = 4;
    int purple = 5;

    for (int i = 0; i < 10; ++i) {
        SKITTLES_BAG *bag = create_skittles_bag(red, orange, yellow, green, purple);
        print_skittles_bag(bag);
        add_to_skittles_bag_stack(stack, bag);
        red++;
        orange++;
        yellow++;
        green++;
        purple++;
    }

    printf("\n\n");

    print_skittles_bag_stack(stack);
    destroy_skittles_bag_stack(stack);

}
