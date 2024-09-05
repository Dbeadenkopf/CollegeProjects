#include <stdio.h>
#include <stdlib.h>
#include "frac_heap.h"
// This union was pulled directly from the project description
typedef union {
 union fraction_block_u *next;
 fraction frac;
} fraction_block_u;
   // global m_head to be used for entire program
static fraction_block_u *m_head;



/*
 * init_heap():
 * must be called once by the program using your
 * functions before calls to any other functions are made. This
 * allows you to set up any housekeeping needed for your memory
 * allocator. For example, this is when you can initialize
 * your free block list.
 */
void init_heap(void){
  m_head = NULL;
}

/*
 * new_frac():
 * must return a pointer to fractions.
 * It should be an item taken from the list of free blocks.
 * (Don't forget to remove it from the list of free blocks!)
 * If the free list is empty, you need to get more using malloc()
 * (Number of blocks to malloc each time is specified in the project
 * description)
 */
fraction *new_frac(void){
  if (m_head == NULL){
    m_head = malloc(10*sizeof(fraction_block_u));
    fraction_block_u *ptr_Ten = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Nine = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Eight = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Sev = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Six = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Five = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Four = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Three = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_Two = malloc(sizeof(fraction_block_u));
    fraction_block_u *ptr_One = malloc(sizeof(fraction_block_u));
    ptr_Ten->next = NULL;
    ptr_Nine->next = ptr_Ten;
    ptr_Eight->next = ptr_Nine;
    ptr_Sev->next = ptr_Eight;
    ptr_Six->next = ptr_Sev;
    ptr_Five->next = ptr_Six;
    ptr_Four->next = ptr_Five;
    ptr_Three->next = ptr_Four;
    ptr_Two->next = ptr_Three;
    ptr_One->next = ptr_Two;
    m_head = ptr_One;
    printf("\nCalled malloc(%d): Returned 0x%Lx\n\n", 10*sizeof(fraction_block_u), &m_head);
  }
  fraction_block_u *return_frac;
  return_frac = m_head;
  m_head = m_head->next;
  return (&return_frac->frac); 
}

/*
 * del_frac():
 * takes a pointer to a fraction and adds that item to the free block list.
 * The programmer using your functions promises to never use that item again,
 * unless the item is given to her/him by a subsequent call to new_frac().
 */
void del_frac(fraction *frac){
  if(frac == NULL){
    printf("\nError: del_frac() issued on NULL pointer.\n");
    exit(1);
  }
  fraction_block_u *return_frac = (fraction_block_u *) frac;
  if(m_head == NULL){
    m_head = return_frac; // garbage
    return_frac->next = NULL; // taking care of garbage
  }
  else{
    return_frac->next = m_head->next;
  }
  m_head->next = return_frac; // setting to return frac
  // so we can add to front of the linked list
}

/*
 * dump_heap():
 * For debugging/diagnostic purposes.
 * It should print out the entire contents of the free list,
 * printing out the address for each item.
 */
void dump_heap(void){
  fraction_block_u *ptr = m_head;
  printf("\n**** BEGIN HEAP DUMP ****\n\n");
  while(ptr!= NULL){
    printf("0x%Lx\n", ptr);
    ptr = ptr->next;
  }
  printf( "\n**** END HEAP DUMP ****\n\n");
}


