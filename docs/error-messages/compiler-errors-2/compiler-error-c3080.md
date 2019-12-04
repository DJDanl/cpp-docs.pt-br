---
title: Erro do compilador C3080
ms.date: 11/04/2016
f1_keywords:
- C3080
helpviewer_keywords:
- C3080
ms.assetid: ff62a3f7-9b3b-44bd-b8d9-f3a8e5354560
ms.openlocfilehash: 74a5f33a3b6b6524b53b15067c722c19c0e3f04e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756702"
---
# <a name="compiler-error-c3080"></a>Erro do compilador C3080

' finalizer_function ': um finalizador não pode ter um especificador de classe de armazenamento

Para obter mais informações, consulte [destruidores e finalizadores em como: definir e consumir classes e Structs (C++/CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3080.

```cpp
// C3080.cpp
// compile with: /clr /c
ref struct rs {
protected:
   static !rs(){}   // C3080
   !rs(){}   // OK
};
```
