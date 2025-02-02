
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       u8;
typedef signed   char       s8;

typedef unsigned short      u16;
typedef signed   short      s16;

typedef unsigned long       u32;
typedef signed   long       s32;

typedef unsigned long long  u64;
typedef signed   long long  s64;

typedef float               f32;
typedef double              f64;
typedef long double         f80;

typedef void (*ptr2fun_Iv_Ov)(void);

#define NULL	((volatile void*) 0LL)

#endif
