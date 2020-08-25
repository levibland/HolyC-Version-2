/**
 * @file opcodes.h
 * @author Levi Bland
 * @date Aug 26 2020
 * This file contains the opcode to be used by the Terrence Virtual Machine.
 */

#ifndef __TERRENCE_OPCODES__
#define __TERRENCE_OPCODES__

// All instructions are 32-bits in length
// Opcodes alone are 6-bits

typedef enum
{
    //      *************************************************************************************************
    //      2^6 = 64 possible opcodes because each opcode value is 6-bits in length
    //      56 TOTAL OPCODES FOR THIS VM
    //      *************************************************************************************************
    //
    
    RET0 = 0,    // return nothing from a function

    HALT,       // stop Terrence VM execution
    NOP,        // NOP
    RET,        // return from a function
    CALL,       // call a function

    LOAD,       // Load a value, A, from B, and then store it in C
    LOADS,      // Load a value, A, from B, and then store it in C (super variant)
    LOADAT,     // Load a value, A, from B, and then store it in C
    LOADK,      // Load a constant into register
    LOADG,      // Load global into register
    LOADI,      // Load integer into register
    LOADU,      // Load upvalue into register
    MOV,        // Move registers
    STORE,      // Store a value
    STORAT,     // Store a value
    STOREG,     // Store global
    STOREU,     // Store upvalue

    JUMP,       // Unconditional jump
    JUMPF,      // params: A, B. jump if R(A) is false
    SWITCH,     // Switch statement

    ADD,        // Add operation
    SUB,        // Sub operation
    DIV,        // Div operation
    MUL,        // Mul operation
    REM,        // Rem operation
    AND,        // And operation
    OR,         // Or operation
    LT,         // < comparison
    GT,         // > comparison
    EQ,         // == comparison
    LEQ,        // <= comparison
    GEQ,        // >= comparison
    NEQ,        // != comparison
    EQQ,        // === comparison
    NEQQ,       // !== comparison
    ISA,        // isa comparison
    MATCH,      // =~ pattern match
    NEG,        // neg operation
    NOT,        // not operation

    LSHIFT,     // shift left
    RSHIFT,     // shift right
    BAND,       // bit and
    BOR,        // bit or
    BXOR,       // bit xor
    BNOT,       // bit not

    MAPNEW,     // create a new map
    LISTNEW,    // create a new array
    RANGENEW,   // create a new range
    SETLIST,    // set list/map items

    CLOSURE,    // create a new closure
    CLOSE,      // close all upvalues

    CHECK,      // checkpoint for structs
    RESERVED,   // reserved for future use
    RESERVED2,  // reserved for future use
    RESERVED3,  // reserved for future use
    RESERVED4,  // reserved for future use
    RESERVED5   // reserved for future use
} terrence_opcodes_t;

#define TERRENCE_LATEST_OPCODE RESERVED5    // used in debug

typedef enum
{
    TERRENCE_NOTFOUND_INDEX = 0,
    TERRENCE_ADD_INDEX,
    TERRENCE_SUB_INDEX,
    TERRENCE_DIV_INDEX,
    TERRENCE_MUL_INDEX,
    TERRENCE_REM_INDEX,
    TERRENCE_AND_INDEX,
    TERRENCE_OR_INDEX,
    TERRENCE_CMP_INDEX,
    TERRENCE_EQQ_INDEX,
    TERRENCE_IS_INDEX,
    TERRENCE_MATCH_INDEX,
    TERRENCE_NEG_INDEX,
    TERRENCE_NOT_INDEX,
    TERRENCE_LSHIFT_INDEX,
    TERRENCE_RSHIFT_INDEX,
    TERRENCE_BAND_INDEX,
    TERRENCE_BOR_INDEX,
    TERRENCE_BXOR_INDEX,
    TERRENCE_BNOT_INDEX,
    TERRENCE_LOAD_INDEX,
    TERRENCE_LOADS_INDEX,
    TERRENCE_LOADAT_INDEX,
    TERRENCE_STORE_INDEX,
    TERRENCE_STOREAT_INDEX,
    TERRENCE_INT_INDEX,
    TERRENCE_FLOAT_INDEX,
    TERRENCE_BOOL_INDEX,
    TERRENCE_STRING_INDEX,
    TERRENCE_EXEC_INDEX,
    TERRENCE_VTABLE_SIZE        // MUST BE LAST
} TERRENCE_VTABLE_INDEX;

#define TERRENCE_OPERATOR_ADD_NAME       "+"
#define TERRENCE_OPERATOR_SUB_NAME       "-"
#define TERRENCE_OPERATOR_DIV_NAME       "/"
#define TERRENCE_OPERATOR_MUL_NAME       "*"
#define TERRENCE_OPERATOR_REM_NAME       "%"
#define TERRENCE_OPERATOR_AND_NAME       "&&"
#define TERRENCE_OPERATOR_OR_NAME        "||"
#define TERRENCE_OPERATOR_CMP_NAME       "=="
#define TERRENCE_OPERATOR_EQQ_NAME       "==="
#define TERRENCE_OPERATOR_NEQQ_NAME      "!=="
#define TERRENCE_OPERATOR_IS_NAME        "is"
#define TERRENCE_OPERATOR_MATCH_NAME     "=~"
#define TERRENCE_OPERATOR_NEG_NAME       "neg"
#define TERRENCE_OPERATOR_NOT_NAME        "!"
#define TERRENCE_OPERATOR_LSHIFT_NAME    "<<"
#define TERRENCE_OPERATOR_RSHIFT_NAME    ">>"
#define TERRENCE_OPERATOR_BAND_NAME      "&"
#define TERRENCE_OPERATOR_BOR_NAME       "|"
#define TERRENCE_OPERATOR_BXOR_NAME      "^"
#define TERRENCE_OPERATOR_BNOT_NAME      "~"
#define TERRENCE_INTERNAL_LOAD_NAME      "load"
#define TERRENCE_INTERNAL_LOADS_NAME     "loads"
#define TERRENCE_INTERNAL_STORE_NAME     "store"
#define TERRENCE_INTERNAL_LOADAT_NAME    "loadat"
#define TERRENCE_INTERNAL_STOREAT_NAME   "storeat"
#define TERRENCE_INTERNAL_NOTFOUND_NAME  "notfound"
#define TERRENCE_INTERNAL_EXEC_NAME      "exec"
#define TERRENCE_INTERNAL_LOOP_NAME      "loop"

#define TERRENCE_CLASS_INT_NAME          "Int"
#define TERRENCE_CLASS_FLOAT_NAME        "Float"
#define TERRENCE_CLASS_BOOL_NAME         "Bool"
#define TERRENCE_CLASS_STRING_NAME       "String"
#define TERRENCE_CLASS_OBJECT_NAME       "Object"
#define TERRENCE_CLASS_CLASS_NAME        "Class"
#define TERRENCE_CLASS_NULL_NAME         "Null"
#define TERRENCE_CLASS_FUNCTION_NAME     "Func"
#define TERRENCE_CLASS_FIBER_NAME        "Fiber"
#define TERRENCE_CLASS_INSTANCE_NAME     "Instance"
#define TERRENCE_CLASS_CLOSURE_NAME      "Closure"
#define TERRENCE_CLASS_LIST_NAME         "List"
#define TERRENCE_CLASS_MAP_NAME          "Map"
#define TERRENCE_CLASS_RANGE_NAME        "Range"
#define TERRENCE_CLASS_UPVALUE_NAME      "Upvalue"

#define TERRENCE_CLASS_SYSTEM_NAME       "System"
#define TERRENCE_SYSTEM_PRINT_NAME       "print"
#define TERRENCE_SYSTEM_PUT_NAME         "put"
#define TERRENCE_SYSTEM_NANOTIME_NAME    "nanotime"

#define TERRENCE_TOCLASS_NAME            "toClass"
#define TERRENCE_TOSTRING_NAME           "toString"
#define TERRENCE_TOINT_NAME              "toInt"
#define TERRENCE_TOFLOAT_NAME            "toFloat"
#define TERRENCE_TOBOOL_NAME             "toBool"

#endif