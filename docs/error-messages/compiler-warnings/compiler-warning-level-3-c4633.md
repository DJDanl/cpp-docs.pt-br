---
title: Compilador aviso (nível 3) C4633
ms.date: 11/04/2016
f1_keywords:
- C4633
helpviewer_keywords:
- C4633
ms.assetid: 6d76f268-ba8c-448b-8e83-b903a18b583b
ms.openlocfilehash: f1a4af399859c28f13432a344ae3dd921f9e1696
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50459807"
---
# <a name="compiler-warning-level-3-c4633"></a>Compilador aviso (nível 3) C4633

Destino de comentário de documento XML: erro: motivo

Um nome passado para o [ \<param >](../../ide/param-visual-cpp.md) marca não foi encontrada pelo compilador.

O exemplo a seguir gera C4633:

```
// C4633.cpp
// compile with: /clr /doc /LD /W3

/// Text for class MyClass.
public ref class MyClass {
   // C4633 remove line for Int3
   /// <param name="Int1">Used to indicate status.</param>
   /// <param name="Int3">Used to indicate status.</param>
   void MyMethod(int Int1) {
      Int1 = 0;
      Int1++;
   }
};
```