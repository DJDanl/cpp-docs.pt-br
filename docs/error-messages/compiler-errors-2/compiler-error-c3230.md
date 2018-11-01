---
title: Erro do compilador C3230
ms.date: 11/04/2016
f1_keywords:
- C3230
helpviewer_keywords:
- C3230
ms.assetid: 5ec53f25-59f6-4801-81e7-7b68bf04994d
ms.openlocfilehash: a4d5edeb5898a57b99839b7e044f909cea1ec199
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428243"
---
# <a name="compiler-error-c3230"></a>Erro do compilador C3230

'function': argumento de tipo de modelo para 'template' não pode conter um parâmetro de tipo genérico: 'param'

Modelos são instanciados em tempo de compilação, mas os genéricos são instanciados em tempo de execução. Portanto, não é possível gerar código genérico que pode chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico, por fim, é conhecido.

O exemplo a seguir gera C3230:

```
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