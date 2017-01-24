---
title: "Erro do Compilador C2439 | Microsoft Docs"
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
  - "C2439"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2439"
ms.assetid: 3c5dbe5c-b7d3-4bb0-8619-92f6e280461e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2439
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: o membro não pôde ser inicializado  
  
 Uma classe, uma estrutura, ou um sindicalista não podem ser inicializados.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Tente inicializar uma classe base ou uma estrutura indireta.  
  
2.  Tente inicializar um membro a partir de uma classe ou estrutura.  Um membro herdado deve ser iniciado pelo construtor de classe ou estrutura.