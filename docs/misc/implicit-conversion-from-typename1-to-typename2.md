---
title: "Convers&#227;o impl&#237;cita de &#39;&lt; typename1 &gt;&#39; para &#39;&lt; typename2 &gt;&#39; | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vbc42016"
  - "BC42016"
helpviewer_keywords: 
  - "BC42016"
ms.assetid: 7dabaab0-8258-4c17-927f-28e61f50bd3a
caps.latest.revision: 11
caps.handback.revision: 11
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Convers&#227;o impl&#237;cita de &#39;&lt; typename1 &gt;&#39; para &#39;&lt; typename2 &gt;&#39;
Uma expressão ou uma instrução de atribuição leva um valor de um tipo de dados e o converte em outro tipo. Como nenhuma palavra\-chave de conversão for usado, a conversão é *implícita*.  
  
 Por padrão, essa mensagem é um aviso. Para obter informações sobre como ocultar avisos ou tratar avisos como erros, consulte [Configurando avisos no Visual Basic](../Topic/Configuring%20Warnings%20in%20Visual%20Basic.md).  
  
 **ID do erro:** BC42016  
  
### Para corrigir este erro  
  
-   Se possível, use valores do mesmo tipo de dados, portanto [!INCLUDE[vbprvb](../Token/vbprvb_md.md)] não precisa fazer nenhuma conversão.  
  
-   Use `CType` ou um dos outras conversão palavras\-chave para que a conversão seja *explícita*.  
  
## Consulte também  
 [Conversões implícitas e explícitas](../Topic/Implicit%20and%20Explicit%20Conversions%20\(Visual%20Basic\).md)   
 [Funções de conversão do tipo](../Topic/Type%20Conversion%20Functions%20\(Visual%20Basic\).md)