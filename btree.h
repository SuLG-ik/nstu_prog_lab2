//
// Created by Володя on 21.03.2024.
//

#ifndef BTREE_H
#define BTREE_H

typedef struct btree {
    int value; // информационная часть
    struct btree *left, *right; // служебная часть
} btree;


void Ins_Btree(int val, btree** q);

int Delete(int key, btree** node);

void DeleteAll(btree** node);

void Print_Btree_ASC(btree* p);

void Print_Btree_DESC(btree* p);

int Size(btree* node);

btree* RandomTree(int size);


#endif //BTREE_H
