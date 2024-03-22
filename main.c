#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PART 0

#if PART == 1

#include "btree_laptop.h"

Laptop* InputLaptop()
{
    printf("Введите имя производителя (пусто - закончить ввод): ");
    char vendor[VENDOR_NAME_SIZE];
    char cpu[CPU_MODEL_SIZE];
    char hasGpu;
    gets(vendor);
    if (strlen(vendor) == 0) return NULL;
    printf("Введите модель процессора: ");
    gets(cpu);
    printf("Есть ли игровая видеокарта (0 - нет, 1 - да): ");
    gets(&hasGpu);
    return Init(vendor, cpu, hasGpu == '1');
}


btree* InputTree()
{
    btree* tree = NULL;
    printf("Вводите ноутбуки:\n");
    while (1)
    {
        Laptop* laptop = InputLaptop();
        if (laptop == NULL)
            return tree;
        Ins_Btree(laptop, &tree);
    }
}

int main()
{
    btree* tree = InputTree();
    Print_Btree_ASC(tree);
    printf("Введите ноутбук, который хотите удалить:\n");
    Laptop* laptopToDelete = InputLaptop();
    Delete(laptopToDelete, &tree);
    Print_Btree_ASC(tree);
    DeleteAll(&tree);
    free(laptopToDelete);
    return 0;
}

#else

#include "btree.h"

int main()
{
    int size;
    printf("Введите размер дерева: ");
    scanf("%d", &size);
    btree* node = RandomTree(size);
    int countedSize = Size(node);
    if (countedSize == size)
        printf("Все числа отличны\n");
    else
        printf("Сгенерированные числа повторяются\n");
    Print_Btree_ASC(node);
    printf("\nВведите число, которое нужно исключить: ");
    int numToDelete;
    scanf("%d", &numToDelete);
    Delete(numToDelete, &node);
    Print_Btree_ASC(node);
    DeleteAll(&node);
    return 0;
}

#endif
