---
title: "Inicializa&#231;&#227;o e encerramento de programas em C++ | Microsoft Docs"
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
  - "fluxos de texto de controle"
  - "procedimentos da função Main"
  - "Função main, inicialização de programa"
  - "Biblioteca Padrão C++, inicialização e encerramento de programas"
  - "código de inicialização, e encerramento de programas em C++"
  - "terminando a execução"
ms.assetid: f72c8f76-f507-4ddd-a270-7b60f4fed625
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Inicializa&#231;&#227;o e encerramento de programas em C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O programa criando c executa as mesmas operações que o programa c faz na inicialização do programa e no encerramento de programa, mais quaisquer mais descritos aqui.  
  
 Antes do ambiente de destino chama a função `main`, e depois que armazena todos os valores iniciais constantes você especifica em todos os objetos que detêm a duração estático, o programa executará qualquer outros construtores estáticos para tais objetos.  A ordem de execução não for especificado entre unidades de tradução, mas você pode não obstante suponha que alguns objetos de [iostreams](../standard-library/iostreams-conventions.md) são inicializados corretamente para o uso destes construtores estáticos.  Esses fluxos de texto do controle são:  
  
-   [cin](../Topic/cin.md) — para a entrada padrão.  
  
-   [cout](../Topic/cout.md) — para a saída padrão.  
  
-   [cerr](../Topic/cerr.md) — para saída de erro padrão não armazenado.  
  
-   [obstrução](../Topic/clog.md) — para saída de erro padrão armazenados em buffer.  
  
 Você também pode usar esses objetos dentro de destruidores chamado para objetos estáticos, durante a fim do programa.  
  
 Como com 2.0 C, retornando de `main` ou chamando `exit` chama todas as funções registradas com `atexit` na ordem inversa de Registro.  Uma exceção lançada dessas chamadas de função `terminate`registradas.  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)