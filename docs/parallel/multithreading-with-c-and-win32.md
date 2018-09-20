---
title: Multithreading com C e Win32 | Microsoft Docs
ms.custom: ''
ms.date: 02/02/2018
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows API [C++], multithreading
- multithreading [C++], C and Win32
- Visual C, multithreading
- Win32 applications [C++], multithreading
- threading [C++], C and Win32
- Win32 [C++], multithreading
- threading [C]
ms.assetid: 67cdc99e-1ad9-452b-a042-ed246b70040e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 09397b5a60dcc2cbe2b3e6265f6080f3c5c1e212
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46428090"
---
# <a name="multithreading-with-c-and-win32"></a>Multithread com C e Win32

Microsoft Visual C++ fornece suporte para a criação de aplicativos multithread. Você deve considerar o uso de mais de um thread se seu aplicativo precisa para executar operações caras que faria com que a interface do usuário pare de responder.

Com o Visual C++, há duas maneiras de programa com vários threads: usar a biblioteca Microsoft Foundation Class (MFC) ou a biblioteca de tempo de execução de C e a API do Win32. Para obter informações sobre como criar aplicativos multithread com o MFC, consulte [Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md) depois de ler os seguintes tópicos sobre multithreading em C.

Estes tópicos explicam os recursos do Visual C++ que oferecem suporte à criação de programas multithread.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [O que multithreading é sobre](multithread-programs.md)

- [Suporte de biblioteca para multithreading](library-support-for-multithreading.md)

- [Incluir arquivos para multithreading](include-files-for-multithreading.md)

- [Funções de biblioteca de tempo de execução C para controle de thread](c-run-time-library-functions-for-thread-control.md)

- [Programação multithread de exemplo em C](sample-multithread-c-program.md)

- [Escrevendo um programa Win32 Multithread](writing-a-multithreaded-win32-program.md)

- [Compilando e vinculando programas multithread](compiling-and-linking-multithread-programs.md)

- [Evitando áreas de problema com programas multithread](avoiding-problem-areas-with-multithread-programs.md)

- [Armazenamento local de thread (TLS)](thread-local-storage-tls.md)

## <a name="see-also"></a>Consulte também

[Suporte de multithreading para código anterior (Visual C++)](multithreading-support-for-older-code-visual-cpp.md)