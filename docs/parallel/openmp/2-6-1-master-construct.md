---
title: 2.6.1 constructo de mestre | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: c092064b-ea57-4d4e-9c99-a004d65656fe
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2517e19b49f1314e7432bb265756193ea3bb8f91
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="261-master-construct"></a>2.6.1 Constructo master
O **mestre** diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread principal da equipe. A sintaxe do **mestre** diretiva é da seguinte maneira:  
  
```  
#pragma omp master new-linestructured-block  
```  
  
 Outros threads da equipe não executem o bloco estruturado associado. Não há nenhum barreira implícita na entrada ou saída de construção a mestre.