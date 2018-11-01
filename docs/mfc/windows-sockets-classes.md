---
title: Classes de Windows Sockets
ms.date: 11/04/2016
f1_keywords:
- vc.classes.net
helpviewer_keywords:
- sockets classes [MFC]
- Windows Sockets [MFC], classes
ms.assetid: 58b9ab8d-9e44-4db3-8265-e04e713d2e9a
ms.openlocfilehash: 18537c0de09185c8cd219e3d17ef8bb297e1d711
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50433595"
---
# <a name="windows-sockets-classes"></a>Classes de Windows Sockets

Windows Sockets fornecem uma maneira independente de protocolo de rede para comunicação entre dois computadores. Esses soquetes podem ser síncronas (o programa aguarda até que a comunicação é feita) ou assíncrona (o programa continua em execução enquanto a comunicação está em andamento).

[CAsyncSocket](../mfc/reference/casyncsocket-class.md)<br/>
Encapsula a API de soquetes do Windows em um wrapper estreito.

[CSocket](../mfc/reference/csocket-class.md)<br/>
Abstração de nível superior é derivado de `CAsyncSocket`. Ele opera de forma síncrona.

[CSocketFile](../mfc/reference/csocketfile-class.md)<br/>
Fornece um `CFile` interface para um soquete do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

