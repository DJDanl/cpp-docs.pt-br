---
title: Erro do compilador C2897
ms.date: 11/04/2016
f1_keywords:
- C2897
helpviewer_keywords:
- C2897
ms.assetid: a88349e2-823f-42a0-8660-0653b677afa4
ms.openlocfilehash: 264ad52a10c6cf19d1105561f1140cf2d3e2f8e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50431025"
---
# <a name="compiler-error-c2897"></a>Erro do compilador C2897

um destruidor/finalizador não pode ser um modelo de função

Os destruidores ou os finalizadores não podem ser sobrecarregados, portanto, não é permitido declarar um destruidor como um modelo (o que seria definir um conjunto de destruidores).

O exemplo a seguir gera C2897:

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2897.

```
// C2897.cpp
// compile with: /c
class X {
public:
   template<typename T> ~X() {}   // C2897
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2897.

```
// C2897_b.cpp
// compile with: /c /clr
ref struct R2 {
protected:
   template<typename T> !R2(){}   // C2897 error
};
```