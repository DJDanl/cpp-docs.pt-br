---
title: 'Multithreading: Criando threads da interface do usuário do MFC'
ms.date: 08/27/2018
f1_keywords:
- CREATE_SUSPENDED
- SECURITY_ATTRIBUTES
helpviewer_keywords:
- multithreading [C++], user interface threads
- threading [C++], creating threads
- threading [C++], user interface threads
- user interface threads [C++]
- threading [MFC], user interface threads
ms.assetid: 446925c1-db59-46ea-ae5b-d5ae5d5b91d8
ms.openlocfilehash: 1cd28a848f9be223f43412c3e0f3961cef9db6c7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512080"
---
# <a name="multithreading-creating-mfc-user-interface-threads"></a>Multithreading: Criando threads da interface do usuário do MFC

Um thread de interface de usuário geralmente é usado para manipular a entrada do usuário e responder a eventos de usuário independentemente de threads que executam outras partes do aplicativo. O thread principal do aplicativo (fornecido em `CWinApp`sua classe derivada) já foi criado e iniciado para você. Este tópico descreve as etapas necessárias para criar threads de interface de usuário adicionais.

A primeira coisa que você deve fazer ao criar um thread de interface do usuário é derivar uma classe de [CWinThread](../mfc/reference/cwinthread-class.md). Você deve declarar e implementar essa classe, usando as macros [DECLARE_DYNCREATE](../mfc/reference/run-time-object-model-services.md#declare_dyncreate) e [IMPLEMENT_DYNCREATE](../mfc/reference/run-time-object-model-services.md#implement_dyncreate) . Essa classe deve substituir algumas funções e pode substituir outras. Essas funções e o que elas devem fazer são apresentados na tabela a seguir.

### <a name="functions-to-override-when-creating-a-user-interface-thread"></a>Funções a serem substituídas ao criar um thread de interface do usuário

|Função|Finalidade|
|--------------|-------------|
|[ExitInstance](../mfc/reference/cwinthread-class.md#exitinstance)|Executa a limpeza quando o thread é encerrado. Geralmente substituído.|
|[InitInstance](../mfc/reference/cwinthread-class.md#initinstance)|Execute a inicialização da instância de thread. Deve ser substituído.|
|[OnIdle](../mfc/reference/cwinthread-class.md#onidle)|Executar o processamento de tempo ocioso específico do thread. Geralmente não é substituído.|
|[PreTranslateMessage](../mfc/reference/cwinthread-class.md#pretranslatemessage)|Filtre as mensagens antes que elas sejam expedidas `DispatchMessage`para `TranslateMessage` e. Geralmente não é substituído.|
|[ProcessWndProcException](../mfc/reference/cwinthread-class.md#processwndprocexception)|Interceptar exceções sem tratamento lançadas pelos manipuladores de mensagem e comando do thread. Geralmente não é substituído.|
|[Executar](../mfc/reference/cwinthread-class.md#run)|Controlando a função para o thread. Contém a bomba de mensagem. Raramente substituído.|

O MFC fornece duas versões `AfxBeginThread` do por meio de sobrecarga de parâmetro: uma que só pode criar threads de trabalho e uma que possa criar threads de interface do usuário ou threads de trabalho. Para iniciar o thread da interface do usuário, chame a segunda sobrecarga de [AfxBeginThread](../mfc/reference/application-information-and-management.md#afxbeginthread), fornecendo as seguintes informações:

- O [RUNTIME_CLASS](../mfc/reference/run-time-object-model-services.md#runtime_class) da classe da `CWinThread`qual você deriva.

- Adicional O nível de prioridade desejado. O padrão é a prioridade normal. Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

- Adicional O tamanho de pilha desejado para o thread. O padrão é a mesma pilha de tamanho que o thread de criação.

- Adicional CREATE_SUSPENDED se você quiser que o thread seja criado em um estado suspenso. O padrão é 0 ou iniciar o thread normalmente.

- Adicional Os atributos de segurança desejados. O padrão é o mesmo acesso que o thread pai. Para obter mais informações sobre o formato dessas informações de segurança, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

`AfxBeginThread`faz a maior parte do trabalho para você. Ele cria um novo objeto da sua classe, inicializa-o com as informações fornecidas e chama [CWinThread:: CreateThread](../mfc/reference/cwinthread-class.md#createthread) para iniciar a execução do thread. As verificações são feitas em todo o procedimento para garantir que todos os objetos sejam desalocados corretamente caso qualquer parte da criação falhe.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Multithreading: terminar threads](multithreading-terminating-threads.md)

- [Multithreading: criar threads de trabalho](multithreading-creating-worker-threads.md)

- [Processos e threads](/windows/win32/ProcThread/processes-and-threads)

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
