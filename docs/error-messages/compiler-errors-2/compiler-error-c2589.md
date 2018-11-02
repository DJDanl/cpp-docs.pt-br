---
title: Erro do compilador C2589
ms.date: 11/04/2016
f1_keywords:
- C2589
helpviewer_keywords:
- C2589
ms.assetid: 1d7942c7-8a81-4bb4-b272-76a0019e8513
ms.openlocfilehash: 18d8f7130c34f5e1e33bc7aa9b9463f50c243045
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50587299"
---
# <a name="compiler-error-c2589"></a>Erro do compilador C2589

'identifier': token inválido no lado direito de ':: '

Se uma classe, estrutura ou união nome aparece à esquerda do operador de resolução de escopo (dois-pontos duplo), o token à direita deve ser uma classe, estrutura ou membro de união. Caso contrário, qualquer identificador global pode aparecer à direita.

O operador de resolução de escopo não pode ser sobrecarregado.

O exemplo a seguir gera C2589:

```
// C2589.cpp
void Test(){}
class A {};
void operator :: ();   // C2589

int main() {
   ::Test();
}
```