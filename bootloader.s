.set MAGIC, 0x1badb002
.set FLAGS, 0
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .text
.global entry
entry:
mov $kernel_stack, %esp
call kernel_main
jmp entry

.section .data
.space 1024
kernel_stack:
