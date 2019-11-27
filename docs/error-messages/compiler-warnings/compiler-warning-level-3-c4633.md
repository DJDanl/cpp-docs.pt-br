---
title: Aviso do compilador (nível 3) C4633
ms.date: 11/04/2016
f1_keywords:
- C4633
helpviewer_keywords:
- C4633
ms.assetid: 6d76f268-ba8c-448b-8e83-b903a18b583b
ms.openlocfilehash: ea0a26e34ac72be1e8a9fb4cc7dd913ba7d1a742
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74189161"
---
# <a name="compiler-warning-level-3-c4633"></a>Aviso do compilador (nível 3) C4633

Destino do comentário do documento XML: erro: motivo

Um nome passado para a marca [\<param >](../../build/reference/param-visual-cpp.md) não foi encontrado pelo compilador.

O exemplo a seguir gera C4633:

```cpp
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