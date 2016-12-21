---
title: "Aviso do compilador (n&#237;vel 4) C4234 | Microsoft Docs"
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
  - "C4234"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4234"
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4234
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: palavra\-chave “palavra\-chave” reservado para uso futuro  
  
 O compilador não implementa ainda a palavra\-chave usado.  
  
 Esse aviso é alto automaticamente em um erro.  Se você quiser alterar esse comportamento, use [aviso de \#pragma](../../preprocessor/warning.md).  Por exemplo, para fazer C4234 em um problema de aviso de nível 4,  
  
```  
#pragma warning(2:4234)  
```  
  
 em seu arquivo de código\-fonte.