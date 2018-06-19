---
title: C2975 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2975
dev_langs:
- C++
helpviewer_keywords:
- C2975
ms.assetid: 526f6b9d-6c76-4c12-9252-1b1d7c1e06c7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 53cb020dc0d456f10b7cfbae82a16b2ebe5fda6b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246977"
---
# <a name="compiler-error-c2975"></a>C2975 de erro do compilador

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