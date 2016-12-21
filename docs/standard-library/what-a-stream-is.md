---
title: "O que &#233; um fluxo | Microsoft Docs"
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
helpviewer_keywords: 
  - "dados [C++], lendo"
  - "lendo dados [C++], programação iostream"
  - "fluxos [C++]"
  - "fluxos [C++], em classes iostream"
ms.assetid: a7e661e9-6cd1-4543-a9a4-c58ee9fd32f3
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# O que &#233; um fluxo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como C, C\+\+ 2.0 não tem o recurso interno de entrada\/saída.  Todos os compiladores C\+\+, porém, vindos empacotado com um pacote sistêmico, orientado a objeto de E\/S, conhecido como o iostream classe.  O fluxo é o conceito central das classes iostream.  Você pode pensar em um objeto de fluxo como um arquivo inteligente que atue como uma origem e um destino para bytes.  As características de um fluxo são determinadas pela classe e por operadores personalizados de inserção e de extração.  
  
 Nos drivers de dispositivo, o sistema operacional de disco controla o teclado, a tela, a impressora, e as portas de comunicação como arquivos estendidos.  As classes iostream interagem com esses arquivos estendidos.  As classes internos dão suporte à leitura e a gravação da memória com a sintaxe idêntica à do disco E\/S, o que facilita derivar classes de fluxo.  
  
## Nesta seção  
 [Alternativas de Entrada\/Saída](../standard-library/input-output-alternatives.md)  
  
## Consulte também  
 [Programação iostream](../Topic/iostream%20Programming.md)