---
title: "BLOB_ENTRY_LENGTH | Microsoft Docs"
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
  - "BLOB_ENTRY_LENGTH"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro BLOB_ENTRY_LENGTH"
ms.assetid: 832d21ab-5fdd-49ad-af6e-4fca5722ec93
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# BLOB_ENTRY_LENGTH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado com `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP` para associar um objeto binário grande \([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)\).  Semelhante a, exceto que a [BLOB\_ENTRY](../Topic/BLOB_ENTRY.md)esta macro também obtém o comprimento em bytes da coluna de BLOB.  
  
## Sintaxe  
  
```  
  
BLOB_ENTRY_LENGTH(  
nOrdinal  
,   
IID  
,   
flags  
,   
data  
,   
length  
 )  
  
```  
  
#### Parâmetros  
 `nOrdinal`  
 \[in\] o número da coluna.  
  
 *IID*  
 \[in\] interface GUID, como **IDD\_ISequentialStream**, usado para recuperar o BLOB.  
  
 `flags`  
 \[in\] sinalizadores de armazenamento modo conforme definido pelo modelo de armazenamento estruturado OLE \(por exemplo, **STGM\_READ**\).  
  
 `data`  
 \[in\] o membro de dados correspondente no registro do usuário.  
  
 *length*  
 \[fora\] o tamanho real \(em bytes\) da coluna de BLOB.  
  
## Exemplo  
 Consulte [Como posso recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md)   
 [END\_COLUMN\_MAP](../../data/oledb/end-column-map.md)   
 [COLUMN\_ENTRY](../../data/oledb/column-entry.md)   
 [BLOB\_ENTRY](../Topic/BLOB_ENTRY.md)   
 [BLOB\_ENTRY\_LENGTH\_STATUS](../../data/oledb/blob-entry-length-status.md)   
 [BLOB\_ENTRY\_STATUS](../Topic/BLOB_ENTRY_STATUS.md)