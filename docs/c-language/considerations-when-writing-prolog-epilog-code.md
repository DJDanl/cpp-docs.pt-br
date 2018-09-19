---
title: Considerações quando escrever código de prólogo/epílogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- layouts, stack frame
- stack frame layout
- __LOCAL_SIZE constant
- stack, stack frame layout
ms.assetid: 3b8addec-e809-48e4-b1d0-5bad133bd4b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0da7d91ab32218e407c9be197e978f98ec481305
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46067735"
---
# <a name="considerations-when-writing-prologepilog-code"></a>Considerações quando escrever código de prólogo/epílogo

**Seção específica da Microsoft**

Antes de escrever suas próprias sequências de código de prólogo e epílogo, é importante entender como o registro de ativação é apresentado. Também é útil saber como usar a constante predefinida **__LOCAL_SIZE**.

##  <a name="_clang_c_stack_frame_layout"></a> Layout de registro de ativação C

Este exemplo mostra o código padrão do prólogo que pode aparecer em uma função de 32 bits:

```
push     ebp                 ; Save ebp
mov      ebp, esp            ; Set stack frame pointer
sub      esp, localbytes     ; Allocate space for locals
push     <registers>         ; Save registers
```

A variável `localbytes` representa o número de bytes necessários na pilha para as variáveis locais. A variável `registers` é um espaço reservado que representa a lista de registros a serem salvos na pilha. Depois de enviar os registros, você pode colocar todos os outros dados apropriados na pilha. O seguinte exemplo é o código do epílogo correspondente:

```
pop      <registers>         ; Restore registers
mov      esp, ebp            ; Restore stack pointer
pop      ebp                 ; Restore ebp
ret                          ; Return from function
```

A pilha sempre vai para baixo (dos endereços de memória mais altos para os mais baixos). O ponteiro de base (`ebp`) aponta para o valor enviados por push de `ebp`. A área de variáveis locais começa em `ebp-2`. Para acessar variáveis locais, calcule um deslocamento de `ebp` subtraindo o valor apropriado de `ebp`.

##  <a name="_clang_the___local_size_constant"></a> A constante __LOCAL_SIZE

O compilador fornece uma constante, **__LOCAL_SIZE**, para o uso no bloco embutido do assembler do código do prólogo da função. Essa constante é usada para alocar espaço para as variáveis locais no quadro da pilha no código personalizado de prólogo.

O compilador determina o valor de **__LOCAL_SIZE**. O valor é o número total de bytes de todas as variáveis locais definidas pelo usuário e variáveis temporárias geradas pelo compilador. **__LOCAL_SIZE** pode ser usada apenas como um operando imediato; não pode ser usada em uma expressão. Você não deve alterar ou redefinir o valor dessa constante. Por exemplo:

```
mov      eax, __LOCAL_SIZE           ;Immediate operand--Okay
mov      eax, [ebp - __LOCAL_SIZE]   ;Error
```

O exemplo a seguir mostra uma função naked que contém sequências de prólogo e epílogo personalizadas e usa **__LOCAL_SIZE** na sequência de prólogo:

```
__declspec ( naked ) func()
{
   int i;
   int j;

   __asm      /* prolog */
      {
      push   ebp
      mov      ebp, esp
      sub      esp, __LOCAL_SIZE
      }

   /* Function body */

   __asm      /* epilog */
      {
      mov      esp, ebp
      pop      ebp
      ret
      }
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Funções naked](../c-language/naked-functions.md)