---
title: Regras e limitações para funções naked
ms.date: 11/04/2016
helpviewer_keywords:
- naked functions [C++]
ms.assetid: ff203858-2dd3-4a76-8a57-d0d06817adef
ms.openlocfilehash: 3dd089e13323e1811cf9d7c7717612313f2cef7d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225846"
---
# <a name="rules-and-limitations-for-naked-functions"></a>Regras e limitações para funções naked

**Específico da Microsoft**

As seguintes regras e restrições se aplicam às funções naked:

- A **`return`** instrução não é permitida.

- O tratamento de exceções estruturado e tratamento de exceções de C++ não são permitidos, pois eles devem desenrolar pelo quadro de pilhas.

- Pela mesma razão, qualquer forma de `setjmp` é proibida.

- O uso da função `_alloca` é proibido.

- Para assegurar que nenhum código de inicialização para variáveis locais apareça antes da sequência de prólogo, variáveis locais inicializadas não são permitidas no escopo da função. Em particular, a declaração de objetos C++ não é permitida no escopo da função. Porém, podem haver dados inicializados em um escopo aninhado.

- A otimização do ponteiro do quadro (a opção /Oy do compilador) não é recomendada, mas ela será suprimida automaticamente para uma função naked.

- Você não pode declarar objetos da classe do C++ no escopo lexical da função. No entanto, é possível declarar objetos em um bloco aninhado.

- A **`naked`** palavra-chave é ignorada durante a compilação com [/CLR](../build/reference/clr-common-language-runtime-compilation.md).

- Para [__fastcall](../cpp/fastcall.md) funções Naked, sempre que houver uma referência no código C/C++ para um dos argumentos de registro, o código de prólogo deverá armazenar os valores desse registro no local da pilha para essa variável. Por exemplo:

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

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Chamadas de função Naked](../cpp/naked-function-calls.md)
