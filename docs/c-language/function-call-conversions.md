---
title: "Convers&#245;es de fun&#231;&#227;o de chamada | Microsoft Docs"
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
helpviewer_keywords: 
  - "chamadas de função, conversões de tipo de argumento"
  - "chamadas de função, convertendo"
  - "funções [C], conversões de argumento"
ms.assetid: 04ea0f81-509a-4913-8b12-0937a81babcf
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es de fun&#231;&#227;o de chamada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de conversão executado nos argumentos em uma chamada de função depende da presença de um protótipo de função \(declaração de encaminhamento\) com tipos de argumentos declarados para a função chamada.  
  
 Se um protótipo da função estiver presente e incluir tipos de argumentos declarados, o compilador fará a verificação de tipos \(consulte [Funções](../Topic/Functions%20\(C\).md)\).  
  
 Se nenhum protótipo da função estiver presente, somente as conversões aritméticas comuns serão executadas nos argumentos na chamada da função.  Essas conversões são executadas independentemente em cada argumento na chamada.  Isso significa que um valor **float** será convertido em **double**; um valor `char` ou **short** é convertido em `int`; e `unsigned char` ou **unsigned short** é convertido em `unsigned int`.  
  
## Consulte também  
 [Conversões de tipo](../c-language/type-conversions-c.md)