---
title: "Erro CXX0019 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0019"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0019"
  - "CXX0019"
ms.assetid: 4c6431fd-3310-4a61-934d-58b070b330fe
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0019 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

conversão de tipo incorreto  
  
 O avaliador de expressão C não pode executar conversão de tipos como escrito.  
  
 Esse erro é idêntico a CAN0019.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  O tipo especificado é desconhecido.  
  
2.  Há muitos níveis de tipos do ponteiro.  Por exemplo, a conversão de tipos  
  
    ```  
    (char **)h_message  
    ```  
  
     não pode ser avaliada pelo avaliador de expressão C.