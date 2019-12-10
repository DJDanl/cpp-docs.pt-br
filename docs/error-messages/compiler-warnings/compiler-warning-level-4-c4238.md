---
title: Aviso do compilador (nível 4) C4238
ms.date: 11/04/2016
f1_keywords:
- C4238
helpviewer_keywords:
- C4238
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
ms.openlocfilehash: cc913a4f92963437347fbc708eca03c25ab9d403
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991470"
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
