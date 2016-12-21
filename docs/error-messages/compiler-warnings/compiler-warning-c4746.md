---
title: "Aviso do compilador C4746 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
dev_langs: 
  - "C++"
ms.assetid: 5e79ab46-6031-499a-a986-716c866b6c0e
caps.latest.revision: 2
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador C4746
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o acesso temporário '\<da\>' expressão está sujeito a \/volatile: \[ISO&#124;configuração ms\-\]; considere usar funções intrínsecas de \_\_iso\_volatile\_load\/store.  
  
 C4746 é emitido sempre que uma variável temporário é acessado diretamente.  O objetivo de ajudar os desenvolvedores a identificar os locais de código que são afetadas pelo modelo específico de volátil especificado atualmente \(que pode ser controlado com a opção do compilador de [\/volatile](../../build/reference/volatile-volatile-keyword-interpretation.md) \).  Em particular, pode ser útil para localizar barreiras completo gerados de memória de hardware quando \/volatile:ms é usado.  
  
 Os intrinsics de \_\_iso\_volatile\_load\/store podem ser usados para acessar explicitamente a memória volátil sem ser afetada pelo modelo temporário.  Usando esses intrinsics não irá C4746.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para maiores informações.