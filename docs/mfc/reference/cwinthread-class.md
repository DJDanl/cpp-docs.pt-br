---
title: Classe CWinThread | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWinThread
dev_langs:
- C++
helpviewer_keywords:
- worker threads
- threading [MFC], safety
- CWinThread class
- threading [MFC], creating threads
ms.assetid: 10cdc294-4057-4e76-ac7c-a8967a89af0b
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 866e847f9c1d73d6f9882e50b1274fbad9e21a39
ms.lasthandoff: 02/25/2017

---
# <a name="cwinthread-class"></a>Classe CWinThread
Representa um segmento de execução dentro de um aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWinThread : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinThread::CWinThread](#cwinthread)|Constrói um objeto `CWinThread`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinThread::CreateThread](#createthread)|Inicia a execução de uma `CWinThread` objeto.|  
|[CWinThread::ExitInstance](#exitinstance)|Substituição para a limpeza quando o segmento é encerrado.|  
|[CWinThread::GetMainWnd](#getmainwnd)|Recupera um ponteiro para a janela principal para o thread.|  
|[CWinThread::GetThreadPriority](#getthreadpriority)|Obtém a prioridade do thread atual.|  
|[CWinThread::InitInstance](#initinstance)|Substitua para executar a inicialização de instância de thread.|  
|[CWinThread::IsIdleMessage](#isidlemessage)|Verifica se há mensagens especiais.|  
|[CWinThread::OnIdle](#onidle)|Substitua para executar o processamento de tempo ocioso do thread específico.|  
|[CWinThread::PostThreadMessage](#postthreadmessage)|Envia uma mensagem para outro `CWinThread` objeto.|  
|[CWinThread::PreTranslateMessage](#pretranslatemessage)|Filtra as mensagens antes de serem distribuídos para as funções do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934).|  
|[CWinThread::ProcessMessageFilter](#processmessagefilter)|Intercepta determinadas mensagens antes que elas atinjam o aplicativo.|  
|[CWinThread::ProcessWndProcException](#processwndprocexception)|Intercepta todas as exceções sem tratamento lançadas por mensagem do thread e manipuladores de comandos.|  
|[CWinThread::PumpMessage](#pumpmessage)|Contém o loop de mensagens do thread.|  
|[CWinThread::ResumeThread](#resumethread)|Contagem de suspensões decrementa uma do thread.|  
|[CWinThread::Run](#run)|Controlando a função para segmentos com uma bomba de mensagem. Substitua para personalizar o loop de mensagem padrão.|  
|[CWinThread::SetThreadPriority](#setthreadpriority)|Define a prioridade do thread atual.|  
|[CWinThread::SuspendThread](#suspendthread)|Contagem de suspensões incrementos de um thread.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Identificador de CWinThread::operator](#operator_handle)|Recupera o identificador do `CWinThread` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinThread::m_bAutoDelete](#m_bautodelete)|Especifica se deve destruir o objeto no encerramento do thread.|  
|[CWinThread::m_hThread](#m_hthread)|Manipula o thread atual.|  
|[CWinThread::m_nThreadID](#m_nthreadid)|ID do thread atual.|  
|[CWinThread::m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo de contêiner quando um servidor OLE está ativo no local.|  
|[CWinThread::m_pMainWnd](#m_pmainwnd)|Contém um ponteiro para a janela principal do aplicativo.|  
  
## <a name="remarks"></a>Comentários  
 O thread principal de execução é geralmente fornecido por um objeto derivado de `CWinApp`; `CWinApp` é derivado de `CWinThread`. Adicionais `CWinThread` objetos permitem que vários threads dentro de um determinado aplicativo.  
  
 Há dois tipos gerais de threads que `CWinThread` suporta: threads de trabalho e threads de interface do usuário. Threads de trabalho não tem nenhum bombeador: por exemplo, um thread que executa cálculos de plano de fundo em um aplicativo de planilha. Threads de interface do usuário tem uma bomba de mensagem e processam as mensagens recebidas do sistema. [CWinApp](../../mfc/reference/cwinapp-class.md) e classes derivadas dela são exemplos de threads de interface do usuário. Outros threads de interface do usuário também podem ser derivados diretamente de `CWinThread`.  
  
 Objetos da classe `CWinThread` normalmente existe para a duração do segmento. Se você quiser modificar esse comportamento, defina [m_bAutoDelete](#m_bautodelete) para **FALSE**.  
  
 O `CWinThread` classe é necessária para tornar seu código e o MFC totalmente thread-safe. Dados de thread local usados pelo framework para manter informações específicas de thread gerenciados pelo `CWinThread` objetos. Devido a essa dependência `CWinThread` para lidar com dados de thread local, qualquer thread que usa MFC deve ser criada por MFC. Por exemplo, um thread criado pela função de tempo de execução [beginthread, beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) não é possível usar quaisquer APIs do MFC.  
  
 Para criar um thread, chame [AfxBeginThread](application-information-and-management.md#afxbeginthread). Há duas formas, dependendo se você deseja que um thread de trabalho ou a interface do usuário. Se você quiser que um thread de interface do usuário, passar para `AfxBeginThread` um ponteiro para o `CRuntimeClass` de seu `CWinThread`-classe derivada. Se você quiser criar um thread de trabalho, passe para `AfxBeginThread` um ponteiro para a função de controle e o parâmetro para a função de controle. Para threads de trabalho e threads de interface do usuário, você pode especificar parâmetros opcionais que modificam o tamanho da pilha, prioridade, sinalizadores de criação e atributos de segurança. `AfxBeginThread`Retorna um ponteiro para o novo `CWinThread` objeto.  
  
 Em vez de chamar `AfxBeginThread`, você pode construir um `CWinThread`-derivados do objeto e, em seguida, chame `CreateThread`. Esse método de duas fases de construção é útil se você quiser reutilizar o `CWinThread` objeto entre criação sucessiva e encerramentos de execuções do thread.  
  
 Para obter mais informações sobre `CWinThread`, consulte os artigos [Multithreading com C++ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md), [Multithreading: Criando Threads de Interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md), [Multithreading: Criando Threads de trabalho](../../parallel/multithreading-creating-worker-threads.md), e [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CWinThread`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecreatethreada--cwinthreadcreatethread"></a><a name="createthread"></a>CWinThread::CreateThread  
 Cria um thread para executar no espaço de endereço do processo de chamada.  
  
```  
BOOL CreateThread(
    DWORD dwCreateFlags = 0,  
    UINT nStackSize = 0,  
    LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCreateFlags`  
 Especifica um sinalizador adicional que controla a criação do thread. Este sinalizador pode conter um dos dois valores:  
  
- **CREATE_SUSPENDED** iniciar o thread com uma contagem de suspensões de um. Use **CREATE_SUSPENDED** para inicializar todos os dados de membro de `CWinThread` de objeto, como [m_bAutoDelete](#m_bautodelete) ou qualquer membro da sua classe derivada, antes do segmento começa a ser executado. Quando a inicialização estiver concluída, use o [CWinThread::ResumeThread](#resumethread) para iniciar o thread em execução. O thread não será executado até `CWinThread::ResumeThread` é chamado.  
  
- **0** iniciar o thread imediatamente após a criação.  
  
 `nStackSize`  
 Especifica o tamanho em bytes da pilha para o novo thread. Se **0**, o tamanho da pilha padrão é o mesmo tamanho que o thread do processo principal.  
  
 `lpSecurityAttrs`  
 Aponta para um [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica os atributos de segurança para o thread.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o thread é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `AfxBeginThread` para criar um objeto de thread e executá-lo em uma única etapa. Use `CreateThread` se quiser reutilizar o objeto de thread entre sucessiva criação e finalização de execuções de thread.  
  
##  <a name="a-namecwinthreada--cwinthreadcwinthread"></a><a name="cwinthread"></a>CWinThread::CWinThread  
 Constrói um objeto `CWinThread`.  
  
```  
CWinThread();
```  
  
### <a name="remarks"></a>Comentários  
 Para começar a execução do thread, chame o [CreateThread](#createthread) função de membro. Você normalmente irá criar threads chamando [AfxBeginThread](http://msdn.microsoft.com/library/e9e8684d-24f7-4599-8fdf-1f4f560a753b), que chamará este construtor e `CreateThread`.  
  
##  <a name="a-nameexitinstancea--cwinthreadexitinstance"></a><a name="exitinstance"></a>CWinThread::ExitInstance  
 Chamado pela estrutura de dentro de um raramente substituído [executar](#run) a função de membro para sair dessa instância do segmento, ou se uma chamada para [InitInstance](#initinstance) falhar.  
  
```  
virtual int ExitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Código de saída do segmento; 0 não indica que nenhum erro, e valores maiores que 0 indicam um erro. Esse valor pode ser recuperado chamando [GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190).  
  
### <a name="remarks"></a>Comentários  
 Não chame essa função de membro de qualquer lugar mas dentro do **executar** função de membro. Essa função de membro é usada somente em threads de interface do usuário.  
  
 A implementação padrão dessa função exclui o `CWinThread` objeto se [m_bAutoDelete](#m_bautodelete) é **TRUE**. Substitua essa função se você deseja realizar limpeza adicional quando o thread é encerrado. A implementação do `ExitInstance` deve chamar a versão da classe base depois que seu código é executado.  
  
##  <a name="a-namegetmainwnda--cwinthreadgetmainwnd"></a><a name="getmainwnd"></a>CWinThread::GetMainWnd  
 Se seu aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo em vez de referir-se diretamente para o `m_pMainWnd` membro do objeto do aplicativo.  
  
```  
virtual CWnd* GetMainWnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função retorna um ponteiro para um dos dois tipos de janelas. Se o thread faz parte de um servidor OLE e tem um objeto que está ativo no local dentro de um contêiner do active, esta função retorna o [CWinApp::m_pActiveWnd](../../mfc/reference/cwinapp-class.md#m_pactivewnd) membro de dados a `CWinThread` objeto.  
  
 Se não há nenhum objeto está ativo no local dentro de um contêiner ou seu aplicativo não é um servidor OLE, essa função retorna o [m_pMainWnd](#m_pmainwnd) membro de dados do seu objeto de thread.  
  
### <a name="remarks"></a>Comentários  
 Para threads de interface do usuário, isso é equivalente a referência diretamente para o `m_pActiveWnd` membro do objeto do aplicativo.  
  
 Se seu aplicativo não é um servidor OLE, chamar essa função é equivalente ao referir-se diretamente para o `m_pMainWnd` membro do objeto do aplicativo.  
  
 Substitua essa função para modificar o comportamento padrão.  
  
##  <a name="a-namegetthreadprioritya--cwinthreadgetthreadpriority"></a><a name="getthreadpriority"></a>CWinThread::GetThreadPriority  
 Obtém o nível de prioridade do thread atual deste thread.  
  
```  
int GetThreadPriority();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nível de prioridade de thread atual dentro de sua classe de prioridade. O valor retornado será um dos seguintes, listados da prioridade mais alta para a mais baixa:  
  
- **THREAD_PRIORITY_TIME_CRITICAL**  
  
- **THREAD_PRIORITY_HIGHEST**  
  
- **THREAD_PRIORITY_ABOVE_NORMAL**  
  
- **THREAD_PRIORITY_NORMAL**  
  
- **THREAD_PRIORITY_BELOW_NORMAL**  
  
- **THREAD_PRIORITY_LOWEST**  
  
- **THREAD_PRIORITY_IDLE**  
  
 Para obter mais informações sobre essas prioridades, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameinitinstancea--cwinthreadinitinstance"></a><a name="initinstance"></a>CWinThread::InitInstance  
 `InitInstance`deve ser substituído para inicializar cada nova instância de um thread de interface do usuário.  
  
```  
virtual BOOL InitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você substituir `InitInstance` para executar tarefas que devem ser concluídas quando um thread é criado.  
  
 Essa função de membro é usada somente em threads de interface do usuário. Executar a inicialização de threads de trabalho na função de controle passada para [AfxBeginThread](application-information-and-management.md#afxbeginthread).  
  
##  <a name="a-nameisidlemessagea--cwinthreadisidlemessage"></a><a name="isidlemessage"></a>CWinThread::IsIdleMessage  
 Substituir essa função para manter **OnIdle** chamada após gerar mensagens específicas.  
  
```  
virtual BOOL IsIdleMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Aponta para a mensagem atual que está sendo processada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `OnIdle` deve ser chamado após o processamento de mensagem; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não chama **OnIdle** depois de mensagens do mouse redundantes e mensagens geradas pelo piscando sinais de interpolação.  
  
 Se um aplicativo tiver criado um temporizador curto, **OnIdle** será chamado com frequência, causando problemas de desempenho. Para melhorar o desempenho de um aplicativo, substituir `IsIdleMessage` do aplicativo `CWinApp`-classe para verificar se há derivada `WM_TIMER` mensagens da seguinte maneira:  
  
 [!code-cpp[NVC_MFCDocView&#189;](../../mfc/codesnippet/cpp/cwinthread-class_1.cpp)]  
  
 Manipulando `WM_TIMER` dessa forma melhora o desempenho de aplicativos que usam temporizadores curtos.  
  
##  <a name="a-namembautodeletea--cwinthreadmbautodelete"></a><a name="m_bautodelete"></a>CWinThread::m_bAutoDelete  
 Especifica se o `CWinThread` objeto deve ser excluído automaticamente no encerramento do thread.  
  
```  
BOOL m_bAutoDelete;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_bAutoDelete` membro de dados é uma variável pública do tipo **BOOL**.  
  
 O valor de `m_bAutoDelete` não afeta como o identificador de thread subjacente é fechado. O identificador de thread sempre é fechado quando o `CWinThread` objeto é destruído.  
  
##  <a name="a-namemhthreada--cwinthreadmhthread"></a><a name="m_hthread"></a>CWinThread::m_hThread  
 Manipula o thread anexado a esse `CWinThread`.  
  
```  
HANDLE m_hThread;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_hThread` membro de dados é uma variável pública do tipo `HANDLE`. Só é válida se existir subjacente thread atualmente.  
  
##  <a name="a-namemnthreadida--cwinthreadmnthreadid"></a><a name="m_nthreadid"></a>CWinThread::m_nThreadID  
 ID do thread anexado a esse `CWinThread`.  
  
```  
DWORD m_nThreadID;  
```  
  
### <a name="remarks"></a>Comentários  
 O **m_nThreadID** membro de dados é uma variável pública do tipo `DWORD`. Só é válida se existir subjacente thread atualmente.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [AfxGetThread](application-information-and-management.md#afxgetthread).  
  
##  <a name="a-namempactivewnda--cwinthreadmpactivewnd"></a><a name="m_pactivewnd"></a>CWinThread::m_pActiveWnd  
 Use este membro de dados para armazenar um ponteiro para o objeto de janela ativa do thread.  
  
```  
CWnd* m_pActiveWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 A biblioteca Microsoft Foundation Class terminará automaticamente seu thread quando a janela referido por `m_pActiveWnd` está fechado. Se esse thread é o thread primário para um aplicativo, o aplicativo também será encerrado. Se este membro de dados é **nulo**, a janela ativa para o aplicativo `CWinApp` objeto será herdado. `m_pActiveWnd`é uma variável pública do tipo **CWnd\***.  
  
 Normalmente, você define essa variável de membro quando você substituir `InitInstance`. Em um thread de trabalho, o valor desse membro de dados é herdado do thread pai.  
  
##  <a name="a-namempmainwnda--cwinthreadmpmainwnd"></a><a name="m_pmainwnd"></a>CWinThread::m_pMainWnd  
 Use este membro de dados para armazenar um ponteiro para o objeto de janela principal do thread.  
  
```  
CWnd* m_pMainWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 A biblioteca Microsoft Foundation Class terminará automaticamente seu thread quando a janela referido por `m_pMainWnd` está fechado. Se esse thread é o thread primário para um aplicativo, o aplicativo também será encerrado. Se este membro de dados é **nulo**, a janela principal do aplicativo `CWinApp` objeto será usado para determinar quando terminar o thread. `m_pMainWnd`é uma variável pública do tipo **CWnd\***.  
  
 Normalmente, você define essa variável de membro quando você substituir `InitInstance`. Em um thread de trabalho, o valor desse membro de dados é herdado do thread pai.  
  
##  <a name="a-nameonidlea--cwinthreadonidle"></a><a name="onidle"></a>CWinThread::OnIdle  
 Substitua essa função de membro para executar o processamento de tempo ocioso.  
  
```  
virtual BOOL OnIdle(LONG lCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lCount`  
 Um contador incrementado toda vez que `OnIdle` é chamado quando a fila de mensagens do thread está vazia. Essa contagem é redefinida como 0, sempre que uma nova mensagem é processada. Você pode usar o `lCount` parâmetro para determinar o tamanho relativo de tempo que o thread está ocioso sem processamento de uma mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero para receber o tempo de processamento mais ocioso; 0 se não há mais tempo de processamento ocioso é necessária.  
  
### <a name="remarks"></a>Comentários  
 `OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do thread está vazia. Use sua substituição para chamar seu próprio plano de fundo tarefas manipulador ocioso.  
  
 `OnIdle`deve retornar 0 para indicar que nenhum tempo de processamento ocioso adicional é necessário. O `lCount` parâmetro é incrementado toda vez que `OnIdle` é chamado quando a fila de mensagens está vazia e é redefinida como 0, sempre que uma nova mensagem é processada. Você pode chamar suas rotinas de ociosas diferentes com base nessa contagem.  
  
 A implementação padrão dessa função de membro libera os objetos temporários e bibliotecas de vínculo dinâmico não usada da memória.  
  
 Essa função de membro é usada somente em threads de interface do usuário.  
  
 Porque o aplicativo não pode processar mensagens até `OnIdle` retorna, não execute tarefas demoradas nessa função.  
  
##  <a name="a-nameoperatorhandlea--cwinthreadoperator-handle"></a><a name="operator_handle"></a>Identificador de CWinThread::operator  
 Recupera o identificador do `CWinThread` objeto.  
  
```  
operator HANDLE() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador do objeto thread; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use a alça para chamar diretamente as APIs do Windows.  
  
##  <a name="a-namepostthreadmessagea--cwinthreadpostthreadmessage"></a><a name="postthreadmessage"></a>CWinThread::PostThreadMessage  
 Chamado para postar uma mensagem definida pelo usuário para outro `CWinThread` objeto.  
  
```  
BOOL PostThreadMessage(
    UINT message,  
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `message`  
 ID da mensagem definida pelo usuário.  
  
 `wParam`  
 Primeiro parâmetro da mensagem.  
  
 `lParam`  
 Segundo parâmetro de mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A mensagem postada é mapeada para o manipulador de mensagens apropriado, a macro de mapa de mensagem `ON_THREAD_MESSAGE`.  
  
> [!NOTE]
>  Ao chamar o Windows [PostThreadMessage](http://msdn.microsoft.com/library/windows/desktop/ms644946) função em um aplicativo MFC, a mensagem MFC manipuladores não serão chamados. Para obter mais informações, consulte o artigo da Base de dados de Conhecimento, "PRB: MFC mensagem manipulador não chamado com PostThreadMessage()" (Q142415).  
  
##  <a name="a-namepretranslatemessagea--cwinthreadpretranslatemessage"></a><a name="pretranslatemessage"></a>CWinThread::PreTranslateMessage  
 Substituir essa função para filtrar mensagens de janela antes de serem distribuídos para as funções do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934).  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Aponta para um [estrutura MSG](../../mfc/reference/msg-structure1.md) que contém a mensagem para processar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi totalmente processada em `PreTranslateMessage` e não devem ser processadas ainda mais. Zero se a mensagem deve ser processada da maneira normal.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é usada somente em threads de interface do usuário.  
  
##  <a name="a-nameprocessmessagefiltera--cwinthreadprocessmessagefilter"></a><a name="processmessagefilter"></a>CWinThread::ProcessMessageFilter  
 Função de gancho do framework chama essa função de membro para filtrar e responder a determinadas mensagens do Windows.  
  
```  
virtual BOOL ProcessMessageFilter(
    int code,  
    LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `code`  
 Especifica um código de gancho. Essa função de membro usa o código para determinar como processar`lpMsg.`  
  
 `lpMsg`  
 Um ponteiro para um Windows [estrutura MSG](../../mfc/reference/msg-structure1.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é processada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma função de gancho processa os eventos antes de serem enviados à mensagem normal do aplicativo de processamento.  
  
 Se você substituir este recurso avançado, certifique-se de chamar a versão da classe base para manter a estrutura de gancho de processamento.  
  
##  <a name="a-nameprocesswndprocexceptiona--cwinthreadprocesswndprocexception"></a><a name="processwndprocexception"></a>CWinThread::ProcessWndProcException  
 O framework chama essa função membro sempre que o manipulador não capturar uma exceção lançada em uma das mensagens do thread ou manipuladores de comandos.  
  
```  
virtual LRESULT ProcessWndProcException(
    CException* e,  
    const MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *e*  
 Aponta para uma exceção não tratada.  
  
 `pMsg`  
 Aponta para um [estrutura MSG](../../mfc/reference/msg-structure1.md) que contém informações sobre a mensagem do windows que causou a estrutura lançar uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 – 1 se um `WM_CREATE` será gerada uma exceção; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Não chame essa função membro diretamente.  
  
 A implementação padrão dessa função de membro trata apenas as exceções geradas das seguintes mensagens:  
  
|Comando|Ação|  
|-------------|------------|  
|`WM_CREATE`|Falhe.|  
|`WM_PAINT`|Validar a janela afetada, impedindo que outra `WM_PAINT` mensagem sendo gerada.|  
  
 Substitua essa função de membro para fornecer tratamento global de suas exceções. Chame a funcionalidade básica somente se você deseja exibir o comportamento padrão.  
  
 Essa função de membro é usada somente em segmentos que têm uma bomba de mensagem.  
  
##  <a name="a-namepumpmessagea--cwinthreadpumpmessage"></a><a name="pumpmessage"></a>CWinThread::PumpMessage  
 Contém o loop de mensagens do thread.  
  
```  
virtual BOOL PumpMessage();
```  
  
### <a name="remarks"></a>Comentários  
 `PumpMessage`contém o loop de mensagens do thread. **PumpMessage** é chamado por `CWinThread` para bomba de mensagens do thread. Você pode chamar `PumpMessage` diretamente para forçar as mensagens sejam processadas, ou você pode substituir `PumpMessage` para alterar seu comportamento padrão.  
  
 Chamando `PumpMessage` diretamente e substituindo o comportamento padrão é recomendada somente para usuários avançados.  
  
##  <a name="a-nameresumethreada--cwinthreadresumethread"></a><a name="resumethread"></a>CWinThread::ResumeThread  
 Chamado para retomar a execução de um thread que foi suspenso pelo [SuspendThread](#suspendthread) função membro, ou em um thread criado com o **CREATE_SUSPENDED** sinalizador.  
  
```  
DWORD ResumeThread();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O thread do anterior suspender contagem se for bem-sucedida; `0xFFFFFFFF` caso contrário. Se o valor de retorno for zero, o thread atual não foi suspensa. Se o valor de retorno é um, o thread foi suspenso, mas agora é reiniciado. Qualquer valor de retorno maior significa que um thread permanece suspenso.  
  
### <a name="remarks"></a>Comentários  
 A contagem de suspensões do thread atual é reduzida por um. Se a contagem de suspensões é reduzida a zero, o segmento continua a execução; Caso contrário, o thread permanece suspenso.  
  
##  <a name="a-nameruna--cwinthreadrun"></a><a name="run"></a>CWinThread::Run  
 Fornece um loop de mensagem padrão para threads de interface do usuário.  
  
```  
virtual int Run();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `int` valor retornado pelo thread. Esse valor pode ser recuperado chamando [GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190).  
  
### <a name="remarks"></a>Comentários  
 **Executar** adquire e envia mensagens do Windows até que o aplicativo recebe um [WM_QUIT](http://msdn.microsoft.com/library/windows/desktop/ms632641) mensagem. Se a fila de mensagens do thread atualmente não contenha mensagens, **executar** chamadas `OnIdle` para executar o processamento de tempo ocioso. Mensagens de entrada acessem o [PreTranslateMessage](#pretranslatemessage) função de membro para processamento especial e, em seguida, a função do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) para a tradução de teclado padrão. Por fim, o [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) é chamada de função do Windows.  
  
 **Executar** raramente é substituído, mas você pode substituí-la para implementar um comportamento especial.  
  
 Essa função de membro é usada somente em threads de interface do usuário.  
  
##  <a name="a-namesetthreadprioritya--cwinthreadsetthreadpriority"></a><a name="setthreadpriority"></a>CWinThread::SetThreadPriority  
 Essa função define o nível de prioridade do thread atual dentro de sua classe de prioridade.  
  
```  
BOOL SetThreadPriority(int nPriority);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPriority`  
 Especifica o novo nível de prioridade de thread dentro de sua classe de prioridade. Esse parâmetro deve ser um dos valores a seguir, listados da prioridade mais alta para a mais baixa:  
  
- **THREAD_PRIORITY_TIME_CRITICAL**  
  
- **THREAD_PRIORITY_HIGHEST**  
  
- **THREAD_PRIORITY_ABOVE_NORMAL**  
  
- **THREAD_PRIORITY_NORMAL**  
  
- **THREAD_PRIORITY_BELOW_NORMAL**  
  
- **THREAD_PRIORITY_LOWEST**  
  
- **THREAD_PRIORITY_IDLE**  
  
 Para obter mais informações sobre essas prioridades, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele só pode ser chamado após [CreateThread](#createthread) retorna com êxito.  
  
##  <a name="a-namesuspendthreada--cwinthreadsuspendthread"></a><a name="suspendthread"></a>CWinThread::SuspendThread  
 Incrementa atual contagem de suspensões do thread.  
  
```  
DWORD SuspendThread();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O thread do anterior suspender contagem se for bem-sucedida; `0xFFFFFFFF` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Se qualquer thread tem uma contagem de suspensões acima de zero, esse thread não é executado. O thread pode ser retomado chamando o [ResumeThread](#resumethread) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

