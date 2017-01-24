---
title: "M&#233;todo AsyncBase::TryTransitionToCompleted | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::TryTransitionToCompleted"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método TryTransitionToCompleted"
ms.assetid: 8d038e0a-47ec-4cfc-8aeb-6821282df67a
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::TryTransitionToCompleted
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se a operação assíncrona atual foi concluída.  
  
## Sintaxe  
  
```  
bool TryTransitionToCompleted(  
   void  
);  
```  
  
## Valor de retorno  
 `true` se a operação assíncrona foi concluída; caso contrário, `false`.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)