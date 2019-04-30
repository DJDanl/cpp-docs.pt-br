---
title: Compilador aviso (nível 4) C4238
ms.date: 11/04/2016
f1_keywords:
- C4238
helpviewer_keywords:
- C4238
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
ms.openlocfilehash: c5ffa07b06f010d10edc14aa7576bb614aa9dd04
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401027"
---
# <a name="compiler-warning-level-4-c4238"></a>Compilador aviso (nível 4) C4238

extensão não padrão usada: classe rvalue usada como lvalue

Para compatibilidade com versões anteriores do Visual C++, extensões da Microsoft (**/Ze**) permitem que você use um tipo de classe como um rvalue em um contexto que implicitamente ou explicitamente usa seu endereço. Em alguns casos, como no exemplo abaixo, isso pode ser perigoso.

## <a name="example"></a>Exemplo

```
// C4238.cpp
// compile with: /W4 /c
struct C {
   C() {}
};

C * pC = &C();   // C4238
```

Esse uso causa um erro em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).