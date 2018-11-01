---
title: Erro do compilador C2929
ms.date: 11/04/2016
f1_keywords:
- C2929
helpviewer_keywords:
- C2929
ms.assetid: 11134027-6adc-4733-b6bd-b94486bd1933
ms.openlocfilehash: fe2a56f7722c70c11e980fb6ee59230ffd056c5f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658803"
---
# <a name="compiler-error-c2929"></a>Erro do compilador C2929

'identifier': instanciação explícita; não é possível forçar explicitamente e suprimir instanciação de membro de classe de modelo

Você explicitamente não é possível instanciar um identificador enquanto impede que ele seja instanciado.

O exemplo a seguir gera C2929:

```
// C2929.cpp
// compile with: /c
template<typename T>
class A {
public:
   A() {}
};

template A<int>::A();

extern template A<int>::A();   // C2929
```