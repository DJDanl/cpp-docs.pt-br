---
title: Aviso do compilador (nível 1) C4546
ms.date: 11/04/2016
f1_keywords:
- C4546
helpviewer_keywords:
- C4546
ms.assetid: 071e1709-3841-46c1-8e71-96109cd22041
ms.openlocfilehash: 7c2e47b92050bb83b1f55836e633d9749bb5e309
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966411"
---
# <a name="compiler-warning-level-1-c4546"></a>Aviso do compilador (nível 1) C4546

faltando lista de argumentos na chamada de função antes da vírgula

O compilador detectou uma expressão de vírgula mal formada.

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4546:

```cpp
// C4546.cpp
// compile with: /W1
#pragma warning (default : 4546)
void f(int i) {
   i++;
}

int main() {
   int i = 0, k = 0;

   if ( f, k )   // C4546
   // try the following line instead
   // if ( f(i), k )
      i++;
}
```