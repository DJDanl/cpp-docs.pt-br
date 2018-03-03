---
title: 2.5.2 constructo parallel sections | Microsoft Docs
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
ms.assetid: 94220e27-14f8-465c-bd8d-eb960b4b5dee
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e3a76a950d547effccf0b50fa04799814597bc5e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="252-parallel-sections-construct"></a>2.5.2 Constructo parallel sections
O **paralelo seções** diretiva fornece um formulário de atalho para especificar um **paralela** região que contém um único **seções** diretiva. A semântica é idêntica para especificar explicitamente um **paralela** diretiva seguida imediatamente por um **seções** diretiva. A sintaxe do **paralelo seções** diretiva é da seguinte maneira:  
  
```  
#pragma omp parallel sections  [clause[[,] clause] ...] new-line  
   {  
   [#pragma omp section new-line]  
      structured-block  
   [#pragma omp section new-linestructured-block  ]  
   ...  
}  
```  
  
 O *cláusula* pode ser uma das cláusulas aceitas pela **paralela** e **seções** diretivas, exceto o **nowait** cláusula.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **paralelo** diretiva, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.  
  
-   **seções** diretiva, consulte [seção 2.4.2](../../parallel/openmp/2-4-2-sections-construct.md) na 14 da página.