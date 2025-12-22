# CPP01 - Ex03: Unnecessary violence

## Overview
This exercise demonstrates **when to use references vs pointers** through a practical example of weapon management in combat classes.

## Core Concept
Learn the **design decision** between references and pointers based on object lifetime and relationship requirements.

## Implementation Analysis

### Weapon Class
```cpp
class Weapon {
private:
    std::string type;
public:
    const std::string& getType() const; // Returns const reference - no copy
    void setType(const std::string& type); // Avoids copy with const reference
};
```

### HumanA vs HumanB Design

| Aspect | HumanA (Reference) | HumanB (Pointer) |
|--------|-------------------|------------------|
| **Weapon Storage** | `Weapon& weapon` | `Weapon* weapon` |
| **Constructor** | Takes weapon | No weapon initially |
| **Always Armed** | ✅ Yes | ❌ No |
| **Can Change Weapon** | ❌ No | ✅ Yes (setWeapon) |
| **Null Check Needed** | ❌ No | ✅ Yes |
| **Memory Safety** | Higher | Lower |

## Key Design Decisions

### Why HumanA Uses Reference?
```cpp
class HumanA {
private:
    Weapon& weapon; // Reference = always valid, cannot change
public:
    HumanA(const std::string& name, Weapon& weapon); // Must provide weapon
    void attack() const; // No null check needed!
};
```

**Advantages:**
- **Guaranteed validity** - cannot be null
- **Immutable association** - weapon cannot change after construction
- **Performance** - no indirection cost
- **Safety** - no null pointer dereference risk

**Use Case:** Professional warrior who always carries their signature weapon

### Why HumanB Uses Pointer?
```cpp
class HumanB {
private:
    Weapon* weapon; // Pointer = can be null, can change
public:
    HumanB(const std::string& name); // No weapon required
    void setWeapon(Weapon& weapon); // Can set weapon later
    void attack() const; // Must check if weapon exists
};
```

**Advantages:**
- **Optional weapon** - can start unarmed
- **Flexibility** - can change weapons
- **Late binding** - weapon assigned after creation

**Use Case:** Civilian who might pick up a weapon during combat

## Memory Management Analysis

### No Memory Leaks Here!
```cpp
{
    Weapon club("crude spiked club"); // Stack allocation
    HumanA bob("Bob", club);          // Reference to stack object
    // club destroyed automatically when scope ends
}

{
    Weapon club("crude spiked club"); // Stack allocation  
    HumanB jim("Jim");                // Pointer initially null
    jim.setWeapon(club);             // Points to stack object
    // club destroyed automatically when scope ends
}
```

**Why No Leaks:**
- All `Weapon` objects created on **stack** (automatic storage)
- No `new`/`delete` used
- References and pointers point to **existing objects**
- Automatic cleanup when scope ends

### When Memory Leaks WOULD Occur
```cpp
// BAD EXAMPLE - DON'T DO THIS
HumanB* jim = new HumanB("Jim");        // Dynamic allocation
Weapon* club = new Weapon("club");      // Dynamic allocation
jim->setWeapon(*club);
// Missing: delete jim; delete club;     // MEMORY LEAK!
```

## Real-World Design Patterns

### Use References When:
1. **Mandatory relationship** - object always needs the reference
2. **Immutable association** - relationship never changes
3. **Performance critical** - no indirection overhead
4. **Function parameters** - avoid copies

### Use Pointers When:
1. **Optional relationship** - object might not exist
2. **Mutable association** - can change what you point to
3. **Dynamic allocation** - objects created with `new`
4. **Polymorphism** - pointing to derived classes

## Example Output
```bash
$ ./violence
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club  
Jim attacks with their some other type of club
```

## Attack Implementation Comparison
```cpp
// HumanA - No null check needed
void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

// HumanB - Must check for null weapon
void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}
```

## Key Takeaways

1. **References = Mandatory, Immutable relationships**
2. **Pointers = Optional, Mutable relationships**
3. **Stack allocation** prevents memory leaks
4. **Design drives implementation** - not the other way around
5. **Safety vs Flexibility** trade-off

## Memory Leak Prevention Rules

- ✅ Use stack allocation when possible
- ✅ Match every `new` with `delete`
- ✅ Use references for permanent relationships
- ✅ Use smart pointers (C++11+) for dynamic allocation
- ❌ Don't mix stack objects with dynamic pointers

## Usage
```bash
make
./violence
```

**Remember**: Choose references for **guaranteed relationships**, pointers for **optional flexibility**!

By Méryl BITEE