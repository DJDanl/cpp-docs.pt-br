---
title: "M&#233;todo AsyncBase::FireCompletion | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::FireCompletion"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FireCompletion"
ms.assetid: b5e29d6d-52e7-4148-a7f3-a313b1359819
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::FireCompletion
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Invoca o manipulador de eventos de conclusão, ou redefine o delegado interno de progresso.  
  
## Sintaxe  
  
```  
void FireCompletion(  
   void  
) override;  
  
virtual void FireCompletion();  
```  
  
## Comentários  
 A primeira versão de FireCompletion\(\) redefine a variável interno delegado do progresso.  A segunda versão invoca o manipulador de eventos de conclusão se a operação assíncrona está completo.  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)