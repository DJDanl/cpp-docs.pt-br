---
title: "Destruidor RoInitializeWrapper::~RoInitializeWrapper | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::~RoInitializeWrapper"
dev_langs: 
  - "C++"
ms.assetid: afef4c1f-ffde-4cd2-8654-8de4182eb5f4
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Destruidor RoInitializeWrapper::~RoInitializeWrapper
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uninitializes [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```cpp  
~RoInitializeWrapper()  
```  
  
## Comentários  
 A classe de RoInitializeWrapper invoca Windows::Foundation::Uninitialize\(\).  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HandleT](../Topic/HandleT%20Class.md)