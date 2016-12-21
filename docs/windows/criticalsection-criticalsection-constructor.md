---
title: "Construtor CriticalSection::CriticalSection | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::CriticalSection::CriticalSection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Seção crítica, o construtor"
ms.assetid: 930b89be-4d74-46bd-8879-5dd4d15bcbd0
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor CriticalSection::CriticalSection
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa um objeto de sincronização que é semelhante a um objeto do mutex, mas pode ser usado somente por threads de um único processo.  
  
## Sintaxe  
  
```  
explicit CriticalSection(  
   ULONG spincount = 0  
);  
```  
  
#### Parâmetros  
 `spincount`  
 A contagem de rotação do objeto da seção crítica.  O valor padrão é 0.  
  
## Comentários  
 Para obter mais informações sobre as seções e de spincounts crticial, consulte a função de **InitializeCriticalSectionAndSpinCount** na seção de sincronização do SDK de apis do windows.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe CriticalSection](../Topic/CriticalSection%20Class.md)