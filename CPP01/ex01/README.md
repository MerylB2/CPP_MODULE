# CPP01 - Ex01: Moar brainz!

## Overview
This exercise demonstrates **array allocation on the heap** using `new[]` and the importance of the **Orthodox Canonical Form** in C++ class design.

## Core Concept
Learn to allocate multiple objects in a single allocation and understand when heap arrays are necessary vs stack allocation.

## Implementation

### Zombie Class (Orthodox Canonical Form)
```cpp
class Zombie {
private:
    std::string name;
    
public:
    Zombie();                               // Default constructor
    Zombie(std::string name);               // Parameterized constructor
    Zombie(const Zombie& other);            // Copy constructor
    Zombie& operator=(const Zombie& other); // Assignment operator
    ~Zombie();                              // Destructor
    
    void announce(void);
    void setName(std::string name);
};
```

### zombieHorde Function
```cpp
Zombie* zombieHorde(int N, std::string name);
```
- Allocates **N zombies in a single allocation** using `new[]`
- Initializes each zombie with the given name + index (`name_0`, `name_1`, etc.)
- Returns pointer to the first zombie
- **Must be freed with `delete[]`** (not `delete`)

## Orthodox Canonical Form

### What is it?
The **Orthodox Canonical Form** requires every class to implement:
1. **Default constructor** - Creates object without parameters
2. **Copy constructor** - Creates new object from existing one
3. **Assignment operator** - Copies into existing object
4. **Destructor** - Cleans up when object is destroyed

### Why is it mandatory?
- **C++98 best practice** for robust class design
- **Prevents undefined behavior** with copying/assignment
- **Required by 42 standards** - Grade 0 if missing
- **Future-proof** - works correctly even if class evolves

### Example Usage
```cpp
Zombie a;                    // Default constructor
Zombie b("Walker");          // Parameterized constructor  
Zombie c(b);                 // Copy constructor
a = b;                       // Assignment operator
// Destructors called automatically
```

## Key Differences: new vs new[]

|    Operation        |         Single Object      |              Array             |
|---------------------|----------------------------|--------------------------------|
| **Allocation**      |        `new Zombie()`      |          `new Zombie[N]`       |
| **Deallocation**    |        `delete zombie`     |        `delete[] zombies`      |
| **Constructor**     | Calls specific constructor | Calls default constructor only |
| **Initialization**  |        At allocation       |   Separate step with setters   |

## Memory Management

```cpp
// Correct usage
Zombie* horde = zombieHorde(5, "Foo");
// ... use zombies ...
delete[] horde;  // IMPORTANT: delete[] not delete!

// Wrong - memory leak
Zombie* horde = zombieHorde(5, "Foo");
// Missing delete[] - MEMORY LEAK!

// Wrong - undefined behavior  
delete horde;  // Should be delete[]
```

## Usage
```bash
make
./Zombie                    # Uses default: 5 zombies named "Foo"
./Zombie Grunt 3           # Creates 3 zombies named "Grunt_0", "Grunt_1", "Grunt_2"
```

## Key Learning Points

1. **Heap arrays** require `new[]` and `delete[]`
2. **Orthodox Canonical Form** is mandatory for all C++ classes
3. **Array allocation** only calls default constructors
4. **Post-initialization** needed with setters for custom names
5. **Memory management** is critical - always match `new[]` with `delete[]`

## Common Pitfalls
- ❌ Using `delete` instead of `delete[]`
- ❌ Forgetting to implement Orthodox Canonical Form
- ❌ Memory leaks from missing `delete[]`
- ❌ Trying to use parameterized constructor with `new[]`

**Rule**: If you allocate with `new[]`, you MUST deallocate with `delete[]`

By Méryl BITEE
