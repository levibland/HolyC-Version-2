/**
 * @file terrence_delegate.h
 * @author Levi Bland
 * @date Aug 26 2020
 */

#ifndef __terrence_DELEGATE__
#define __terrence_DELEGATE__

#include <stdint.h>
#include "terrence_value.h"

// error type and code definitions
typedef enum {
    terrence_ERROR_NONE = 0,
    terrence_ERROR_SYNTAX,
    terrence_ERROR_SEMANTIC,
    terrence_ERROR_RUNTIME,
    terrence_ERROR_IO,
    terrence_WARNING,
} error_type_t;

typedef struct {
    uint32_t        lineno;
    uint32_t        colno;
    uint32_t        fileid;
    uint32_t        offset;
} error_desc_t;

#define ERROR_DESC_NONE     (error_desc_t){0,0,0,0}

typedef void                (*terrence_log_callback)    (terrence_vm *vm, const char *message, void *xdata);
typedef void                (*terrence_log_clear) (terrence_vm *vm, void *xdata);
typedef void                (*terrence_error_callback) (terrence_vm *vm, error_type_t error_type, const char *description, error_desc_t error_desc, void *xdata);
typedef void                (*terrence_unittest_callback) (terrence_vm *vm, error_type_t error_type, const char *desc, const char *note, terrence_value_t value, int32_t row, int32_t col, void *xdata);
typedef void                (*terrence_parser_callback) (void *token, void *xdata);
typedef void                (*terrence_type_callback) (void *token, const char *type, void *xdata);
typedef const char*         (*terrence_precode_callback) (void *xdata);
typedef const char*			(*terrence_loadfile_callback) (const char *file, size_t *size, uint32_t *fileid, void *xdata, bool *is_static);
typedef const char*         (*terrence_filename_callback) (uint32_t fileid, void *xdata);
typedef const char**        (*terrence_optclass_callback) (void *xdata);

typedef bool                (*terrence_bridge_initinstance) (terrence_vm *vm, void *xdata, terrence_value_t ctx, terrence_instance_t *instance, terrence_value_t args[], int16_t nargs);
typedef bool                (*terrence_bridge_setvalue) (terrence_vm *vm, void *xdata, terrence_value_t target, const char *key, terrence_value_t value);
typedef bool                (*terrence_bridge_getvalue) (terrence_vm *vm, void *xdata, terrence_value_t target, const char *key, uint32_t vindex);
typedef bool                (*terrence_bridge_setundef) (terrence_vm *vm, void *xdata, terrence_value_t target, const char *key, terrence_value_t value);
typedef bool                (*terrence_bridge_getundef) (terrence_vm *vm, void *xdata, terrence_value_t target, const char *key, uint32_t vindex);
typedef bool                (*terrence_bridge_execute)  (terrence_vm *vm, void *xdata, terrence_value_t ctx, terrence_value_t args[], int16_t nargs, uint32_t vindex);
typedef bool                (*terrence_bridge_equals) (terrence_vm *vm, void *obj1, void *obj2);
typedef const char*         (*terrence_bridge_string) (terrence_vm *vm, void *xdata, uint32_t *len);
typedef void*               (*terrence_bridge_clone)  (terrence_vm *vm, void *xdata);
typedef uint32_t            (*terrence_bridge_size) (terrence_vm *vm, terrence_object_t *obj);
typedef void                (*terrence_bridge_free) (terrence_vm *vm, terrence_object_t *obj);
typedef void                (*terrence_bridge_blacken) (terrence_vm *vm, void *xdata);

typedef struct {
    // user data
    void                        *xdata;                 // optional user data transparently passed between callbacks
    bool                        report_null_errors;     // by default messages sent to null objects are silently ignored (if this flag is false)
    bool                        disable_gccheck_1;      // memory allocations are protected so it could be useful to automatically check gc when enabled is restored
    
    // callbacks
    terrence_log_callback        log_callback;           // log reporting callback
    terrence_log_clear           log_clear;              // log reset callback
    terrence_error_callback      error_callback;         // error reporting callback
    terrence_unittest_callback   unittest_callback;      // special unit test callback
    terrence_parser_callback     parser_callback;        // lexer callback used for syntax highlight
    terrence_type_callback       type_callback;          // callback used to bind a token with a declared type
    terrence_precode_callback    precode_callback;       // called at parse time in order to give the opportunity to add custom source code
    terrence_loadfile_callback   loadfile_callback;      // callback to give the opportunity to load a file from an import statement
    terrence_filename_callback   filename_callback;      // called while reporting an error in order to be able to convert a fileid to a real filename
    terrence_optclass_callback   optional_classes;       // optional classes to be exposed to the semantic checker as extern (to be later registered)

    // bridge
    terrence_bridge_initinstance bridge_initinstance;    // init class
    terrence_bridge_setvalue     bridge_setvalue;        // setter
    terrence_bridge_getvalue     bridge_getvalue;        // getter
    terrence_bridge_setundef     bridge_setundef;        // setter not found
    terrence_bridge_getundef     bridge_getundef;        // getter not found
    terrence_bridge_execute      bridge_execute;         // execute a method/function
    terrence_bridge_blacken      bridge_blacken;         // blacken obj to be GC friend
    terrence_bridge_string       bridge_string;          // instance string conversion
    terrence_bridge_equals       bridge_equals;          // check if two objects are equals
    terrence_bridge_clone        bridge_clone;           // clone
    terrence_bridge_size         bridge_size;            // size of obj
    terrence_bridge_free         bridge_free;            // free obj
} terrence_delegate_t;

#endif