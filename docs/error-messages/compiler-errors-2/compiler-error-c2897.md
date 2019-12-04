---
title: Erro do compilador C2897
ms.date: 11/04/2016
f1_keywords:
- C2897
helpviewer_keywords:
- C2897
ms.assetid: a88349e2-823f-42a0-8660-0653b677afa4
ms.openlocfilehash: 1433faade0a41ad8b63a3b40cb5d02f724bde658
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760768"
---
# <a name="compiler-error-c2897"></a>Erro do compilador C2897

um destruidor/finalizador não pode ser um modelo de função

Os destruidores ou finalizadores não podem ser sobrecarregados, portanto, a declaração de um destruidor como um modelo (que poderia definir um conjunto de destruidores) não é permitida.

O exemplo a seguir gera C2897:

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2897.

```cpp
// C2897.cpp
// compile with: /c
class X {
public:
   template<typename T> ~X() {}   // C2897
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2897.

```cpp
// C2897_b.cpp
// compile with: /c /clr
ref struct R2 {
protected:
   template<typename T> !R2(){}   // C2897 error
};
```
