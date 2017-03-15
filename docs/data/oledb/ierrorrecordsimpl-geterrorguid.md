---
title: "IErrorRecordsImpl::GetErrorGUID | Microsoft Docs"
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
  - "GetErrorGUID"
  - "IErrorRecordsImpl.GetErrorGUID"
  - "IErrorRecordsImpl::GetErrorGUID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetErrorGUID"
ms.assetid: 42c00755-50e5-401a-8246-adef9de5ced2
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IErrorRecordsImpl::GetErrorGUID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o erro GUID de um registro de erro.  
  
## Sintaxe  
  
```  
  
      REFGUID GetErrorGUID(  
   ERRORINFO& rCurError   
);  
```  
  
#### Parâmetros  
 `rCurError`  
 Um registro de `ERRORINFO` em uma interface de **IErrorInfo** .  
  
## Valor de retorno  
 Uma referência ao GUID do erro.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)