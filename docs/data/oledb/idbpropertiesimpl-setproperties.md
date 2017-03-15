---
title: "IDBPropertiesImpl::SetProperties | Microsoft Docs"
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
  - "IDBPropertiesImpl.SetProperties"
  - "SetProperties"
  - "IDBPropertiesImpl::SetProperties"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetProperties"
ms.assetid: 2f9fc1de-7f35-4bca-bab3-7b427bf92c26
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBPropertiesImpl::SetProperties
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define propriedades grupos na propriedade da fonte de dados e a inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização, para enumeradores.  
  
## Sintaxe  
  
```  
  
      STDMETHOD(SetProperties)(   
   ULONG cPropertySets,   
   DBPROPSET rgPropertySets[]    
);  
```  
  
#### Parâmetros  
 Consulte [IDBProperties::SetProperties](https://msdn.microsoft.com/en-us/library/ms723049.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 Se o provedor é inicializado, os conjuntos desse método os valores das propriedades em **DBPROPSET\_DATASOURCE**, **DBPROPSET\_DATASOURCEINFO**, grupos de propriedade de **DBPROPSET\_DBINIT** para a fonte de dados publicado.  Se o provedor não é inicializado, define as propriedades do grupo de **DBPROPSET\_DBINIT** somente.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)   
 [IDBPropertiesImpl::GetProperties](../../data/oledb/idbpropertiesimpl-getproperties.md)   
 [IDBPropertiesImpl::GetPropertyInfo](../../data/oledb/idbpropertiesimpl-getpropertyinfo.md)