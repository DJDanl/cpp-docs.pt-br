---
title: "Classe de CWinThread | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CWinThread"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWinThread"
  - "threading [MFC], criando segmentos"
  - "threading [MFC], segurança"
  - "segmentos de trabalho"
ms.assetid: 10cdc294-4057-4e76-ac7c-a8967a89af0b
caps.latest.revision: 24
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinThread
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa um segmento de execução dentro de um aplicativo.  
  
## Sintaxe  
  
```  
class CWinThread : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinThread::CWinThread](../Topic/CWinThread::CWinThread.md)|Constrói um objeto de `CWinThread` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinThread::CreateThread](../Topic/CWinThread::CreateThread.md)|Inicia a execução de um objeto de `CWinThread` .|  
|[CWinThread::ExitInstance](../Topic/CWinThread::ExitInstance.md)|Substituição a limpeza quando o thread finalizar.|  
|[CWinThread::GetMainWnd](../Topic/CWinThread::GetMainWnd.md)|Recupera um ponteiro para a janela principal para o segmento.|  
|[CWinThread::GetThreadPriority](../Topic/CWinThread::GetThreadPriority.md)|Obtém a prioridade de segmento atual.|  
|[CWinThread::InitInstance](../Topic/CWinThread::InitInstance.md)|Substituição para executar a inicialização de instância de segmento.|  
|[CWinThread::IsIdleMessage](../Topic/CWinThread::IsIdleMessage.md)|Verifica para mensagens especiais.|  
|[CWinThread::OnIdle](../Topic/CWinThread::OnIdle.md)|Substituição para executar o processamento de segmento específico de tempo ocioso.|  
|[CWinThread::PostThreadMessage](../Topic/CWinThread::PostThreadMessage.md)|Enviar uma mensagem a outro objeto de `CWinThread` .|  
|[CWinThread::PreTranslateMessage](../Topic/CWinThread::PreTranslateMessage.md)|Mensagens de filtro antes que elas sejam despachados funções do windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934).|  
|[CWinThread::ProcessMessageFilter](../Topic/CWinThread::ProcessMessageFilter.md)|Determinadas mensagens de intercepções antes que atingiu o aplicativo.|  
|[CWinThread::ProcessWndProcException](../Topic/CWinThread::ProcessWndProcException.md)|Intercepta todas as exceções não tratadas geradas por manipuladores de mensagem e de comando do segmento.|  
|[CWinThread::PumpMessage](../Topic/CWinThread::PumpMessage.md)|Contém o loop de mensagem de segmento.|  
|[CWinThread::ResumeThread](../Topic/CWinThread::ResumeThread.md)|Diminui um segmento suspendem a contagem.|  
|[CWinThread::Run](../Topic/CWinThread::Run.md)|A função de controle para segmentos com uma mensagem bombeia.  Substituição para personalizar o loop de mensagem padrão.|  
|[CWinThread::SetThreadPriority](../Topic/CWinThread::SetThreadPriority.md)|Define a prioridade de segmento atual.|  
|[CWinThread::SuspendThread](../Topic/CWinThread::SuspendThread.md)|Sai um segmento suspendem a contagem.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ALÇA de CWinThread::operator](../Topic/CWinThread::operator%20HANDLE.md)|Recupera a alça de objeto de `CWinThread` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinThread::m\_bAutoDelete](../Topic/CWinThread::m_bAutoDelete.md)|Especifica se destruir no fim do segmento.|  
|[CWinThread::m\_hThread](../Topic/CWinThread::m_hThread.md)|Identificador para o segmento atual.|  
|[CWinThread::m\_nThreadID](../Topic/CWinThread::m_nThreadID.md)|Identificação do segmento atual.|  
|[CWinThread::m\_pActiveWnd](../Topic/CWinThread::m_pActiveWnd.md)|Ponteiro para a janela principal do aplicativo quando um contêiner de servidor OLE está no lugar.|  
|[CWinThread::m\_pMainWnd](../Topic/CWinThread::m_pMainWnd.md)|Contém um ponteiro para a janela principal do aplicativo.|  
  
## Comentários  
 O segmento principal de execução é geralmente fornecido por um objeto derivado de `CWinApp`; `CWinApp` é derivado de `CWinThread`.  Os objetos adicionais de `CWinThread` permitem vários segmentos em um determinado aplicativo.  
  
 Há dois tipos gerais de segmentos que `CWinThread` suporta: segmentos de trabalho e segmentos da interface do usuário.  Segmentos de trabalho não têm nenhuma mensagem bomba: por exemplo, um segmento que executa cálculos em segundo plano em um aplicativo de planilha.  Segmentos de interface do usuário têm as mensagens de mensagem de uma bomba do processo e recebidas do sistema.  [CWinApp](../../mfc/reference/cwinapp-class.md) e as classes derivadas de ela são exemplos de segmentos da interface do usuário.  Outros segmentos da interface do usuário também podem ser derivados diretamente de `CWinThread`.  
  
 Os objetos de classe `CWinThread` geralmente existem para a duração do segmento.  Se você desejar alterar esse comportamento, defina [m\_bAutoDelete](../Topic/CWinThread::m_bAutoDelete.md) a **Falso**.  
  
 A classe de `CWinThread` é necessária para tornar seu código e MFC totalmente thread\-safe.  Os dados do local com usados pela estrutura para manter informações específicas de segmento são gerenciados por objetos de `CWinThread` .  Devido a essa dependência em `CWinThread` para manipular dados de com local, qualquer segmento que usar o MFC deve ser criado pelo MFC.  Por exemplo, um segmento criado pela função [\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md) em tempo de execução não pode usar quaisquer APIs MFC.  
  
 Para criar um segmento, chame [AfxBeginThread](../Topic/AfxBeginThread.md).  Há duas formas, dependendo se você quiser um trabalhador ou um encadeamento de interface do usuário.  Se você quiser um encadeamento de interface do usuário, passe a `AfxBeginThread` um ponteiro para `CRuntimeClass` do seu `CWinThread`\- classe derivada.  Se você deseja criar um segmento de trabalho, passe a `AfxBeginThread` um ponteiro para a função de controle e o parâmetro na função de controle.  Para ambos os segmentos de trabalho e segmentos da interface do usuário, você pode especificar parâmetros opcionais que modificam a prioridade, o tamanho da pilha, os sinalizadores de design, e os atributos de segurança.  `AfxBeginThread` retornará um ponteiro para o novo objeto de `CWinThread` .  
  
 Em vez de chamar `AfxBeginThread`, você pode construir `CWinThread`objeto derivado e chamar `CreateThread`.  Este método de dois estágios de compilação é útil se você deseja reutilizar o objeto de `CWinThread` entre criar e terminações sucessivas de um segmento.  
  
 Para obter mais informações sobre `CWinThread`, consulte os artigos [multithreading com C\+\+ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md), [multithreading: Criando segmentos da interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md), [multithreading: Criando segmentos de trabalho](../../parallel/multithreading-creating-worker-threads.md), e [multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `CWinThread`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CWinApp](../../mfc/reference/cwinapp-class.md)   
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)