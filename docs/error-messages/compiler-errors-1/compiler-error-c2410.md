---
title: "Erro do Compilador C2410 | Microsoft Docs"
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
  - "C2410"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2410"
ms.assetid: b69b2de1-56f3-4ebc-8913-04ac57ffe8a1
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2410
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: nome ambíguo do membro no contexto” “  
  
 O identificador é um membro de mais de uma estrutura ou união neste contexto.  
  
 Use um especificador da estrutura ou da união do operando que causou o erro.  Um especificador da estrutura ou de união é um identificador do tipo `struct` ou `union` \(um nome de `typedef` ou uma variável do mesmo tipo que a estrutura ou a união que estão sendo referenciadas\).  O especificador deve ser o primeiro operando da esquerda do operador membros de seleção \(.\) para usar o operando.