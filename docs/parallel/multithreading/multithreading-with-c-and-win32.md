---
title: "Multithread com C e Win32 | Microsoft Docs"
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
  - "multithreading [C++], C e Win32"
  - "threading [C]"
  - "threading [C++], C e Win32"
  - "Visual C, multithreading"
  - "Win32 [C++], multithreading"
  - "Aplicativos Win32 [C++], multithreading"
  - "API do Windows [C++], multithreading"
ms.assetid: 67cdc99e-1ad9-452b-a042-ed246b70040e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread com C e Win32
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O Microsoft Visual C\+\+ oferece suporte para criar aplicativos multithread com o Microsoft Windows: Windows XP, Windows 2000, Windows NT, Windows Me, e Windows 98.  Você deverá considerar o uso de mais de um thread se o seu aplicativo precisar gerenciar várias atividades, como uma entrada de teclado e de mouse simultâneas.  Um thread pode processar a entrada do teclado quando um segundo thread filtra atividades do mouse.  Um terceiro thread pode atualizar a tela de exibição com base nos dados dos threads do mouse e do teclado.  Ao mesmo tempo, outros threads podem acessar arquivos de disco ou obter dados de um porta de comunicação.  
  
 Com o Visual C\+\+, há duas maneiras de programar com várias threads: usar a biblioteca de classes do Microsoft Foundation \(MFC\) ou a biblioteca em tempo de execução do C e o API do Win32.  Para obter informações sobre como criar aplicativos multithread com o MFC, consulte [Multithreading com C\+\+ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md), após ler os seguintes tópicos sobre multithreading em C.  
  
 Esses tópicos explicam os recursos no Visual C\+\+ que oferecem suporte à criação de programas multithread.  
  
## Que você deseja saber mais?  
  
-   [O que é multithreading](../../parallel/multithread-programs.md)  
  
-   [Suporte de biblioteca para multithreading](../../parallel/library-support-for-multithreading.md)  
  
-   [Incluir arquivos para multithreading](../../parallel/include-files-for-multithreading.md)  
  
-   [Funções da biblioteca em tempo de execução de C para controle de thread](../../parallel/c-run-time-library-functions-for-thread-control.md)  
  
-   [Programação multithread de exemplo em C](../../parallel/sample-multithread-c-program.md)  
  
-   [Escrevendo um programa Multithread Win32](../Topic/Writing%20a%20Multithreaded%20Win32%20Program.md)  
  
-   [Compilando e vinculando programas multithread](../../parallel/compiling-and-linking-multithread-programs.md)  
  
-   [Evitando áreas do problema com programas multithread](../Topic/Avoiding%20Problem%20Areas%20with%20Multithread%20Programs.md)  
  
-   [Armazenamento local de thread \(TLS\)](../../parallel/thread-local-storage-tls.md)  
  
## Consulte também  
 [Suporte multithread para código anterior \(Visual C\+\+\)](../../parallel/multithreading-support-for-older-code-visual-cpp.md)