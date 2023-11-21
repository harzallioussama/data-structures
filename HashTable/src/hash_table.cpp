#include "hash_table.h"
#include "string.h"
// #include <stdio.h>
#include <cmath>
#include <iostream>

extern "C" {
int prime1 = 131;


static ht_item *create_ht_item(const char *k, const char *v)
{
    ht_item *item = new ht_item();
    item->key = strdup(k);
    item->value = strdup(v);
    item->next = NULL;
    return item;
}

hash_table *init_ht()
{
    hash_table *ht = new hash_table();
    ht->size = 53;
    ht->items = new ht_item *[ht->size];
    return ht;
}

static void del_ht_item(ht_item *it)
{
    delete it->key;
    delete it->value;
    delete it;
}

void del_hash_table(hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *it = ht->items[i];
        if (it != NULL)
        {
            del_ht_item(it);
        }
    }
    delete[] ht->items;
    delete ht;
}

// hash function :

static int ht_hash(const char *s, const int a, const int m)
{
    long long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        hash += (long long)pow(a, len_s - (i + 1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

// methods :

// head

void insert_ht_item(hash_table *ht, const char *k, const char *v)
{
    ht_item *item = create_ht_item(k, v);
    int index = ht_hash(k, prime1, ht->size);
    if (ht->items[index] == NULL)
    {
        ht->items[index] = item;
    }
    else
    {
        ht_item *cur_item = ht->items[index];
        ht->items[index] = item;
        item->next = cur_item;
    }
}

void delete_ht_item(hash_table *ht, const char *key)
{
    // two cases  :
    //      element exists
    //      doesn't not
    int index = ht_hash(key, prime1, ht->size);
    // target does not exists
    if (ht->items[index] == NULL)
        return;

    ht_item *item = ht->items[index];
    if (strcmp(item->key, key) == 0)
    {
        ht->items[index] = item->next;

        del_ht_item(item);
        return;
    }
    ht_item *prev = ht->items[index];

    while (item->next != NULL && strcmp(item->key, key) != 0)
    {
        prev = item;
        item = item->next;
    }
    prev->next = item->next;

    if (strcmp(item->key, key) == 0)
        del_ht_item(item);
}

char *search_ht_item(hash_table *ht, const char *k)
{
    int index = ht_hash(k, prime1, ht->size);
    // if(ht->items[index] == NULL) return NULL ;
    ht_item *item = ht->items[index];
    while (item != NULL)
    {
        if (strcmp(item->key, k) == 0)
        {
            return item->value;
        }
        item = item->next;
    }
    char *errprMsg = new char[15];
    strcpy(errprMsg, "No data found.");
    return errprMsg;
}

void print_ht(hash_table *ht)
{
    for (int i = 0; i < ht->size; ++i)
    {
        if (ht->items[i] != NULL)
        {
            std::cout << "index   :" << i << "    :"
                      << "\n";
            ht_item *cur_item = ht->items[i];
            while (cur_item != NULL)
            {
                std::cout << "\t key : " << cur_item->key << "          value  :" << cur_item->value << "\n";
                cur_item = cur_item->next;
            }
            std::cout << std::endl;
        }
    }
}
}