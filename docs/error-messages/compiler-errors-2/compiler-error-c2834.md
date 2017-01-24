---
title: "Erro do Compilador C2834 | Microsoft Docs"
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
  - "C2834"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2834"
ms.assetid: 28f9f6eb-ab2a-4e64-aaaa-9d14f955de41
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2834
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador operador” deve ser qualificado global  
  
 Os operadores de `new` e de `delete` forem associados à classe onde residem.  A resolução de escopo não pode ser usada para selecionar uma versão de `new` ou de `delete` de uma classe diferente.  Para implementar várias formas de operador de `new` ou de `delete` , crie uma versão do operador com os parâmetros formais adicionais.