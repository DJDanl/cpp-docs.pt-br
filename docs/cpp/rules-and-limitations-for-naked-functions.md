---
title: Regras e limitações para funções Naked | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- naked functions [C++]
ms.assetid: ff203858-2dd3-4a76-8a57-d0d06817adef
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 944945c8a5660ef65621e022130a63a02b46761a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46020466"
---
# <a name="rules-and-limitations-for-naked-functions"></a>Regras e limitações para funções naked

## <a name="microsoft-specific"></a>Específico da Microsoft

As seguintes regras e restrições se aplicam às funções naked:

- O **retornar** instrução não é permitida.

- O tratamento de exceções estruturado e tratamento de exceções de C++ não são permitidos, pois eles devem desenrolar pelo quadro de pilhas.

- Pela mesma razão, qualquer forma de `setjmp` é proibida.

- O uso da função `_alloca` é proibido.

- Para assegurar que nenhum código de inicialização para variáveis locais apareça antes da sequência de prólogo, variáveis locais inicializadas não são permitidas no escopo da função. Em particular, a declaração de objetos C++ não é permitida no escopo da função. Porém, podem haver dados inicializados em um escopo aninhado.

- A otimização do ponteiro do quadro (a opção /Oy do compilador) não é recomendada, mas ela será suprimida automaticamente para uma função naked.

- Você não pode declarar objetos da classe do C++ no escopo lexical da função. No entanto, é possível declarar objetos em um bloco aninhado.

- O **naked** palavra-chave é ignorado ao compilar com [/clr](../build/reference/clr-common-language-runtime-compilation.md).

- Para [fastcall](../cpp/fastcall.md) funções naked, sempre que houver uma referência em código C/C++ para um dos argumentos do registro, o código de prólogo deve armazenar os valores do registro no local da pilha para essa variável. Por exemplo:

```cpp
// nkdfastcl.cpp
// compile with: /c
// processor: x86
__declspec(naked) int __fastcall  power(int i, int j) {
   // calculates i^j, assumes that j >= 0

   // prolog
   __asm {
      push ebp
      mov ebp, esp
      sub esp, __LOCAL_SIZE
     // store ECX and EDX into stack locations allocated for i and j
     mov i, ecx
     mov j, edx
   }

   {
      int k = 1;   // return value
      while (j-- > 0)
         k *= i;
      __asm {
         mov eax, k
      };
   }

   // epilog
   __asm {
      mov esp, ebp
      pop ebp
      ret
   }
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Chamadas de função naked](../cpp/naked-function-calls.md)