---
title: "Registros salvos de chamador/receptor | Microsoft Docs"
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
ms.assetid: 0533bd4b-d6bb-4ce1-8201-495e16870cbb
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Registros salvos de chamador/receptor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os registros RAX, RCX, RDX, R8, R9, R10, R11 são considerados voláteis e devem ser considerados destruído em chamadas de função \(a menos que de outro modo de segurança provable pela análise como a otimização de programa inteiro\).  
  
 Os registros RBX, RBP, RDI, RSI, RSP, R12, R13, R14, e R15 são considerados permanentes e devem ser salvos e restaurado por uma função que os usa.  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)