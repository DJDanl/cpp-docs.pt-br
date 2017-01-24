---
title: "M&#233;todo AsyncBase::put_Id | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::put_Id"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método put_Id"
ms.assetid: aebad85f-4774-42de-b625-a9cf5f65cb4e
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::put_Id
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o identificador de operação assíncrona.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   put_Id  
)(const unsigned int id);  
```  
  
#### Parâmetros  
 `id`  
 Um identificador diferente de zero.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; se não, E\_INVALIDARG ou E\_ILLEGAL\_METHOD\_CALL.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)