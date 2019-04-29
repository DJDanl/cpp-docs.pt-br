---
title: Regras e limitações para funções naked
ms.date: 11/04/2016
helpviewer_keywords:
- naked functions [C++]
ms.assetid: ff203858-2dd3-4a76-8a57-d0d06817adef
ms.openlocfilehash: c813b97b85469165aae892b0a4cce888112e3dc5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62267360"
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

- Para [fastcall](../cpp/fastcall.md) funções naked, sempre que houver uma referência em C /C++ código como um dos argumentos do registro, o código de prólogo deve armazenar os valores do registro no local da pilha para essa variável. Por exemplo:

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