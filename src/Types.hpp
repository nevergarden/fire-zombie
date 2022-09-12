#ifndef FZ_TYPES_H
#define FZ_TYPES_H

#ifdef __cplusplus

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <windef.h>

#ifndef fz_null
#define fz_null NULL
#endif

typedef BOOL fz_bool

#ifndef false
#define false FALSE
#endif

#ifndef true
#define true TRUE
#endif

#ifdef _WIN64
#else
#endif
#elif __APPLE__
#elif __ANDROID__
#elif __linux__
#include <stddef.h>
#include <cstdbool>
#include <cstdint>

#ifdef FZ_CONST
#defie FZ_CONST const
#endif

#ifndef fz_null
#define fz_null NULL
#endif

typedef bool fz_bool;

typedef std::uint8_t  fz_uint8;
typedef std::uint16_t fz_uint16;
typedef std::uint32_t fz_uint32;
typedef std::uint64_t fz_uint64;
typedef std::int8_t   fz_int8;
typedef std::int16_t  fz_int16;
typedef std::int32_t  fz_int32;
typedef std::int64_t  fz_int64;
typedef std::size_t   fz_size;

typedef float fz_float;
typedef double fz_double;

typedef void fz_void;

#else
#error "Unknown Compiler"
#endif // !TYPES

#endif

#endif // !FZ_TYPES_H
