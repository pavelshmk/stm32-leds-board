//
// Created by bakatrouble on 20/10/22.
//

#include "font.h"

uint8_t font[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9
        0x3, 0x2, 0x3, 0x3, 0x3, 0x2, 0x2,  // 0xa
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x10
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x11
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x12
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x13
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x14
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x15
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x16
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x17
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x18
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x19
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1a
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1b
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1c
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1d
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1e
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x1f
        0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x20
        0x2, 0x1, 0x1, 0x1, 0x0, 0x1, 0x0,  // 0x21
        0x4, 0x5, 0x5, 0x0, 0x0, 0x0, 0x0,  // 0x22
        0x6, 0xa, 0x1f, 0xa, 0x1f, 0xa, 0x0,  // 0x23
        0x4, 0x2, 0x7, 0x3, 0x4, 0x7, 0x2,  // 0x24
        0x4, 0x1, 0x4, 0x2, 0x1, 0x4, 0x0,  // 0x25
        0x5, 0x2, 0x5, 0x2, 0x5, 0xa, 0x0,  // 0x26
        0x2, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0,  // 0x27
        0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x2,  // 0x28
        0x3, 0x1, 0x2, 0x2, 0x2, 0x2, 0x1,  // 0x29
        0x4, 0x5, 0x2, 0x7, 0x2, 0x5, 0x0,  // 0x2a
        0x4, 0x0, 0x2, 0x7, 0x2, 0x0, 0x0,  // 0x2b
        0x3, 0x0, 0x0, 0x0, 0x0, 0x2, 0x1,  // 0x2c
        0x3, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0,  // 0x2d
        0x2, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0,  // 0x2e
        0x4, 0x4, 0x4, 0x2, 0x1, 0x1, 0x0,  // 0x2f
        0x4, 0x2, 0x5, 0x7, 0x5, 0x2, 0x0,  // 0x30
        0x3, 0x2, 0x3, 0x2, 0x2, 0x3, 0x0,  // 0x31
        0x4, 0x2, 0x5, 0x4, 0x2, 0x7, 0x0,  // 0x32
        0x4, 0x7, 0x4, 0x2, 0x4, 0x3, 0x0,  // 0x33
        0x4, 0x5, 0x5, 0x7, 0x4, 0x4, 0x0,  // 0x34
        0x4, 0x7, 0x1, 0x3, 0x4, 0x3, 0x0,  // 0x35
        0x4, 0x6, 0x1, 0x3, 0x5, 0x2, 0x0,  // 0x36
        0x4, 0x7, 0x4, 0x2, 0x1, 0x1, 0x0,  // 0x37
        0x4, 0x6, 0x5, 0x2, 0x5, 0x3, 0x0,  // 0x38
        0x4, 0x2, 0x5, 0x6, 0x4, 0x3, 0x0,  // 0x39
        0x2, 0x0, 0x1, 0x0, 0x0, 0x1, 0x0,  // 0x3a
        0x3, 0x0, 0x2, 0x0, 0x0, 0x2, 0x1,  // 0x3b
        0x4, 0x4, 0x2, 0x1, 0x2, 0x4, 0x0,  // 0x3c
        0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x0,  // 0x3d
        0x4, 0x1, 0x2, 0x4, 0x2, 0x1, 0x0,  // 0x3e
        0x4, 0x3, 0x4, 0x2, 0x0, 0x2, 0x0,  // 0x3f
        0x5, 0xe, 0x9, 0xd, 0x1, 0xe, 0x0,  // 0x40
        0x4, 0x2, 0x5, 0x7, 0x5, 0x5, 0x0,  // 0x41
        0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x0,  // 0x42
        0x4, 0x2, 0x5, 0x1, 0x5, 0x2, 0x0,  // 0x43
        0x4, 0x3, 0x5, 0x5, 0x5, 0x3, 0x0,  // 0x44
        0x4, 0x7, 0x1, 0x3, 0x1, 0x7, 0x0,  // 0x45
        0x4, 0x7, 0x1, 0x3, 0x1, 0x1, 0x0,  // 0x46
        0x4, 0x6, 0x1, 0x5, 0x5, 0x6, 0x0,  // 0x47
        0x4, 0x5, 0x5, 0x7, 0x5, 0x5, 0x0,  // 0x48
        0x4, 0x7, 0x2, 0x2, 0x2, 0x7, 0x0,  // 0x49
        0x4, 0x4, 0x4, 0x4, 0x5, 0x2, 0x0,  // 0x4a
        0x4, 0x5, 0x5, 0x3, 0x5, 0x5, 0x0,  // 0x4b
        0x4, 0x1, 0x1, 0x1, 0x1, 0x7, 0x0,  // 0x4c
        0x6, 0x11, 0x1b, 0x15, 0x15, 0x11, 0x0,  // 0x4d
        0x5, 0x9, 0xb, 0xd, 0x9, 0x9, 0x0,  // 0x4e
        0x4, 0x2, 0x5, 0x5, 0x5, 0x2, 0x0,  // 0x4f
        0x4, 0x3, 0x5, 0x3, 0x1, 0x1, 0x0,  // 0x50
        0x4, 0x2, 0x5, 0x5, 0x5, 0x2, 0x4,  // 0x51
        0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x0,  // 0x52
        0x4, 0x6, 0x1, 0x2, 0x4, 0x3, 0x0,  // 0x53
        0x4, 0x7, 0x2, 0x2, 0x2, 0x2, 0x0,  // 0x54
        0x4, 0x5, 0x5, 0x5, 0x5, 0x7, 0x0,  // 0x55
        0x4, 0x5, 0x5, 0x5, 0x7, 0x2, 0x0,  // 0x56
        0x6, 0x11, 0x15, 0x15, 0x1b, 0x11, 0x0,  // 0x57
        0x4, 0x5, 0x5, 0x2, 0x5, 0x5, 0x0,  // 0x58
        0x4, 0x5, 0x5, 0x2, 0x2, 0x2, 0x0,  // 0x59
        0x6, 0x1f, 0x8, 0x4, 0x2, 0x1f, 0x0,  // 0x5a
        0x3, 0x3, 0x1, 0x1, 0x1, 0x3, 0x0,  // 0x5b
        0x4, 0x1, 0x1, 0x2, 0x4, 0x4, 0x0,  // 0x5c
        0x3, 0x3, 0x2, 0x2, 0x2, 0x3, 0x0,  // 0x5d
        0x4, 0x2, 0x5, 0x0, 0x0, 0x0, 0x0,  // 0x5e
        0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,  // 0x5f
        0x3, 0x1, 0x2, 0x0, 0x0, 0x0, 0x0,  // 0x60
        0x4, 0x0, 0x6, 0x5, 0x5, 0x6, 0x0,  // 0x61
        0x4, 0x1, 0x3, 0x5, 0x5, 0x3, 0x0,  // 0x62
        0x4, 0x0, 0x6, 0x1, 0x1, 0x6, 0x0,  // 0x63
        0x4, 0x4, 0x6, 0x5, 0x5, 0x6, 0x0,  // 0x64
        0x4, 0x0, 0x2, 0x5, 0x3, 0x6, 0x0,  // 0x65
        0x4, 0x4, 0x2, 0x7, 0x2, 0x2, 0x0,  // 0x66
        0x4, 0x0, 0x6, 0x5, 0x6, 0x4, 0x3,  // 0x67
        0x4, 0x1, 0x3, 0x5, 0x5, 0x5, 0x0,  // 0x68
        0x2, 0x1, 0x0, 0x1, 0x1, 0x1, 0x0,  // 0x69
        0x3, 0x2, 0x0, 0x2, 0x2, 0x2, 0x1,  // 0x6a
        0x4, 0x1, 0x5, 0x3, 0x5, 0x5, 0x0,  // 0x6b
        0x4, 0x3, 0x2, 0x2, 0x2, 0x7, 0x0,  // 0x6c
        0x6, 0x0, 0xb, 0x15, 0x15, 0x15, 0x0,  // 0x6d
        0x4, 0x0, 0x3, 0x5, 0x5, 0x5, 0x0,  // 0x6e
        0x4, 0x0, 0x2, 0x5, 0x5, 0x2, 0x0,  // 0x6f
        0x4, 0x0, 0x3, 0x5, 0x3, 0x1, 0x1,  // 0x70
        0x4, 0x0, 0x6, 0x5, 0x5, 0x6, 0x4,  // 0x71
        0x4, 0x0, 0x5, 0x3, 0x1, 0x1, 0x0,  // 0x72
        0x4, 0x0, 0x6, 0x3, 0x4, 0x3, 0x0,  // 0x73
        0x4, 0x2, 0x7, 0x2, 0x2, 0x4, 0x0,  // 0x74
        0x4, 0x0, 0x5, 0x5, 0x5, 0x6, 0x0,  // 0x75
        0x4, 0x0, 0x5, 0x5, 0x5, 0x2, 0x0,  // 0x76
        0x6, 0x0, 0x11, 0x15, 0x15, 0xa, 0x0,  // 0x77
        0x4, 0x0, 0x5, 0x2, 0x2, 0x5, 0x0,  // 0x78
        0x4, 0x0, 0x5, 0x5, 0x6, 0x4, 0x3,  // 0x79
        0x5, 0x0, 0xf, 0x4, 0x2, 0xf, 0x0,  // 0x7a
        0x4, 0x4, 0x2, 0x3, 0x2, 0x2, 0x4,  // 0x7b
        0x2, 0x1, 0x1, 0x0, 0x1, 0x1, 0x0,  // 0x7c
        0x4, 0x1, 0x2, 0x6, 0x2, 0x2, 0x1,  // 0x7d
        0x5, 0xa, 0x5, 0x0, 0x0, 0x0, 0x0,  // 0x7e
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x7f
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x80
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x81
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x82
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x83
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x84
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x85
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x86
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x87
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x88
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x89
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8a
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8b
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8c
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8d
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8e
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x8f
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x90
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x91
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x92
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x93
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x94
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x95
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x96
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x97
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x98
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x99
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9a
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9b
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9c
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9d
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9e
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0x9f
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xa9
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xaa
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xab
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xac
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xad
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xae
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xaf
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xb9
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xba
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xbb
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xbc
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xbd
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xbe
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xbf
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xc9
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xca
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xcb
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xcc
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xcd
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xce
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xcf
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xd9
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xda
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xdb
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xdc
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xdd
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xde
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xdf
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xe9
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xea
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xeb
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xec
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xed
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xee
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xef
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf0
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf1
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf2
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf3
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf4
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf6
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf7
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf8
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xf9
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xfa
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xfb
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xfc
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xfd
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xfe
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0xff
};

uint8_t RenderChar(uint8_t ch, uint8_t x, uint8_t y, uint8_t fgValue, uint8_t bgValue) {
    uint8_t *chp = font + (ch * 7);
    for (uint8_t xp=0; xp < *chp; xp++) {
        for (uint8_t yp=0; yp < 6; yp++) {
            LedMatrix_SetPixel(x + xp, y + yp, ((*(chp + yp + 1) >> xp) & 0x1) != 0 ? fgValue : bgValue);
        }
    }
}

void RenderStr(const uint8_t *s, uint8_t x, uint8_t y, uint8_t fgValue, uint8_t bgValue) {
    while (*s != 0) {
        uint8_t w = RenderChar(*s, x, y, fgValue, bgValue);
        x += w;
        if (x >= 16) {
            x = 0;
            y += 7;
        }
        s++;
    }
}
