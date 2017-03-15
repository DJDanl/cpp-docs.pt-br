---
title: Aviso LNK4219 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4219
dev_langs:
- C++
helpviewer_keywords:
- LNK4219
ms.assetid: 363fedf4-b10c-4985-811a-55a9fba688d6
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ab241e13f266158fa0a7bd09036ab2131718f554
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4219"></a>Aviso LNK4219 (Ferramentas de Vinculador)
estouro de correção do nome de correção. O destino 'nome do símbolo de destino' está fora do intervalo, a inserção de conversão  
  
 O vinculador inserida uma conversão em uma situação em que o endereço ou deslocamento não pôde caber na instrução de determinado como o símbolo de destino está muito longe do local da instrução.  
  
 Talvez você queira reordenar a imagem (usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção, por exemplo) para evitar o nível extra de indireção.
