---
title: "Fun&#231;&#245;es de biblioteca em tempo de execu&#231;&#227;o C para controle de thread | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _beginthread"
  - "Função _beginthreadex"
  - "Função _endthread"
  - "Função _endthreadex"
  - "multithreading [C++], controlando threads"
  - "threading [C++], controlando threads"
ms.assetid: 39d0529c-c392-4c6f-94f5-105d1e8054e4
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de biblioteca em tempo de execu&#231;&#227;o C para controle de thread
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Todos os programas do Win32 têm pelo menos um thread.  Qualquer thread pode criar threads adicionais.  Um thread pode concluir seu trabalho rapidamente e depois encerrar, ou pode permanecer ativa para a duração do programa.  
  
 As bibliotecas de tempo de execução de LIBCMT e de MSVCRT C fornece as seguintes funções para a criação e a fim do thread: [\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md) e [\_endthread, \_endthreadex](../Topic/_endthread,%20_endthreadex.md).  
  
 As funções de `_beginthread` e de `_beginthreadex` criam um thread novo e retorna um identificador de thread se a operação foi bem\-sucedida.  O thread termina automaticamente se concluir a execução, ou pode finalizar\-se com uma chamada a `_endthread` ou a `_endthreadex`.  
  
> [!NOTE]
>  Se você pretende chamar rotinas de tempo de execução C de um programa compilado com Libcmt.lib, você deve iniciar os threads com a função de `_beginthread` ou de `_beginthreadex` .  Não use as funções `ExitThread` e `CreateThread`do Win32.  Usar `SuspendThread` pode resultar em um deadlock quando mais de um thread é bloqueado esperando o thread suspenso para concluir seu acesso à estrutura de dados de tempo de execução c.  
  
##  <a name="_core_the__beginthread_function"></a> As funções de \_beginthread e de \_beginthreadex  
 As funções de `_beginthread` e de `_beginthreadex` criam um thread novo.  Um thread compartilha os segmentos de código e de dados de um processo com outros threads no processo mas tem seus próprios valores exclusivos do registro, espaço de endereço de pilha, e instrução atual.  O sistema da CPU tempo a cada thread, de forma que todos os threads em um processo possam ser executadas simultaneamente.  
  
 `_beginthread` e `_beginthreadex` são semelhantes à função de [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) na API do Win32 mas têm essas diferenças:  
  
-   Inicializar determinadas variáveis da biblioteca de tempo de execução C.  Isso é importante somente se você usar a biblioteca de tempo de execução C em seus threads.  
  
-   ajuda de`CreateThread` fornecem controle sobre os atributos de segurança.  Você pode usar essa função para iniciar um thread em um estado suspenso.  
  
 `_beginthread` e `_beginthreadex` retorna um identificador para o novo thread se bem\-sucedido ou um código de erro se houve um erro.  
  
##  <a name="_core_the__endthread_function"></a> As funções de \_endthread e de \_endthreadex  
 A função de [\_endthread](../Topic/_endthread,%20_endthreadex.md) finaliza um thread criado por `_beginthread` \(e mesma forma, `_endthreadex` finaliza um thread criado por `_beginthreadex`\).  Os threads serão encerradas automaticamente quando for concluído.  `_endthread` e `_endthreadex` são úteis para terminação condicional do thread.  Um thread dedicado a comunicação que processam, por exemplo, pode parar se for não é possível obter o controle da porta de comunicação.  
  
## Consulte também  
 [Multithread com C e Win32](../parallel/multithreading-with-c-and-win32.md)