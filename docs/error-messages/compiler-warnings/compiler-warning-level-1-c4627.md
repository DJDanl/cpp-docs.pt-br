---
title: "Compilador C4627 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4627"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4627"
ms.assetid: 8840f3e6-b496-423a-8635-eb55d5f854a2
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4627 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'\< identificador \>': ignorados quando procurando pré\-compilados uso do cabeçalho  
  
 Ao procurar o local onde um cabeçalho pré\-compilado é usado, o compilador encontrou um `#include` diretriz para a *\< identificador \>* arquivo de inclusão. O compilador ignora o `#include` diretiva, mas emite aviso **C4627** se o cabeçalho pré\-compilado ainda não contiver o *\< identificador \>* arquivo de inclusão.  
  
## Consulte também  
 [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)