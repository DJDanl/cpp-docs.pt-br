---
title: "M&#233;todo AsyncBase::CheckValidStateForResultsCall | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "async/Microsoft::WRL::AsyncBase::CheckValidStateForResultsCall"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CheckValidStateForResultsCall"
ms.assetid: 87ca6805-bff1-4063-b855-6dd26132deff
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::CheckValidStateForResultsCall
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se os resultados de uma operação assíncrona podem ser coletados no estado assíncrona atual.  
  
## Sintaxe  
  
```  
inline HRESULT CheckValidStateForResultsCall();  
```  
  
## Valor de retorno  
 S\_OK se os resultados podem ser coletados; caso contrário, E\_ILLEGAL\_METHOD\_CALLE\_ILLEGAL\_METHOD\_CALL.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)