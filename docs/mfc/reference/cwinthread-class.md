---
title: Classe CWinThread
ms.date: 11/04/2016
f1_keywords:
- CWinThread
- AFXWIN/CWinThread
- AFXWIN/CWinThread::CWinThread
- AFXWIN/CWinThread::CreateThread
- AFXWIN/CWinThread::ExitInstance
- AFXWIN/CWinThread::GetMainWnd
- AFXWIN/CWinThread::GetThreadPriority
- AFXWIN/CWinThread::InitInstance
- AFXWIN/CWinThread::IsIdleMessage
- AFXWIN/CWinThread::OnIdle
- AFXWIN/CWinThread::PostThreadMessage
- AFXWIN/CWinThread::PreTranslateMessage
- AFXWIN/CWinThread::ProcessMessageFilter
- AFXWIN/CWinThread::ProcessWndProcException
- AFXWIN/CWinThread::PumpMessage
- AFXWIN/CWinThread::ResumeThread
- AFXWIN/CWinThread::Run
- AFXWIN/CWinThread::SetThreadPriority
- AFXWIN/CWinThread::SuspendThread
- AFXWIN/CWinThread::m_bAutoDelete
- AFXWIN/CWinThread::m_hThread
- AFXWIN/CWinThread::m_nThreadID
- AFXWIN/CWinThread::m_pActiveWnd
- AFXWIN/CWinThread::m_pMainWnd
helpviewer_keywords:
- CWinThread [MFC], CWinThread
- CWinThread [MFC], CreateThread
- CWinThread [MFC], ExitInstance
- CWinThread [MFC], GetMainWnd
- CWinThread [MFC], GetThreadPriority
- CWinThread [MFC], InitInstance
- CWinThread [MFC], IsIdleMessage
- CWinThread [MFC], OnIdle
- CWinThread [MFC], PostThreadMessage
- CWinThread [MFC], PreTranslateMessage
- CWinThread [MFC], ProcessMessageFilter
- CWinThread [MFC], ProcessWndProcException
- CWinThread [MFC], PumpMessage
- CWinThread [MFC], ResumeThread
- CWinThread [MFC], Run
- CWinThread [MFC], SetThreadPriority
- CWinThread [MFC], SuspendThread
- CWinThread [MFC], m_bAutoDelete
- CWinThread [MFC], m_hThread
- CWinThread [MFC], m_nThreadID
- CWinThread [MFC], m_pActiveWnd
- CWinThread [MFC], m_pMainWnd
ms.assetid: 10cdc294-4057-4e76-ac7c-a8967a89af0b
ms.openlocfilehash: f2e95dd3ba8be31633590e37d95dedc8749ebdd8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367413"
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

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinThread::CreateThread](#createthread)|Começa a `CWinThread` execução de um objeto.|
|[CWinthread::ExitInstance](#exitinstance)|Anular para limpar quando seu fio terminar.|
|[CWinThread::GetMainWnd](#getmainwnd)|Recupera um ponteiro para a janela principal para o fio.|
|[CWinthread::GetThreadPriority](#getthreadpriority)|Obtém a prioridade do segmento atual.|
|[CWinThread::InitInstance](#initinstance)|Substituir para executar a inicialização da instância de segmento.|
|[Cwinthread::IsIdleMessage](#isidlemessage)|Verifica mensagens especiais.|
|[Cwinthread::Onidle](#onidle)|Substituir para executar o processamento de tempo ocioso específico do segmento.|
|[CWinThread::PostThreadMessage](#postthreadmessage)|Posta uma `CWinThread` mensagem para outro objeto.|
|[CWinThread::PreTraduzirmensagem](#pretranslatemessage)|Filtra mensagens antes de serem enviadas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).|
|[CWinThread::ProcessMessageFilter](#processmessagefilter)|Intercepta certas mensagens antes de chegar ao aplicativo.|
|[CWinThread::ProcessWndProcException](#processwndprocexception)|Intercepta todas as exceções não manuseadas lançadas pelos manipuladores de mensagens e comandos do segmento.|
|[CWinThread::PumpMessage](#pumpmessage)|Contém o loop de mensagem do segmento.|
|[CWinThread::Resumethread](#resumethread)|Decreta a contagem de suspensão de um fio.|
|[CWinThread::Execução](#run)|Função de controle para roscas com uma bomba de mensagem. Substituir para personalizar o loop de mensagem padrão.|
|[CWinthread::SetThreadPriority](#setthreadpriority)|Define a prioridade do segmento atual.|
|[CWinThread::Suspender thread](#suspendthread)|Incrementa a contagem de suspensão de um fio.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinThread::manipulação do operador](#operator_handle)|Recupera a alça `CWinThread` do objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinThread::m_bAutoDelete](#m_bautodelete)|Especifica se deve destruir o objeto no término do segmento.|
|[CWinThread::m_hThread](#m_hthread)|Manuseie o fio atual.|
|[CWinThread::m_nThreadID](#m_nthreadid)|ID do segmento atual.|
|[CWinThread::m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo de contêiner quando um servidor OLE estiver ativo no local.|
|[CWinThread::m_pMainWnd](#m_pmainwnd)|Segura um ponteiro na janela principal do aplicativo.|

## <a name="remarks"></a>Comentários

O segmento principal de execução é geralmente `CWinApp`fornecido por um objeto derivado; `CWinApp` é derivado `CWinThread`de . Objetos adicionais `CWinThread` permitem vários segmentos dentro de um determinado aplicativo.

Existem dois tipos gerais `CWinThread` de threads que suportam: threads de trabalhador e threads de interface de usuário. Os segmentos do trabalhador não têm bomba de mensagem: por exemplo, um segmento que executa cálculos de fundo em um aplicativo de planilha. Os segmentos de interface do usuário têm uma bomba de mensagens e mensagens de processo recebidas do sistema. [CWinApp](../../mfc/reference/cwinapp-class.md) e classes derivadas dele são exemplos de threads de interface de usuário. Outros segmentos de interface de usuário `CWinThread`também podem ser derivados diretamente de .

Objetos `CWinThread` de classe normalmente existem durante a duração do segmento. Se desejar modificar esse comportamento, defina [m_bAutoDelete](#m_bautodelete) como FALSO.

A `CWinThread` classe é necessária para tornar seu código e MFC totalmente seguros. Os dados locais de thread usados pela estrutura para `CWinThread` manter informações específicas do segmento são gerenciados por objetos. Devido `CWinThread` a essa dependência de lidar com dados locais de thread, qualquer segmento que use MFC deve ser criado por MFC. Por exemplo, um segmento criado pela função de tempo de execução [_beginthread, _beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) não pode usar nenhuma APIs MFC.

Para criar um segmento, chame [AfxBeginThread](application-information-and-management.md#afxbeginthread). Existem dois formulários, dependendo se você quer um segmento de interface de usuário ou trabalhador. Se você quiser um segmento de `AfxBeginThread` interface de `CRuntimeClass` usuário, passe para um ponteiro para a classe derivada de sua. `CWinThread` Se você quiser criar um segmento `AfxBeginThread` de trabalhador, passe para um ponteiro para a função de controle e o parâmetro para a função de controle. Para os threads do trabalhador e os segmentos de interface do usuário, você pode especificar parâmetros opcionais que modificam prioridade, tamanho da pilha, sinalizadores de criação e atributos de segurança. `AfxBeginThread`retornará um ponteiro `CWinThread` ao seu novo objeto.

Em vez `AfxBeginThread`de chamar, `CWinThread`você pode construir `CreateThread`um objeto derivado e, em seguida, chamar . Este método de construção em duas etapas `CWinThread` é útil se você quiser reutilizar o objeto entre criação sucessiva e terminações de execuções de segmentos.

Para obter `CWinThread`mais informações sobre , consulte os artigos [Multithreading com C++ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md), [Multithreading: Criando Threads user-interface,](../../parallel/multithreading-creating-user-interface-threads.md) [Multithreading: Criando Threads worker](../../parallel/multithreading-creating-worker-threads.md)e [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CWinThread`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cwinthreadcreatethread"></a><a name="createthread"></a>CWinThread::CreateThread

Cria um segmento para executar dentro do espaço de endereço do processo de chamada.

```
BOOL CreateThread(
    DWORD dwCreateFlags = 0,
    UINT nStackSize = 0,
    LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwCreateFlags*<br/>
Especifica uma bandeira adicional que controla a criação do segmento. Esta bandeira pode conter um dos dois valores:

- CREATE_SUSPENDED Inicie a linha com uma contagem de suspensão de um. Use CREATE_SUSPENDED se quiser inicializar quaisquer `CWinThread` dados membros do objeto, como [m_bAutoDelete](#m_bautodelete) ou quaisquer membros da sua classe derivada, antes que o segmento comece a ser executado. Uma vez que sua inicialização esteja concluída, use o [CWinThread::ResumeThread](#resumethread) para iniciar a execução do segmento. O segmento não `CWinThread::ResumeThread` será executado até que seja chamado.

- **0** Inicie o segmento imediatamente após a criação.

*nStackSize*<br/>
Especifica o tamanho em bytes da pilha para o novo segmento. Se **0**, o tamanho da pilha é padrão para o mesmo tamanho do segmento principal do processo.

*lpSecurityAttrs*<br/>
Aponta para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica os atributos de segurança para o segmento.

### <a name="return-value"></a>Valor retornado

Não zero se o segmento for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `AfxBeginThread` para criar um objeto de rosca e executá-lo em uma etapa. Use `CreateThread` se quiser reutilizar o objeto de rosca entre a criação sucessiva e o término das execuções de segmentos.

## <a name="cwinthreadcwinthread"></a><a name="cwinthread"></a>CWinThread::CWinThread

Constrói um objeto `CWinThread`.

```
CWinThread();
```

### <a name="remarks"></a>Comentários

Para iniciar a execução do segmento, chame a função de membro [CreateThread.](#createthread) Você geralmente criará threads chamando [AfxBeginThread](application-information-and-management.md#afxbeginthread), `CreateThread`que chamará este construtor e .

## <a name="cwinthreadexitinstance"></a><a name="exitinstance"></a>CWinthread::ExitInstance

Chamado pela estrutura de dentro de uma função de membro [run](#run) raramente substituída para sair desta instância do segmento, ou se uma chamada para [InitInstance](#initinstance) falhar.

```
virtual int ExitInstance();
```

### <a name="return-value"></a>Valor retornado

O código de saída do segmento; 0 indica nenhum erro, e valores maiores que 0 indicam um erro. Esse valor pode ser recuperado chamando [GetExitCodeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread).

### <a name="remarks"></a>Comentários

Não chame esta função de membro `Run` de qualquer lugar, mas dentro da função membro. Esta função de membro é usada apenas em threads de interface de usuário.

A implementação padrão desta `CWinThread` função exclui o objeto se [m_bAutoDelete](#m_bautodelete) for TRUE. Anular esta função se desejar realizar uma limpeza adicional quando o segmento terminar. Sua implementação `ExitInstance` deve chamar a versão da classe base depois que seu código for executado.

## <a name="cwinthreadgetmainwnd"></a><a name="getmainwnd"></a>CWinThread::GetMainWnd

Se o aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para `m_pMainWnd` a janela principal ativa do aplicativo, em vez de se referir diretamente ao membro do objeto do aplicativo.

```
virtual CWnd* GetMainWnd();
```

### <a name="return-value"></a>Valor retornado

Esta função retorna um ponteiro para um dos dois tipos de janelas. Se o segmento fizer parte de um servidor OLE e tiver um objeto ativo no local dentro de um `CWinThread` contêiner ativo, essa função reacircunda o membro de dados [CWinApp::m_pActiveWnd](../../mfc/reference/cwinapp-class.md#m_pactivewnd) do objeto.

Se não houver nenhum objeto ativo no local dentro de um contêiner ou seu aplicativo não for um servidor OLE, esta função reah/ [m_pMainWnd](#m_pmainwnd) membro de dados do objeto thread.

### <a name="remarks"></a>Comentários

Para threads de interface de usuário, isso `m_pActiveWnd` equivale a se referir diretamente ao membro do objeto do aplicativo.

Se o seu aplicativo não for um servidor OLE, então `m_pMainWnd` chamar essa função é equivalente a se referir diretamente ao membro do objeto do aplicativo.

Anular essa função para modificar o comportamento padrão.

## <a name="cwinthreadgetthreadpriority"></a><a name="getthreadpriority"></a>CWinthread::GetThreadPriority

Obtém o nível de prioridade de segmento atual deste segmento.

```
int GetThreadPriority();
```

### <a name="return-value"></a>Valor retornado

O nível de prioridade atual do segmento dentro de sua classe prioritária. O valor devolvido será um dos seguintes, listado da maior prioridade para o menor:

- THREAD_PRIORITY_TIME_CRITICAL

- Thread_priority_highest

- THREAD_PRIORITY_ABOVE_NORMAL

- THREAD_PRIORITY_NORMAL

- THREAD_PRIORITY_BELOW_NORMAL

- THREAD_PRIORITY_LOWEST

- THREAD_PRIORITY_IDLE

Para obter mais informações sobre essas prioridades, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no Windows SDK.

## <a name="cwinthreadinitinstance"></a><a name="initinstance"></a>CWinThread::InitInstance

`InitInstance`deve ser substituído para inicializar cada nova instância de um segmento de interface de usuário.

```
virtual BOOL InitInstance();
```

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Normalmente, você `InitInstance` se sobreporá para executar tarefas que devem ser concluídas quando um segmento é criado pela primeira vez.

Esta função de membro é usada apenas em threads de interface de usuário. Executar a inicialização dos threads do trabalhador na função de controle passada para [AfxBeginThread](application-information-and-management.md#afxbeginthread).

## <a name="cwinthreadisidlemessage"></a><a name="isidlemessage"></a>Cwinthread::IsIdleMessage

Anular essa função `OnIdle` para evitar ser chamada depois que mensagens específicas forem geradas.

```
virtual BOOL IsIdleMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Aponta para a mensagem atual que está sendo processada.

### <a name="return-value"></a>Valor retornado

Não zero `OnIdle` se deve ser chamado após o processamento da mensagem; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão `OnIdle` não é chamada após mensagens e mensagens de mouse redundantes geradas por caretas piscando.

Se um aplicativo criou um temporizador curto, `OnIdle` será chamado com freqüência, causando problemas de desempenho. Para melhorar o desempenho de um `IsIdleMessage` aplicativo, anule-se na classe derivada do `CWinApp`aplicativo para verificar se há mensagens WM_TIMER da seguinte forma:

[!code-cpp[NVC_MFCDocView#189](../../mfc/codesnippet/cpp/cwinthread-class_1.cpp)]

O manuseio WM_TIMER desta forma melhorará o desempenho de aplicações que usam temporizadores curtos.

## <a name="cwinthreadm_bautodelete"></a><a name="m_bautodelete"></a>CWinThread::m_bAutoDelete

Especifica se `CWinThread` o objeto deve ser excluído automaticamente no término do segmento.

```
BOOL m_bAutoDelete;
```

### <a name="remarks"></a>Comentários

O `m_bAutoDelete` membro de dados é uma variável pública do tipo BOOL.

O valor `m_bAutoDelete` de não afeta a forma como a alça de rosca subjacente está fechada, mas afeta o tempo de fechamento da alça. A alça da rosca `CWinThread` está sempre fechada quando o objeto é destruído.

## <a name="cwinthreadm_hthread"></a><a name="m_hthread"></a>CWinThread::m_hThread

Manuseie o fio `CWinThread`ligado a isso .

```
HANDLE m_hThread;
```

### <a name="remarks"></a>Comentários

O `m_hThread` membro de dados é uma variável pública do tipo HANDLE. Ele só é válido se o objeto de segmento do kernel subjacente existir atualmente, e a alça ainda não foi fechada.

O destructor CWinThread chama `m_hThread`CloseHandle on . Se [m_bAutoDelete](#m_bautodelete) for TRUE quando o segmento for encerrado, o objeto CWinThread será destruído, o que invalida quaisquer ponteiros para o objeto CWinThread e suas variáveis de membro. Você pode `m_hThread` precisar que o membro verifique o valor de saída do segmento ou aguarde um sinal. Para manter o objeto CWinThread e seu `m_hThread` membro durante `m_bAutoDelete` a execução do segmento e depois que ele terminar, defina-o como FALSE antes de permitir que a execução do segmento continue. Caso contrário, o segmento pode terminar, destruir o objeto CWinThread e fechar a alça antes de tentar usá-lo. Se você usar essa técnica, você será responsável pela exclusão do objeto CWinThread.

## <a name="cwinthreadm_nthreadid"></a><a name="m_nthreadid"></a>CWinThread::m_nThreadID

ID do fio anexado `CWinThread`a isso .

```
DWORD m_nThreadID;
```

### <a name="remarks"></a>Comentários

O `m_nThreadID` membro de dados é uma variável pública do tipo DWORD. Ele só é válido se o objeto de segmento do kernel subjacente existir atualmente.
Veja também comentários sobre [m_hThread](#m_hthread) vida.

### <a name="example"></a>Exemplo

  Veja o exemplo [de AfxGetThread](application-information-and-management.md#afxgetthread).

## <a name="cwinthreadm_pactivewnd"></a><a name="m_pactivewnd"></a>CWinThread::m_pActiveWnd

Use este membro de dados para armazenar um ponteiro no objeto de janela ativa do segmento.

```
CWnd* m_pActiveWnd;
```

### <a name="remarks"></a>Comentários

A Biblioteca de Classes da Microsoft Foundation encerrará `m_pActiveWnd` automaticamente seu segmento quando a janela referida for fechada. Se este segmento for o segmento principal de uma aplicação, o aplicativo também será encerrado. Se esse membro de dados for NULO, `CWinApp` a janela ativa para o objeto do aplicativo será herdada. `m_pActiveWnd`é uma variável `CWnd*`pública do tipo.

Normalmente, você define essa variável `InitInstance`de membro quando você sobrepor . Em um segmento de trabalhador, o valor desse membro de dados é herdado de seu segmento pai.

## <a name="cwinthreadm_pmainwnd"></a><a name="m_pmainwnd"></a>CWinThread::m_pMainWnd

Use este membro de dados para armazenar um ponteiro no objeto da janela principal do seu segmento.

```
CWnd* m_pMainWnd;
```

### <a name="remarks"></a>Comentários

A Biblioteca de Classes da Microsoft Foundation encerrará `m_pMainWnd` automaticamente seu segmento quando a janela referida for fechada. Se este segmento for o segmento principal de uma aplicação, o aplicativo também será encerrado. Se esse membro de dados for NULL, `CWinApp` a janela principal para o objeto do aplicativo será usada para determinar quando encerrar o segmento. `m_pMainWnd`é uma variável `CWnd*`pública do tipo.

Normalmente, você define essa variável `InitInstance`de membro quando você sobrepor . Em um segmento de trabalhador, o valor desse membro de dados é herdado de seu segmento pai.

## <a name="cwinthreadonidle"></a><a name="onidle"></a>Cwinthread::Onidle

Substituir essa função de membro para executar o processamento de tempo ocioso.

```
virtual BOOL OnIdle(LONG lCount);
```

### <a name="parameters"></a>Parâmetros

*Lcount*<br/>
Um contador incrementado cada vez `OnIdle` é chamado quando a fila de mensagens do segmento está vazia. Esta contagem é redefinida para 0 cada vez que uma nova mensagem é processada. Você pode usar o parâmetro *lCount* para determinar o tempo relativo que o segmento ficou ocioso sem processar uma mensagem.

### <a name="return-value"></a>Valor retornado

Não zero para receber mais tempo de processamento ocioso; 0 se não for necessário mais tempo de processamento ocioso.

### <a name="remarks"></a>Comentários

`OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do segmento está vazia. Use sua substituição para chamar suas próprias tarefas de manipulador ocioso de fundo.

`OnIdle`deve retornar 0 para indicar que não é necessário tempo adicional de processamento ocioso. O parâmetro *iCount* é incrementado cada vez `OnIdle` que é chamado quando a fila de mensagens está vazia e é redefinido para 0 cada vez que uma nova mensagem é processada. Você pode chamar suas diferentes rotinas ociosas com base nesta contagem.

A implementação padrão desta função membro libera objetos temporários e bibliotecas de links dinâmicos não utilizadas da memória.

Esta função de membro é usada apenas em threads de interface de usuário.

Como o aplicativo não `OnIdle` pode processar mensagens até o retorno, não execute tarefas longas nesta função.

## <a name="cwinthreadoperator-handle"></a><a name="operator_handle"></a>CWinThread::manipulação do operador

Recupera a alça `CWinThread` do objeto.

```
operator HANDLE() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, a alça do objeto de rosca; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use a alça para chamar diretamente as APIs do Windows.

## <a name="cwinthreadpostthreadmessage"></a><a name="postthreadmessage"></a>CWinThread::PostThreadMessage

Chamado para postar uma mensagem `CWinThread` definida pelo usuário para outro objeto.

```
BOOL PostThreadMessage(
    UINT message,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
ID da mensagem definida pelo usuário.

*wParam*<br/>
Primeiro parâmetro de mensagem.

*lParam*<br/>
Segundo parâmetro de mensagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A mensagem postada é mapeada para o manipulador de mensagens adequado pela macro mapa de mensagens ON_THREAD_MESSAGE.

> [!NOTE]
> Quando você chama [PostThreadMessage](/windows/win32/api/winuser/nf-winuser-postthreadmessagew), a mensagem é colocada na fila de mensagens do segmento. No entanto, como as mensagens postadas dessa forma não estão associadas a uma janela, o MFC não as enviará para manipuladores de mensagens ou comandos. Para lidar com essas mensagens, `PreTranslateMessage()` anule a função da sua classe derivada do CWinApp e manuseie as mensagens manualmente.

## <a name="cwinthreadpretranslatemessage"></a><a name="pretranslatemessage"></a>CWinThread::PreTraduzirmensagem

Anular esta função para filtrar mensagens de janela antes de serem enviadas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Aponta para uma [estrutura MSG](/windows/win32/api/winuser/ns-winuser-msg) contendo a mensagem a ser processada.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem `PreTranslateMessage` foi totalmente processada e não deve ser processada mais adiante. Zero se a mensagem deve ser processada da maneira normal.

### <a name="remarks"></a>Comentários

Esta função de membro é usada apenas em threads de interface de usuário.

## <a name="cwinthreadprocessmessagefilter"></a><a name="processmessagefilter"></a>CWinThread::ProcessMessageFilter

A função de gancho da estrutura chama essa função de membro para filtrar e responder a certas mensagens do Windows.

```
virtual BOOL ProcessMessageFilter(
    int code,
    LPMSG lpMsg);
```

### <a name="parameters"></a>Parâmetros

*Código*<br/>
Especifica um código de gancho. Esta função membro usa o código para determinar como processar *lpMsg.*

*Lpmsg*<br/>
Um ponteiro para uma [estrutura MSG do](/windows/win32/api/winuser/ns-winuser-msg)Windows .

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem for processada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma função de gancho processa eventos antes de serem enviados para o processamento normal de mensagens do aplicativo.

Se você substituir esse recurso avançado, certifique-se de chamar a versão de classe base para manter o processamento de ganchos da estrutura.

## <a name="cwinthreadprocesswndprocexception"></a><a name="processwndprocexception"></a>CWinThread::ProcessWndProcException

A estrutura chama essa função de membro sempre que o manipulador não captura uma exceção lançada em uma das mensagens ou manipuladores de comando do seu segmento.

```
virtual LRESULT ProcessWndProcException(
    CException* e,
    const MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*e*<br/>
Aponta para uma exceção não tratada.

*pMsg*<br/>
Aponta para uma [estrutura MSG](/windows/win32/api/winuser/ns-winuser-msg) contendo informações sobre a mensagem do windows que fez com que a estrutura lançasse uma exceção.

### <a name="return-value"></a>Valor retornado

-1 se for gerada uma exceção WM_CREATE; caso contrário, 0.

### <a name="remarks"></a>Comentários

Não chame essa função de membro diretamente.

A implementação padrão desta função membro lida apenas com exceções geradas a partir das seguintes mensagens:

|Comando|Ação|
|-------------|------------|
|Wm_create|Falha.|
|Wm_paint|Valide a janela afetada, evitando assim que outra mensagem WM_PAINT seja gerada.|

Anular essa função de membro para fornecer o manuseio global de suas exceções. Chame a funcionalidade base somente se desejar exibir o comportamento padrão.

Esta função de membro é usada apenas em threads que têm uma bomba de mensagem.

## <a name="cwinthreadpumpmessage"></a><a name="pumpmessage"></a>CWinThread::PumpMessage

Contém o loop de mensagem do segmento.

```
virtual BOOL PumpMessage();
```

### <a name="remarks"></a>Comentários

`PumpMessage`contém o loop de mensagem do segmento. `PumpMessage`é chamado `CWinThread` para bombear as mensagens do segmento. Você pode `PumpMessage` ligar diretamente para forçar o processamento de `PumpMessage` mensagens ou pode substituir para alterar seu comportamento padrão.

Chamar `PumpMessage` diretamente e sobrepor seu comportamento padrão é recomendado apenas para usuários avançados.

## <a name="cwinthreadresumethread"></a><a name="resumethread"></a>CWinThread::Resumethread

Chamado para retomar a execução de um segmento que foi suspenso pela função de membro [SuspendThread,](#suspendthread) ou um segmento criado com a bandeira CREATE_SUSPENDED.

```
DWORD ResumeThread();
```

### <a name="return-value"></a>Valor retornado

A contagem anterior de suspensão do segmento se for bem sucedida; `0xFFFFFFFF` caso contrário. Se o valor de retorno for zero, o segmento atual não foi suspenso. Se o valor de retorno for um, o segmento foi suspenso, mas agora é reiniciado. Qualquer valor de retorno maior que um significa que o segmento permanece suspenso.

### <a name="remarks"></a>Comentários

A contagem de suspensão do segmento atual é reduzida por um. Se a contagem de suspensão for reduzida a zero, a linha retomará a execução; caso contrário, o fio permanece suspenso.

## <a name="cwinthreadrun"></a><a name="run"></a>CWinThread::Execução

Fornece um loop de mensagem padrão para segmentos de interface de usuário.

```
virtual int Run();
```

### <a name="return-value"></a>Valor retornado

Um valor **int** que é devolvido pelo segmento. Esse valor pode ser recuperado chamando [GetExitCodeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread).

### <a name="remarks"></a>Comentários

`Run`adquire e despacha mensagens do Windows até que o aplicativo receba uma [mensagem WM_QUIT.](/windows/win32/winmsg/wm-quit) Se a fila de mensagens do segmento `Run` não `OnIdle` contiver mensagens, não será realizado processamento de tempo ocioso. As mensagens recebidas vão para a função de membro [PreTranslateMessage](#pretranslatemessage) para processamento especial e, em seguida, para a função do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) para tradução padrão do teclado. Finalmente, a função [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows é chamada.

`Run`raramente é substituído, mas você pode substituí-lo para implementar comportamento especial.

Esta função de membro é usada apenas em threads de interface de usuário.

## <a name="cwinthreadsetthreadpriority"></a><a name="setthreadpriority"></a>CWinthread::SetThreadPriority

Esta função define o nível de prioridade do segmento atual dentro de sua classe prioritária.

```
BOOL SetThreadPriority(int nPriority);
```

### <a name="parameters"></a>Parâmetros

*nPrioridade*<br/>
Especifica o novo nível de prioridade do segmento dentro de sua classe prioritária. Este parâmetro deve ser um dos seguintes valores, listado da maior prioridade para o mais baixo:

- THREAD_PRIORITY_TIME_CRITICAL

- Thread_priority_highest

- THREAD_PRIORITY_ABOVE_NORMAL

- THREAD_PRIORITY_NORMAL

- THREAD_PRIORITY_BELOW_NORMAL

- THREAD_PRIORITY_LOWEST

- THREAD_PRIORITY_IDLE

Para obter mais informações sobre essas prioridades, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele só pode ser chamado após o retorno do [CreateThread](#createthread) com sucesso.

## <a name="cwinthreadsuspendthread"></a><a name="suspendthread"></a>CWinThread::Suspender thread

Incrementa a contagem de suspensão do segmento atual.

```
DWORD SuspendThread();
```

### <a name="return-value"></a>Valor retornado

A contagem anterior de suspensão do segmento se for bem sucedida; `0xFFFFFFFF` caso contrário.

### <a name="remarks"></a>Comentários

Se qualquer segmento tiver uma contagem de suspensão acima de zero, esse segmento não será executado. O segmento pode ser retomado chamando a função de membro [ResumeThread.](#resumethread)

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
