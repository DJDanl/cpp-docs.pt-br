---
title: "BLOB_NAME | Microsoft Docs"
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
  - "BLOB_NAME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro BLOB_NAME"
ms.assetid: 757acd0d-946d-447d-937e-94ecd700ba38
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# BLOB_NAME
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado com `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP` para associar um objeto binário grande \([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)\).  Semelhante a, exceto que a [BLOB\_ENTRY](../Topic/BLOB_ENTRY.md)esta macro usa um nome de coluna em vez de um número da coluna.  
  
## Sintaxe  
  
```  
  
BLOB_NAME(  
pszName  
,   
IID  
,   
flags  
,   
data )  
```  
  
#### Parâmetros  
 `pszName`  
 \[in\] ponteiro da o nome da coluna.  O nome deve ser uma cadeia de caracteres Unicode.  Isso pode ser feito colocando um “L” em frente do nome, por exemplo: `L"MyColumn"`.  
  
 *IID*  
 \[in\] interface GUID, como **IDD\_ISequentialStream**, usado para recuperar o BLOB.  
  
 `flags`  
 \[in\] sinalizadores de armazenamento modo conforme definido pelo modelo de armazenamento estruturado OLE \(por exemplo, **STGM\_READ**\).  
  
 `data`  
 \[in\] o membro de dados correspondente no registro do usuário.  
  
## Exemplo  
 Consulte [Como posso recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md)   
 [END\_COLUMN\_MAP](../../data/oledb/end-column-map.md)   
 [COLUMN\_ENTRY](../../data/oledb/column-entry.md)   
 [BLOB\_NAME\_LENGTH](../../data/oledb/blob-name-length.md)   
 [BLOB\_NAME\_LENGTH\_STATUS](../../data/oledb/blob-name-length-status.md)   
 [BLOB\_NAME\_STATUS](../Topic/BLOB_NAME_STATUS.md)