---
title: "Enumera&#231;&#227;o AsyncResultType | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncResultType"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Enumeração AsyncResultType"
ms.assetid: 4195d234-3f3f-4363-9118-6ad2a7551cf2
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#227;o AsyncResultType
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o tipo de resultado retornado pelo método de GetResults\(\) .  
  
## Sintaxe  
  
```  
enum AsyncResultType;  
```  
  
## Membros  
  
### Valores  
  
|Nome|Descrição|  
|----------|---------------|  
|`MultipleResults`|Um conjunto de vários resultados, que são apresentados progressivamente entre o estado inicial e antes que Close\(\) seja chamado.|  
|`SingleResult`|Um único resultado, que é apresentado após o evento completa ocorrer.|  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)