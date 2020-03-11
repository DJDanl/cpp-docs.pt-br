---
title: Informações e gerenciamento do aplicativo
description: Referência para as funções de gerenciamento e informações de aplicativo da Microsoft Foundation Class Library (MFC).
ms.date: 01/27/2020
helpviewer_keywords:
- applications [MFC], managing
ms.assetid: b72f4154-24db-4e75-bca3-6873e2459c15
ms.openlocfilehash: c372f43bc5184349e70f29b6c0ae6a490f2102ed
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854535"
---
# <a name="application-information-and-management"></a>Informações e gerenciamento do aplicativo

Ao escrever um aplicativo, você cria um único objeto derivado de [CWinApp](../../mfc/reference/cwinapp-class.md). Às vezes, talvez você queira obter informações sobre esse objeto de fora do objeto derivado de `CWinApp`. Ou talvez você precise de acesso a outros objetos "Manager" globais.

O biblioteca MFC fornece as seguintes funções globais para ajudá-lo a realizar essas tarefas:

## <a name="application-information-and-management-functions"></a>Funções de gerenciamento e informações do aplicativo

|||
|-|-|
|[AfxBeginThread](#afxbeginthread)|Cria um novo thread.|
|[AfxContextMenuManager](#afxcontextmenumanager)|Ponteiro para o [Gerenciador de menu de contexto](ccontextmenumanager-class.md)global.|
|[AfxEndThread](#afxendthread)|Encerra o thread atual.|
|[AfxFindResourceHandle](#afxfindresourcehandle)|Percorre a cadeia de recursos e localiza um recurso específico por ID de recurso e tipo de recurso. |
|[AfxFreeLibrary](#afxfreelibrary)|Decrementa a contagem de referência do módulo carregado da biblioteca de vínculo dinâmico (DLL). Quando a contagem de referência chega a zero, o módulo não é mapeado.|
|[AfxGetApp](#afxgetapp)|Retorna um ponteiro para o único objeto de `CWinApp` do aplicativo.|
|[AfxGetAppName](#afxgetappname)|Retorna uma cadeia de caracteres que contém o nome do aplicativo.|
|[AfxGetInstanceHandle](#afxgetinstancehandle)|Retorna um HINSTANCE que representa essa instância do aplicativo.|
|[AfxGetMainWnd](#afxgetmainwnd)|Retorna um ponteiro para a janela "Main" atual de um aplicativo não OLE ou para a janela de quadro in-loco de um aplicativo de servidor.|
|[AfxGetPerUserRegistration](#afxgetperuserregistration)|Use essa função para determinar se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** (**HKCU**).|
|[AfxGetResourceHandle](#afxgetresourcehandle)|Retorna um HINSTANCE para a fonte dos recursos padrão do aplicativo. Use o para acessar os recursos do aplicativo diretamente.|
|[AfxGetThread](#afxgetthread)|Recupera um ponteiro para o objeto [CWinThread](../../mfc/reference/cwinthread-class.md) atual.|
|[AfxInitRichEdit](#afxinitrichedit)|Inicializa o controle de edição avançada versão 1,0 do aplicativo.|
|[O AfxInitRichEdit2](#afxinitrichedit2)|Inicializa a versão 2,0 e o controle de edição avançado mais recente para o aplicativo.|
|[AfxIsExtendedFrameClass](#afxisextendedframeclass)|Determina se a janela especificada é um objeto de quadro estendido.|
|[AfxIsMFCToolBar](#afxismfctoolbar)|Determina se a janela especificada é um objeto de barra de ferramentas.|
|[AfxKeyboardManager](#afxkeyboardmanager)|Ponteiro para o [Gerenciador de teclado](ckeyboardmanager-class.md)global.|
|[AfxLoadLibrary](#afxloadlibrary)|Mapeia um módulo de DLL e retorna um identificador que pode ser usado para obter o endereço de uma função de DLL.|
|[AfxLoadLibraryEx](#afxloadlibraryex)|Mapeia um módulo de DLL usando as opções especificadas e retorna um identificador que pode ser usado para obter o endereço de uma função de DLL.|
|[AfxMenuTearOffManager](#afxmenutearoffmanager)|Ponteiro para o [Gerenciador de menus destacável](cmenutearoffmanager-class.md)global.|
|[AfxMouseManager](#afxmousemanager)|Ponteiro para o global [mouse Manager](cmousemanager-class.md).|
|[AfxRegisterClass](#afxregisterclass)|Registra uma classe de janela em uma DLL que usa MFC.|
|[AfxRegisterWndClass](#afxregisterwndclass)|Registra uma classe de janela do Windows para complementar aquelas registradas automaticamente pelo MFC.|
|[AfxSetPerUserRegistration](#afxsetperuserregistration)|Define se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** (**HKCU**).|
|[AfxSetResourceHandle](#afxsetresourcehandle)|Define o identificador HINSTANCE em que os recursos padrão do aplicativo são carregados.|
|[AfxShellManager](#afxshellmanager)|Ponteiro para o [Gerenciador de shell](cshellmanager-class.md)global. |
|[AfxSocketInit](#afxsocketinit)|Chamado em uma substituição de `CWinApp::InitInstance` para inicializar o Windows Sockets.|
|[AfxUserToolsManager](#afxusertoolsmanager)|Ponteiro para o [gerente de ferramentas de usuário](cusertoolsmanager-class.md)global.|
|[AfxWinInit](#afxwininit)|Chamado pela função de `WinMain` fornecida pelo MFC, como parte da inicialização do [CWinApp](../../mfc/reference/cwinapp-class.md) de um aplicativo baseado em GUI, para inicializar o MFC. Deve ser chamado diretamente para aplicativos de console que usam MFC.|

## <a name="afxbeginthread"></a>AfxBeginThread

Chame essa função para criar um novo thread.

```cpp
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

### <a name="parameters"></a>parâmetros

\ *pfnThreadProc*
Aponta para a função de controle para o thread de trabalho. O ponteiro não pode ser nulo. Essa função deve ser declarada da seguinte maneira:

`UINT __cdecl MyControllingFunction( LPVOID pParam );`

\ *pThreadClass*
O RUNTIME_CLASS de um objeto derivado de [CWinThread](../../mfc/reference/cwinthread-class.md).

\ *pParam*
Parâmetro a ser passado para a função de controle.

\ *nPriority*
A prioridade a ser definida para o thread. Para obter uma lista completa e uma descrição das prioridades disponíveis, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

\ *nStackSize*
Especifica o tamanho em bytes da pilha para o novo thread. Se for 0, o tamanho da pilha será padronizado para a mesma pilha de tamanho que o thread de criação.

\ *dwCreateFlags*
Especifica um sinalizador adicional que controla a criação do thread. Esse sinalizador pode conter um dos dois valores:

- CREATE_SUSPENDED iniciar o thread com uma contagem de suspensão de um. Use CREATE_SUSPENDED se você quiser inicializar qualquer dado de membro do objeto `CWinThread`, como [m_bAutoDelete](../../mfc/reference/cwinthread-class.md#m_bautodelete) ou qualquer membro da classe derivada, antes de o thread começar a ser executado. Quando a inicialização for concluída, use [CWinThread:: ResumeThread](../../mfc/reference/cwinthread-class.md#resumethread) para iniciar o thread em execução. O thread não será executado até que `CWinThread::ResumeThread` seja chamado.

- **0** inicie o thread imediatamente após a criação.

\ *lpSecurityAttrs*
Aponta para uma estrutura de [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica os atributos de segurança para o thread. Se for NULL, os mesmos atributos de segurança que o thread de criação serão usados. Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

### <a name="return-value"></a>Valor retornado

Ponteiro para o objeto de thread recém-criado, ou NULL se ocorrer uma falha.

### <a name="remarks"></a>Comentários

A primeira forma de `AfxBeginThread` cria um thread de trabalho. O segundo formulário cria um thread que pode servir como um thread de interface do usuário ou como um thread de trabalho.

`AfxBeginThread` cria um novo objeto `CWinThread`, chama sua função [CreateThread](../../mfc/reference/cwinthread-class.md#createthread) para iniciar a execução do thread e retorna um ponteiro para o thread. As verificações são feitas em todo o procedimento para garantir que todos os objetos sejam desalocados corretamente caso qualquer parte da criação falhe. Para encerrar o thread, chame [AfxEndThread](#afxendthread) de dentro do thread ou retorne da função de controle do thread de trabalho.

O multithreading deve ser habilitado pelo aplicativo; caso contrário, essa função falhará. Para obter mais informações sobre como habilitar multithreading, consulte [/MD,/MT,/LD (usar biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md).

Para obter mais informações sobre `AfxBeginThread`, consulte os artigos [multithreadinging: criando threads de trabalho](../../parallel/multithreading-creating-worker-threads.md) e [multithreading: criando threads de interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [CSocket:: Attach](../../mfc/reference/csocket-class.md#attach).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxcontextmenumanager"></a>AfxContextMenuManager

Ponteiro para o [Gerenciador de menu de contexto](ccontextmenumanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```cpp
CContextMenuManager* afxContextMenuManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcontextmenumanager. h

## <a name="afxendthread"></a>AfxEndThread

Chame essa função para encerrar o thread em execução no momento.

```cpp
void AFXAPI AfxEndThread(
    UINT nExitCode,
    BOOL bDelete  = TRUE);
```

### <a name="parameters"></a>parâmetros

\ *nExitCode*
Especifica o código de saída do thread.

\ *bDelete*
Exclui o objeto de thread da memória.

### <a name="remarks"></a>Comentários

Deve ser chamado de dentro do thread a ser encerrado.

Para obter mais informações sobre `AfxEndThread`, consulte o artigo [multithreadinging: terminando threads](../../parallel/multithreading-terminating-threads.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxfindresourcehandle"></a>AfxFindResourceHandle

Use `AfxFindResourceHandle` para percorrer a cadeia de recursos e localizar um recurso específico por ID de recurso e tipo de recurso.

### <a name="syntax"></a>Sintaxe

```cpp
HINSTANCE AFXAPI AfxFindResourceHandle( LPCTSTR lpszName,  LPCTSTR lpszType );
```

### <a name="parameters"></a>parâmetros

\ *lpszName*
Um ponteiro para uma cadeia de caracteres que contém a ID do recurso.
\ *lpszType*
Um ponteiro para o tipo de recurso. Para obter uma lista de tipos de recursos, consulte [FindResource](/windows/win32/api/winbase/nf-winbase-findresourcea) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Um identificador para o módulo que contém o recurso.

### <a name="remarks"></a>Comentários

`AfxFindResourceHandle` localiza o recurso específico e retorna um identificador para o módulo que contém o recurso. O recurso pode estar em qualquer DLL de extensão MFC carregada. `AfxFindResourceHandle` informa qual deles tem o recurso.

Os módulos são pesquisados nesta ordem:

1. O módulo principal, se for uma DLL de extensão do MFC.

1. Módulos que não são do sistema.

1. Módulos específicos de idioma.

1. O módulo principal, se for uma DLL do sistema.

1. Módulos do sistema.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="afxfreelibrary"></a>AfxFreeLibrary

Ambos `AfxFreeLibrary` e `AfxLoadLibrary` manter uma contagem de referência para cada módulo de biblioteca carregado.

```cpp
BOOL AFXAPI AfxFreeLibrary(HINSTANCE hInstLib);
```

### <a name="parameters"></a>parâmetros

\ *hInstLib*
Um identificador do módulo de biblioteca carregado. [AfxLoadLibrary](#afxloadlibrary) retorna esse identificador.

### <a name="return-value"></a>Valor retornado

TRUE se a função for realizada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`AfxFreeLibrary` decrementa a contagem de referência do módulo carregado da biblioteca de vínculo dinâmico (DLL). Quando a contagem de referência chega a zero, o módulo não é mapeado do espaço de endereço do processo de chamada e o identificador não é mais válido. Essa contagem de referência é incrementada a cada vez que `AfxLoadLibrary` é chamado.

Antes de remover o mapeamento de um módulo de biblioteca, o sistema permite que a DLL se desanexe dos processos que o utilizam. Isso dá ao DLL uma oportunidade de limpar os recursos alocados para o processo atual. Depois que a função de ponto de entrada retorna, o módulo de biblioteca é removido do espaço de endereço do processo atual.

Use `AfxLoadLibrary` para mapear um módulo DLL.

Certifique-se de usar `AfxFreeLibrary` e `AfxLoadLibrary` (em vez das funções do Win32 `FreeLibrary` e `LoadLibrary`) se seu aplicativo usar vários threads. O uso de `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e de desligamento que é executado quando a DLL de extensão do MFC é carregada e descarregado não corrompa o estado global do MFC.

### <a name="example"></a>Exemplo

Consulte o exemplo de [AfxLoadLibrary](#afxloadlibrary).

### <a name="requirements"></a>Requisitos

  Afxdll_ de **cabeçalho** . h

## <a name="afxgetapp"></a>AfxGetApp

O ponteiro retornado por essa função pode ser usado para acessar informações do aplicativo, como o código principal de expedição de mensagens ou a janela mais alta.

```cpp
CWinApp* AFXAPI AfxGetApp();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o único objeto de `CWinApp` para o aplicativo.

### <a name="remarks"></a>Comentários

Se esse método retornar NULL, isso poderá indicar que a janela principal do aplicativo ainda não foi totalmente inicializada. Ele também pode indicar um problema.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#126](../../mfc/reference/codesnippet/cpp/application-information-and-management_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxgetappname"></a>AfxGetAppName

A cadeia de caracteres retornada pode ser usada para mensagens de diagnóstico ou como uma raiz para nomes de cadeia de caracteres temporárias.

```cpp
LPCTSTR AFXAPI AfxGetAppName();
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres terminada em nulo que contém o nome do aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#127](../../mfc/reference/codesnippet/cpp/application-information-and-management_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxgetinstancehandle"></a>AfxGetInstanceHandle

Essa função permite que você recupere o identificador de instância do aplicativo atual.

```cpp
HINSTANCE  AFXAPI AfxGetInstanceHandle();
```

### <a name="return-value"></a>Valor retornado

Um HINSTANCE para a instância atual do aplicativo. Se chamado de dentro de uma DLL vinculada à versão USRDLL do MFC, um HINSTANCE para a DLL será retornado.

### <a name="remarks"></a>Comentários

`AfxGetInstanceHandle` sempre retorna o HINSTANCE do seu arquivo executável (. EXE) a menos que ele seja chamado de dentro de uma DLL vinculada à versão USRDLL do MFC. Nesse caso, ele retorna um HINSTANCE para a DLL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#128](../../mfc/reference/codesnippet/cpp/application-information-and-management_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxgetmainwnd"></a>AfxGetMainWnd

Se seu aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo. Use esse resultado em vez de fazer referência direta ao membro de [m_pMainWnd](../../mfc/reference/cwinthread-class.md#m_pmainwnd) do objeto de aplicativo.

```cpp
CWnd* AFXAPI AfxGetMainWnd();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o objeto de janela do quadro que contém o documento ativo no local, se o servidor tiver um objeto que está ativo no local dentro de um contêiner ativo.

Se não houver um objeto ativo no local dentro de um contêiner ou seu aplicativo não for um servidor OLE, essa função retornará a *m_pMainWnd* do seu objeto de aplicativo.

Se `AfxGetMainWnd` for chamado a partir do thread principal do aplicativo, ele retornará a janela principal do aplicativo de acordo com as regras acima. Se a função for chamada de um thread secundário no aplicativo, a função retornará a janela principal associada ao thread que fez a chamada.

### <a name="remarks"></a>Comentários

Se seu aplicativo não for um servidor OLE, chamar essa função será equivalente a fazer referência direta ao membro de *m_pMainWnd* do seu objeto de aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#129](../../mfc/reference/codesnippet/cpp/application-information-and-management_4.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxgetperuserregistration"></a>AfxGetPerUserRegistration

Use essa função para determinar se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** (**HKCU**).

```cpp
BOOL AFXAPI AfxGetPerUserRegistration();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que as informações do registro são direcionadas para o nó HKCU. FALSE indica que o aplicativo grava as informações do registro no nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="remarks"></a>Comentários

Se você habilitar o redirecionamento do registro, a estrutura redirecionará o acesso de **HKCR** para **HKEY_CURRENT_USER \software\classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.

Para alterar se o aplicativo redireciona o acesso ao registro, use [AfxSetPerUserRegistration](#afxsetperuserregistration).

### <a name="requirements"></a>Requisitos

  Afxstat_ de **cabeçalho** . h

## <a name="afxgetresourcehandle"></a>AfxGetResourceHandle

Use o identificador HINSTANCE retornado por essa função para acessar os recursos do aplicativo diretamente, por exemplo, em chamadas para a função do Windows `FindResource`.

```cpp
extern HINSTANCE  AfxGetResourceHandle();
```

### <a name="return-value"></a>Valor retornado

Um identificador de HINSTANCE em que os recursos padrão do aplicativo são carregados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#130](../../mfc/reference/codesnippet/cpp/application-information-and-management_5.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxgetthread"></a>AfxGetThread

Chame essa função para obter um ponteiro para o objeto [CWinThread](../../mfc/reference/cwinthread-class.md) que representa o thread em execução no momento.

```cpp
CWinThread* AfxGetThread();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para o thread em execução no momento; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Deve ser chamado de dentro do thread.

> [!NOTE]
> Se você estiver portando um projeto MFC chamando `AfxGetThread` das versões C++ 4,2, 5,0 ou 6,0 do Visual, `AfxGetThread` chamará [AfxGetApp](#afxgetapp) se nenhum thread for encontrado. Em versões mais recentes do compilador, `AfxGetThread` retornará NULL se nenhum thread for encontrado. Se você quiser o thread do aplicativo, deverá chamar `AfxGetApp`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#132](../../mfc/reference/codesnippet/cpp/application-information-and-management_6.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxinitrichedit"></a>AfxInitRichEdit

Chame essa função para inicializar o controle rich edit (versão 1,0) para o aplicativo.

```cpp
BOOL AFXAPI AfxInitRichEdit();
```

### <a name="remarks"></a>Comentários

Essa função é fornecida para compatibilidade com versões anteriores. Os novos aplicativos devem usar o [o AfxInitRichEdit2](#afxinitrichedit2).

`AfxInitRichEdit` carrega RICHED32. DLL para inicializar a versão 1,0 do controle de edição rico. Para usar a versão 2,0 e 3,0 do controle rich edit, RICHED20. A DLL precisa ser carregada. Ele é carregado fazendo uma chamada para [o AfxInitRichEdit2](#afxinitrichedit2).

Para atualizar os controles de edição avançados em C++ aplicativos visuais existentes para a versão 2,0, abra o. Arquivo RC como texto, altere o nome da classe de cada controle de edição rico de "RICHEDIT" para "RichEdit20a". Em seguida, substitua a chamada para `AfxInitRichEdit` por `AfxInitRichEdit2`.

Essa função também inicializa a biblioteca de controles comuns, se a biblioteca ainda não tiver sido inicializada para o processo. Se você usar o controle rich edit diretamente do aplicativo MFC, chame essa função para garantir que o MFC tenha inicializado corretamente o tempo de execução do controle de edição rico. Se você chamar o método `Create` de [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md)ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), normalmente não precisará chamar essa função, mas, em alguns casos, talvez seja necessário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxinitrichedit2"></a>O AfxInitRichEdit2

Chame essa função para inicializar o controle rich edit (versão 2,0 e posterior) para o aplicativo.

```cpp
BOOL AFXAPI AfxInitRichEdit2();
```

### <a name="remarks"></a>Comentários

Chame essa função para carregar o RICHED20. DLL e inicializar a versão 2,0 do controle de edição rico. Se você chamar o método `Create` de [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md)ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), normalmente não precisará chamar essa função, mas, em alguns casos, talvez seja necessário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxisextendedframeclass"></a>AfxIsExtendedFrameClass

Determina se a janela especificada é um objeto de quadro estendido.

### <a name="syntax"></a>Sintaxe

```cpp
BOOL AFXAPI AfxIsExtendedFrameClass( CWnd* pWnd );
```

### <a name="parameters"></a>parâmetros

\ *pWnd*
no Um ponteiro para um objeto derivado de `CWnd`.

### <a name="return-value"></a>Valor retornado

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

## <a name="afxismfctoolbar"></a>AfxIsMFCToolBar

Determina se a janela especificada é um objeto de barra de ferramentas.

### <a name="syntax"></a>Sintaxe

```cpp
BOOL AFXAPI AfxIsMFCToolBar(CWnd* pWnd);
```

### <a name="parameters"></a>parâmetros

\ *pWnd*
no Um ponteiro para um objeto derivado de `CWnd`.

### <a name="return-value"></a>Valor retornado

TRUE se a janela fornecida for um objeto Toolbar; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retorna `TRUE` se *pWnd* deriva de `CMFCToolBar`. Esse método é útil quando você precisa validar que um parâmetro de função ou método é um objeto `CMFCToolBar`.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXPRIV. h

## <a name="afxkeyboardmanager"></a>AfxKeyboardManager

Ponteiro para o [Gerenciador de teclado](ckeyboardmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```cpp
CKeyboardManager* afxKeyboardManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxkeyboardmanager. h

## <a name="afxloadlibrary"></a>AfxLoadLibrary

Use `AfxLoadLibrary` para mapear um módulo DLL.

```cpp
HINSTANCE AFXAPI AfxLoadLibrary(LPCTSTR lpszModuleName);
```

### <a name="parameters"></a>parâmetros

\ *lpszModuleName*
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do módulo (um. DLL ou. Arquivo EXE). O nome especificado é o nome do arquivo do módulo.

Se a cadeia de caracteres especificar um caminho, mas o arquivo não existir no diretório especificado, a função falhará.

Se um caminho não for especificado e a extensão de nome de arquivo for omitida, a extensão padrão. A DLL é anexada. No entanto, a cadeia de caracteres do nome do arquivo pode incluir um caractere de ponto à direita (.) para indicar que o nome do módulo não tem extensão. Quando nenhum caminho é especificado, a função usa a [ordem de pesquisa para aplicativos da área de trabalho](/windows/win32/dlls/dynamic-link-library-search-order#search-order-for-desktop-applications).

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será um identificador para o módulo. Em caso de falha, o valor de retorno é nulo.

### <a name="remarks"></a>Comentários

Ele retorna um identificador que pode ser usado em [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função DLL. `AfxLoadLibrary` também pode ser usado para mapear outros módulos executáveis.

Cada processo mantém uma contagem de referência para cada módulo de biblioteca carregado. Essa contagem de referência é incrementada a cada vez que `AfxLoadLibrary` é chamado e diminui cada vez que `AfxFreeLibrary` é chamado. Quando a contagem de referência chega a zero, o módulo não é mapeado do espaço de endereço do processo de chamada e o identificador não é mais válido.

Certifique-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez das funções do Win32 `LoadLibrary` e `FreeLibrary`) se seu aplicativo usar vários threads e se ele carregar dinamicamente uma DLL de extensão do MFC. Usar `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e de desligamento que é executado quando a DLL de extensão do MFC é carregada e descarregada não corrompe o estado global do MFC.

Usar `AfxLoadLibrary` em um aplicativo exige que você vincule dinamicamente à versão da DLL do MFC. O arquivo de cabeçalho para `AfxLoadLibrary`, Afxdll_. h, só será incluído se o MFC estiver vinculado ao aplicativo como uma DLL. Esse requisito é por design, porque você precisa vincular à versão de DLL do MFC para usar ou criar DLLs de extensão do MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_DLLUser#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_7.cpp)]
[!code-cpp[NVC_MFC_DLLUser#2](../../mfc/reference/codesnippet/cpp/application-information-and-management_8.cpp)]
[!code-cpp[NVC_MFC_DLLUser#3](../../mfc/reference/codesnippet/cpp/application-information-and-management_9.cpp)]

### <a name="requirements"></a>Requisitos

  Afxdll_ de **cabeçalho** . h

## <a name="afxloadlibraryex"></a>AfxLoadLibraryEx

Use `AfxLoadLibraryEx` para mapear um módulo DLL.

```cpp
HINSTANCE AFXAPI AfxLoadLibraryEx(LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);
```

### <a name="parameters"></a>parâmetros

\ *lpFileName*
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do módulo (um. DLL ou. Arquivo EXE). O nome especificado é o nome do arquivo do módulo.

Se a cadeia de caracteres especificar um caminho, mas o arquivo não existir no diretório especificado, a função falhará.

Se um caminho não for especificado e a extensão de nome de arquivo for omitida, a extensão padrão. A DLL é anexada. No entanto, a cadeia de caracteres do nome do arquivo pode incluir um caractere de ponto à direita (.) para indicar que o nome do módulo não tem extensão. Quando nenhum caminho é especificado, a função usa a [ordem de pesquisa para aplicativos da área de trabalho](/windows/win32/dlls/dynamic-link-library-search-order#search-order-for-desktop-applications).

\ *hFile*
Esse parâmetro é reservado para uso futuro. Ele deve ser nulo.

*dwFlags*\
A ação a ser tomada durante o carregamento do módulo. Se nenhum sinalizador for especificado, o comportamento dessa função será idêntico à função `AfxLoadLibrary`. Os valores possíveis desse parâmetro são descritos na documentação do [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) .

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será um identificador para o módulo. Em caso de falha, o valor de retorno é nulo.

### <a name="remarks"></a>Comentários

`AfxLoadLibraryEx` retorna um identificador que pode ser usado em [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função DLL. `AfxLoadLibraryEx` também pode ser usado para mapear outros módulos executáveis.

Cada processo mantém uma contagem de referência para cada módulo de biblioteca carregado. Essa contagem de referência é incrementada a cada vez que `AfxLoadLibraryEx` é chamado e diminui cada vez que `AfxFreeLibrary` é chamado. Quando a contagem de referência chega a zero, o módulo não é mapeado do espaço de endereço do processo de chamada e o identificador não é mais válido.

Certifique-se de usar `AfxLoadLibraryEx` e `AfxFreeLibrary` (em vez das funções do Win32 `LoadLibraryEx` e `FreeLibrary`) se seu aplicativo usar vários threads e se ele carregar dinamicamente uma DLL de extensão do MFC. O uso de `AfxLoadLibraryEx` e `AfxFreeLibrary` garante que o código de inicialização e de desligamento que é executado quando a DLL de extensão do MFC é carregada e descarregado não corrompa o estado global do MFC.

Usar `AfxLoadLibraryEx` em um aplicativo exige que você vincule dinamicamente à versão da DLL do MFC. O arquivo de cabeçalho para `AfxLoadLibraryEx`, Afxdll_. h, só será incluído se o MFC estiver vinculado ao aplicativo como uma DLL. Esse requisito é por design, porque você precisa vincular à versão de DLL do MFC para usar ou criar DLLs de extensão do MFC.

### <a name="requirements"></a>Requisitos

  Afxdll_ de **cabeçalho** . h

## <a name="afxmenutearoffmanager"></a>AfxMenuTearOffManager

Ponteiro para o [Gerenciador de menus destacável](cmenutearoffmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```cpp
CMenuTearOffManager* g_pTearOffMenuManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenutearoffmanager. h

## <a name="afxmousemanager"></a>AfxMouseManager

Ponteiro para o global [mouse Manager](cmousemanager-class.md).

### <a name="syntax"></a>Sintaxe

```cpp
CMouseManager* afxMouseManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmousemanager. h

## <a name="afxregisterclass"></a>AfxRegisterClass

Use essa função para registrar as classes de janela em uma DLL que usa MFC.

```cpp
BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass);
```

### <a name="parameters"></a>parâmetros

\ *lpWndClass*
Ponteiro para uma estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) que contém informações sobre a classe de janela a ser registrada. Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

### <a name="return-value"></a>Valor retornado

TRUE se a classe for registrada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se você usar essa função, a classe será desregistrada automaticamente quando a DLL for descarregada.

Em compilações não-DLL, o identificador de `AfxRegisterClass` é definido como uma macro que mapeia para a função do Windows `RegisterClass`, já que as classes registradas em um aplicativo são desregistradas automaticamente. Se você usar `AfxRegisterClass` em vez de `RegisterClass`, seu código poderá ser usado sem alterações em um aplicativo e em uma DLL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_DLL#3](../../atl-mfc-shared/codesnippet/cpp/application-information-and-management_10.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxregisterwndclass"></a>AfxRegisterWndClass

Permite que você registre suas próprias classes de janela.

```cpp
LPCTSTR AFXAPI AfxRegisterWndClass(
    UINT nClassStyle,
    HCURSOR hCursor = 0,
    HBRUSH hbrBackground = 0,
    HICON hIcon = 0);
```

### <a name="parameters"></a>parâmetros

\ *nClassStyle*
Especifica o estilo de classe do Windows ou a combinação de estilos, criada usando o operador bit **&#124;** -a-or () para a classe Window. Para obter uma lista de estilos de classe, consulte a estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) no SDK do Windows. Se for NULL, os padrões serão definidos da seguinte maneira:

- Define o estilo do mouse como CS_DBLCLKS, que envia mensagens de clique duplo para o procedimento de janela quando o usuário clica duas vezes no mouse.

- Define o estilo do cursor de seta como o IDC_ARROW padrão do Windows.

- Define o pincel de plano de fundo como nulo, portanto, a janela não apagará seu plano de fundo.

- Define o ícone para o ícone de logotipo padrão acenando do Windows.

\ *hCursor*
Especifica um identificador para o recurso de cursor a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, obterá o cursor de IDC_ARROW padrão.

\ *hbrBackground*
Especifica um identificador para o recurso de pincel a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, terá um pincel de plano de fundo nulo e, por padrão, sua janela não apagará seu plano de fundo durante o processamento de [WM_ERASEBKGND](/windows/win32/winmsg/wm-erasebkgnd).

\ *HICON*
Especifica um identificador para o recurso de ícone a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, obterá o ícone de logotipo padrão do Windows acenando-Flag.

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres terminada em nulo que contém o nome da classe. Você pode passar esse nome de classe para a função membro `Create` em `CWnd` ou outras classes derivadas de **CWnd**para criar uma janela. O nome é gerado pelo biblioteca MFC.

> [!NOTE]
> O valor de retorno é um ponteiro para um buffer estático. Para salvar essa cadeia de caracteres, atribua-a a uma variável `CString`.

### <a name="remarks"></a>Comentários

O biblioteca MFC automaticamente registra várias classes de janela padrão para você. Chame essa função se você quiser registrar suas próprias classes de janela.

O nome registrado para uma classe por `AfxRegisterWndClass` depende exclusivamente dos parâmetros. Se você chamar `AfxRegisterWndClass` várias vezes com parâmetros idênticos, ele registrará apenas uma classe na primeira chamada. Chamadas posteriores para `AfxRegisterWndClass` com parâmetros idênticos retornam o ClassName já registrado.

Se você chamar `AfxRegisterWndClass` para várias classes derivadas de CWnd com parâmetros idênticos, em vez de obter uma classe de janela separada para cada classe, cada classe compartilhará a mesma classe de janela. Esse compartilhamento poderá causar problemas se o estilo de classe de CS_CLASSDC for usado. Em vez de várias classes de janela CS_CLASSDC, você acaba com apenas uma classe de janela de CS_CLASSDC. Todas C++ as janelas que usam essa classe compartilham o mesmo DC. Para evitar esse problema, chame [AfxRegisterClass](#afxregisterclass) para registrar a classe.

Consulte a nota técnica [TN001: registro de classe de janela](../../mfc/tn001-window-class-registration.md) para obter mais informações sobre o registro de classe de janela e a função `AfxRegisterWndClass`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#134](../../mfc/reference/codesnippet/cpp/application-information-and-management_11.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxsetperuserregistration"></a>AfxSetPerUserRegistration

Define se o aplicativo redireciona o acesso do registro para o nó **HKEY_CURRENT_USER** (**HKCU**).

```cpp
void AFXAPI AfxSetPerUserRegistration(BOOL bEnable);
```

### <a name="parameters"></a>parâmetros

\ *bEnable*
no VERDADEIRO indica que as informações do registro são direcionadas para o nó HKCU. FALSE indica que o aplicativo grava as informações do registro no nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="remarks"></a>Comentários

Antes do Windows Vista, os aplicativos que acessaram o registro normalmente usaram o nó **HKEY_CLASSES_ROOT** . No entanto, com o Windows Vista ou sistemas operacionais posteriores, você deve executar um aplicativo no modo elevado para gravar em HKCR.

Esse método permite que seu aplicativo Leia e grave no registro sem executar no modo elevado. Ele funciona redirecionando o acesso ao registro de HKCR para HKCU. Para obter mais informações, consulte [páginas de propriedades do vinculador](../../build/reference/linker-property-pages.md).

Se você habilitar o redirecionamento do registro, a estrutura redirecionará o acesso de HKCR para **HKEY_CURRENT_USER \software\classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.

A implementação padrão acessa o registro em HKCR.

### <a name="requirements"></a>Requisitos

  Afxstat_ de **cabeçalho** . h

## <a name="afxsetresourcehandle"></a>AfxSetResourceHandle

Use essa função para definir o identificador HINSTANCE que determina onde os recursos padrão do aplicativo são carregados.

```cpp
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);
```

### <a name="parameters"></a>parâmetros

\ *hInstResource*
A instância ou o identificador de módulo para um. Arquivo EXE ou DLL do qual os recursos do aplicativo são carregados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#135](../../mfc/reference/codesnippet/cpp/application-information-and-management_12.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="afxshellmanager"></a>AfxShellManager

Ponteiro para o [Gerenciador de shell](cshellmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```cpp
CShellManager* afxShellManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshellmanager. h

## <a name="afxsocketinit"></a>AfxSocketInit

Chame essa função em seu `CWinApp::InitInstance` substituir para inicializar o Windows Sockets.

```cpp
BOOL AfxSocketInit(WSADATA* lpwsaData = NULL);
```

### <a name="parameters"></a>parâmetros

\ *lpwsaData*
Um ponteiro para uma estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) . Se *lpwsaData* não for igual a NULL, o endereço da estrutura de `WSADATA` será preenchido pela chamada para `WSAStartup`. Essa função também garante que `WSACleanup` seja chamado para você antes de o aplicativo ser encerrado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ao usar soquetes do MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado apenas no thread principal.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AfxSock. h

## <a name="afxusertoolsmanager"></a>AfxUserToolsManager

Ponteiro para o [gerente de ferramentas de usuário](cusertoolsmanager-class.md)global.

### <a name="syntax"></a>Sintaxe

```cpp
CUserToolsManager* afxUserToolsManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertoolsmanager. h

## <a name="afxwininit"></a>AfxWinInit

Essa função é chamada pela função de `WinMain` fornecida pelo MFC, como parte da inicialização [CWinApp](../../mfc/reference/cwinapp-class.md) de um aplicativo baseado em GUI, para inicializar o MFC.

```cpp
BOOL AFXAPI AfxWinInit(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine,
    int nCmdShow);
```

### <a name="parameters"></a>parâmetros

\ *HINSTANCE*
O identificador do módulo em execução no momento.

\ *hPrevInstance*
Um identificador para uma instância anterior do aplicativo. Para um aplicativo baseado em Win32, esse parâmetro é sempre **nulo**.

\ *lpCmdLine*
Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo.

\ *nCmdShow*
Especifica como a janela principal de um aplicativo de GUI seria mostrada.

### <a name="remarks"></a>Comentários

Para um aplicativo de console, que não usa a função de `WinMain` fornecida pelo MFC, você deve chamar `AfxWinInit` diretamente para inicializar o MFC.

Se você chamar `AfxWinInit` você mesmo, deverá declarar uma instância de uma classe `CWinApp`. Para um aplicativo de console, você pode optar por não derivar sua própria classe de `CWinApp` e, em vez disso, usar uma instância do `CWinApp` diretamente. Essa técnica é apropriada se você decidir deixar toda a funcionalidade para seu aplicativo em sua implementação de **principal**.

> [!NOTE]
> Quando ele cria um contexto de ativação para um assembly, o MFC usa um recurso de manifesto fornecido pelo módulo do usuário. O contexto de ativação é criado no `AfxWinInit`. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../../mfc/support-for-activation-contexts-in-the-mfc-module-state.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_AfxWinInit#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_13.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)\
\ [classe CWinApp](cwinapp-class.md)
\ [classe CContextMenuManager](ccontextmenumanager-class.md)
\ [classe CWnd](cwnd-class.md)
\ [Classe CFrameWndEx](cframewndex-class.md)
\ [Classe CMFCToolBar](cmfctoolbar-class.md)
\ [Classe CKeyboardManager](ckeyboardmanager-class.md)
\ [classe CMenuTearOffManager](cmenutearoffmanager-class.md)
\ [classe CMouseManager](cmousemanager-class.md)
\ [classe CShellManager](cshellmanager-class.md)
[Classe CUserToolsManager](cusertoolsmanager-class.md)
