//
// Created by Володя on 27.02.2024.
//

#ifndef LAPTOP_H
#define LAPTOP_H

#define VENDOR_NAME_SIZE 20
#define CPU_MODEL_SIZE 20
#define LAPTOP_VALID 1
#define LAPTOP_INVALID_VENDOR_EMPTY 0
#define LAPTOP_INVALID_CPU_EMPTY -1
#define LAPTOP_INVALID_HAS_GAME -2

typedef struct Laptop {
    char vendorName[VENDOR_NAME_SIZE];
    char cpuModel[CPU_MODEL_SIZE];
    int hasGameGPU;
} Laptop;

Laptop* Init(char vendorName[VENDOR_NAME_SIZE], char cpuModel[CPU_MODEL_SIZE], int hasGameGPU);

int Equals(Laptop laptop, Laptop other);

int LessThan(Laptop laptop, Laptop other);

void print_laptop(Laptop laptop);

#endif //LAPTOP_H
