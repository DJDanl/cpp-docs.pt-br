---
title: "Erro CXX0024 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0024"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0024"
  - "CXX0024"
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0024 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a operação precisa do valor l\-  
  
 Uma expressão que não é avaliada para um valor l\- foi especificada para uma operação que requer um valor l\-.  
  
 Um valor l\- \(também chamado porque é exibido no lado esquerdo de uma instrução de atribuição\) é uma expressão que referencie um local de memória.  
  
 Por exemplo, `buffer[count]` é um valor válido porque l\- aponta para um local de memória específico.  A comparação lógica `zed != 0` não é um l\- valor válido porque é avaliada como RETIFICAR ou FALSE, não a um endereço de memória.  
  
 Esse erro é idêntico a CAN0024.