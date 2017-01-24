---
title: "M&#233;todo AsyncBase::OnCancel | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::OnCancel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método OnCancel"
ms.assetid: 4bd0b68e-a9df-4913-9f6c-e093ed55c3f9
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::OnCancel
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando substituído em uma classe derivada, cancela uma operação assíncrona.  
  
## Sintaxe  
  
```  
virtual void OnCancel(  
   void  
) = 0;  
```  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)   
 [Método AsyncBase::Cancel](../Topic/AsyncBase::Cancel%20Method.md)