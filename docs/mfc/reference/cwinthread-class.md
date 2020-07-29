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
ms.openlocfilehash: 6dbe4c4d3ed5edaf0563abf589cd844cca6803f0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182766"
---
# <a name="cwinthread-class"></a>Classe CWinThread

Representa um thread de execução dentro de um aplicativo.

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
|[CWinThread:: CreateThread](#createthread)|Inicia a execução de um `CWinThread` objeto.|
|[CWinThread:: ExitInstance](#exitinstance)|Substitua para limpar quando seu thread for encerrado.|
|[CWinThread::GetMainWnd](#getmainwnd)|Recupera um ponteiro para a janela principal do thread.|
|[CWinThread::GetThreadPriority](#getthreadpriority)|Obtém a prioridade do thread atual.|
|[CWinThread:: InitInstance](#initinstance)|Substitua para executar a inicialização da instância de thread.|
|[CWinThread::IsIdleMessage](#isidlemessage)|Verifica se há mensagens especiais.|
|[CWinThread:: OnIdle](#onidle)|Substitua para executar o processamento de tempo ocioso específico do thread.|
|[CWinThread::P ostThreadMessage](#postthreadmessage)|Posta uma mensagem em outro `CWinThread` objeto.|
|[CWinThread::P reTranslateMessage](#pretranslatemessage)|Filtra mensagens antes que elas sejam expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).|
|[CWinThread::P rocessMessageFilter](#processmessagefilter)|Intercepta determinadas mensagens antes que elas cheguem ao aplicativo.|
|[CWinThread::P rocessWndProcException](#processwndprocexception)|Intercepta todas as exceções sem tratamento lançadas pelos manipuladores de mensagem e comando do thread.|
|[CWinThread::P umpMessage](#pumpmessage)|Contém o loop de mensagem do thread.|
|[CWinThread::ResumeThread](#resumethread)|Decrementa a contagem de suspensões de um thread.|
|[CWinThread:: Run](#run)|Controlando a função para threads com uma bomba de mensagem. Substitua para personalizar o loop de mensagem padrão.|
|[CWinThread::SetThreadPriority](#setthreadpriority)|Define a prioridade do thread atual.|
|[CWinThread::SuspendThread](#suspendthread)|Incrementa a contagem de suspensões de um thread.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[IDENTIFICADOR de CWinThread:: Operator](#operator_handle)|Recupera o identificador do `CWinThread` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinThread:: m_bAutoDelete](#m_bautodelete)|Especifica se deve-se destruir o objeto na terminação de thread.|
|[CWinThread:: m_hThread](#m_hthread)|Identificador para o thread atual.|
|[CWinThread:: m_nThreadID](#m_nthreadid)|ID do thread atual.|
|[CWinThread:: m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo de contêiner quando um servidor OLE está ativo no local.|
|[CWinThread:: m_pMainWnd](#m_pmainwnd)|Mantém um ponteiro para a janela principal do aplicativo.|

## <a name="remarks"></a>Comentários

O thread principal de execução geralmente é fornecido por um objeto derivado de `CWinApp` ; `CWinApp` é derivado de `CWinThread` . `CWinThread`Objetos adicionais permitem vários threads em um determinado aplicativo.

Há dois tipos gerais de threads que `CWinThread` dão suporte a: threads de trabalho e threads de interface do usuário. Os threads de trabalho não têm bombeamento de mensagem: por exemplo, um thread que executa cálculos em segundo plano em um aplicativo de planilha. Os threads de interface do usuário têm uma bomba de mensagem e processam mensagens recebidas do sistema. [CWinApp](../../mfc/reference/cwinapp-class.md) e classes derivadas dele são exemplos de threads de interface do usuário. Outros threads de interface do usuário também podem ser derivados diretamente do `CWinThread` .

Os objetos da classe `CWinThread` normalmente existem para a duração do thread. Se você quiser modificar esse comportamento, defina [m_bAutoDelete](#m_bautodelete) como false.

A `CWinThread` classe é necessária para tornar seu código e o MFC totalmente seguros. Os dados locais de thread usados pelo Framework para manter informações específicas de thread são gerenciados por `CWinThread` objetos. Por causa dessa dependência `CWinThread` para lidar com dados locais de thread, qualquer thread que usa MFC deve ser criado pelo MFC. Por exemplo, um thread criado pela função de tempo de execução [_beginthread, _beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) não pode usar nenhuma API MFC.

Para criar um thread, chame [AfxBeginThread](application-information-and-management.md#afxbeginthread). Há dois formulários, dependendo se você deseja um thread de trabalho ou de interface do usuário. Se você quiser um thread de interface do usuário, passe para `AfxBeginThread` um ponteiro para a `CRuntimeClass` de sua `CWinThread` classe derivada. Se você quiser criar um thread de trabalho, passe para `AfxBeginThread` um ponteiro para a função de controle e o parâmetro para a função de controle. Para threads de trabalho e threads de interface do usuário, você pode especificar parâmetros opcionais que modificam a prioridade, o tamanho da pilha, os sinalizadores de criação e os atributos de segurança. `AfxBeginThread`retornará um ponteiro para o novo `CWinThread` objeto.

Em vez de chamar `AfxBeginThread` , você pode construir um `CWinThread` objeto derivado e, em seguida, chamar `CreateThread` . Esse método de construção de dois estágios será útil se você quiser reutilizar o `CWinThread` objeto entre a criação e os encerramentos sucessivos de execuções de thread.

Para obter mais informações sobre `CWinThread` o, consulte os artigos [multithreading com C++ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md), [multithreading: criando threads de interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md), [multithreading: criando threads de trabalho](../../parallel/multithreading-creating-worker-threads.md)e [multithreading: como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CWinThread`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="cwinthreadcreatethread"></a><a name="createthread"></a>CWinThread:: CreateThread

Cria um thread para executar dentro do espaço de endereço do processo de chamada.

```
BOOL CreateThread(
    DWORD dwCreateFlags = 0,
    UINT nStackSize = 0,
    LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
```

### <a name="parameters"></a>parâmetros

*dwCreateFlags*<br/>
Especifica um sinalizador adicional que controla a criação do thread. Esse sinalizador pode conter um dos dois valores:

- CREATE_SUSPENDED iniciar o thread com uma contagem de suspensão de um. Use CREATE_SUSPENDED se você quiser inicializar qualquer dado de membro do `CWinThread` objeto, como [m_bAutoDelete](#m_bautodelete) ou qualquer membro da classe derivada, antes de o thread começar a ser executado. Quando a inicialização for concluída, use [CWinThread:: ResumeThread](#resumethread) para iniciar o thread em execução. O thread não será executado até que `CWinThread::ResumeThread` seja chamado.

- **0** inicie o thread imediatamente após a criação.

*nStackSize*<br/>
Especifica o tamanho em bytes da pilha para o novo thread. Se for **0**, o tamanho da pilha será padronizado para o mesmo tamanho do thread principal do processo.

*lpSecurityAttrs*<br/>
Aponta para uma estrutura de [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica os atributos de segurança para o thread.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o thread for criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `AfxBeginThread` para criar um objeto de thread e executá-lo em uma única etapa. Use `CreateThread` se você quiser reutilizar o objeto de thread entre a criação sucessiva e o encerramento de execuções de thread.

## <a name="cwinthreadcwinthread"></a><a name="cwinthread"></a>CWinThread::CWinThread

Constrói um objeto `CWinThread`.

```
CWinThread();
```

### <a name="remarks"></a>Comentários

Para iniciar a execução do thread, chame a função de membro [CreateThread](#createthread) . Normalmente, você criará threads chamando [AfxBeginThread](application-information-and-management.md#afxbeginthread), que chamará esse construtor e `CreateThread` .

## <a name="cwinthreadexitinstance"></a><a name="exitinstance"></a>CWinThread:: ExitInstance

Chamado pelo Framework de dentro de uma função de membro [Run](#run) raramente substituída para sair dessa instância do thread, ou se uma chamada para [InitInstance](#initinstance) falhar.

```
virtual int ExitInstance();
```

### <a name="return-value"></a>Valor retornado

O código de saída do thread; 0 indica que não há erros e valores maiores que 0 indicam um erro. Esse valor pode ser recuperado chamando [GetExitCodeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread).

### <a name="remarks"></a>Comentários

Não chame essa função de membro de qualquer lugar, mas dentro da `Run` função de membro. Essa função de membro é usada somente em threads de interface do usuário.

A implementação padrão dessa função excluirá o `CWinThread` objeto se [M_BAUTODELETE](#m_bautodelete) for true. Substitua essa função se desejar executar uma limpeza adicional quando seu thread for encerrado. Sua implementação do `ExitInstance` deve chamar a versão da classe base depois que o código é executado.

## <a name="cwinthreadgetmainwnd"></a><a name="getmainwnd"></a>CWinThread::GetMainWnd

Se seu aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo em vez de fazer referência direta ao `m_pMainWnd` membro do objeto de aplicativo.

```
virtual CWnd* GetMainWnd();
```

### <a name="return-value"></a>Valor retornado

Essa função retorna um ponteiro para um dos dois tipos de janelas. Se o thread fizer parte de um servidor OLE e tiver um objeto ativo no local dentro de um contêiner ativo, essa função retornará o membro de dados [CWinApp:: m_pActiveWnd](../../mfc/reference/cwinapp-class.md#m_pactivewnd) do `CWinThread` objeto.

Se não houver nenhum objeto ativo no local dentro de um contêiner ou seu aplicativo não for um servidor OLE, essa função retornará o [m_pMainWnd](#m_pmainwnd) membro de dados do seu objeto de thread.

### <a name="remarks"></a>Comentários

Para threads de interface do usuário, isso é equivalente a fazer referência direta ao `m_pActiveWnd` membro do seu objeto de aplicativo.

Se o seu aplicativo não for um servidor OLE, chamar essa função será equivalente a referir-se diretamente ao `m_pMainWnd` membro do seu objeto de aplicativo.

Substitua essa função para modificar o comportamento padrão.

## <a name="cwinthreadgetthreadpriority"></a><a name="getthreadpriority"></a>CWinThread::GetThreadPriority

Obtém o nível de prioridade do thread atual deste thread.

```
int GetThreadPriority();
```

### <a name="return-value"></a>Valor retornado

O nível de prioridade de thread atual dentro de sua classe de prioridade. O valor retornado será um dos seguintes, listados da prioridade mais alta para a mais baixa:

- THREAD_PRIORITY_TIME_CRITICAL

- THREAD_PRIORITY_HIGHEST

- THREAD_PRIORITY_ABOVE_NORMAL

- THREAD_PRIORITY_NORMAL

- THREAD_PRIORITY_BELOW_NORMAL

- THREAD_PRIORITY_LOWEST

- THREAD_PRIORITY_IDLE

Para obter mais informações sobre essas prioridades, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

## <a name="cwinthreadinitinstance"></a><a name="initinstance"></a>CWinThread:: InitInstance

`InitInstance`deve ser substituído para inicializar cada nova instância de um thread de interface do usuário.

```
virtual BOOL InitInstance();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a inicialização for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Normalmente, você substitui `InitInstance` o para executar tarefas que devem ser concluídas quando um thread é criado pela primeira vez.

Essa função de membro é usada somente em threads de interface do usuário. Execute a inicialização de threads de trabalho na função de controle passada para [AfxBeginThread](application-information-and-management.md#afxbeginthread).

## <a name="cwinthreadisidlemessage"></a><a name="isidlemessage"></a>CWinThread::IsIdleMessage

Substitua essa função para manter `OnIdle` de ser chamada depois que mensagens específicas forem geradas.

```
virtual BOOL IsIdleMessage(MSG* pMsg);
```

### <a name="parameters"></a>parâmetros

*pMsg*<br/>
Aponta para a mensagem atual que está sendo processada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se `OnIdle` deve ser chamado após o processamento da mensagem; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não é chamada `OnIdle` após mensagens de mouse redundantes e mensagens geradas por interpolações intermitentes.

Se um aplicativo tiver criado um temporizador curto, `OnIdle` será chamado com frequência, causando problemas de desempenho. Para melhorar o desempenho de um aplicativo, substitua `IsIdleMessage` na `CWinApp` classe derivada do aplicativo para verificar WM_TIMER mensagens da seguinte maneira:

[!code-cpp[NVC_MFCDocView#189](../../mfc/codesnippet/cpp/cwinthread-class_1.cpp)]

Lidar com WM_TIMER dessa maneira melhorará o desempenho dos aplicativos que usam temporizadores curtos.

## <a name="cwinthreadm_bautodelete"></a><a name="m_bautodelete"></a>CWinThread:: m_bAutoDelete

Especifica se o `CWinThread` objeto deve ser excluído automaticamente na terminação de thread.

```
BOOL m_bAutoDelete;
```

### <a name="remarks"></a>Comentários

O `m_bAutoDelete` membro de dados é uma variável pública do tipo bool.

O valor de `m_bAutoDelete` não afeta a forma como o identificador de thread subjacente é fechado, mas afeta o tempo de fechamento do identificador. O identificador de thread sempre é fechado quando o `CWinThread` objeto é destruído.

## <a name="cwinthreadm_hthread"></a><a name="m_hthread"></a>CWinThread:: m_hThread

Identificador para o thread anexado a este `CWinThread` .

```
HANDLE m_hThread;
```

### <a name="remarks"></a>Comentários

O `m_hThread` membro de dados é uma variável pública do identificador de tipo. Ele só será válido se o objeto de thread do kernel subjacente existir atualmente e o identificador ainda não tiver sido fechado.

O destruidor CWinThread chama CloseHandle em `m_hThread` . Se [m_bAutoDelete](#m_bautodelete) for true quando o thread for encerrado, o objeto CWinThread será destruído, o que invalida quaisquer ponteiros para o objeto CWinThread e suas variáveis de membro. Talvez você precise do `m_hThread` membro para verificar o valor de saída do thread ou aguardar um sinal. Para manter o objeto CWinThread e seu `m_hThread` membro durante a execução do thread e depois que ele for encerrado, defina `m_bAutoDelete` como false antes de permitir que a execução do thread continue. Caso contrário, o thread pode ser encerrado, destruir o objeto CWinThread e fechar o identificador antes de tentar usá-lo. Se você usar essa técnica, será responsável pela exclusão do objeto CWinThread.

## <a name="cwinthreadm_nthreadid"></a><a name="m_nthreadid"></a>CWinThread:: m_nThreadID

ID do thread anexado a este `CWinThread` .

```
DWORD m_nThreadID;
```

### <a name="remarks"></a>Comentários

O `m_nThreadID` membro de dados é uma variável pública do tipo DWORD. Ele só será válido se o objeto de thread do kernel subjacente existir atualmente.
Consulte também comentários sobre [m_hThread](#m_hthread) tempo de vida.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [AfxGetThread](application-information-and-management.md#afxgetthread).

## <a name="cwinthreadm_pactivewnd"></a><a name="m_pactivewnd"></a>CWinThread:: m_pActiveWnd

Use este membro de dados para armazenar um ponteiro para o objeto de janela ativa do thread.

```
CWnd* m_pActiveWnd;
```

### <a name="remarks"></a>Comentários

O biblioteca MFC encerrará automaticamente seu thread quando a janela referenciada por `m_pActiveWnd` estiver fechada. Se esse thread for o principal thread de um aplicativo, o aplicativo também será encerrado. Se esse membro de dados for nulo, a janela ativa do objeto do aplicativo `CWinApp` será herdada. `m_pActiveWnd`é uma variável pública do tipo `CWnd*` .

Normalmente, você define essa variável de membro ao substituir `InitInstance` . Em um thread de trabalho, o valor desse membro de dados é herdado de seu thread pai.

## <a name="cwinthreadm_pmainwnd"></a><a name="m_pmainwnd"></a>CWinThread:: m_pMainWnd

Use este membro de dados para armazenar um ponteiro para o objeto de janela principal do seu thread.

```
CWnd* m_pMainWnd;
```

### <a name="remarks"></a>Comentários

O biblioteca MFC encerrará automaticamente seu thread quando a janela referenciada por `m_pMainWnd` estiver fechada. Se esse thread for o principal thread de um aplicativo, o aplicativo também será encerrado. Se esse membro de dados for nulo, a janela principal do objeto do aplicativo `CWinApp` será usada para determinar quando encerrar o thread. `m_pMainWnd`é uma variável pública do tipo `CWnd*` .

Normalmente, você define essa variável de membro ao substituir `InitInstance` . Em um thread de trabalho, o valor desse membro de dados é herdado de seu thread pai.

## <a name="cwinthreadonidle"></a><a name="onidle"></a>CWinThread:: OnIdle

Substitua essa função de membro para executar o processamento em tempo ocioso.

```
virtual BOOL OnIdle(LONG lCount);
```

### <a name="parameters"></a>parâmetros

*lCount*<br/>
Um contador incrementado A cada vez `OnIdle` é chamado quando a fila de mensagens do thread está vazia. Essa contagem é redefinida como 0 sempre que uma nova mensagem é processada. Você pode usar o parâmetro *lCount* para determinar o período de tempo relativo que o thread esteve ocioso sem processar uma mensagem.

### <a name="return-value"></a>Valor retornado

Diferente de zero para receber mais tempo de processamento ocioso; 0 se não for necessário mais tempo de processamento ocioso.

### <a name="remarks"></a>Comentários

`OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do thread está vazia. Use sua substituição para chamar suas próprias tarefas de manipulador ocioso de segundo plano.

`OnIdle`deve retornar 0 para indicar que nenhum tempo de processamento ocioso adicional é necessário. O parâmetro *lCount* é incrementado cada vez `OnIdle` que é chamado quando a fila de mensagens está vazia e é redefinido como 0 sempre que uma nova mensagem é processada. Você pode chamar suas diferentes rotinas ociosas com base nessa contagem.

A implementação padrão dessa função de membro libera objetos temporários e bibliotecas de vínculo dinâmico não utilizadas da memória.

Essa função de membro é usada somente em threads de interface do usuário.

Como o aplicativo não pode processar mensagens até `OnIdle` retornar, não execute tarefas demoradas nessa função.

## <a name="cwinthreadoperator-handle"></a><a name="operator_handle"></a>IDENTIFICADOR de CWinThread:: Operator

Recupera o identificador do `CWinThread` objeto.

```
operator HANDLE() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o identificador do objeto de thread; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use o identificador para chamar diretamente as APIs do Windows.

## <a name="cwinthreadpostthreadmessage"></a><a name="postthreadmessage"></a>CWinThread::P ostThreadMessage

Chamado para postar uma mensagem definida pelo usuário em outro `CWinThread` objeto.

```
BOOL PostThreadMessage(
    UINT message,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>parâmetros

*message*<br/>
ID da mensagem definida pelo usuário.

*wParam*<br/>
Primeiro parâmetro de mensagem.

*lParam*<br/>
Segundo parâmetro de mensagem.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A mensagem postada é mapeada para o manipulador de mensagens adequado pelo ON_THREAD_MESSAGE de macro do mapa de mensagens.

> [!NOTE]
> Quando você chama [PostThreadMessage](/windows/win32/api/winuser/nf-winuser-postthreadmessagew), a mensagem é colocada na fila de mensagens do thread. No entanto, como as mensagens lançadas dessa maneira não estão associadas a uma janela, o MFC não as enviará a manipuladores de mensagens ou comandos. Para lidar com essas mensagens, substitua a `PreTranslateMessage()` função da classe derivada de CWinApp e manipule as mensagens manualmente.

## <a name="cwinthreadpretranslatemessage"></a><a name="pretranslatemessage"></a>CWinThread::P reTranslateMessage

Substitua essa função para filtrar as mensagens de janela antes que elas sejam expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>parâmetros

*pMsg*<br/>
Aponta para uma [estrutura msg](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser processada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem foi totalmente processada em `PreTranslateMessage` e não deve ser processada ainda mais. Zero se a mensagem deve ser processada da maneira normal.

### <a name="remarks"></a>Comentários

Essa função de membro é usada somente em threads de interface do usuário.

## <a name="cwinthreadprocessmessagefilter"></a><a name="processmessagefilter"></a>CWinThread::P rocessMessageFilter

A função Hook da estrutura chama essa função de membro para filtrar e responder a determinadas mensagens do Windows.

```
virtual BOOL ProcessMessageFilter(
    int code,
    LPMSG lpMsg);
```

### <a name="parameters"></a>parâmetros

*code*<br/>
Especifica um código de gancho. Essa função de membro usa o código para determinar como processar *lpMsg.*

*lpMsg*<br/>
Um ponteiro para uma [estrutura de MSG](/windows/win32/api/winuser/ns-winuser-msg)do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem for processada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma função de Hook processa eventos antes que eles sejam enviados para o processamento de mensagem normal do aplicativo.

Se você substituir esse recurso avançado, certifique-se de chamar a versão de classe base para manter o processamento de gancho da estrutura.

## <a name="cwinthreadprocesswndprocexception"></a><a name="processwndprocexception"></a>CWinThread::P rocessWndProcException

A estrutura chama essa função de membro sempre que o manipulador não captura uma exceção gerada em um dos manipuladores de comando ou de mensagem do thread.

```
virtual LRESULT ProcessWndProcException(
    CException* e,
    const MSG* pMsg);
```

### <a name="parameters"></a>parâmetros

*Oriental*<br/>
Aponta para uma exceção sem tratamento.

*pMsg*<br/>
Aponta para uma [estrutura msg](/windows/win32/api/winuser/ns-winuser-msg) que contém informações sobre a mensagem do Windows que fez com que a estrutura lançasse uma exceção.

### <a name="return-value"></a>Valor retornado

-1 se uma exceção de WM_CREATE for gerada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Não chame essa função de membro diretamente.

A implementação padrão dessa função de membro trata apenas das exceções geradas a partir das seguintes mensagens:

|Comando|Ação|
|-------------|------------|
|WM_CREATE|Falha.|
|WM_PAINT|Validar a janela afetada, impedindo que outra mensagem WM_PAINT seja gerada.|

Substitua essa função de membro para fornecer manipulação global de suas exceções. Chame a funcionalidade base somente se desejar exibir o comportamento padrão.

Essa função de membro é usada somente em threads que têm uma bomba de mensagem.

## <a name="cwinthreadpumpmessage"></a><a name="pumpmessage"></a>CWinThread::P umpMessage

Contém o loop de mensagem do thread.

```
virtual BOOL PumpMessage();
```

### <a name="remarks"></a>Comentários

`PumpMessage`contém o loop de mensagem do thread. `PumpMessage`é chamado pelo `CWinThread` para bombear as mensagens do thread. Você pode chamar `PumpMessage` diretamente para forçar as mensagens a serem processadas ou pode substituir `PumpMessage` para alterar seu comportamento padrão.

Chamar `PumpMessage` diretamente e substituir seu comportamento padrão é recomendado somente para usuários avançados.

## <a name="cwinthreadresumethread"></a><a name="resumethread"></a>CWinThread::ResumeThread

Chamado para retomar a execução de um thread que foi suspenso pela função membro [SuspendThread](#suspendthread) ou um thread criado com o sinalizador CREATE_SUSPENDED.

```
DWORD ResumeThread();
```

### <a name="return-value"></a>Valor retornado

A contagem de suspensão anterior do thread se tiver êxito; `0xFFFFFFFF`caso contrário. Se o valor de retorno for zero, o thread atual não foi suspenso. Se o valor de retorno for um, o thread foi suspenso, mas agora será reiniciado. Qualquer valor de retorno maior que um significa que o thread permanece suspenso.

### <a name="remarks"></a>Comentários

A contagem de suspensões do thread atual é reduzida em um. Se a contagem de suspensão for reduzida para zero, o thread retomará a execução; caso contrário, o thread permanecerá suspenso.

## <a name="cwinthreadrun"></a><a name="run"></a>CWinThread:: Run

Fornece um loop de mensagem padrão para threads de interface do usuário.

```
virtual int Run();
```

### <a name="return-value"></a>Valor retornado

Um **`int`** valor que é retornado pelo thread. Esse valor pode ser recuperado chamando [GetExitCodeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread).

### <a name="remarks"></a>Comentários

`Run`adquire e envia mensagens do Windows até que o aplicativo receba uma mensagem de [WM_QUIT](/windows/win32/winmsg/wm-quit) . Se a fila de mensagens do thread não contiver nenhuma mensagem, `Run` chamadas `OnIdle` para executar o processamento em tempo ocioso. Mensagens de entrada acessam a função membro [PreTranslateMessage](#pretranslatemessage) para processamento especial e, em seguida, para a função do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) para tradução de teclado padrão. Por fim, a função [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) do Windows é chamada.

`Run`raramente é substituído, mas você pode substituí-lo para implementar um comportamento especial.

Essa função de membro é usada somente em threads de interface do usuário.

## <a name="cwinthreadsetthreadpriority"></a><a name="setthreadpriority"></a>CWinThread::SetThreadPriority

Essa função define o nível de prioridade do thread atual dentro de sua classe de prioridade.

```
BOOL SetThreadPriority(int nPriority);
```

### <a name="parameters"></a>parâmetros

*nPriority*<br/>
Especifica o novo nível de prioridade de thread dentro de sua classe de prioridade. Esse parâmetro deve ser um dos seguintes valores, listados da prioridade mais alta para a mais baixa:

- THREAD_PRIORITY_TIME_CRITICAL

- THREAD_PRIORITY_HIGHEST

- THREAD_PRIORITY_ABOVE_NORMAL

- THREAD_PRIORITY_NORMAL

- THREAD_PRIORITY_BELOW_NORMAL

- THREAD_PRIORITY_LOWEST

- THREAD_PRIORITY_IDLE

Para obter mais informações sobre essas prioridades, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Só pode ser chamado depois que [CreateThread](#createthread) retornar com êxito.

## <a name="cwinthreadsuspendthread"></a><a name="suspendthread"></a>CWinThread::SuspendThread

Incrementa a contagem de suspensões do thread atual.

```
DWORD SuspendThread();
```

### <a name="return-value"></a>Valor retornado

A contagem de suspensão anterior do thread se tiver êxito; `0xFFFFFFFF`caso contrário.

### <a name="remarks"></a>Comentários

Se qualquer thread tiver uma contagem de suspensão acima de zero, esse thread não será executado. O thread pode ser retomado chamando a função membro [ResumeThread](#resumethread) .

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)
