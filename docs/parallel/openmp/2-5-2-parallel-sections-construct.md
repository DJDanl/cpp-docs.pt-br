---
title: 2.5.2 constructo parallel sections | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 94220e27-14f8-465c-bd8d-eb960b4b5dee
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6f7a84e322cb273733c6a724ee2563928df8362
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
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