#include "../src/hash_table.h"
#include <iostream>

int main()
{
    hash_table* ht = init_ht() ;
    insert_ht_item(ht , "4" , "values4") ;
    insert_ht_item(ht , "31" , "values31") ;
    insert_ht_item(ht , "54" , "values54") ;
    char* c = search_ht_item(ht , "4") ;
    std::cout<<c<<std::endl;
    print_ht(ht);
    del_hash_table(ht) ;

}