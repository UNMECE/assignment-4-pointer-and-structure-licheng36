//item.h
#ifndef item_h
#define item_h

#include <stdlib.h>
#include <string.h>

struct _Item
{
double price;
char  *sku;
char  *name;
char *category;
};
typedef struct _Item Item;

#endif
