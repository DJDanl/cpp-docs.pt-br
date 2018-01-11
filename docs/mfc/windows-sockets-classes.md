---
title: Classes de Windows Sockets | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.net
dev_langs: C++
helpviewer_keywords:
- sockets classes [MFC]
- Windows Sockets [MFC], classes
ms.assetid: 58b9ab8d-9e44-4db3-8265-e04e713d2e9a
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cea7690c9d1f754006a38c793fcd9608747c13b7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

