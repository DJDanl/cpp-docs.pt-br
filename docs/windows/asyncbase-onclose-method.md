---
title: "M&#233;todo AsyncBase::OnClose | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::OnClose"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método OnClose"
ms.assetid: 96766450-c262-4611-8534-7d190b799142
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::OnClose
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando substituído em uma classe derivada, fecha uma operação assíncrona.  
  
## Sintaxe  
  
```  
virtual void OnClose(  
   void  
) = 0;  
```  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)   
 [Método AsyncBase::Close](../windows/asyncbase-close-method.md)