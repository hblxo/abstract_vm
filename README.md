# abstract_vm

C++ simple virtual machine interpreting basic assembly language.

## Description

42 school project using c++ to make a virtual machine that can interpret basic assembly language et perform operations between operands.

See file `abstract-vm.en.pdf` for full project instructions

## Install && Launch

`make && ./avm`

Then you can write instructions.

### Instructions :

| Instructions | Description |
| ----------- | --------------- |
| push _v_ |  Pushes the value _v_ at the top of the stack. The _value_ must have one of the following form: <ul><li>int8(n) : Creates an 8-bit integer with value n.</li><li>int16(n) : Creates a 16-bit integer with value n.</li><li>int32(n) : Creates a 32-bit integer with value n.</li><li>float(z) : Creates a float with value z.</li><li>double(z) : Creates a double with value z.</li></ul>|
| pop | Unstacks the value from the top of the stack. If the stack is empty, the program execution must stop with an error |
| dump | Displays each value of the stack.  |
| assert _v_ | Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction. |
| add |Unstacks the first two values on the stack, adds them together and stacks the result.  |
| sub | ... subtracts them, then stacks the result.|
| mul |... multiplies them, then stacks the result. |
|div|... divides them, then stacks the result. |
|mod|... calculates the modulus, then stacks the result. |
| max | ... return the greater value.|
| min | ... return the smaller value.|
| pow | ... |
| sin | ... |
| cos | ... |
| tan | ... |
| sqrt | ... |
| and | ... |
| xor | ...|
| or | ...|
|print| Asserts that the value at the top of the stack is an 8-bit integer. |
| exit |Terminate the execution of the current program. |


## Notes

Abstract-vm is a school project. Please note that this is my *first* project in C++.
Some improvements are possible, such as :

+ color & verbose mode
+ execution of instructions in live
+ some minor corrections in operations
+ exception handling improvement
+ better options handling
+ etc.
