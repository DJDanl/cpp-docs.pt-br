---
title: 2.6.6 constructo ordered | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 5b3c1ba5-cfb8-4b05-865b-f446ae1c9f7c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fa66d9fb8a0a9af2fc33497690bfe67a3ea5d717
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690339"
---
# <a name="266-ordered-construct"></a>2.6.6 Constructo ordered
O seguinte bloco estruturado um **ordenados** diretiva é executada na ordem iterações seriam executadas em um loop sequencial. A sintaxe do **ordenados** diretiva é da seguinte maneira:  
  
```  
#pragma omp ordered new-linestructured-block  
```  
  
 Um **ordenados** diretiva deve estar dentro a extensão dinâmica de um **para** ou **paralelo para** construir. O **para** ou **paralelo para** diretiva para o qual o **ordenados** construção associa deve ter uma **ordenados** cláusula especificada conforme descrito em [Seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página 11. Na execução de um **para** ou **paralelo para** construir com um **ordenados** cláusula, **ordenados** construções são executadas em estritamente a ordem na qual eles seriam executados em uma execução sequencial do loop.  
  
 Restrições para o **ordenados** diretiva são da seguinte maneira:  
  
-   Uma iteração de um loop com um **para** construção não deve executar a mesma diretiva ordenada mais de uma vez e não deve executar mais de um **ordenados** diretiva.