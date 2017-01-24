---
title: "Operador Event::operator= | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Event::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador operator="
ms.assetid: d8fe9820-8856-4899-9553-56226bdc4945
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador Event::operator=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atribui a referência especificada de eventos à instância atual do evento.  
  
## Sintaxe  
  
```  
WRL_NOTHROW Event& operator=(  
   _Inout_ Event&& h  
);  
```  
  
#### Parâmetros  
 `h`  
 Uma rvalue\- referência a uma instância do evento.  
  
## Valor de retorno  
 Um ponteiro para a instância atual do evento.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe Event \(Biblioteca em Tempo de Execução C\+\+ do Tempo de Execução do Windows\)](../windows/event-class-windows-runtime-cpp-template-library.md)