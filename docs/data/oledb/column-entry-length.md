---
title: "COLUMN_ENTRY_LENGTH | Microsoft Docs"
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
  - "COLUMN_ENTRY_LENGTH"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro COLUMN_ENTRY_LENGTH"
ms.assetid: 1758babf-204c-4d1d-b82a-f9a607072e9a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# COLUMN_ENTRY_LENGTH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma associação no conjunto de linhas para a coluna específica no base de dados.  
  
## Sintaxe  
  
```  
  
COLUMN_ENTRY_LENGTH(  
nOrdinal  
,   
data  
,   
length  
 )  
  
```  
  
#### Parâmetros  
 Consulte [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)*na referência do programador de OLE DB*.  
  
 `nOrdinal`  
 \[in\] o número da coluna, começando com um.  O indicador corresponde à coluna zero.  
  
 `data`  
 \[in\] o membro de dados correspondente no registro do usuário.  
  
 *length*  
 \[in\] a variável a ser associado ao comprimento da coluna.  
  
## Comentários  
 Esta macro da suporte à variável *de comprimento* .  É usado nos seguintes locais:  
  
-   Entre [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md) e macros do [END\_COLUMN\_MAP](../../data/oledb/end-column-map.md) .  
  
-   Entre [BEGIN\_ACCESSOR](../../data/oledb/begin-accessor.md) e macros do [END\_ACCESSOR](../Topic/END_ACCESSOR.md) .  
  
-   Entre [BEGIN\_PARAM\_MAP](../Topic/BEGIN_PARAM_MAP.md) e macros do [END\_PARAM\_MAP](../../data/oledb/end-param-map.md) .  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md)   
 [COLUMN\_ENTRY](../../data/oledb/column-entry.md)   
 [COLUMN\_ENTRY\_EX](../../data/oledb/column-entry-ex.md)   
 [COLUMN\_ENTRY\_PS](../../data/oledb/column-entry-ps.md)   
 [COLUMN\_ENTRY\_PS\_LENGTH](../../data/oledb/column-entry-ps-length.md)   
 [COLUMN\_ENTRY\_LENGTH\_STATUS](../../data/oledb/column-entry-length-status.md)   
 [COLUMN\_ENTRY\_PS\_LENGTH\_STATUS](../Topic/COLUMN_ENTRY_PS_LENGTH_STATUS.md)   
 [COLUMN\_ENTRY\_STATUS](../../data/oledb/column-entry-status.md)   
 [COLUMN\_ENTRY\_PS\_STATUS](../Topic/COLUMN_ENTRY_PS_STATUS.md)   
 [END\_ACCESSOR](../Topic/END_ACCESSOR.md)   
 [END\_ACCESSOR\_MAP](../../data/oledb/end-accessor-map.md)   
 [END\_COLUMN\_MAP](../../data/oledb/end-column-map.md)