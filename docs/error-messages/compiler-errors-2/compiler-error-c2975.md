---
title: Erro do compilador C2975
ms.date: 11/04/2016
f1_keywords:
- C2975
helpviewer_keywords:
- C2975
ms.assetid: 526f6b9d-6c76-4c12-9252-1b1d7c1e06c7
ms.openlocfilehash: 66b7c0d61cbc8141b9ed3e5f6eb329b68eb00477
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64344695"
---
# <a name="compiler-error-c2975"></a>Erro do compilador C2975

> '*argumento*': argumento de template inválido para '*tipo*', esperada expressão constante de tempo de compilação

O argumento de modelo não coincide com a declaração de modelo; uma expressão constante deve aparecer dentro de colchetes angulares. Não são permitidas variáveis como argumentos de modelo real. Verifique a definição de modelo para localizar os tipos corretos.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2975 e também mostra o uso correto:

```cpp
// C2975.cpp
template<int I>
class X {};

int main() {
   int i = 4, j = 2;
   X<i + j> x1;   // C2975
   X<6> x2;   // OK
}
```

C2975 também ocorre quando você usa &#95; &#95;linha&#95; &#95; como uma constante de tempo de compilação com [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md). Uma solução seria compilar com [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) em vez de **/ZI**.

```cpp
// C2975b.cpp
// compile with: /ZI
// processor: x86
template<long line>
void test(void) {}

int main() {
   test<__LINE__>();   // C2975
}
```