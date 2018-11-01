---
title: Erro das Ferramentas de Vinculador LNK2013
ms.date: 11/04/2016
f1_keywords:
- LNK2013
helpviewer_keywords:
- LNK2013
ms.assetid: 21408e2d-3f56-4d1f-a031-00df70785ed4
ms.openlocfilehash: 4d932a89f1b0bde27f6de2f84b2ed103dab1b1b0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50620721"
---
# <a name="linker-tools-error-lnk2013"></a>Erro das Ferramentas de Vinculador LNK2013

estouro de conserto de tipo de correção. Destino de 'nome do símbolo' está fora do intervalo

O vinculador pode não cabe o endereço necessário ou offset na instrução fornecida porque o símbolo de destino está muito longe do local da instrução.

Você pode resolver esse problema criando várias imagens ou usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção para que a instrução e o destino estiverem mais juntos.

Quando o nome do símbolo é um símbolo definido pelo usuário (e não é um símbolo gerado pelo compilador), você também pode tentar as seguintes ações para resolver o erro:

- Altere a função estática para ser não estático.

- Renomeie a seção de código que contém a função estática para ser o mesmo que o chamador.

Use `DUMPBIN /SYMBOLS`, para ver se uma função é estática.