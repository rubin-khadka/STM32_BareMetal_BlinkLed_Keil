# STM32 BareMetal BlinkLed Keil

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![STM32](https://img.shields.io/badge/STM32-F103C8T6-blue)
![Keil](https://img.shields.io/badge/IDE-Keil--uVision5-green)

## Project Overview

This is the **Keil uVision5 version** of my bare-metal blink-led STM32F103C8 project. It was created to learn Keil and compare the two toolchains (Keil and CubeIDE). It demonstrates the exact same functionality as the **STM32CubeIDE** version. It configures the **72MHz system clock from the 8MHz HSE crystal and PLL**, and blinking the onboard LED on PC13 but built with Keil's ARMCLANG compiler.

**Purpose:** Compare toolchains (Keil vs CubeIDE) and their impact on code size, build process, and developer experience.

You can find the STM32CubeIDE version here:  
🔗 [STM32_BareMetal_BlinkLed_STM32cubeIDE](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_STM32cubeIDE)

## Features

| Feature | Description |
|---------|-------------|
| **72MHz System Clock** | HSE 8MHz × 9 PLL multiplication | 
| **Flash Configuration** | 2 wait states for 72MHz operation | 
| **APB1 Prescaler** | 72MHz/2 = 36MHz | 
| **LED Control** | PC13 push-pull output, active low | 

## Compare Two versions

| Aspect | STM32CubeIDE (GCC) | Keil uVision5 (ARMCLANG) |
|--------|---------------------|--------------------------|
| **Code Size** | 936 bytes | **712 bytes** |
| **Total Flash** | 2504 bytes | **984 bytes** |
| **Build Time** | 153ms | ~1s |
| **RAM Usage** | 1568 bytes | 1640 bytes |
| **Compiler** | arm-none-eabi-gcc | ARMCLANG V6.18 |

**Key findings:** 
- Keil produces **60% smaller** code with the same functionality
- STM32CubeIDE builds significantly faster
- RAM usage is comparable between both toolchains


## Video Demonstration

https://github.com/user-attachments/assets/cc511bb2-c0b4-4bc1-b9db-fd029f3f6868

*Same hardware, same behavior — LED blinks at 1Hz with 72MHz clock*

## Key Registers Configured

| Register | Setting | Purpose |
|----------|---------|---------|
| `RCC->CR` | `HSEON`, `PLLON` | Enable HSE crystal and PLL |
| `RCC->CFGR` | `PLLMULL9`, `PLLSRC`, `PPRE1_DIV2` | 72MHz clock, APB1 = 36MHz |
| `FLASH->ACR` | `LATENCY_2` | 2 wait states for 72MHz |
| `GPIOC->CRH` | `MODE13_0` | PC13 as output 10MHz, push-pull |
| `GPIOC->BSRR` | `BS13`, `BR13` | Atomic LED control |

[View complete clock configuration code](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_Keil/blob/main/Core/src/system_stm32f1xx.c)<br>
[View GPIO initialisation and control code](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_Keil/blob/main/Core/src/gpio.c)<br>
[View main application code](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_Keil/blob/main/Core/src/main.c)

## Getting Started

### Prerequisites

| Components | Details |
|------|---------|
| **MCU** | STM32F103C8T6 "Blue Pill" |
| **Crystal** | 8MHz HSE (onboard) |
| **LED** | PC13 (onboard, active LOW) |
| **Programmer** | ST-Link V2 |
    | **IDE** | Keil uVision5 (MDK-ARM) |

### Installation

1. Clone the repository
```bash
git clone https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_Keil.git
```
2. Open in Keil uVision5
- Double-click the project file (.uvprojx)
- Or `Project` → `Open Project` → select file

3. Configure Project Settings
- Ensure device is set to STM32F103C8
- `Project` → `Options for Target` → `C/C++` tab
- Add `STM32F10X_MD` to Preprocessor Symbols `Define`
- Also add `Include Paths`:
    - ~\Keil\Packs\ARM\CMSIS\5.9.0\CMSIS\Core\Include

4. Build & Flash
- Build: `F7`
- Flash: `F8` (if using ST-Link)
- Or `Debug` → `Start/Stop Debug Session`

Expected Behavior
- LED ON: 500ms
- LED OFF: 500ms
- Cycle: 1 second total
- Frequency: 1 Hz

LED blinks at 1Hz = 72MHz configured correctly

## Memory Footprint
| Section | Size | Description |
|--------|------|-------------|
|Code|712 bytes | Executable code |
|RO-data| 268 bytes	| Read-only data (constants) |
|RW-data| 4 bytes	| Initialized variables |
|ZI-data| 1636 bytes	| Uninitialized variables |
|Total Flash| 984 bytes	| Code + RO-data + RW-data |

Total Flash Usage: <1KB — Extremely efficient!

## Resources
- [STM32F103 Datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf)
- [STM32F103 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Project Status
- **Status**: Complete
- **Version**: v1.0
- **Last Updated**: February 2026

## Contact
**Rubin Khadka Chhetri**  
📧 rubin.robotic@gmail.com  
🐙 GitHub: https://github.com/rubin-khadka
