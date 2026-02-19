<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
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
  <a href=https://scholar.google.com/citations?user=Djium2IAAAAJ&hl=en" target="_blank">Scholar</a> ·
  <a href="https://www.linkedin.com/in/aggelos-georgoulas/?originalSubdomain=uk" target="_blank">LinkedIn</a>
</p>

</hr>

---

<p align="center">
  Athens, April 2023
</p>

---

<p align="center">
  <img src="https://www.cobalt.io/hs-fs/hubfs/overflow-vulnerabilities-example-4.png?width=1600&height=900&name=overflow-vulnerabilities-example-4.png" width="250"/>
</p>

---

# INSTALL

## Buffer Overflow

This guide explains how to **set up, compile, and execute** the Buffer Overflow laboratory project in a **controlled environment** for educational purposes.

> **Warning**  
> This project intentionally disables security mechanisms and demonstrates exploitation techniques.  
> **Run ONLY on a virtual machine or isolated lab environment. Never on a production system.**

---

## 1. Prerequisites

### 1.1 Operating System (Mandatory)

- **SEED Ubuntu 16.04 (32-bit)**
- Provided by the **SEED Security Labs** project
- Preconfigured for security experimentation

> This project is **fully compatible** with the SEED 16.04 (x86) environment.

---

## 2. Virtualization (Strongly Recommended)

Use a Virtual Machine for safety:

- **VirtualBox** or **VMware**
- Ubuntu ISO installed inside the VM

---

## 3. Required Software & Tools

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

## 4. System Configuration (Lab Mode)

### 4.1 Disable ASLR (Required)

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

### 4.2 Disable Stack Protections (Compile-Time)

During compilation, stack protection and NX must be disabled manually (see below).

---

## 5. Installation and Setup

### 5.1 Clone the Repository

```bash
git clone https://github.com/Information-Technology-Security/Buffer-Overflow.git
cd Buffer-Overflow/src
```

---

## 6. Compilation Instructions

### 6.1 Compile the Vulnerable Program

```bash
gcc -fno-stack-protector -z execstack -no-pie stack.c -o stack
```

Flags explained:

- `-fno-stack-protector` → disables stack canaries
- `-z execstack` → makes stack executable
- `-no-pie` → disables position-independent execution

### 6.2 Compile the Shellcode

```bash
gcc -fno-stack-protector -z execstack shellcode.c -o shellcode
```

Optional (dash shell version):

```bash
gcc -fno-stack-protector -z execstack dash_shellcode.c -o dash_shellcode
```

### 6.3 Compile the Exploit Generator

```bash
gcc exploit.c -o exploit
```

---

## 7. Running the Exploit (Controlled Lab)

### 7.1 Generate the Malicious Input File

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

### 7.2 Execute the Vulnerable Program

```bash
./stack
```

If successful, you should obtain a shell:

```bash
#
```

This confirms successful stack-based buffer overflow exploitation.

---

## 8. Testing Security Countermeasures

### 8.1 Stack Guard (Canaries)

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

### 8.2 Non-Executable Stack (NX)

Compile without executable stack:

```bash
gcc -fno-stack-protector stack.c -o stack_nx
```

Expected behavior:

```bash
Segmentation fault
```

### 8.3 ASLR Enabled

Enable ASLR again:

```bash
sudo sysctl -w kernel.randomize_va_space=2
```

Re-run exploit → Exploit fails unpredictably

---

## 9. Troubleshooting

### 9.1 Exploit fails

- Verify ASLR is disabled
- Check compiler flags
- Confirm correct return address offset

### 9.2 Segmentation fault

- NX enabled
- Wrong memory offset
- Incorrect shellcode placement

---

## 10. Open the Documentation

1. Navigate to the `docs/` directory
2. Open the report corresponding to your preferred language:
   - English: `Buffer-Overflow.pdf`
   - Greek: `Υπερχείλιση-Ενδιάμεσης-Μνήμης.pdf`
