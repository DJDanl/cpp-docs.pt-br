---
title: "IConvertTypeImpl::CanConvert | Microsoft Docs"
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
  - "IConvertTypeImpl.CanConvert"
  - "CanConvert"
  - "IConvertTypeImpl::CanConvert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CanConvert"
ms.assetid: bdad6e95-bc0b-4427-9b5e-eea51f09f392
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IConvertTypeImpl::CanConvert
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece informações sobre a disponibilidade conversões de tipo em um comando ou em um conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      STDMETHOD(CanConvert)(   
   DBTYPE wFromType,   
   DBTYPE wToType,   
   DBCONVERTFLAGS dwConvertFlags    
);  
```  
  
#### Parâmetros  
 Consulte [IConvertType::CanConvert](https://msdn.microsoft.com/en-us/library/ms711224.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 Conversão de dados OLE DB do em `MSADC.DLL`.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IConvertTypeImpl](../../data/oledb/iconverttypeimpl-class.md)