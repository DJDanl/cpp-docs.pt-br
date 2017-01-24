---
title: "Especificando o modelo de threading para um projeto (ATL) | Microsoft Docs"
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
helpviewer_keywords: 
  - "Macro _ATL_APARTMENT_THREADED"
  - "Macro _ATL_FREE_THREADED"
  - "Macro _ATL_SINGLE_THREADED"
  - "ATL, multithreading"
  - "threading [ATL], modelos"
ms.assetid: 6b571078-521c-4f3e-9f08-482aa235a822
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificando o modelo de threading para um projeto (ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os seguintes macros estão disponíveis para especificar o modelo de threads de um projeto de ATL:  
  
|Macro|Diretrizes para usar|  
|-----------|--------------------------|  
|\_ATL\_SINGLE\_THREADED|Defina se todos os seus objetos usam o único modelo.|  
|\_ATL\_APARTMENT\_THREADED|Defina se um ou mais dos seus objetos usam o Apartment threads.|  
|\_ATL\_FREE\_THREADED|Defina se um ou mais de uso de objetos de segmentação livre ou neutra.  o código existente pode conter referências a [\_ATL\_MULTI\_THREADED](../Topic/_ATL_MULTI_THREADED.md)macro equivalente.|  
  
 Se você não definir qualquer um de macros para seu projeto, o \_ATL\_FREE\_THREADED será aplicado.  
  
 Macros afetam o desempenho de tempo de execução como segue:  
  
-   Especificar a macro que correspondem aos objetos em seu projeto pode melhorar o desempenho de tempo de execução.  
  
-   Especificar um nível mais alto de macros, por exemplo se você especificar o \_ATL\_APARTMENT\_THREADED quando todos os seus objetos são de thread única, degradará um pouco o desempenho de tempo de execução.  
  
-   Especificar um nível inferior de macros, por exemplo, se você especificar o \_ATL\_SINGLE\_THREADED quando um ou mais dos seus objetos usam o thread Apartment ou segmentação livre, seu aplicativo pode causar falhar em tempo de execução.  
  
 Consulte [Opções, assistente simples de objeto de ATL](../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de threads disponíveis para um objeto de ATL.  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)