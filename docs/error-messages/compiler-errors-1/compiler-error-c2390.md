---
title: Erro do compilador C2390
ms.date: 11/04/2016
f1_keywords:
- C2390
helpviewer_keywords:
- C2390
ms.assetid: 06b749ee-d072-4db1-b229-715f2c0728b5
ms.openlocfilehash: 89f6ebb02326413e8dca67d333e555321da4e645
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595865"
---
# <a name="compiler-error-c2390"></a>Erro do compilador C2390

'identifier': classe de armazenamento incorreta 'especificador'

A classe de armazenamento não é válida para o identificador de escopo global. A classe de armazenamento padrão é usada no lugar de classe inválida.

Possíveis resoluções:

- Se o identificador é uma função, declare-o com `extern` armazenamento.

- Se o identificador é um parâmetro formal ou uma variável local, declare-o com o armazenamento automático.

- Se o identificador é uma variável global, declare-o com nenhuma classe de armazenamento (armazenamento automático).

## <a name="example"></a>Exemplo

- O exemplo a seguir gera C2390:

```
// C2390.cpp
register int i;   // C2390

int main() {
   register int j;   // OK
}
```