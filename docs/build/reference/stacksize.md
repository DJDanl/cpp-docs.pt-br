---
title: STACKSIZE
ms.date: 11/04/2016
f1_keywords:
- STACKSIZE
helpviewer_keywords:
- STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
ms.openlocfilehash: 5f0c23ad8b8d81f888616042ee5d6ba5bc63bd44
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57412868"
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
