---
title: Escrevendo um programa Win32 multithread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- thread stacks [C++]
- resources [C++], multithreading
- stacks [C++]
- shared resources [C++]
- threading [C++], sharing common resources
- multithreading [C++], thread stacks
- multithreading [C++], sharing common resources
- mutual exclusion [C++]
- communications [C++], between threads
- mutex [C++]
- threading [C++], thread stacks
ms.assetid: 1415f47d-417f-4f42-949b-946fb28aab0e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4ede0e6dc1740f93f4905dc69b1927aee0d1a7ff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="writing-a-multithreaded-win32-program"></a>Escrevendo um programa Win32 multithread
Quando você escreve um programa com vários threads, é preciso coordenar seu comportamento e [usar os recursos do programa](#_core_sharing_common_resources_between_threads). Você também deve certificar-se que cada thread receba [sua própria pilha](#_core_thread_stacks).  
  
##  <a name="_core_sharing_common_resources_between_threads"></a>Compartilhando recursos comuns entre Threads  
  
> [!NOTE]
>  Para obter uma discussão semelhante do ponto de vista do MFC, consulte [Multithreading: dicas de programação](../parallel/multithreading-programming-tips.md) e [Multithreading: quando usar as Classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md).  
  
 Cada thread tem sua própria pilha e registra sua própria cópia da CPU. Outros recursos, como arquivos, dados estáticos e memória heap, são compartilhados por todos os threads do processo. Threads que usam esses recursos comuns que devem ser sincronizados. Win32 fornece várias maneiras de recursos, incluindo seções críticas, semáforos, eventos e mutexes.  
  
 Quando vários threads estão acessando dados estáticos, o programa deve fornecer para conflitos de recursos possíveis. Considere a possibilidade de um programa em que um thread atualiza uma estrutura de dados estáticos que contém *x*,*y* coordenadas de itens a ser exibido por outro thread. Se o thread de atualização altera o *x* coordenar e é apropriado antes que ele possa alterar o *y* coordenada, o thread de exibição pode ser agendado antes do *y* é coordenada atualizado. O item será exibido no local errado. Você pode evitar esse problema usando semáforos para controlar o acesso à estrutura.  
  
 Um mutex (abreviação de *mut*ual *ex*conclusão) é uma maneira de se comunicar entre threads ou processos que são executados de forma assíncrona uma da outra. Geralmente, essa comunicação é usada para coordenar as atividades de vários threads ou processos, geralmente controlando o acesso a um recurso compartilhado bloqueando e desbloqueando o recurso. Para solucionar isso, *x*,*y* problema de coordenada de atualização, o thread de atualização define um mutex indicando que a estrutura de dados está em uso antes de executar a atualização. Ele desmarque o mutex após as duas coordenadas tiveram sido processadas. O thread de exibição deve aguardar o mutex ser criptografado antes de atualizar a exibição. Esse processo de aguardando um mutex é geralmente chamado de bloqueio em um mutex porque o processo está bloqueado e não pode continuar até que o mutex limpa.  
  
 O programa Bounce.c mostrado na [do programa C Multithread exemplo](../parallel/sample-multithread-c-program.md) usa um mutex denominado `ScreenMutex` para coordenar as atualizações da tela. Cada vez que um dos threads de exibição está pronto para escrever na tela, ele chama **WaitForSingleObject** com o identificador para `ScreenMutex` e constante **infinito** para indicar que o  **WaitForSingleObject** chamada deve bloquear o mutex e o tempo limite. Se `ScreenMutex` estiver desmarcada, a função espera define o mutex para outros threads não podem interferir com a exibição e continua a execução do thread. Caso contrário, o thread bloqueia até que o mutex limpa. Quando o thread conclui a atualização de exibição, ele libera o mutex chamando **ReleaseMutex**.  
  
 Tela exibe e dados estáticos são apenas dois dos recursos que exigem cuidadoso do gerenciamento. Por exemplo, seu programa pode ter vários threads acessando o mesmo arquivo. Porque outro thread pode ter sido movido o ponteiro do arquivo, cada thread deve redefinir o ponteiro do arquivo antes de ler ou gravar. Além disso, cada thread deve garantir que ele não é apropriado entre a hora em que ele posiciona o ponteiro e a hora em que ele acessa o arquivo. Esses threads devem usar um semáforo para coordenar o acesso ao arquivo por colchetes cada acesso a arquivos com **WaitForSingleObject** e **ReleaseMutex** chamadas. O exemplo de código a seguir ilustra essa técnica:  
  
```  
HANDLE    hIOMutex= CreateMutex (NULL, FALSE, NULL);  
  
WaitForSingleObject( hIOMutex, INFINITE );  
fseek( fp, desired_position, 0L );  
fwrite( data, sizeof( data ), 1, fp );  
ReleaseMutex( hIOMutex);  
```  
  
##  <a name="_core_thread_stacks"></a>Pilhas de thread  
 Todo espaço de pilha padrão do aplicativo está alocada para o primeiro thread de execução, o que é conhecido como o thread 1. Como resultado, você deve especificar a quantidade de memória a ser alocada para uma pilha separada para cada thread adicional seu programa necessita. O sistema operacional aloca espaço de pilha adicionais para o thread, se necessário, mas você deve especificar um valor padrão.  
  
 O primeiro argumento do `_beginthread` chamada é um ponteiro para o **BounceProc** função, que executa os threads. O segundo argumento especifica o tamanho da pilha padrão para o thread. O último argumento é um número de ID que é passado para **BounceProc**. **BounceProc** usa o número de identificação para propagar o gerador de número aleatório e para selecionar o atributo de cor do thread e exibir caracteres.  
  
 Threads que fazer chamadas para a biblioteca de tempo de execução do C ou a API do Win32 devem permitir que o espaço de pilha suficiente para a biblioteca e as funções de API que eles chamam. C `printf` função requer mais de 500 bytes de espaço de pilha, e você deve ter 2 K de espaço de pilha disponível ao chamar as rotinas de API do Win32.  
  
 Como cada thread tem sua própria pilha, você pode evitar colisões potenciais sobre itens de dados usando-se como dados estáticos pequeno quanto possível. Crie seu programa usar as variáveis de pilha automáticas para todos os dados que podem ser particulares a um thread. As únicas variáveis globais no programa de Bounce.c são mutexes ou variáveis que nunca é alterado depois que eles sejam inicializados.  
  
 Win32 também fornece o armazenamento Local de Thread (TLS) para armazenar dados por thread. Para obter mais informações, consulte [armazenamento Local de Thread (TLS)](../parallel/thread-local-storage-tls.md).  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)