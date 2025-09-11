#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    char *value;
    Entry *next;
} Entry;

typedef struct {
    Entry **entries;
} HashTable;

unsigned int hash(const char *key) {
    unsigned int hash_value = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash_value = (hash_value * 31) + key[i];
    }
    return hash_value % TABLE_SIZE;
}

// --- Create a new hash table ---
HashTable *createHashTable() {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL) {
        perror("Failed to allocate memory for hash table");
        return NULL;
    }
    ht->entries = (Entry **)malloc(sizeof(Entry *) * TABLE_SIZE);
    if (ht->entries == NULL) {
        perror("Failed to allocate memory for entries array");
        free(ht); // Clean up!
        return NULL;
    }
    // Initialize all entries to NULL (empty lists)
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->entries[i] = NULL;
    }
    return ht;
}

bool insert(HashTable *ht, const char *key, const char *value) {
    unsigned int index = hash(key);

    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    if (new_entry == NULL) {
        perror("Failed to allocate memory for new entry");
        return false;
    }
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);
    new_entry->next = NULL;

    // Collision Handling (Separate Chaining):
    if (ht->entries[index] == NULL) {
        // No collision, simply insert at the head
        ht->entries[index] = new_entry;
    } else {
        // Collision: Add to the beginning of the linked list at this index
        new_entry->next = ht->entries[index];
        ht->entries[index] = new_entry;
    }
    return true;
}

char *get(HashTable *ht, const char *key) {
    unsigned int index = hash(key);
    Entry *current = ht->entries[index];

    // Traverse the linked list at this index
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Found it!
        }
        current = current->next;
    }
    return NULL; // Key not found
}

// --- Delete a key-value pair ---
bool remove(HashTable* ht, const char* key) {
    unsigned int index = hash(key);
    Entry* current = ht->entries[index];
    Entry* previous = NULL;

    // Traverse the linked list
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Found the entry to delete
            if (previous == NULL) {
                // Deleting the head of the list
                ht->entries[index] = current->next;
            } else {
                // Deleting from the middle or end
                previous->next = current->next;
            }
            free(current->key);   // Free the duplicated key string
            free(current->value); // Free the duplicated value string
            free(current);       // Free the entry itself
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false; // Key not found
}

// --- Free the hash table (important for memory management!) ---
void freeHashTable(HashTable *ht) {
    if (ht == NULL) return;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *current = ht->entries[i];
        while (current != NULL) {
            Entry *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->entries);
    free(ht);
}

int main() {
    HashTable *my_table = createHashTable();

    insert(my_table, "name", "Kenyo");
    insert(my_table, "name", "45"); //Might collide.  Our example handles it.
    insert(my_table, "city", "Goiania");
    //insert(my_table, "ega", "40");  // Intentionally cause a collision with "age"

    printf("Name: %s\n", get(my_table, "name"));
    printf("Age: %s\n", get(my_table, "age"));
    printf("City: %s\n", get(my_table, "city"));
    //printf("ega: %s\n", get(my_table, "ega"));
    printf("Nonexistent: %s\n", get(my_table, "nonexistent")); // Should print (null)

	remove(my_table, "age");
	printf("Age after delete: %s\n", get(my_table, "age"));
	printf("ega after delete: %s\n", get(my_table, "ega"));

    freeHashTable(my_table); // Always clean up!
    return 0;
}