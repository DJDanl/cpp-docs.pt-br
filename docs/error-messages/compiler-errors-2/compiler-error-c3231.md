---
title: Erro do compilador C3231
ms.date: 11/04/2016
f1_keywords:
- C3231
helpviewer_keywords:
- C3231
ms.assetid: fe5dc352-e634-45fa-9534-3da176294c98
ms.openlocfilehash: 653f0b18737f937483f5d3e79cb99c9a55160c19
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173841"
---
# <a name="compiler-error-c3231"></a>Erro do compilador C3231

'arg': argumento de tipo de modelo não é possível usar um parâmetro de tipo genérico

Modelos são instanciados em tempo de compilação, mas os genéricos são instanciados em tempo de execução. Portanto, não é possível gerar código genérico que pode chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico, por fim, é conhecido.

O exemplo a seguir gera C3231:

```
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