//
// Created by Володя on 27.02.2024.
//

#include "Laptop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Laptop* Init(char vendorName[VENDOR_NAME_SIZE], char cpuModel[CPU_MODEL_SIZE], int hasGameGPU)
{
    Laptop* laptop = malloc(sizeof(Laptop));
    strncpy(laptop->vendorName, vendorName, VENDOR_NAME_SIZE);
    strncpy(laptop->cpuModel, cpuModel, CPU_MODEL_SIZE);
    laptop->hasGameGPU = hasGameGPU;
    return laptop;
}

int Equals(Laptop laptop, Laptop other)
{
    return strcmp(laptop.vendorName, other.vendorName) == 0
           && strcmp(laptop.cpuModel, other.cpuModel) == 0
           && laptop.hasGameGPU == other.hasGameGPU;
}

int LessThan(Laptop laptop, Laptop other)
{
    return strlen(laptop.cpuModel) < strlen(other.cpuModel) ||
           strlen(laptop.vendorName) < strlen(other.vendorName) ||
           !laptop.hasGameGPU && other.hasGameGPU;
}

void print_laptop(Laptop laptop)
{
    printf("___________________\n");
    printf("Info about laptop:\n");
    printf("Vendor name: %s\n", laptop.vendorName);
    printf("Process model: %s\n", laptop.cpuModel);
    printf("Has game GPU: ");
    if (laptop.hasGameGPU)
        printf("true");
    else
        printf("false");
    printf("\n___________________\n");
}
