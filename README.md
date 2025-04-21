# Password Key Project (ATmega32)

## Overview

This is an embedded “password key” security system built around an ATmega32 microcontroller. Users enter a 5‑digit code on a 4×4 matrix keypad; the code is compared to a stored password, and access is granted or denied via LEDs, buzzer, servo lock, and LCD feedback. Additional features include a temperature sensor (LM35) reading and UART reporting.

---

## Table of Contents

1. [Features](#features)  
2. [Hardware Requirements](#hardware-requirements)  
3. [Software Requirements](#software-requirements)  
4. [Directory Structure](#directory-structure)  
   - [MCAL](#mcal)  
   - [HAL](#hal)  
   - [LIB](#lib)  
   - [APP](#app)  
5. [Build & Flash Instructions](#build--flash-instructions)  
6. [Simulation](#simulation)  
7. [Authors](#authors)  
8. [License](#license)  

---

## Features

- **Secure password entry** via 4×4 keypad (5‑digit code)  
- **LCD prompts** and feedback (16×2 character LCD)  
- **Access indicators**: LEDs & buzzer  
- **Servo driven lock**  
- **Temperature monitoring** with LM35, reported over UART  
- **Modular HAL/M­CAL layers** for easy reuse  

---

## Hardware Requirements

- **Microcontroller**: ATmega32 (8 MHz internal oscillator)  
- **Input**: 4×4 Matrix Keypad  
- **Display**: HD44780‑compatible 16×2 LCD  
- **Outputs**: LEDs, Buzzer, Servo Motor  
- **Sensor**: LM35 Temperature Sensor  
- **UART**: Serial port for PC communication  
- **Power**: 5 V regulated supply  

---

## Software Requirements

- **Toolchain**: AVR‑GCC, AVR‑DUDE (or Atmel Studio 7)  
- **Simulator**: Proteus (optional)  
- **Programmer**: USBasp or similar ISP  

---

## Directory Structure

```
GccApplication1/
├─ APP/             # Application layer
│   ├─ main.c  
│   ├─ program.c  
│   └─ program.h  
├─ HAL/             # Hardware Abstraction Layer
│   ├─ Button.c/.h       – Push‑button interface  
│   ├─ Buzzer.c/.h       – Piezo‑buzzer control  
│   ├─ Keypad.c/.h       – 4×4 keypad scanning  
│   ├─ LCD.c/.h          – Character LCD driver  
│   ├─ LED.c/.h          – LED on/off control  
│   ├─ LM35.c/.h         – Temperature sensor driver  
│   └─ SERVO.c/.h        – Servo motor (PWM) control  
├─ MCAL/            # Microcontroller Abstraction Layer
│   ├─ DIO.c/.h           – GPIO direction & data  
│   ├─ adc.c/.h           – ADC driver  
│   ├─ EXTI.c/.h          – Edge‑triggered external interrupts  
│   ├─ EXT_INTERRUPT.c/.h – Global interrupt enable/disable  
│   ├─ TIMER0_*.c/.h      – Timer0 config & functions  
│   ├─ Timer1_*.c/.h      – Timer1 config & PWM  
│   └─ UART_*.c/.h        – USART init & transmit/receive  
├─ LIB/            # Common utilities
│   ├─ BitMath.h          – Bit‑manipulation macros  
│   ├─ STD_types.h        – Fixed‑width type definitions  
│   └─ LCD_types.h        – LCD-specific constants & types  
├─ Debug/          # Build outputs & auto‐generated files
│   ├─ Makefile  
│   ├─ GccApplication1.hex/.elf/.map  
│   └─ MCAL/, HAL/, APP/ object files  
└─ Proteus/        # (Optional) Simulation project  
    └─ Milestone simulation.pdsprj  
```

### MCAL

Low‐level drivers interfacing directly with ATmega32 registers:

- **DIO.c/.h**  
  Configure and manipulate GPIO pins (set direction, write, read).  

- **adc.c/.h**  
  Initialize and read from the 10‑bit ADC (prescaler, channel selection).  

- **EXTI.c/.h** & **EXT_INTERRUPT.c/.h**  
  Configure external interrupt lines and global interrupt control.  

- **TIMER0_*.c/.h** & **Timer1_*.c/.h**  
  Set up Timer0/1 for normal, CTC, and Fast PWM modes (used for delay, PWM servo, buzzer tone).  

- **UART_*.c/.h**  
  Initialize baud rate, frame format, send/receive data over serial port.  

### HAL

Mid‐level drivers abstracting specific peripherals:

- **Button.c/.h**  
  Debounced button initialization & read.  

- **Buzzer.c/.h**  
  Generate tones using Timer/PWM.  

- **Keypad.c/.h**  
  Scan 4×4 matrix keypad; set a flag when a key is pressed.  

- **LCD.c/.h**  
  4‑bit or 8‑bit interfacing, send commands/data, move cursor, display strings.  

- **LED.c/.h**  
  Turn status LEDs on/off.  

- **LM35.c/.h**  
  Read temperature in °C via ADC and convert.  

- **SERVO.c/.h**  
  Control servo angle via PWM duty cycle.  

### LIB

Reusable headers with common definitions:

- **BitMath.h**  
  `SetBit`, `ClrBit`, `GetBit`, `ToggleBit` macros.  

- **STD_types.h**  
  `u8`, `u16`, `s8`, etc., for explicit-width integers.  

- **LCD_types.h**  
  LCD row/column constants, command codes.  

### APP

High‐level application code tying everything together:

- **main.c**  
  System initialization (clock, UART, ADC, timers), call to `Set_password()`, main loop handling menu and keypad input.  

- **program.c / program.h**  
  - `Set_password()` – prompt user via LCD and read a 5‑digit code  
  - `Setup_password()` – store or change the code in EEPROM (if implemented)  
  - `Enter_password(trials)` – allow multiple attempts, trigger lockout or open servo  
  - `Main_Menu()` – navigate application options (view temp, number of trials, reset).  

---

## Build & Flash Instructions

1. **Using AVR‑GCC/Make**  
   ```bash
   cd GccApplication1/Debug
   make
   avrdude -c usbasp -p m32 -U flash:w:GccApplication1.hex
   ```

2. **Using Atmel Studio**  
   - Open `GccApplication1.cproj`  
   - Build solution  
   - Connect programmer and flash device  

---

## Simulation

- **Proteus**: Open `Proteus/Milestone simulation.pdsprj`, run to test keypad, LCD, servo, etc.

---

## Authors

- Karim Mohamed  
- Abanoub Osama  

