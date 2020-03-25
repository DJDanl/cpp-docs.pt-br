---
title: Instrução de expressão
ms.date: 11/04/2016
helpviewer_keywords:
- statements [C++], expression
- expression statements
ms.assetid: 547d7f7a-58be-4ffc-a4b3-d64c7ae7538c
ms.openlocfilehash: 2f12bbbafd9be50f851e36f472098431f9ac0d5d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188994"
---
# <a name="expression-statement"></a>Instrução de expressão

Instruções de expressão fazem com as expressões sejam avaliadas. Nenhuma transferência de controle ou iteração ocorre como resultado de uma instrução de expressão.

A sintaxe da instrução de expressão é simplesmente

## <a name="syntax"></a>Sintaxe

```
[expression ] ;
```

## <a name="remarks"></a>Comentários

Todas as expressões em uma instrução de expressão são avaliadas e todos os efeitos colaterais são concluídos antes que a próxima instrução seja executada. As instruções de expressão mais comuns são atribuições e chamadas de função.  Como a expressão é opcional, um ponto-e-vírgula sozinho é considerado uma instrução de expressão vazia, conhecida como instrução [NULL](../cpp/null-statement.md) .

## <a name="see-also"></a>Confira também

[Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)
