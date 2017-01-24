---
title: "Multithread: encerrando threads | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CREATE_SUSPENDED"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AfxEndThread"
  - "multithreading [C++], encerrando threads"
  - "encerramento prematuro de threads"
  - "iniciando threads"
  - "parando threads"
  - "encerrando threads"
  - "threading [C++], parando threads"
  - "threading [MFC], encerrando threads"
ms.assetid: 4c0a8c6d-c02f-456d-bd02-0a8c8d006ecb
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread: encerrando threads
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Duas situações normais fazem com que um segmento seja finalizado: a função de controle é encerrada ou o segmento não pode ser executado para a conclusão.  Se um processador de texto usou um thread para impressão em segundo plano, a função de controle finalizaria normalmente se a impressão fosse concluída com êxito.  Se o usuário deseja cancelar a impressão, porém, o thread de impressão em segundo plano tem que ser finalizado prematuramente.  Este tópico explica como implementar cada situação e como obter o código de saída de um thread depois que ele é finalizado.  
  
-   [Encerramento Normal de Thread](#_core_normal_thread_termination)  
  
-   [Terminação prematura de thread](#_core_premature_thread_termination)  
  
-   [Recuperando o código de saída de um thread](#_core_retrieving_the_exit_code_of_a_thread)  
  
##  <a name="_core_normal_thread_termination"></a> Encerramento Normal de Thread  
 Para um thread de trabalho, o encerramento normal do thread é simples: saia da função de controle e retorne um valor que signifique a razão para o encerramento.  Você pode usar a função [AfxEndThread](../Topic/AfxEndThread.md) ou uma instrução `return`.  Em geral, 0 significa conclusão com êxito, mas depende da sua configuração.  
  
 Para um encadeamento de interface do usuário, o processo é igualmente simples: de dentro do encadeamento de interface do usuário, chame [PostQuitMessage](http://msdn.microsoft.com/library/windows/desktop/ms644945) no [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  O único parâmetro que leva **PostQuitMessage** é o código de saída de thread.  Quanto a threads de trabalho, 0 significa normalmente conclusão com êxito.  
  
##  <a name="_core_premature_thread_termination"></a> Terminação prematura de thread  
 A terminação prematura de um thread é quase simples: chame [AfxEndThread](../Topic/AfxEndThread.md) de dentro do thread.  Passe o código de saída desejado como o único parâmetro.  Isso para a execução do thread, desaloca a pilha do thread, dispara todas as DLLs anexadas ao thread e exclui o objeto de thread da memória.  
  
 `AfxEndThread` deve ser chamado de dentro do thread para ser encerrado.  Se deseja encerrar um thread a partir de outro thread, você deve configurar um método de comunicação entre os dois threads.  
  
##  <a name="_core_retrieving_the_exit_code_of_a_thread"></a> Recuperando o código de saída de um thread  
 Para obter o código de saída de trabalhador ou o encadeamento de interface do usuário, chame a função [GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190) .  Para obter informações sobre essa função, consulte o [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  Essa função usa o manipulador para o thread \(armazenado no membro de dados `m_hThread` de objetos `CWinThread`\) e o endereço de `DWORD`.  
  
 Se o segmento ainda está ativo, **GetExitCodeThread** coloca **STILL\_ACTIVE** no endereço `DWORD` fornecido; caso contrário, o código de saída é colocado neste endereço.  
  
 A recuperação do código de saída do objeto [CWinThread](../mfc/reference/cwinthread-class.md) usa uma etapa adicional.  Por padrão, quando um thread `CWinThread` finaliza, o objeto de thread é excluído.  Isso significa que você não pode acessar o membro de dados `m_hThread` porque o objeto `CWinThread` não existe mais.  Para evitar esta situação, execute um dos procedimentos a seguir:  
  
-   Defina o membro de dados `m_bAutoDelete` como **FALSO**.  Isso permite que o objeto `CWinThread` sobreviva depois que o segmento tiver sido terminado.  Em seguida, é possível acessar o membro de dados `m_hThread` após a thread ser encerrada.  Porém, se usar essa técnica, você será responsável por destruir o objeto `CWinThread`, porque a estrutura não o excluirá automaticamente.  Esse é o método preferido.  
  
-   Armazene o manipulador do thread separadamente.  Depois que o thread é criado, copie seu membro de dados `m_hThread` \(usando **::DuplicateHandle**\) para outra variável e acesse\-o por meio dessa variável.  Dessa maneira, o objeto é automaticamente excluído quando a terminação ocorre e você ainda pode descobrir porque o thread foi terminado.  Cuidado para o thread não terminar para você poder duplicar o identificador.  A maneira mais segura de fazer isso é passar **CREATE\_SUSPENDED** para [AfxBeginThread](../Topic/AfxBeginThread.md), armazenar o manipulador e então retomar o thread chamando [ResumeThread](../Topic/CWinThread::ResumeThread.md).  
  
 Qualquer um desses métodos permite que você determine por que um objeto `CWinThread` foi finalizado.  
  
## Consulte também  
 [Multithread com C\+\+ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)   
 [\_endthread, \_endthreadex](../Topic/_endthread,%20_endthreadex.md)   
 [\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md)   
 [ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659)