---
title: STACKSIZE
ms.date: 11/04/2016
f1_keywords:
- STACKSIZE
helpviewer_keywords:
- STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
ms.openlocfilehash: de2aa99375f588d682b714632590ba8e0db8ddcb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50597217"
---
# <a name="stacksize"></a>STACKSIZE

Define o tamanho da pilha, em bytes.

```
STACKSIZE reserve[,commit]
```

## <a name="remarks"></a>Comentários

Uma maneira equivalente para definir a pilha é com o [alocações da pilha](../../build/reference/stack-stack-allocations.md) (/Stack) opção. Consulte a documentação sobre essa opção para obter detalhes o *reservar* e `commit` argumentos.

Essa opção não tem nenhum efeito em DLLs.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)