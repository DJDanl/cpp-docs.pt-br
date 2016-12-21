---
title: "Erro do Compilador C2223 | Microsoft Docs"
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
  - "C2223"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2223"
ms.assetid: e4506f0f-0317-4a96-8a90-877a156d7939
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2223
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a esquerda do identificador “\-\>” deve apontar para o struct\/união  
  
 O operando à esquerda de `->` não é um ponteiro para uma classe, a uma estrutura, ou uma união.  
  
 Esse erro pode ser causado por um operando esquerdo que é uma variável indefinido \(como consequência tipo `int`\).