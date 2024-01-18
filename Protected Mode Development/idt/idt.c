#include "idt.h"
#include "config.h"
#include "kernel.h"

struct IDTEntry idtDescriptors[CONQUEROS_TOTAL_INTERRUPTS];
struct IDTDescriptor idtDescriptor;

extern void idtLoad(struct IDTDescriptor* ptr);

void idtZero() {
    print("Divide by zero error\n");
}

void idtSet(int interruptNo, void* address) {
    struct IDTEntry* entry = &idtDescriptors[interruptNo];
    entry->offsetLow = (uint32_t)address & 0x0000FFFF;
    entry->selector = KERNEL_CODE_SELECTOR;
    entry->reserved = 0x00;
    entry->typeAttributes = 0xEE;
    entry->offsetHigh = (uint32_t)address >> 16;
}

void initIDT() {
    memset(idtDescriptors, 0, sizeof(idtDescriptors));
    idtDescriptor.limit = sizeof(idtDescriptors) - 1;
    idtDescriptor.base = (uint32_t)idtDescriptors;

    idtSet(0, idtZero);

    // Load the interrupt descriptor table
    idtLoad(&idtDescriptor);
}
