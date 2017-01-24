---
title: "Maior tamanho da matriz | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
ms.assetid: 4c782cf6-73f3-40b0-b306-229d22da4ee1
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Maior tamanho da matriz
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.3.3.4, 4.1.1** O tipo de inteiro necessário para manter o tamanho máximo de uma matriz – ou seja, o tamanho de **size\_t**.  
  
 O typedef `size_t` é `unsigned int` na plataforma x86 de 32 bits.  Em plataformas de 64 bits, o typedef `size_t` é **unsigned \_\_int64**.  
  
## Consulte também  
 [Matrizes e ponteiros](../c-language/arrays-and-pointers.md)