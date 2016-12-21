---
title: "Compilador C4754 de aviso (n&#237;vel 4) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4754"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4754"
ms.assetid: e0e4606a-754a-4f42-a274-21a34978d21d
caps.latest.revision: 6
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4754 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Regras de conversão para operações aritméticas em um meio de comparação que uma ramificação não pode ser executado.  
  
 O C4754 aviso é emitido porque o resultado da comparação será sempre o mesmo.  Isso indica que uma das ramificações de condição é executado nunca, provavelmente porque a expressão associada de inteiro está incorreta.  Este código de defeito ocorre com frequência em verificações incorretas de estouro de inteiro em arquiteturas de 64 bits.  
  
 As regras de conversão de inteiro são complexas e há muitas armadilhas suteis.  Como uma alternativa para corrigir cada aviso C4754, você pode atualizar o código para usar [Biblioteca de SafeInt](../../windows/safeint-library.md).  
  
## Exemplo  
 Este exemplo gera C4754:  
  
```cpp  
// C4754a.cpp  
// Compile with: /W4 /c  
#include "errno.h"  
  
int sum_overflow(unsigned long a, unsigned long b)   
{  
   unsigned long long x = a + b; // C4754  
  
   if (x > 0xFFFFFFFF)   
   {  
      // never executes!  
      return EOVERFLOW;  
   }  
   return 0;  
}  
```  
  
 A adição `a + b` poderia causar um estouro aritmético antes do resultado é upcast a um valor de 64 bits e é atribuído a `x`variável de 64 bits.  Isso significa que a verificação em `x` é redundante e nunca detectará um estouro.  Nesse caso, o compilador emite esse aviso:  
  
  **C4754 de aviso: Regras de conversão para operações aritméticas na comparação no meio de C4754a.cpp \(7\) que uma ramificação não pode ser executado.  “A conversão \(\+…\)” a “ULONG64” \(ou a um tipo semelhante de 8 bytes\).**  Para eliminar o prompt, você pode modificar a instrução de atribuição para converter os operandos em 8 valores de byte:  
  
```cpp  
// Casting one operand is sufficient to force all the operands in   
// the addition be upcast according to C/C++ conversion rules, but  
// casting both is clearer.  
unsigned long long x =   
   (unsigned long long)a + (unsigned long long)b;  
```  
  
## Exemplo  
 O exemplo a seguir também gerencia C4754.  
  
```cpp  
// C4754b.cpp  
// Compile with: /W4 /c  
#include "errno.h"  
  
int wrap_overflow(unsigned long a)   
{  
   if (a + sizeof(unsigned long) < a) // C4754  
   {   
      // never executes!  
      return EOVERFLOW;  
   }  
   return 0;  
}  
```  
  
 O operador de `sizeof()` retorna `size_t`, cujo tamanho é arquitetura\- dependente.  O código de exemplo funciona em arquiteturas de 32 bits em `size_t` é um tipo de 32 bits.  No entanto, em arquiteturas de 64 bits, `size_t` é um tipo de 64 bits.  As regras de conversão para inteiros significa que `a` é upcast a um valor de 64 bits na expressão `a + b < a` como se gravou `(size_t)a + (size_t)b < (size_t)a`.  Quando `a` e `b` são inteiro de 32 bits, a operação de 64 bits de adição nunca pode transbordar, e a restrição nunca contém.  No, o código nunca detectar uma condição de estouro de inteiro em arquiteturas de 64 bits.  Este exemplo faz com que o compilador emita\-se esse aviso:  
  
  **C4754 de aviso: Regras de conversão para operações aritméticas na comparação no meio de C4754b.cpp \(7\) que uma ramificação não pode ser executado.  Conversão “4 " para “ULONG” \(ou a um tipo semelhante de 4 bytes\).**  Observe que a mensagem de aviso lista explicitamente o valor constante 4 em vez do original cadeia de caracteres\- para a hora em que a análise de aviso encontrar o código de para, `sizeof(unsigned long)` já tiver sido convertida como uma constante.  Consequentemente, talvez você precise rastrear para baixo que a expressão no código\-fonte estiver associada com o valor constante na mensagem de aviso.  As fontes mais comuns de código resolvidas às constantes em mensagens de aviso C4754 são expressões como `sizeof(TYPE)` e `strlen(szConstantString)`.  
  
 Nesse caso, o código fixo seria semelhante a este:  
  
```cpp  
// Casting the result of sizeof() to unsigned long ensures  
// that all the addition operands are 32-bit, so any overflow   
// is detected by the check.  
if (a + (unsigned long)sizeof(unsigned long) < a)  
  
```  
  
 **Observação** O número da linha referenciada em avisos do compilador é a última linha de uma instrução.  Em uma mensagem de aviso sobre uma instrução condicional complexa que é difundida sobre várias linhas, a linha que tem o defeito de código pode ser várias linhas antes da linha que é relatado.  Por exemplo:  
  
```cpp  
unsigned long a;  
  
if (a + sizeof(unsigned long) < a || // incorrect check  
    condition1() ||   
    a == 0) {    // C4754 warning reported on this line  
         // never executes!  
         return INVALID_PARAMETER;  
}  
  
```