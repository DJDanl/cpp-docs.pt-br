---
title: "Aviso do compilador (n&#237;vel 1) C4399 | Microsoft Docs"
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
  - "C4399"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4399"
ms.assetid: f58d9ba7-71a0-4c3b-b26f-f946dda8af30
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4399
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo “”: o símbolo do processo não deve ser marcado com \_\_declspec \(dllimport\) quando criado com \/clr:pure  
  
 Os dados de uma imagem nativo ou de imagem com nativo e construções de CLR não podem ser importados para uma imagem pura.  Para resolver esse aviso, compile com **\/clr** \(não **\/clr:pure**\) ou excluir `__declspec(dllimport)`.  
  
## Exemplo  
 O exemplo a seguir produz C4399.  
  
```  
// C4399.cpp  
// compile with: /clr:pure /doc /W1 /c  
__declspec(dllimport) __declspec(process) extern const int i;   // C4399  
```