---
title: Funções de biblioteca em tempo de execução C para controle de thread
ms.date: 11/04/2016
helpviewer_keywords:
- _beginthread function
- _endthread function
- threading [C++], controlling threads
- multithreading [C++], controlling threads
- _beginthreadex function
- _endthreadex function
ms.assetid: 39d0529c-c392-4c6f-94f5-105d1e8054e4
ms.openlocfilehash: ea04e42730b0e7d1f0fafe5d3139d2b1a6aed970
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50572153"
---
# <a name="c-run-time-library-functions-for-thread-control"></a>Funções de biblioteca em tempo de execução C para controle de thread

Todos os programas Win32 têm pelo menos um thread. Qualquer thread pode criar threads adicionais. Um thread pode concluir seu trabalho rapidamente e, em seguida, encerrar ou ele pode permanecer ativo durante a vida útil do programa.

As bibliotecas de tempo de execução NAFXCWD e MSVCRT C fornecem as seguintes funções para criação de thread e término: [beginthread, beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md) e [endthread, endthreadex](../c-runtime-library/reference/endthread-endthreadex.md).

O `_beginthread` e `_beginthreadex` funções criar um novo thread e retornar um identificador de thread se a operação for bem-sucedida. O thread é encerrado automaticamente se ele conclui a execução, ou ele pode encerrado por si mesmo com uma chamada para `_endthread` ou `_endthreadex`.

> [!NOTE]
> Se você pretende chamar rotinas de tempo de execução do C a partir de um programa compilado com libcmt. lib, você deve iniciar seus threads com o `_beginthread` ou `_beginthreadex` função. Não use as funções do Win32 `ExitThread` e `CreateThread`. Usando `SuspendThread` pode causar um deadlock quando mais de um thread está bloqueado aguardando o thread suspenso concluir seu acesso a uma estrutura de dados de tempo de execução do C.

##  <a name="_core_the__beginthread_function"></a> As funções beginthread e beginthreadex

O `_beginthread` e `_beginthreadex` funções criam um novo thread. Um thread compartilha os segmentos de código e os dados de um processo com outros threads no processo, mas tem seus próprios valores do registro exclusivo, o espaço de pilha e o endereço da instrução atual. O sistema fornece o tempo de CPU para cada thread, para que todos os threads em um processo podem ser executadas simultaneamente.

`_beginthread` e `_beginthreadex` são semelhantes para o [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) função na API do Win32, mas tem essas diferenças:

- Eles inicializam determinadas variáveis de biblioteca de tempo de execução C. Isso é importante apenas se você usar a biblioteca de tempo de execução do C em seus threads.

- `CreateThread` ajuda a fornecer controle sobre os atributos de segurança. Você pode usar essa função para iniciar um thread em um estado suspenso.

`_beginthread` e `_beginthreadex` retornar um identificador para o novo thread, se for bem-sucedido ou um código de erro se ocorreu um erro.

##  <a name="_core_the__endthread_function"></a> As funções endthread e endthreadex

O [endthread](../c-runtime-library/reference/endthread-endthreadex.md) função termina um thread criado pelo `_beginthread` (e da mesma forma, `_endthreadex` termina um thread criado pelo `_beginthreadex`). Threads encerrar automaticamente quando terminarem. `_endthread` e `_endthreadex` são úteis para a terminação condicional de dentro de um thread. Um thread dedicado para as comunicações de processamento, por exemplo, pode encerrar se não for possível obter controle sobre as portas de comunicação.

## <a name="see-also"></a>Consulte também

[Multithreading com C e Win32](multithreading-with-c-and-win32.md)