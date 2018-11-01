---
title: Erro do compilador C3653
ms.date: 11/04/2016
f1_keywords:
- C3653
helpviewer_keywords:
- C3653
ms.assetid: 316549d7-f7ef-4578-a2ba-57adc8aac527
ms.openlocfilehash: d7936303dab4fbb273a01f98def5b9af99f89dac
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477617"
---
# <a name="compiler-error-c3653"></a>Erro do compilador C3653

'function': não pode ser usado como uma substituição nomeada: uma função que está sendo substituída não foi encontrada; Você esqueceu de nomear a função explicitamente, usando um:: operador?

Uma substituição explícita especificada de uma função que não foi encontrada em qualquer interface. Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).

O exemplo a seguir gera C3653:

```
// C3653.cpp
// compile with: /clr
public interface struct I {
   void h();
};

public ref struct X : public I {
   virtual void f() new sealed = J {};   // C3653 no J in scope
   virtual void g() {}   // OK
   virtual void h() new sealed = I::h {};   // OK
};
```