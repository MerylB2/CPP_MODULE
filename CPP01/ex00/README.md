# CPP01 - Ex00: BraiiiiiiinnnzzzZ

## Overview
This exercise demonstrates the fundamental difference between **stack allocation** and **heap allocation** in C++ through a simple Zombie class implementation.

## Core Concept
The main goal is to understand when to allocate objects on the stack versus the heap, and the trade-offs involved.

## Implementation

### Zombie Class
- **Private attribute**: `std::string name`
- **Methods**:
  - `Zombie(std::string name)`: Constructor
  - `~Zombie()`: Destructor (prints destruction message)
  - `void announce()`: Prints `<name>: BraiiiiiiinnnzzzZ...`

### Two Allocation Strategies

#### 1. Heap Allocation (`newZombie`)
```cpp
Zombie* newZombie(std::string name);
```
- Allocates zombie on the **heap** using `new`
- Returns a pointer to the zombie
- **Must** be manually freed with `delete`
- Object persists beyond function scope

#### 2. Stack Allocation (`randomChump`)
```cpp
void randomChump(std::string name);
```
- Creates zombie on the **stack**
- Zombie announces itself immediately
- **Automatically** destroyed when function ends
- No manual memory management needed

## Key Differences

|        Aspect         | Stack (`randomChump`)|      Heap (`newZombie`)    |
|-----------------------|----------------------|----------------------------|
| **Memory Management** |     Automatic        | Manual (`delete` required) |
| **Performance**       |      Faster          |          Slower            |
| **Lifetime**          | Function scope only  |  Until explicitly deleted  |
| **Safety**            |     Memory-safe      |    Risk of memory leaks    |
| **Use Case**          | Temporary objects    |     Persistent objects     |

## Conclusion

**For this exercise context**: Stack allocation (`randomChump`) is preferable because:
- The zombie only needs to announce once
- No long-term persistence required
- Automatic cleanup prevents memory leaks
- Simpler and safer code

**Use heap allocation when**:
- Object needs to outlive its creation function
- Sharing objects across multiple functions
- Object size is very large
- Lifetime is determined at runtime

## Usage
```bash
make
./zombie [name]    # Uses provided name or none ("Foo" as default)
```

**Rule of thumb**: Use stack allocation by default, heap only when necessary.

## By : Méryl BITEE