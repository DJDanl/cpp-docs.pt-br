---
title: "ML Nonfatal Error A2085 | Microsoft Docs"
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
  - "A2085"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A2085"
ms.assetid: c2fef415-a32b-4249-896c-6d981fc6e327
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Nonfatal Error A2085
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**instrução ou o registro não é aceito no modo atual de CPU**  
  
 Houve uma tentativa de usar uma instrução, registrar ou palavra\-chave que não era válido para o modo atual do processador.  
  
 Por exemplo, os registradores de 32 bits exigem  [. 386](../Topic/.386.md) ou superior.  Registradores de controle, como CR0 exigem o modo privilegiado  [.386P](../../assembler/masm/dot-386p.md) ou superior.  Este erro também será gerado para o  **NEAR32**,  **FAR32**, e  **FLAT** palavras\-chave, que requerem. **386** ou superior.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)