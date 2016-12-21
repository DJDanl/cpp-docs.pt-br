---
title: "CDBErrorInfo::GetErrorParameters | Microsoft Docs"
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
  - "ATL.CDBErrorInfo.GetErrorParameters"
  - "CDBErrorInfo::GetErrorParameters"
  - "ATL::CDBErrorInfo::GetErrorParameters"
  - "CDBErrorInfo.GetErrorParameters"
  - "GetErrorParameters"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetErrorParameters"
ms.assetid: 3a2dd8e2-fecc-4315-9f2b-ce3138cdd187
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDBErrorInfo::GetErrorParameters
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chama [IErrorRecords::GetErrorParameters](https://msdn.microsoft.com/en-us/library/ms715793.aspx) para retornar parâmetros de erro.  
  
## Sintaxe  
  
```  
  
      HRESULT GetErrorParameters(   
   ULONG ulRecordNum,   
   DISPPARAMS* pdispparams    
) const throw( );  
```  
  
#### Parâmetros  
 Consulte [IErrorRecords::GetErrorParameters](https://msdn.microsoft.com/en-us/library/ms715793.aspx)*na referência do programador de OLE DB*.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)