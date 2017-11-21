---
title: "2.5.1 paralelo para construção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: a233e7ed-2462-4f7a-9a5d-556ab9f363d8
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0c1384799df3f84ffc20724ad3f2bb4890109698
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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