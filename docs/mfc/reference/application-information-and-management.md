---
title: Informações e gerenciamento do aplicativo
description: Referência às funções de gerenciamento e informações de aplicativos da Biblioteca de Classe da Microsoft Foundation (MFC).
ms.date: 01/27/2020
helpviewer_keywords:
- applications [MFC], managing
ms.assetid: b72f4154-24db-4e75-bca3-6873e2459c15
ms.openlocfilehash: fc0b4b09f6c48da68bebe4a2825f49bcf6ab7e23
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372494"
---
# <a name="application-information-and-management"></a>Informações e gerenciamento do aplicativo

Quando você escreve um aplicativo, você cria um único objeto derivado do [CWinApp.](../../mfc/reference/cwinapp-class.md) Às vezes, você pode querer obter informações `CWinApp`sobre este objeto de fora do objeto derivado. Ou você pode precisar de acesso a outros objetos globais de "gerente".

A Biblioteca de Classes da Microsoft Foundation fornece as seguintes funções globais para ajudá-lo a realizar essas tarefas:

## <a name="application-information-and-management-functions"></a>Informações de aplicativos e funções de gerenciamento

|||
|-|-|
|[AfxBeginThread](#afxbeginthread)|Cria um novo fio.|
|[AfxContextMenuManager](#afxcontextmenumanager)|Pointer para o [gerenciador de menus de contexto global](ccontextmenumanager-class.md).|
|[AfxEndThread](#afxendthread)|Termina o segmento atual.|
|[AfxFindResourceHandle](#afxfindresourcehandle)|Caminha pela cadeia de recursos e localiza um recurso específico por ID de recurso e tipo de recurso. |
|[AfxFreeLibrary](#afxfreelibrary)|Decreta a contagem de referência do módulo DLL (Dynamic-Link Library, biblioteca de link dinâmico carregado). Quando a contagem de referência atinge zero, o módulo é não mapeado.|
|[AfxGetApp](#afxgetapp)|Retorna um ponteiro para o `CWinApp` único objeto do aplicativo.|
|[AfxGetAppName](#afxgetappname)|Retorna uma seqüência que contém o nome do aplicativo.|
|[AfxGetInstanceHandle](#afxgetinstancehandle)|Retorna um HINSTANCE representando esta instância do aplicativo.|
|[AfxGetMainWnd](#afxgetmainwnd)|Retorna um ponteiro para a janela "principal" atual de um aplicativo não-OLE ou a janela de quadro no lugar de um aplicativo de servidor.|
|[AfxGetPerUserRegistration](#afxgetperuserregistration)|Use esta função para determinar se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** (**HKCU).**|
|[AfxGetResourceHandle](#afxgetresourcehandle)|Retorna um HINSTANCE à fonte dos recursos padrão do aplicativo. Use para acessar os recursos do aplicativo diretamente.|
|[AfxGetThread](#afxgetthread)|Recupera um ponteiro para o objeto [CWinThread](../../mfc/reference/cwinthread-class.md) atual.|
|[AfxInitRichEdit](#afxinitrichedit)|Inicializa o controle de edição rico versão 1.0 para o aplicativo.|
|[AfxInitRichEdit2](#afxinitrichedit2)|Inicializa a versão 2.0 e depois rico controle de edição para o aplicativo.|
|[AfxIsExtendedFrameClass](#afxisextendedframeclass)|Determina se a janela dada é um objeto de quadro estendido.|
|[AfxIsMFCToolBar](#afxismfctoolbar)|Determina se a janela dada é um objeto de barra de ferramentas.|
|[AfxKeyboardManager](#afxkeyboardmanager)|Ponteiro para o [gerenciador](ckeyboardmanager-class.md)global de teclado .|
|[AfxLoadLibrary](#afxloadlibrary)|Mapeie um módulo DLL e retorna uma alça que pode ser usada para obter o endereço de uma função DLL.|
|[AfxLoadLibraryEx](#afxloadlibraryex)|Mapeie um módulo DLL usando as opções especificadas e retorna uma alça que pode ser usada para obter o endereço de uma função DLL.|
|[AfxMenuTearOffManager](#afxmenutearoffmanager)|Ponteiro para o [gerenciador de menu sumido global](cmenutearoffmanager-class.md).|
|[AfxMouseManager](#afxmousemanager)|Ponteiro para o gerenciador global de [mouses](cmousemanager-class.md).|
|[AfxRegisterClass](#afxregisterclass)|Registra uma classe de janela em uma DLL que usa MFC.|
|[AfxRegisterWndClass](#afxregisterwndclass)|Registra uma classe de janela do Windows para complementar as registradas automaticamente pelo MFC.|
|[AfxSetPerUserRegistration](#afxsetperuserregistration)|Define se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** **(HKCU).**|
|[AfxSetResourceHandle](#afxsetresourcehandle)|Define o cabo HINSTANCE onde os recursos padrão do aplicativo são carregados.|
|[AfxShellManager](#afxshellmanager)|Ponteiro para o gerente global [de shell](cshellmanager-class.md). |
|[AfxSocketInit](#afxsocketinit)|Chamado em `CWinApp::InitInstance` uma substituição para inicializar soquetes do Windows.|
|[AfxUserToolsManager](#afxusertoolsmanager)|Ponteiro para o [gerenciador](cusertoolsmanager-class.md)global de ferramentas de usuário .|
|[AfxWinInit](#afxwininit)|Chamado pela função fornecida `WinMain` pelo MFC, como parte da inicialização do [CWinApp](../../mfc/reference/cwinapp-class.md) de um aplicativo baseado em GUI, para inicializar o MFC. Deve ser chamado diretamente para aplicativos de console que usam MFC.|

## <a name="afxbeginthread"></a><a name="afxbeginthread"></a>Afxbeginthread

Chame esta função para criar um novo segmento.

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

### <a name="parameters"></a>Parâmetros

*pfnThreadProc*\
Aponta para a função de controle para o fio do trabalhador. O ponteiro não pode ser NULO. Esta função deve ser declarada da seguinte forma:

`UINT __cdecl MyControllingFunction( LPVOID pParam );`

*pThreadClass*\
A RUNTIME_CLASS de um objeto derivado de [CWinThread](../../mfc/reference/cwinthread-class.md).

*pParam*\
Parâmetro para passar para a função de controle.

*nPrioridade*\
A prioridade para definir para o segmento. Para obter uma lista completa e descrição das prioridades disponíveis, consulte [SetThreadPriority](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) no SDK do Windows.

*nStackSize*\
Especifica o tamanho em bytes da pilha para o novo segmento. Se 0, o tamanho da pilha é padrão para a mesma pilha de tamanho que o segmento de criação.

*dwCreateFlags*\
Especifica uma bandeira adicional que controla a criação do segmento. Esta bandeira pode conter um dos dois valores:

- CREATE_SUSPENDED Inicie a linha com uma contagem de suspensão de um. Use CREATE_SUSPENDED se quiser inicializar quaisquer `CWinThread` dados membros do objeto, como [m_bAutoDelete](../../mfc/reference/cwinthread-class.md#m_bautodelete) ou quaisquer membros da sua classe derivada, antes que o segmento comece a ser executado. Uma vez que sua inicialização esteja concluída, use [CWinThread::ResumeThread](../../mfc/reference/cwinthread-class.md#resumethread) para iniciar a execução do segmento. O fio não será `CWinThread::ResumeThread` executado até que seja chamado.

- **0** Inicie o segmento imediatamente após a criação.

*lpSecurityAttrs*\
Aponta para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica os atributos de segurança para o segmento. Se NULL, os mesmos atributos de segurança que o segmento de criação são usados. Para obter mais informações sobre esta estrutura, consulte o Windows SDK.

### <a name="return-value"></a>Valor retornado

Ponteiro para o objeto de rosca recém-criado ou NULL se ocorrer uma falha.

### <a name="remarks"></a>Comentários

A primeira `AfxBeginThread` forma de criar um fio de trabalhador. O segundo formulário cria um segmento que pode servir como um segmento de interface de usuário ou como um segmento de trabalhador.

`AfxBeginThread`cria um `CWinThread` novo objeto, chama sua função [CreateThread](../../mfc/reference/cwinthread-class.md#createthread) para começar a executar o segmento e retorna um ponteiro para o segmento. Verificações são feitas durante todo o procedimento para garantir que todos os objetos sejam desalocados corretamente caso qualquer parte da criação falhe. Para finalizar o segmento, chame [AfxEndThread](#afxendthread) de dentro do segmento ou retorne da função de controle do segmento do trabalhador.

A multithreading deve ser habilitada pelo aplicativo; caso contrário, esta função falhará. Para obter mais informações sobre como ativar multithreading, consulte [/MD, /MT, /LD (Use biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md).

Para obter `AfxBeginThread`mais informações sobre , consulte os artigos [Multithreading: Criando Threads do trabalhador](../../parallel/multithreading-creating-worker-threads.md) e [Multithreading: Criando threads de interface de usuário](../../parallel/multithreading-creating-user-interface-threads.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [CSocket::Attach](../../mfc/reference/csocket-class.md#attach).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxcontextmenumanager"></a><a name="afxcontextmenumanager"></a>AfxContextMenuManager

Pointer para o [gerenciador de menus de contexto global](ccontextmenumanager-class.md).

### <a name="syntax"></a>Sintaxe

```cpp
CContextMenuManager* afxContextMenuManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcontextmenumanager.h

## <a name="afxendthread"></a><a name="afxendthread"></a>Afxendthread

Chame esta função para terminar o segmento de execução atualmente.

```cpp
void AFXAPI AfxEndThread(
    UINT nExitCode,
    BOOL bDelete  = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nExitCode*\
Especifica o código de saída do segmento.

*bDelete*\
Exclui o objeto de segmento da memória.

### <a name="remarks"></a>Comentários

Deve ser chamado de dentro do fio para ser encerrado.

Para obter `AfxEndThread`mais informações, consulte o artigo [Multithreading: Terminando os segmentos](../../parallel/multithreading-terminating-threads.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxfindresourcehandle"></a><a name="afxfindresourcehandle"></a>Afxfindresourcehandle

Use `AfxFindResourceHandle` para andar na cadeia de recursos e localizar um recurso específico por ID de recurso e tipo de recurso.

### <a name="syntax"></a>Sintaxe

```cpp
HINSTANCE AFXAPI AfxFindResourceHandle( LPCTSTR lpszName,  LPCTSTR lpszType );
```

### <a name="parameters"></a>Parâmetros

*Lpszname*\
Um ponteiro para uma seqüência contendo o ID de recurso.
*lpszType*\
Um ponteiro para o tipo de recurso. Para obter uma lista de tipos de recursos, consulte [FindResource](/windows/win32/api/winbase/nf-winbase-findresourcea) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Uma alça para o módulo que contém o recurso.

### <a name="remarks"></a>Comentários

`AfxFindResourceHandle`encontra o recurso específico e retorna uma alça para o módulo que contém o recurso. O recurso pode estar em qualquer dll de extensão MFC que esteja carregada. `AfxFindResourceHandle`diz qual deles tem o recurso.

Os módulos são pesquisados nesta ordem:

1. O módulo principal, se for um DLL de extensão MFC.

1. Módulos não-sistema.

1. Módulos específicos do idioma.

1. O módulo principal, se for um sistema DLL.

1. Módulos do sistema.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="afxfreelibrary"></a><a name="afxfreelibrary"></a>Afxfreelibrary

Ambos `AfxFreeLibrary` `AfxLoadLibrary` e manter uma contagem de referência para cada módulo de biblioteca carregado.

```cpp
BOOL AFXAPI AfxFreeLibrary(HINSTANCE hInstLib);
```

### <a name="parameters"></a>Parâmetros

*hInstLib*\
Uma alça do módulo de biblioteca carregado. [AfxLoadLibrary](#afxloadlibrary) retorna este cabo.

### <a name="return-value"></a>Valor retornado

VERDADE se a função for bem sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`AfxFreeLibrary`decreta a contagem de referência do módulo DLL (Dynamic-Link Library, biblioteca de link dinâmico carregado). Quando a contagem de referência atinge zero, o módulo é desmapeado do espaço de endereço do processo de chamada e a alça não é mais válida. Esta contagem de referência `AfxLoadLibrary` é incrementada cada vez que é chamada.

Antes de desmapear um módulo de biblioteca, o sistema permite que a DLL se desconecte dos processos que o utilizam. Isso dá ao DLL a oportunidade de limpar os recursos alocados para o processo atual. Após o retorno da função de ponto de entrada, o módulo da biblioteca é removido do espaço de endereço do processo atual.

Use `AfxLoadLibrary` para mapear um módulo DLL.

Certifique-se `AfxFreeLibrary` de `AfxLoadLibrary` usar e (em vez `FreeLibrary` `LoadLibrary`das funções Win32 e ) se o aplicativo usar vários threads. O `AfxLoadLibrary` `AfxFreeLibrary` uso e garante que o código de inicialização e desligamento que é executado quando a DLL de extensão MFC é carregada e descarregada não corrompe o estado Global De MFC.

### <a name="example"></a>Exemplo

Veja o exemplo [de AfxLoadLibrary](#afxloadlibrary).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdll_.h

## <a name="afxgetapp"></a><a name="afxgetapp"></a>Afxgetapp

O ponteiro retornado por esta função pode ser usado para acessar informações do aplicativo, como o código principal de despacho de mensagens ou a janela superior.

```cpp
CWinApp* AFXAPI AfxGetApp();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `CWinApp` o único objeto para a aplicação.

### <a name="remarks"></a>Comentários

Se este método retornar NULL, pode indicar que a janela principal da aplicação ainda não foi totalmente inicializada. Também pode indicar um problema.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#126](../../mfc/reference/codesnippet/cpp/application-information-and-management_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxgetappname"></a><a name="afxgetappname"></a>Afxgetappname

A seqüência retornada pode ser usada para mensagens de diagnóstico ou como uma raiz para nomes temporários de strings.

```cpp
LPCTSTR AFXAPI AfxGetAppName();
```

### <a name="return-value"></a>Valor retornado

Uma seqüência de terminadas nula contendo o nome do aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#127](../../mfc/reference/codesnippet/cpp/application-information-and-management_2.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxgetinstancehandle"></a><a name="afxgetinstancehandle"></a>Afxgetinstancehandle

Esta função permite que você recupere o cabo de ocorrência do aplicativo atual.

```cpp
HINSTANCE  AFXAPI AfxGetInstanceHandle();
```

### <a name="return-value"></a>Valor retornado

Um HINSTANCE para a instância atual do aplicativo. Se chamado de dentro de uma DLL vinculada à versão USRDLL do MFC, um HINSTANCE para a DLL é retornado.

### <a name="remarks"></a>Comentários

`AfxGetInstanceHandle`sempre retorna o HINSTANCE do seu arquivo executável (. EXE) a menos que seja chamado de dentro de uma DLL vinculada à versão USRDLL do MFC. Neste caso, ele retorna um HINSTANCE para a DLL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#128](../../mfc/reference/codesnippet/cpp/application-information-and-management_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxgetmainwnd"></a><a name="afxgetmainwnd"></a>Afxgetmainwnd

Se o aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo. Use este resultado em vez de se referir diretamente ao [membro m_pMainWnd](../../mfc/reference/cwinthread-class.md#m_pmainwnd) do objeto de aplicação.

```cpp
CWnd* AFXAPI AfxGetMainWnd();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o objeto da janela do quadro que contém o documento ativo no local, se o servidor tiver um objeto ativo no local dentro de um contêiner ativo.

Se não houver nenhum objeto ativo no local dentro de um contêiner ou seu aplicativo não for um servidor OLE, essa função retorna o *m_pMainWnd* do objeto do aplicativo.

Se `AfxGetMainWnd` for chamado do segmento principal do aplicativo, ele retorna a janela principal do aplicativo de acordo com as regras acima. Se a função for chamada a partir de um segmento secundário no aplicativo, a função retorna a janela principal associada ao segmento que fez a chamada.

### <a name="remarks"></a>Comentários

Se o seu aplicativo não for um servidor OLE, então chamar essa função é equivalente a se referir diretamente ao *membro m_pMainWnd* do objeto do aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#129](../../mfc/reference/codesnippet/cpp/application-information-and-management_4.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxgetperuserregistration"></a><a name="afxgetperuserregistration"></a>Registro de usuário afxGetPeruser

Use esta função para determinar se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** (**HKCU).**

```cpp
BOOL AFXAPI AfxGetPerUserRegistration();
```

### <a name="return-value"></a>Valor retornado

TRUE indica que as informações do registro são direcionadas ao nó HKCU. FALSE indica que o aplicativo grava informações de registro para o nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="remarks"></a>Comentários

Se você habilitar o redirecionamento do registro, a estrutura redirecionará o acesso do **HKCR** para **HKEY_CURRENT_USER\Software\Classes**. Apenas as estruturas MFC e ATL são afetadas pelo redirecionamento.

Para alterar se o aplicativo redireciona o acesso ao registro, use [AfxSetPerUserRegistration](#afxsetperuserregistration).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxstat_.h

## <a name="afxgetresourcehandle"></a><a name="afxgetresourcehandle"></a>Afxgetresourcehandle

Use a alça HINSTANCE retornada por esta função para acessar os recursos do `FindResource`aplicativo diretamente, por exemplo, em chamadas para a função Windows .

```cpp
extern HINSTANCE  AfxGetResourceHandle();
```

### <a name="return-value"></a>Valor retornado

Uma alça HINSTANCE onde os recursos padrão do aplicativo são carregados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#130](../../mfc/reference/codesnippet/cpp/application-information-and-management_5.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxgetthread"></a><a name="afxgetthread"></a>AfxGetThread

Chame esta função para obter um ponteiro para o objeto [CWinThread](../../mfc/reference/cwinthread-class.md) representando o segmento em execução no momento.

```cpp
CWinThread* AfxGetThread();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para o segmento de execução atualmente; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Deve ser chamado de dentro do fio.

> [!NOTE]
> Se você estiver portando um `AfxGetThread` projeto de MFC ligando das versões 4.2, 5.0 ou 6.0 do Visual C++, `AfxGetThread` ligue para o [AfxGetApp](#afxgetapp) se nenhum segmento for encontrado. Nas versões mais recentes `AfxGetThread` do compilador, retorna NULL se nenhum segmento foi encontrado. Se você quiser o segmento `AfxGetApp`de aplicativo, você deve chamar .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#132](../../mfc/reference/codesnippet/cpp/application-information-and-management_6.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxinitrichedit"></a><a name="afxinitrichedit"></a>Afxinitrichedit

Chame esta função para inicializar o rico controle de edição (versão 1.0) para o aplicativo.

```cpp
BOOL AFXAPI AfxInitRichEdit();
```

### <a name="remarks"></a>Comentários

Esta função é fornecida para compatibilidade retrógrada. Novos aplicativos devem usar [AfxInitRichEdit2](#afxinitrichedit2).

`AfxInitRichEdit`cargas RICHED32. DLL para inicializar a versão 1.0 do rico controle de edição. Para usar as versões 2.0 e 3.0 do rico controle de edição, RICHED20. A LLA precisa ser carregada. Ele é carregado fazendo uma chamada para [AfxInitRichEdit2](#afxinitrichedit2).

Para atualizar os controles de edição ricos nos aplicativos Visuais C++ existentes para a versão 2.0, abra o . Arquivo RC como texto, altere o nome de classe de cada controle de edição rico de "RICHEDIT" para "RichEdit20a". Em seguida, `AfxInitRichEdit` substitua a chamada para . `AfxInitRichEdit2`

Essa função também inicializa a biblioteca de controles comuns, caso a biblioteca ainda não tenha sido inicializada para o processo. Se você usar o rico controle de edição diretamente do seu aplicativo MFC, chame esta função para garantir que o MFC tenha inicializado corretamente o rico tempo de execução do controle de edição. Se você `Create` chamar o método de [CRichEditCtrl,](../../mfc/reference/cricheditctrl-class.md) [CRichEditView](../../mfc/reference/cricheditview-class.md)ou [CRichEditDoc,](../../mfc/reference/cricheditdoc-class.md)você normalmente não precisa chamar essa função, mas em alguns casos pode ser necessário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxinitrichedit2"></a><a name="afxinitrichedit2"></a>AfxInitRichEdit2

Chame esta função para inicializar o rico controle de edição (versão 2.0 e posterior) para o aplicativo.

```cpp
BOOL AFXAPI AfxInitRichEdit2();
```

### <a name="remarks"></a>Comentários

Ligue para esta função para carregar o RICHED20. DLL e inicializar a versão 2.0 do rico controle de edição. Se você `Create` chamar o método de [CRichEditCtrl,](../../mfc/reference/cricheditctrl-class.md) [CRichEditView](../../mfc/reference/cricheditview-class.md)ou [CRichEditDoc,](../../mfc/reference/cricheditdoc-class.md)você normalmente não precisa chamar essa função, mas em alguns casos pode ser necessário.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxisextendedframeclass"></a><a name="afxisextendedframeclass"></a>AfxIsExtendedFrameClass

Determina se a janela dada é um objeto de quadro estendido.

### <a name="syntax"></a>Sintaxe

```cpp
BOOL AFXAPI AfxIsExtendedFrameClass( CWnd* pWnd );
```

### <a name="parameters"></a>Parâmetros

*Pwnd*\
[em] Um ponteiro para um objeto `CWnd`derivado de .

### <a name="return-value"></a>Valor retornado

TRUE se a janela fornecida for um objeto de quadro estendido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método retorna TRUE se *pWnd* deriva de uma das seguintes classes:

- `CFrameWndEx`

- `CMDIFrameWndEx`

- `COleIPFrameWndEx`

- `COleDocIPFrameWndEx`

- `CMDIChildWndEx`

Este método é útil quando você tem que validar que um parâmetro de função ou método é uma janela de quadro estendida.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpriv.h

## <a name="afxismfctoolbar"></a><a name="afxismfctoolbar"></a>AfxIsmFCToolBar

Determina se a janela dada é um objeto de barra de ferramentas.

### <a name="syntax"></a>Sintaxe

```cpp
BOOL AFXAPI AfxIsMFCToolBar(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*\
[em] Um ponteiro para um objeto `CWnd`derivado de .

### <a name="return-value"></a>Valor retornado

TRUE se a janela fornecida for um objeto de barra de ferramentas; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método `TRUE` retorna se o `CMFCToolBar` *pWnd* deriva de . Este método é útil quando você tem que validar `CMFCToolBar` que um parâmetro de função ou método é um objeto.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpriv.h

## <a name="afxkeyboardmanager"></a><a name="afxkeyboardmanager"></a>AfxKeyboardManager

Ponteiro para o [gerenciador](ckeyboardmanager-class.md)global de teclado .

### <a name="syntax"></a>Sintaxe

```cpp
CKeyboardManager* afxKeyboardManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxkeyboardmanager.h

## <a name="afxloadlibrary"></a><a name="afxloadlibrary"></a>Afxloadlibrary

Use `AfxLoadLibrary` para mapear um módulo DLL.

```cpp
HINSTANCE AFXAPI AfxLoadLibrary(LPCTSTR lpszModuleName);
```

### <a name="parameters"></a>Parâmetros

*lpszModuleName*\
Aponta para uma seqüência de terminação nula que contém o nome do módulo (a . DLL ou . Arquivo EXE). O nome especificado é o nome de arquivo do módulo.

Se a seqüência especificar um caminho, mas o arquivo não existir no diretório especificado, a função falhará.

Se um caminho não for especificado e a extensão do nome do arquivo for omitida, a extensão padrão . DLL é anexado. No entanto, a seqüência de nome de arquivo pode incluir um caractere de ponto de arrasto (.) para indicar que o nome do módulo não tem extensão. Quando nenhum caminho é especificado, a função usa a [Ordem de pesquisa para aplicativos de desktop](/windows/win32/dlls/dynamic-link-library-search-order#search-order-for-desktop-applications).

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será uma alça para o módulo. Na falha, o valor de devolução é NULO.

### <a name="remarks"></a>Comentários

Ele retorna uma alça que pode ser usada no [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função DLL. `AfxLoadLibrary`também pode ser usado para mapear outros módulos executáveis.

Cada processo mantém uma contagem de referência para cada módulo de biblioteca carregado. Esta contagem de referência `AfxLoadLibrary` é incrementada cada vez `AfxFreeLibrary` que é chamada e é decrementada cada vez que é chamada. Quando a contagem de referência atinge zero, o módulo é desmapeado do espaço de endereço do processo de chamada e a alça não é mais válida.

Certifique-se `AfxLoadLibrary` de `AfxFreeLibrary` usar e (em vez `LoadLibrary` `FreeLibrary`das funções Win32 e ) se o aplicativo usar vários threads e se ele carregar dinamicamente uma DLL de extensão MFC. O `AfxLoadLibrary` `AfxFreeLibrary` uso e assuma que o código de inicialização e desligamento que é executado quando a DLL de extensão MFC é carregada e descarregada não corrompe o estado Global MFC.

O `AfxLoadLibrary` uso em um aplicativo requer que você vincule dinamicamente à versão DLL do MFC. O arquivo `AfxLoadLibrary`de cabeçalho para , Afxdll_.h, só é incluído se o MFC estiver vinculado ao aplicativo como um DLL. Este requisito é por design, porque você tem que vincular à versão DLL do MFC para usar ou criar DLLs de extensão MFC.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_DLLUser#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_7.cpp)]
[!code-cpp[NVC_MFC_DLLUser#2](../../mfc/reference/codesnippet/cpp/application-information-and-management_8.cpp)]
[!code-cpp[NVC_MFC_DLLUser#3](../../mfc/reference/codesnippet/cpp/application-information-and-management_9.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdll_.h

## <a name="afxloadlibraryex"></a><a name="afxloadlibraryex"></a>AfxLoadLibraryEx

Use `AfxLoadLibraryEx` para mapear um módulo DLL.

```cpp
HINSTANCE AFXAPI AfxLoadLibraryEx(LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*Lpfilename*\
Aponta para uma seqüência de terminação nula que contém o nome do módulo (a . DLL ou . Arquivo EXE). O nome especificado é o nome de arquivo do módulo.

Se a seqüência especificar um caminho, mas o arquivo não existir no diretório especificado, a função falhará.

Se um caminho não for especificado e a extensão do nome do arquivo for omitida, a extensão padrão . DLL é anexado. No entanto, a seqüência de nome de arquivo pode incluir um caractere de ponto de arrasto (.) para indicar que o nome do módulo não tem extensão. Quando nenhum caminho é especificado, a função usa a [Ordem de pesquisa para aplicativos de desktop](/windows/win32/dlls/dynamic-link-library-search-order#search-order-for-desktop-applications).

*Hfile*\
Esse parâmetro é reservado para uso futuro. Deve ser NULO.

*Dwflags*\
A ação a ser tomada ao carregar o módulo. Se não forem especificados sinalizadores, o `AfxLoadLibrary` comportamento desta função é idêntico à função. Os valores possíveis deste parâmetro estão descritos na documentação [LoadLibraryEx.](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será uma alça para o módulo. Na falha, o valor de devolução é NULO.

### <a name="remarks"></a>Comentários

`AfxLoadLibraryEx`retorna uma alça que pode ser usada no [GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) para obter o endereço de uma função DLL. `AfxLoadLibraryEx`também pode ser usado para mapear outros módulos executáveis.

Cada processo mantém uma contagem de referência para cada módulo de biblioteca carregado. Esta contagem de referência `AfxLoadLibraryEx` é incrementada cada vez `AfxFreeLibrary` que é chamada e é decrementada cada vez que é chamada. Quando a contagem de referência atinge zero, o módulo é desmapeado do espaço de endereço do processo de chamada e a alça não é mais válida.

Certifique-se `AfxLoadLibraryEx` de `AfxFreeLibrary` usar e (em vez `LoadLibraryEx` `FreeLibrary`das funções Win32 e ) se o aplicativo usar vários threads e se ele carregar dinamicamente uma DLL de extensão MFC. O `AfxLoadLibraryEx` `AfxFreeLibrary` uso e garante que o código de inicialização e desligamento que é executado quando a DLL de extensão MFC é carregada e descarregada não corrompe o estado Global De MFC.

O `AfxLoadLibraryEx` uso em um aplicativo requer que você vincule dinamicamente à versão DLL do MFC. O arquivo `AfxLoadLibraryEx`de cabeçalho para , Afxdll_.h, só é incluído se o MFC estiver vinculado ao aplicativo como um DLL. Este requisito é por design, porque você tem que vincular à versão DLL do MFC para usar ou criar DLLs de extensão MFC.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdll_.h

## <a name="afxmenutearoffmanager"></a><a name="afxmenutearoffmanager"></a>AfxMenuTearOffManager

Ponteiro para o [gerenciador de menu sumido global](cmenutearoffmanager-class.md).

### <a name="syntax"></a>Sintaxe

```cpp
CMenuTearOffManager* g_pTearOffMenuManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenutearoffmanager.h

## <a name="afxmousemanager"></a><a name="afxmousemanager"></a>AfxMouseManager

Ponteiro para o gerenciador global de [mouses](cmousemanager-class.md).

### <a name="syntax"></a>Sintaxe

```cpp
CMouseManager* afxMouseManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmousemanager.h

## <a name="afxregisterclass"></a><a name="afxregisterclass"></a>Afxregisterclass

Use esta função para registrar classes de janela em uma DLL que usa MFC.

```cpp
BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass);
```

### <a name="parameters"></a>Parâmetros

*lpWndClass*\
Ponteiro para uma estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) contendo informações sobre a classe da janela a ser registrada. Para obter mais informações sobre esta estrutura, consulte o Windows SDK.

### <a name="return-value"></a>Valor retornado

TRUE se a classe for registrada com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se você usar esta função, a classe não será registrada automaticamente quando a DLL for descarregada.

Em compilações não-DLL, o `AfxRegisterClass` identificador é definido como `RegisterClass`uma macro que mapeia para a função Windows, uma vez que as classes registradas em um aplicativo são automaticamente não registradas. Se você `AfxRegisterClass` usar `RegisterClass`em vez de , seu código pode ser usado sem alteração tanto em um aplicativo quanto em uma DLL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_DLL#3](../../atl-mfc-shared/codesnippet/cpp/application-information-and-management_10.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxregisterwndclass"></a><a name="afxregisterwndclass"></a>Afxregisterwndclass

Permite que você registre suas próprias aulas de janela.

```cpp
LPCTSTR AFXAPI AfxRegisterWndClass(
    UINT nClassStyle,
    HCURSOR hCursor = 0,
    HBRUSH hbrBackground = 0,
    HICON hIcon = 0);
```

### <a name="parameters"></a>Parâmetros

*nClassStyle*\
Especifica o estilo de classe do Windows ou a combinação de estilos, criado usando o operador bitwise-OR** (&#124;), **para a classe de janela. Para obter uma lista de estilos de classe, consulte a estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) no SDK do Windows. Se NULL, os padrões serão definidos da seguinte forma:

- Define o estilo do mouse para CS_DBLCLKS, que envia mensagens de duplo clique para o procedimento da janela quando o usuário clica duas vezes no mouse.

- Define o estilo do cursor de seta para o IDC_ARROW padrão do Windows.

- Define o pincel de fundo como NULO, para que a janela não apague seu plano de fundo.

- Define o ícone para o ícone padrão, agitando-bandeira do logotipo do Windows.

*Hcursor*\
Especifica uma alça para o recurso do cursor a ser instalado em cada janela criada a partir da classe janela. Se você usar o padrão de **0,** você terá o cursor padrão IDC_ARROW.

*Hbrbackground*\
Especifica uma alça para o recurso de pincel a ser instalado em cada janela criada a partir da classe janela. Se você usar o padrão de **0,** você terá uma escova de fundo NULL e, por padrão, sua janela não apagará seu plano de fundo durante o processamento [WM_ERASEBKGND](/windows/win32/winmsg/wm-erasebkgnd).

*Hicon*\
Especifica uma alça para o recurso de ícone a ser instalado em cada janela criada a partir da classe janela. Se você usar o padrão de **0,** você terá o ícone padrão do logotipo do Windows com bandeira sinuosa.

### <a name="return-value"></a>Valor retornado

Uma seqüência de terminadas nula contendo o nome da classe. Você pode passar este `Create` nome de `CWnd` classe para a função de membro em ou em outras classes derivadas do **CWnd**para criar uma janela. O nome é gerado pela Biblioteca de Classes da Microsoft Foundation.

> [!NOTE]
> O valor de retorno é um ponteiro para um buffer estático. Para salvar esta seqüência, `CString` atribua-a a uma variável.

### <a name="remarks"></a>Comentários

A Biblioteca de Classes da Microsoft Foundation registra automaticamente várias classes de janela padrão para você. Ligue para esta função se quiser registrar suas próprias aulas de janela.

O nome registrado para `AfxRegisterWndClass` uma classe depende apenas dos parâmetros. Se você `AfxRegisterWndClass` ligar várias vezes com parâmetros idênticos, ele só registra uma classe na primeira chamada. Chamadas posteriores para `AfxRegisterWndClass` com parâmetros idênticos retornam o nome de classe já registrado.

Se você `AfxRegisterWndClass` chamar várias classes derivadas de CWnd com parâmetros idênticos, em vez de obter uma classe de janela separada para cada classe, cada classe compartilhará a mesma classe de janela. Esse compartilhamento pode causar problemas se o estilo de classe CS_CLASSDC for usado. Em vez de várias classes de janelas CS_CLASSDC, você acaba com apenas um CS_CLASSDC aula de janela. Todas as janelas C++ que usam essa classe compartilham o mesmo DC. Para evitar esse problema, ligue para [a AfxRegisterClass](#afxregisterclass) para registrar a classe.

Consulte a Nota Técnica [TN001: Registro da Classe](../../mfc/tn001-window-class-registration.md) `AfxRegisterWndClass` da Janela para obter mais informações sobre o registro da classe da janela e a função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#134](../../mfc/reference/codesnippet/cpp/application-information-and-management_11.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxsetperuserregistration"></a><a name="afxsetperuserregistration"></a>Registro de usuário afxSetPeruser

Define se o aplicativo redireciona o acesso do registro ao nó **HKEY_CURRENT_USER** **(HKCU).**

```cpp
void AFXAPI AfxSetPerUserRegistration(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*Benable*\
[em] TRUE indica que as informações do registro são direcionadas ao nó HKCU. FALSE indica que o aplicativo grava informações de registro para o nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** (**HKCR**).

### <a name="remarks"></a>Comentários

Antes do Windows Vista, os aplicativos que acessavam o registro geralmente usavam o **nó HKEY_CLASSES_ROOT.** No entanto, com o Windows Vista ou sistemas operacionais posteriores, você deve executar um aplicativo no modo elevado para gravar no HKCR.

Este método permite que seu aplicativo leia e escreva no registro sem ser executado no modo elevado. Ele funciona redirecionando o acesso ao registro de HKCR para HKCU. Para obter mais informações, consulte [Páginas de propriedade do Linker](../../build/reference/linker-property-pages.md).

Se você habilitar o redirecionamento do registro, a estrutura redirecionará o acesso do HKCR para **HKEY_CURRENT_USER\Software\Classes**. Apenas as estruturas MFC e ATL são afetadas pelo redirecionamento.

A implementação padrão acessa o registro em HKCR.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxstat_.h

## <a name="afxsetresourcehandle"></a><a name="afxsetresourcehandle"></a>Afxsetresourcehandle

Use esta função para definir o cabo HINSTANCE que determina onde os recursos padrão do aplicativo são carregados.

```cpp
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);
```

### <a name="parameters"></a>Parâmetros

*hInstResource*\
A instância ou o cabo do módulo para um . Arquivo EXE ou DLL a partir do qual os recursos do aplicativo são carregados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#135](../../mfc/reference/codesnippet/cpp/application-information-and-management_12.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="afxshellmanager"></a><a name="afxshellmanager"></a>AfxShellManager

Ponteiro para o gerente global [de shell](cshellmanager-class.md).

### <a name="syntax"></a>Sintaxe

```cpp
CShellManager* afxShellManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxshellmanager.h

## <a name="afxsocketinit"></a><a name="afxsocketinit"></a>Afxsocketinit

Chame esta função `CWinApp::InitInstance` em seu dispositivo para inicializar soquetes do Windows.

```cpp
BOOL AfxSocketInit(WSADATA* lpwsaData = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpwsaData*\
Um ponteiro para uma estrutura [WSADATA.](/windows/win32/api/winsock2/ns-winsock2-wsadata) Se *lpwsaData* não for igual a NULL, `WSADATA` então o endereço da `WSAStartup`estrutura será preenchido pela chamada para . Esta função também `WSACleanup` garante que é chamado para você antes que o aplicativo termine.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ao usar soquetes MFC em segmentos secundários em `AfxSocketInit` um aplicativo MFC estático ligado, você deve chamar em cada segmento que usa soquetes para inicializar as bibliotecas de soquetes. Por padrão, `AfxSocketInit` é chamado apenas no segmento principal.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxsock.h

## <a name="afxusertoolsmanager"></a><a name="afxusertoolsmanager"></a>AfxUserToolsManager

Ponteiro para o [gerenciador](cusertoolsmanager-class.md)global de ferramentas de usuário .

### <a name="syntax"></a>Sintaxe

```cpp
CUserToolsManager* afxUserToolsManager;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertoolsmanager.h

## <a name="afxwininit"></a><a name="afxwininit"></a>Afxwininit

Essa função é chamada pela `WinMain` função fornecida pelo MFC, como parte da inicialização do [CWinApp](../../mfc/reference/cwinapp-class.md) de um aplicativo baseado em GUI, para inicializar o MFC.

```cpp
BOOL AFXAPI AfxWinInit(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine,
    int nCmdShow);
```

### <a name="parameters"></a>Parâmetros

*Hinstance*\
A alça do módulo em execução no momento.

*hPrevInstance*\
Uma alça para uma instância anterior do aplicativo. Para um aplicativo baseado em Win32, este parâmetro é sempre **NULO**.

*lpCmdLine*\
Aponta para uma seqüência de terminadas nula especificando a linha de comando para o aplicativo.

*Ncmdshow*\
Especifica como a janela principal de um aplicativo de GUI seria mostrada.

### <a name="remarks"></a>Comentários

Para um aplicativo de console, que não `WinMain` usa a função `AfxWinInit` fornecida pelo MFC, você deve ligar diretamente para inicializar o MFC.

Se você `AfxWinInit` se chamar, você deve `CWinApp` declarar um exemplo de uma classe. Para um aplicativo de `CWinApp` console, você pode optar por não `CWinApp` derivar sua própria classe e, em vez disso, usar uma instância de diretamente. Esta técnica é apropriada se você decidir deixar todas as funcionalidades para sua aplicação na sua implementação do **principal**.

> [!NOTE]
> Quando cria um contexto de ativação para uma montagem, o MFC usa um recurso manifesto fornecido pelo módulo do usuário. O contexto de ativação é criado em `AfxWinInit`. Para obter mais informações, consulte [Suporte para Contextos de Ativação no Estado do Módulo MFC](../../mfc/support-for-activation-contexts-in-the-mfc-module-state.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_AfxWinInit#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_13.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="see-also"></a>Confira também

[Macros e Globais](mfc-macros-and-globals.md)\
[Classe Cwinapp](cwinapp-class.md)\
[Classe CContextMenuManager](ccontextmenumanager-class.md)\
[Classe CWnd](cwnd-class.md)\
[Classe CFrameWndEx](cframewndex-class.md)\
[Classe CMFCToolBar](cmfctoolbar-class.md)\
[Classe CKeyboardManager](ckeyboardmanager-class.md)\
[Classe CMenuTearOffManager](cmenutearoffmanager-class.md)\
[Classe CmouseManager](cmousemanager-class.md)\
[Classe CShellManager](cshellmanager-class.md)\
[Classe CUserToolsManager](cusertoolsmanager-class.md)
