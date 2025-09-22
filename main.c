#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

// Function prototypes
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[])
{
    // Create an array of Items by dynamically allocating space for 5 different items
    Item *item_list = (Item *)malloc(5 * sizeof(Item));
    
    // Add 5 different items to the array
    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 2.50, "14512", "snacks", "chips", 2);
    add_item(item_list, 8.99, "33456", "meat", "chicken breast", 3);
    add_item(item_list, 1.25, "98765", "beverages", "soda", 4);
    
    // Print all items to the screen
    print_items(item_list, 5);
    
    // Calculate and print the average price
    double avg = average_price(item_list, 5);
    printf("average price of items = %.6f\n", avg);
    
    // Handle command line arguments for SKU search
    if (argc > 1) {
        char *search_sku = argv[1];
        int found = 0;
        int ct = 0;
        
        // Search for the item using while loop with short-circuit evaluation
        while (ct < 5 && strcmp(item_list[ct].sku, search_sku) != 0) {
            ct++;
        }
        
        if (ct < 5) {
            // Item found
            printf("###############\n");
            printf("item name = %s\n", item_list[ct].name);
            printf("item sku = %s\n", item_list[ct].sku);
            printf("item category = %s\n", item_list[ct].category);
            printf("item price = %.6f\n", item_list[ct].price);
            printf("###############\n");
        } else {
            printf("item not found\n");
        }
    }
    
    // Free all allocated memory
    free_items(item_list, 5);
    free(item_list);
    
    return 0;
}

// Function to add an item to the array
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    // Allocate memory for each string field
    item_list[index].sku = (char *)malloc((strlen(sku) + 1) * sizeof(char));
    item_list[index].name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    item_list[index].category = (char *)malloc((strlen(category) + 1) * sizeof(char));
    
    // Copy the strings
    strcpy(item_list[index].sku, sku);
    strcpy(item_list[index].name, name);
    strcpy(item_list[index].category, category);
    
    // Set the price
    item_list[index].price = price;
}

// Function to free all allocated memory for items
void free_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
}

// Function to calculate the average price of all items
double average_price(Item *item_list, int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += item_list[i].price;
    }
    return total / size;
}

// Function to print all items
void print_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %.6f\n", item_list[i].price);
    }
}
