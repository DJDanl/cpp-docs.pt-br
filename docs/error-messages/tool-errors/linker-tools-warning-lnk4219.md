---
title: Aviso LNK4219 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4219
dev_langs:
- C++
helpviewer_keywords:
- LNK4219
ms.assetid: 363fedf4-b10c-4985-811a-55a9fba688d6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 59cb7376957b7985b7ae2335ea472171d490ff42
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33301129"
---
# <a name="linker-tools-warning-lnk4219"></a>Aviso LNK4219 (Ferramentas de Vinculador)
estouro de conserto de nome de correção. O destino 'nome do símbolo de destino' está fora do intervalo, inserindo conversão  
  
 O vinculador inserida uma conversão em uma situação em que o endereço ou o deslocamento não pôde ajustar em determinada instrução porque o símbolo de destino é muito distante do local da instrução.  
  
 Talvez você queira reordenar a imagem (usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção, por exemplo) para evitar o nível extra de indireção.