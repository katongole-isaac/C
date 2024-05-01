# C PROGRAMMING [ Dennis Ritchie ]

> **Functions** > **_Args - Call by Value:_** In C, all function args are passed **by value**. This mean that the called function is given the values of its args in temporary variables rather than origiinals. Whatever is done to the `arg` inside a function has no effect on the argument that function was originally called with.

> **External Variables and Scope:**
> External Variables remain in existence and retain their values ever when functions that have set them are exited. External variables are defined outside any function at the top of the source file. But a function has to declare it when it wants to use it. using `extern` keyword.
