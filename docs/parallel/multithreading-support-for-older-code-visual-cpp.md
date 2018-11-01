---
title: Suporte multithread para código anterior (Visual C++)
ms.date: 08/27/2018
helpviewer_keywords:
- threading [C++]
- multiple threads
- concurrent programming [C++]
- programming [C++], multithreaded
- multithreading [C++], about multithreading
- multiple concurrent threads
- multithreading [C++]
ms.assetid: 24425b1f-5031-4c6b-aac7-017115a40e7c
ms.openlocfilehash: 649e26c3f0704dfd6740b1a250613545e29316a3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50457727"
---
# <a name="multithreading-support-for-older-code-visual-c"></a>Suporte multithread para código anterior (Visual C++)

Visual C++ permite que você tenha vários threads simultâneos de execução sendo executados simultaneamente. Com o multithreading, você pode rotacionar tarefas em segundo plano, gerenciar fluxos simultâneos de entrada, gerenciar uma interface do usuário e muito mais.

## <a name="in-this-section"></a>Nesta seção

[Multithreading com C e Win32](multithreading-with-c-and-win32.md)<br/>
Fornece suporte para criar aplicativos multithread com o Microsoft Windows

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)<br/>
Descreve quais são os processos e threads e o que a abordagem MFC para multithreading é.

[Multithread e localidades](multithreading-and-locales.md)<br/>
Discute problemas que ocorrem ao usar a funcionalidade de localidade da biblioteca de tempo de execução C e a biblioteca padrão C++ em um aplicativo multithreaded.

## <a name="related-sections"></a>Seções relacionadas

[CWinThread](../mfc/reference/cwinthread-class.md)<br/>
Representa um segmento de execução dentro de um aplicativo.

[CSyncObject](../mfc/reference/csyncobject-class.md)<br/>
Descreve uma classe virtual pura que fornece funcionalidade comum para os objetos de sincronização no Win32.

[CSemaphore](../mfc/reference/csemaphore-class.md)<br/>
Representa um semáforo, que é um objeto de sincronização que permite que um número limitado de threads em um ou mais processos para acessar um recurso.

[CMutex](../mfc/reference/cmutex-class.md)<br/>
Representa um mutex, que é um objeto de sincronização que permite um acesso mutuamente exclusivo de thread a um recurso.

[CCriticalSection](../mfc/reference/ccriticalsection-class.md)<br/>
Representa uma seção crítica, o que é um objeto de sincronização que permite que um thread por vez para acessar um recurso ou seção de código.

[CEvent](../mfc/reference/cevent-class.md)<br/>
Representa um evento, que é um objeto de sincronização que permite que um thread notifique outro que ocorreu um evento.

[CMultiLock](../mfc/reference/cmultilock-class.md)<br/>
Representa o mecanismo de controle de acesso usado no controle de acesso aos recursos em um programa multi-threaded.

[CSingleLock](../mfc/reference/csinglelock-class.md)<br/>
Representa o mecanismo de controle de acesso usado no controle de acesso a um recurso em um programa multi-threaded.