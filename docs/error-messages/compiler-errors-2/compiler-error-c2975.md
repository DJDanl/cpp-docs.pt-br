---
title: Erro do compilador C2975
ms.date: 11/04/2016
f1_keywords:
- C2975
helpviewer_keywords:
- C2975
ms.assetid: 526f6b9d-6c76-4c12-9252-1b1d7c1e06c7
ms.openlocfilehash: 70fc648de8bcf4f1e85edf3a12cc0b7d3d70625f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201559"
---
# <a name="compiler-error-c2975"></a>Erro do compilador C2975

> '*Argument*': argumento de template inválido para '*Type*', expressão constante de tempo de compilação esperada

O argumento de modelo não corresponde à declaração de modelo; uma expressão constante deve aparecer dentro dos colchetes angulares. Variáveis não são permitidas como argumentos reais de modelo. Verifique a definição do modelo para localizar os tipos corretos.

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

C2975 também ocorre quando você usa &#95; &#95;a&#95; &#95; linha como uma constante de tempo de compilação com [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md). Uma solução seria compilar com [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) em vez de **/Zi**.

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
