---
title: Erro do compilador C3231
ms.date: 11/04/2016
f1_keywords:
- C3231
helpviewer_keywords:
- C3231
ms.assetid: fe5dc352-e634-45fa-9534-3da176294c98
ms.openlocfilehash: 3bc8293f0cbed7c2093cfe9dd0513b690b8c76f0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750332"
---
# <a name="compiler-error-c3231"></a>Erro do compilador C3231

' arg ': argumento de tipo de template não pode usar um parâmetro de tipo genérico

Os modelos são instanciados no momento da compilação, mas os genéricos são instanciados em tempo de execução. Portanto, não é possível gerar código genérico que possa chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico é finalmente conhecido.

O exemplo a seguir gera C3231:

```cpp
// C3231.cpp
// compile with: /clr /LD
template <class T> class A;

generic <class T>
ref class C {
   void f() {
      A<T> a;   // C3231
   }
};
```
