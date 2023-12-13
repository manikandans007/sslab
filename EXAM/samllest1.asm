
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
    
    mov ax,[si]
    LoopA:
    cmp [si],bl 
    jle small
    jmp p1
    campare1:
    inc si  
    loop LoopA
     
    LoopB:
    cmp [si],ax 
    jge large
    jmp p2
    campare2:
    inc si  
    loop LoopB
    p1:
    print 'Smallest value in array :$'
    p2:   
     print 'largest value in array :$'
     add al,48
     
    add bl,48
     
    mov dl,bl
    mov dx,ax
    mov ah,2
    int 21h
    
    small:
    mov bl,[si]
    jmp campare1 
       
    large:
    mov ax,[si]
    jmp campare2     
    
main endp

ret
