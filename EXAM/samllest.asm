
include 'emu8086.inc'
org 100h   

.model small
.data                    
  arr db 8,5,3,6,1
.code
main proc  
    mov ax,@data
    mov ds,ax
    
    mov si,offset arr
    mov cx,5
    mov bl,[si]
    
    LoopA:
    cmp [si],bl 
    jle small
    campare:
    inc si  
    loop LoopA 
    
    print 'Smallest value in array :$'
    add bl,48 
    mov dl,bl
    mov ah,2
    int 21h
    
    small:
    mov bl,[si]
    jmp campare 
       
    large:
    mov bl,[si]
    jmp campare     
    
main endp

ret