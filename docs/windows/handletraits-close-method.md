---
title: "M&#233;todo HANDLETraits::Close | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::Close"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Close"
ms.assetid: 3c631a7c-ccce-472a-b1da-aab8fa815c13
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo HANDLETraits::Close
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
 [Estrutura HANDLETraits](../windows/handletraits-structure.md)