---
title: "Aviso do compilador (n&#237;vel 3) C4723 | Microsoft Docs"
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
  - "C4723"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4723"
ms.assetid: 07669d14-3fd8-4a43-94bc-b61c50e58460
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4723
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

potencialmente divisão por 0  
  
 O segundo operando em uma operação de divisão avaliada como zero em tempo de compilação, dando resultados indefinidos.  
  
 Esse aviso é emitido somente ao usar [\/Og](../../build/reference/og-global-optimizations.md) ou uma opção de otimização que implica \/Og.  
  
 O compilador pode ter gerado o operando zero.