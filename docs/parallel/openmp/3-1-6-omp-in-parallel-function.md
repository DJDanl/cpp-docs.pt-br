---
title: "3.1.6 omp_in_parallel Function | Microsoft Docs"
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
ms.assetid: db6e3a63-2a0a-4b8e-8cc6-c6b49edca5fb
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.6 omp_in_parallel Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **omp\_in\_parallel** função retorna um valor diferente de zero se ele é chamado a extensão dinâmica de uma região paralela em execução em paralelo; Caso contrário, ele retornará 0.  O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_in_parallel(void);  
```  
  
 Esta função retorna um valor diferente de zero quando chamado de uma região em execução em paralelo, incluindo regiões aninhadas que são serializados.