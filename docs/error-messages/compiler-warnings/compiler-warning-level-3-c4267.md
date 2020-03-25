---
title: Aviso do compilador (nível 3) C4267
ms.date: 11/04/2016
f1_keywords:
- C4267
helpviewer_keywords:
- C4267
ms.assetid: 2fa2f13f-fa4f-47bb-ad8f-6cb19cfc91e6
ms.openlocfilehash: 2ae4b53dfa5050e178bf5ddd366e97c4ff773dd0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161510"
---
# <a name="compiler-warning-level-3-c4267"></a>Aviso do compilador (nível 3) C4267

' var ': conversão de ' size_t ' para ' type ', possível perda de dados

O compilador detectou uma conversão de `size_t` em um tipo menor.

Para corrigir esse aviso, use `size_t` em vez de `type`. Como alternativa, use um tipo integral que seja pelo menos tão grande quanto `size_t`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4267.

```cpp
// C4267.cpp
// compile by using: cl /W4 C4267.cpp
void Func1(short) {}
void Func2(int) {}
void Func3(long) {}
void Func4(size_t) {}

int main() {
   size_t bufferSize = 10;
   Func1(bufferSize);   // C4267 for all platforms
   Func2(bufferSize);   // C4267 only for 64-bit platforms
   Func3(bufferSize);   // C4267 only for 64-bit platforms
   Func4(bufferSize);   // OK for all platforms
}
```
