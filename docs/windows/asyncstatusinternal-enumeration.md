---
title: "Enumera&#231;&#227;o AsyncStatusInternal | Microsoft Docs"
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
  - "async/Microsoft::WRL::Details::AsyncStatusInternal"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Enumeração AsyncStatusInternal"
ms.assetid: b783923f-3f1c-4487-9384-be572cbc62d7
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#227;o AsyncStatusInternal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
enum AsyncStatusInternal;  
```  
  
## Comentários  
 Especifica um mapeamento entre enumerações internas para o estado de operações assíncronas e a enumeração de **Windows::Foundation::AsyncStatus** .  
  
## Membros  
 `_Created`  
 Equivalente ao ::Windows::Foundation::AsyncStatus::Created  
  
 `_Started`  
 Equivalente ao ::Windows::Foundation::AsyncStatus::Started  
  
 `_Completed`  
 Equivalente ao ::Windows::Foundation::AsyncStatus::Completed  
  
 `_Cancelled`  
 Equivalente ao ::Windows::Foundation::AsyncStatus::Cancelled  
  
 `_Error`  
 Equivalente ao ::Windows::Foundation::AsyncStatus::Error  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)