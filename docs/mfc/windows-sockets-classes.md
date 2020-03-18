---
title: Classes de Windows Sockets
ms.date: 11/04/2016
helpviewer_keywords:
- sockets classes [MFC]
- Windows Sockets [MFC], classes
ms.assetid: 58b9ab8d-9e44-4db3-8265-e04e713d2e9a
ms.openlocfilehash: 3f1b7b2b6674b4a5f8c8f7bff6c5fa239715f459
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445986"
---
# <a name="windows-sockets-classes"></a>Classes de Windows Sockets

O Windows Sockets fornece uma maneira independente de protocolo de rede para se comunicar entre dois computadores. Esses soquetes podem ser síncronos (o programa aguarda até que a comunicação seja feita) ou assíncrono (seu programa continua em execução enquanto a comunicação está em andamento).

[CAsyncSocket](../mfc/reference/casyncsocket-class.md)<br/>
Encapsula a API do Windows Sockets em um wrapper fino.

[CSocket](../mfc/reference/csocket-class.md)<br/>
Abstração de nível superior derivada de `CAsyncSocket`. Ele funciona de forma síncrona.

[CSocketFile](../mfc/reference/csocketfile-class.md)<br/>
Fornece uma interface `CFile` para um soquete do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
