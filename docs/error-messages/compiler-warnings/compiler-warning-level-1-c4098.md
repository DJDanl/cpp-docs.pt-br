---
title: "Aviso do compilador (n&#237;vel 1) C4098 | Microsoft Docs"
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
  - "C4098"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4098"
ms.assetid: 8c8aef1c-1639-44ec-a3dd-c0dfe9aa727d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4098
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: função vaga que retorna um valor  
  
 Uma função declarada com o tipo de retorno [nulo](../../cpp/void-cpp.md) tiver uma instrução de `return` que retorna um valor.  O compilador assume a função retornará um valor do tipo `int`.