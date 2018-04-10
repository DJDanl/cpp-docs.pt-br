---
title: Regras e limitações para funções Naked | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- naked functions [C++]
ms.assetid: ff203858-2dd3-4a76-8a57-d0d06817adef
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b9a007cd18714906b3897004549da83053b42ec3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rules-and-limitations-for-naked-functions"></a>Regras e limitações para funções naked
## <a name="microsoft-specific"></a>Específico da Microsoft  
 As seguintes regras e restrições se aplicam às funções naked:  
  
-   A instrução `return` não é permitida.  
  
-   O tratamento de exceções estruturado e tratamento de exceções de C++ não são permitidos, pois eles devem desenrolar pelo quadro de pilhas.  
  
-   Pela mesma razão, qualquer forma de `setjmp` é proibida.  
  
-   O uso da função `_alloca` é proibido.  
  
-   Para assegurar que nenhum código de inicialização para variáveis locais apareça antes da sequência de prólogo, variáveis locais inicializadas não são permitidas no escopo da função. Em particular, a declaração de objetos C++ não é permitida no escopo da função. Porém, podem haver dados inicializados em um escopo aninhado.  
  
-   A otimização do ponteiro do quadro (a opção /Oy do compilador) não é recomendada, mas ela será suprimida automaticamente para uma função naked.  
  
-   Você não pode declarar objetos da classe do C++ no escopo lexical da função. No entanto, é possível declarar objetos em um bloco aninhado.  
  
-   O `naked` palavra-chave é ignorada durante a compilação com [/clr](../build/reference/clr-common-language-runtime-compilation.md).  
  
-   Para [fastcall](../cpp/fastcall.md) funções naked, sempre que houver uma referência no código C/C++ para um dos argumentos de registro, o código de prólogo deve armazenar os valores de registrador para o local da pilha para aquela variável. Por exemplo:  
  
```  
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