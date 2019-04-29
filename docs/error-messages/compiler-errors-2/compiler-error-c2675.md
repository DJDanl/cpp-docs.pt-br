---
title: Erro do compilador C2675
ms.date: 11/04/2016
f1_keywords:
- C2675
helpviewer_keywords:
- C2675
ms.assetid: 4b92a12b-bff8-4dd5-a109-620065fc146c
ms.openlocfilehash: aea79509d0e1ae5c31fcf0cf369c28af39a21154
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62367922"
---
# <a name="compiler-error-c2675"></a>Erro do compilador C2675

unário 'operator': 'type' não define este operador ou uma conversão para um tipo aceitável ao operador pré-definido

C2675 também podem ocorrer ao usar um operador unário, e o tipo não define o operador ou uma conversão para um tipo aceitável ao operador pré-definido. Para usar o operador, você deve sobrecarregá-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2675.

```
// C2675.cpp
struct C {
   C(){}
} c;

struct D {
   D(){}
   void operator-(){}
} d;

int main() {
   -c;   // C2675
   -d;   // OK
}
```