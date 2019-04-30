//
// Created by JoseR on 4/30/2019.
//

#include "SkittlesBagStack.h"

typedef struct skittles_bag_node {
    SKITTLES_BAG *val;
    struct skittles_bag_node *next;
} SKITTLES_BAG_NODE;

typedef struct skittles_bag_stack {
    SKITTLES_BAG_NODE *head;
} SKITTLES_BAG_STACK;

void construct_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    this->head = NULL;
}

SKITTLES_BAG_STACK *create_skittles_bag_stack() {
    SKITTLES_BAG_STACK *instance = calloc(1, sizeof(SKITTLES_BAG_STACK));
    construct_skittles_bag_stack(instance);
    return instance;
}

bool is_empty(SKITTLES_BAG_STACK *this) {
    return this->head == NULL;
}

bool is_in_skittles_bag_stack(SKITTLES_BAG_STACK *this, SKITTLES_BAG *val) {
    SKITTLES_BAG_NODE *cN = this->head;
    while (cN != NULL) {
        if(skittles_bags_equal(cN->val, val)) {
            return true;
        }
        cN = cN->next;
    }
    return false;
}

void add_to_skittles_bag_stack(SKITTLES_BAG_STACK *this, SKITTLES_BAG *newValue) {
    SKITTLES_BAG_NODE *newHead = calloc(1, sizeof(SKITTLES_BAG_NODE));
    newHead->val = newValue;
    newHead->next = this->head;
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
    destructSkittlesBagNode(node->next);
    destroy_skittles_bag(node->val);
    node->val = NULL;
    node->next = NULL;
    free(node);
}

void destruct_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    destructSkittlesBagNode(this->head);
}

void destroy_skittles_bag_stack(SKITTLES_BAG_STACK *this) {
    destruct_skittles_bag_stack(this);
    this->head = NULL;
    free(this);
}
