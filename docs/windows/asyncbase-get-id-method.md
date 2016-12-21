---
title: "M&#233;todo AsyncBase::get_Id | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::get_Id"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método get_Id"
ms.assetid: 591d8366-ea76-4deb-9278-9d3bc394a42b
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::get_Id
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera o identificador de operação assíncrona.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   get_Id  
)(unsigned int *id) override;  
```  
  
#### Parâmetros  
 `id`  
 O local onde o identificador deve ser armazenada.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, E\_ILLEGAL\_METHOD\_CALL.  
  
## Comentários  
 Esse método implementa IAsyncInfo::get\_Id.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)