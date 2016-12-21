---
title: "Aviso do compilador (n&#237;vel 4) C4611 | Microsoft Docs"
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
  - "C4611"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4611"
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4611
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a interação entre a destruição de função” e “do objeto C\+\+ não é portátil  
  
 Em algumas plataformas, as funções que incluem **catch** não podem dar suporte a semântica do objeto C\+\+ de destruição quando fora do escopo.  
  
 Para evitar comportamento inesperado, evite usar **catch** em funções que têm construtores e destruidores.  
  
 Esse aviso é emitido somente uma vez; consulte [aviso de pragma](../../preprocessor/warning.md).