---
title: Compilador aviso (nível 1) C4669
ms.date: 11/04/2016
f1_keywords:
- C4669
helpviewer_keywords:
- C4669
ms.assetid: 97730679-e3dc-44d4-b2a8-aa65badc17f2
ms.openlocfilehash: f4d0b87c91649c5f2f6b5823fea82d2ce355d11a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518632"
---
# <a name="compiler-warning-level-1-c4669"></a>Compilador aviso (nível 1) C4669

'cast': conversão não segura: 'class' é um serviço ou objeto de tipo de WinRT

Uma conversão contém um tempo de execução do Windows ou um tipo gerenciado. O compilador conclui a conversão, executando uma cópia bit a bit de um ponteiro para o outro, mas não fornece nenhuma outra verificação. Para resolver este aviso, não converta as classes que contêm membros gerenciados ou tipos de tempo de execução do Windows.

O exemplo a seguir gera C4669 e mostra como corrigi-lo:

```
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