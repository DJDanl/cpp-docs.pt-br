---
title: "Compilador C4023 de aviso (n&#237;vel 3) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4023"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4023"
ms.assetid: 615d5374-d7c1-42eb-acfd-917c053270c8
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4023 de aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'symbol': ponteiro baseado passado para a função sem protótipo: número do parâmetro  
  
 Transmitir um ponteiro baseado em uma função sem protótipo faz com que o ponteiro ser normalizados, com resultados imprevisíveis.  
  
 Esse aviso pode ser corrigido se você usar funções de protótipo que são passadas ponteiros baseados.