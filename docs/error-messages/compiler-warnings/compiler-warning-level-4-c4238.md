---
title: Aviso do compilador (nível 4) C4238
ms.date: 11/04/2016
f1_keywords:
- C4238
helpviewer_keywords:
- C4238
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
ms.openlocfilehash: 982457ded987f6aee4f2891bbb7d9103b830cc99
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541783"
---
# <a name="compiler-warning-level-4-c4238"></a>Aviso do compilador (nível 4) C4238

extensão não padrão usada: classe rvalue usada como lvalue

Para compatibilidade com versões anteriores do Visual C++, o Microsoft Extensions ( **/ze**) permite que você use um tipo de classe como um Rvalue em um contexto que usa implicitamente ou explicitamente seu endereço. Em alguns casos, como o exemplo a seguir, isso pode ser perigoso.

## <a name="example"></a>Exemplo

```cpp
// C4238.cpp
// compile with: /W4 /c
struct C {
   C() {}
};

C * pC = &C();   // C4238
```

Esse uso causa um erro em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).