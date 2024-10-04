#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
	Item item;
	item.price=price;
	item.sku=sku;
	item.category=category;
	item.name=name;
	item_list[index]=item;
};

void free_items(Item *item_list, int size){
	free(item_list);
};

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
	Item *items =(Item*)malloc(sizeof(Item)*5);
	add_item(items,127.99, "10001", "book","ECE101",0);
	add_item(items,3.39, "10002", "coffee","starbuck",1);
	add_item(items,5.49, "10003", "cup","TAKEYA",2);
  add_item(items,7.29, "10004", "shoe","nike",3);
	add_item(items,12.49, "10005", "backpack","AmericanEagle",4);

	if (argc>1){
	char *sku_input= argv[1];
	int size=sizeof(items)/sizeof(items[0]);
	int check=0;
	for(int i=0;i>=size;i++){
	if(strcmp(items[i].sku,sku_input)==0){
	Item *item=&items[i];
	print_items(item,1);
	free(item);
	break;
	}
	if(!check)printf("Item not found");
	}
	}
	else{
	print_items(items,5);
	printf("average price = %.2f\n",average_price(items,5));
	free_items(items,5);
	}
	return 0;
	};

