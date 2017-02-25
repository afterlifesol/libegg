# libegg
C++11 tools and data structures

## Tools about types

#### libeggInfo

Compile time information about data types: Minimum, maximum and size.
Covers most basic data types. Useful when testing difference architectures.

## Math tools

#### libeggMath

Math and associated support tools.
Check for overflow before operations for very sensitive data

```C++
    if safeadd(a,b) sum = a+b;
    else handle Overflow();
```

## Containers

#### libeggList

dynamic node based simple LinkedList template

**support**

 - for c++11 range based for
 - array style random access by index
 - Iterator begin and end
 - stack access members
 - c++ exemptions
 
**soon**

- emplace

#### libeggStack

dynamic node based simple stack template

  **support**
  - c++ exemptions

  **soon**
  - for c++11 range based for
  - iterators
  - emplace
  - array basic

## Logging

#### libeggLog

Tools to support logging to file and debugging.

## Testing Support

#### libeggCheck

Tools to help with unit tests and testing in general

#### libeggTest

Calls all tests for libegg

#### TestList
Tests for LinkedList

#### TestStack
Tests for Stack



