---
title: Erro do compilador C3420
ms.date: 11/04/2016
f1_keywords:
- C3420
helpviewer_keywords:
- C3420
ms.assetid: 99b53c77-f36b-4574-9199-b53111becccb
ms.openlocfilehash: 3db109598ce0741ca34a230d8925994543bcb5ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182451"
---
# <a name="compiler-error-c3420"></a>Erro do compilador C3420

'finalizador': um finalizador não pode ser virtual

Um finalizador só pode ser chamado sem praticamente do seu tipo delimitador. Portanto, é um erro declarar um finalizador virtual.

Para obter mais informações, consulte [destruidores e finalizadores em como: Definir e consumir classes e structs (C++ /CLI CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3420.

```
// C3420.cpp
// compile with: /clr /c
ref class R {
   virtual !R() {}   // C3420
};
```