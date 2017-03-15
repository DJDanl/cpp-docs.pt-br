---
title: "ML Warning A4012 | Microsoft Docs"
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
  - "A4012"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A4012"
ms.assetid: 842b1259-9679-4eeb-a02d-672a583a94e5
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Warning A4012
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**informações sobre números de linha para o segmento sem classe 'CODE'**  
  
 Havia instruções em um segmento que não tinha um nome de classe que termina com "Código". O montador não gerou informações do CodeView para estas instruções.  
  
 CodeView não pode processar os módulos de código em segmentos com nomes de classe que não terminam com "Código".  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)