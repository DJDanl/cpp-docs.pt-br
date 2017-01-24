---
title: "M&#233;todo HANDLENullTraits::Close | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::Close"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Close"
ms.assetid: 6fb2fa0d-df20-45dc-856f-f78497f8bdf9
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo HANDLENullTraits::Close
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fecha o identificador especificado.  
  
## Sintaxe  
  
```  
inline static bool Close(  
   _In_ Type h  
);  
```  
  
#### Parâmetros  
 `h`  
 O identificador para fechar.  
  
## Valor de retorno  
 **true** se o identificador `h` se é encerrado com êxito; caso contrário, **false**.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Estrutura HANDLENullTraits](../windows/handlenulltraits-structure.md)