---
title: Ferramentas de vinculador LNK2013 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2013
dev_langs:
- C++
helpviewer_keywords:
- LNK2013
ms.assetid: 21408e2d-3f56-4d1f-a031-00df70785ed4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8cf88f768f05eee06ae8ffaa66f8de5a9c443f82
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2013"></a>Erro das Ferramentas de Vinculador LNK2013
estouro de conserto de tipo de correção. O destino 'nome do símbolo' está fora do intervalo  
  
 O vinculador não pode ajustar o endereço necessário ou o deslocamento em determinada instrução porque o símbolo de destino é muito distante do local da instrução.  
  
 Você pode resolver esse problema criando várias imagens, ou usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção para a instrução e o destino estiverem mais juntos.  
  
 Quando o nome do símbolo é um símbolo definido pelo usuário (e não um símbolo gerado pelo compilador), você também pode tentar as seguintes ações para resolver o erro:  
  
-   Altere a função estática para ser não estático.  
  
-   Renomeie a seção de código que contém a função estática para ser o mesmo que o chamador.  
  
 Use `DUMPBIN /SYMBOLS`para ver se uma função é estática.