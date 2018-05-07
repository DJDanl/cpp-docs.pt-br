---
title: Classes de Windows Sockets | Microsoft Docs
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
ms.openlocfilehash: 4e370c8a5f9cb2fb42c3199dbc0d56b69d93dc35
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-classes"></a>Classes de Windows Sockets
Windows Sockets fornecem uma maneira independente de protocolo de rede para comunicação entre dois computadores. Estes soquetes podem ser síncronas (o programa deve aguardar até que a comunicação é feita) ou assíncrona (o programa continua em execução enquanto a comunicação em andamento).  
  
 [CAsyncSocket](../mfc/reference/casyncsocket-class.md)  
 Encapsula a API do Windows Sockets em um wrapper fino.  
  
 [CSocket](../mfc/reference/csocket-class.md)  
 Abstração de nível superior é derivado de `CAsyncSocket`. Ele opera de forma síncrona.  
  
 [CSocketFile](../mfc/reference/csocketfile-class.md)  
 Fornece um `CFile` interface para um soquete do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

