#pragma once

#include "lfk78.h"

// readability
#define XXX KC_NO

// This is a shortcut to help you visually see your layout.
/*
 * ,---------.  ,-----------------------------------------------------------------------.  ,---------.
 * |  0 |  1 |  |  2 |  3 |  4 |  5 |  6 |  7 | 50 | 51 | 52 | 53 | 54 | 55 | 56 |   57 |  | 94 | 95 |
 * |---------|  |-----------------------------------------------------------------------|  |---------|
 * | 10 | 11 |  | 12  | 13 | 14 | 15 | 16 | 17 | 60 | 61 | 62 | 63 | 64 | 65 | 66 |  67 |  | 96 | 97 |
 * |---------|  |-----------------------------------------------------------------------|  `---------'
 * | 20 | 21 |  | 22    | 23 | 24 | 25 | 26 | 27 | 70 | 71 | 72 | 73 | 74 | 75 |     76 |
 * |---------|  |-----------------------------------------------------------------------|  ,----.
 * | 30 | 31 |  | 32      | 33 | 34 | 35 | 36 | 37 | 80 | 81 | 82 | 83 | 84 |        85 |  | 86 |
 * |---------|  |-------------------------------------------------------------------------------------.
 * | 40 | 41 |  | 42  | 43  | 44 |               45                |  46 |  47 |  90 | | 91 | 92 | 93 |
 * `---------'  `--------------------------------------------------------------------' `--------------'
 */
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define LAYOUT( \
    k00, k01,   k02, k03, k04, k05, k06, k07, k50, k51, k52, k53, k54, k55, k56, k57,   k94, k95, \
    k10, k11,   k12, k13, k14, k15, k16, k17, k60, k61, k62, k63, k64, k65, k66, k67,   k96, k97, \
    k20, k21,   k22, k23, k24, k25, k26, k27, k70, k71, k72, k73, k74, k75,      k76, \
    k30, k31,   k32,  k33, k34, k35, k36, k37, k80, k81, k82, k83, k84,          k85,   k86, \
    k40, k41,   k42, k43, k44,              k45,                  k46, k47, k90,   k91, k92, k93 \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, k17 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, k31, k32, k33, k34, k35, k36, k37 }, \
    { k40, k41, k42, k43, k44, k45, k46, k47 }, \
    { k50, k51, k52, k53, k54, k55, k56, k57 }, \
    { k60, k61, k62, k63, k64, k65, k66, k67 }, \
    { k70, k71, k72, k73, k74, k75, k76, XXX }, \
    { k80, k81, k82, k83, k84, k85, k86, XXX }, \
    { k90, k91, k92, k93, k94, k95, k96, k97 }  \
}