#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct {
    char *name;
    double value;
} symbol_entry;

typedef struct {
    symbol_entry *entries;
    int size;
    int capacity;
} symbol_table;

void symbol_table_init(symbol_table *table);
void symbol_table_set(symbol_table *table, const char *name, double value);
double symbol_table_get(symbol_table *table, const char *name, int *found);
void symbol_table_free(symbol_table *table);

#endif

