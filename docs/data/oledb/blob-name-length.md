---
title: "BLOB_NAME_LENGTH | Microsoft Docs"
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
  - "BLOB_NAME_LENGTH"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro BLOB_NAME_LENGTH"
ms.assetid: 38150260-a127-486d-a7ab-0d01b731b6fd
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# BLOB_NAME_LENGTH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado com `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP` para associar um objeto binário grande \([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)\).  Semelhante a, exceto que a [BLOB\_NAME](../../data/oledb/blob-name.md)esta macro também obtém o comprimento em bytes da coluna de dados BLOB.  
  
## Sintaxe  
  
```  
  
BLOB_NAME_LENGTH(  
pszName  
,   
IID  
,   
flags  
,   
data  
,   
length )  
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
  
 *length*  
 \[fora\] o tamanho real \(em bytes\) da coluna de BLOB.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)   
 [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md)   
 [END\_COLUMN\_MAP](../../data/oledb/end-column-map.md)   
 [COLUMN\_ENTRY](../../data/oledb/column-entry.md)   
 [BLOB\_NAME](../../data/oledb/blob-name.md)   
 [BLOB\_NAME\_LENGTH\_STATUS](../../data/oledb/blob-name-length-status.md)   
 [BLOB\_NAME\_STATUS](../Topic/BLOB_NAME_STATUS.md)