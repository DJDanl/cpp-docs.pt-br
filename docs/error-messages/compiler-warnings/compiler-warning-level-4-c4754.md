---
title: Aviso do compilador (nível 4) C4754
ms.date: 11/04/2016
f1_keywords:
- C4754
helpviewer_keywords:
- C4754
ms.assetid: e0e4606a-754a-4f42-a274-21a34978d21d
ms.openlocfilehash: 85c99feee72d94f50ec19394cf8aec7a3c9811bc
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684974"
---
# <a name="compiler-warning-level-4-c4754"></a>Aviso do compilador (nível 4) C4754

As regras de conversão para operações aritméticas em uma comparação significam que uma ramificação não pode ser executada.

O aviso C4754 é emitido porque o resultado da comparação é sempre o mesmo. Isso indica que uma das ramificações da condição nunca é executada, provavelmente porque a expressão de inteiro associada está incorreta. Esse defeito de código geralmente ocorre em verificações de estouro de inteiros incorretos em arquiteturas de 64 bits.

As regras de conversão de inteiros são complexas e há muitas armadilhas sutis. Como alternativa para corrigir cada aviso de C4754, você pode atualizar o código para usar a [biblioteca SafeInt](../../safeint/safeint-library.md).

## <a name="examples"></a>Exemplos

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

A adição `a + b` pode causar um estouro aritmético antes que o resultado seja convertido em um valor de 64 bits e atribuído à variável de 64 bits `x` . Isso significa que o check-in `x` é redundante e nunca detectará um estouro. Nesse caso, o compilador emite este aviso:

```Output
Warning C4754: Conversion rules for arithmetic operations in the comparison at C4754a.cpp (7) mean that one branch cannot be executed. Cast '(a + ...)' to 'ULONG64' (or similar type of 8 bytes).
```

Para eliminar o aviso, você pode alterar a instrução de atribuição para converter os operandos em valores de 8 bytes:

```cpp
// Casting one operand is sufficient to force all the operands in
// the addition be upcast according to C/C++ conversion rules, but
// casting both is clearer.
unsigned long long x =
   (unsigned long long)a + (unsigned long long)b;
```

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

O `sizeof()` operador retorna um `size_t` , cujo tamanho é dependente da arquitetura. O código de exemplo funciona em arquiteturas de 32 bits em que um `size_t` é um tipo de 32 bits. No entanto, em arquiteturas de 64 bits, `size_t` é um tipo de bit 64. As regras de conversão para inteiros significam que `a` é feito o upcast para um valor de 64 bits na expressão `a + b < a` como se ele fosse gravado `(size_t)a + (size_t)b < (size_t)a` . Quando `a` e `b` são inteiros de 32 bits, a operação de adição de 64 bits nunca pode exceder e a restrição nunca é mantida. Como resultado, o código nunca detecta uma condição de estouro de número inteiro em arquiteturas de 64 bits. Este exemplo faz com que o compilador emita este aviso:

```Output
Warning C4754: Conversion rules for arithmetic operations in the comparison at C4754b.cpp (7) mean that one branch cannot be executed. Cast '4' to 'ULONG' (or similar type of 4 bytes).
```

Observe que a mensagem de aviso lista explicitamente o valor de constante 4 em vez da cadeia de caracteres de origem original — no momento em que a análise de aviso encontra o código incorreto, `sizeof(unsigned long)` já foi convertida em uma constante. Portanto, talvez você precise rastrear qual expressão no código-fonte está associada ao valor constante na mensagem de aviso. As fontes de código mais comuns resolvidas para constantes em mensagens de aviso C4754 são expressões como `sizeof(TYPE)` e `strlen(szConstantString)` .

Nesse caso, o código fixo seria semelhante a este:

```cpp
// Casting the result of sizeof() to unsigned long ensures
// that all the addition operands are 32-bit, so any overflow
// is detected by the check.
if (a + (unsigned long)sizeof(unsigned long) < a)
```

**Observação** O número de linha referenciado nos avisos do compilador é a última linha de uma instrução. Em uma mensagem de aviso sobre uma instrução condicional complexa que se espalha por várias linhas, a linha que tem o defeito de código pode ser várias linhas antes da linha relatada. Por exemplo:

```cpp
unsigned long a;

if (a + sizeof(unsigned long) < a || // incorrect check
    condition1() ||
    a == 0) {    // C4754 warning reported on this line
         // never executes!
         return INVALID_PARAMETER;
}
```
