---
title: Ferramentas de vinculador LNK2013 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2013
dev_langs:
- C++
helpviewer_keywords:
- LNK2013
ms.assetid: 21408e2d-3f56-4d1f-a031-00df70785ed4
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 36c569ee49fa8509468dc51ef47b42207c8da45a
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2013"></a>Erro das Ferramentas de Vinculador LNK2013
estouro de correção de tipo de correção. Nome do símbolo de destino está fora do intervalo  
  
 O vinculador não pode se encaixa o endereço necessário ou deslocamento determinada instrução porque o símbolo de destino está muito longe do local da instrução.  
  
 Você pode resolver esse problema criando várias imagens ou usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção para a instrução e o destino estiverem mais juntos.  
  
 Quando o nome do símbolo é um símbolo definido pelo usuário (e não um símbolo gerado pelo compilador), você também pode tentar as seguintes ações para resolver o erro:  
  
-   Altere a função estática para ser não estático.  
  
-   Renomeie a seção de código que contém a função estática para ser o mesmo que o chamador.  
  
 Use `DUMPBIN /SYMBOLS`, para ver se uma função é estática.
