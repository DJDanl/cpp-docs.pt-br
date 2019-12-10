---
title: Considerações para escrever o código prólogo-epílogo
ms.date: 11/04/2016
helpviewer_keywords:
- stack frame layout
- prolog code
- epilog code
- __LOCAL_SIZE constant
- stack, stack frame layout
ms.assetid: c7814de2-bb5c-4f5f-96d0-bcfd2ad3b182
ms.openlocfilehash: a598ddbdd1b5f91c97e32905202e264b444c05d0
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988705"
---
# <a name="considerations-for-writing-prologepilog-code"></a>Considerações para escrever o código de prólogo/epílogo

**Seção específica da Microsoft**

Antes de escrever suas próprias sequências de código prólogo e epílogo, é importante entender como o quadro de pilhas é disposto. Também é útil saber como usar o símbolo de `__LOCAL_SIZE`.

##  <a name="_pluslang_c.2b2b_.stack_frame_layout"></a>Layout do quadro de pilhas

Este exemplo mostra o código padrão do prólogo que pode aparecer em uma função de 32 bits:

```
push        ebp                ; Save ebp
mov         ebp, esp           ; Set stack frame pointer
sub         esp, localbytes    ; Allocate space for locals
push        <registers>        ; Save registers
```

A variável `localbytes` representa o número de bytes necessários na pilha para as variáveis locais. A variável `<registers>` é um espaço reservado que representa a lista de registros a serem salvos na pilha. Depois de enviar os registros, você pode colocar todos os outros dados apropriados na pilha. O seguinte exemplo é o código do epílogo correspondente:

```
pop         <registers>   ; Restore registers
mov         esp, ebp      ; Restore stack pointer
pop         ebp           ; Restore ebp
ret                       ; Return from function
```

A pilha sempre vai para baixo (dos endereços de memória mais altos para os mais baixos). O ponteiro de base (`ebp`) aponta para o valor enviados por push de `ebp`. A área de locais começa em `ebp-4`. Para acessar variáveis locais, calcule um deslocamento de `ebp` subtraindo o valor apropriado de `ebp`.

##  <a name="_pluslang___local_size"></a> __LOCAL_SIZE

O compilador fornece um símbolo, `__LOCAL_SIZE`, para uso no bloco embutido do assembler do código de prólogo da função. Esse símbolo é usado para alocar espaço para as variáveis locais no quadro da pilha no código personalizado de prólogo.

O compilador determina o valor de `__LOCAL_SIZE`. Seu valor é o número total de bytes de todas as variáveis locais definidas pelo usuário e variáveis temporárias geradas pelo compilador. `__LOCAL_SIZE` pode ser usado somente como um operando imediato; Ele não pode ser usado em uma expressão. Você não deve alterar ou redefinir o valor desse símbolo. Por exemplo:

```
mov        eax, __LOCAL_SIZE           ;Immediate operand--Okay
mov        eax, [ebp - __LOCAL_SIZE]   ;Error
```

O exemplo a seguir de uma função Naked contendo prólogo personalizado e sequências epílogos usa o símbolo de `__LOCAL_SIZE` na sequência de prólogo:

```cpp
// the__local_size_symbol.cpp
// processor: x86
__declspec ( naked ) int main() {
   int i;
   int j;

   __asm {      /* prolog */
      push   ebp
      mov      ebp, esp
      sub      esp, __LOCAL_SIZE
      }

   /* Function body */
   __asm {   /* epilog */
      mov      esp, ebp
      pop      ebp
      ret
      }
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Chamadas de função naked](../cpp/naked-function-calls.md)
