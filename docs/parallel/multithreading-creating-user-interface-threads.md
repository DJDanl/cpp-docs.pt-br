---
title: 'Multithreading: Criando Threads de Interface do usuário | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
f1_keywords:
- CREATE_SUSPENDED
- SECURITY_ATTRIBUTES
dev_langs:
- C++
helpviewer_keywords:
- multithreading [C++], user interface threads
- threading [C++], creating threads
- threading [C++], user interface threads
- user interface threads [C++]
- threading [MFC], user interface threads
ms.assetid: 446925c1-db59-46ea-ae5b-d5ae5d5b91d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0223e342bf2312919247d42564445a9e116ca59b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42607389"
---
# <a name="multithreading-creating-user-interface-threads"></a>Multithread: criando threads de interface do usuário
Um thread de interface do usuário geralmente é usado para manipular a entrada do usuário e responder aos eventos de usuário, independentemente dos threads de execução de outras partes do aplicativo. O thread principal do aplicativo (fornecido na sua `CWinApp`-classe derivada) já é criada e iniciada para você. Este tópico descreve as etapas necessárias para criar threads adicionais da interface do usuário.  
  
A primeira coisa que você deve fazer ao criar um thread de interface do usuário é derive uma classe de [CWinThread](../mfc/reference/cwinthread-class.md). Você deve declarar e implementar essa classe usando o [DECLARE_DYNCREATE](../mfc/reference/run-time-object-model-services.md#declare_dyncreate) e [IMPLEMENT_DYNCREATE](../mfc/reference/run-time-object-model-services.md#implement_dyncreate) macros. Essa classe deve substituir algumas funções e pode substituir outras pessoas. Essas funções e o que deve fazer são apresentados na tabela a seguir.  
  
### <a name="functions-to-override-when-creating-a-user-interface-thread"></a>Função para substituir durante a criação de um Thread de Interface do usuário  
  
|Função|Finalidade|  
|--------------|-------------|  

|[ExitInstance](../mfc/reference/cwinthread-class.md#exitinstance)| Execute limpeza quando o thread é encerrado. Costumam ser substituídos. |  
|[InitInstance](../mfc/reference/cwinthread-class.md#initinstance)| Execute a inicialização de instância de thread. Deve ser substituído. |  
|[OnIdle](../mfc/reference/cwinthread-class.md#onidle)| Execute o processamento de tempo ocioso do thread específico. Não costumam ser substituídos. |  
|[PreTranslateMessage](../mfc/reference/cwinthread-class.md#pretranslatemessage)| Filtrar mensagens antes de serem expedidas `TranslateMessage` e `DispatchMessage`. Não costumam ser substituídos. |  
|[ProcessWndProcException](../mfc/reference/cwinthread-class.md#processwndprocexception)| Intercepte exceções sem tratamento lançadas por manipuladores de mensagens e comandos do segmento. Não costumam ser substituídos. |  
|[Executar](../mfc/reference/cwinthread-class.md#run)| Função de controle para o thread. Contém a bomba de mensagens. Raramente é substituído. |  

  
O MFC fornece duas versões do `AfxBeginThread` por meio de sobrecarga de parâmetro: um que só pode criar threads de trabalho e uma que pode criar threads de trabalho ou threads de interface do usuário. Para iniciar o thread de interface do usuário, chame a segunda sobrecarga de [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), fornecendo as seguintes informações:  
  
- O [RUNTIME_CLASS](../mfc/reference/run-time-object-model-services.md#runtime_class) da classe derivada de `CWinThread`.  
  
- (Opcional) O nível de prioridade desejada. O padrão é prioridade normal. Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no SDK do Windows.  
  
- (Opcional) O tamanho desejado de pilha do thread. O padrão é o mesmo tamanho de pilha do thread de criação.  
  
- (Opcional) CREATE_SUSPENDED se você quiser que o thread a ser criado em um estado suspenso. O padrão é 0 ou iniciar o thread normalmente.  
  
- (Opcional) Os atributos de segurança desejado. O padrão é o mesmo acesso que o thread pai. Para obter mais informações sobre o formato de informações de segurança, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.  
  
`AfxBeginThread` faz a maior parte do trabalho para você. Ele cria um novo objeto de sua classe, inicializa-o com as informações fornecidas e chamadas [CWinThread::CreateThread](../mfc/reference/cwinthread-class.md#createthread) para iniciar a execução do thread. Verificações são feitas em todo o procedimento para garantir que todos os objetos são desalocados corretamente caso de falha de qualquer parte da criação.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
- [Multithreading: encerrando threads](../parallel/multithreading-terminating-threads.md)  
  
- [Multithreading: criando threads de trabalho](../parallel/multithreading-creating-worker-threads.md)  
  
- [Processos e Threads](http://msdn.microsoft.com/library/windows/desktop/ms684841)  
  
## <a name="see-also"></a>Consulte também  
 
[Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)