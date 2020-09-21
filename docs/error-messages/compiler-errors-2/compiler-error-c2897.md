---
title: Erro do compilador C2897
ms.date: 11/04/2016
f1_keywords:
- C2897
helpviewer_keywords:
- C2897
ms.assetid: a88349e2-823f-42a0-8660-0653b677afa4
ms.openlocfilehash: 22e63ce92a6d526f08e68bedb35de104be339dc3
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743367"
---
# <a name="compiler-error-c2897"></a>Erro do compilador C2897

um destruidor/finalizador não pode ser um modelo de função

Os destruidores ou finalizadores não podem ser sobrecarregados, portanto, a declaração de um destruidor como um modelo (que poderia definir um conjunto de destruidores) não é permitida.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2897.

```cpp
// C2897.cpp
// compile with: /c
class X {
public:
   template<typename T> ~X() {}   // C2897
};
```

O exemplo a seguir gera C2897.

```cpp
// C2897_b.cpp
// compile with: /c /clr
ref struct R2 {
protected:
   template<typename T> !R2(){}   // C2897 error
};
```
