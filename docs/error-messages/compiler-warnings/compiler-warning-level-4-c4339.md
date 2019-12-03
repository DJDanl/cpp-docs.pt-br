---
title: Aviso do compilador (nível 4) C4339
ms.date: 11/04/2016
f1_keywords:
- C4339
helpviewer_keywords:
- C4339
ms.assetid: 5b83353d-7777-4afb-8476-3c368349028c
ms.openlocfilehash: fffdaa255f6b8f2259488df610f163bebf8d6dec
ms.sourcegitcommit: d0504e2337bb671e78ec6dd1c7b05d89e7adf6a7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/02/2019
ms.locfileid: "74683286"
---
# <a name="compiler-warning-level-4-c4339"></a>Aviso do compilador (nível 4) C4339

' type ': uso de tipo indefinido detectado em metadados do WinRT ou CLR-o uso desse tipo pode levar a uma exceção de tempo de execução

Um tipo não foi definido no código que foi compilado para Windows Runtime ou Common Language Runtime. Defina o tipo para evitar uma possível exceção de tempo de execução.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4339 e mostra como corrigi-lo:

```cpp
// C4339.cpp
// compile with: /W4 /clr /c
// C4339 expected
#pragma warning(default : 4339)

// Delete the following line to resolve.
class A;

// Uncomment the following line to resolve.
// class A{};

class X {
public:
   X() {}

   virtual A *mf() {
      return 0;
   }
};

X * f() {
   return new X();
}
```