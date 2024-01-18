#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#pragma pack(1)

struct IDTEntry {
    uint16_t offsetLow;
    uint16_t selector;
    uint8_t reserved;
    uint8_t typeAttributes;
    uint16_t offsetHigh;
};

#pragma pack()

#pragma pack(1)

struct IDTDescriptor {
    uint16_t limit;
    uint32_t base;
};

#pragma pack()

void initIDT();

#endif
