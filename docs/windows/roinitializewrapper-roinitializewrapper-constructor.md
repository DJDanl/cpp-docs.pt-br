---
title: "Construtor RoInitializeWrapper::RoInitializeWrapper | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper"
dev_langs: 
  - "C++"
ms.assetid: c6f7fb07-14af-4574-9135-cea164607f30
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor RoInitializeWrapper::RoInitializeWrapper
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe de RoInitializeWrapper.  
  
## Sintaxe  
  
```cpp  
RoInitializeWrapper(  
   RO_INIT_TYPE flags)  
  
```  
  
#### Parâmetros  
 `flags`  
 Uma das enumerações de RO\_INIT\_TYPE, que especifica o suporte fornecido por [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
## Comentários  
 A classe de RoInitializeWrapper invoca Windows::Foundation::Initialize \(*flags*\).  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HandleT](../Topic/HandleT%20Class.md)