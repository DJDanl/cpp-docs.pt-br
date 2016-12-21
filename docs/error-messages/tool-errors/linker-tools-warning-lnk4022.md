---
title: "Aviso LNK4022 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4022"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4022"
ms.assetid: 890f487e-db98-45dd-a226-c7ccead82b1e
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4022 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível encontrar a correspondência exclusivo para o símbolo “símbolo”  
  
 O LINK ou as correspondências encontradas LIB de vários para o símbolo e ele undecorated dados não pôde resolver a ambiguidade.  Nenhum arquivo de saída \(.exe, .dll, .exp, ou .lib\) é gerado.  Esse aviso é seguido por um aviso [LNK4002](../../error-messages/tool-errors/linker-tools-warning-lnk4002.md) para cada símbolo duplicada e finalmente seguido pelo erro fatal [LNK1152](../../error-messages/tool-errors/linker-tools-error-lnk1152.md).  
  
 Para evitar esse aviso, especifique o símbolo em sua forma decorado.  Executar [DUMPBIN](../../build/reference/dumpbin-options.md) no objeto para consultar nomes decorados.