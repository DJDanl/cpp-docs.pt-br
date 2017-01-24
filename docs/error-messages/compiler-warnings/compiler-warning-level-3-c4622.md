---
title: "Compilador C4622 de aviso (n&#237;vel 3) | Microsoft Docs"
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
  - "C4622"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4622"
ms.assetid: d3c879f0-4492-4f4b-b26d-230993f3a933
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4622 de aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Substituição de informações de depuração formada durante a criação do cabeçalho pré\-compilado no arquivo de objeto: 'arquivo'  
  
 Informações de CodeView no arquivo especificado foi perdidas quando ele foi compilado com o [\/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção \(usar cabeçalhos pré\-compilados\).  
  
 Renomeie o arquivo de objeto \(usando [\/Fo](../../build/reference/fo-object-file-name.md)\) ao criar ou usando o cabeçalho pré\-compilado arquivo e usar o novo arquivo de objeto de link.