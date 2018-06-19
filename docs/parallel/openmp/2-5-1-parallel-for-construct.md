---
title: 2.5.1 paralelo para construção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a233e7ed-2462-4f7a-9a5d-556ab9f363d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef2732c4f8713466d282346ea240bd3c41886ce0
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33687147"
---
# <a name="251-parallel-for-construct"></a>2.5.1 Construto parallel for
O **paralelo para** diretiva é um atalho para um **paralela** região que contém um único **para** diretiva. A sintaxe do **paralelo para** diretiva é da seguinte maneira:  
  
```  
#pragma omp parallel for [clause[[,] clause] ...] new-linefor-loop  
```  
  
 Essa diretiva permite que todas as cláusulas do **paralela** diretiva e a **para** diretiva, exceto o `nowait` cláusula com significados idênticos e restrições. A semântica é idêntica para especificar explicitamente um **paralela** diretiva seguida imediatamente por um **para** diretiva.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **paralelo** diretiva, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.  
  
-   **para** diretiva, consulte [seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página 11.  
  
-   Cláusulas de atributo de dados, consulte [2.7.2 cláusulas de compartilhamento de dados de atributo](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.