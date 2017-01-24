---
title: "Erro fatal C1126 | Microsoft Docs"
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
  - "C1126"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1126"
ms.assetid: f22b26a6-8ad7-47cf-a237-196c8ea60aca
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1126
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: a alocação exceder o tamanho automático  
  
 O espaço alocado para variáveis locais de uma função \(mais uma quantidade de espaço limitada usada pelo compilador, como um acréscimo 20 bytes para funções swappable\) excede o limite.  
  
 Para corrigir esse erro, use `malloc` ou `new` atribuir grandes quantidades de dados.