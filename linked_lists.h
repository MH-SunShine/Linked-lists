#include<stdlib.h>
#include <stdbool.h>

typedef struct node* Node;

bool is_empty(Node);
Node from_number(int);
void print_list(const Node);
Node from_array(int*, int);
Node prepend(int, Node);
int length(const Node);
int maximum(const Node);
int minimum(const Node);
Node insert_at(int, int, const Node);
Node reverse(const Node);
Node concatenate(const Node, const Node);
Node range(int, int);
int product(const Node);
int sum(const Node);
Node delete(int item, const Node);
Node delete_all(int item, const Node);