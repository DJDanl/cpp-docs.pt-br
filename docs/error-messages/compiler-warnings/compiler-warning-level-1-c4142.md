---
title: Compilador aviso (nível 1) C4142
ms.date: 11/04/2016
f1_keywords:
- C4142
helpviewer_keywords:
- C4142
ms.assetid: 1fdfc3dc-60a2-4f00-b133-20e400f9b7a6
ms.openlocfilehash: 762f52c9f051a660cce68d424e02fc45422376e2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456076"
---
# <a name="compiler-warning-level-1-c4142"></a>Compilador aviso (nível 1) C4142

redefinição benigna de tipo

Um tipo é redefinido de forma que não tem efeito sobre o código gerado.

Para corrigir verificando as possíveis causas:

- Uma função de membro de uma classe derivada tem um tipo de retorno diferente da função de membro correspondente da classe base.

- Um tipo definido com o `typedef` comando é redefinido com o uso de uma sintaxe diferente.

O exemplo a seguir gera C4142:

```
// C4142.c
// compile with: /W1
float X2;
X2 = 2.0 + 1.0;   // C4142

int main() {
   float X2;
   X2 = 2.0 + 1.0;   // OK
}
```