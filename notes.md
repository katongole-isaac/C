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

### Control Flow

#### `Switch` Statement

The switch statement is a multi-way decision that tests whether an expression matches one of a number of constant integer values, and branches accordingly.

```c
switch(expr) {
    case const-expr: statments;
    case const-expr: statments;
    case const-expr: case: const-expr: statements;
    default: statements;
}
```

#### Goto and labels

C provides the infinitely-abusable `goto` statement, and labels to branch to. Formally, the `goto` statement is never necessary, and in practice it is almost always easy to write code without it.  
A label has the same form as a variable name, and is followed by a colon. It can be attached to
any statement in the same function as the `goto` . The scope of a label is the entire function.

```c

int guess = 5;

if(your_guess == guess) goto found;

found:
    printf("We found the guess bro !");

```

Code that relies on `goto` statements is generally harder to understand and to maintain than code without `goto`s

## Chapter 4 - Functions and Program Structure

Each function definition has the following form

```c
return-type function-name(argument declarations){
    declarations and statements;
}

// e.g int func(int x) {}
```

A minimal function is which does nothing and returns nothing. e.g `dummy() {}`. A do-nothing function like such is sometimes useful as a placeholder during program dev't. If return-type is omitted `int` is assumed.

### External Variables

External variables are defined outside of any function, and are thus potentionally available to many functions. Functions themselves are always external **because C does not allow fun(s) to be defined inside other functions.**

By default, external variables and functions have the property that all references to them by the same name, even from functions compiled separately, are references to the same thing. (The standard calls this property **external linkage** .)

#### Scope Rules

The functions and external variables that make up a C program need not all be compiled at the same time; the source text of the program may be kept in several files, and previously compiled routines may be loaded from libraries. Among the questions of interest are

- How are declarations written so that variables are properly declared during compilation?
- How are declarations arranged so that all the pieces will be properly connected when the program is loaded?
- How are declarations organized so there is only one copy?
  How are external variables initialized?

The scope of a name is the part of the program within which the name can be used. For an automatic variable declared at the beginning of a function, the scope is the function in which the name is declared. Local variables of the same name in different functions are unrelated. The same is true of the parameters of the function, which are in effect local variables.

The scope of an external variable or a function lasts from the point at which it is declared to the end of the file being compiled. For example, if `main , sp , val , push , and pop` are defined in one file, in the order shown above

```c
main() { ... }

int sp = 0;
double val[MAXVAL];

void push(double f) { ... }
double pop(void) { ... }
```

then the variables sp and val may be used in push and pop simply by naming them; no further declarations are needed. But these names are not visible in `main , nor are push and pop` themselves.

If an external variable is to be referred to before it is defined, or if it is defined in a different source file from the one where it is being used, then an extern declaration is mandatory.

It is important to distinguish between the declaration of an external variable and its definition . A declaration announces the properties of a variable _(primarily its type)_; a definition also
causes storage to be set aside.

```c
int sp;
double val[MAXVAL];
```

If the above lines appear outside of any function, they define the external variables `sp` and` val` , cause storage to be set aside, and also serve as the declarations for the rest of that source file.

```c
extern int sp;
extern double val[];
```

The lines declare for the rest of the source file that `sp` is an `int` and that `val` is a `double` array (whose size is determined elsewhere), but they do not create the variables or reserve storage for them.

There must be only one definition of an external variable among all the files that make up the source program; other files may contain `extern` declarations to access it. (There may also be `extern` declarations in the file containing the definition.) Array sizes must be specified with the definition, but are optional with an `extern` declaration.

> Initialization of an external variable goes only with the definition.

#### Header Files

A header file in C is a file with the extension `.h` that contains C declarations and macro definitions to be shared between several source files. It allows the sharing of common code among multiple source files, promoting modularity and reuse. Header files typically contain function prototypes, structure and union definitions, type definitions, and macro definitions

```c
// calc.h
#define PI 3.14
void velocity(void);
void acceleration(void);
```

```c
// main.c
#include <stdio.h> // system header files
#include "calc.h"; // user-defined header files
main(){...}
```

#### Static variables

The `static` declaration applied to an external variable or function, limits the scope of that object to the rest of the source file being compiled. External `static` thus provides a way to hide names like `buf` and `bufp` in the `getch-ungetch` combination, which must be external so they can be shared, yet which should not be visible to users of `getch` and `ungetch` functions.  
Static storage is specified by prefixing the normal declaration with the word `static`.

```c
static int external ;
static void print(void){...};
```

**NOTE** Normally function names are global, visible to any part of the entire program, so when a function is declared `static`, however it's name is **invisible** outside of the file in which it's declared.

The `static` declaration can also be applied to internal variables. Internal `static` variables are local to a particular function just as automatic variables are, but unlike automatics, they remain in existence rather than coming and going each time the function is activated. This means that internal `static` variables provide private, permanent storage within a single
function.

#### Register Variables

A `register` declaration advises the compiler that the variable in question will be heavily used. The idea is that `register` variables are to be placed in machine registers, which may result in smaller and faster programs. But compilers are free to ignore the advice.

```c
register int x;
register int y;
```

**NOTE:** The `register` declaration can only be applied to automatic variables and to the formal parameters of a function.

```c
f(register unsigned int m, register long n){...}
```

In practice, there are restrictions on `register` variables, reflecting the realities of underlying hardware. Only a few variables in each function may be kept in registers, and only certain types are allowed. Excess register declarations are harmless, however, since the word `register` is ignored for excess or disallowed declarations. And it is not possible to take the
address of a `register` variable, regardless of whether the variable
is actually placed in a register. The specific restrictions on number and types of `register` variables vary from machine to machine.

#### Initialization

In the absence of explicit initialization, _external_ and `static` variables are guaranteed to be initialized to `zero`; _automatic_ and `register` variables have undefined (i.e., garbage) initial values.

For _external_ and `static` variables, the initializer must be a constant expression; the initialization is done once, conceptionally before the program begins execution. For _automatic_ and `register` variables, the initializer is not restricted to being a constant: it may be any expression involving previously defined values, even function call.

### The C Preprocessor

C provides certain language facilities by means of a preprocessor, which is conceptionally a separate first step in compilation.

The two most frequently used features are:-

- `#include ` - to include the contents of a file during compilation.
- `#define` - to replace a token by an arbitrary sequence of characters.

Other features described in this section include conditional compilation and macros with arguments.

#### File Inclusion

File inclusion makes it easy to handle collections of `#define`s and declarations (among other things)

```c
#include "some-file";
#include <some-std-lib>
```

Any source line of the above form is replaced by the contents of the file filename . If the filename is quoted, searching for the file typically begins where the source program was found; if it is not found there, or if the name is enclosed in `<`and `>`, searching follows an implementation-defined rule to find the file. An included file may itself contain `#include` lines.

#### Macro Substitution

```c
#define name replacement_text
```

The above calls for a macro substitution of the simplest kind - subsequent occurrences of the token `name` will be replaced by the `replacement_text`. The scope of a `name` defined with `#define` is from its point of definition to the end of the source file being compiled. A definition may use previous definitions.

It is also possible to define macros with arguments, so the replacement text can be different for different calls of the macro.

```c
// macro with arguments
#define max(a,b) ((A) > (B) ? (A) : (B))
```

Although it looks like a function call, a use of max expands into in-line code. Each occurrence
of a formal parameter (here A or B ) will be replaced by the corresponding actual argument. Thus the line

```c
x = max(p+q, r+s);
```

will be replaced by the line

```c
x = ((p+q) > (r+s) ? (p+q) : (r+s));
```

Nonetheless, macros are valuable. One practical example comes from `<stdio.h>` , in which `getchar` and `putchar` are often defined as macros to avoid the run-time overhead of a function call per character processed. The functions in `<ctype.h>` are also usually implemented as macros.

The `#undef` preprocessor directive in C is used to remove a macro definition. It effectively "undefines" a name that was previously defined using` #define`. The basic syntax is:

```c
#undef identifier
```

`identifier` is the name of the macro to be undefined. If the identifier is not currently defined as a macro,` #undef` has no effect. After using `#undef`, subsequent occurrences of the identifier are treated as if they were never defined.

```c
#define PI 3.14159
#define AREA(r) (PI * r * r)

int main() {

    float radius = 5.0;
    float area = AREA(radius);
    printf("Area: %f\n", area);

    #undef PI
    #undef AREA

    // The following line would cause a compilation error because PI is no longer defined
    // float new_area = AREA(radius);

    return 0;
}
```

Formal parameters are not replaced within quoted strings. If, however, a parameter name is preceded by a `#` in the replacement text, the combination will be expanded into a quoted string with the parameter replaced by the actual argument. This can be combined with string concatenation to make, for example

```c
#define dprint(expr) printf(#expr " = %g\n", expr)
```

When this is invoked, as in `dprint(x/y)`, the macro is expanded into

```c
printf("x/y" " = &g\n", x/y);
```

and the strings are concantenated, so the effect is

```c
printf("x/y = &g\n", x/y);
```

The preprocessor operator `##` provides a way to concatenate actual arguments during macro expansion. If a parameter in the replacement text is adjacent to a `##` , the parameter is replaced by the actual argument, the `##` and surrounding white space are removed, and the result is re-scanned.

```c
#define paste(front, back)  front ## back
paste(name, 1); // create a token "name1"
```

#### Conditional Inclusion

It is possible to control preprocessing itself with conditional statements that are evaluated during preprocessing. This provides a way to include code selectively, depending on the value of conditions evaluated during compilation.

The `#if` line evaluates a constant integer expression (which may not include `sizeof` , casts, or `enum` constants). If the expression is non-zero, subsequent lines until an `#endif` or `#elif` or
`#else` are included. (The preprocessor statement` #elif` is like `else-if` .) The expression `defined( name )` in a `#if` is `1` if the name has been defined, and `0` otherwise.

```c
#if !defined(HDR)
#define HDR
/* contents of hdr.h go here */
#endif
```

This sequence tests the name `SYSTEM` to decide which version of a header to include:

```c
#if SYSTEM == SYSV
    #define HDR "sysv.h"
    #elif SYSTEM == BSD
    #define HDR "bsd.h"
    #elif SYSTEM == MSDOS
    #define HDR "msdos.h"
    #else
    #define HDR "default.h"
#endif

#include HDR
```

The `#ifdef` and` #ifndef` lines are specialized forms that test whether a name is defined. The first example of #if above could have been written

```c
#ifndef HDR
#define HDR
/* contents of hdr.h go here */
#endif
```

### Chapter 5 Pointers and Array

A pointer is a variable that contains(stores) the address of another variable. A pointer is a group of cells (often two or four) that can hold an address. So if `c` is a `char` and `p` is a pointer that points to it, we could represent the situation this way:

```c
int *p;
char c = 'A';

p = &c;
```

The unary operator `&` gives the address of an object. The `&` operator only
applies to objects in memory: variables and array elements. It cannot be applied to expressions, constants, or `register` variables.

The unary operator `*` is the indirection or dereferencing operator; when applied to a pointer, it accesses the object the pointer points to.

```c
int x = 10;
int *p;

p = &x;

printf("Value: %d\n", *p); // *p gives 10

*p = 11; // now x is 11
```

**NOTE:** You should also note the implication that a pointer is constrained to point to a particular kind of object: every pointer points to a specific data type. (There is one exception: _a pointer to void_ is used to hold any type of pointer but cannot be dereferenced itself)

The unary operators `*` and `&` bind more tightly than arithmetic operators, so the assignment takes whatever `ip` points at, adds `1`, and assigns the result to `y`

```c

y = *ip + 1;

*ip += 1; // increments what ip points to by 1
++*ip;
(*ip)++; // The parentheses are necessary in this last example;
// without them, the expression would increment ip instead of
// what it points to, because unary operators like * and ++ associate right to left.
```

Finally, since pointers are variables, they can be used without dereferencing. For example, if `iq` is another pointer to `int`, copies the contents of `ip` into `iq` , thus making `iq` point to whatever `ip` pointed to.

```c
iq = ip;
```

#### Pointers and Function Arguments

Since C passes arguments to functions by value, there is no direct way for the called function to alter a variable in the calling function. Forexample the following function can't affect the arguents `a` and `b` in the routine that called it. Instead the function swaps copies of `a` and `b`.

```c
void swap(a,b){...}
```

The way to obtain the desired effect is for the calling program to pass pointers to the values to be changed

```c
void swap(int *pa, int *pb){...}
swap(&a, &b);
```

#### Pointers and Arrays

In C, there is a strong relationship between pointers and arrays, strong enough that pointers and arrays should be discussed simultaneously. Any operation that can be achieved by array subscripting can also be done with pointers. The pointer version will in general be faster but, at least to the uninitiated, somewhat harder to understand.

The declaration below defines an array of size 10, that is, a block of 10 consecutive objects and `arr[0]...arr[9]`

```c
int arr[10];

int *p;

p = &arr[0]; // pointer p points to the first array element.

x = *p; // derefence the object pointed by pointer p and store it in x
```

From the above code, pointer `p` points to the first array element and by definition, `p+1` points to the next element and `p-1` or `p-i` points to an element before. Thus if `p` points to `arr[0]` then `*(p+i)` points to `arr[i]`

```c
int arr[0] = {8,5,6,2,4,1};
int *p;

P = arr; // same as p = &arr[0];

*(p+1) // same as arr[1] --> 5
*(p+2) // same as arr[2] --> 6
```

These remarks are true regardless of the type or size of the variables in the array `arr` . The meaning of adding `1` to a pointer, and by extension, all pointer arithmetic, is that `p+1` points to the next object, and `p+i` points to the `i-th` object beyond `p`.  *Inside the complier it's expanded into the following*
```c
Addr[i] = address of the first element + ( sizeof(data_type) * offset )
Addr[i] = 100 + (sizeof(int) * i);

Forexample
For i = 1;
addr[1] = 100 + (sizeof(int) * 1 );
        = 100 + (4*1); 
        = 104; // arr[1] ---> 5
```

**NOTE** *An array name is a synonym for the location of the  initial element*

Rather more surprising, at first sight, is the fact that a reference to `arr[i]` can also be written as `*(arr+i)` . In evaluating `a[i]` , C converts it to `*(arr+i)` immediately; the two forms are equivalent. Applying the operator & to both parts of this equivalence, it follows that `&arr[i]`
and `arr+i` are also identical:` arr+i` is the address of the `i-th` element beyond `arr` . As the other side of this coin, if `p` is a pointer, expressions might use it with a subscript; `p[i]` is identical to `*(p+i)` . In short, an array-and-index expression is equivalent to one written as a pointer and offset.

There is one difference between an array name and a pointer that must be kept in mind. A pointer is a variable, so `p=arr` and `p++` are legal. But an array name is not a variable; constructions like `arr=p` and `arr++` are illegal.

When an array name is passed to a function, what is passed is the location of the initial element. Within the called function, this argument is a local variable, and so an array name parameter is a pointer, that is, a variable containing an address. We could write another version of `strlen` like

```c
int strlen(char *s){
    int n ;

    for(n= 0; *s != '\0'; s++) n++;

    return n;
}

strlen("hello, world"); /* string constant */
strlen(array); /* char array[100]; */
strlen(ptr);  /* char *ptr; */
```
Since `s` is a pointer, incrementing it is perfectly legal; `s++` has no effect on the character string in the function that called `strlen` , but merely increments `strlen` 's private copy of the pointer  

It is possible to pass part of an array to a function, by passing a pointer to the beginning of the subarray. For example, if `arr` is an array,
```c
f(&arr[2]){...}
// or
f(arr+2){...}
```

If one is sure that the elements exist, it is also possible to index backwards in an array; `p[-1]`, `p[-2]` , and so on are syntactically legal, and refer to the elements that immediately precede `p[0]` . Of course, it is illegal to refer to objects that are not within the array bounds.  

#### Pointer or Address Arithmetic  

The valid pointer operations are assignment of pointers of the same type, adding or subtracting a pointer and an integer, subtracting or comparing two pointers to members of the same array, and assigning or comparing to zero. All other pointer arithmetic is illegal. It is not legal to add two pointers, or to multiply or divide or shift or mask them, or to add float or double to them, or even, except for `void *` , to assign a pointer of one type to a pointer of another type without a cast.

*see [storage-allocator](/c/introduction/storage-allocator.c)*  

#### Character Pointers and Functions  

*see [character-pointer](/c/introduction/character-pointer.c)*  

A string constant , written as 
```c
"I am a string"
```
is an array of characters. In the internal representation, the array is terminated with the null character `'\0'` so that programs can find the end. The length in storage is thus one more than the number of characters between the double quotes.  

Perhaps the most common occurrence of string constants is as arguments to functions, as in

```c
printf("hello, world\n");
```

When a character string like this appears in a program, access to it is through a character pointer; `printf` receives a pointer to the beginning of the character array. That is, a string constant is accessed by a pointer to its first element.  

String constants need not be function arguments. If pmessage is declared as
```c
char *pmessage;
```
then the statement
```c
pmessage = "now is the time";
```
assigns to pmessage a pointer to the character array. This is not a string copy; only pointers are involved. C does not provide any operators for processing an entire string of characters as a unit.  

There is an important difference between these definitions: 

```c
char amessage[] = "now is the time"; /* an array */
char *pmessage = "now is the time"; /* a pointer */
```

`amessage` is an array, just big enough to hold the sequence of characters and `'\0'` that initializes it. Individual characters within the array may be changed but amessage will alwaysrefer to the same storage.  

On the other hand, `pmessage` is a pointer, initialized to point to a string constant; the pointer may subsequently be modified to point elsewhere, but the result is undefined if you try to modify the string contents.