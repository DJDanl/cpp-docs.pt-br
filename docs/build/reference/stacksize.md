---
title: STACKSIZE
ms.date: 11/04/2016
f1_keywords:
- STACKSIZE
helpviewer_keywords:
- STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
ms.openlocfilehash: 2d27b4fd596098f4abc5bb0d804d87bd08f70a60
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62318349"
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
