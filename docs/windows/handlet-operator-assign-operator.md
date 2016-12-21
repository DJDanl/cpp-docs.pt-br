---
title: "Operador HandleT::operator= | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleT::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador operator="
ms.assetid: 9e42dcca-30fa-4e8b-8954-802fd64a5595
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador HandleT::operator=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Move o valor do objeto especificado de HandleT ao objeto atual de HandleT.  
  
## Sintaxe  
  
```  
HandleT& operator=(  
   _Inout_ HandleT&& h  
);  
```  
  
#### Parâmetros  
 `h`  
 Uma rvalue\- referência a um identificador.  
  
## Valor de retorno  
 Uma referência ao objeto atual de HandleT.  
  
## Comentários  
 Essa operação invalida o objeto de HandleT especificado pelo parâmetro `h`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HandleT](../Topic/HandleT%20Class.md)