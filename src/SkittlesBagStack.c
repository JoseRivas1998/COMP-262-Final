#include "SkittlesBagStack.h"

/**
 * A node for the linked list
 */
typedef struct skittles_bag_node {
    SKITTLES_BAG *val;
    struct skittles_bag_node *next;
} SKITTLES_BAG_NODE;

/**
 * The linked stack's structure itself. It consists of a head which is linked to the rest of the stack.
 */
typedef struct skittles_bag_stack {
    SKITTLES_BAG_NODE *head;
} SKITTLES_BAG_STACK;

void construct_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    // Initially the skittles stack's head is null
    this->head = NULL;
}

SKITTLES_BAG_STACK *create_skittles_bag_stack() {
    SKITTLES_BAG_STACK *instance = calloc(1, sizeof(SKITTLES_BAG_STACK));
    construct_skittles_bag_stack(instance);
    return instance;
}

bool is_empty(SKITTLES_BAG_STACK *this) {
    return this == NULL || this->head == NULL;
}

bool is_in_skittles_bag_stack(SKITTLES_BAG_STACK *this, SKITTLES_BAG *val) {
    if(!this) {
        return false;
    }
    SKITTLES_BAG_NODE *cN = this->head;
    // Iterate through the stack
    while (cN != NULL) {
        // As soon as we find a bag that equals the given bag, return true and break out of function
        if(skittles_bags_equal(cN->val, val)) {
            return true;
        }
        // Otherwise, move on to the next node. The node will eventually be null which signifies the bottom of the stack
        cN = cN->next;
    }
    return false;
}

void add_to_skittles_bag_stack(SKITTLES_BAG_STACK *this, SKITTLES_BAG *newValue) {
    // Allocate space for the new node and populate with values
    SKITTLES_BAG_NODE *newHead = calloc(1, sizeof(SKITTLES_BAG_NODE));
    newHead->val = newValue;
    newHead->next = this->head;
    // Since this a stack, the head of the stack is set to the new node
    this->head = newHead;
}

void print_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    SKITTLES_BAG_NODE *cN = this->head;
    while(cN != NULL) {
        print_skittles_bag(cN->val);
        cN = cN->next;
    }
}

void destructSkittlesBagNode(SKITTLES_BAG_NODE *node) {
    if (!node) {
        return;
    }
    // Free the next node, recurse until the next node is null
    destructSkittlesBagNode(node->next);
    // Once the nodes after this node are freed, free the skittles bag
    destroy_skittles_bag(node->val);
    // Null out values to avoid seg faults
    node->val = NULL;
    node->next = NULL;
    // Free up the node
    free(node);
}

void destruct_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    destructSkittlesBagNode(this->head);
}

void clear_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    destruct_skittles_bag_stack(this);
    this->head = NULL;
}

void destroy_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    if(!this) {
        return;
    }
    // Destroy all the nodes in the stack
    destruct_skittles_bag_stack(this);
    this->head = NULL;
    // Free the memory for the stack
    free(this);
}
