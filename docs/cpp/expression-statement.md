---
title: Instrução de expressão
ms.date: 11/04/2016
helpviewer_keywords:
- statements [C++], expression
- expression statements
ms.assetid: 547d7f7a-58be-4ffc-a4b3-d64c7ae7538c
ms.openlocfilehash: 2973c3e0a1cd59edfc7ef1e771454b780da23cf9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562442"
---
# <a name="expression-statement"></a>Instrução de expressão

Instruções de expressão fazem com as expressões sejam avaliadas. Nenhuma transferência de controle ou iteração ocorre como resultado de uma instrução de expressão.

A sintaxe da instrução de expressão é simplesmente

## <a name="syntax"></a>Sintaxe

```
[expression ] ;
```

## <a name="remarks"></a>Comentários

Todas as expressões em uma instrução de expressão são avaliadas e todos os efeitos colaterais são concluídos antes que a próxima instrução seja executada. As instruções de expressão mais comuns são atribuições e chamadas de função.  Uma vez que a expressão é opcional, um ponto e vírgula sozinho é considerado uma instrução expression vazia, conhecida como o [nulo](../cpp/null-statement.md) instrução.

## <a name="see-also"></a>Consulte também

[Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)