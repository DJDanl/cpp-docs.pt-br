---
title: Erro do compilador C2929
ms.date: 11/04/2016
f1_keywords:
- C2929
helpviewer_keywords:
- C2929
ms.assetid: 11134027-6adc-4733-b6bd-b94486bd1933
ms.openlocfilehash: d420e3f6470a94874549fadc8cd90e4dac20fe6e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760987"
---
# <a name="compiler-error-c2929"></a>Erro do compilador C2929

' identifier ': instanciação explícita; Não é possível forçar explicitamente e suprimir a instanciação do membro de classe de template

Você não pode instanciar explicitamente um identificador ao impedir que ele seja instanciado.

O exemplo a seguir gera C2929:

```cpp
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
