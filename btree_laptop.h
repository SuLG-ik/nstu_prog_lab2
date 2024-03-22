//
// Created by Володя on 21.03.2024.
//

#ifndef BTREE_H
#define BTREE_H

#include "Laptop.h"

typedef struct btree {
    Laptop* value; // информационная часть
    struct btree *left, *right; // служебная часть
} btree;


void Ins_Btree(Laptop* val, btree** q);

int Delete(Laptop* key, btree** node);

void DeleteAll(btree** node);

void Print_Btree_ASC(btree* p);

void Print_Btree_DESC(btree* p);

int Size(btree* node);

#endif //BTREE_H
