---
title: 'Multithread: Encerrando Threads | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CREATE_SUSPENDED
dev_langs:
- C++
helpviewer_keywords:
- premature thread termination
- starting threads
- threading [MFC], terminating threads
- multithreading [C++], terminating threads
- threading [C++], stopping threads
- terminating threads
- stopping threads
- AfxEndThread method
ms.assetid: 4c0a8c6d-c02f-456d-bd02-0a8c8d006ecb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c287de62169ef5d205ac791071cee4b103f60abc
ms.sourcegitcommit: 185e11ab93af56ffc650fe42fb5ccdf1683e3847
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2018
---
# <a name="multithreading-terminating-threads"></a>Multithread: encerrando threads
Duas situações normais fazer com que um thread encerrar: a função de controle for encerrada ou o thread não tem permissão para executar até a conclusão. Se um processador de texto usado um thread para impressão em segundo plano, a função controlar seria encerrar normalmente se a impressão concluída com êxito. Se o usuário deseja cancelar a impressão, no entanto, o thread de impressão em segundo plano foi encerrada prematuramente. Este tópico explica como implementar cada situação e como obter o código de saída de um thread após ele ser terminado.  
  
-   [Encerramento normal de threads](#_core_normal_thread_termination)  
  
-   [Encerramento prematuro de threads](#_core_premature_thread_termination)  
  
-   [Recuperar o código de saída de Thread](#_core_retrieving_the_exit_code_of_a_thread)  
  
##  <a name="_core_normal_thread_termination"></a>Encerramento normal de threads  
 Para um thread de trabalho, o encerramento normal de threads é simple: a função de controle de saída e retornar um valor que indica o motivo do término. Você pode usar o [AfxEndThread](../mfc/reference/application-information-and-management.md#afxendthread) função ou um `return` instrução. Normalmente, 0 significa conclusão com êxito, mas que fica a seu critério.  
  
 Um thread de interface do usuário, o processo é simple: de dentro do thread de interface do usuário, chame [PostQuitMessage](http://msdn.microsoft.com/library/windows/desktop/ms644945) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)]. O único parâmetro que **PostQuitMessage** usa é o código de saída do thread. Para threads de trabalho, 0 significa normalmente conclusão com êxito.  
  
##  <a name="_core_premature_thread_termination"></a>Encerramento prematuro de threads  
 Encerrar um thread prematuramente é quase tão simple: chamar [AfxEndThread](../mfc/reference/application-information-and-management.md#afxendthread) de dentro do thread. Passe o código de saída desejado como o único parâmetro. Isso interrompe a execução do thread, desaloca a pilha do thread, desconecta todas as DLLs anexadas ao thread e exclui o objeto de segmento de memória.  
  
 `AfxEndThread`deve ser chamado de dentro de thread a ser encerrada. Se você quiser encerrar um thread de outro thread, você deve configurar um método de comunicação entre os dois threads.  
  
##  <a name="_core_retrieving_the_exit_code_of_a_thread"></a>Recuperar o código de saída de Thread  
 Para obter o código de saída do trabalhador ou o thread de interface do usuário, chame o [GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190) função. Para obter informações sobre essa função, consulte o [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)]. Essa função usa o identificador para o thread (armazenados no `m_hThread` membro de dados de `CWinThread` objetos) e o endereço de um `DWORD`.  
  
 Se o thread ainda estiver ativo, **GetExitCodeThread** coloca **STILL_ACTIVE** fornecido `DWORD` endereço; caso contrário, o código de saída é colocado nesse endereço.  
  
 Recuperar o código de saída [CWinThread](../mfc/reference/cwinthread-class.md) objetos usa uma etapa extra. Por padrão, quando um `CWinThread` thread termina, o objeto de thread é excluído. Isso significa que você não pode acessar o `m_hThread` membro de dados porque o `CWinThread` objeto não existe mais. Para evitar essa situação, siga um destes procedimentos:  
  
-   Definir o `m_bAutoDelete` membro de dados para **FALSE**. Isso permite que o `CWinThread` objeto sobreviva depois que o thread foi encerrado. Você pode acessar o `m_hThread` membro de dados depois que o thread foi encerrado. Se você usar essa técnica, no entanto, você é responsável por destruir o `CWinThread` porque a estrutura não excluirá automaticamente-lo para você. Esse é o método preferencial.  
  
-   Armazene o identificador do segmento separadamente. Depois que o thread é criado, copie o `m_hThread` membro de dados (usando **:: DuplicateHandle**) a outra variável e acessá-lo através dessa variável. Dessa forma, o objeto é excluída automaticamente quando ocorre um encerramento e você ainda pode descobrir por que o thread foi encerrado. Tenha cuidado para que o thread não terminar antes de você pode duplicar o identificador. A maneira mais segura para fazer isso é passar **CREATE_SUSPENDED** para [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), armazenar o identificador e, em seguida, reiniciar o thread chamando [ResumeThread](../mfc/reference/cwinthread-class.md#resumethread).  
  
 O método permite que você determine por que um `CWinThread` objeto encerrado.  
  
## <a name="see-also"></a>Consulte também  
 [Multithread com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)   
 [_endthread, _endthreadex](../c-runtime-library/reference/endthread-endthreadex.md)   
 [_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)   
 [ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659)