---
title: Erro do compilador C2657
ms.date: 11/04/2016
f1_keywords:
- C2657
helpviewer_keywords:
- C2657
ms.assetid: f7cf29a9-684a-4605-9469-ecfee9ba4b03
ms.openlocfilehash: 4e2816092b3c0c210ae2c544e9bf9a823a9c5d18
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661130"
---
# <a name="compiler-error-c2657"></a>Erro do compilador C2657

' classe:: *' encontrado no início de uma instrução (você esqueceu de especificar um tipo?)

A linha começou com um identificador de ponteiro para membro.

Esse erro pode ser causado por um especificador de tipo ausente na declaração de um ponteiro para um membro.

O exemplo a seguir gera C2657:

```
// C2657.cpp
class C {};
int main() {
   C::* pmc1;        // C2657
   int C::* pmc2;   // OK
}
```