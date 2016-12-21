---
title: "CDataSource::GetProperties | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CDataSource::GetProperties"
  - "ATL.CDataSource.GetProperties"
  - "CDataSource.GetProperties"
  - "ATL::CDataSource::GetProperties"
  - "GetProperties"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetProperties"
ms.assetid: ffaecc17-9fe7-449e-94d6-43d31ad06cfc
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataSource::GetProperties
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna informações de propriedade solicitada do objeto de conexão da fonte de dados.  
  
## Sintaxe  
  
```  
  
      HRESULT GetProperties(   
   ULONG ulPropIDSets,   
   const DBPROPIDSET* pPropIDSet,   
   ULONG* pulPropertySets,   
   DBPROPSET** ppPropsets    
) const throw( );  
```  
  
#### Parâmetros  
 Consulte [IDBProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms714344.aspx)*na referência do programador do* OLE DB em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Para obter uma única propriedade, use [GetProperty](../Topic/CDataSource::GetProperty.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataSource](../Topic/CDataSource%20Class.md)