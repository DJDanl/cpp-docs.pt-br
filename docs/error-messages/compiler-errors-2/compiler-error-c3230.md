---
title: Erro do compilador C3230
ms.date: 11/04/2016
f1_keywords:
- C3230
helpviewer_keywords:
- C3230
ms.assetid: 5ec53f25-59f6-4801-81e7-7b68bf04994d
ms.openlocfilehash: 69ea279ac5e11c03f366711484ba0c250fc50225
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743309"
---
# <a name="compiler-error-c3230"></a>Erro do compilador C3230

' function ': argumento de tipo de modelo para ' template ' não pode conter um parâmetro de tipo genérico: ' param '

Os modelos são instanciados no momento da compilação, mas os genéricos são instanciados em tempo de execução. Portanto, não é possível gerar código genérico que possa chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico é finalmente conhecido.

O exemplo a seguir gera C3230:

```cpp
// C3230.cpp
// compile with: /clr /LD
template <class S>
void f(S t);

generic <class U>
ref class C {
   void f1(U x) {
      f(x);   // C3230
   }
};
```
