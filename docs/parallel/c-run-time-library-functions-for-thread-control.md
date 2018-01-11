---
title: "Funções de biblioteca de tempo de execução do C para controle de Thread | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- _beginthread function
- _endthread function
- threading [C++], controlling threads
- multithreading [C++], controlling threads
- _beginthreadex function
- _endthreadex function
ms.assetid: 39d0529c-c392-4c6f-94f5-105d1e8054e4
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 49d3d9029f85a8a80da6a7cd38bb26b887223d35
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-run-time-library-functions-for-thread-control"></a>Funções de biblioteca em tempo de execução C para controle de thread
Todos os programas Win32 tem pelo menos um thread. Qualquer thread pode criar threads adicionais. Um thread pode concluir seu trabalho rapidamente e, em seguida, encerrar ou ele pode permanecer ativo durante a vida útil do programa.  
  
 As bibliotecas de tempo de execução LIBCMT e MSVCRT C fornecem as seguintes funções de criação de threads e a terminação: [beginthread, beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md) e [endthread, endthreadex](../c-runtime-library/reference/endthread-endthreadex.md).  
  
 O `_beginthread` e `_beginthreadex` funções de criar um novo thread e retornar um identificador de thread se a operação for bem-sucedida. O thread será encerrado automaticamente se ele conclui a execução ou ele pode ser encerrado em si com uma chamada para `_endthread` ou `_endthreadex`.  
  
> [!NOTE]
>  Se você pretende chamar rotinas de tempo de execução do C a partir de um programa compilado com Libcmt.lib, você deve iniciar seus threads com a `_beginthread` ou `_beginthreadex` função. Não use as funções do Win32 `ExitThread` e `CreateThread`. Usando `SuspendThread` pode levar a um deadlock quando mais de um thread está bloqueado, aguardando o thread suspenso concluir seu acesso a uma estrutura de dados de tempo de execução C.  
  
##  <a name="_core_the__beginthread_function"></a>As funções beginthread e beginthreadex  
 O `_beginthread` e `_beginthreadex` funções de criar um novo thread. Um thread compartilha os segmentos de código e os dados de um processo com outros threads no processo, mas tem seu próprio valores do registro exclusivo, o espaço de pilha e o endereço da instrução atual. O sistema dá tempo de CPU para cada thread, para que todos os threads em um processo podem ser executados simultaneamente.  
  
 `_beginthread`e `_beginthreadex` são semelhantes a [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função na API do Win32, mas tem essas diferenças:  
  
-   Eles inicializarem determinadas variáveis de biblioteca de tempo de execução C. Isso é importante apenas se você usar a biblioteca de tempo de execução do C em seu threads.  
  
-   `CreateThread`fornece controle sobre os atributos de segurança. Você pode usar essa função para iniciar um thread em um estado suspenso.  
  
 `_beginthread`e `_beginthreadex` retornar um identificador para o novo thread se for bem-sucedido ou um código de erro, se houver um erro.  
  
##  <a name="_core_the__endthread_function"></a>As funções endthread e endthreadex  
 O [endthread](../c-runtime-library/reference/endthread-endthreadex.md) função encerra um thread criado por `_beginthread` (e da mesma forma, `_endthreadex` encerra um thread criado pelo `_beginthreadex`). Threads encerrar automaticamente quando ele terminar. `_endthread`e `_endthreadex` são úteis para encerramento condicional de dentro de um thread. Um thread dedicado à comunicação do processamento, por exemplo, pode encerrar se não for possível obter o controle da porta de comunicação.  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)