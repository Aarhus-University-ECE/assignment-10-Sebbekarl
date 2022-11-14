#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct tree_node *Insert(int x, struct tree_node *t)
{
  /* places the node in the tree */
  if (t == NULL)
  {
    tree_node *new_node = malloc(sizeof(tree_node));
    new_node->item = x;
    new_node->left = NULL;
    new_node->right = NULL;
    t = new_node;
  }
  
  /* goes through the tree to find where to place it */
  else if (t->item >= x)
  {
    t->right = Insert(x, t->right);
  }
  else if (t->item < x)
  {
    t->left = Insert(x, t->left);
  }

  return t;
}

struct tree_node *Remove(int x, struct tree_node *t)
{
  /* goes through the tree to find x */
  if (t == NULL)
  {
  }

  else if (t->item > x)
    t->right = Remove(x, t->right);

  else if (t->item < x)
    t->left = Remove(x, t->left);

  /* removes x from the tree */
  else if (t->item == x)
  {
    tree_node *temp = t;

    /* case 1: no left node  */
    if (t->left == NULL)
      t = t->right;

    /* case 2: left node is the biggest of the smallest */
    else if (t->left->right == NULL)
    {
      t->left->right = t->right;
      t = t->left;
    }

    /* case 3: left node is not the biggest of the smallest */
    else if (t->left->right != NULL)
    {
      temp = t->left->right;
      while (temp->right != NULL)
        temp = temp->right;
      t->item = temp->item;
    }

    free(temp);
  }
  return t;
}

int Contains(int x, struct tree_node *t)
{
  /* goes through the tree and checks if x is in the tree */
  if (t == NULL)
  {
    return false;
  }
  else if (t->item > x)
  {
    return Contains(x, t->right);
  }
  else if (t->item < x)
  {
    return Contains(x, t->left);
  }
  else if (t->item == x)
  {
    return true;
  }
}

struct tree_node *Initialize(struct tree_node *t)
{
  return NULL;
}

int Empty(struct tree_node *t)
{
  return t == NULL;
}

int Full(struct tree_node *t)
{
  return 0;
}
