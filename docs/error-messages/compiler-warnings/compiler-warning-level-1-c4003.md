---
title: Aviso do compilador (nível 1) C4003
ms.date: 11/04/2016
f1_keywords:
- C4003
helpviewer_keywords:
- C4003
ms.assetid: 0ed1c285-4428-4c90-8131-86897e31f115
ms.openlocfilehash: 4adbffe3220060ee9d43f01cf94628f85d3991cc
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627381"
---
# <a name="compiler-warning-level-1-c4003"></a>Aviso do compilador (nível 1) C4003

parâmetros reais insuficientes para macro ' identifier '

O número de parâmetros formais na definição de macro excede o número de parâmetros reais na macro. A expansão de macro substitui o texto vazio pelos parâmetros ausentes.

O exemplo a seguir gera C4003:

```cpp
// C4003.cpp
// compile with: /WX
#define test(a,b) (a+b)

int main()
{
   int a = 1;
   int b = 2;
   a = test(b);   // C4003
   // try..
   a = test(a,b);
}
```