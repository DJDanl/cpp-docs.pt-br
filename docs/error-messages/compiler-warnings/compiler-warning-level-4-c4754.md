---
title: "Compilador aviso (nível 4) C4754 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4754
dev_langs:
- C++
helpviewer_keywords:
- C4754
ms.assetid: e0e4606a-754a-4f42-a274-21a34978d21d
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5a8678f7bdc2a83cb86ab53f5f2793003f4a0c03
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4754"></a>Compilador C4754 de aviso (nível 4)
Regras de conversão para operações aritméticas em uma comparação significam que uma ramificação não pode ser executada.  
  
 O C4754 aviso é emitido porque o resultado da comparação é sempre o mesmo. Isso indica que uma das ramificações da condição nunca será executada, provavelmente porque a expressão de inteiro associado está incorreta. Esse defeito de código geralmente ocorre em verificações de estouro de inteiro incorreto em arquiteturas de 64 bits.  
  
 Regras de conversão de inteiro são complexas e há muitas armadilhas sutis. Como alternativa para a correção de cada aviso C4754, você pode atualizar o código para usar o [biblioteca SafeInt](../../windows/safeint-library.md).  
  
## <a name="example"></a>Exemplo  
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
  
 A adição `a + b` pode causar um estouro aritmético antes do resultado é elevado para um valor de 64 bits e atribuído à variável de 64 bits `x`. Isso significa que a verificação em `x` é redundante e nunca será catch um estouro. Nesse caso, o compilador emite esse aviso:  
  
```Output  
Warning C4754: Conversion rules for arithmetic operations in the comparison at C4754a.cpp (7) mean that one branch cannot be executed. Cast '(a + ...)' to 'ULONG64' (or similar type of 8 bytes).  
```  
  
 Para eliminar o aviso, você pode alterar a instrução de atribuição para converter os operandos para valores de 8 bytes:  
  
```cpp  
// Casting one operand is sufficient to force all the operands in   
// the addition be upcast according to C/C++ conversion rules, but  
// casting both is clearer.  
unsigned long long x =   
   (unsigned long long)a + (unsigned long long)b;  
```  
  
## <a name="example"></a>Exemplo  
 O próximo exemplo também gera C4754.  
  
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
  
 O `sizeof()` operador retorna um `size_t`, cujo tamanho é dependente da arquitetura. O código de exemplo funciona em arquiteturas de 32 bits em que um `size_t` é um tipo de 32 bits. No entanto, em arquiteturas de 64 bits, `size_t` é um tipo de 64 bits. As regras de conversão de inteiros significam que `a` é elevado para um valor de 64 bits na expressão `a + b < a` como se ele foi gravado `(size_t)a + (size_t)b < (size_t)a`. Quando `a` e `b` são inteiros de 32 bits, a operação de adição de 64 bits nunca pode estourar e nunca contém a restrição. Como resultado, o código nunca detecta uma condição de estouro de inteiro em arquiteturas de 64 bits. Este exemplo faz com que o compilador emita este aviso:  
  
```Output  
Warning C4754: Conversion rules for arithmetic operations in the comparison at C4754b.cpp (7) mean that one branch cannot be executed. Cast '4' to 'ULONG' (or similar type of 4 bytes).  
```  
  
 Observe que a mensagem de aviso lista explicitamente o valor da constante 4 em vez da cadeia de caracteres de origem original — no momento a análise de aviso encontra o código incorreto, `sizeof(unsigned long)` já foi convertido em uma constante. Portanto, você precisará controlar para baixo da expressão na fonte de código é associado com o valor da constante na mensagem de aviso. As fontes mais comuns de código resolvido para constantes em mensagens de aviso C4754 são expressões como `sizeof(TYPE)` e `strlen(szConstantString)`.  
  
 Nesse caso, o código fixo é semelhante a isso:  
  
```cpp  
// Casting the result of sizeof() to unsigned long ensures  
// that all the addition operands are 32-bit, so any overflow   
// is detected by the check.  
if (a + (unsigned long)sizeof(unsigned long) < a)  
  
```  
  
 **Observação** o número da linha referenciado em avisos do compilador é a última linha de uma instrução. Em uma mensagem de aviso sobre uma instrução condicional complexa que é distribuída em várias linhas, a linha que tenha o defeito de código pode ser várias linhas antes da linha que é relatado. Por exemplo:  
  
```cpp  
unsigned long a;  
  
if (a + sizeof(unsigned long) < a || // incorrect check  
    condition1() ||   
    a == 0) {    // C4754 warning reported on this line  
         // never executes!  
         return INVALID_PARAMETER;  
}  
```
