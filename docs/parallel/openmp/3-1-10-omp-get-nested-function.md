---
title: "3.1.10 omp_get_nested Function | Microsoft Docs"
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
ms.assetid: 48736a25-5c6e-4e2d-aad0-421087663a3c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.10 omp_get_nested Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `omp_get_nested` função retorna um valor diferente de zero se paralelismo aninhado estiver habilitado e 0 se ela estiver desativada.  Para obter mais informações sobre o paralelismo aninhado, consulte a seção 3.1.9 na página 40.  O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_nested(void);  
```  
  
 Se uma implementação não implementa o paralelismo aninhado, essa função sempre retornará 0.