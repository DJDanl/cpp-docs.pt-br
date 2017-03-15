---
title: "Construtor Event::Event (Biblioteca em Tempo de Execu&#231;&#227;o C++ do Tempo de Execu&#231;&#227;o do Windows) | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Event::Event"
dev_langs: 
  - "C++"
ms.assetid: 21495297-9612-4095-9256-16e168cc0021
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor Event::Event (Biblioteca em Tempo de Execu&#231;&#227;o C++ do Tempo de Execu&#231;&#227;o do Windows)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe Event.  
  
## Sintaxe  
  
```  
explicit Event(  
   HANDLE h = HandleT::Traits::GetInvalidValue()  
);  
WRL_NOTHROW Event(  
   _Inout_ Event&& h  
);  
```  
  
#### Parâmetros  
 `h`  
 Manipular um evento.  Por padrão, `h` é inicializado como `nullptr`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe Event \(Biblioteca em Tempo de Execução C\+\+ do Tempo de Execução do Windows\)](../windows/event-class-windows-runtime-cpp-template-library.md)