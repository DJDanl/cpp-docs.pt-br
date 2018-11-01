---
title: Erro do compilador C2695
ms.date: 11/04/2016
f1_keywords:
- C2695
helpviewer_keywords:
- C2695
ms.assetid: 3f6f2091-c38b-40ea-ab6c-f1846f5702d7
ms.openlocfilehash: 08f74bf635324ed9a05c13ecf532862d58e4f0b1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50429413"
---
# <a name="compiler-error-c2695"></a>Erro do compilador C2695

'function1': função virtual de substituição difere de 'function2' apenas pela convenção de chamada

A assinatura de uma função em uma classe derivada não pode substituir uma função em uma classe base e alterar a convenção de chamada.

O exemplo a seguir gera C2695:

```
// C2695.cpp
class C {
   virtual void __fastcall func();
};

class D : public C {
   virtual void __clrcall func();   // C2695
};
```