---
title: Aviso do compilador (nível 1) C4965
ms.date: 11/04/2016
f1_keywords:
- C4965
helpviewer_keywords:
- C4965
ms.assetid: 47f3f6dc-459b-4a25-9947-f394c8966cb5
ms.openlocfilehash: e882cabdf38fd9bc926fbaa04352ba9d0ace90ce
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174408"
---
# <a name="compiler-warning-level-1-c4965"></a>Aviso do compilador (nível 1) C4965

caixa implícita de inteiro 0; usar nullptr ou conversão explícita

O C++ Visual apresenta uma Boxing implícita de tipos de valor. Uma instrução que resultou em uma atribuição nula usando extensões gerenciadas C++ agora se torna uma atribuição para um inteiro em caixa.

Para obter mais informações, consulte [Boxing](../../extensions/boxing-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4965.

```cpp
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
