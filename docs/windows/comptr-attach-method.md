---
title: "M&#233;todo ComPtr::Attach | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::Attach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Attach"
ms.assetid: 5b911f2d-9830-4dc7-b9e3-527abd55d2c8
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ComPtr::Attach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Associa este ComPtr com o tipo de interface especificado pelo parâmetro de tipo atual do modelo.  
  
## Sintaxe  
  
```  
void Attach(  
   _In_opt_ InterfaceType* other  
);  
```  
  
#### Parâmetros  
 `other`  
 Um tipo de interface.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)