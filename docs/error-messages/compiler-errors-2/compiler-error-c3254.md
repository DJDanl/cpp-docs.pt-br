---
title: Erro do compilador C3254 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3254
dev_langs:
- C++
helpviewer_keywords:
- C3254
ms.assetid: 93427b10-fa72-4e43-80d1-1a6e122f9f40
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e9e42071c55ef3c7a4fc950b1b25656cf68d4024
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081176"
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