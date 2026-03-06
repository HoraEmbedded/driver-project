# Abstract Device Driver — C++ Embedded Systems Project

A C++ implementation of an abstract device driver architecture, inspired by real-world Hardware Abstraction Layers (HAL) used in embedded systems frameworks like STM32Cube and Zephyr RTOS.

---

## What This Project Does

Defines a common abstract interface (`DeviceDriver`) that enforces a contract on all hardware drivers. Concrete drivers (`UARTDriver`, `TemperatureSensor`) inherit from this base class and implement device-specific behavior — demonstrating clean, scalable embedded software architecture.

---

## Concepts Covered

| Concept | Description |
|---|---|
| **Classes & Objects** | Blueprint and instance relationship |
| **Encapsulation** | Private data protected via public methods |
| **Constructor & Initializer List** | Safe object initialization at creation |
| **Inheritance** | Child classes extend parent behavior |
| **`protected` access** | Attributes shared with child classes only |
| **`virtual` methods** | Runtime method dispatch via pointer |
| **Pure virtual functions** | `= 0` forces child implementation |
| **Abstract class** | Cannot be instantiated — contract only |
| **Polymorphism** | One interface, many behaviors |
| **`override` keyword** | Compile-time override verification |
| **Virtual destructor** | Safe memory cleanup through base pointer |
| **`dynamic_cast`** | Safe runtime downcasting with nullptr check |
| **`const` methods** | Read-only methods that never modify state |
| **`const` reference params** | Efficient parameter passing without copying |
| **Header / Source split** | Professional multi-file project structure |
| **Include guards** | Prevents duplicate header inclusion |

---

## Project Structure

```
driver-project/
│
├── DeviceDriver.h          ← Abstract base class declaration
├── DeviceDriver.cpp        ← Base class implementation
│
├── UARTDriver.h            ← UART driver declaration
├── UARTDriver.cpp          ← UART driver implementation
│
├── TemperatureSensor.h     ← Temperature sensor declaration
├── TemperatureSensor.cpp   ← Temperature sensor implementation
│
└── mainDD.cpp              ← Entry point — polymorphic driver usage
```

---

## Architecture

```
         DeviceDriver          (abstract)
         ────────────
         deviceName
         is_initialized
         initialize()
         shutdown()
         displayStatus()
         read()   = 0          ← contract
         write()  = 0          ← contract
              │
              ├────────────────────────────┐
              ▼                            ▼
         UARTDriver                TemperatureSensor
         ──────────                ─────────────────
         baudRate                  currentTemperature
         initialize() override     unit
         read()       override     read()       override
         write()      override     write()      override
         displayStatus() override  displayStatus() override
```

---

## Compile & Run

```bash
g++ mainDD.cpp DeviceDriver.cpp UARTDriver.cpp TemperatureSensor.cpp -o driver.exe
.\driver.exe
```

---

## Sample Output

```
Initializing device: UART1
Setting baud rate to: 9600
Device: UART1, Status: Initialized
Baud Rate: 9600
Writing data to UART device: UART1, Data: Hello, UART!
Reading data from UART device: UART1
---
Initializing device: TempSensor1
Device: TempSensor1, Status: Initialized
Temperature sensor does not support writing data.
Reading temperature: 25.5 Celsius
---
Destroying device driver: UART1
Destroying device driver: TempSensor1
```

---

## Author

**HoraEmbedded** — Electronics & Automation Systems Engineering Student  
Embedded Systems | C++ | Hardware Abstraction | Driver Architecture