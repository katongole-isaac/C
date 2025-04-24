# C PROGRAMMING [ Dennis Ritchie ]

> **Functions** > **_Args - Call by Value:_** In C, all function args are passed **by value**. This mean that the called function is given the values of its args in temporary variables rather than origiinals. Whatever is done to the `arg` inside a function has no effect on the argument that function was originally called with.

> **External Variables and Scope:**
> External Variables remain in existence and retain their values ever when functions that have set them are exited. External variables are defined outside any function at the top of the source file. But a function has to declare it when it wants to use it. using `extern` keyword. For example `extern int max`

## Overview

### Symbolic Constants

It's a bad pratice to bury magic numbers in a program because they convey little information to someone who might read the program later. So a `#define` line defines a symbolic constant to be a particular string of char(s). Notice there is no semicolon at the end of the line.

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

| Type     | Description                                | Size (bytes)             |
| -------- | ------------------------------------------ | ------------------------ |
| `char`   | stores one char in the local character set | 1 (8bits)                |
| `int`    | Nature size of integers on host machine    | 2 (16bits) or 4 (32bits) |
| `float`  | Single-precision floating point            |
| `double` | Double-precision floating point            |

**Integer qualifiers**

> The intent is that `short` and `long` should provide different lengths of integers where practical.

| `short` | often 16bits            |
| ------- | ----------------------- |
| `int`   | **either 16 or 32bits** |
| `long`  | **atleast 32bits**      |

**`unsigned` and `signed` qualifiers**

> The `unsigned` in computing refers to a data type that can hold only non-negative integers.  
> The `signed` indicates a variable the hold both negative and positive values.  
> The property can be apply to numeric data types including `int` `short` `long` `char`.

These qualifiers can be applied to both `int` and `char`. `unsigned` numbers are always positive or zero and obey the arithmetic modulo `2`<sup>`n`</sup> - where `n` is the number of bits in the type.  
Forexample if `char` are 8 bits:-

- `Unsigned char` variables have values between 0 and 255.
- `signed char` variables have values between -128 to 127 (2's complement machine.)

> NB: Printable character are always positive.  
>  The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all these sizes, along with other properties of the machine and compiler.

### Constants

An integer constant e.g `1234` is an `int` . A `long` constant is written with `l` or `L` for example `12345678L` .  
Unsigned constants are written with a terminal `u` or `U` and suffix `ul` or `UL` means `unsigned long`.

Floating-point constants contain decimal point (1.2) or an exponent (1e-2) or both. A leading `0` (zero) on an integer means octal and a leading `0x` or `0X` means hexadecimal Forexample

```c
    To represent 31 in octal is 037 and in hexadecimal 0x1f or 0x1F
```

> Octal or hexadecimal may also be followed by `L` to make them `long` and `U` to make them `unsigned` forexample `0xFUL` is an unsigned long constant with value 15 decimal

A _character constant_ is an integer, written as a character within single quotes e.g `'0'`. The value of the character constant is the numeric value of that character in the machine's character set. e.g in ASCII character set, the character constant `'0'` is `48` which is unrelated to a numeric value `0`  
If we write `'0'` instead of a numeric value like `48` that depends on the character set, the program is independent of a given value and easy to read.

Certain characters can be represented in character and string constants by escape sequences e.g `\n` (newline). These sequences look like two characters but represnt only one. forexample

```c
    '\000'  // where 000 is one to three octal digits (0..7)
    '\xhh'  // where one or more hex digits
```

The character constant `'0'` represents the character with value zero, the null character. `'\0'` is often written instead of `0` to emphasize the character nature of some expression, but the numeric value is just `0`.

A string constant is a sequence of zero or more characters surrounded by double-quote e.g `"this is a string"` or `"" // empty string`

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

The qualifer `const` can be applied to the declaration of any variable to specify that its value will not be changed. For an array, the `const` qualifier says that the elements will not be altered

```c
    const int marks[] = {21,31,3}; // immutable
    marks[0] = 2 // throws
```

The `const` declaration can be used with array augments, to indicate that the function does not change that array;

```c
    int strlen(const str[]);
```

### Type Conversions

When an operator has operands of different types, they are converted to a common type according to a small number of rules.

- Only automatic conversions are those that convert a narrower operand into a wider one without losing information. e.g converting integer to floating-point in an expression `f+i`
- Expressions that might lose information e.g assigning a longer integer type to a shorter, or float to int may draw a warning but they are not illegal.

A `char` is just a small integer so `char`s may be freely used in arithmetic expressions.

The standard header `<ctype.h>` defines the family of functions that provide tests and conversions that are indpendent of any character set.

> The definition of C guarantees that any character in the machine's standard printing character set will never be negative, so these char(s) will always be positive quantities in expression.

Finally, the explicit type conversions can be forced (coerced) in any expression, with a unary operator called `cast`

```c
    (type name) expression
```

In the construction, the expression is converted to the named type by the conversion rules above. The precise meaning of the cast is as if the expression were assigned to a variable of the specified type, which is then used in place of the whole construction.

### Increment and decrement operators

- The expression `++n` increments `n` before it's value is used while `n++` increments `n` after it's value has been used.

```c
 int n  = 5;
 x = n++; // x = 5, and the increment offers after reading the value of n
 x = ++n; // x = 6 , increment is done then the value is used.
```

### Bitwise Operators

The bitwise `AND` operator `&` is often used to mask off some set of bits e.g

```c
n = n & 0177; // sets to zero all but the low-order 7 bits of n
```

The bitwise `OR` operator `|` is used to turn bits on

```c
 x = x | SET_ON ; // sets to one in x the bits are set to one in SET_ON
```

The bitwise exclusive `OR` operator `^` sets a one in each bit position where it's operands have different bits, and zero where they are the same.

The shift operators `<< `and `>>` perform left and right shifts of their left operand by the number of bit positions given by the right operand, which must be non-negative. Thus `x << 2` shifts the value of `x` by two positions, filling vacated bits with zero; this is equivalent to multiplication by 4. Right shifting an `unsigned` quantity always fits the vacated bits with zero. Right shifting a `signed` quantity will fill with bit signs (``arithmetic shift'') on some machines and with 0-bits (logical shift'') on others.

The unary operator `~` yields the one's complement of an integer; i.e it converts each `1-bit` into `0-bit` and vice versa. For example

```c
x = x & ~077
```

The unary operator `~`yields the one's complement of an integer; that is, it converts each `1-bit` into a `0-bit` and vice versa. For example

```c
x = x & ~077
```

sets the last six bits of `x` to zero. Note that `x & ~077` is independent of word length, and is thus preferable to, for example,` x & 0177700` , which assumes that x is a 16-bit quantity. The portable form involves no extra cost, since `~077` is a constant expression that can be evaluated at compile iime.

## Control Flow

### `Switch` Statement

The switch statement is a multi-way decision that tests whether an expression matches one of a number of constant integer values, and branches accordingly.

```c
switch(expr) {
    case const-expr: statments;
    case const-expr: statments;
    case const-expr: case: const-expr: statements;
    default: statements;
}
```

### Goto and labels

C provides the infinitely-abusable `goto` statement, and labels to branch to. Formally, the `goto` statement is never necessary, and in practice it is almost always easy to write code without it.  
A label has the same form as a variable name, and is followed by a colon. It can be attached to
any statement in the same function as the `goto` . The scope of a label is the entire function.

```c

int guess = 5;

if(your_guess == guess) goto found;

found:
    printf("We found the guess bro !");

```
