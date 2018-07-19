---
title: Informações do aplicativo e gerenciamento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], managing
ms.assetid: b72f4154-24db-4e75-bca3-6873e2459c15
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7cfc0b62fd3008ae18ae82703bfb896d56dba1de
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37337363"
---
# <a name="application-information-and-management"></a>Informações e gerenciamento do aplicativo
Quando você escreve um aplicativo, você cria uma única [CWinApp](../../mfc/reference/cwinapp-class.md)-objeto derivado. Às vezes, você talvez queira obter informações sobre esse objeto de fora a `CWinApp`-objeto derivado. Ou você pode precisar de acesso a outros objetos globais "Manager".
  
 A biblioteca Microsoft Foundation Class fornece as seguintes funções globais para ajudá-lo a realizar essas tarefas:  
  
### <a name="application-information-and-management-functions"></a>Informações do aplicativo e funções de gerenciamento  
  
|||  
|-|-|  
|[AfxBeginThread](#afxbeginthread)|Cria um novo thread.|  
|[AfxContextMenuManager](#afxcontextmenumanager)|Ponteiro para o global [Gerenciador de menu de contexto](ccontextmenumanager-class.md).|
|[AfxEndThread](#afxendthread)|Encerra o thread atual.|  
|[AfxFindResourceHandle](#afxfindresourcehandle)|Orienta a cadeia de recursos e localize uma ID de recurso por recurso específico e o tipo de recurso. |
|[AfxFreeLibrary](#afxfreelibrary)|Diminui a contagem de referência do módulo carregado biblioteca de vínculo dinâmico (DLL); Quando a contagem de referência atinge zero, o módulo não está mapeado.|  
|[AfxGetApp](#afxgetapp)|Retorna um ponteiro para o aplicativo único do `CWinApp` objeto.|  
|[AfxGetAppName](#afxgetappname)|Retorna uma cadeia de caracteres que contém o nome do aplicativo.|  
|[AfxGetInstanceHandle](#afxgetinstancehandle)|Retorna um HINSTANCE que representa esta instância do aplicativo.|  
|[AfxGetMainWnd](#afxgetmainwnd)|Retorna um ponteiro para a janela de "main" atual de um aplicativo não são OLE ou a janela de quadro in-loco de um aplicativo de servidor.|  
|[AfxGetPerUserRegistration](#afxgetperuserregistration)|Use esta função para determinar se o aplicativo redireciona o acesso ao registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AfxGetResourceHandle](#afxgetresourcehandle)|Retorna um HINSTANCE para a fonte de recursos do padrão do aplicativo. Use isso para acessar os recursos do aplicativo diretamente.|  
|[AfxGetThread](#afxgetthread)|Recupera um ponteiro para o atual [CWinThread](../../mfc/reference/cwinthread-class.md) objeto.|  
|[AfxInitRichEdit](#afxinitrichedit)|Inicializa a versão de controle para o aplicativo de edição avançado 1.0.|  
|[AfxInitRichEdit2](#afxinitrichedit2)|Inicializa a versão de controle para o aplicativo de edição avançado 2.0 e posterior.| 
|[AfxIsExtendedFrameClass](#afxisextendedframeclass)|Determina se a determinada janela é um objeto de quadros estendida.|
|[AfxIsMFCToolBar](#afxismfctoolbar)|Determina se a determinada janela é um objeto de barra de ferramentas.|
|[AfxKeyboardManager](#afxkeyboardmanager)|Ponteiro para o global [manager teclado](ckeyboardmanager-class.md).|
|[AfxLoadLibrary](#afxloadlibrary)|Mapeia um módulo DLL e retorna um identificador que pode ser usado para obter o endereço de uma função de DLL.|  
|[AfxMenuTearOffManager](#afxmenutearoffmanager)|Ponteiro para o global [Gerenciador de menus de destaque](cmenutearoffmanager-class.md).|
|[AfxMouseManager](#afxmousemanager)|Ponteiro para o global [manager mouse](cmousemanager-class.md).|
|[AfxRegisterClass](#afxregisterclass)|Registra uma classe de janela em uma DLL que usa MFC.|  
|[AfxRegisterWndClass](#afxregisterwndclass)|Registra uma classe de janela do Windows para complementar as registradas automaticamente pelo MFC.|  
|[AfxSetPerUserRegistration](#afxsetperuserregistration)|Define se o aplicativo redireciona o acesso ao registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AfxSetResourceHandle](#afxsetresourcehandle)|Define o identificador HINSTANCE onde os recursos padrão do aplicativo são carregados.|  
|[AfxShellManager](#afxshellmanager)|Ponteiro para o global [Gerenciador de shell](cshellmanager-class.md). |
|[AfxSocketInit](#afxsocketinit)|Chamado em um `CWinApp::InitInstance` substituição é para inicializar o Windows Sockets.|  
|[AfxUserToolsManager](#afxusertoolsmanager)|Ponteiro para o global [Gerenciador do usuário das ferramentas de](cusertoolsmanager-class.md).|
|[AfxWinInit](#afxwininit)|Chamado pelo fornecido a MFC `WinMain` função, como parte do [CWinApp](../../mfc/reference/cwinapp-class.md) inicialização de um aplicativo baseado em GUI, para inicializar o MFC. Deve ser chamado diretamente para aplicativos de console que usam o MFC.|  
  

  
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
 *pfnThreadProc*  
 Aponta para a função de controle para o thread de trabalho. Não pode ser NULL. Essa função deve ser declarada da seguinte maneira:  
  
 `UINT __cdecl MyControllingFunction( LPVOID pParam );`  
  
 *pThreadClass*  
 O RUNTIME_CLASS de um objeto derivado de [CWinThread](../../mfc/reference/cwinthread-class.md).  
  
 *pParam*  
 Parâmetro a ser passado para a função de controle, conforme mostrado no parâmetro para a declaração de função no *pfnThreadProc*.  
  
 *nPriority*  
 A prioridade desejada do thread. Para obter uma lista completa e descrição de prioridades disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no SDK do Windows.  
  
 *nStackSize*  
 Especifica o tamanho em bytes da pilha para o novo thread. Se for 0, o tamanho da pilha padrão é o mesmo tamanho de pilha do thread de criação.  
  
 *dwCreateFlags*  
 Especifica um sinalizador adicional que controla a criação do thread. Este sinalizador pode conter um dos dois valores:  
  
- CREATE_SUSPENDED iniciar o thread com uma contagem de suspensão de um. Use CREATE_SUSPENDED se desejar inicializar quaisquer dados de membro do `CWinThread` objeto, como [m_bAutoDelete](../../mfc/reference/cwinthread-class.md#m_bautodelete) ou todos os membros de sua classe derivada, antes do thread for executado. Depois de sua inicialização estiver concluída, use [cwinthread:: ResumeThread](../../mfc/reference/cwinthread-class.md#resumethread) ao iniciar o thread em execução. O thread não será executada até `CWinThread::ResumeThread` é chamado.  
  
- **0** iniciar o thread imediatamente após a criação.  
  
 *lpSecurityAttrs*  
 Aponta para um [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica os atributos de segurança para o thread. Se for NULL, os mesmos atributos de segurança que o thread de criação serão usados. Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o objeto de thread recém-criado ou nulo se ocorrer uma falha.  
  
### <a name="remarks"></a>Comentários  
 A primeira forma de `AfxBeginThread` cria um thread de trabalho. O segundo formato cria um thread que poderá servir como um thread de interface do usuário ou como um thread de trabalho.  
  
 `AfxBeginThread` cria um novo `CWinThread` object, chamadas de seu [CreateThread](../../mfc/reference/cwinthread-class.md#createthread) funcionar para iniciar a execução do thread e retorna um ponteiro para o thread. Verificações são feitas em todo o procedimento para garantir que todos os objetos são desalocados corretamente caso de falha de qualquer parte da criação. Para encerrar o thread, chame [AfxEndThread](#afxendthread) de dentro do thread ou o retorno da função de controle do thread de trabalho.  
  
 Multithreading deve ser habilitado pelo aplicativo; Caso contrário, essa função falhará. Para obter mais informações sobre como habilitar o multithreading, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) sob *opções de compilador do Visual C++*.  
  
 Para obter mais informações sobre `AfxBeginThread`, consulte os artigos [Multithreading: Criando Threads de trabalho](../../parallel/multithreading-creating-worker-threads.md) e [Multithreading: Criando Threads de Interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md).  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [csocket:: Attach](../../mfc/reference/csocket-class.md#attach).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  

## <a name="afxcontextmenumanager"></a> AfxContextMenuManager
Ponteiro para o global [Gerenciador de menu de contexto](ccontextmenumanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CContextMenuManager* afxContextMenuManager;  
```     
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcontextmenumanager.h     

### <a name="see-also"></a>Consulte também   
 [Classe CContextMenuManager](ccontextmenumanager-class.md)

  
##  <a name="afxendthread"></a>  AfxEndThread  
 Chame essa função para encerrar o thread em execução no momento.  
  
```   
void AFXAPI AfxEndThread(
    UINT nExitCode,  
    BOOL bDelete  = TRUE); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *nExitCode*  
 Especifica o código de saída do thread.  
  
 *bDelete*  
 Exclui o objeto de thread da memória.  
  
### <a name="remarks"></a>Comentários  
 Deve ser chamado de dentro do thread ser encerrada.  
  
 Para obter mais informações sobre `AfxEndThread`, consulte o artigo [Multithreading: encerrando Threads](../../parallel/multithreading-terminating-threads.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  

  ## <a name="afxfindresourcehandle"></a>AfxFindResourceHandle
Use `AfxFindResourceHandle` para percorrer a cadeia de recursos e localizar um tipo específico de recursos e a ID de recurso por recurso.  
   
### <a name="syntax"></a>Sintaxe    
```
HINSTANCE AFXAPI AfxFindResourceHandle( LPCTSTR lpszName,  LPCTSTR lpszType );  
```
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Um ponteiro para uma cadeia de caracteres que contém a ID do recurso.    
 *lpszType*  
 Um ponteiro para o tipo de recurso. Para obter uma lista de tipos de recursos, consulte [FindResource](http://msdn.microsoft.com/library/windows/desktop/ms648042) no SDK do Windows.  
   
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o módulo que contém o recurso.  
   
### <a name="remarks"></a>Comentários  
 `AfxFindResourceHandle` Localiza o recurso específico e retorna um identificador para o módulo que contém o recurso. O recurso pode estar em qualquer extensão MFC DLL que você carregou. `AfxFindResourceHandle` informa qual deles apresenta o recurso.  
  
 Os módulos são pesquisados nesta ordem:  
  
1.  O módulo principal (se for uma DLL de extensão do MFC).  
  
2.  Módulos não são do sistema.  
  
3.  Módulos de linguagem específicos.  
  
4.  O módulo principal (se for uma DLL do sistema).  
  
5.  Módulos do sistema.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
  
##  <a name="afxfreelibrary"></a>  AfxFreeLibrary  
 Ambos `AfxFreeLibrary` e `AfxLoadLibrary` manter uma contagem de referência para cada módulo carregado de biblioteca.  
  
```   
BOOL AFXAPI AfxFreeLibrary(HINSTANCE hInstLib); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *hInstLib*  
 Um identificador do módulo carregado de biblioteca. [AfxLoadLibrary](#afxloadlibrary) retorna esse identificador.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a função for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 `AfxFreeLibrary` diminui a contagem de referência do módulo carregado biblioteca de vínculo dinâmico (DLL). Quando a contagem de referência atinge zero, o módulo não estiver mapeado do espaço de endereço do processo de chamada e o identificador não é válido. Essa contagem de referência é incrementada toda vez `AfxLoadLibrary` é chamado.  
  
 Antes de desmapeá um módulo de biblioteca, o sistema permite que a DLL desanexar dos processos usá-lo. Ao fazer isso a DLL uma oportunidade para limpar os recursos alocados em nome do processo atual. Depois que a função de ponto de entrada retornada, o módulo de biblioteca é removido do espaço de endereço do processo atual.  
  
 Use `AfxLoadLibrary` para mapear um módulo DLL.  
  
 Certifique-se de usar `AfxFreeLibrary` e `AfxLoadLibrary` (em vez das funções do Win32 `FreeLibrary` e `LoadLibrary`) se seu aplicativo usa vários threads. Usando o `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e desligamento é executado quando a extensão MFC DLL é carregado e descarregado não corromper o estado global do MFC.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [AfxLoadLibrary](#afxloadlibrary).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdll_.h  
  
##  <a name="afxgetapp"></a>  AfxGetApp  
 O ponteiro retornado por essa função pode ser usado para acessar informações do aplicativo, como o código de expedição de mensagem principal ou a janela de nível mais alta.  
  
```   
CWinApp* AFXAPI AfxGetApp(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o único `CWinApp` objeto para o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Se esse método retornará nulo, isso pode indicar que a janela principal do aplicativo não foi completamente inicializada ainda. Isso também pode indicar um problema.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#126](../../mfc/reference/codesnippet/cpp/application-information-and-management_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxgetappname"></a>  AfxGetAppName  
 A cadeia de caracteres retornada por essa função pode ser usada para mensagens de diagnóstico ou como uma raiz para nomes de cadeia de caracteres temporária.  
  
```   
LPCTSTR AFXAPI AfxGetAppName(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia terminada em nulo que contém o nome do aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#127](../../mfc/reference/codesnippet/cpp/application-information-and-management_2.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxgetinstancehandle"></a>  AfxGetInstanceHandle  
 Essa função permite que você recupere o identificador da instância do aplicativo atual.  
  
```   
HINSTANCE  AFXAPI AfxGetInstanceHandle(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um HINSTANCE à instância atual do aplicativo. Se chamado de dentro de uma DLL vinculada com a versão USRDLL do MFC, será retornado um HINSTANCE para a DLL.  
  
### <a name="remarks"></a>Comentários  
 `AfxGetInstanceHandle` sempre retorna o HINSTANCE do seu arquivo executável (. EXE), a menos que ele é chamado de dentro uma DLL é vinculado com a versão USRDLL do MFC. Nesse caso, ele retorna um HINSTANCE para a DLL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#128](../../mfc/reference/codesnippet/cpp/application-information-and-management_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxgetmainwnd"></a>  AfxGetMainWnd  
 Se seu aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo em vez de fazer referência diretamente à [m_pMainWnd](../../mfc/reference/cwinthread-class.md#m_pmainwnd) membro do objeto de aplicativo.  
  
```   
CWnd* AFXAPI AfxGetMainWnd(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o servidor tiver um objeto que está no local ativo dentro de um contêiner e esse contêiner estiver ativo, essa função retorna um ponteiro para o objeto de janela do quadro que contém o documento ativo no local.  
  
 Se não há nenhum objeto que está ativo no local dentro de um contêiner ou seu aplicativo não seja um servidor OLE, essa função simplesmente retorna o *m_pMainWnd* do seu objeto de aplicativo.  
  
 Se `AfxGetMainWnd` é chamado do thread de principal do aplicativo, ele retorna a janela principal do aplicativo de acordo com as regras acima. Se a função é chamada de um thread secundário no aplicativo, a função retorna a janela principal associada ao thread que fez a chamada.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo não for um servidor OLE, chamar essa função é equivalente a referindo-se diretamente para o *m_pMainWnd* membro do seu objeto de aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#129](../../mfc/reference/codesnippet/cpp/application-information-and-management_4.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxgetperuserregistration"></a>  AfxGetPerUserRegistration  
 Use esta função para determinar se o aplicativo redireciona o acesso ao registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.  
  
```  
BOOL AFXAPI AfxGetPerUserRegistration();
```  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO indica que as informações de registro são direcionadas para o nó HKCU; FALSE indica que o aplicativo grava as informações de registro para o nó de padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).  
  
### <a name="remarks"></a>Comentários  
 Se você habilitar o redirecionamento do registro, o framework redireciona o acesso de **HKCR** à **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.  
  
 Para alterar se o aplicativo redireciona o acesso ao registro, use [AfxSetPerUserRegistration](#afxsetperuserregistration).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxstat_.h    
  
##  <a name="afxgetresourcehandle"></a>  AfxGetResourceHandle  
 Use o HINSTANCE manipular retornado por essa função para acessar os recursos do aplicativo diretamente, por exemplo, em chamadas para o Windows funcionar `FindResource`.  
  
```   
extern HINSTANCE  AfxGetResourceHandle(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador HINSTANCE onde os recursos padrão do aplicativo são carregados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#130](../../mfc/reference/codesnippet/cpp/application-information-and-management_5.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxgetthread"></a>  AfxGetThread  
 Chame essa função para obter um ponteiro para o [CWinThread](../../mfc/reference/cwinthread-class.md) objeto que representa o thread em execução no momento.  
  
```   
CWinThread* AfxGetThread(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o thread em execução no momento. Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Deve ser chamado de dentro do thread desejado.  
  
> [!NOTE]
>  Se você estiver portando uma chamada de projeto do MFC `AfxGetThread` de versões do Visual C++ 4.2, 5.0 ou 6.0, `AfxGetThread` chamadas [AfxGetApp](#afxgetapp) se nenhum thread for encontrado. Em versões mais recentes do compilador, `AfxGetThread` retornará nulo se nenhum thread foi encontrado. Se você quiser que o thread do aplicativo, você deve chamar `AfxGetApp`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#132](../../mfc/reference/codesnippet/cpp/application-information-and-management_6.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxinitrichedit"></a>  AfxInitRichEdit  
 Chame essa função para inicializar o controle rich edit (versão 1.0) para o aplicativo.  
  
```   
BOOL AFXAPI AfxInitRichEdit(); 
```  
  
### <a name="remarks"></a>Comentários  
 Essa função é fornecida para compatibilidade com versões anteriores. Novos aplicativos devem usar [AfxInitRichEdit2](#afxinitrichedit2).  
  
 `AfxInitRichEdit` carrega RICHED32. DLL para inicializar a versão 1.0 do controle de edição avançada. Para usar a versão 2.0 e 3.0 do controle de edição avançada, RICHED20. DLL precisa ser carregado. Isso é feito com uma chamada para [AfxInitRichEdit2](#afxinitrichedit2).  
  
 Para atualizar os controles de edição rica em aplicativos existentes do Visual C++ para a versão 2.0, abra o. Arquivo RC como texto, altere o nome de classe de cada controle de edição rica de "RICHEDIT" para "RichEdit20a". Em seguida, substitua a chamada para `AfxInitRichEdit` com `AfxInitRichEdit2`.  
  
 Essa função também inicializa a biblioteca de controles comuns, se a biblioteca não tiver sido inicializada para o processo. Se você usar o controle rich edit diretamente do seu aplicativo do MFC, você deve chamar essa função para garantir que MFC foi inicializado corretamente o tempo de execução do controle de edição rica. Se você chamar o método Create da [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md), ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), você normalmente não precisa chamar essa função, mas em alguns casos, pode ser necessário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxinitrichedit2"></a>  AfxInitRichEdit2  
 Chame essa função para inicializar o controle rich edit (versão 2.0 e posterior) para o aplicativo.  
  
```   
BOOL AFXAPI AfxInitRichEdit2(); 
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para carregar o RICHED20. Controle de edição de DLL e inicializar a versão 2.0 do sofisticada. Se você chamar o método Create da [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md), ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), você normalmente não precisa chamar essa função, mas em alguns casos, pode ser necessário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  

  ## <a name="afxisextendedframeclass"></a>  AfxIsExtendedFrameClass
Determina se a determinada janela é um objeto de quadros estendida.  
   
### <a name="syntax"></a>Sintaxe    
```  
BOOL AFXAPI AfxIsExtendedFrameClass( CWnd* pWnd );  
```
### <a name="parameters"></a>Parâmetros  
 [in] *Apropriei*  
 Um ponteiro para um objeto que é derivado de `CWnd`.  
   
### <a name="return-value"></a>Valor de retorno  
 TRUE se a janela fornecido é um objeto de quadros estendida; Caso contrário, FALSE.  
   
### <a name="remarks"></a>Comentários  
 Esse método retornará TRUE se *Apropriei* deriva de uma das seguintes classes:  
  
-   `CFrameWndEx`  
  
-   `CMDIFrameWndEx`  
  
-   `COleIPFrameWndEx`  
  
-   `COleDocIPFrameWndEx`  
  
-   `CMDIChildWndEx`  
  
 Esse método é útil quando você precisa validar que um parâmetro de função ou método é uma janela do quadro estendido.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CWnd](cwnd-class.md)   
 [Classe CFrameWndEx](cframewndex-class.md)   

## <a name="afxismfctoolbar"></a> AfxIsMFCToolBar
Determina se a determinada janela é um objeto de barra de ferramentas.  
   
### <a name="syntax"></a>Sintaxe    
```  
BOOL AFXAPI AfxIsMFCToolBar(CWnd* pWnd);  
```
### <a name="parameters"></a>Parâmetros  
 [in] *Apropriei*  
 Um ponteiro para um objeto que é derivado de `CWnd`.  
   
### <a name="return-value"></a>Valor de retorno  
 TRUE se a janela fornecido for um objeto de barra de ferramentas; Caso contrário, FALSE.  
   
### <a name="remarks"></a>Comentários  
 Esse método retornará `TRUE` se *Apropriei* deriva `CMFCToolBar`. Esse método é útil quando você precisa validar que um parâmetro de função ou método é um `CMFCToolBar` objeto.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CWnd](cwnd-class.md)   
 [Classe CMFCToolBar](cmfctoolbar-class.md)

 
## <a name="afxkeyboardmanager"></a> AfxKeyboardManager
Ponteiro para o global [manager teclado](ckeyboardmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CKeyboardManager* afxKeyboardManager;  
```  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxkeyboardmanager.h  
   
### <a name="see-also"></a>Consulte também  

 [Macros, funções globais e variáveis globais](mfc-macros-and-globals.md)   
 [Classe CKeyboardManager](ckeyboardmanager-class.md)


##  <a name="afxloadlibrary"></a>  AfxLoadLibrary  
 Use `AfxLoadLibrary` para mapear um módulo DLL.  
  
```   
HINSTANCE AFXAPI AfxLoadLibrary(LPCTSTR lpszModuleName); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszModuleName*  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do módulo (qualquer um. DLL ou. Arquivo EXE). O nome especificado é o nome do arquivo do módulo.  
  
 Se a cadeia de caracteres Especifica um caminho, mas o arquivo não existe no diretório especificado, a função falhará.  
  
 Se não for especificado um caminho e a extensão de nome de arquivo for omitida, a extensão padrão. DLL é acrescentado. No entanto, a cadeia de caracteres de nome de arquivo pode incluir um caractere à direita do ponto (.) para indicar que o nome do módulo não tiver uma extensão. Quando nenhum caminho for especificado, a função de pesquisa para o arquivo na sequência a seguir:  
  
-   O diretório do qual o aplicativo é carregado.  
  
-   O diretório atual.  
  
- **Windows 95 98:** o diretório de sistema do Windows. **Windows NT:** o diretório de sistema do Windows de 32 bits. O nome desse diretório é SYSTEM32.  
  
- **Somente para o Windows NT:** diretório de sistema do Windows a 16 bits. Não há nenhuma função do Win32 que obtém o caminho desse diretório, mas ele é pesquisado. O nome desse diretório é o sistema.  
  
-   O diretório do Windows.  
  
-   Os diretórios que são listados na variável de ambiente PATH.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida, o valor de retorno é um identificador para o módulo. Se a função falhar, o valor retornado é NULL.  
  
### <a name="remarks"></a>Comentários  
 Ele retorna um identificador que pode ser usado em [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212) para obter o endereço de uma função DLL. `AfxLoadLibrary` também pode ser usado para mapear a outros módulos executáveis.  
  
 Cada processo mantém uma contagem de referência para cada módulo carregado de biblioteca. Essa contagem de referência é incrementada toda vez `AfxLoadLibrary` é chamado e é decrementado sempre `AfxFreeLibrary` é chamado. Quando a contagem de referência atinge zero, o módulo não estiver mapeado do espaço de endereço do processo de chamada e o identificador não é válido.  
  
 Certifique-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez das funções do Win32 `LoadLibrary` e `FreeLibrary`) se o seu aplicativo usa vários threads e se ele é carregado dinamicamente uma DLL de extensão do MFC. Usando o `AfxLoadLibrary` e `AfxFreeLibrary` assegura que o código de inicialização e desligamento é executado quando a DLL de extensão do MFC é carregado e descarregado não corromper o estado global do MFC.  
  
 Usando o `AfxLoadLibrary` em um aplicativo requer que você vincule dinamicamente para a versão DLL do MFC; o arquivo de cabeçalho para `AfxLoadLibrary`, Afxdll_.h, é apenas incluído se o MFC é vinculado ao aplicativo como uma DLL. Isso ocorre por design, porque você tem de vincular-se à versão DLL do MFC para usar ou criar DLLs de extensão do MFC.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_DLLUser#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_7.cpp)]  
[!code-cpp[NVC_MFC_DLLUser#2](../../mfc/reference/codesnippet/cpp/application-information-and-management_8.cpp)]  
[!code-cpp[NVC_MFC_DLLUser#3](../../mfc/reference/codesnippet/cpp/application-information-and-management_9.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdll_.h  
   
## <a name="afxmenutearoffmanager"></a> AfxMenuTearOffManager
Ponteiro para o global [Gerenciador de menus de destaque](cmenutearoffmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CMenuTearOffManager* g_pTearOffMenuManager;  
```  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmenutearoffmanager.h  
   
### <a name="see-also"></a>Consulte também     
 [Classe CMenuTearOffManager](cmenutearoffmanager-class.md)
 
## <a name="afxmousemanager"></a>  AfxMouseManager
Ponteiro para o global [manager mouse](cmousemanager-class.md).  
   
### <a name="syntax"></a>Sintaxe  
```  
CMouseManager* afxMouseManager;  
```  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmousemanager.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CMouseManager](cmousemanager-class.md)
 

  
##  <a name="afxregisterclass"></a>  AfxRegisterClass  
 Use essa função para registrar classes de janela em uma DLL que usa MFC.  
  
```   
BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpWndClass*  
 Ponteiro para um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura que contém informações sobre a classe de janela a ser registrado. Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a classe for registrada com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Se você usar essa função, a classe é cancelada automaticamente quando a DLL é descarregada.  
  
 Em builds de DLL não, o `AfxRegisterClass` identificador está definido como uma macro que mapeia para a função Windows `RegisterClass`, já que as classes em um aplicativo não são automaticamente registradas. Se você usar `AfxRegisterClass` em vez de `RegisterClass`, seu código pode ser usado sem alteração em um aplicativo e em uma DLL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_DLL#3](../../atl-mfc-shared/codesnippet/cpp/application-information-and-management_10.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
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
 *nClassStyle*  
 Especifica o estilo de classe do Windows ou uma combinação de estilos, criados com o uso de OR bit a bit ( **&#124;**) operador, para a classe de janela. Para obter uma lista de estilos de classe, consulte o [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura no SDK do Windows. Se for NULL, os padrões serão definidos da seguinte maneira:  
  
-   Define o estilo de mouse para CS_DBLCLKS, que envia duas vezes em mensagens para o procedimento de janela quando o usuário clica duas vezes no mouse.  
  
-   Define o estilo de cursor de seta para a IDC_ARROW padrão do Windows.  
  
-   Define o pincel de plano de fundo como NULL, portanto, a janela não apagará seu plano de fundo.  
  
-   Define o ícone para o ícone do logotipo do Windows padrão, o sinalizador de ondulação.  
  
 *hCursor*  
 Especifica um identificador para o recurso de cursor a ser instalado em cada janela criada a partir a classe de janela. Se você usar o padrão de **0**, você obterá o cursor IDC_ARROW padrão.  
  
 *hbrBackground*  
 Especifica um identificador para o recurso de pincel a ser instalado em cada janela criada a partir a classe de janela. Se você usar o padrão de **0**, você terá um pincel de plano de fundo NULL e sua janela, por padrão, não apagará seu plano de fundo durante o processamento [WM_ERASEBKGND](http://msdn.microsoft.com/library/windows/desktop/ms648055).  
  
 *hIcon*  
 Especifica um identificador para o recurso de ícone a ser instalado em cada janela criada a partir a classe de janela. Se você usar o padrão de **0**, você obterá o ícone do logotipo do Windows padrão, o sinalizador de ondulação.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia terminada em nulo que contém o nome de classe. Você pode passar esse nome de classe para o `Create` função de membro na `CWnd` ou outros **CWnd -** derivadas de classes para criar uma janela. O nome é gerado pela biblioteca de classes Microsoft Foundation.  
  
> [!NOTE]
>  O valor de retorno é um ponteiro para um buffer estático. Para salvar essa cadeia de caracteres, atribuí-la a um `CString` variável.  
  
### <a name="remarks"></a>Comentários  
 A biblioteca Microsoft Foundation Class registra automaticamente várias classes de janela padrão para você. Chame essa função se você quiser registrar suas próprias classes de janela.  
  
 O nome registrado para uma classe por `AfxRegisterWndClass` depende exclusivamente os parâmetros. Se você chamar `AfxRegisterWndClass` várias vezes com parâmetros idênticos, ele só registra uma classe na primeira chamada. As chamadas subsequentes para `AfxRegisterWndClass` com parâmetros idênticos simplesmente retornar o nome de classe já registrado.  
  
 Se você chamar `AfxRegisterWndClass` para várias classes derivadas de CWnd com parâmetros idênticos, em vez de obter uma classe de janela separada para cada classe, cada classe compartilha a mesma classe de janela. Isso pode causar problemas se o estilo de classe CS_CLASSDC é usado. Em vez de várias classes de janela CS_CLASSDC, você acaba com uma classe de janela CS_CLASSDC e todas as janelas de C++ que usam esse compartilhamento de classe mesmo controlador de domínio. Para evitar esse problema, chame [AfxRegisterClass](#afxregisterclass) para registrar a classe.  
  
 Consulte a nota técnica [TN001: registro da classe Window](../../mfc/tn001-window-class-registration.md) para obter mais informações sobre o registro de classe de janela e o `AfxRegisterWndClass` função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#134](../../mfc/reference/codesnippet/cpp/application-information-and-management_11.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="afxsetperuserregistration"></a>  AfxSetPerUserRegistration  
 Define se o aplicativo redireciona o acesso ao registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.  
  
```  
void AFXAPI AfxSetPerUserRegistration(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bAtivar*  
 VERDADEIRO indica que as informações de registro são direcionadas para o nó HKCU; FALSE indica que o aplicativo grava as informações de registro para o nó de padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).  
  
### <a name="remarks"></a>Comentários  

Antes do Windows Vista, aplicativos que são acessados do registro normalmente é usado o **HKEY_CLASSES_ROOT** nó. No entanto, com o Windows Vista ou sistemas operacionais posteriores, você deve executar um aplicativo no modo elevado para gravam no HKCR.  
  
 Esse método permite que seu aplicativo ler e gravar no registro sem executar no modo elevado ao redirecionar o acesso ao registro de HKCR HKCU. Para obter mais informações, consulte [páginas de propriedade do vinculador](../../ide/linker-property-pages.md).  
  
 Se você habilitar o redirecionamento do registro, o framework redireciona o acesso de HKCR para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.  
  
 A implementação padrão acessa o registro em HKCR.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxstat_.h    
  
##  <a name="afxsetresourcehandle"></a>  AfxSetResourceHandle  
 Use essa função para definir o identificador HINSTANCE que determina onde os recursos padrão do aplicativo são carregados.  
  
```  
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *hInstResource*  
 O identificador de instância ou um módulo para um. Arquivo EXE ou DLL do qual os recursos do aplicativo são carregados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#135](../../mfc/reference/codesnippet/cpp/application-information-and-management_12.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  

## <a name="afxshellmanager"></a>  AfxShellManager
Ponteiro para o global [Gerenciador de shell](cshellmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CShellManager* afxShellManager;  
```  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxshellmanager.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CShellManager](cshellmanager-class.md)
  
##  <a name="afxsocketinit"></a>  AfxSocketInit  
 Chame essa função em seu `CWinApp::InitInstance` substituição é para inicializar o Windows Sockets.  
  
```  
BOOL AfxSocketInit(WSADATA* lpwsaData = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpwsaData*  
 Um ponteiro para um [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura. Se *lpwsaData* não é igual a NULL, em seguida, o endereço do `WSADATA` estrutura é preenchida pela chamada para `WSAStartup`. Essa função também garante que `WSACleanup` é chamado para você antes que o aplicativo seja encerrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread primário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxsock.h  

## <a name="afxusertoolsmanager"></a>  AfxUserToolsManager
Ponteiro para o global [Gerenciador do usuário das ferramentas de](cusertoolsmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CUserToolsManager* afxUserToolsManager;  
```  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxusertoolsmanager.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CUserToolsManager](cusertoolsmanager-class.md)
 
  
##  <a name="afxwininit"></a>  AfxWinInit  
 Essa função é chamada pelo fornecido a MFC `WinMain` função, como parte do [CWinApp](../../mfc/reference/cwinapp-class.md) inicialização de um aplicativo baseado em GUI, para inicializar o MFC.  
  
```  
BOOL AFXAPI AfxWinInit(
    HINSTANCE hInstance,  
    HINSTANCE hPrevInstance,  
    LPTSTR lpCmdLine,  
    int nCmdShow);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *hInstance*  
 O identificador do módulo em execução no momento.  
  
 *hPrevInstance*  
 Um identificador para uma instância anterior do aplicativo. Para um aplicativo baseado em Win32, esse parâmetro é sempre **nulo**.  
  
 *lpCmdLine*  
 Aponta para uma cadeia de caracteres terminada em nulo, especificando a linha de comando para o aplicativo.  
  
 *nCmdShow*  
 Especifica como a janela principal de um aplicativo de GUI seria mostrada.  
  
### <a name="remarks"></a>Comentários  
 Para um aplicativo de console que não usa o MFC fornecido pelo `WinMain` função, você deve chamar `AfxWinInit` diretamente para inicializar o MFC.  
  
 Se você chamar `AfxWinInit` por conta própria, você deve declarar uma instância de um `CWinApp` classe. Para um aplicativo de console, você pode optar por não derivar sua própria classe de `CWinApp` e, em vez disso, use uma instância de `CWinApp` diretamente. Essa técnica é apropriada se você decidir deixar toda a funcionalidade para seu aplicativo em sua implementação de **principal**.  
  
> [!NOTE]
>  Quando ele cria um contexto de ativação para um assembly, o MFC usa um recurso de manifesto fornecido pelo módulo do usuário. O contexto de ativação é criado no `AfxWinInit`. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../../mfc/support-for-activation-contexts-in-the-mfc-module-state.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_AfxWinInit#1](../../mfc/reference/codesnippet/cpp/application-information-and-management_13.cpp)]  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)
