---
title: "Regras e limita&#231;&#245;es para fun&#231;&#245;es naked | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções naked"
ms.assetid: ff203858-2dd3-4a76-8a57-d0d06817adef
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Regras e limita&#231;&#245;es para fun&#231;&#245;es naked
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 As seguintes regras e restrições se aplicam às funções naked:  
  
-   A instrução `return` não é permitida.  
  
-   O tratamento de exceções estruturado e tratamento de exceções de C\+\+ não são permitidos, pois eles devem desenrolar pelo quadro de pilhas.  
  
-   Pela mesma razão, qualquer forma de `setjmp` é proibida.  
  
-   O uso da função `_alloca` é proibido.  
  
-   Para assegurar que nenhum código de inicialização para variáveis locais apareça antes da sequência de prólogo, variáveis locais inicializadas não são permitidas no escopo da função.  Em particular, a declaração de objetos C\+\+ não é permitida no escopo da função.  Porém, podem haver dados inicializados em um escopo aninhado.  
  
-   A otimização do ponteiro do quadro \(a opção \/Oy do compilador\) não é recomendada, mas ela será suprimida automaticamente para uma função naked.  
  
-   Você não pode declarar objetos da classe do C\+\+ no escopo lexical da função.  No entanto, é possível declarar objetos em um bloco aninhado.  
  
-   A palavra\-chave `naked` é ignorada durante a criação com [\/clr](../build/reference/clr-common-language-runtime-compilation.md).  
  
-   Para funções naked [\_\_fastcall](../cpp/fastcall.md), sempre que há uma referência em código C\/C\+\+ para um dos argumentos do registro, o código de prólogo deve armazenar os valores desse registro no local da pilha para essa variável.  Por exemplo:  
  
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
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Chamadas de função naked](../Topic/Naked%20Function%20Calls.md)