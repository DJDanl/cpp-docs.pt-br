---
title: "IErrorRecordsImpl::GetErrorSource | Microsoft Docs"
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
  - "IErrorRecordsImpl.GetErrorSource"
  - "GetErrorSource"
  - "IErrorRecordsImpl::GetErrorSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetErrorSource"
ms.assetid: 5436f1ce-c5a4-403b-a62b-c58e70e5c925
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IErrorRecordsImpl::GetErrorSource
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o código\-fonte que ocasionou o erro de um registro de erro.  
  
## Sintaxe  
  
```  
  
      LPOLESTR GetErrorSource(  
   ERRORINFO& rCurError   
);  
```  
  
#### Parâmetros  
 `rCurError`  
 Um registro de `ERRORINFO` em uma interface de **IErrorInfo** .  
  
## Valor de retorno  
 Ponteiro para uma cadeia de caracteres que contém a origem do erro.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)