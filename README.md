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

# README

## Buffer Overflow

This project presents a comprehensive study of **buffer overflow vulnerabilities**. It combines theoretical analysis of memory management with a practical laboratory walkthrough demonstrating both **exploitation** and **mitigation** of stack-based buffer overflows.

The goal is to understand how buffer overflows occur, how they can be exploited in controlled environments, and how modern operating systems defend against them.

---

## Table of Contents

| Section | Path / File                                                    | Description                                         |
| ------: | -------------------------------------------------------------- | --------------------------------------------------- |
|       1 | `assign/`                                                      | Official laboratory exercise specifications         |
|     1.1 | `assign/Exercise 1 (Buffer Overflow) - THEORETICAL PART.pdf`   | Assignment description – theoretical part (English) |
|     1.2 | `assign/Exercise 1 (Buffer Overflow) - PRACTICAL PART.pdf`     | Assignment description – practical part (English)   |
|     1.3 | `assign/Άσκηση 1 (Buffer Overflow) - ΘΕΩΡΗΤΙΚΟ ΜΕΡΟΣ_2023.pdf` | Assignment description – theoretical part (Greek)   |
|     1.4 | `assign/Άσκηση 1 (Buffer Overflow) - ΠΡΑΚΤΙΚΟ ΜΕΡΟΣ_2023.pdf`  | Assignment description – practical part (Greek)     |
|       2 | `docs/`                                                        | Project reports and analysis                        |
|     2.1 | `docs/Buffer-Overflow.pdf`                                     | Technical report (English)                          |
|     2.2 | `docs/Υπερχείλιση-Ενδιάμεσης-Μνήμης.pdf`                       | Technical report (Greek)                            |
|       3 | `src/`                                                         | Vulnerable programs and exploit source code         |
|     3.1 | `src/stack.c`                                                  | Vulnerable stack-based buffer overflow program      |
|     3.2 | `src/shellcode.c`                                              | Shellcode implementation                            |
|     3.3 | `src/dash_shellcode.c`                                         | Shellcode adapted for dash shell                    |
|     3.4 | `src/exploit.c`                                                | Exploit construction and payload generation         |
|       4 | `figs/`                                                        | Diagrams and theoretical illustrations              |
|       5 | `screens/`                                                     | Experimental screenshots and attack validation      |
|     5.1 | `screens/Activity1–8/`                                         | Step-by-step evidence for each lab activity         |
|       6 | `README.md`                                                    | Project documentation                               |
|       7 | `INSTALL.md`                                                   | Usage instructions                                  |

---

## 1. Memory Structure

The project analyzes how a program’s memory is organized and where vulnerabilities may arise:

- **Text Segment**: Stores executable program code.
- **Data Segment**: Stores initialized global and static variables.
- **BSS Segment**: Stores uninitialized global and static variables.
- **Heap**: Used for dynamic memory allocation (e.g., `malloc()`).
- **Stack**: Stores local variables, function arguments, return addresses, and stack frames.

---

## 2. Stack Frames

Each function call creates a **stack frame** containing:

- Function arguments
- Return Address
- Previous Frame Pointer
- Local variables

---

## 3. The Vulnerability

A **buffer overflow** occurs when a program writes more data to a buffer than it can hold.  
In stack-based overflows, this can overwrite the **Return Address**, allowing an attacker to redirect execution to malicious code (shellcode).

---

## 4. Practical Implementation

The laboratory exercise demonstrates a buffer overflow attack in a controlled environment.

## 5. Initial Setup

- **ASLR disabled** to make memory addresses predictable.

---

## 6. Shellcode Development

- A machine-level payload (`shellcode.c`) was developed to execute `/bin/sh`, granting a command shell.

---

## 7. Vulnerable Program

- A C program (`stack.c`) was created using the unsafe `strcpy()` function, which does not perform bounds checking.

---

## 8. Exploit Creation

- An exploit utility (`exploit.c`) generates a `badfile` containing:
  - **NOP Sled**: A sequence of `0x90` instructions to increase exploit reliability.
  - **Shellcode**: The malicious payload.
  - **Modified Return Address**: Redirects execution back into the buffer where the shellcode resides.

---

## 9. Experimental Results

### 9.1 Successful Exploitation

- By correctly calculating memory offsets and addresses, the exploit successfully redirected execution flow and spawned a shell with **root privileges (`#`)**.

### 9.2 Countermeasure Testing

The effectiveness of modern defenses was evaluated:

- **Stack Guard**
  - Detected stack corruption and terminated execution
  - Error: _“stack smashing detected”_

- **Non-Executable Stack (NX)**
  - Prevented execution of stack-resident code
  - Resulted in a _Segmentation Fault_ instead of a shell

- **Address Space Layout Randomization (ASLR)**
  - Randomized memory addresses
  - Made reliable exploitation significantly more difficult

---

## 10. Conclusion

This project demonstrates that **buffer overflows remain a critical security threat**, but modern operating system defenses, such as **ASLR**, **Stack Guards**, and **Non-Executable Stacks**, provide multiple layers of protection. While not foolproof individually, these mechanisms together greatly increase the complexity and difficulty of successful exploitation.
