---
title: "Erro CXX0017 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0017"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0017"
  - "CXX0017"
ms.assetid: af74db02-a64d-49ca-8363-3e044a107580
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0017 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo não encontrado  
  
 Um símbolo especificado em uma expressão não pôde ser localizado.  
  
 Uma possível causa desse erro é uma incompatibilidade de casos no nome de símbolo.  Porque C e C\+\+ 2.0 são idiomas com diferenciação de maiúsculas e minúsculas, um nome de símbolo deve ser determinado em caso exato em que é definido na origem.  
  
 Esse erro pode ocorrer ao tentar typecast uma variável para inspecionar a variável durante a depuração.  `typedef` declara um novo nome para um tipo, mas não define um novo tipo.  O typecast tentado no depurador requer o nome de um tipo definido.  
  
 Esse erro é idêntico a CAN0017.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Verifique se o símbolo é declarado no ponto no programa onde está sendo usado.  
  
2.  Use um nome real do tipo para converter variáveis no depurador, em vez de `typedef`\- nome definido.