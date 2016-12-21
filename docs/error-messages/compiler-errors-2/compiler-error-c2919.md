---
title: "Compiler Error C2919 | Microsoft Docs"
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
  - "C2919"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2919"
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compiler Error C2919
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': não não possível usar operadores a superfície publicada de um tipo WinRT  
  
 O sistema de tipos do tempo de execução do Windows não oferece suporte a funções de membro do operador na superfície de publicada de um tipo.  Isso ocorre porque nem todas as linguagens podem consumir funções de membro de operador.  Você pode criar funções de membro que podem ser chamadas de código C\+\+ na mesma unidade de compilação ou de classe do operador particular ou interno.  
  
 Para corrigir esse problema, remova a função de membro do operador da interface pública ou alterá\-la para uma função de membro nomeado.  Por exemplo, em vez de `operator==`, nomeie a função de membro `Equals`.