
extern "C" {
struct ht_item
{
    char *key;
    char *value;
    ht_item *next;
};

struct hash_table
{
    int size;
    ht_item **items;
};

hash_table *init_ht();
void del_hash_table(hash_table *ht);
void insert_ht_item(hash_table *ht, const char *k, const char *v);
void delete_ht_item(hash_table *ht, const char *key);
char *search_ht_item(hash_table *ht, const char *k);
void print_ht(hash_table *ht);

}