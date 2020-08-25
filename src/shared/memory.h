/**
 * @file memory.h
 * @author Levi Bland
 * @date Aug 26 2020
 * declare memory functions
 */

#ifndef __TERRENCE_MEMORY_H__
#define __TERRENCE_MEMORY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TERRENCE_MEMORY_DEBUG 0

#ifndef TERRENCE_VM_DEFINED
#define TERRENCE_VM_DEFINED
typedef struct terrence_vm terrence_vm;
#endif

#if TERRENCE_MEMORY_DEBUG
#define mem_init()                      memdebug_init()
#define mem_stat()                      memdebug_stat()
#define mem_alloc(_vm,_size)            memdebug_malloc0(_vm,_size)
#define mem_calloc(_vm,_count,_size)    memdebug_calloc(_vm,_count,_size)
#define mem_realloc(_vm,_ptr,_size)     memdebug_realloc(_vm,_ptr,_size)
#define mem_free(v)                     memdebug_free((void *)v)
#define mem_check(v)                    memdebug_setcheck(v)
#define mem_status                      memdebug_status
#define mem_leaks()                     memdebug_leaks()
#define mem_remove                      memdebug_remove
#else
#define mem_init()
#define mem_stat()
#define mem_alloc(_vm,_size)            terrence_calloc(_vm, 1, _size)
#define mem_calloc(_vm,_count,_size)    terrence_calloc(_vm, _count, _size)
#define mem_realloc(_vm,_ptr,_size)     terrence_realloc(_vm, _ptr, _size)
#define mem_free(v)                     free((void *)v)
#define mem_check(v)
#define mem_status()                    0
#define mem_leaks()                     0
#define mem_remove(_v)
#endif

#if TERRENCE_MEMORY_DEBUG
void    memdebug_init (void);
void    *memdebug_malloc (terrence_vm *vm, size_t size);
void    *memdebug_malloc0 (terrence_vm *vm, size_t size);
void    *memdebug_calloc (terrence_vm *vm, size_t num, size_t size);
void    *memdebug_realloc (terrence_vm *vm, void *ptr, size_t new_size);
void    memdebug_free (void *ptr);
size_t  memdebug_leaks (void);
size_t  memdebug_status (void);
void    memdebug_setcheck (bool flag);
void    memdebug_stat (void);
bool    memdebug_remove (void *ptr);
#else
void    *terrence_calloc (terrence_vm *vm, size_t count, size_t size);
void    *terrence_realloc (terrence_vm *vm, void *ptr, size_t new_size);
#endif

#endif