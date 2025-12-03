#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>

void symbol_table_init(symbol_table *table) {
    table->size = 0;
    table->capacity = 8;
    table->entries = malloc(sizeof(symbol_entry) * table->capacity);
}

void symbol_table_set(symbol_table *table, const char *name, double value) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            table->entries[i].value = value;
            return;
        }
    }

    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->entries = realloc(table->entries, sizeof(symbol_entry) * table->capacity);
    }

    table->entries[table->size].name = strdup(name);
    table->entries[table->size].value = value;
    table->size++;
}

double symbol_table_get(symbol_table *table, const char *name, int *found) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            *found = 1;
            return table->entries[i].value;
        }
    }
    *found = 0;
    return 0;
}

void symbol_table_free(symbol_table *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->entries[i].name);
    }
    free(table->entries);
}

