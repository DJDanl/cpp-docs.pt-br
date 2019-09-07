---
title: Informações e gerenciamento do aplicativo
ms.date: 11/04/2016
helpviewer_keywords:
- applications [MFC], managing
ms.assetid: b72f4154-24db-4e75-bca3-6873e2459c15
ms.openlocfilehash: 52e6dbaa07fa8343a07533f071d538d9f76b0f61
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741164"
---
# <a name="application-information-and-management"></a>Informações e gerenciamento do aplicativo

Ao escrever um aplicativo, você cria um único objeto derivado de [CWinApp](../../mfc/reference/cwinapp-class.md). Às vezes, talvez você queira obter informações sobre esse objeto de fora do `CWinApp`objeto derivado. Ou talvez você precise de acesso a outros objetos "Manager" globais.

O biblioteca MFC fornece as seguintes funções globais para ajudá-lo a realizar essas tarefas:

### <a name="application-information-and-management-functions"></a>Funções de gerenciamento e informações do aplicativo

|||
|-|-|
|[AfxBeginThread](#afxbeginthread)|Cria um novo thread.|
|[AfxContextMenuManager](#afxcontextmenumanager)|Ponteiro para o [Gerenciador de menu de contexto](ccontextmenumanager-class.md)global.|
|[AfxEndThread](#afxendthread)|Encerra o thread atual.|
|[AfxFindResourceHandle](#afxfindresourcehandle)|Percorre a cadeia de recursos e localiza um recurso específico por ID de recurso e tipo de recurso. |
|[AfxFreeLibrary](#afxfreelibrary)|Decrementa a contagem de referência do módulo carregado da biblioteca de vínculo dinâmico (DLL); Quando a contagem de referência chega a zero, o módulo não é mapeado.|
|[AfxGetApp](#afxgetapp)|Retorna um ponteiro para o único `CWinApp` objeto do aplicativo.|
|[AfxGetAppName](#afxgetappname)|Retorna uma cadeia de caracteres que contém o nome do aplicativo.|
|[AfxGetInstanceHandle](#afxgetinstancehandle)|Retorna um HINSTANCE que representa essa instância do aplicativo.|
|[AfxGetMainWnd](#afxgetmainwnd)|Retorna um ponteiro para a janela "Main" atual de um aplicativo não OLE ou para a janela de quadro in-loco de um aplicativo de servidor.|
|[AfxGetPerUserRegistration](#afxgetperuserregistration)|Use essa função para determinar se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** ( **HKCU**).|
|[AfxGetResourceHandle](#afxgetresourcehandle)|Retorna um HINSTANCE para a fonte dos recursos padrão do aplicativo. Use isso para acessar os recursos do aplicativo diretamente.|
|[AfxGetThread](#afxgetthread)|Recupera um ponteiro para o objeto [CWinThread](../../mfc/reference/cwinthread-class.md) atual.|
|[AfxInitRichEdit](#afxinitrichedit)|Inicializa o controle de edição avançada versão 1,0 do aplicativo.|
|[AfxInitRichEdit2](#afxinitrichedit2)|Inicializa a versão 2,0 e o controle de edição avançado mais recente para o aplicativo.|
|[AfxIsExtendedFrameClass](#afxisextendedframeclass)|Determina se a janela especificada é um objeto de quadro estendido.|
|[AfxIsMFCToolBar](#afxismfctoolbar)|Determina se a janela especificada é um objeto de barra de ferramentas.|
|[AfxKeyboardManager](#afxkeyboardmanager)|Ponteiro para o [Gerenciador de teclado](ckeyboardmanager-class.md)global.|
|[AfxLoadLibrary](#afxloadlibrary)|Mapeia um módulo de DLL e retorna um identificador que pode ser usado para obter o endereço de uma função de DLL.|
|[AfxMenuTearOffManager](#afxmenutearoffmanager)|Ponteiro para o [Gerenciador do menu tearoff](cmenutearoffmanager-class.md)global.|
|[AfxMouseManager](#afxmousemanager)|Ponteiro para o global [mouse Manager](cmousemanager-class.md).|
|[AfxRegisterClass](#afxregisterclass)|Registra uma classe de janela em uma DLL que usa MFC.|
|[AfxRegisterWndClass](#afxregisterwndclass)|Registra uma classe de janela do Windows para complementar aquelas registradas automaticamente pelo MFC.|
|[AfxSetPerUserRegistration](#afxsetperuserregistration)|Define se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** ( **HKCU**).|
|[AfxSetResourceHandle](#afxsetresourcehandle)|Define o identificador HINSTANCE em que os recursos padrão do aplicativo são carregados.|
|[AfxShellManager](#afxshellmanager)|Ponteiro para o [Gerenciador de shell](cshellmanager-class.md)global. |
|[AfxSocketInit](#afxsocketinit)|Chamado em uma `CWinApp::InitInstance` substituição para inicializar o Windows Sockets.|
|[AfxUserToolsManager](#afxusertoolsmanager)|Ponteiro para o [gerente de ferramentas de usuário](cusertoolsmanager-class.md)global.|
|[AfxWinInit](#afxwininit)|Chamado pela função fornecida `WinMain` pelo MFC, como parte da inicialização do [CWinApp](../../mfc/reference/cwinapp-class.md) de um aplicativo baseado em GUI, para inicializar o MFC. Deve ser chamado diretamente para aplicativos de console que usam MFC.|

##  <a name="afxbeginthread"></a>  AfxBeginThread

Chame essa função para criar um novo thread.

```
CWinThread* AfxBeginThread(
    AFX_THREADPROC pfnThreadProc,
    LPVOID pParam,
    int nPriority = THREAD_PRIORITY_NORMAL,
    UINT nStackSize = 0,
    DWORD dwCreateFlags = 0,
    LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);

CWinThread* AfxBeginThread(
    CRuntimeClass* pThreadClass,
    int nPriority = THREAD_PRIORITY_NORMAL,
    UINT nStackSize = 0,
    DWORD dwCreateFlags = 0,
    LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
```

### <a name="parameters"></a>Parâmetros

*pfnThreadProc*<br/>
Aponta para a função de controle para o thread de trabalho. Não pode ser NULL. Essa função deve ser declarada da seguinte maneira:

`UINT __cdecl MyControllingFunction( LPVOID pParam );`

*pThreadClass*<br/>
O RUNTIME_CLASS de um objeto derivado de [CWinThread](../../mfc/reference/cwinthread-class.md).

*pParam*<br/>
Parâmetro a ser passado para a função de controle, conforme mostrado no parâmetro para a declaração da função em *pfnThreadProc*.

*nPriority*<br/>
A prioridade desejada do thread. Para obter uma lista completa e uma descrição das prioridades disponíveis, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

*nStackSize*<br/>
Especifica o tamanho em bytes da pilha para o novo thread. Se for 0, o tamanho da pilha será padronizado para a mesma pilha de tamanho que o thread de criação.

*dwCreateFlags*<br/>
Especifica um sinalizador adicional que controla a criação do thread. Esse sinalizador pode conter um dos dois valores:

- CREATE_SUSPENDED inicie o thread com uma contagem de suspensão de um. Use CREATE_SUSPENDED se você quiser inicializar qualquer dado de membro do `CWinThread` objeto, como [m_bAutoDelete](../../mfc/reference/cwinthread-class.md#m_bautodelete) ou quaisquer membros de sua classe derivada, antes que o thread comece a ser executado. Quando a inicialização for concluída, use [CWinThread:: ResumeThread](../../mfc/reference/cwinthread-class.md#resumethread) para iniciar o thread em execução. O thread não será executado até `CWinThread::ResumeThread` que seja chamado.

- **0** inicie o thread imediatamente após a criação.

*lpSecurityAttrs*<br/>
Aponta para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica os atributos de segurança para o thread. Se for NULL, os mesmos atributos de segurança que o thread de criação serão usados. Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Ponteiro para o objeto de thread recém-criado, ou NULL se ocorrer uma falha.

### <a name="remarks"></a>Comentários

A primeira forma de `AfxBeginThread` criar um thread de trabalho. O segundo formulário cria um thread que pode servir como um thread de interface do usuário ou como um thread de trabalho.

`AfxBeginThread`Cria um novo `CWinThread` objeto, chama sua função [CreateThread](../../mfc/reference/cwinthread-class.md#createthread) para iniciar a execução do thread e retorna um ponteiro para o thread. As verificações são feitas em todo o procedimento para garantir que todos os objetos sejam desalocados corretamente caso qualquer parte da criação falhe. Para encerrar o thread, chame [AfxEndThread](#afxendthread) de dentro do thread ou retorne da função de controle do thread de trabalho.

O multithreading deve ser habilitado pelo aplicativo; caso contrário, essa função falhará. Para obter mais informações sobre como habilitar multithreading, consulte [/MD,/MT,/LD (usar biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) em *Opções do compilador Visual C++* .

Para obter mais informações `AfxBeginThread`sobre o, consulte [os artigos multithreadinging: Criando threads](../../parallel/multithreading-creating-worker-threads.md) de [trabalho e multithreading: Criando threads](../../parallel/multithreading-creating-user-interface-threads.md)de interface do usuário.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CSocket:: Attach](../../mfc/reference/csocket-class.md#attach).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxcontextmenumanager"></a>AfxContextMenuManager

Ponteiro para o [Gerenciador de menu de contexto](ccontextmenumanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```
CContextMenuManager* afxContextMenuManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcontextmenumanager. h

##  <a name="afxendthread"></a>  AfxEndThread

Chame essa função para encerrar o thread em execução no momento.

```
void AFXAPI AfxEndThread(
    UINT nExitCode,
    BOOL bDelete  = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nExitCode*<br/>
Especifica o código de saída do thread.

*bDelete*<br/>
Exclui o objeto de thread da memória.

### <a name="remarks"></a>Comentários

Deve ser chamado de dentro do thread a ser encerrado.

Para obter mais informações `AfxEndThread`sobre o, consulte [o artigo Multithreading: Encerrando](../../parallel/multithreading-terminating-threads.md)threads.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

  ## <a name="afxfindresourcehandle"></a>AfxFindResourceHandle
Use `AfxFindResourceHandle` para percorrer a cadeia de recursos e localizar um recurso específico por ID de recurso e tipo de recurso.

### <a name="syntax"></a>Sintaxe

```
HINSTANCE AFXAPI AfxFindResourceHandle( LPCTSTR lpszName,  LPCTSTR lpszType );
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que contém a ID do recurso.
*lpszType*<br/>
Um ponteiro para o tipo de recurso. Para obter uma lista de tipos de recursos, consulte [FindResource](/windows/win32/api/winbase/nf-winbase-findresourcea) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um identificador para o módulo que contém o recurso.

### <a name="remarks"></a>Comentários

`AfxFindResourceHandle`localiza o recurso específico e retorna um identificador para o módulo que contém o recurso. O recurso pode estar em qualquer DLL de extensão MFC que você carregou. `AfxFindResourceHandle`informa qual deles tem o recurso.

Os módulos são pesquisados nesta ordem:

1. O módulo principal (se for uma DLL de extensão do MFC).

1. Módulos que não são do sistema.

1. Módulos específicos de idioma.

1. O módulo principal (se for um sistema DLL).

1. Módulos do sistema.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="afxfreelibrary"></a>  AfxFreeLibrary

`AfxFreeLibrary` E`AfxLoadLibrary` manter uma contagem de referência para cada módulo de biblioteca carregado.

```
BOOL AFXAPI AfxFreeLibrary(HINSTANCE hInstLib);
```

### <a name="parameters"></a>Parâmetros

*hInstLib*<br/>
Um identificador do módulo de biblioteca carregado. [AfxLoadLibrary](#afxloadlibrary) retorna esse identificador.

### <a name="return-value"></a>Valor de retorno

TRUE se a função for realizada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`AfxFreeLibrary`decrementa a contagem de referência do módulo carregado da biblioteca de vínculo dinâmico (DLL). Quando a contagem de referência chega a zero, o módulo não é mapeado do espaço de endereço do processo de chamada e o identificador não é mais válido. Essa contagem de referência é incrementada a `AfxLoadLibrary` cada vez que o é chamado.

Antes de remover o mapeamento de um módulo de biblioteca, o sistema permite que a DLL se desanexe dos processos que o utilizam. Isso dá ao DLL uma oportunidade de limpar os recursos alocados em nome do processo atual. Depois que a função de ponto de entrada retorna, o módulo de biblioteca é removido do espaço de endereço do processo atual.

Use `AfxLoadLibrary` para mapear um módulo dll.

Certifique-se de `AfxFreeLibrary` usar `AfxLoadLibrary` e (em vez das funções `FreeLibrary` do `LoadLibrary`Win32 e) se seu aplicativo usar vários threads. Usar `AfxLoadLibrary` e`AfxFreeLibrary` garante que o código de inicialização e de desligamento seja executado quando a DLL de extensão do MFC for carregada e descarregada não corromper o estado global do MFC.

### <a name="example"></a>Exemplo

Consulte o exemplo de [AfxLoadLibrary](#afxloadlibrary).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdll_. h

##  <a name="afxgetapp"></a>  AfxGetApp

O ponteiro retornado por essa função pode ser usado para acessar informações do aplicativo, como o código principal de expedição de mensagens ou a janela mais alta.

```
CWinApp* AFXAPI AfxGetApp();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o único `CWinApp` objeto para o aplicativo.

### <a name="remarks"></a>Comentários

Se esse método retornar NULL, isso poderá indicar que a janela principal do aplicativo ainda não foi totalmente inicializada. Ele também pode indicar um problema.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#126](../../mfc/reference/codesnippet/cpp/application-information-and-management_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxgetappname"></a>  AfxGetAppName

A cadeia de caracteres retornada por essa função pode ser usada para mensagens de diagnóstico ou como uma raiz para nomes de cadeia de caracteres temporárias.

```
LPCTSTR AFXAPI AfxGetAppName();
```

### <a name="return-value"></a>Valor de retorno

Uma cadeia de caracteres terminada em nulo que contém o nome do aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#127](../../mfc/reference/codesnippet/cpp/application-information-and-management_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxgetinstancehandle"></a>  AfxGetInstanceHandle

Essa função permite que você recupere o identificador de instância do aplicativo atual.

```
HINSTANCE  AFXAPI AfxGetInstanceHandle();
```

### <a name="return-value"></a>Valor de retorno

Um HINSTANCE para a instância atual do aplicativo. Se chamado de dentro de uma DLL vinculada à versão USRDLL do MFC, um HINSTANCE para a DLL será retornado.

### <a name="remarks"></a>Comentários

`AfxGetInstanceHandle`sempre retorna o HINSTANCE do seu arquivo executável (. EXE) a menos que seja chamado de dentro de uma DLL vinculada à versão USRDLL do MFC. Nesse caso, ele retorna um HINSTANCE para a DLL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#128](../../mfc/reference/codesnippet/cpp/application-information-and-management_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxgetmainwnd"></a>  AfxGetMainWnd

Se seu aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo em vez de fazer referência direta ao membro [m_pMainWnd](../../mfc/reference/cwinthread-class.md#m_pmainwnd) do objeto Application.

```
CWnd* AFXAPI AfxGetMainWnd();
```

### <a name="return-value"></a>Valor de retorno

Se o servidor tiver um objeto que está ativo no local dentro de um contêiner e esse contêiner estiver ativo, essa função retornará um ponteiro para o objeto janela do quadro que contém o documento ativo no local.

Se não houver nenhum objeto ativo no local dentro de um contêiner ou seu aplicativo não for um servidor OLE, essa função simplesmente retornará o *m_pMainWnd* do seu objeto de aplicativo.

Se `AfxGetMainWnd` for chamado a partir do thread principal do aplicativo, ele retornará a janela principal do aplicativo de acordo com as regras acima. Se a função for chamada de um thread secundário no aplicativo, a função retornará a janela principal associada ao thread que fez a chamada.

### <a name="remarks"></a>Comentários

Se seu aplicativo não for um servidor OLE, chamar essa função será equivalente a fazer referência direta ao membro *m_pMainWnd* do seu objeto de aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#129](../../mfc/reference/codesnippet/cpp/application-information-and-management_4.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxgetperuserregistration"></a>  AfxGetPerUserRegistration

Use essa função para determinar se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** ( **HKCU**).

```
BOOL AFXAPI AfxGetPerUserRegistration();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO indica que as informações do registro são direcionadas para o nó HKCU; FALSE indica que o aplicativo grava informações de registro no nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).

### <a name="remarks"></a>Comentários

Se você habilitar o redirecionamento do registro, a estrutura redirecionará o acesso de **HKCR** para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.

Para alterar se o aplicativo redireciona o acesso ao registro, use [AfxSetPerUserRegistration](#afxsetperuserregistration).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxstat_. h

##  <a name="afxgetresourcehandle"></a>  AfxGetResourceHandle

Use o identificador HINSTANCE retornado por essa função para acessar os recursos do aplicativo diretamente, por exemplo, em chamadas para a função `FindResource`do Windows.

```
extern HINSTANCE  AfxGetResourceHandle();
```

### <a name="return-value"></a>Valor de retorno

Um identificador de HINSTANCE em que os recursos padrão do aplicativo são carregados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#130](../../mfc/reference/codesnippet/cpp/application-information-and-management_5.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxgetthread"></a>  AfxGetThread

Chame essa função para obter um ponteiro para o objeto [CWinThread](../../mfc/reference/cwinthread-class.md) que representa o thread em execução no momento.

```
CWinThread* AfxGetThread();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para o thread em execução no momento; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Deve ser chamado de dentro do thread desejado.

> [!NOTE]
>  Se você estiver portando um projeto MFC chamando `AfxGetThread` das versões C++ 4,2, 5,0 ou 6,0 do Visual, `AfxGetThread` o chamará [AfxGetApp](#afxgetapp) se nenhum thread for encontrado. Em versões mais recentes do compilador, `AfxGetThread` retorna NULL se nenhum thread foi encontrado. Se você quiser o thread do aplicativo, deverá chamar `AfxGetApp`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#132](../../mfc/reference/codesnippet/cpp/application-information-and-management_6.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxinitrichedit"></a>  AfxInitRichEdit

Chame essa função para inicializar o controle rich edit (versão 1,0) para o aplicativo.

```
BOOL AFXAPI AfxInitRichEdit();
```

### <a name="remarks"></a>Comentários

Essa função é fornecida para compatibilidade com versões anteriores. Os novos aplicativos devem usar o [o AfxInitRichEdit2](#afxinitrichedit2).

`AfxInitRichEdit`carrega RICHED32. DLL para inicializar a versão 1,0 do controle de edição rico. Para usar a versão 2,0 e 3,0 do controle rich edit, RICHED20. A DLL precisa ser carregada. Isso é feito com uma chamada para [o AfxInitRichEdit2](#afxinitrichedit2).

Para atualizar os controles de edição avançados em C++ aplicativos visuais existentes para a versão 2,0, abra o. Arquivo RC como texto, altere o nome da classe de cada controle de edição rico de "RICHEDIT" para "RichEdit20a". Em seguida, substitua a `AfxInitRichEdit` chamada `AfxInitRichEdit2`para por.

Essa função também inicializa a biblioteca de controles comuns, se a biblioteca ainda não tiver sido inicializada para o processo. Se você usar o controle rich edit diretamente do aplicativo MFC, deverá chamar essa função para garantir que o MFC tenha inicializado corretamente o tempo de execução do controle de edição rico. Se você chamar o método Create de [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md)ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), normalmente não precisará chamar essa função, mas, em alguns casos, talvez seja necessário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxinitrichedit2"></a>  AfxInitRichEdit2

Chame essa função para inicializar o controle rich edit (versão 2,0 e posterior) para o aplicativo.

```
BOOL AFXAPI AfxInitRichEdit2();
```

### <a name="remarks"></a>Comentários

Chame essa função para carregar o RICHED20. DLL e inicializar a versão 2,0 do controle de edição rico. Se você chamar o método Create de [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md)ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), normalmente não precisará chamar essa função, mas, em alguns casos, talvez seja necessário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

  ## <a name="afxisextendedframeclass"></a>  AfxIsExtendedFrameClass
Determina se a janela especificada é um objeto de quadro estendido.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxIsExtendedFrameClass( CWnd* pWnd );
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para um objeto que é derivado de `CWnd`.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela fornecida for um objeto de quadro estendido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retornará TRUE se *pWnd* derivar de uma das seguintes classes:

- `CFrameWndEx`

- `CMDIFrameWndEx`

- `COleIPFrameWndEx`

- `COleDocIPFrameWndEx`

- `CMDIChildWndEx`

Esse método é útil quando você precisa validar que um parâmetro de função ou método é uma janela de quadro estendido.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxismfctoolbar"></a> AfxIsMFCToolBar

Determina se a janela especificada é um objeto de barra de ferramentas.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxIsMFCToolBar(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para um objeto que é derivado de `CWnd`.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela fornecida for um objeto Toolbar; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retorna `TRUE` se *pWnd* deriva de `CMFCToolBar`. Esse método é útil quando você precisa validar que um parâmetro de função ou método é um `CMFCToolBar` objeto.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxkeyboardmanager"></a>AfxKeyboardManager

Ponteiro para o [Gerenciador de teclado](ckeyboardmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```
CKeyboardManager* afxKeyboardManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxkeyboardmanager. h

##  <a name="afxloadlibrary"></a>  AfxLoadLibrary

Use `AfxLoadLibrary` para mapear um módulo dll.

```
HINSTANCE AFXAPI AfxLoadLibrary(LPCTSTR lpszModuleName);
```

### <a name="parameters"></a>Parâmetros

*lpszModuleName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do módulo (um. DLL ou. Arquivo EXE). O nome especificado é o nome do arquivo do módulo.

Se a cadeia de caracteres especificar um caminho, mas o arquivo não existir no diretório especificado, a função falhará.

Se um caminho não for especificado e a extensão de nome de arquivo for omitida, a extensão padrão. A DLL é anexada. No entanto, a cadeia de caracteres do nome do arquivo pode incluir um caractere de ponto à direita (.) para indicar que o nome do módulo não tem extensão. Quando nenhum caminho é especificado, a função procura o arquivo na seguinte sequência:

- O diretório do qual o aplicativo foi carregado.

- O diretório atual.

- **Windows 95/98:** O diretório do sistema do Windows. **Windows NT:** O diretório de sistema do Windows de 32 bits. O nome desse diretório é SYSTEM32.

- **Somente Windows NT:** O diretório do sistema Windows de 16 bits. Não há nenhuma função Win32 que obtenha o caminho desse diretório, mas ele é pesquisado. O nome desse diretório é SYSTEM.

- O diretório do Windows.

- Os diretórios listados na variável de ambiente PATH.

### <a name="return-value"></a>Valor de retorno

Se a função for realizada com sucesso, o valor de retorno será um identificador para o módulo. Se a função falhar, o valor de retorno será nulo.

### <a name="remarks"></a>Comentários

Ele retorna um identificador que pode ser usado em [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função DLL. `AfxLoadLibrary`também pode ser usado para mapear outros módulos executáveis.

Cada processo mantém uma contagem de referência para cada módulo de biblioteca carregado. Essa contagem de referência é incrementada toda `AfxLoadLibrary` vez que é chamada e diminui cada vez `AfxFreeLibrary` que o é chamado. Quando a contagem de referência chega a zero, o módulo não é mapeado do espaço de endereço do processo de chamada e o identificador não é mais válido.

Certifique-se de `AfxLoadLibrary` usar `AfxFreeLibrary` e (em vez das funções `LoadLibrary` do `FreeLibrary`Win32 e) se seu aplicativo usar vários threads e se ele carregar dinamicamente uma DLL de extensão do MFC. Usar `AfxLoadLibrary` e`AfxFreeLibrary` garantir que o código de inicialização e desligamento seja executado quando a DLL de extensão do MFC for carregada e descarregada não corromper o estado global do MFC.

Usar `AfxLoadLibrary` o em um aplicativo exige que você vincule dinamicamente à versão DLL do MFC; o arquivo de cabeçalho `AfxLoadLibrary`para, Afxdll_. h, só será incluído se o MFC estiver vinculado ao aplicativo como uma dll. Isso ocorre por design porque você precisa vincular à versão de DLL do MFC para usar ou criar DLLs de extensão do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_DLLUser#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_7.cpp)]
[!code-cpp[NVC_MFC_DLLUser#2](../../mfc/reference/codesnippet/cpp/application-information-and-management_8.cpp)]
[!code-cpp[NVC_MFC_DLLUser#3](../../mfc/reference/codesnippet/cpp/application-information-and-management_9.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdll_. h

## <a name="afxmenutearoffmanager"></a> AfxMenuTearOffManager

Ponteiro para o [Gerenciador do menu tearoff](cmenutearoffmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```
CMenuTearOffManager* g_pTearOffMenuManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenutearoffmanager. h

## <a name="afxmousemanager"></a>  AfxMouseManager

Ponteiro para o global [mouse Manager](cmousemanager-class.md).

### <a name="syntax"></a>Sintaxe

```
CMouseManager* afxMouseManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmousemanager. h

##  <a name="afxregisterclass"></a>  AfxRegisterClass

Use essa função para registrar as classes de janela em uma DLL que usa MFC.

```
BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass);
```

### <a name="parameters"></a>Parâmetros

*lpWndClass*<br/>
Ponteiro para uma estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) que contém informações sobre a classe de janela a ser registrada. Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

### <a name="return-value"></a>Valor de retorno

TRUE se a classe for registrada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se você usar essa função, a classe será desregistrada automaticamente quando a DLL for descarregada.

Em compilações não-dll, `AfxRegisterClass` o identificador é definido como uma macro que é mapeada para a `RegisterClass`função do Windows, já que as classes registradas em um aplicativo são desregistradas automaticamente. Se você usar `AfxRegisterClass` em vez `RegisterClass`de, seu código poderá ser usado sem alterações em um aplicativo e em uma dll.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_DLL#3](../../atl-mfc-shared/codesnippet/cpp/application-information-and-management_10.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxregisterwndclass"></a>  AfxRegisterWndClass

Permite que você registre suas próprias classes de janela.

```
LPCTSTR AFXAPI AfxRegisterWndClass(
    UINT nClassStyle,
    HCURSOR hCursor = 0,
    HBRUSH hbrBackground = 0,
    HICON hIcon = 0);
```

### <a name="parameters"></a>Parâmetros

*nClassStyle*<br/>
Especifica o estilo de classe do Windows ou a combinação de estilos, criada usando o operador bit **&#124;** -a-or () para a classe Window. Para obter uma lista de estilos de classe, consulte a estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) no SDK do Windows. Se for NULL, os padrões serão definidos da seguinte maneira:

- Define o estilo do mouse como CS_DBLCLKS, que envia mensagens de clique duplo para o procedimento de janela quando o usuário clica duas vezes no mouse.

- Define o estilo do cursor de seta como o IDC_ARROW padrão do Windows.

- Define o pincel de plano de fundo como nulo, portanto, a janela não apagará seu plano de fundo.

- Define o ícone para o ícone de logotipo padrão acenando do Windows.

*hCursor*<br/>
Especifica um identificador para o recurso de cursor a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, obterá o cursor IDC_ARROW padrão.

*hbrBackground*<br/>
Especifica um identificador para o recurso de pincel a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, terá um pincel de plano de fundo nulo e a janela, por padrão, não apagará seu plano de fundo durante o processamento de [WM_ERASEBKGND](/windows/win32/winmsg/wm-erasebkgnd).

*hIcon*<br/>
Especifica um identificador para o recurso de ícone a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, obterá o ícone de logotipo padrão do Windows acenando-Flag.

### <a name="return-value"></a>Valor de retorno

Uma cadeia de caracteres terminada em nulo que contém o nome da classe. Você pode passar esse nome de classe para `Create` a função membro `CWnd` em ou outras classes derivadas de **CWnd**para criar uma janela. O nome é gerado pelo biblioteca MFC.

> [!NOTE]
>  O valor de retorno é um ponteiro para um buffer estático. Para salvar essa cadeia de caracteres, atribua- `CString` a a uma variável.

### <a name="remarks"></a>Comentários

O biblioteca MFC automaticamente registra várias classes de janela padrão para você. Chame essa função se você quiser registrar suas próprias classes de janela.

O nome registrado para uma classe `AfxRegisterWndClass` depende exclusivamente dos parâmetros. Se você chamar `AfxRegisterWndClass` várias vezes com parâmetros idênticos, ele registrará apenas uma classe na primeira chamada. As chamadas subsequentes para `AfxRegisterWndClass` com parâmetros idênticos simplesmente retornam o ClassName já registrado.

Se você chamar `AfxRegisterWndClass` várias classes derivadas de CWnd com parâmetros idênticos, em vez de obter uma classe de janela separada para cada classe, cada classe compartilhará a mesma classe de janela. Isso pode causar problemas se o estilo de classe CS_CLASSDC for usado. Em vez de várias classes de janela CS_CLASSDC, você acaba com uma classe de janela CS_CLASSDC e C++ todas as janelas que usam essa classe compartilham o mesmo DC. Para evitar esse problema, chame [AfxRegisterClass](#afxregisterclass) para registrar a classe.

Consulte a nota [técnica TN001: Registro](../../mfc/tn001-window-class-registration.md) de classe de janela para obter mais informações sobre o registro `AfxRegisterWndClass` de classe de janela e a função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#134](../../mfc/reference/codesnippet/cpp/application-information-and-management_11.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

##  <a name="afxsetperuserregistration"></a>  AfxSetPerUserRegistration

Define se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** ( **HKCU**).

```
void AFXAPI AfxSetPerUserRegistration(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no VERDADEIRO indica que as informações do registro são direcionadas para o nó HKCU; FALSE indica que o aplicativo grava informações de registro no nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).

### <a name="remarks"></a>Comentários

Antes do Windows Vista, os aplicativos que acessaram o registro geralmente usaram o nó **HKEY_CLASSES_ROOT** . No entanto, com o Windows Vista ou sistemas operacionais posteriores, você deve executar um aplicativo no modo elevado para gravar em HKCR.

Esse método permite que seu aplicativo Leia e grave no registro sem executar no modo elevado redirecionando o acesso do registro de HKCR para HKCU. Para obter mais informações, consulte [páginas de propriedades do vinculador](../../build/reference/linker-property-pages.md).

Se você habilitar o redirecionamento do registro, a estrutura redirecionará o acesso de HKCR para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.

A implementação padrão acessa o registro em HKCR.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxstat_. h

##  <a name="afxsetresourcehandle"></a>  AfxSetResourceHandle

Use essa função para definir o identificador HINSTANCE que determina onde os recursos padrão do aplicativo são carregados.

```
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);
```

### <a name="parameters"></a>Parâmetros

*hInstResource*<br/>
A instância ou o identificador de módulo para um. Arquivo EXE ou DLL do qual os recursos do aplicativo são carregados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#135](../../mfc/reference/codesnippet/cpp/application-information-and-management_12.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxshellmanager"></a>  AfxShellManager

Ponteiro para o [Gerenciador de shell](cshellmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```
CShellManager* afxShellManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshellmanager. h

##  <a name="afxsocketinit"></a>  AfxSocketInit

Chame essa função em sua `CWinApp::InitInstance` substituição para inicializar o Windows Sockets.

```
BOOL AfxSocketInit(WSADATA* lpwsaData = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpwsaData*<br/>
Um ponteiro para uma estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) . Se *lpwsaData* não for igual a NULL, o endereço da `WSADATA` estrutura será preenchido pela chamada para. `WSAStartup` Essa função também garante que `WSACleanup` o seja chamado para você antes de o aplicativo ser encerrado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você `AfxSocketInit` deve chamar em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado apenas no thread primário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AfxSock. h

## <a name="afxusertoolsmanager"></a>  AfxUserToolsManager

Ponteiro para o [gerente de ferramentas de usuário](cusertoolsmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```
CUserToolsManager* afxUserToolsManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertoolsmanager. h

##  <a name="afxwininit"></a>  AfxWinInit

Essa função é chamada pela função fornecida `WinMain` pelo MFC, como parte da inicialização do [CWinApp](../../mfc/reference/cwinapp-class.md) de um aplicativo baseado em GUI, para inicializar o MFC.

```
BOOL AFXAPI AfxWinInit(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine,
    int nCmdShow);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O identificador do módulo em execução no momento.

*hPrevInstance*<br/>
Um identificador para uma instância anterior do aplicativo. Para um aplicativo baseado em Win32, esse parâmetro é sempre **nulo**.

*lpCmdLine*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo.

*nCmdShow*<br/>
Especifica como a janela principal de um aplicativo de GUI seria mostrada.

### <a name="remarks"></a>Comentários

Para um aplicativo de console, que não usa a função fornecida `WinMain` pelo MFC, você deve chamar `AfxWinInit` diretamente para inicializar o MFC.

Se você chamar `AfxWinInit` a si mesmo, deverá declarar uma instância de `CWinApp` uma classe. Para um aplicativo de console, você pode optar por não derivar sua própria `CWinApp` classe de e, em vez `CWinApp` disso, usar uma instância do diretamente. Essa técnica é apropriada se você decidir deixar toda a funcionalidade para seu aplicativo em sua implementação de **principal**.

> [!NOTE]
>  Quando ele cria um contexto de ativação para um assembly, o MFC usa um recurso de manifesto fornecido pelo módulo do usuário. O contexto de ativação é criado `AfxWinInit`no. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../../mfc/support-for-activation-contexts-in-the-mfc-module-state.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_AfxWinInit#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_13.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CWinApp](cwinapp-class.md)<br/>
[Classe CContextMenuManager](ccontextmenumanager-class.md)<br/>
[Classe CWnd](cwnd-class.md)<br/>
[Classe CFrameWndEx](cframewndex-class.md)<br/>
[Classe CMFCToolBar](cmfctoolbar-class.md)<br/>
[Classe CKeyboardManager](ckeyboardmanager-class.md)<br/>
[Classe CMenuTearOffManager](cmenutearoffmanager-class.md)<br/>
[Classe CMouseManager](cmousemanager-class.md)<br/>
[Classe CShellManager](cshellmanager-class.md)<br/>
[Classe CUserToolsManager](cusertoolsmanager-class.md)
