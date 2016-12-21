---
title: "C3552 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3552"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3552"
ms.assetid: 83401524-1bf1-44c0-8aca-a6eb35c4224c
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3552 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'typename': um tipo de retorno especificado final não pode conter 'auto'  
  
 Se você usar o `auto` palavra\-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno especificado tardia. No entanto, você não pode usar outro `auto` palavra\-chave para especificar o tipo de retorno a especificação tardia. Por exemplo, o fragmento de código a seguir gera erro C3552.  
  
 `auto myFunction->auto; // C3552`