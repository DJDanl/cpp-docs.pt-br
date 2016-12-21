---
title: "M&#233;todo Implements::FillArrayWithIid | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Implements::FillArrayWithIid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FillArrayWithIid"
ms.assetid: b2e62e3f-0ab9-4c70-aad7-856268544f44
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Implements::FillArrayWithIid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Insere a ID da interface especificado pelo parâmetro atual do modelo de zeroth no elemento da matriz especificado.  
  
## Sintaxe  
  
```  
__forceinline static void FillArrayWithIid(  
   unsigned long &index,  
   _In_ IID* iids  
);  
```  
  
#### Parâmetros  
 `index`  
 Um índice com base em zero indica que o elemento da matriz inicial para esta operação.  Quando esta operação for concluída, `index` será incrementado em 1.  
  
 `iids`  
 Uma matriz do tipo IID.  
  
## Comentários  
 Função interna de auxiliar.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Implementa estrutura](../Topic/Implements%20Structure.md)