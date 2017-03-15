---
title: "IRowsetImpl::GetData | Microsoft Docs"
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
  - "ATL.IRowsetImpl.GetData"
  - "ATL::IRowsetImpl::GetData"
  - "IRowsetImpl::GetData"
  - "IRowsetImpl.GetData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetData [OLE DB]"
ms.assetid: cb15f1cc-bd25-4b74-93c3-db71aa93829c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetImpl::GetData
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera dados de uma cópia do conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      STDMETHOD( GetData )(  
   HROW hRow,  
   HACCESSOR hAccessor,  
   void* pDstData   
);  
```  
  
#### Parâmetros  
 Consulte [IRowset::GetData](https://msdn.microsoft.com/en-us/library/ms716988.aspx)*na referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem aos *parâmetros de referência do programador de OLE DB* os nomes diferentes, que são descritos em **IRowset::GetData**:  
  
|Parâmetros do modelo de OLE DB|*Os parâmetros de referência do programador de OLE DB*|  
|------------------------------------|------------------------------------------------------------|  
|*pDstData*|`pData`|  
  
## Comentários  
 Também controla a conversão de dados usando a DLL de conversão de dados OLE DB.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetImpl](../Topic/IRowsetImpl%20Class.md)