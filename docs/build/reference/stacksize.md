---
title: STACKSIZE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- STACKSIZE
dev_langs:
- C++
helpviewer_keywords:
- STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7d9b61febedde1a2647df6312a8588b08c6bdad7
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705556"
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