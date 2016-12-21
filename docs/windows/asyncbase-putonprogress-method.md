---
title: "M&#233;todo AsyncBase::PutOnProgress | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::PutOnProgress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método PutOnProgress"
ms.assetid: 1f5f180e-eb5a-4afe-ac16-69dbf36f0383
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::PutOnProgress
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o endereço do manipulador de eventos de andamento para o valor especificado.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   PutOnProgress  
)(TProgress* progressHandler);  
```  
  
#### Parâmetros  
 `progressHandler`  
 O endereço para o qual o manipulador de eventos de andamento está definido.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, E\_ILLEGAL\_METHOD\_CALL.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)