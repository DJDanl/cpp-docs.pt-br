---
title: "END_ACCESSOR_MAP | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "END_ACCESSOR_MAP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro END_ACCESSOR_MAP"
ms.assetid: ede813c7-46c9-48a6-aa1a-8ebf38e92023
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# END_ACCESSOR_MAP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Marca o término das entradas do mapa do acessador.  
  
## Sintaxe  
  
```  
  
END_ACCESSOR_MAP( )  
  
```  
  
## Comentários  
 Para mais acessadores em um conjunto de linhas, você precisa especificar `BEGIN_ACCESSOR_MAP` e usar a macro de `BEGIN_ACCESSOR` para cada acessador individual.  A macro de `BEGIN_ACCESSOR` é concluído com a macro de `END_ACCESSOR` .  A macro de `BEGIN_ACCESSOR_MAP` é concluído com a macro de `END_ACCESSOR_MAP` .  
  
## Exemplo  
 Consulte [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN\_ACCESSOR](../../data/oledb/begin-accessor.md)