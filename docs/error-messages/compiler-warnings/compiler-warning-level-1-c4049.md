---
title: "Aviso do compilador (n&#237;vel 1) C4049 | Microsoft Docs"
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
  - "C4049"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4049"
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4049
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

limite do compilador: término da emissão número de linha  
  
 O arquivo contém mais de 16.777.215 linhas de origem<sup>24</sup>\(de 2\-1\).  O compilador do número em 16.777.215.  
  
 Para o código depois da linha 16.777.215:  
  
-   A imagem não conterá nenhuma informação de depuração para números de linha.  
  
-   Alguns diagnóstico podem ser informados com números de linha incorreta.  
  
-   as listagens de .asm \(\/FAs\) podem ter números de linha incorreta.