---
title: STACKSIZE
ms.date: 11/04/2016
f1_keywords:
- STACKSIZE
helpviewer_keywords:
- STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
ms.openlocfilehash: 2d27b4fd596098f4abc5bb0d804d87bd08f70a60
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57814313"
---
# <a name="stacksize"></a>STACKSIZE

Define o tamanho da pilha, em bytes.

```
STACKSIZE reserve[,commit]
```

## <a name="remarks"></a>Comentários

Uma maneira equivalente para definir a pilha é com o [alocações da pilha](stack-stack-allocations.md) (/Stack) opção. Consulte a documentação sobre essa opção para obter detalhes o *reservar* e `commit` argumentos.

Essa opção não tem nenhum efeito em DLLs.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)
