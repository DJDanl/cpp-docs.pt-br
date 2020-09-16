---
title: Erro do compilador C3699
ms.date: 11/04/2016
f1_keywords:
- C3699
helpviewer_keywords:
- C3699
ms.assetid: 47c29afc-ab8b-4238-adfe-788dd6e00b3b
ms.openlocfilehash: d313168e8033395da1749e000e52421939f77af4
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686646"
---
# <a name="compiler-error-c3699"></a>Erro do compilador C3699

' operator ': não é possível usar esta indireção no tipo ' type '

Foi feita uma tentativa de usar indireção que não é permitido em `type` .

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3699.

```cpp
// C3699.cpp
// compile with: /clr /c
using namespace System;
int main() {
   String * s;   // C3699
   // try the following line instead
   // String ^ s2;
}
```

Uma propriedade trivial não pode ter tipo de referência. Consulte a [Propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações. O exemplo a seguir gera C3699.

```cpp
// C3699_b.cpp
// compile with: /clr /c
ref struct C {
   property System::String % x;   // C3699
   property System::String ^ y;   // OK
};
```

O equivalente a uma sintaxe "ponteiro para um ponteiro" é um identificador para uma referência de rastreamento. O exemplo a seguir gera C3699.

```cpp
// C3699_c.cpp
// compile with: /clr /c
using namespace System;
void Test(String ^^ i);   // C3699
void Test2(String ^% i);
```
