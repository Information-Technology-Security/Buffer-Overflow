<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<hr/>

<p align="center">
  <strong>Information Technology Security</strong>
</p>

<h1 align="center" style="letter-spacing: 1px;">
  Buffer Overflow
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr/>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Ioanna Kantzavelou, Associate Professor<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/ioanna-kantzavelou/" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/ioanna-kantzavelou-74685934/" target="_blank">LinkedIn</a>
</p>


<p align="center">
  Co-supervisor: Angelos Georgoulas, Assistant Professor<br>
</p>

<p align="center">
  <a href=https://scholar.google.com/citations?user=Djium2IAAAAJ&hl=en" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/aggelos-georgoulas/?originalSubdomain=uk" target="_blank">LinkedIn</a>
</p>

</hr>


<p align="center">
  Athens, April 2023
</p>


---

# Project Overview

This project presents a comprehensive study of **buffer overflow vulnerabilities**. It combines theoretical analysis of memory management with a practical laboratory walkthrough demonstrating both **exploitation** and **mitigation** of stack-based buffer overflows.

The goal is to understand how buffer overflows occur, how they can be exploited in controlled environments, and how modern operating systems defend against them.

---

## Table of Contents

| Section | Path / File | Description |
|--------:|-------------|-------------|
| 1 | `assign/` | Official laboratory exercise specifications |
| 1.1 | `assign/Exercise 1 (Buffer Overflow) - THEORETICAL PART.pdf` | Assignment description – theoretical part (English) |
| 1.2 | `assign/Exercise 1 (Buffer Overflow) - PRACTICAL PART.pdf` | Assignment description – practical part (English) |
| 1.3 | `assign/Άσκηση 1 (Buffer Overflow) - ΘΕΩΡΗΤΙΚΟ ΜΕΡΟΣ_2023.pdf` | Assignment description – theoretical part (Greek) |
| 1.4 | `assign/Άσκηση 1 (Buffer Overflow) - ΠΡΑΚΤΙΚΟ ΜΕΡΟΣ_2023.pdf` | Assignment description – practical part (Greek) |
| 2 | `docs/` | Project reports and analysis |
| 2.1 | `docs/Buffer-Overflow.pdf` | Technical report (English) |
| 2.2 | `docs/Υπερχείλιση-Ενδιάμεσης-Μνήμης.pdf` | Technical report (Greek) |
| 3 | `src/` | Vulnerable programs and exploit source code |
| 3.1 | `src/stack.c` | Vulnerable stack-based buffer overflow program |
| 3.2 | `src/shellcode.c` | Shellcode implementation |
| 3.3 | `src/dash_shellcode.c` | Shellcode adapted for dash shell |
| 3.4 | `src/exploit.c` | Exploit construction and payload generation |
| 4 | `figs/` | Diagrams and theoretical illustrations |
| 5 | `screens/` | Experimental screenshots and attack validation |
| 5.1 | `screens/Activity1–8/` | Step-by-step evidence for each lab activity |
| 6 | `README.md` | Repository overview and execution notes |

## Theoretical Background

### Memory Structure
The project analyzes how a program’s memory is organized and where vulnerabilities may arise:

- **Text Segment**: Stores executable program code.  
- **Data Segment**: Stores initialized global and static variables.  
- **BSS Segment**: Stores uninitialized global and static variables.  
- **Heap**: Used for dynamic memory allocation (e.g., `malloc()`).
- **Stack**: Stores local variables, function arguments, return addresses, and stack frames.

### Stack Frames
Each function call creates a **stack frame** containing:
- Function arguments  
- Return Address  
- Previous Frame Pointer  
- Local variables  

### The Vulnerability
A **buffer overflow** occurs when a program writes more data to a buffer than it can hold.  
In stack-based overflows, this can overwrite the **Return Address**, allowing an attacker to redirect execution to malicious code (shellcode).

---

## Practical Implementation

The laboratory exercise demonstrates a buffer overflow attack in a controlled environment.

### Initial Setup
- **ASLR disabled** to make memory addresses predictable.

### Shellcode Development
- A machine-level payload (`shellcode.c`) was developed to execute `/bin/sh`, granting a command shell.

### Vulnerable Program
- A C program (`stack.c`) was created using the unsafe `strcpy()` function, which does not perform bounds checking.

### Exploit Creation
- An exploit utility (`exploit.c`) generates a `badfile` containing:
  - **NOP Sled**: A sequence of `0x90` instructions to increase exploit reliability.
  - **Shellcode**: The malicious payload.
  - **Modified Return Address**: Redirects execution back into the buffer where the shellcode resides.

---

## Experimental Results

### Successful Exploitation
- By correctly calculating memory offsets and addresses, the exploit successfully redirected execution flow and spawned a shell with **root privileges (`#`)**.

### Countermeasure Testing
The effectiveness of modern defenses was evaluated:

- **Stack Guard**  
  - Detected stack corruption and terminated execution  
  - Error: *“stack smashing detected”*

- **Non-Executable Stack (NX)**  
  - Prevented execution of stack-resident code  
  - Resulted in a *Segmentation Fault* instead of a shell

- **Address Space Layout Randomization (ASLR)**  
  - Randomized memory addresses  
  - Made reliable exploitation significantly more difficult

---

## Conclusion
This project demonstrates that **buffer overflows remain a critical security threat**, but modern operating system defenses, such as **ASLR**, **Stack Guards**, and **Non-Executable Stacks**, provide multiple layers of protection. While not foolproof individually, these mechanisms together greatly increase the complexity and difficulty of successful exploitation.

---

# Installation & Setup Guide  

This guide explains how to **set up, compile, and execute** the Buffer Overflow laboratory project in a **controlled environment** for educational purposes.

> **Warning**  
> This project intentionally disables security mechanisms and demonstrates exploitation techniques.  
> **Run ONLY on a virtual machine or isolated lab environment. Never on a production system.**

---

## Prerequisites

### 1. Operating System (Mandatory)

- **SEED Ubuntu 16.04 (32-bit)**
- Provided by the **SEED Security Labs** project
- Preconfigured for security experimentation

> This project is **fully compatible** with the SEED 16.04 (x86) environment.

---

### 2. Virtualization (Strongly Recommended)

Use a Virtual Machine for safety:

- **VirtualBox** or **VMware**
- Ubuntu ISO installed inside the VM

---

### 3. Required Software & Tools

Install the following packages:

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  gcc \
  gdb \
  make \
  vim \
  hexedit
```
Optional (for debugging & analysis):

```bash
sudo apt install -y gdb-multiarch
```

---

## System Configuration (Lab Mode)
### 1. Disable ASLR (Required)
ASLR must be disabled to make memory addresses predictable:
```bash
sudo sysctl -w kernel.randomize_va_space=0
```
Verify:
```bash
cat /proc/sys/kernel/randomize_va_space
```
Expected output:
```bash
0
```
To re-enable ASLR later:
```bash
sudo sysctl -w kernel.randomize_va_space=2
```

### 2. Disable Stack Protections (Compile-Time)
During compilation, stack protection and NX must be disabled manually (see below).

---

## Installation
### 1. Clone the Repository
```bash
git clone https://github.com/Information-Technology-Security/Buffer-Overflow.git
cd Buffer-Overflow/src
```

---

## Compilation Instructions
### 1. Compile the Vulnerable Program
```bash
gcc -fno-stack-protector -z execstack -no-pie stack.c -o stack
```
Flags explained:
- `-fno-stack-protector` → disables stack canaries
- `-z execstack` → makes stack executable
- `-no-pie` → disables position-independent execution

### 2. Compile the Shellcode
```bash
gcc -fno-stack-protector -z execstack shellcode.c -o shellcode
```
Optional (dash shell version):
```bash
gcc -fno-stack-protector -z execstack dash_shellcode.c -o dash_shellcode
```

### 3. Compile the Exploit Generator
```bash
gcc exploit.c -o exploit
```

--- 
 
## Running the Exploit (Controlled Lab)
### 1. Generate the Malicious Input File
```bash
./exploit
```
This creates a file named:
```bash
badfile
```
Containing:
- NOP sled
- Shellcode
- Overwritten return address

### 2. Execute the Vulnerable Program
```bash
./stack
```
If successful, you should obtain a shell:
```bash
#
```
This confirms successful stack-based buffer overflow exploitation.

---

## Testing Security Countermeasures
### 1. Stack Guard (Canaries)
Recompile without disabling stack protection:
```bash
gcc stack.c -o stack_protected
```
Run:
```bash
./stack_protected
```
Expected output:
```bash
*** stack smashing detected ***
```

### 2. Non-Executable Stack (NX)
Compile without executable stack:
```bash
gcc -fno-stack-protector stack.c -o stack_nx
```
Expected behavior:
```bash
Segmentation fault
```

### 3. ASLR Enabled
Enable ASLR again:
```bash
sudo sysctl -w kernel.randomize_va_space=2
```
Re-run exploit → Exploit fails unpredictably

---

## Troubleshooting
### Exploit fails
- Verify ASLR is disabled
- Check compiler flags
- Confirm correct return address offset

### Segmentation fault
- NX enabled
- Wrong memory offset
- Incorrect shellcode placement

---

## Open the Documentation
1. Navigate to the `docs/` directory
2. Open the report corresponding to your preferred language:
    - English: `Buffer-Overflow.pdf`
    - Greek: `Υπερχείλιση-Ενδιάμεσης-Μνήμης.pdf`