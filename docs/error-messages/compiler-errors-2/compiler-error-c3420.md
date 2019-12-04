---
title: Erro do compilador C3420
ms.date: 11/04/2016
f1_keywords:
- C3420
helpviewer_keywords:
- C3420
ms.assetid: 99b53c77-f36b-4574-9199-b53111becccb
ms.openlocfilehash: 5e165a0c181bc27adebe75111050f49130305693
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756247"
---
# <a name="compiler-error-c3420"></a>Erro do compilador C3420

' finalizador ': um finalizador não pode ser virtual

Um finalizador só pode ser chamado não virtualmente de seu tipo delimitador. Portanto, é um erro para declarar um finalizador virtual.

Para obter mais informações, consulte [destruidores e finalizadores em como: definir e consumir classes e Structs (C++/CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3420.

```cpp
// C3420.cpp
// compile with: /clr /c
ref class R {
   virtual !R() {}   // C3420
};
```
