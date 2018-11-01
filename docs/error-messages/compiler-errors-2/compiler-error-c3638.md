---
title: Erro do compilador C3638
ms.date: 11/04/2016
f1_keywords:
- C3638
helpviewer_keywords:
- C3638
ms.assetid: 8d8bc5ca-75aa-480e-b6b6-3178fab51b1d
ms.openlocfilehash: 8b1ef7f4cb38653f0ccdfae5684eb2907a735af7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50486876"
---
# <a name="compiler-error-c3638"></a>Erro do compilador C3638

'operator': a conversão boxing padrão e os operadores de conversão unboxing não podem ser redefinidos

O compilador define um operador de conversão para cada classe gerenciada para dar suporte à conversão boxing implícita. Este operador não pode ser redefinido.

Para obter mais informações, consulte [conversão Boxing implícita](../../windows/boxing-cpp-component-extensions.md).

O exemplo a seguir gera C3638:

```
// C3638.cpp
// compile with: /clr
value struct V {
   V(){}
   static operator V^(V);   // C3638
};

int main() {
   V myV;
   V ^ pmyV = myV;   // operator supports implicit boxing
}
```