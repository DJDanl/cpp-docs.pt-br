---
title: "Erro do Compilador C2307 | Microsoft Docs"
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
  - "C2307"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2307"
ms.assetid: ce6c8033-a673-4679-9883-bedec36ae385
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2307
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o pragma “pragma” deve ser função externa se a compilação incremental é habilitada  
  
 Você deve colocar o pragma de `data_seg` entre funções se você estiver usando a compilação incremental.