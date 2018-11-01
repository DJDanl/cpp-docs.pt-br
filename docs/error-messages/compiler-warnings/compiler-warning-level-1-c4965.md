---
title: Compilador aviso (nível 1) C4965
ms.date: 11/04/2016
f1_keywords:
- C4965
helpviewer_keywords:
- C4965
ms.assetid: 47f3f6dc-459b-4a25-9947-f394c8966cb5
ms.openlocfilehash: 7d77df395d680b467d1a04a3f59c9822842f99f5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653096"
---
# <a name="compiler-warning-level-1-c4965"></a>Compilador aviso (nível 1) C4965

box implícito de inteiro 0; Use nullptr ou conversão explícita

Conversão boxing implícita de tipos de valor de recursos do Visual C++. Uma instrução que resultaram em uma atribuição de nulo usando extensões gerenciadas para C++ agora se torna uma atribuição em um int. box

Para obter mais informações, consulte [Boxing](../../windows/boxing-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4965.

```
// C4965.cpp
// compile with: /clr /W1
int main() {
   System::Object ^o = 0;   // C4965

   // the previous line is the same as the following line
   // using Managed Extensions for C++
   // System::Object *o = __box(0);

   // OK
   System::Object ^o2 = nullptr;
   System::Object ^o3 = safe_cast<System::Object^>(0);
}
```