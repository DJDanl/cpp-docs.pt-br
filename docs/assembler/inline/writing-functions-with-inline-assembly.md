---
title: "Escrevendo fun&#231;&#245;es com assembly embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __asm [C++], em funções"
  - "assembler [C++], gravando funções"
  - "funções [C++], assembly embutido"
  - "assembly embutido [C++], gravando funções"
ms.assetid: b5df8a04-fdc7-4622-8c9e-e4b618927497
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Escrevendo fun&#231;&#245;es com assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Se você escrever uma função embutida com o código do assembly, é fácil a argumentos para a função e retornar um valor delas.  Os exemplos a seguir comparam uma função escrita principalmente para um assembler separado e reescrita para o assembler embutido.  A função, `power2`chamado, receberá dois parâmetros, multiplicando o primeiro parâmetro por 2 à potência do segundo parâmetro.  Escrito para um assembler separado, a função pode ter esta aparência:  
  
```  
; POWER.ASM  
; Compute the power of an integer  
;  
       PUBLIC _power2  
_TEXT SEGMENT WORD PUBLIC 'CODE'  
_power2 PROC  
  
        push ebp        ; Save EBP  
        mov ebp, esp    ; Move ESP into EBP so we can refer  
                        ;   to arguments on the stack  
        mov eax, [ebp+4] ; Get first argument  
        mov ecx, [ebp+6] ; Get second argument  
        shl eax, cl     ; EAX = EAX * ( 2 ^ CL )  
        pop ebp         ; Restore EBP  
        ret             ; Return with sum in EAX  
  
_power2 ENDP  
_TEXT   ENDS  
        END  
```  
  
 Desde que gravou para um assembler separado, a função requer etapas de um arquivo de origem separado e o assembly e link.  Os argumentos de função c e C\+\+ 2.0 geralmente são passados na pilha, o que nesta versão dos acessos da função de `power2` seus argumentos por suas posições na pilha. \(Observe que a política de **MODEL** , disponível em MASM e em outros assembler, também permitem que você acesse argumentos da pilha e variáveis locais da pilha por nome.\)  
  
## Exemplo  
 Esse programa grava a função de `power2` embutido com o código do assembly:  
  
```  
// Power2_inline_asm.c  
// compile with: /EHsc  
// processor: x86  
  
#include <stdio.h>  
  
int power2( int num, int power );  
  
int main( void )  
{  
    printf_s( "3 times 2 to the power of 5 is %d\n", \  
              power2( 3, 5) );  
}  
int power2( int num, int power )  
{  
   __asm  
   {  
      mov eax, num    ; Get first argument  
      mov ecx, power  ; Get second argument  
      shl eax, cl     ; EAX = EAX * ( 2 to the power of CL )  
   }  
   // Return with result in EAX  
}  
```  
  
 A versão embutida da função de `power2` se refere a seus argumentos e aparece por nome no mesmo arquivo de origem que o restante do programa.  Essa versão também requer menos instruções de assembly.  
  
 Como a versão embutida de `power2` não executará a instrução c `return` , gerencie um aviso inofensivo se você cria no nível de aviso 2 ou superior.  A função retorna um valor, mas o compilador não pode perceber que na ausência de uma instrução de `return` .  Você pode usar [aviso de \#pragma](../../preprocessor/warning.md) para desabilitar a geração desse aviso.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando C ou C\+\+ em blocos \_\_asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)