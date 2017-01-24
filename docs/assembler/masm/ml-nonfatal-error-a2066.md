---
title: "ML Nonfatal Error A2066 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "A2066"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A2066"
ms.assetid: 58220fdf-fb8f-47fc-a36d-737867361185
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Nonfatal Error A2066
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**tamanho incompatível de modo e o segmento de CPU**  
  
 Foi feita uma tentativa para abrir um segmento com um  **USE16**,  **USE32**, ou  **FLAT** atributo que não era compatível com a CPU especificada, ou para alterar para uma CPU de 16 bits enquanto estiver em um segmento de 32 bits.  
  
 O  **USE32** e  **FLAT** atributos devem ser precedidos pela. 386 ou diretiva maior do processador.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)