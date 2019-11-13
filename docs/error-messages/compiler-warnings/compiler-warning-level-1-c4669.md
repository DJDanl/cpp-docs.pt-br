---
title: Aviso do compilador (nível 1) C4669
ms.date: 11/04/2016
f1_keywords:
- C4669
helpviewer_keywords:
- C4669
ms.assetid: 97730679-e3dc-44d4-b2a8-aa65badc17f2
ms.openlocfilehash: 58f7150caeb3e06ba400a08c6e484f677a8deff9
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051382"
---
# <a name="compiler-warning-level-1-c4669"></a>Aviso do compilador (nível 1) C4669

' cast ': conversão não segura: ' class ' é um objeto de tipo gerenciado ou WinRT

Uma conversão contém um Windows Runtime ou um tipo gerenciado. O compilador conclui a conversão executando uma cópia bits de um ponteiro para outro, mas não fornece nenhuma outra verificação. Para resolver esse aviso, não converta classes que contenham Membros gerenciados ou tipos de Windows Runtime.

O exemplo a seguir gera C4669 e mostra como corrigi-lo:

```cpp
// C4669.cpp
// compile with: /clr /W1
ref struct A {
   int i;
   Object ^ pObj;   // remove the managed member to fix the warning
};

ref struct B {
   int j;
};

int main() {
   A ^ a = gcnew A;
   B ^ b = reinterpret_cast<B ^>(a);   // C4669
}
```