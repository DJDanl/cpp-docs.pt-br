---
title: "Escrevendo funções com Assembly embutido | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- functions [C++], inline assembly
- inline assembly [C++], writing functions
- assembler [C++], writing functions
- __asm keyword [C++], in functions
ms.assetid: b5df8a04-fdc7-4622-8c9e-e4b618927497
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2b7abbb7a09f5205ada192cf15d5b7eb3c5c6b33
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="writing-functions-with-inline-assembly"></a>Escrevendo funções com assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Se você escrever uma função com código de assembly embutido, é fácil passar argumentos para a função e retornar um valor de-lo. Os exemplos a seguir comparam uma função primeiro criado para um assembler separado e, em seguida, reescrito para o assembler embutido. A função chamada `power2`, recebe dois parâmetros, multiplicando o primeiro parâmetro 2 à potência do segundo parâmetro. Escrito para um assembler separado, a função teria esta aparência:  
  
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
  
 Desde que ele foi criado para um assembler separado, a função requer etapas de arquivo e o assembly e o link de uma fonte separado. Argumentos de função C e C++ são passados na pilha, portanto essa versão do `power2` função acessa seus argumentos por suas posições na pilha. (Observe que o **modelo** diretiva, disponível no MASM e alguns outros montadores também permite que você acesse pilha argumentos e variáveis de pilha local por nome.)  
  
## <a name="example"></a>Exemplo  
 Este programa grava o `power2` função com o código de assembly embutido:  
  
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
  
 A versão embutida o `power2` refere-se aos argumentos por nome de função e aparece no arquivo de origem como o restante do programa. Esta versão também requer menos instruções do assembly.  
  
 Porque a versão embutida do `power2` não executa um C `return` instrução, ele faz com que um aviso inofensivo se você compilar no nível de aviso 2 ou superior. A função retornar um valor, mas o compilador não pode determinar que na ausência de um `return` instrução. Você pode usar [#pragma aviso](../../preprocessor/warning.md) para desabilitar a geração deste aviso.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)