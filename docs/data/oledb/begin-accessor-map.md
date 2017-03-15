---
title: "BEGIN_ACCESSOR_MAP | Microsoft Docs"
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
  - "BEGIN_ACCESSOR_MAP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro BEGIN_ACCESSOR_MAP"
ms.assetid: e6d6e3a4-62fa-4e49-8c53-caf8c9d20091
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# BEGIN_ACCESSOR_MAP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Marca o início das entradas de mapa do acessador.  
  
## Sintaxe  
  
```  
  
BEGIN_ACCESSOR_MAP(  
x  
,   
num  
 )  
  
```  
  
#### Parâmetros  
 *x*  
 \[in\] O nome da classe de registro de usuário.  
  
 *num*  
 \[in\] O número de acessadores neste mapa do acessador.  
  
## Comentários  
 No caso de vários acessadores em um conjunto de linhas, você precisa especificar `BEGIN_ACCESSOR_MAP` no início e no uso de `BEGIN_ACCESSOR` macro cada acessador individuais. O `BEGIN_ACCESSOR` macro é preenchida com o `END_ACCESSOR` macro. O mapa de acessador é preenchido com o `END_ACCESSOR_MAP` macro.  
  
 Se você tiver apenas um acessador no registro do usuário, use a macro [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md).  
  
## Exemplo  
 [!CODE [NVC_OLEDB_Consumer#15](../CodeSnippet/VS_Snippets_Cpp/NVC_OLEDB_Consumer#15)]  
  
## Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [END\_ACCESSOR](../Topic/END_ACCESSOR.md)   
 [END\_ACCESSOR\_MAP](../../data/oledb/end-accessor-map.md)