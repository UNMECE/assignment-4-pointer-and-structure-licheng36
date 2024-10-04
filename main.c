#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
//	Item item;
//  item.price=price;
//	item.sku=sku;
//	item.category=category;
//	item.name=name;
//	item_list[index]=item;
//};

void add_item(Item *item_list, double price,const char *sku, const char *category,const char *name, int index) {
    item_list[index].price = price;

		    // Dynamically allocate memory for the SKU, name, and category strings
        item_list[index].sku = (char *)malloc(strlen(sku) + 1);
				item_list[index].name = (char *)malloc(strlen(name) + 1);
				item_list[index].category = (char *)malloc(strlen(category) + 1);
				
				// Copy strings into the item struct
				strcpy(item_list[index].sku, sku);
				strcpy(item_list[index].name, name);
				strcpy(item_list[index].category, category);
}

//function to free the allocated memory
void free_items(Item *item_list, int size){
	for (int i = 0; i < size; i++) {
	free(item_list[i].sku);
	free(item_list[i].name);
	free(item_list[i].category);
}
	free(item_list);
}

//function to calculate the average price
double average_price(Item *item_list, int size){
	double avg=0;
	for(int i=0;i<size;i++){
		avg+=item_list[i].price;
		}
		return avg/size;
};

void print_items(Item *item_list, int size){
	for(int i=0;i<size;i++){
	Item item=item_list[i];
	printf("###########\n");
	printf("item name=%s\n",item.name);
	printf("item sku=%s\n",item.sku);
	printf("item category=%s\n",item.category);
	printf("item price=%.2f\n",item.price);
}
	printf("##########\n");
};

int main(int argc, char *argv[]){
	int size=5;
	Item *items =(Item*)malloc(sizeof(Item)*5);
	add_item(items,127.99, "10001", "book","ECE101",0);
	add_item(items,3.39, "10002", "coffee","starbuck",1);
	add_item(items,5.49, "10003", "cup","TAKEYA",2);
  add_item(items,7.29, "10004", "shoe","nike",3);
	add_item(items,12.49, "10005", "backpack","AmericanEagle",4);

  print_items(items, size);
	printf("Average price of items = %f\n", average_price(items, size));

if (argc == 2) {
char *search_sku = argv[1];
int found = 0;
for (int i = 0; i < size; i++) {
if (strcmp(items[i].sku, search_sku) == 0) {
printf("Item found:\n");
printf("Item name = %s\n", items[i].name);
printf("Item SKU = %s\n", items[i].sku);
printf("Item category = %s\n", items[i].category);
printf("Item price = %f\n", items[i].price);
found = 1;
break;
}
}
if (!found){
printf("Item not found.\n");
}
}
free_items(items, size);
return 0;
	};

