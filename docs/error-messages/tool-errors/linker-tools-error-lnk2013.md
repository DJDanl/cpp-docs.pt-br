---
title: Ferramentas de vinculador LNK2013 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2013
dev_langs:
- C++
helpviewer_keywords:
- LNK2013
ms.assetid: 21408e2d-3f56-4d1f-a031-00df70785ed4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9320b9ead0276b6fb5e1b9773260049a01520e12
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299845"
---
# <a name="linker-tools-error-lnk2013"></a>Erro das Ferramentas de Vinculador LNK2013
estouro de conserto de tipo de correção. O destino 'nome do símbolo' está fora do intervalo  
  
 O vinculador não pode ajustar o endereço necessário ou o deslocamento em determinada instrução porque o símbolo de destino é muito distante do local da instrução.  
  
 Você pode resolver esse problema criando várias imagens, ou usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção para a instrução e o destino estiverem mais juntos.  
  
 Quando o nome do símbolo é um símbolo definido pelo usuário (e não um símbolo gerado pelo compilador), você também pode tentar as seguintes ações para resolver o erro:  
  
-   Altere a função estática para ser não estático.  
  
-   Renomeie a seção de código que contém a função estática para ser o mesmo que o chamador.  
  
 Use `DUMPBIN /SYMBOLS`para ver se uma função é estática.