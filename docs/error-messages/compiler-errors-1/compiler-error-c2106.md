---
title: Erro do compilador C2106
ms.date: 11/04/2016
f1_keywords:
- C2106
helpviewer_keywords:
- C2106
ms.assetid: d5c91a2e-04e4-4770-8478-788b98c52a53
ms.openlocfilehash: 6a82792c8a8acfd0d397e02929a457aae8ef7050
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208926"
---
# <a name="compiler-error-c2106"></a>Erro do compilador C2106

'operator': operando esquerdo deve ser l-value

O operador deve ter um l-value como operando esquerdo.

O exemplo a seguir gera C2106:

```
// C2106.cpp
int main() {
   int a;
   1 = a;   // C2106
   a = 1;   // OK
}
```