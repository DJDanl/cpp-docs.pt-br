---
title: "3.1.8 omp_get_dynamic Function | Microsoft Docs"
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
ms.assetid: c03e2daf-29c9-49e3-9b67-b980ad1ab195
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.8 omp_get_dynamic Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **omp\_get\_dynamic** função retorna um valor diferente de zero se ajuste dinâmico de segmentos estiver habilitado e, caso contrário, retornará 0.  O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_dynamic(void);  
```  
  
 Se a implementação não implementa ajuste dinâmico do número de segmentos, essa função sempre retornará 0.  
  
## Entre as referências:  
  
-   Para obter uma descrição do ajuste de segmento dinâmico, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.