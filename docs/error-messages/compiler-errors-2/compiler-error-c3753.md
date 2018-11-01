---
title: Erro do compilador C3753
ms.date: 11/04/2016
f1_keywords:
- C3753
helpviewer_keywords:
- C3753
ms.assetid: a5b99e28-796c-4107-a673-97c2ae3bb2b9
ms.openlocfilehash: b6b1e8c3241a778b29045e734fffebb663554e62
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498365"
---
# <a name="compiler-error-c3753"></a>Erro do compilador C3753

uma propriedade de generic não é permitida

Listas de parâmetro genérico podem aparecer somente em funções, estruturas ou classes gerenciadas.

Para obter mais informações, consulte [genéricos](../../windows/generics-cpp-component-extensions.md) e [propriedade](../../windows/property-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3753.

```
// C3753.cpp
// compile with: /clr /c
ref struct A {
   generic <typename T>
   property int i;   // C3753 error
};
```