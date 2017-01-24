---
title: "Aviso do compilador (n&#237;vel 4) C4092 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4092"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4092"
ms.assetid: 396ae826-a892-4327-bd66-f4762376d72b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4092
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o sizeof retorna “longo sem assinatura”  
  
 O operando do operador de `sizeof` era muito grande, assim `sizeof` retornado **long**sem assinatura.  Esse aviso ocorre nas extensões da Microsoft \([\/Ze](../../build/reference/za-ze-disable-language-extensions.md)\).  Na compatibilidade ANSI \(\/Za\), o resultado é truncado em vez disso.