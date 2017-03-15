---
title: "CDBErrorInfo::GetErrorRecords | Microsoft Docs"
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
  - "CDBErrorInfo.GetErrorRecords"
  - "ATL.CDBErrorInfo.GetErrorRecords"
  - "ATL::CDBErrorInfo::GetErrorRecords"
  - "GetErrorRecords"
  - "CDBErrorInfo::GetErrorRecords"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetErrorRecords"
ms.assetid: 07746774-bcca-4833-8f55-a619e9777c17
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDBErrorInfo::GetErrorRecords
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém registros de erro para o objeto especificado.  
  
## Sintaxe  
  
```  
  
      HRESULT GetErrorRecords(   
   IUnknown* pUnk,   
   const IID& iid,   
   ULONG* pcRecords    
) throw( );  
HRESULT GetErrorRecords(   
   ULONG* pcRecords    
) throw( );  
```  
  
#### Parâmetros  
 *punk*  
 \[in\] interface para o objeto para o qual obter registros de erro.  
  
 `iid`  
 \[in\] O IID da interface associada ao erro.  
  
 *pcRecords*  
 \[out\] ponteiro da contagem \(com base em um\) de registros de erro.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Use o primeiro formulário de função se você desejar verificar de fazer interface para obter informações de erro.  Se não, use o segundo formulário.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)