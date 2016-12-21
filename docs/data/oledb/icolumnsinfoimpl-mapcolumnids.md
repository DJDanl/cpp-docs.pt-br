---
title: "IColumnsInfoImpl::MapColumnIDs | Microsoft Docs"
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
  - "IColumnsInfoImpl<T>::MapColumnIDs"
  - "MapColumnIDs"
  - "ATL::IColumnsInfoImpl::MapColumnIDs"
  - "IColumnsInfoImpl.MapColumnIDs"
  - "ATL::IColumnsInfoImpl<T>::MapColumnIDs"
  - "IColumnsInfoImpl::MapColumnIDs"
  - "ATL.IColumnsInfoImpl<T>.MapColumnIDs"
  - "ATL.IColumnsInfoImpl.MapColumnIDs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MapColumnIDs"
ms.assetid: 7aa2d011-75ba-440a-bafe-ab8fccd16dfb
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IColumnsInfoImpl::MapColumnIDs
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna uma matriz dos ordinais das colunas em um conjunto de linhas que são identificadas pelos IDs de coluna especificados.  
  
## Sintaxe  
  
```  
  
      STDMETHOD (MapColumnIDs)(  
   DBORDINAL cColumnIDs,  
   const DBID rgColumnIDs[],  
   DBORDINAL rgColumns[]   
);  
```  
  
#### Parâmetros  
 Consulte [IColumnsInfo::MapColumnIDs](https://msdn.microsoft.com/en-us/library/ms714200.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IColumnsInfoImpl](../../data/oledb/icolumnsinfoimpl-class.md)   
 [IColumnsInfoImpl::GetColumnInfo](../../data/oledb/icolumnsinfoimpl-getcolumninfo.md)