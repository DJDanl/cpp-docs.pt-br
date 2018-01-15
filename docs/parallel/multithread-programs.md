---
title: Programas multithread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- threading [C++], about threading
- multithreading [C++], about threads
ms.assetid: 02443596-f7e1-48d0-b3a4-39ee0e54e444
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0ff73b4d3a1c8ee6971fbd3f88f491c2a5c76311
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="multithread-programs"></a>Programas multithread
Um thread é basicamente um caminho de execução por meio de um programa. Também é a menor unidade de execução que a agenda de Win32. Um thread consiste em uma pilha, o estado de registros de CPU e uma entrada na lista de execução do Agendador de sistema. Cada thread compartilha os recursos de todos os do processo.  
  
 Um processo consiste em um ou mais threads e o código, dados e outros recursos de um programa na memória. Recursos do programa típicos são arquivos abertos, semáforos e a memória alocada dinamicamente. Um programa é executado quando o Agendador de sistema dá a um dos seus threads de controle de execução. O Agendador determina quais segmentos devem ser executado e quando ele deve ser executado. Threads de prioridade mais baixa talvez seja necessário aguardar enquanto os threads de prioridade mais altos concluem suas tarefas. Em computadores multiprocessador, o Agendador pode mover segmentos individuais para processadores diferentes para balancear a carga de CPU.  
  
 Cada thread em um processo funciona de forma independente. A menos que você torná-las visíveis entre si, os threads executar individualmente e não estiver ciente de outros threads em um processo. Threads compartilhando recursos comuns, no entanto, devem coordenar o trabalho usando semáforos ou outro método de comunicação entre processos. Para obter mais informações sobre a sincronização de threads, consulte [escrevendo um programa Win32 multithread](../parallel/writing-a-multithreaded-win32-program.md).  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)