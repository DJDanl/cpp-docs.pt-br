---
title: "ISessionPropertiesImpl::GetProperties | Microsoft Docs"
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
  - "ISessionPropertiesImpl::GetProperties"
  - "ISessionPropertiesImpl.GetProperties"
  - "GetProperties"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetProperties"
ms.assetid: 48726c2a-9599-4fc5-9940-a932faef91ab
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ISessionPropertiesImpl::GetProperties
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna a lista de propriedades no grupo de propriedades **DBPROPSET\_SESSION** que são definidas atualmente na sessão.  
  
## Sintaxe  
  
```  
  
      STDMETHOD(GetProperties)(   
   ULONG cPropertyIDSets,   
   const DBPROPIDSET rgPropertyIDSets[],   
   ULONG * pcPropertySets,   
   DBPROPSET ** prgPropertySets    
);  
```  
  
#### Parâmetros  
 Consulte [ISessionProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms723643.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe ISessionPropertiesImpl](../../data/oledb/isessionpropertiesimpl-class.md)   
 [ISessionPropertiesImpl::SetProperties](../../data/oledb/isessionpropertiesimpl-setproperties.md)