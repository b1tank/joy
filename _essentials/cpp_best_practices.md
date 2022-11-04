# C++ best practices

## Reference: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es23-prefer-the--initializer-syntax

## Best practices & heads-up
1. Always initialize types.
2. ```const``` is required for accessor member functions of classes; so think about ```const``` at the beginning in case you need to add it to every single member function later. 
3. Passing by **Reference** for function parameters can be used to return more than one value in a function; often used for objects to avoid bulky copies.