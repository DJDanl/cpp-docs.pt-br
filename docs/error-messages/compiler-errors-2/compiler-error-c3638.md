---
title: Erro do compilador C3638
ms.date: 11/04/2016
f1_keywords:
- C3638
helpviewer_keywords:
- C3638
ms.assetid: 8d8bc5ca-75aa-480e-b6b6-3178fab51b1d
ms.openlocfilehash: 33bb248faf946c39543de4a14a44e2ebbda49880
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58775225"
---
# <a name="compiler-error-c3638"></a>Erro do compilador C3638

'operator': a conversão boxing padrão e os operadores de conversão unboxing não podem ser redefinidos

O compilador define um operador de conversão para cada classe gerenciada para dar suporte à conversão boxing implícita. Este operador não pode ser redefinido.

Para obter mais informações, consulte [conversão Boxing implícita](../../extensions/boxing-cpp-component-extensions.md).

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