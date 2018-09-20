---
title: Classes de soquetes do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.net
dev_langs:
- C++
helpviewer_keywords:
- sockets classes [MFC]
- Windows Sockets [MFC], classes
ms.assetid: 58b9ab8d-9e44-4db3-8265-e04e713d2e9a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 893fa525b04376cde0e96f280c95e6bfd1243946
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439972"
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

