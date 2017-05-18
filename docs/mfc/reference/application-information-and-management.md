---
title: "Informações do aplicativo e gerenciamento | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], managing
ms.assetid: b72f4154-24db-4e75-bca3-6873e2459c15
caps.latest.revision: 17
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: b943ef8dd652df061965fe81ecc9c08115636141
ms.openlocfilehash: 5d7b6a0c31a8c4ff63b3cfc1fa58c08879e37f58
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="application-information-and-management"></a>Informações e gerenciamento do aplicativo
Quando você escreve um aplicativo, você cria um único [CWinApp](../../mfc/reference/cwinapp-class.md)-objeto derivado. Às vezes, você pode desejar obter informações sobre esse objeto de fora de `CWinApp`-objeto derivado. Ou, talvez seja necessário o acesso a outros objetos globais "Manager".
  
 A biblioteca Microsoft Foundation Class fornece as seguintes funções globais para ajudá-lo a realizar essas tarefas:  
  
### <a name="application-information-and-management-functions"></a>Informações do aplicativo e funções de gerenciamento  
  
|||  
|-|-|  
|[AfxBeginThread](#afxbeginthread)|Cria um novo thread.|  
|[AfxContextMenuManager](#afxcontextmenumanager)|Ponteiro para global [Gerenciador do menu de contexto](ccontextmenumanager-class.md).|
|[AfxEndThread](#afxendthread)|Encerra o thread atual.|  
|[AfxFindResourceHandle](#afxfindresourcehandle)|Conduz a cadeia de recurso e localizar uma ID de recurso por recurso específico e o tipo de recurso. |
|[AfxFreeLibrary](#afxfreelibrary)|Diminui a contagem de referência do módulo carregado biblioteca de vínculo dinâmico (DLL); Quando a contagem de referência chega a zero, o módulo não está mapeado.|  
|[AfxGetApp](#afxgetapp)|Retorna um ponteiro para o aplicativo 's único `CWinApp` objeto.|  
|[AfxGetAppName](#afxgetappname)|Retorna uma cadeia de caracteres que contém o nome do aplicativo.|  
|[AfxGetInstanceHandle](#afxgetinstancehandle)|Retorna um `HINSTANCE` que representa esta instância do aplicativo.|  
|[AfxGetMainWnd](#afxgetmainwnd)|Retorna um ponteiro para a janela atual "main" de um aplicativo não são OLE ou a janela do quadro no local de um aplicativo de servidor.|  
|[AfxGetPerUserRegistration](#afxgetperuserregistration)|Use esta função para determinar se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AfxGetResourceHandle](#afxgetresourcehandle)|Retorna um `HINSTANCE` para a fonte de recursos de padrão do aplicativo. Use isto para acessar os recursos do aplicativo diretamente.|  
|[AfxGetThread](#afxgetthread)|Recupera um ponteiro para o atual [CWinThread](../../mfc/reference/cwinthread-class.md) objeto.|  
|[AfxInitRichEdit](#afxinitrichedit)|Inicializa a versão de controle para o aplicativo de edição avançado 1.0.|  
|[AfxInitRichEdit2](#afxinitrichedit2)|Inicializa a versão de controle para o aplicativo de edição avançado 2.0 e posterior.| 
|[AfxIsExtendedFrameClass](#afxisextendedframeclass)|Determina se a determinada janela é um objeto de quadro estendida.|
|[AfxIsMFCToolBar](#afxismfctoolbar)|Determina se a janela fornecida é um objeto de barra de ferramentas.|
|[AfxKeyboardManager](#afxkeyboardmanager)|Ponteiro para global [manager teclado](ckeyboardmanager-class.md).|
|[AfxLoadLibrary](#afxloadlibrary)|Mapeia um módulo DLL e retorna um identificador que pode ser usado para obter o endereço de uma função DLL.|  
|[AfxMenuTearOffManager](#afxmenutearoffmanager)|Ponteiro para global [Gerenciador do menu de destacar](cmenutearoffmanager-class.md).|
|[AfxMouseManager](#afxmousemanager)|Ponteiro para global [manager mouse](cmousemanager-class.md).|
|[AfxRegisterClass](#afxregisterclass)|Registra uma classe de janela em uma DLL que usa MFC.|  
|[AfxRegisterWndClass](#afxregisterwndclass)|Registra uma classe de janela do Windows para complementar as registradas automaticamente pelo MFC.|  
|[AfxSetPerUserRegistration](#afxsetperuserregistration)|Define se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AfxSetResourceHandle](#afxsetresourcehandle)|Define o `HINSTANCE` identificador onde os recursos padrão do aplicativo são carregados.|  
|[AfxShellManager](#afxshellmanager)|Ponteiro para global [manager shell](cshellmanager-class.md). |
|[AfxSocketInit](#afxsocketinit)|Chamado em um `CWinApp::InitInstance` substituição para inicializar o Windows Sockets.|  
|[AfxUserToolsManager](#afxusertoolsmanager)|Ponteiro para global [gerente do usuário ferramentas](cusertoolsmanager-class.md).|
|[AfxWinInit](#afxwininit)|Chamado pelo fornecido a MFC `WinMain` função, como parte do [CWinApp](../../mfc/reference/cwinapp-class.md) inicialização de um aplicativo baseado em GUI, inicializar MFC. Deve ser chamado diretamente de aplicativos de console que usam MFC.|  
  

  
##  <a name="afxbeginthread"></a>AfxBeginThread  
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
 `pfnThreadProc`  
 Aponta para a função de controle para o thread de trabalho. Não pode ser **nulo**. Essa função deve ser declarada da seguinte maneira:  
  
 `UINT __cdecl MyControllingFunction( LPVOID pParam );`  
  
 *pThreadClass*  
 RUNTIME_CLASS de um objeto derivado de [CWinThread](../../mfc/reference/cwinthread-class.md).  
  
 *pParam*  
 Parâmetro a ser passado para a função de controle, conforme mostrado no parâmetro para a declaração da função no `pfnThreadProc`.  
  
 `nPriority`  
 A prioridade desejada do thread. Para uma lista completa e a descrição das prioridades disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no SDK do Windows.  
  
 `nStackSize`  
 Especifica o tamanho em bytes da pilha para o novo thread. Se for 0, o tamanho da pilha padrão é a mesma pilha de tamanho, como o thread de criação.  
  
 `dwCreateFlags`  
 Especifica um sinalizador adicional que controla a criação do thread. Este sinalizador pode conter um dos dois valores:  
  
- **CREATE_SUSPENDED** iniciar o thread com uma contagem de suspensão de um. Use **CREATE_SUSPENDED** se deseja inicializar todos os dados de membro de `CWinThread` objeto, como [m_bAutoDelete](../../mfc/reference/cwinthread-class.md#m_bautodelete) ou quaisquer membros de sua classe derivada, antes do thread é iniciado. Quando a inicialização for concluída, use [CWinThread::ResumeThread](../../mfc/reference/cwinthread-class.md#resumethread) ao iniciar o thread em execução. O thread não será executado até `CWinThread::ResumeThread` é chamado.  
  
- **0** iniciar o thread imediatamente após a criação.  
  
 `lpSecurityAttrs`  
 Aponta para um [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica os atributos de segurança para o thread. Se **nulo**, a mesma segurança atributos como o thread de criação será usado. Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o objeto de thread criado recentemente, ou **nulo** se ocorrer uma falha.  
  
### <a name="remarks"></a>Comentários  
 O primeiro formulário da `AfxBeginThread` cria um thread de trabalho. O segundo formulário cria um thread que pode servir como um thread de interface do usuário ou como um thread de trabalho.  
  
 `AfxBeginThread`cria um novo `CWinThread` objeto, chamadas de seu [CreateThread](../../mfc/reference/cwinthread-class.md#createthread) para iniciar a execução do thread de função e retorna um ponteiro para o thread. Verificações são feitas em todo o procedimento para verificar se que todos os objetos são desalocados corretamente caso de falha de qualquer parte da criação. Para encerrar o thread, chame [AfxEndThread](#afxendthread) de dentro do thread ou retorno da função de controle do thread de trabalho.  
  
 Multithreading deve ser habilitado pelo aplicativo. Caso contrário, a função falhará. Para obter mais informações sobre como habilitar multithreading, consulte [/MD, /MT, /LD (usar biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) em *opções do compilador do Visual C++*.  
  
 Para obter mais informações sobre `AfxBeginThread`, consulte os artigos [Multithreading: Criando Threads de trabalho](../../parallel/multithreading-creating-worker-threads.md) e [Multithreading: Criando Threads de Interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CSocket::Attach](../../mfc/reference/csocket-class.md#attach).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  

## <a name="afxcontextmenumanager"></a>AfxContextMenuManager
Ponteiro para global [Gerenciador do menu de contexto](ccontextmenumanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CContextMenuManager* afxContextMenuManager;  
```     
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcontextmenumanager.h     

### <a name="see-also"></a>Consulte também   
 [Classe CContextMenuManager](ccontextmenumanager-class.md)

  
##  <a name="afxendthread"></a>AfxEndThread  
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
 Exclui o objeto de segmento de memória.  
  
### <a name="remarks"></a>Comentários  
 Deve ser chamado de dentro de thread a ser encerrada.  
  
 Para obter mais informações sobre `AfxEndThread`, consulte o artigo [Multithreading: encerrando Threads](../../parallel/multithreading-terminating-threads.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  

  ## <a name="afxfindresourcehandle"></a>AfxFindResourceHandle
Use `AfxFindResourceHandle` para percorrer a cadeia de recurso e localize um tipo específico de recursos e a ID de recurso por recurso.  
   
### <a name="syntax"></a>Sintaxe    
```
HINSTANCE AFXAPI AfxFindResourceHandle( LPCTSTR lpszName,  LPCTSTR lpszType );  
```
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres que contém a ID de recurso.    
 *lpszType*  
 Um ponteiro para o tipo de recurso. Para obter uma lista dos tipos de recursos, consulte [FindResource](http://msdn.microsoft.com/library/windows/desktop/ms648042) no SDK do Windows.  
   
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o módulo que contém o recurso.  
   
### <a name="remarks"></a>Comentários  
 `AfxFindResourceHandle`Localiza o recurso específico e retorna um identificador para o módulo que contém o recurso. O recurso pode estar em qualquer extensão DLL que você carregou. `AfxFindResourceHandle`indica qual delas tem o recurso.  
  
 Os módulos são pesquisados nesta ordem:  
  
1.  O módulo principal (se ela é uma extensão DLL).  
  
2.  Módulos do sistema.  
  
3.  Módulos específicos do idioma.  
  
4.  O módulo principal (se ele for um sistema DLL).  
  
5.  Módulos do sistema.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
  
##  <a name="afxfreelibrary"></a>AfxFreeLibrary  
 Ambos `AfxFreeLibrary` e `AfxLoadLibrary` manter uma contagem de referência para cada módulo carregado de biblioteca.  
  
```   
BOOL AFXAPI AfxFreeLibrary(HINSTANCE hInstLib); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *hInstLib*  
 Um identificador do módulo carregado de biblioteca. [AfxLoadLibrary](#afxloadlibrary) retorna esse identificador.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a função for bem-sucedida; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 `AfxFreeLibrary`diminui a contagem de referência do módulo carregado biblioteca de vínculo dinâmico (DLL). Quando a contagem de referência chega a zero, o módulo não está mapeado do espaço de endereço do processo de chamada e o identificador não é válido. Essa contagem de referência é incrementada toda vez que `AfxLoadLibrary` é chamado.  
  
 Antes do cancelamento do mapeamento de um módulo de biblioteca, o sistema permite que a DLL desconectar-se de que os processos de usá-lo. Isso permite a DLL tenha a oportunidade para limpar os recursos alocados em nome do processo atual. Depois que a função de ponto de entrada retorna, o módulo de biblioteca é removido do espaço de endereço do processo atual.  
  
 Use `AfxLoadLibrary` para mapear um módulo DLL.  
  
 Certifique-se de usar `AfxFreeLibrary` e `AfxLoadLibrary` (em vez de funções do Win32 **FreeLibrary** e **LoadLibrary**) se seu aplicativo usa vários threads. Usando `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e desligamento que é executado quando a extensão DLL é carregado e descarregado não corromper o estado global do MFC.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [AfxLoadLibrary](#afxloadlibrary).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdll_.h  
  
##  <a name="afxgetapp"></a>AfxGetApp  
 O ponteiro retornado por essa função pode ser usado para acessar informações do aplicativo, como o código de expedição de mensagem principal ou a primeira janela.  
  
```   
CWinApp* AFXAPI AfxGetApp(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o único `CWinApp` objeto para o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Se esse método retornará nulo, pode indicar que a janela principal do aplicativo não foi completamente inicializada ainda. Ele também pode indicar um problema.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #126](../../mfc/reference/codesnippet/cpp/application-information-and-management_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxgetappname"></a>AfxGetAppName  
 A cadeia de caracteres retornada por essa função pode ser usada para mensagens de diagnóstico ou como uma raiz para nomes de cadeia de caracteres temporária.  
  
```   
LPCTSTR AFXAPI AfxGetAppName(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia terminada em nulo que contém o nome do aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #127](../../mfc/reference/codesnippet/cpp/application-information-and-management_2.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxgetinstancehandle"></a>AfxGetInstanceHandle  
 Esta função permite que você recupere o identificador de instância do aplicativo atual.  
  
```   
HINSTANCE  AFXAPI AfxGetInstanceHandle(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HINSTANCE` para a instância atual do aplicativo. Se for chamado de dentro de uma DLL vinculada com a versão USRDLL do MFC, um `HINSTANCE` para a DLL será retornado.  
  
### <a name="remarks"></a>Comentários  
 `AfxGetInstanceHandle`sempre retorna o `HINSTANCE` do seu arquivo executável (. EXE), a menos que ele é chamado de dentro uma DLL vinculado com a versão USRDLL do MFC. Nesse caso, ele retorna um `HINSTANCE` para a DLL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #128](../../mfc/reference/codesnippet/cpp/application-information-and-management_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxgetmainwnd"></a>AfxGetMainWnd  
 Se seu aplicativo for um servidor OLE, chamar essa função para recuperar um ponteiro para a janela principal ativa do aplicativo em vez de referir-se diretamente para o [m_pMainWnd](../../mfc/reference/cwinthread-class.md#m_pmainwnd) membro do objeto application.  
  
```   
CWnd* AFXAPI AfxGetMainWnd(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o servidor tiver um objeto que está no local ativo dentro de um contêiner e esse contêiner estiver ativo, essa função retorna um ponteiro para o objeto de janela do quadro que contém o documento ativo no local.  
  
 Se não há nenhum objeto que está ativo no local dentro de um contêiner ou seu aplicativo não é um servidor OLE, essa função retorna apenas o `m_pMainWnd` de seu objeto de aplicativo.  
  
 Se `AfxGetMainWnd` é chamado do thread de principal do aplicativo, ele retorna a janela principal do aplicativo de acordo com as regras acima. Se a função é chamada de um thread secundário no aplicativo, a função retorna a janela principal associada ao thread que fez a chamada.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo não é um servidor OLE, chamar essa função é equivalente a referindo-se diretamente para o `m_pMainWnd` membro do seu objeto de aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #129](../../mfc/reference/codesnippet/cpp/application-information-and-management_4.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxgetperuserregistration"></a>AfxGetPerUserRegistration  
 Use esta função para determinar se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.  
  
```  
BOOL AFXAPI AfxGetPerUserRegistration();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava informações de registro para o nó de padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).  
  
### <a name="remarks"></a>Comentários  
 Se você habilitar o redirecionamento do registro, o framework redireciona o acesso de **HKCR** para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas de MFC e ATL são afetadas pelo redirecionamento.  
  
 Para que o aplicativo redireciona o acesso ao registro, use [AfxSetPerUserRegistration](#afxsetperuserregistration).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxstat_.h    
  
##  <a name="afxgetresourcehandle"></a>AfxGetResourceHandle  
 Use o `HINSTANCE` identificador retornado por essa função para acessar os recursos do aplicativo diretamente, por exemplo, em chamadas para a função do Windows **FindResource**.  
  
```   
extern HINSTANCE  AfxGetResourceHandle(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HINSTANCE` identificador onde os recursos padrão do aplicativo são carregados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #130](../../mfc/reference/codesnippet/cpp/application-information-and-management_5.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxgetthread"></a>AfxGetThread  
 Chamar essa função para obter um ponteiro para o [CWinThread](../../mfc/reference/cwinthread-class.md) objeto que representa o thread em execução no momento.  
  
```   
CWinThread* AfxGetThread(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o thread em execução no momento; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Deve ser chamado de dentro do thread desejado.  
  
> [!NOTE]
>  Se você estiver portando uma chamada de projeto MFC `AfxGetThread` de versões do Visual C++ 4.2, 5.0 ou 6.0, `AfxGetThread` chamadas [AfxGetApp](#afxgetapp) se nenhum thread foi encontrado. No Visual c++ .NET e posterior, `AfxGetThread` retorna **nulo** se nenhum thread foi encontrado. Se você quiser que o thread de aplicativo, você deve chamar `AfxGetApp`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[132 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/application-information-and-management_6.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxinitrichedit"></a>AfxInitRichEdit  
 Chame essa função para inicializar o controle rich edit (versão 1.0) para o aplicativo.  
  
```   
BOOL AFXAPI AfxInitRichEdit(); 
```  
  
### <a name="remarks"></a>Comentários  
 Esta função é fornecida para compatibilidade com versões anteriores. Os aplicativos criados com o Visual C++ .NET e o uso posterior [AfxInitRichEdit2](#afxinitrichedit2).  
  
 `AfxInitRichEdit`carrega RICHED32. DLL para inicializar a versão 1.0 do controle de edição avançada. Para usar a versão 2.0 e 3.0 do controle de edição rica, RICHED20. DLL precisa ser carregada. Isso é feito com uma chamada para [AfxInitRichEdit2](#afxinitrichedit2). Se você tiver recursos de caixa de diálogo com o controle rich edit criado antes do Visual C++ .NET, os controles de edição com formato são automaticamente versão 1.0. Controles de edição avançada inseridos usando o Editor de recursos do Visual C++ .NET são versão 2.0.  
  
 Para atualizar os controles de edição avançada em aplicativos existentes do Visual C++ para a versão 2.0, abra o. Arquivo RC como texto, altere o nome da classe de cada controle de edição com formato de "RICHEDIT" para "RichEdit20a". Em seguida, substitua a chamada para `AfxInitRichEdit` com `AfxInitRichEdit2`.  
  
 Essa função também inicializa a biblioteca de controles comuns, se a biblioteca já não foi inicializada para o processo. Se você usar o controle rich edit diretamente do seu aplicativo MFC, você deve chamar esta função para assegurar que MFC foi inicializado corretamente o tempo de execução do controle de edição com formato. Se você chamar o método Create da [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md), ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), você normalmente não precisa chamar essa função, mas em alguns casos, pode ser necessário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxinitrichedit2"></a>AfxInitRichEdit2  
 Chame essa função para inicializar o controle rich edit (versão 2.0 e posterior) para o aplicativo.  
  
```   
BOOL AFXAPI AfxInitRichEdit2(); 
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para carregar o RICHED20. DLL e inicializar a versão 2.0 do sofisticado controle de edição. Se você chamar o método Create da [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md), ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), você normalmente não precisa chamar essa função, mas em alguns casos, pode ser necessário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  

  ## <a name="afxisextendedframeclass"></a>AfxIsExtendedFrameClass
Determina se a determinada janela é um objeto de quadro estendida.  
   
### <a name="syntax"></a>Sintaxe    
```  
BOOL AFXAPI AfxIsExtendedFrameClass( CWnd* pWnd );  
```
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Um ponteiro para um objeto que é derivado de `CWnd`.  
   
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela fornecida é um objeto de quadro estendido; Caso contrário, `FALSE`.  
   
### <a name="remarks"></a>Comentários  
 Este método retorna `TRUE` se `pWnd` derivada de uma das seguintes classes:  
  
-   `CFrameWndEx`  
  
-   `CMDIFrameWndEx`  
  
-   `COleIPFrameWndEx`  
  
-   `COleDocIPFrameWndEx`  
  
-   `CMDIChildWndEx`  
  
 Esse método é útil quando você precisa validar que um parâmetro de função ou método é uma janela do quadro estendida.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CWnd](cwnd-class.md)   
 [Classe CFrameWndEx](cframewndex-class.md)   

## <a name="afxismfctoolbar"></a>AfxIsMFCToolBar
Determina se a janela fornecida é um objeto de barra de ferramentas.  
   
### <a name="syntax"></a>Sintaxe    
```  
BOOL AFXAPI AfxIsMFCToolBar(CWnd* pWnd);  
```
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Um ponteiro para um objeto que é derivado de `CWnd`.  
   
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela fornecida é um objeto de barra de ferramentas. Caso contrário, `FALSE`.  
   
### <a name="remarks"></a>Comentários  
 Este método retorna `TRUE` se `pWnd` deriva de `CMFCToolBar`. Esse método é útil quando você precisa validar que um parâmetro de função ou método é um `CMFCToolBar` objeto.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpriv.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CWnd](cwnd-class.md)   
 [Classe CMFCToolBar](cmfctoolbar-class.md)

 
## <a name="afxkeyboardmanager"></a>AfxKeyboardManager
Ponteiro para global [manager teclado](ckeyboardmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CKeyboardManager* afxKeyboardManager;  
```  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxkeyboardmanager.h  
   
### <a name="see-also"></a>Consulte também  

 [Macros, funções globais e variáveis globais](mfc-macros-and-globals.md)   
 [Classe CKeyboardManager](ckeyboardmanager-class.md)


##  <a name="afxloadlibrary"></a>AfxLoadLibrary  
 Use `AfxLoadLibrary` para mapear um módulo DLL.  
  
```   
HINSTANCE AFXAPI AfxLoadLibrary(LPCTSTR lpszModuleName); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszModuleName*  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do módulo (qualquer um. DLL ou. Arquivo EXE). O nome especificado é o nome do arquivo do módulo.  
  
 Se a cadeia de caracteres Especifica um caminho, mas o arquivo não existe no diretório especificado, a função falhará.  
  
 Se um caminho não for especificado e a extensão de nome de arquivo for omitida, a extensão padrão. DLL é anexado. No entanto, a cadeia de caracteres de nome de arquivo pode incluir um caractere à direita do ponto (.) para indicar que o nome do módulo não tem extensão. Quando não for especificado, a função de pesquisa para o arquivo na sequência a seguir:  
  
-   O diretório do qual o aplicativo é carregado.  
  
-   O diretório atual.  
  
- **Windows 95/98:** o diretório de sistema do Windows. **Windows NT:** o diretório de sistema do Windows de 32 bits. O nome deste diretório é SYSTEM32.  
  
- **Somente Windows NT:** diretório de sistema do Windows a 16 bits. Não há nenhuma função Win32 que obtém o caminho desse diretório, mas é pesquisado. O nome deste diretório é o sistema.  
  
-   O diretório do Windows.  
  
-   Os diretórios que são listados na variável de ambiente PATH.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, o valor de retorno é um identificador para o módulo. Se a função falhar, o valor de retorno será NULL.  
  
### <a name="remarks"></a>Comentários  
 Retorna um identificador que pode ser usado em [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212) para obter o endereço de uma função DLL. `AfxLoadLibrary`também pode ser usado para mapear outros módulos de executáveis.  
  
 Cada processo mantém uma contagem de referência para cada módulo carregado de biblioteca. Essa contagem de referência é incrementada toda vez que `AfxLoadLibrary` é chamado e é decrementado sempre `AfxFreeLibrary` é chamado. Quando a contagem de referência chega a zero, o módulo não está mapeado do espaço de endereço do processo de chamada e o identificador não é válido.  
  
 Certifique-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez de funções do Win32 **LoadLibrary** e **FreeLibrary**) se seu aplicativo usa vários threads e se ele dinamicamente carrega uma DLL de extensão. Usando `AfxLoadLibrary` e `AfxFreeLibrary` assegura que o código de inicialização e desligamento que é executado quando a DLL de extensão é carregado e descarregado não corromper o estado global do MFC.  
  
 Usando `AfxLoadLibrary` em um aplicativo requer que você vincular dinamicamente para a versão DLL do MFC; o arquivo de cabeçalho para `AfxLoadLibrary`, Afxdll_.h, só é incluída se MFC está vinculado ao aplicativo como uma DLL. Isso ocorre por design, pois você precisa vincular para a versão DLL do MFC para usar ou criar DLLs de extensão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_DLLUser n º 1](../../mfc/reference/codesnippet/cpp/application-information-and-management_7.cpp)]  
[!code-cpp[NVC_MFC_DLLUser n º 2](../../mfc/reference/codesnippet/cpp/application-information-and-management_8.cpp)]  
[!code-cpp[NVC_MFC_DLLUser n º 3](../../mfc/reference/codesnippet/cpp/application-information-and-management_9.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdll_.h  
   
## <a name="afxmenutearoffmanager"></a>AfxMenuTearOffManager
Ponteiro para global [Gerenciador do menu de destacar](cmenutearoffmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CMenuTearOffManager* g_pTearOffMenuManager;  
```  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmenutearoffmanager.h  
   
### <a name="see-also"></a>Consulte também     
 [Classe CMenuTearOffManager](cmenutearoffmanager-class.md)
 
## <a name="afxmousemanager"></a>AfxMouseManager
Ponteiro para global [manager mouse](cmousemanager-class.md).  
   
### <a name="syntax"></a>Sintaxe  
  ```  
CMouseManager* afxMouseManager;  
```  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmousemanager.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CMouseManager](cmousemanager-class.md)
 

  
##  <a name="afxregisterclass"></a>AfxRegisterClass  
 Use esta função para registrar classes de janela em uma DLL que usa MFC.  
  
```   
BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpWndClass*  
 Ponteiro para um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura que contém informações sobre a classe de janela a ser registrado. Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a classe com êxito registrado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Se você usar essa função, a classe é cancelada automaticamente quando a DLL é descarregada.  
  
 Em compilações de DLL não, o `AfxRegisterClass` identificador está definido como uma macro que mapeia para a função do Windows **RegisterClass**, pois não são automaticamente registrados classes registrados em um aplicativo. Se você usar `AfxRegisterClass` em vez de **RegisterClass**, seu código pode ser usado sem alteração em um aplicativo e em uma DLL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_DLL N º 3](../../atl-mfc-shared/codesnippet/cpp/application-information-and-management_10.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxregisterwndclass"></a>AfxRegisterWndClass  
 Permite registrar suas próprias classes de janela.  
  
```  
LPCTSTR AFXAPI AfxRegisterWndClass(
    UINT nClassStyle,  
    HCURSOR hCursor = 0,  
    HBRUSH hbrBackground = 0,  
    HICON hIcon = 0);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nClassStyle*  
 Especifica o estilo de classe do Windows ou uma combinação de estilos, criados usando o OR bit a bit ( **|**) operador, para a classe de janela. Para obter uma lista de estilos de classe, consulte o [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura no SDK do Windows. Se **nulo**, os padrão serão definidos da seguinte maneira:  
  
-   Define o estilo de mouse **CS_DBLCLKS**, que envia duas vezes em mensagens para o procedimento de janela quando o usuário clica duas vezes o mouse.  
  
-   Define o estilo da seta de cursor para o padrão do Windows **IDC_ARROW**.  
  
-   Define o pincel do plano de fundo **nulo**, portanto, a janela não apagará seu plano de fundo.  
  
-   Define o ícone para o ícone do logotipo do Windows padrão, o sinalizador balançando.  
  
 `hCursor`  
 Especifica um identificador para o recurso de cursor a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, você obterá o padrão **IDC_ARROW** cursor.  
  
 *hbrBackground*  
 Especifica um identificador para o recurso de pincel para ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, você terá uma **nulo** pincel de plano de fundo e o janela será, por padrão, não apagar seu plano de fundo durante o processamento [WM_ERASEBKGND](http://msdn.microsoft.com/library/windows/desktop/ms648055).  
  
 `hIcon`  
 Especifica um identificador para o recurso de ícone a ser instalado em cada janela criada a partir da classe de janela. Se você usar o padrão de **0**, você obterá o ícone do logotipo do Windows padrão, o sinalizador balançando.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia terminada em nulo que contém o nome da classe. Você pode passar esse nome de classe para o **criar** função de membro em `CWnd` ou outros **CWnd -**classes para criar uma janela derivadas. O nome é gerado pela biblioteca Microsoft Foundation Class.  
  
> [!NOTE]
>  O valor de retorno é um ponteiro para um buffer estático. Para salvar essa cadeia de caracteres, atribuí-la a um `CString` variável.  
  
### <a name="remarks"></a>Comentários  
 A biblioteca Microsoft Foundation Class registra automaticamente várias classes de janela padrão para você. Chame essa função se você deseja registrar suas próprias classes de janela.  
  
 O nome registrado para uma classe por `AfxRegisterWndClass` exclusivamente depende dos parâmetros. Se você chamar `AfxRegisterWndClass` várias vezes com parâmetros idênticos, ele só registra uma classe na primeira chamada. As chamadas subsequentes para `AfxRegisterWndClass` com parâmetros idênticos simplesmente retornar o nome de classe já registrado.  
  
 Se você chamar `AfxRegisterWndClass` para várias classes derivadas CWnd com parâmetros idênticos, em vez de obter uma classe de janela separada para cada classe, cada classe compartilha a mesma classe de janela. Isso pode causar problemas se o **CS_CLASSDC** estilo de classe é usado. Em vez de vários **CS_CLASSDC** classes de janela, você acabará com uma **CS_CLASSDC** classe de janela e todas as janelas de C++ que usam a classe compartilham o mesmo controlador de domínio. Para evitar esse problema, chame [AfxRegisterClass](#afxregisterclass) para registrar a classe.  
  
 Consulte a nota técnica [TN001: registro da classe Window](../../mfc/tn001-window-class-registration.md) para obter mais informações sobre o registro de classe de janela e `AfxRegisterWndClass` função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #134](../../mfc/reference/codesnippet/cpp/application-information-and-management_11.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="afxsetperuserregistration"></a>AfxSetPerUserRegistration  
 Define se o aplicativo redireciona o acesso de registro para o **HKEY_CURRENT_USER** ( **HKCU**) nó.  
  
```  
void AFXAPI AfxSetPerUserRegistration(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava informações de registro para o nó de padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).  
  
### <a name="remarks"></a>Comentários  
 Antes de [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)], aplicativos que acessam o registro geralmente usam o **HKEY_CLASSES_ROOT** nó. No entanto, com [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)], você deve executar um aplicativo no modo elevado para gravar **HKCR**.  
  
 Esse método permite que seu aplicativo ler e gravar o registro sem executar no modo elevado redirecionando o acesso ao registro de **HKCR** para **HKCU**. Para obter mais informações, consulte [páginas de propriedade do vinculador](../../ide/linker-property-pages.md).  
  
 Se você habilitar o redirecionamento do registro, o framework redireciona o acesso de **HKCR** para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas de MFC e ATL são afetadas pelo redirecionamento.  
  
 A implementação padrão acessa o registro em **HKCR**.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxstat_.h    
  
##  <a name="afxsetresourcehandle"></a>AfxSetResourceHandle  
 Use esta função para definir o `HINSTANCE` identificador que determina onde os recursos padrão do aplicativo são carregados.  
  
```  
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstResource`  
 O identificador de instância ou o módulo para um. Arquivo EXE ou DLL do qual os recursos do aplicativo são carregados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing #135](../../mfc/reference/codesnippet/cpp/application-information-and-management_12.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  

## <a name="afxshellmanager"></a>AfxShellManager
Ponteiro para global [manager shell](cshellmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CShellManager* afxShellManager;  
```  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxshellmanager.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CShellManager](cshellmanager-class.md)
  
##  <a name="afxsocketinit"></a>AfxSocketInit  
 Chamar essa função em seu `CWinApp::InitInstance` substituição para inicializar o Windows Sockets.  
  
```  
BOOL AfxSocketInit(WSADATA* lpwsaData = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpwsaData`  
 Um ponteiro para um [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura. Se `lpwsaData` não é igual a `NULL`, em seguida, o endereço do `WSADATA` estrutura está preenchida pela chamada para `WSAStartup`. Essa função também garante que `WSACleanup` é chamado para você antes do encerramento do aplicativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread principal.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxsock.h  

## <a name="afxusertoolsmanager"></a>AfxUserToolsManager
Ponteiro para global [gerente do usuário ferramentas](cusertoolsmanager-class.md).  
   
### <a name="syntax"></a>Sintaxe    
```  
CUserToolsManager* afxUserToolsManager;  
```  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxusertoolsmanager.h  
   
### <a name="see-also"></a>Consulte também  
 [Classe CUserToolsManager](cusertoolsmanager-class.md)
 
  
##  <a name="afxwininit"></a>AfxWinInit  
 Essa função é chamada pelo fornecido a MFC `WinMain` função, como parte do [CWinApp](../../mfc/reference/cwinapp-class.md) inicialização de um aplicativo baseado em GUI, inicializar MFC.  
  
```  
BOOL AFXAPI AfxWinInit(
    HINSTANCE hInstance,  
    HINSTANCE hPrevInstance,  
    LPTSTR lpCmdLine,  
    int nCmdShow);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 O identificador do módulo em execução no momento.  
  
 *hPrevInstance*  
 Um identificador para uma instância anterior do aplicativo. Para um aplicativo Win32, este parâmetro é sempre **nulo**.  
  
 `lpCmdLine`  
 Aponta para uma cadeia de caracteres terminada em nulo especificando a linha de comando para o aplicativo.  
  
 `nCmdShow`  
 Especifica como a janela principal de um aplicativo de interface gráfica do usuário será mostrada.  
  
### <a name="remarks"></a>Comentários  
 Para um aplicativo de console, que não usa o MFC fornecido `WinMain` função, você deve chamar `AfxWinInit` diretamente ao inicializar MFC.  
  
 Se você chamar `AfxWinInit` por conta própria, você deve declarar uma instância de um `CWinApp` classe. Para um aplicativo de console, você pode optar por não derivar sua própria classe de `CWinApp` e usar uma instância de `CWinApp` diretamente. Essa técnica é apropriada se você optar por deixar toda a funcionalidade de seu aplicativo em sua implementação de **principal**.  
  
> [!NOTE]
>  Quando cria um contexto de ativação para um assembly, o MFC usa um recurso de manifesto fornecido pelo módulo de usuário. O contexto de ativação é criado no `AfxWinInit`. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../../mfc/support-for-activation-contexts-in-the-mfc-module-state.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_AfxWinInit n º 1](../../mfc/reference/codesnippet/cpp/application-information-and-management_13.cpp)]  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)

