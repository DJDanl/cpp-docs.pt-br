---
title: "IRowsetInfoImpl::GetSpecification | Microsoft Docs"
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
  - "IRowsetInfoImpl::GetSpecification"
  - "ATL.IRowsetInfoImpl.GetSpecification"
  - "IRowsetInfoImpl.GetSpecification"
  - "GetSpecification"
  - "ATL::IRowsetInfoImpl::GetSpecification"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetSpecification"
ms.assetid: 8e14289d-9cca-4df7-a9e0-f4ef03c61e30
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetInfoImpl::GetSpecification
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um ponteiro de interface no objeto \(comando ou de sessão\) que criou este conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      STDMETHOD ( GetSpecification )(  
   REFIID riid,  
   IUnknown** ppSpecification   
);  
```  
  
#### Parâmetros  
 Consulte [IRowsetInfo::GetSpecification](https://msdn.microsoft.com/en-us/library/ms716746.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 Use este método com [IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md) para recuperar propriedades do objeto de fonte de dados.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetInfoImpl](../Topic/IRowsetInfoImpl%20Class.md)   
 [IRowsetInfoImpl::GetReferencedRowset](../../data/oledb/irowsetinfoimpl-getreferencedrowset.md)   
 [IRowsetInfoImpl::GetProperties](../../data/oledb/irowsetinfoimpl-getproperties.md)