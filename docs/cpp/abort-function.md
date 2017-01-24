---
title: "Fun&#231;&#227;o abort | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "Abort"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função abort"
ms.assetid: 3352bcc4-1a8a-4e1f-8dcc-fe30f6b50f2d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o abort
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A função **abort**, também declarada no arquivo de inclusão padrão STDLIB.H, encerra um programa C\+\+.  A diferença entre **exit** e **abort** é que **exit** permite que o processamento de encerramento do tempo de execução C\+\+ ocorra \(os destruidores de objeto globais serão chamados\), enquanto que **abort** encerra o programa imediatamente.  Para obter mais informações, consulte [abort](../c-runtime-library/reference/abort.md) na *Referência da biblioteca em tempo de execução*.  
  
## Consulte também  
 [Término do programa](../Topic/Program%20Termination.md)