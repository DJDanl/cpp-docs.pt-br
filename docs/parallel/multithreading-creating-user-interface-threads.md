---
title: "Multithread: criando threads de interface do usu&#225;rio | Microsoft Docs"
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
  - "SECURITY_ATTRIBUTES"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "multithreading [C++], threads de interface de usuário"
  - "threading [C++], criando threads"
  - "threading [C++], threads de interface de usuário"
  - "threading [MFC], threads de interface de usuário"
  - "threads de interface de usuário [C++]"
ms.assetid: 446925c1-db59-46ea-ae5b-d5ae5d5b91d8
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread: criando threads de interface do usu&#225;rio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um thread da interface do usuário é usado para tratar a entrada do usuário e responder a eventos de usuário independentemente dos threads que executam outras partes do aplicativo.  O thread principal do aplicativo \(fornecido no `CWinApp`\- classe derivada\) já está criado e iniciado para você.  Este tópico descreve as etapas necessárias para criar threads adicionais da interface do usuário.  
  
 A primeira coisa que você deve fazer ao criar um thread da interface do usuário é deve derivar uma classe de [CWinThread](../mfc/reference/cwinthread-class.md).  Você deve declarar e implementar essa classe, usando as macros de [DECLARE\_DYNCREATE](../Topic/DECLARE_DYNCREATE.md) e de [IMPLEMENT\_DYNCREATE](../Topic/IMPLEMENT_DYNCREATE.md) .  Essa classe deve substituir algumas funções e pode substituir outro.  Essas funções e o que devem fazer são apresentadas na tabela a seguir.  
  
### Funções para substituir ao criar um thread da interface do usuário  
  
|Função|Finalidade|  
|------------|----------------|  
|[ExitInstance](../Topic/CWinThread::ExitInstance.md)|Executar a limpeza quando o thread termina.  Geralmente substituído.|  
|[InitInstance](../Topic/CWinThread::InitInstance.md)|Executar a inicialização da instância do thread.  Deve ser substituído.|  
|[OnIdle](../Topic/CWinThread::OnIdle.md)|Executar o processamento de específico do tempo ocioso.  Substituído normalmente não.|  
|[PreTranslateMessage](../Topic/CWinThread::PreTranslateMessage.md)|Mensagens de filtro antes que sejam despachados a **TranslateMessage** e a **DispatchMessage**.  Substituído normalmente não.|  
|[ProcessWndProcException](../Topic/CWinThread::ProcessWndProcException.md)|Intercepte sem\-tratamento as exceções lançadas pelos manipuladores de mensagem e do comando de thread.  Substituído normalmente não.|  
|[Executar](../Topic/CWinThread::Run.md)|Função de controle para o thread.  Contém a bomba da mensagem.  Substituído com pouca frequência.|  
  
 MFC O fornece duas versões de `AfxBeginThread` com o sobrecarregamento do parâmetro: um que só pode criar threads de trabalho e um que pode criar threads ou threads de trabalho da interface do usuário.  Para iniciar o thread da interface do usuário, chame a segunda sobrecarga de [AfxBeginThread](../Topic/AfxBeginThread.md), fornecendo as seguintes informações:  
  
-   [RUNTIME\_CLASS](../Topic/RUNTIME_CLASS.md) da classe que podem ser derivadas de `CWinThread`.  
  
-   \(Opcional\) O nível de prioridade desejada.  O padrão é prioridade normal.  Para obter mais informações sobre os níveis de prioridade disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
-   \(Opcional\) O tamanho desejado de pilha para o thread.  O padrão é o mesmo tamanho de pilha do thread de criação.  
  
-   \(Opcional\) **CREATE\_SUSPENDED** se você deseja que o segmento seja criado em um estado suspenso.  O padrão é 0 ou iniciar o thread normalmente.  
  
-   \(Opcional\) Os atributos de segurança desejados.  O padrão é o mesmo acesso que o thread pai.  Para obter mais informações sobre o formato dessas informações de segurança, consulte [ATRIBUTOS DE SEGURANÇA](http://msdn.microsoft.com/library/windows/desktop/aa379560) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  
  
 `AfxBeginThread` faz a maioria do trabalho para você.  Cria um novo objeto a partir da sua classe, para inicializá\-lo com as informações que você fornece, e chame [CWinThread::CreateThread](../Topic/CWinThread::CreateThread.md) para iniciar a execução do thread.  As verificações são feitas durante qualquer procedimento para certificar\-se que todos os objetos são desalocados corretamente se qualquer parte da falha de design.  
  
## Que você deseja saber mais?  
  
-   [Multithreading: Threads de Terminação](../parallel/multithreading-terminating-threads.md)  
  
-   [Multithreading: Criando Threads de Trabalho](../parallel/multithreading-creating-worker-threads.md)  
  
-   [\<caps:sentence id\="tgt49" sentenceid\="d446961ca833a037f83b141ec4859428" class\="tgtSentence"\>Processos e threads\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms684841)  
  
## Consulte também  
 [Multithread com C\+\+ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)