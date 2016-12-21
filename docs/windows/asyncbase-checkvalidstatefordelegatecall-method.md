---
title: "M&#233;todo AsyncBase::CheckValidStateForDelegateCall | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::CheckValidStateForDelegateCall"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CheckValidStateForDelegateCall"
ms.assetid: d997ebe7-2378-4e74-a379-f0f85e6922f0
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::CheckValidStateForDelegateCall
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se as propriedades de delegação podem ser alteradas no estado assíncrona atual.  
  
## Sintaxe  
  
```  
inline HRESULT CheckValidStateForDelegateCall();  
```  
  
## Valor de retorno  
 S\_OK se as propriedades de delegação podem ser alteradas; caso contrário, E\_ILLEGAL\_METHOD\_CALL.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)