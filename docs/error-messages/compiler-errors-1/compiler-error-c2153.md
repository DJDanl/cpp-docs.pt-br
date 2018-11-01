---
title: Erro do compilador C2153
ms.date: 11/04/2016
f1_keywords:
- C2153
helpviewer_keywords:
- C2153
ms.assetid: cfc50cb7-9a0f-4b5b-879a-d419c99f7be1
ms.openlocfilehash: eeb7da509ffb1b8c408763c79d471586eb94f383
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50605927"
---
# <a name="compiler-error-c2153"></a>Erro do compilador C2153

constantes hex devem possuir pelo menos um dígito hexadecimal

Constantes hexadecimais 0 x, 0x e \x não são válidos. Pelo menos um dígito hexadecimal deve seguir x ou X.

O exemplo a seguir gera C2153:

```
// C2153.cpp
int main() {
   int a= 0x;    // C2153
   int b= 0xA;   // OK
}
```