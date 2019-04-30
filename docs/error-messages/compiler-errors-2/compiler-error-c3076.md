---
title: Erro do compilador C3076
ms.date: 11/04/2016
f1_keywords:
- C3076
helpviewer_keywords:
- C3076
ms.assetid: 8a87b3e4-2c17-4b87-9622-ef0962d6a34e
ms.openlocfilehash: ac9afdfc11a13dd667b06289c73332593a4d884e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406646"
---
# <a name="compiler-error-c3076"></a>Erro do compilador C3076

'instance': não é possível inserir uma instância de um tipo de referência, 'type', em um tipo nativo

Um tipo nativo não pode conter uma instância de um tipo CLR.

Para obter mais informações, consulte [semântica da pilha do C++ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3076.

```
// C3076.cpp
// compile with: /clr /c
ref struct U {};

struct V {
   U y;   // C3076
};

ref struct W {
   U y;   // OK
};
```