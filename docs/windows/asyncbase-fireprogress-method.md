---
title: "M&#233;todo AsyncBase::FireProgress | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::FireProgress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FireProgress"
ms.assetid: 4512bef6-0ebc-4465-9b8a-4c9dfa82084c
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::FireProgress
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Invoca o manipulador de eventos atual do progresso.  
  
## Sintaxe  
  
```  
void FireProgress(  
   const typename ProgressTraits::Arg2Type arg  
);  
```  
  
#### Parâmetros  
 `arg`  
 O método do manipulador de eventos invocá\-lo.  
  
## Comentários  
 `ProgressTraits` é derivado de [Estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md).  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)