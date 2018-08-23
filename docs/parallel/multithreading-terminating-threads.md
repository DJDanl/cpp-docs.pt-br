---
title: 'Multithreading: Encerrando Threads | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2411d11c154bef09b95d33e5b8598ba3c64dfb94
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42608838"
---
# <a name="multithreading-terminating-threads"></a>Multithread: encerrando threads
Duas situações normais fazem com que um thread seja finalizado: a função de controle sai ou o thread não tem permissão para executar até a conclusão. Se um processador de texto usou um thread para impressão em segundo plano, a função de controle finalizaria normalmente se a impressão fosse concluída com êxito. No entanto, se o usuário deseja cancelar a impressão, o thread de impressão em segundo plano tem que ser finalizado prematuramente. Este tópico explica como implementar cada situação e como obter o código de saída de um thread depois que ele é encerrado.  
  
- [Encerramento normal de Thread](#_core_normal_thread_termination)  
  
- [Terminação prematura de Thread](#_core_premature_thread_termination)  
  
- [Recuperando o código de saída de um Thread](#_core_retrieving_the_exit_code_of_a_thread)  
  
##  <a name="_core_normal_thread_termination"></a> Encerramento normal de Thread  
 
Para um thread de trabalho, o encerramento normal de thread é simple: a função de controle de sair e retornar um valor que indica o motivo do encerramento. Você pode usar o [AfxEndThread](../mfc/reference/application-information-and-management.md#afxendthread) função ou um **retornar** instrução. Normalmente, 0 significa conclusão com êxito, mas que cabe a você.  
  
Para um thread de interface do usuário, o processo é igualmente simple: de dentro do thread de interface do usuário, chame [PostQuitMessage](http://msdn.microsoft.com/library/windows/desktop/ms644945) no SDK do Windows. O único parâmetro que `PostQuitMessage` usa é o código de saída do thread. Para threads de trabalho, 0 significa normalmente conclusão com êxito.  
  
##  <a name="_core_premature_thread_termination"></a> Terminação prematura de Thread  
 
Encerrar um thread prematuramente é quase tão simple: chame [AfxEndThread](../mfc/reference/application-information-and-management.md#afxendthread) de dentro do thread. Passe o código de saída desejado como o único parâmetro. Isso interrompe a execução do thread, desaloca a pilha do thread, dispara todas as DLLs anexadas ao thread e exclui o objeto de thread da memória.  
  
`AfxEndThread` Deve ser chamado de dentro do thread ser encerrada. Se você quiser encerrar um thread de outro thread, você deve configurar um método de comunicação entre os dois threads.  
  
##  <a name="_core_retrieving_the_exit_code_of_a_thread"></a> Recuperando o código de saída de um Thread  
 
Para obter o código de saída de trabalhador ou o thread de interface do usuário, chame o [GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190) função. Para obter informações sobre essa função, consulte o SDK do Windows. Essa função usa o identificador para o thread (armazenado na `m_hThread` membro de dados de `CWinThread` objetos) e o endereço de um DWORD.  
  
Se o thread ainda estiver ativo, `GetExitCodeThread` coloca STILL_ACTIVE no endereço fornecido DWORD; caso contrário, o código de saída é colocado neste endereço.  
  
Recuperando o código de saída [CWinThread](../mfc/reference/cwinthread-class.md) objetos usa uma etapa adicional. Por padrão, quando um `CWinThread` thread é encerrado, o objeto de thread é excluído. Isso significa que você não pode acessar o `m_hThread` membro de dados porque o `CWinThread` objeto não existe mais. Para evitar essa situação, siga um destes procedimentos:  
  
- Defina o `m_bAutoDelete` membro de dados como FALSE. Isso permite que o `CWinThread` objeto sobreviva depois que o thread foi encerrado. Você pode acessar o `m_hThread` membro de dados depois que o thread foi encerrado. Se você usar essa técnica, no entanto, você será responsável por destruir o `CWinThread` objeto porque a estrutura não o excluirá automaticamente para você. Esse é o método preferencial.  
  
- Store o manipulador do thread separadamente. Depois que o thread é criado, copie seus `m_hThread` membro de dados (usando `::DuplicateHandle`) a outra variável e acessá-lo por meio dessa variável. Dessa forma, o objeto é excluída automaticamente quando a terminação ocorre e você ainda pode descobrir por que o thread foi encerrado. Tenha cuidado para que o thread não terminar antes de você pode duplicar o identificador. A maneira mais segura de fazer isso é passar CREATE_SUSPENDED para [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), o identificador de armazenar e, em seguida, retomar o thread chamando [ResumeThread](../mfc/reference/cwinthread-class.md#resumethread).  
  
Qualquer um dos métodos permite que você determine por que um `CWinThread` objeto encerrado.  
  
## <a name="see-also"></a>Consulte também  
 
[Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)   
[_endthread, _endthreadex](../c-runtime-library/reference/endthread-endthreadex.md)   
[_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)   
[ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659)