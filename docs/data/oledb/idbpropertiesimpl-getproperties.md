---
title: "IDBPropertiesImpl::GetProperties | Microsoft Docs"
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
  - "IDBPropertiesImpl::GetProperties"
  - "IDBPropertiesImpl.GetProperties"
  - "GetProperties"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetProperties"
ms.assetid: ab24aebd-366d-49a1-b49b-bb46c6d90f05
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBPropertiesImpl::GetProperties
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna os valores das propriedades nos grupos de propriedades de fonte de dados, de informações da fonte de dados, e inicialização definidas atualmente no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização que são definidas atualmente no enumerador.  
  
## Sintaxe  
  
```  
  
      STDMETHOD(GetProperties)(   
   ULONG cPropertySets,   
   const DBPROPIDSET rgPropertySets[],   
   ULONG * pcProperties,   
   DBPROPSET ** prgProperties    
);  
```  
  
#### Parâmetros  
 Consulte [IDBProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms714344.aspx)*na referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem aos *parâmetros de referência do programador de OLE DB* os nomes diferentes, que são descritos em **IDBProperties::GetProperties**:  
  
|Parâmetros do modelo de OLE DB|*Os parâmetros de referência do programador de OLE DB*|  
|------------------------------------|------------------------------------------------------------|  
|`cPropertySets`|`cPropertyIDSets`|  
|`rgPropertySets`|`rgPropertyIDSets`|  
|*pcProperties*|*pcPropertySets*|  
|*prgProperties*|*prgPropertySets*|  
  
## Comentários  
 Se o provedor for inicializado, esse método retornará os valores das propriedades em **DBPROPSET\_DATASOURCE**, **DBPROPSET\_DATASOURCEINFO**, os grupos de propriedade de **DBPROPSET\_DBINIT** definidas atualmente no objeto de fonte de dados.  Se o provedor não é inicializado, retorna propriedades do grupo de **DBPROPSET\_DBINIT** somente.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)   
 [IDBPropertiesImpl::GetPropertyInfo](../../data/oledb/idbpropertiesimpl-getpropertyinfo.md)   
 [IDBPropertiesImpl::SetProperties](../../data/oledb/idbpropertiesimpl-setproperties.md)