---
title: "Intr&#237;nsecos e assembly embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 8affd4bb-279d-46f3-851f-8be0a9c5ed3f
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Intr&#237;nsecos e assembly embutido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma das restrições para o compilador de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] é não ter nenhum suporte embutido de assembler.  Isso significa que as funções que não podem ser gravadas em C ou C\+\+ qualquer um precisarão ser gravadas como sub\-rotina ou como as funções intrínsecas suportadas pelo compilador.  Determinadas funções são desempenho confidenciais quando outro não são.  Funções de desempenho confidenciais devem ser implementadas como funções intrínsecas.  
  
 Os intrinsics suportados pelo compilador são descritos em [Intrinsics do compilador](../intrinsics/compiler-intrinsics.md).  
  
## Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)