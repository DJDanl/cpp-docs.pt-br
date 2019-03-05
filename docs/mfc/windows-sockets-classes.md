---
title: Classes de Windows Sockets
ms.date: 11/04/2016
f1_keywords:
- vc.classes.net
helpviewer_keywords:
- sockets classes [MFC]
- Windows Sockets [MFC], classes
ms.assetid: 58b9ab8d-9e44-4db3-8265-e04e713d2e9a
ms.openlocfilehash: 4abdd8f8fbfc115b5014ffd0b3a37df357852b16
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57303814"
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
