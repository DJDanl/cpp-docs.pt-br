---
title: Erro das Ferramentas de Vinculador LNK2013
ms.date: 11/04/2016
f1_keywords:
- LNK2013
helpviewer_keywords:
- LNK2013
ms.assetid: 21408e2d-3f56-4d1f-a031-00df70785ed4
ms.openlocfilehash: 6ad3f40f06e64422b393edb457a0dcf419828b6f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194740"
---
# <a name="linker-tools-error-lnk2013"></a>Erro das Ferramentas de Vinculador LNK2013

estouro no conserto do tipo de correção. O ' nome do símbolo ' de destino está fora do intervalo

O vinculador não pode se ajustar ao endereço ou deslocamento necessário para a instrução especificada porque o símbolo de destino está muito longe do local da instrução.

Você pode resolver esse problema criando várias imagens ou usando a opção [/Order](../../build/reference/order-put-functions-in-order.md) para que a instrução e o destino fiquem mais próximos.

Quando o nome do símbolo é um símbolo definido pelo usuário (e não um símbolo gerado pelo compilador), você também pode tentar as seguintes ações para resolver o erro:

- Altere a função estática para não estático.

- Renomeie a seção de código que contém a função estática como sendo a mesma do chamador.

Use `DUMPBIN /SYMBOLS`para ver se uma função é estática.
