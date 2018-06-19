---
title: 2.6.1 constructo de mestre | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c092064b-ea57-4d4e-9c99-a004d65656fe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a60a8df380fdcc0052d8fe2d070c8d926bcb28f8
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689549"
---
# <a name="261-master-construct"></a>2.6.1 Constructo master
O **mestre** diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread principal da equipe. A sintaxe do **mestre** diretiva é da seguinte maneira:  
  
```  
#pragma omp master new-linestructured-block  
```  
  
 Outros threads da equipe não executem o bloco estruturado associado. Não há nenhum barreira implícita na entrada ou saída de construção a mestre.