---
title: "ML Nonfatal Error A2096 | Microsoft Docs"
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
  - "A2096"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A2096"
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Nonfatal Error A2096
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**segmento, grupo ou a espera de registrador de segmento**  
  
 Um segmento ou o grupo era esperado, mas não foi encontrado.  
  
 Ao se um destes procedimentos:  
  
-   O operando esquerdo especificado com o segmento de substituir o operador \(**:**\) não era um segmento register \(CS, DS, SS, ES, FS ou GS\), nome do grupo, nome do segmento ou expressão de segmento.  
  
-   O  [presumir que](../../assembler/masm/assume.md) diretiva foi fornecida um registrador de segmento sem um endereço válido de segmento, registrador de segmento, grupo ou a sintaxe especial  **FLAT** grupo.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)