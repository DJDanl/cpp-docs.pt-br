---
title: "Regras de consist&#234;ncia do cabe&#231;alho pr&#233;-compilado | Microsoft Docs"
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
helpviewer_keywords: 
  - "arquivos de cabeçalho pré-compilado, regras de consistência"
ms.assetid: 844b1a14-5b0b-4276-a1f5-cc62f13f6dda
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Regras de consist&#234;ncia do cabe&#231;alho pr&#233;-compilado
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta seção aborda as diretrizes que o ajudarão a forma mais eficiente usar cabeçalhos pré\-compilados:  
  
-   [Regras de consistência para o uso de um Arquivo por vez de cabeçalhos pré\-compilados](../../build/reference/consistency-rules-for-per-file-use-of-precompiled-headers.md)  
  
-   [Regras de consistência para \/Yc e \/Yu](../../build/reference/consistency-rules-for-yc-and-yu.md)  
  
 Como os arquivos de PCH contêm informações sobre o ambiente do computador bem como informações de endereço de memória sobre o programa, você só deve usar um arquivo de PCH no computador em que foi criado.  
  
## Consulte também  
 [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)