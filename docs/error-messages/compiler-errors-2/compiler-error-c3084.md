---
title: Erro do compilador C3084
ms.date: 11/04/2016
f1_keywords:
- C3084
helpviewer_keywords:
- C3084
ms.assetid: 0362cb70-e24e-476f-a24d-8f5bb97c3afd
ms.openlocfilehash: 337cd7f37bf94c7a3d5cffe6b167d4661e3b0a81
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751450"
---
# <a name="compiler-error-c3084"></a>Erro do compilador C3084

' function ': um finalizador/destruidor não pode ser ' keyword '

Um finalizador ou destruidor foi declarado incorretamente.

Por exemplo, um destruidor não deve ser marcado como lacrado.  O destruidor ficará inacessível para tipos derivados.  Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md) e [destruidores e finalizadores em como: definir e consumir classes e Structs (C++/CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3084.

```cpp
// C3084.cpp
// compile with: /clr /c
ref struct R {
protected:
   !R() sealed;   // C3084
   !R() abstract;   // C3084
   !R();
};
```
