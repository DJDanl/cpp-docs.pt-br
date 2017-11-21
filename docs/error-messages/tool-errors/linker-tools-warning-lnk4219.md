---
title: Aviso LNK4219 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4219
dev_langs: C++
helpviewer_keywords: LNK4219
ms.assetid: 363fedf4-b10c-4985-811a-55a9fba688d6
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c2416e8872998f9cb59efee21d33bbe60dd96d37
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4219"></a>Aviso LNK4219 (Ferramentas de Vinculador)
estouro de conserto de nome de correção. O destino 'nome do símbolo de destino' está fora do intervalo, inserindo conversão  
  
 O vinculador inserida uma conversão em uma situação em que o endereço ou o deslocamento não pôde ajustar em determinada instrução porque o símbolo de destino é muito distante do local da instrução.  
  
 Talvez você queira reordenar a imagem (usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção, por exemplo) para evitar o nível extra de indireção.