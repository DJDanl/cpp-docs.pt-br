---
title: "Erro fatal C1210 | Microsoft Docs"
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
  - "C1210"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1210"
ms.assetid: e2208309-c284-425c-a7e8-48e96e66f35b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1210
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\/CLR: puro e \/CLR: safe não são suportados pela versão do tempo de execução instalada  
  
 C1210 ocorre quando você tem um compilador para a versão atual, mas um common language runtime de uma versão anterior.  
  
 Algumas funcionalidades do compilador não podem funcionar em uma versão anterior do tempo de execução.  
  
 Para resolver C1210 instalar a versão de tempo de execução de linguagem comum que é destinada para uso com o compilador.