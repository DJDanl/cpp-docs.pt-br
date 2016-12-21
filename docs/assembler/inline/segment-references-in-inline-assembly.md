---
title: "Refer&#234;ncias de segmento em assembly embutido | Microsoft Docs"
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
helpviewer_keywords: 
  - "assembly embutido, registros"
  - "assembly embutido, referências de segmento"
  - "referências, assembly embutido"
  - "registros"
  - "registros, assembly embutido"
  - "referências de segmento em assembly embutido"
ms.assetid: c63e6bb4-49d9-4fa1-bb22-eea21b5cbc0f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Refer&#234;ncias de segmento em assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Você deve se referir a segmentos pelo registro em vez de por nome \(o nome de segmento `_TEXT` for inválido, por exemplo\).  As substituições da partição devem usar o registro explicitamente, como em ES: \[\] BX.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando linguagem de assembly em blocos de \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)