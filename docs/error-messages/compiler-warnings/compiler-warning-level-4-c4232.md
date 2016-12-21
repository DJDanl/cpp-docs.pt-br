---
title: "Aviso do compilador (n&#237;vel 4) C4232 | Microsoft Docs"
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
  - "C4232"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4232"
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4232
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: “identificador”: o endereço de dllimport “dllimport” não é estático, identidade não garantida  
  
 Nas extensões da Microsoft \(\/Ze\), você pode fornecer um valor não estático como o endereço de uma função declarada com o modificador de **dllimport** .  Na compatibilidade ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\), isso causa um erro.  
  
 O seguinte exemplo gera C4232:  
  
```  
// C4232.c  
// compile with: /W4 /Ze /c  
int __declspec(dllimport) f();  
int (*pfunc)() = &f;   // C4232  
```