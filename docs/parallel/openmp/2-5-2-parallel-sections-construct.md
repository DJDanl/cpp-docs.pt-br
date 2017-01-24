---
title: "2.5.2 parallel sections Construct | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 94220e27-14f8-465c-bd8d-eb960b4b5dee
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.5.2 parallel sections Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **seções paralelas** diretiva fornece um formulário de atalho para especificar um  **paralela** região que contém um único  **seções** diretiva.  A semântica é idêntica ao especificar explicitamente um  **paralela** diretiva imediatamente seguida por um  **seções** diretiva.  A sintaxe da  **seções paralelas** diretiva é o seguinte:  
  
```  
#pragma omp parallel sections  [clause[[,] clause] ...] new-line  
   {  
   [#pragma omp section new-line]  
      structured-block  
   [#pragma omp section new-line  
      structured-block  ]  
   ...  
}  
```  
  
 O  *cláusula* pode ser uma das cláusulas aceitas pelo  **paralela** e  **seções** diretivas, exceto o  **nowait** cláusula.  
  
## Entre as referências:  
  
-   **paralela** diretiva, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8.  
  
-   **seções** diretiva, consulte  [seção 2.4.2](../../parallel/openmp/2-4-2-sections-construct.md) na página 14.