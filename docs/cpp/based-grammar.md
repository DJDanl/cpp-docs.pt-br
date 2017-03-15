---
title: "Gram&#225;tica __based | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "abordando com base em"
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gram&#225;tica __based
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados \(dados estáticos e com base dinâmica\).  
  
 O único formulário aceitável de endereçamento baseado em compilações de 32 bits e de 64 bits é o “baseado em um ponteiro”, que define um tipo que contém um deslocamento de 32 bits ou de 64 bits para uma base de 32 bits ou de 64 bits, ou com base em `void`.  
  
## Gramática  
 *based\-range\-modifier*:  
 **\_\_based\(**  *base\-expression*  **\)**  
  
 *base\-expression*:  
 *based\-variablebased\-abstract\-declaratorsegment\-namesegment\-cast*  
  
 *based\-variable*:  
 *identifier*  
  
 *based\-abstract\-declarator*:  
 *abstract\-declarator*  
  
 *base\-type*:  
 *type\-name*  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Ponteiros baseados](../Topic/Based%20Pointers%20\(C++\).md)