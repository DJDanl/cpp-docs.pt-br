---
title: "ML Nonfatal Error A2133 | Microsoft Docs"
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
  - "A2133"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A2133"
ms.assetid: 5ba50911-22c8-43b7-90e2-946fc612e05f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Nonfatal Error A2133
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**registrar o valor substituído pelo INVOKE**  
  
 Um registro foi passado como um argumento para um procedimento, mas o código gerado pelo  [INVOKE](../../assembler/masm/invoke.md) passar outros argumentos destruído o conteúdo do registrador.  
  
 Os registradores AX, AL, AH, EAX, DX, DL, DH e EDX podem ser usados pelo montador para realizar a conversão de dados.  
  
 Use um registro diferente.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)