---
title: Compilador aviso (nível 1) C4087
ms.date: 11/04/2016
f1_keywords:
- C4087
helpviewer_keywords:
- C4087
ms.assetid: 546e4d57-5c8e-422c-8ef1-92657336dad5
ms.openlocfilehash: 84d24d95053b962c1776dc18576e4ed236b63469
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643710"
---
# <a name="compiler-warning-level-1-c4087"></a>Compilador aviso (nível 1) C4087

'function': declarado com lista de parâmetros 'void'

A declaração de função não possui parâmetros formais, mas a chamada de função tem parâmetros reais. Parâmetros adicionais são passados de acordo com a convenção de chamada da função.

Esse aviso é para o compilador C.

## <a name="example"></a>Exemplo

```
// C4087.c
// compile with: /W1
int f1( void ) {
}

int main() {
   f1( 10 );   // C4087
}
```