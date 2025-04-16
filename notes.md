# C PROGRAMMING [ Dennis Ritchie ]

> **Functions** > **_Args - Call by Value:_** In C, all function args are passed **by value**. This mean that the called function is given the values of its args in temporary variables rather than origiinals. Whatever is done to the `arg` inside a function has no effect on the argument that function was originally called with.

> **External Variables and Scope:**
> External Variables remain in existence and retain their values ever when functions that have set them are exited. External variables are defined outside any function at the top of the source file. But a function has to declare it when it wants to use it. using `extern` keyword.  For example `extern int max`

## Overview  
### Symbolic Constants  
It's a bad pratice to bury magic numbers in a program because they convey little information to someone who might read the program later. So a `#define` line defines a symbolic constant to be a particular string of char(s).  Notice there is no semicolon at the end of the line.

```c
    #define GRAVITY 9.8
    #define PI 2.17
    #define SOME_WORD some_values
```

### Character input and output  
`getchar()` reads the next input character from a text stream and returns that as it's value. Characters normally orginate from keyborad, input from files.  
```c
    c = getchar();
```
`putchar` function prints the content of the integer variable `c` as a character, usually on a screen. 

A character written between single quotes represents an integer value equal to the numerical value of a character in the machine's character set. This is called a **character constant**. E.g 'A' is a character constant in the ASCII character set and it's value is 65 (internal representation of character 'A')  

> Definition - refers to a place where the variable is created and assigned storage.  
> Declaration - refers to places where the nature the variable is stated but no storage is assigned.  

### Functions 

## Chapter 2 - Types, Operators and Expressions

### Data Types and Sizes

| Type | Description | Size (bytes) |
|------|--------------|-----|
| `char` | stores one char in the local character set | 1 (8bits)
| `int`  | Nature size of integers on host machine    | 2 (16bits) or 4 (32bits)
|  `float` | Single-precision floating point          | 
|   `double` | Double-precision floating point        |

**Integer qualifiers**
> The intent is that `short` and `long` should provide different lengths of integers where practical.

| `short` | often 16bits |  
|-------- |--------------|
| `int`   | __either 16 or 32bits__ |
| `long`  | __atleast 32bits__ |

__`unsigned` and `signed` qualifiers__   
> The `unsigned` in computing refers to a data type that can hold only non-negative integers.  
> The `signed` indicates a variable the hold both negative and positive values.  
> The property can be apply to numeric data types including `int` `short` `long` `char`.

These qualifiers can be applied to both `int` and `char`. `unsigned` numbers are always positive or zero and obey the arithmetic modulo `2`<sup>`n`</sup> - where `n` is the number of bits in the type.  
Forexample if `char` are 8 bits:-  
 - `Unsigned char` variables have values between 0 and 255.
 - `signed char` variables have values between -128 to 127 (2's complement machine.) 

 >NB: Printable character are always positive.  
 The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all these sizes, along with other properties of the machine and compiler. 
 
### Constants  
An integer constant e.g `1234` is an `int` . A `long` constant is written with `l` or `L` for example `12345678L` .  
Unsigned constants are written with a terminal `u` or `U` and suffix `ul` or `UL` means `unsigned long`.  

Floating-point constants contain decimal point (1.2) or an exponent (1e-2) or both. A leading `0` (zero) on an integer means octal and a leading `0x` or `0X` means hexadecimal  Forexample 

```c
    To represent 31 in octal is 037 and in hexadecimal 0x1f or 0x1F
```

> Octal or hexadecimal may also be followed by `L` to make them `long` and `U` to make them `unsigned` forexample `0xFUL` is an unsigned long constant with value 15 decimal  

A *character constant* is an integer, written as a character within single quotes e.g `'0'`. The value of the character constant is the numeric value of that character in the machine's character set. e.g in ASCII character set, the character constant `'0'` is `48` which is unrelated to a numeric value `0`  
If we write `'0'` instead of a numeric value like `48` that depends on the character set, the program is independent of a given value and easy to read.  

Certain characters can be represented in character and string constants by escape sequences e.g `\n` (newline). These sequences look like two characters but represnt only one. forexample
```c
    '\000'  // where 000 is one to three octal digits (0..7)
    '\xhh'  // where one or more hex digits
```

The character constant `'0'` represents the character with value zero, the null character. `'\0'` is often written instead of `0` to emphasize the character nature of some expression, but the numeric value is just `0`.  

A string constant is a sequence of zero or more characters surrounded by double-quote e.g `"this is a string"`  or `"" // empty string`  

String constants can be concatenated at compile time: 
```c
    "this is" "a string" // this is a string
```

### Declarations  
Declarations specifies a type, and contains a list of one or more variables of that type. e.g 
```c
    int age;
    int i,j,c;
    int pi = 3.14 // declaration and initilization 
```
> **NOTE:** External and static variables are initialized to zero by default. Automatic variables for which is no explicit initializer have `undefined` (garbage) values. 