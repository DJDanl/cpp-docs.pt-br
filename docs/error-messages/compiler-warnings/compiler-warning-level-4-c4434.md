---
title: Compilador aviso (nível 4) C4434
ms.date: 11/04/2016
f1_keywords:
- C4434
helpviewer_keywords:
- C4434
ms.assetid: 24b8785e-353a-4c37-8bed-ed61001a871d
ms.openlocfilehash: 6a7d760a7d192c7e0a7bd5e16f77efe1a4099c31
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391485"
---
# <a name="compiler-warning-level-4-c4434"></a>Compilador aviso (nível 4) C4434

um construtor de classe deve possuir acessibilidade private; alterando para acesso privado

C4434 indica que o compilador alterou a acessibilidade de um construtor estático. Construtores estáticos devem ter acessibilidade privada, pois eles só devem ser chamado pelo common language runtime. Para obter mais informações, consulte [construtores estáticos](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Static_constructors).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4434.

```
// C4434.cpp
// compile with: /W4 /c /clr
public ref struct R {
   static R(){}   // C4434
};
```