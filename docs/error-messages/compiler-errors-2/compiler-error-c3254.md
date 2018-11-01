---
title: Erro do compilador C3254
ms.date: 11/04/2016
f1_keywords:
- C3254
helpviewer_keywords:
- C3254
ms.assetid: 93427b10-fa72-4e43-80d1-1a6e122f9f40
ms.openlocfilehash: 7e051c6c44d3b85f6f3faaf5380ecf54cba5d73c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50470662"
---
# <a name="compiler-error-c3254"></a>Erro do compilador C3254

'substituição explícita': classe contém substituição explícita 'override', mas não deriva de uma interface que contém a declaração da função

Quando você [substituir explicitamente](../../cpp/explicit-overrides-cpp.md) um método, a classe que contém a substituição deve derivam, direta ou indiretamente, do tipo que contém a função que você está substituindo.

O exemplo a seguir gera C3254:

```
// C3254.cpp
__interface I
{
   void f();
};

__interface I1 : I
{
};

struct A /* : I1 */
{
   void I1::f()
   {   // C3254, uncomment : I1 to resolve this C3254
   }
};

int main()
{
}
```