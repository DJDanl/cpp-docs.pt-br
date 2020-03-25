---
title: Escrevendo funções com assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- functions [C++], inline assembly
- inline assembly [C++], writing functions
- assembler [C++], writing functions
- __asm keyword [C++], in functions
ms.assetid: b5df8a04-fdc7-4622-8c9e-e4b618927497
ms.openlocfilehash: 5416a29477651c496d83e6ee215a2cb88ba26e3b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169052"
---
# <a name="writing-functions-with-inline-assembly"></a>Escrevendo funções com assembly embutido

**Seção específica da Microsoft**

Se você escrever uma função com código de assembly embutido, será fácil passar argumentos para a função e retornar um valor dele. Os exemplos a seguir comparam uma função escrita primeiro para um montador separado e, em seguida, reescritas para o montador embutido. A função, chamada `power2`, recebe dois parâmetros, multiplicando o primeiro parâmetro por 2 na potência do segundo parâmetro. Escrito para um montador separado, a função pode ser assim:

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

Como ele é escrito para um montador separado, a função requer um arquivo de origem separado e etapas de montagem e de link. Os argumentos C++ C e function são geralmente passados na pilha, portanto, essa versão da função `power2` acessa seus argumentos por suas posições na pilha. (Observe que a diretiva de **modelo** , disponível em MASM e outros montadores, também permite que você acesse argumentos de pilha e variáveis de pilha local por nome.)

## <a name="example"></a>Exemplo

Este programa grava a função `power2` com o código de assembly embutido:

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

A versão embutida da função `power2` refere-se a seus argumentos por nome e aparece no mesmo arquivo de origem que o restante do programa. Essa versão também requer menos instruções de assembly.

Como a versão embutida do `power2` não executa uma instrução C `return`, isso causará um aviso inofensivo se você compilar no nível de aviso 2 ou superior. A função retorna um valor, mas o compilador não pode dizer que na ausência de uma instrução `return`. Você pode usar [#pragma Aviso](../../preprocessor/warning.md) para desabilitar a geração desse aviso.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
