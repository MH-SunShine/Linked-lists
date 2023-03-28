#include<stdio.h>
#include <stdlib.h>
#include "linked_lists.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define nothing NULL
#define and &&
#define or ||
#define current_item head->data
#define tail head->next


typedef struct node{
   int data;
   struct node* next;
}node;

bool is_empty(const Node head){
    return head == nothing;
}

Node cons(int data, Node list){
    Node _node = malloc(sizeof(node));
    _node->data = data;
    _node->next = list;
    return _node;
}#

Node from_number(int num){
    if(num == 0) return nothing;
    else return cons(num % 10, from_number(num / 10));
}

Node from_array(int* arr, int size){
    if(size == 0) return nothing;
    else return cons(arr[size - 1], from_array(arr, size - 1));
}

void print_list(const Node head){
    if(is_empty(head)) return;
    else{
        printf("%d ", current_item);
        print_list(tail);
    }
}

Node prepend(int data, Node list){
    return cons(data, list);
}

int length(const Node head){
    if(is_empty(head)) return 0;
    else return 1 + length(tail);
}

int maximum(const Node head){
    if(head->next == nothing) return current_item;
    else return max(current_item, maximum(tail));
}

int minimum(const Node head){
    if(head->next == nothing) return current_item;
    else return min(current_item, minimum(tail));
}

Node insert_at(int data, int index, const Node head){
    if(index == 0) return cons(data, head);
    else return cons(current_item, insert_at(data, index - 1, tail));
}

Node reverse(const Node head){
    if(is_empty(head)) return nothing;
    else return concatenate(reverse(tail), cons(current_item, nothing));
}

Node concatenate(const Node left, const Node right){
    if(is_empty(left)) return right;
    else return cons(left->data, concatenate(left->next, right));
}

Node range(int lower, int upper){
    if(lower > upper) return nothing;
    else if(lower == upper) return nothing;
    else return cons(lower, range(lower + 1, upper));
}

int product(const Node head){
    if(head->next == nothing) return current_item;
    else return current_item * product(tail);
}

int sum(const Node head){
    if(head->next == nothing) return current_item;
    else return current_item + sum(tail);
}

Node delete(int item, const Node head){
    if(is_empty(head)) return nothing;
    else if(current_item == item) return tail;
    else return cons(current_item, delete(item, tail));
}

Node delete_all(int item, const Node head){
    if(is_empty(head)) return nothing;
    else if(current_item == item) return delete_all(item, tail);
    else return cons(current_item, delete_all(item, tail));
}