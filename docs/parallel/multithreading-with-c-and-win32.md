---
title: Multithread com C e Win32 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows API [C++], multithreading
- multithreading [C++], C and Win32
- Visual C, multithreading
- Win32 applications [C++], multithreading
- threading [C++], C and Win32
- Win32 [C++], multithreading
- threading [C]
ms.assetid: 67cdc99e-1ad9-452b-a042-ed246b70040e
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 30c7833a4df80669b6223f1fe6b1ccceed0257cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="multithreading-with-c-and-win32"></a>Multithread com C e Win32
Microsoft Visual C++ oferece suporte para a criação de aplicativos multithread com o Microsoft Windows: Windows XP, Windows 2000, Windows NT, Windows Me e Windows 98. Considere a possibilidade de usar mais de um thread se seu aplicativo precisar gerenciar várias atividades, como simultâneo do teclado e mouse entrada. Um thread pode processar a entrada do teclado enquanto um thread de segundo filtra as atividades de mouse. Um terceiro segmento pode atualizar a tela de exibição com base nos dados de threads de mouse e teclado. Ao mesmo tempo, outros threads podem acessar arquivos de disco ou obter dados de uma porta de comunicação.  
  
 Com o Visual C++, há duas maneiras de programa com vários threads: use a biblioteca Microsoft Foundation Class (MFC) ou a biblioteca de tempo de execução do C e a API do Win32. Para obter informações sobre como criar aplicativos multithread com MFC, consulte [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md) depois de ler os tópicos a seguir sobre multithreading em C.  
  
 Estes tópicos explicam os recursos do Visual C++ que dão suporte a criação de programas multithread.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [O que multithreading é sobre](../parallel/multithread-programs.md)  
  
-   [Suporte de biblioteca para multithread](../parallel/library-support-for-multithreading.md)  
  
-   [Incluir arquivos para multithread](../parallel/include-files-for-multithreading.md)  
  
-   [Funções de biblioteca de tempo de execução C para controle de thread](../parallel/c-run-time-library-functions-for-thread-control.md)  
  
-   [Programas multithread de exemplo em C](../parallel/sample-multithread-c-program.md)  
  
-   [Escrevendo um programa Win32 Multithread](../parallel/writing-a-multithreaded-win32-program.md)  
  
-   [Compilando e vinculando programas multithread](../parallel/compiling-and-linking-multithread-programs.md)  
  
-   [Evitando áreas de problema com programas multithread](../parallel/avoiding-problem-areas-with-multithread-programs.md)  
  
-   [Armazenamento local de thread (TLS)](../parallel/thread-local-storage-tls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de multithreading para código anterior (Visual C++)](../parallel/multithreading-support-for-older-code-visual-cpp.md)