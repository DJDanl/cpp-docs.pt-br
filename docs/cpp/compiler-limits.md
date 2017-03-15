---
title: "Limites do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, limites para construções de linguagem"
ms.assetid: f1fa59c6-55b4-414b-80c5-3df72952160d
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limites do compilador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O padrão do C\+\+ recomenda limites para várias construções de linguagem.  A lista a seguir contém casos onde o compilador do Visual C\+\+ não implementa os limites recomendados.  O primeiro número é o limite estabelecido no padrão ISO C\+\+11 \(INCITS\/ISO\/IEC 14882\-2011\[2012\], Anexo B\) e o segundo número é o limite implementado pelo Visual C\+\+:  
  
-   Níveis de aninhamento de instruções compostas, estruturas de controle de iteração e estruturas de controle de seleção \[padrão C\+\+: 256\] \(Compilador do Visual C\+\+: dependem da combinação de instruções que são aninhadas, mas geralmente entre 100 e 110\).  
  
-   Parâmetros em uma definição de macro \[padrão C\+\+: 256\] \(Compilador do Visual C\+\+:127\).  
  
-   Parâmetros em uma invocação de macro \[padrão C\+\+: 256\] \(Compilador do Visual C\+\+:127\).  
  
-   Caracteres em uma cadeia de caracteres literal ou em uma cadeia de caracteres largos literal \(depois da concatenação\) \[padrão C\+\+: 65536\] \(Compilador do Visual C\+\+: 65535 caracteres de byte único, incluindo o terminador `null` e caracteres de byte duplo 32767, incluindo o terminador `null`\).  
  
-   Níveis de classes, estrutura ou união aninhadas em uma única `struct-declaration-list` \[padrão C\+\+: 256\] \(Compilador do Visual C\+\+: 16\).  
  
-   Inicializadores de membro em uma definição de construtor \[padrão C\+\+: 6144\] \(Compilador do Visual C\+\+:6144\).  
  
-   Qualificações do escopo de um identificador \[padrão C\+\+: 256\] \(Compilador do Visual C\+\+:127\).  
  
-   Especificações aninhadas `extern` \[padrão C\+\+: 1024\] \(Compilador do Visual C\+\+: 9 \(não conta a especificação implícita `extern` no escopo global ou 10, caso conte a especificação implícita `extern` no escopo global\).  
  
-   Argumentos do modelo em uma declaração de modelo \[padrão C\+\+: 1024\] \(Compilador do Visual C\+\+:2046\).  
  
## Consulte também  
 [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md)