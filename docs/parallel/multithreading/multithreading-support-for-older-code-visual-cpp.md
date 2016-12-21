---
title: "Suporte multithread para c&#243;digo anterior (Visual C++) | Microsoft Docs"
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
  - "programação simultânea [C++]"
  - "vários threads simultâneos"
  - "vários threads"
  - "multithreading [C++]"
  - "multithreading [C++], sobre multithreading"
  - "programação [C++], com multithread"
  - "threading [C++]"
ms.assetid: 24425b1f-5031-4c6b-aac7-017115a40e7c
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte multithread para c&#243;digo anterior (Visual C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O Visual C\+\+ permite que você tenha vários segmentos simultâneos de execução sendo executados simultaneamente.  Com o multithreading, você pode rotacionar as tarefas em segundo plano, gerenciar fluxos simultâneos de entrada, gerenciar uma interface de usuário, e muito mais.  
  
## Nesta seção  
 [Multithreading com C e Win32](../../parallel/multithreading-with-c-and-win32.md)  
 Fornece suporte para a criação de aplicativos multithread com o Microsoft Windows  
  
 [Multithreading com C\+\+ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md)  
 Descreve o que são processos e threads e qual é a abordagem MFC para multithreading.  
  
 [Multithread e localidades](../../parallel/multithreading-and-locales.md)  
 Discute problemas que ocorrem ao usar a funcionalidade de localidade da biblioteca em tempo de execução do C e biblioteca do C\+\+ padrão em um aplicativo com vários segmentos.  
  
## Seções relacionadas  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
 Representa um thread de execução em um aplicativo.  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
 Descreve uma classe virtual pura que fornece funcionalidades comuns a objetos de sincronização no Win32.  
  
 [CSemaphore](../../mfc/reference/csemaphore-class.md)  
 Representa um semáforo, que é um objeto de sincronização que permite um número limitado de threads em um ou mais processos para acessar um recurso.  
  
 [CMutex](../../mfc/reference/cmutex-class.md)  
 Representa um mutex, que é um objeto de sincronização que permite um acesso mutuamente exclusivo de thread a um recurso.  
  
 [CCriticalSection](../Topic/CCriticalSection%20Class.md)  
 Representa uma seção crítica, que é um objeto de sincronização que permite que um thread por vez para acessar um recurso ou seção de código.  
  
 [CEvent](../../mfc/reference/cevent-class.md)  
 Representa um evento, que é um objeto de sincronização que permite que um thread notifique outro sobre a ocorrência de um evento.  
  
 [CMultiLock](../../mfc/reference/cmultilock-class.md)  
 Representa o mecanismo de controle de acesso usado no acesso de controle a recursos em um programa multithreaded.  
  
 [CSingleLock](../../mfc/reference/csinglelock-class.md)  
 Representa o mecanismo de controle de acesso usado no acesso de controle a um recurso em um programa multithreaded.  
  
 [\(NOTINBUILD\)Visual C\+\+ Programming Methodologies](http://msdn.microsoft.com/pt-br/0822f806-fa81-4b65-bf0f-1e2921f30c95)  
 Fornece links para tópicos que descrevem informações conceituais sobre as bibliotecas do Visual C\+\+ e para tópicos que discutem diversas tecnologias e técnicas de codificação.