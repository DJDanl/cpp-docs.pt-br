---
title: Programas multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- threading [C++], about threading
- multithreading [C++], about threads
ms.assetid: 02443596-f7e1-48d0-b3a4-39ee0e54e444
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 25debffcd667c7e0d7405d0a4454b60729825fcb
ms.sourcegitcommit: f7703076b850c717c33d72fb0755fbb2215c5ddc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2018
ms.locfileid: "43131275"
---
# <a name="multithread-programs"></a>Programas multithread
Um thread é basicamente um caminho de execução por meio de um programa. Também é a menor unidade de execução que a agenda de Win32. Um thread consiste em uma pilha, o estado de registros de CPU e uma entrada na lista de execução do Agendador de sistema. Cada thread compartilha recursos de todos os do processo.  
  
Um processo consiste em um ou mais threads e o código, dados e outros recursos de um programa na memória. Recursos do programa típico são arquivos abertos, semáforos e memória alocada dinamicamente. Um programa é executado quando o Agendador do sistema dá a um de seus threads controle de execução. O Agendador determina quais segmentos devem ser executado e quando deve ser executado. Threads de prioridade mais baixa talvez seja necessário esperar enquanto os threads de prioridade mais alta concluam suas tarefas. Em máquinas com vários processadores, o Agendador pode mover threads individuais para processadores diferentes para balancear a carga de CPU.  
  
Cada thread em um processo funciona de forma independente. A menos que você torná-las visíveis entre si, os threads executar individualmente e não estão cientes dos outros threads em um processo. Threads de compartilhamento de recursos comuns, no entanto, devem coordenar o trabalho deles usando semáforos ou outro método de comunicação entre processos. Para obter mais informações sobre a sincronização de threads, consulte [escrevendo um programa Win32 multithread](writing-a-multithreaded-win32-program.md).  
  
## <a name="see-also"></a>Consulte também  

[Multithreading com C e Win32](multithreading-with-c-and-win32.md)