---
title: "Programas multithread | Microsoft Docs"
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
  - "multithreading [C++], sobre threads"
  - "threading [C++], sobre threading"
ms.assetid: 02443596-f7e1-48d0-b3a4-39ee0e54e444
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Programas multithread
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um thread é basicamente um caminho de execução do programa.  Também é a unidade menor de execução que o Win32 agenda.  Um thread consiste em uma pilha, o estado da CPU, e registra uma entrada na lista de execução do agendador de sistema.  Cada thread compartilha os recursos de qualquer processo.  
  
 Um processo consiste em um ou mais threads e o código, dados, e outros recursos de um programa na memória.  Os recursos comuns de programa são arquivos abertos, semáforos, e memória dinamicamente atribuída.  Um programa executa quando o agendador de sistema fornece um do controle de execução de threads.  O agendador determina quais threads devem executar e quando devem executar.  Os threads de prioridade inferior podem ter que esperar quando um threads prioridade mais alta é concluído suas tarefas.  Em computadores multiprocessadores, do agendador pode mover threads individuais para processadores diferentes para balancear a carga de CPU.  
  
 Cada thread em um processo opera independentemente.  A menos que você o faça visíveis entre si, os threads são executados individualmente e não são dos outros threads em um processo.  Os threads que compartilham recursos comuns, no entanto, devem coordenar seu trabalho usando dois semáforos ou outro método de IPC.  Para obter mais informações sobre como sincronizar threads, consulte [Escrever um programa de vários threads do Win32](../Topic/Writing%20a%20Multithreaded%20Win32%20Program.md).  
  
## Consulte também  
 [Multithread com C e Win32](../parallel/multithreading-with-c-and-win32.md)