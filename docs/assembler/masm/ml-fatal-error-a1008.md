---
title: "ML Fatal Error A1008 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "A1008"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A1008"
ms.assetid: fe592f9d-c37b-4cd8-a51d-e3c15ddcab83
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Fatal Error A1008
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**aninhamento de macro incomparável**  
  
 Tanto uma macro não foi encerrada antes do final do arquivo ou a diretiva de terminação  [ENDM](../../assembler/masm/endm.md) foi encontrado fora de um bloco de macro.  
  
 Uma causa deste erro é a omissão do ponto antes de  [.Repetir](../../assembler/masm/dot-repeat.md) ou  [.ENQUANTO](../../assembler/masm/dot-while.md).  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)