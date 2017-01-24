---
title: "ML Warning A4014 | Microsoft Docs"
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
  - "A4014"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A4014"
ms.assetid: 11bc8920-3255-4ac8-999a-b9ea9c15bc81
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Warning A4014
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

as instruções e dados inicializados não tem suportados em segmentos BSS  
  
 Foi feita uma tentativa para definir dados inicializados dentro de uma seção BSS.  Uma seção BSS é definida como uma classe cujo nome é BSS.  Isso inclui o segmento simplificado `.data?`.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)