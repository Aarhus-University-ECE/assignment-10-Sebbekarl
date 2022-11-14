#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

/* functions to create lists */
node *make_node(int v, node *q)
{
  node *p = malloc(sizeof(node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p)
{
  p->next = NULL;
}

/* print list to console */
void print_list(node *p)
{
  printf("%d, ", p->value);
  if (p->next == NULL)
    return;
  print_list(p->next);
  return;
}

int sum_squares(node *p)
{
  if (p == NULL)
    return 0;
  if (p->next == NULL)
    return square(p->value);
  return square(p->value) + sum_squares(p->next);
}

node *map(node *p, int (*f)(int))
{
  if (p == NULL)
    return NULL;
  if (p->next == NULL)
    return make_node(f(p->value), NULL);
  return make_node(f(p->value), map(p->next, f));
}

int square(int x)
{
  return x * x;
}
