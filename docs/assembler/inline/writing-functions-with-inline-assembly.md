---
title: Escrevendo funções com assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- functions [C++], inline assembly
- inline assembly [C++], writing functions
- assembler [C++], writing functions
- __asm keyword [C++], in functions
ms.assetid: b5df8a04-fdc7-4622-8c9e-e4b618927497
ms.openlocfilehash: 7848a8f071f50f8d809a999a96a9c0f8193c480e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166848"
---
# <a name="writing-functions-with-inline-assembly"></a>Escrevendo funções com assembly embutido

**Seção específica da Microsoft**

Se você escrever uma função com código de assembly embutido, é fácil passar argumentos para a função e retornar um valor de-lo. Os exemplos a seguir comparam uma função criado pela primeira vez para um assembler separado e, em seguida, reescrita para o assembler embutido. A função chamada `power2`, recebe dois parâmetros, multiplicando o primeiro parâmetro por 2 à potência do segundo parâmetro. Escrito para um assembler separado, a função pode parecer com isso:

```asm
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

Uma vez que ele é escrito para um assembler separado, a função requer um etapas de arquivo e o assembly e o link de origem separado. Argumentos de função C e C++ geralmente são passados na pilha, portanto, esta versão do `power2` função acessa argumentos por suas posições na pilha. (Observe que o **modelo** diretiva, disponível no MASM e alguns outros montadores, também permite que você acesse argumentos da pilha e variáveis de pilha local por nome.)

## <a name="example"></a>Exemplo

Este programa grava o `power2` função com código de assembly embutido:

```cpp
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

A versão embutida do `power2` refere-se aos argumentos por nome de função e aparece no mesmo arquivo de origem como o restante do programa. Esta versão também requer menos instruções de assembly.

Porque a versão embutida do `power2` não executa a C `return` instrução, ele faz com que um aviso inofensivo informando se você compilar no nível de aviso 2 ou superior. A função retornar um valor, mas o compilador não pode determinar que na ausência de um `return` instrução. Você pode usar [#pragma aviso](../../preprocessor/warning.md) para desabilitar a geração deste aviso.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>