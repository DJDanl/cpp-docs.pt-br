---
title: "ICommandPropertiesImpl::GetProperties | Microsoft Docs"
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
  - "ICommandPropertiesImpl::GetProperties"
  - "ICommandPropertiesImpl.GetProperties"
  - "GetProperties"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetProperties"
ms.assetid: 1bee5f1b-bd08-435a-956a-e4cebcdf5d5e
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ICommandPropertiesImpl::GetProperties
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna todos os conjuntos de propriedades solicitados usando o mapa da propriedade do comando.  
  
## Sintaxe  
  
```  
  
      STDMETHOD(GetProperties)(   
   const ULONG cPropertyIDSets,   
   const DBPROPIDSET rgPropertyIDSets[],   
   ULONG * pcPropertySets,   
   DBPROPSET ** prgPropertySets    
);  
```  
  
#### Parâmetros  
 Consulte [ICommandProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms723119.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 Consulte [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe ICommandPropertiesImpl](../../data/oledb/icommandpropertiesimpl-class.md)   
 [ICommandPropertiesImpl::SetProperties](../Topic/ICommandPropertiesImpl::SetProperties.md)