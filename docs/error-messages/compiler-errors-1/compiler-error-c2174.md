---
title: "Erro do Compilador C2174 | Microsoft Docs"
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
  - "C2174"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2174"
ms.assetid: 161d563c-76e9-47e9-9142-7812e9ea169e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2174
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: o parâmetro real tem o tipo “nulo”: parâmetro number1, a lista de parâmetros number2  
  
 O parâmetro `number1` passado à lista de parâmetros `number2` é um parâmetro de `void` .  Os parâmetros não podem ter o tipo `void`.  Use `void*` em vez disso.