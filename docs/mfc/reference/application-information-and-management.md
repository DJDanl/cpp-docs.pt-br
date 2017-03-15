---
title: "Informações do aplicativo e gerenciamento | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: cc9adde202f211d6e0a536e949b42772f0890ef6
ms.lasthandoff: 02/25/2017

---
# <a name="application-information-and-management"></a>Informações e gerenciamento do aplicativo
Quando você escreve um aplicativo, você cria um único [CWinApp](../../mfc/reference/cwinapp-class.md)-objeto derivado. Às vezes, convém obter informações sobre esse objeto de fora a `CWinApp`-objeto derivado.  
  
 A biblioteca Microsoft Foundation Class fornece as seguintes funções globais para ajudá-lo a realizar essas tarefas:  
  
### <a name="application-information-and-management-functions"></a>Informações do aplicativo e funções de gerenciamento  
  
|||  
|-|-|  
|[AfxBeginThread](#afxbeginthread)|Cria um novo thread.|  
|[AfxEndThread](#afxendthread)|Encerra o thread atual.|  
|[AfxFreeLibrary](#afxfreelibrary)|Diminui a contagem de referência do módulo carregado biblioteca de vínculo dinâmico (DLL); Quando a contagem de referência atinge zero, o módulo não está mapeado.|  
|[AfxGetApp](#afxgetapp)|Retorna um ponteiro para o aplicativo do único `CWinApp` objeto.|  
|[AfxGetAppName](#afxgetappname)|Retorna uma cadeia de caracteres que contém o nome do aplicativo.|  
|[AfxGetInstanceHandle](#afxgetinstancehandle)|Retorna um `HINSTANCE` que representa esta instância do aplicativo.|  
|[AfxGetMainWnd](#afxgetmainwnd)|Retorna um ponteiro para a janela atual "principal" de um aplicativo não são OLE ou a janela de quadro in-loco de um aplicativo de servidor.|  
|[AfxGetPerUserRegistration](#afxgetperuserregistration)|Use esta função para determinar se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AfxGetResourceHandle](#afxgetresourcehandle)|Retorna um `HINSTANCE` com a fonte de recursos do padrão do aplicativo. Use isto para acessar os recursos do aplicativo diretamente.|  
|[AfxGetThread](#afxgetthread)|Recupera um ponteiro para a atual [CWinThread](../../mfc/reference/cwinthread-class.md) objeto.|  
|[AfxInitRichEdit](#afxinitrichedit)|Inicializa a versão de controle para o aplicativo de edição avançado 1.0.|  
|[AfxInitRichEdit2](#afxinitrichedit2)|Inicializa a versão de controle para o aplicativo de edição avançado 2.0 e posterior.|  
|[AfxLoadLibrary](#afxloadlibrary)|Mapeia um módulo DLL e retorna um identificador que pode ser usado para obter o endereço de uma função de DLL.|  
|[AfxRegisterClass](#afxregisterclass)|Registra uma classe de janela em uma DLL que usa MFC.|  
|[AfxRegisterWndClass](#afxregisterwndclass)|Registra uma classe de janela do Windows para complementar as registradas automaticamente pelo MFC.|  
|[AfxSetPerUserRegistration](#afxsetperuserregistration)|Define se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** ( **HKCU**) nó.|  
|[AfxSetResourceHandle](#afxsetresourcehandle)|Conjuntos de `HINSTANCE` onde os recursos padrão do aplicativo são carregados de identificador.|  
|[AfxSocketInit](#afxsocketinit)|Chamado em um `CWinApp::InitInstance` substituição para inicializar o Windows Sockets.|  
|[AfxWinInit](#afxwininit)|Chamado pelo fornecido MFC `WinMain` função, como parte do [CWinApp](../../mfc/reference/cwinapp-class.md) inicialização de um aplicativo baseado em GUI, inicializar MFC. Deve ser chamado diretamente para aplicativos de console que usam o MFC.|  
  

  
##  <a name="a-nameafxbeginthreada--afxbeginthread"></a><a name="afxbeginthread"></a>AfxBeginThread  
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
 O RUNTIME_CLASS de um objeto derivado de [CWinThread](../../mfc/reference/cwinthread-class.md).  
  
 *pParam*  
 Parâmetro a ser passado para a função de controle, conforme mostrado no parâmetro para a declaração de função em `pfnThreadProc`.  
  
 `nPriority`  
 A prioridade desejada do thread. Para obter uma lista completa e descrição das prioridades disponíveis, consulte [SetThreadPriority](http://msdn.microsoft.com/library/windows/desktop/ms686277) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `nStackSize`  
 Especifica o tamanho em bytes da pilha para o novo thread. Se for 0, o tamanho da pilha padrão é a mesma pilha de tamanho como o thread de criação.  
  
 `dwCreateFlags`  
 Especifica um sinalizador adicional que controla a criação do thread. Este sinalizador pode conter um dos dois valores:  
  
- **CREATE_SUSPENDED** iniciar o thread com uma contagem de suspensões de um. Use **CREATE_SUSPENDED** para inicializar todos os dados de membro de `CWinThread` de objeto, como [m_bAutoDelete](../../mfc/reference/cwinthread-class.md#m_bautodelete) ou qualquer membro da sua classe derivada, antes do segmento começa a ser executado. Quando a inicialização estiver concluída, use [CWinThread::ResumeThread](../../mfc/reference/cwinthread-class.md#resumethread) para iniciar o thread em execução. O thread não será executado até `CWinThread::ResumeThread` é chamado.  
  
- **0** iniciar o thread imediatamente após a criação.  
  
 `lpSecurityAttrs`  
 Aponta para um [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica os atributos de segurança para o thread. Se **nulo**, a mesma segurança atributos como o thread de criação será usado. Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o objeto thread criado recentemente, ou **nulo** se ocorrer uma falha.  
  
### <a name="remarks"></a>Comentários  
 A primeira forma da `AfxBeginThread` cria um thread de trabalho. O segundo formulário cria um thread que pode servir como um thread de interface do usuário ou um thread de trabalho.  
  
 `AfxBeginThread`cria um novo `CWinThread` objeto, chamadas de seu [CreateThread](../../mfc/reference/cwinthread-class.md#createthread) de função para iniciar a execução do thread e retorna um ponteiro para o thread. Verificações são feitas em todo o procedimento para verificar se que todos os objetos são desalocados corretamente qualquer parte da criação de falhar. Para finalizar o thread, chame [AfxEndThread](#afxendthread) de dentro do thread ou o retorno da função de controle do thread de trabalho.  
  
 Multithreading deve ser habilitado pelo aplicativo; Caso contrário, a função falhará. Para obter mais informações sobre como habilitar multithreading, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) em *opções de compilador do Visual C++*.  
  
 Para obter mais informações sobre `AfxBeginThread`, consulte os artigos [Multithreading: Criando Threads de trabalho](../../parallel/multithreading-creating-worker-threads.md) e [Multithreading: Criando Threads de Interface do usuário](../../parallel/multithreading-creating-user-interface-threads.md).  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CSocket::Attach](../../mfc/reference/csocket-class.md#attach).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxendthreada--afxendthread"></a><a name="afxendthread"></a>AfxEndThread  
 Chame essa função para encerrar o thread atualmente em execução.  
  
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
 Deve ser chamado de dentro do thread seja finalizado.  
  
 Para obter mais informações sobre `AfxEndThread`, consulte o artigo [Multithreading: encerrando Threads](../../parallel/multithreading-terminating-threads.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxfreelibrarya--afxfreelibrary"></a><a name="afxfreelibrary"></a>AfxFreeLibrary  
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
 `AfxFreeLibrary`diminui a contagem de referência do módulo carregado biblioteca de vínculo dinâmico (DLL). Quando a contagem de referência atinge zero, o módulo não está mapeado no espaço de endereço do processo de chamada e o identificador não é válido. Essa contagem de referência é incrementada sempre que `AfxLoadLibrary` é chamado.  
  
 Antes de desmapeá um módulo de biblioteca, o sistema permite que a DLL de desanexar os processos de usá-lo. Isso dá a DLL uma oportunidade para limpar os recursos alocados em nome do processo atual. Depois que a função de ponto de entrada retorna, o módulo de biblioteca é removido do espaço de endereço do processo atual.  
  
 Use `AfxLoadLibrary` para mapear um módulo DLL.  
  
 Certifique-se de usar `AfxFreeLibrary` e `AfxLoadLibrary` (em vez de funções do Win32 **FreeLibrary** e **LoadLibrary**) se o aplicativo usa vários threads. Usando `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e desligamento é executado quando a extensão DLL é carregado e descarregado não corromper o estado global do MFC.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [AfxLoadLibrary](#afxloadlibrary).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdll_.h  
  
##  <a name="a-nameafxgetappa--afxgetapp"></a><a name="afxgetapp"></a>AfxGetApp  
 O ponteiro retornado por essa função pode ser usado para acessar informações do aplicativo, como o código de envio de mensagem principal ou a janela de nível superior.  
  
```   
CWinApp* AFXAPI AfxGetApp(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o único `CWinApp` objeto para o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Se esse método retornará nulo, isso pode indicar que o â €™ janela principal não foi completamente inicializada ainda. Ele também pode indicar um problema.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#126;](../../mfc/reference/codesnippet/cpp/application-information-and-management_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxgetappnamea--afxgetappname"></a><a name="afxgetappname"></a>AfxGetAppName  
 A cadeia de caracteres retornada por essa função pode ser usada para mensagens de diagnóstico ou como uma raiz para nomes de cadeia de caracteres temporária.  
  
```   
LPCTSTR AFXAPI AfxGetAppName(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia terminada em nulo que contém o nome do aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#127;](../../mfc/reference/codesnippet/cpp/application-information-and-management_2.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxgetinstancehandlea--afxgetinstancehandle"></a><a name="afxgetinstancehandle"></a>AfxGetInstanceHandle  
 Essa função permite que você recupere o identificador de instância do aplicativo atual.  
  
```   
HINSTANCE  AFXAPI AfxGetInstanceHandle(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HINSTANCE` à instância atual do aplicativo. Se for chamado de dentro de uma DLL vinculada com a versão USRDLL do MFC, um `HINSTANCE` para a DLL é retornado.  
  
### <a name="remarks"></a>Comentários  
 `AfxGetInstanceHandle`sempre retorna o `HINSTANCE` do seu arquivo executável (. EXE), a menos que ele é chamado de dentro uma DLL vinculado com a versão USRDLL do MFC. Nesse caso, ele retorna um `HINSTANCE` para a DLL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#128;](../../mfc/reference/codesnippet/cpp/application-information-and-management_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxgetmainwnda--afxgetmainwnd"></a><a name="afxgetmainwnd"></a>AfxGetMainWnd  
 Se seu aplicativo for um servidor OLE, chame essa função para recuperar um ponteiro para a janela principal ativa do aplicativo em vez de referir-se diretamente para o [m_pMainWnd](../../mfc/reference/cwinthread-class.md#m_pmainwnd) membro do objeto do aplicativo.  
  
```   
CWnd* AFXAPI AfxGetMainWnd(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o servidor tiver um objeto que está no local ativo dentro de um contêiner e esse contêiner estiver ativo, essa função retorna um ponteiro para o objeto de janela do quadro que contém o documento ativo no local.  
  
 Se não há nenhum objeto está ativo no local dentro de um contêiner ou seu aplicativo não é um servidor OLE, essa função simplesmente retorna o `m_pMainWnd` do objeto do aplicativo.  
  
 Se `AfxGetMainWnd` é chamado de thread principal do aplicativo, ele retorna a janela principal do aplicativo de acordo com as regras acima. Se a função é chamada de um thread secundário no aplicativo, a função retorna a janela principal associada ao thread que fez a chamada.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo não é um servidor OLE, chamar essa função é equivalente ao referir-se diretamente para o `m_pMainWnd` membro do objeto do aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#129;](../../mfc/reference/codesnippet/cpp/application-information-and-management_4.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxgetperuserregistrationa--afxgetperuserregistration"></a><a name="afxgetperuserregistration"></a>AfxGetPerUserRegistration  
 Use esta função para determinar se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** ( **HKCU**) nó.  
  
```  
BOOL AFXAPI AfxGetPerUserRegistration();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava as informações de registro do nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).  
  
### <a name="remarks"></a>Comentários  
 Se você habilitar o redirecionamento do registro, o framework redireciona o acesso de **HKCR** para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.  
  
 Para alterar se o aplicativo redireciona o acesso ao registro, use [AfxSetPerUserRegistration](#afxsetperuserregistration).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxstat_.h    
  
##  <a name="a-nameafxgetresourcehandlea--afxgetresourcehandle"></a><a name="afxgetresourcehandle"></a>AfxGetResourceHandle  
 Use o `HINSTANCE` identificador retornado por essa função para acessar os recursos do aplicativo diretamente, por exemplo, em chamadas para a função do Windows **FindResource**.  
  
```   
extern HINSTANCE  AfxGetResourceHandle(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HINSTANCE` identificador onde os recursos padrão do aplicativo são carregados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#130;](../../mfc/reference/codesnippet/cpp/application-information-and-management_5.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxgetthreada--afxgetthread"></a><a name="afxgetthread"></a>AfxGetThread  
 Chame essa função para obter um ponteiro para o [CWinThread](../../mfc/reference/cwinthread-class.md) objeto que representa o thread atualmente em execução.  
  
```   
CWinThread* AfxGetThread(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o thread atualmente em execução. Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Deve ser chamado de dentro do thread desejado.  
  
> [!NOTE]
>  Se você estiver portando uma chamada de projeto MFC `AfxGetThread` de versões do Visual C++ 4.2, 5.0 ou 6.0, `AfxGetThread` chamadas [AfxGetApp](#afxgetapp) se nenhum thread é encontrado. No Visual c++ .NET e posterior, `AfxGetThread` retorna **nulo** se nenhum thread foi encontrado. Se você quiser que o thread do aplicativo, você deve chamar `AfxGetApp`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&132;](../../mfc/reference/codesnippet/cpp/application-information-and-management_6.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxinitrichedita--afxinitrichedit"></a><a name="afxinitrichedit"></a>AfxInitRichEdit  
 Chame essa função para inicializar o controle rich edit (versão 1.0) para o aplicativo.  
  
```   
BOOL AFXAPI AfxInitRichEdit(); 
```  
  
### <a name="remarks"></a>Comentários  
 Esta função é fornecida para compatibilidade com versões anteriores. Os aplicativos criados com o Visual C++ .NET e o uso posterior [AfxInitRichEdit2](#afxinitrichedit2).  
  
 `AfxInitRichEdit`carrega RICHED32. DLL para inicializar o controle rich edit versão 1.0. Para usar a versão 2.0 e 3.0 do controle rich edit, RICHED20. DLL precisa ser carregada. Isso é feito com uma chamada para [AfxInitRichEdit2](#afxinitrichedit2). Se você tiver recursos de caixa de diálogo com o controle rich edit criado antes do Visual C++ .NET, os controles de edição avançados são automaticamente versão 1.0. Controles de edição de rich inseridos usando o Editor de recursos do Visual C++ .NET são versão 2.0.  
  
 Para atualizar os controles de edição avançados em aplicativos existentes do Visual C++ para a versão 2.0, abra o. Arquivo RC como texto, altere o nome da classe de cada controle rich edit de "RICHEDIT" para "RichEdit20a". Em seguida, substitua a chamada para `AfxInitRichEdit` com `AfxInitRichEdit2`.  
  
 Essa função também inicializa a biblioteca de controles comuns, se a biblioteca já não foi inicializada para o processo. Se você usar o controle rich edit diretamente do seu aplicativo do MFC, você deve chamar essa função para garantir que MFC foi inicializado corretamente o tempo de execução do controle de edição avançada. Se você chamar o método Create da [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md), ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), você normalmente não precisa chamar essa função, mas em alguns casos, pode ser necessário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxinitrichedit2a--afxinitrichedit2"></a><a name="afxinitrichedit2"></a>AfxInitRichEdit2  
 Chame essa função para inicializar o controle rich edit (versão 2.0 e posterior) para o aplicativo.  
  
```   
BOOL AFXAPI AfxInitRichEdit2(); 
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para carregar o RICHED20. Controle de edição de DLL e inicializar a versão 2.0 do sofisticado. Se você chamar o método Create da [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md), [CRichEditView](../../mfc/reference/cricheditview-class.md), ou [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), você normalmente não precisa chamar essa função, mas em alguns casos, pode ser necessário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxloadlibrarya--afxloadlibrary"></a><a name="afxloadlibrary"></a>AfxLoadLibrary  
 Use `AfxLoadLibrary` para mapear um módulo DLL.  
  
```   
HINSTANCE AFXAPI AfxLoadLibrary(LPCTSTR lpszModuleName); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszModuleName*  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do módulo (qualquer um. DLL ou. Arquivo EXE). O nome especificado é o nome do arquivo do módulo.  
  
 Se a cadeia de caracteres Especifica um caminho, mas o arquivo não existir no diretório especificado, a função falhará.  
  
 Se um caminho não for especificado e a extensão de nome de arquivo for omitida, a extensão padrão. DLL é anexado. No entanto, a cadeia de caracteres de nome de arquivo pode incluir um caractere à direita do ponto (.) para indicar que o nome do módulo não tem extensão. Quando nenhum caminho for especificado, a função de pesquisa para o arquivo na sequência a seguir:  
  
-   O diretório do qual o aplicativo é carregado.  
  
-   O diretório atual.  
  
- **Windows 95/98:** o diretório de sistema do Windows. **Windows NT:** o diretório de sistema do Windows de 32 bits. O nome desta pasta é SYSTEM32.  
  
- **Somente Windows NT:** diretório de sistema do Windows a 16 bits. Não há nenhuma função Win32 que obtém o caminho desse diretório, mas é pesquisado. O nome desta pasta é SYSTEM.  
  
-   O diretório do Windows.  
  
-   Os diretórios que são listados na variável de ambiente PATH.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é um identificador para o módulo. Se a função falhar, o valor de retorno será NULL.  
  
### <a name="remarks"></a>Comentários  
 Ele retorna um identificador que pode ser usado em [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212) para obter o endereço de uma função DLL. `AfxLoadLibrary`também pode ser usado para mapear outros módulos executáveis.  
  
 Cada processo mantém uma contagem de referência para cada módulo carregado de biblioteca. Essa contagem de referência é incrementada sempre `AfxLoadLibrary` é chamado e é decrementado sempre `AfxFreeLibrary` é chamado. Quando a contagem de referência atinge zero, o módulo não está mapeado no espaço de endereço do processo de chamada e o identificador não é válido.  
  
 Certifique-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez de funções do Win32 **LoadLibrary** e **FreeLibrary**) se seu aplicativo usa vários threads e se ele dinamicamente carrega uma DLL de extensão. Usando `AfxLoadLibrary` e `AfxFreeLibrary` assegura que o código de inicialização e desligamento é executado quando a DLL de extensão é carregado e descarregado não corromper o estado global do MFC.  
  
 Usando `AfxLoadLibrary` em um aplicativo requer que você vincule dinamicamente para a versão DLL do MFC; o arquivo de cabeçalho para `AfxLoadLibrary`, Afxdll_.h, só é incluída se MFC está vinculado ao aplicativo como uma DLL. Isso ocorre por design, porque você precisa vincular para a versão DLL do MFC para usar ou criar DLLs de extensão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_DLLUser n º&1;](../../mfc/reference/codesnippet/cpp/application-information-and-management_7.cpp)]  
[!code-cpp[NVC_MFC_DLLUser n º&2;](../../mfc/reference/codesnippet/cpp/application-information-and-management_8.cpp)]  
[!code-cpp[NVC_MFC_DLLUser n º&3;](../../mfc/reference/codesnippet/cpp/application-information-and-management_9.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdll_.h  
   
  
##  <a name="a-nameafxregisterclassa--afxregisterclass"></a><a name="afxregisterclass"></a>AfxRegisterClass  
 Use esta função para registrar classes de janela em uma DLL que usa MFC.  
  
```   
BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpWndClass*  
 Ponteiro para uma [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura que contém informações sobre a classe de janela a ser registrado. Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a classe for com êxito registrado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Se você usar essa função, a classe é cancelada automaticamente quando a DLL é descarregada.  
  
 Em compilações de DLL não o `AfxRegisterClass` identificador está definido como uma macro que mapeia para a função do Windows **RegisterClass**, já que as classes registradas em um aplicativo não são registrados automaticamente. Se você usar `AfxRegisterClass` em vez de **RegisterClass**, seu código pode ser usado sem alteração em um aplicativo e em uma DLL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_DLL N º&3;](../../atl-mfc-shared/codesnippet/cpp/application-information-and-management_10.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxregisterwndclassa--afxregisterwndclass"></a><a name="afxregisterwndclass"></a>AfxRegisterWndClass  
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
 Especifica o estilo de classe do Windows ou uma combinação de estilos, criado usando o OR bit a bit ( **|**) operador, para a classe de janela. Para obter uma lista de estilos de classe, consulte o [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Se **nulo**, o padrão será definido da seguinte maneira:  
  
-   Define o estilo do mouse **CS_DBLCLKS**, que envia duas vezes em mensagens para o procedimento de janela quando o usuário clica duas vezes o mouse.  
  
-   Define o estilo da seta de cursor para o padrão do Windows **IDC_ARROW**.  
  
-   Define o pincel do plano de fundo **nulo**, portanto, a janela não apagará seu plano de fundo.  
  
-   Define o ícone para o ícone do logotipo do Windows padrão, o sinalizador movimentar.  
  
 `hCursor`  
 Especifica um identificador para o recurso de cursor para ser instalado em cada janela criada da classe de janela. Se você usar o padrão de **0**, você obterá o padrão **IDC_ARROW** cursor.  
  
 *hbrBackground*  
 Especifica um identificador para o recurso de pincel a ser instalado em cada janela criada da classe de janela. Se você usar o padrão de **0**, você terá um **nulo** Pincel do plano de fundo e a janela será, por padrão, não apagar seu plano de fundo durante o processamento [WM_ERASEBKGND](http://msdn.microsoft.com/library/windows/desktop/ms648055).  
  
 `hIcon`  
 Especifica um identificador para o recurso de ícone a ser instalado em cada janela criada da classe de janela. Se você usar o padrão de **0**, você obterá o ícone do logotipo do Windows padrão, o sinalizador movimentar.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia terminada em nulo que contém o nome da classe. Você pode passar esse nome de classe para o **criar** função de membro em `CWnd` ou outros **CWnd -**derivado classes para criar uma janela. O nome é gerado pela biblioteca Microsoft Foundation Class.  
  
> [!NOTE]
>  O valor de retorno é um ponteiro para um buffer estático. Para salvar essa cadeia de caracteres, atribuí-la a um `CString` variável.  
  
### <a name="remarks"></a>Comentários  
 A biblioteca Microsoft Foundation Class registra automaticamente várias classes de janela padrão. Chame essa função se você quiser registrar suas próprias classes de janela.  
  
 O nome registrado para uma classe por `AfxRegisterWndClass` depende exclusivamente dos parâmetros. Se você chamar `AfxRegisterWndClass` várias vezes com parâmetros idênticos, ele só registra uma classe na primeira chamada. As chamadas subsequentes para `AfxRegisterWndClass` com parâmetros idênticos simplesmente retornar o nome de classe já registrado.  
  
 Se você chamar `AfxRegisterWndClass` para várias classes derivadas CWnd com parâmetros idênticos, em vez de uma classe de janela separada para cada classe, cada classe compartilha a mesma classe de janela. Isso pode causar problemas se o **CS_CLASSDC** estilo de classe é usado. Em vez de vários **CS_CLASSDC** classes de janela, você acabará com um **CS_CLASSDC** classe de janela e todas as janelas do C++ que usam a classe compartilham o mesmo controlador de domínio. Para evitar esse problema, chame [AfxRegisterClass](#afxregisterclass) para registrar a classe.  
  
 Consulte a nota técnica [TN001: registro da classe Window](../../mfc/tn001-window-class-registration.md) para obter mais informações sobre o registro de classe de janela e o `AfxRegisterWndClass` função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#134;](../../mfc/reference/codesnippet/cpp/application-information-and-management_11.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxsetperuserregistrationa--afxsetperuserregistration"></a><a name="afxsetperuserregistration"></a>AfxSetPerUserRegistration  
 Define se o aplicativo redireciona o acesso ao registro de **HKEY_CURRENT_USER** ( **HKCU**) nó.  
  
```  
void AFXAPI AfxSetPerUserRegistration(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`indica que as informações de registro são direcionadas para o **HKCU** nó; `FALSE` indica que o aplicativo grava as informações de registro do nó padrão. O nó padrão é **HKEY_CLASSES_ROOT** ( **HKCR**).  
  
### <a name="remarks"></a>Comentários  
 Antes de [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)], aplicativos que acessam o registro geralmente usam o **HKEY_CLASSES_ROOT** nó. No entanto, com [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)], você deve executar um aplicativo no modo elevado para gravar **HKCR**.  
  
 Esse método permite que seu aplicativo ler e gravar no registro sem executar no modo elevado ao redirecionar o acesso ao registro de **HKCR** para **HKCU**. Para obter mais informações, consulte [páginas de propriedade do vinculador](../../ide/linker-property-pages.md).  
  
 Se você habilitar o redirecionamento do registro, o framework redireciona o acesso de **HKCR** para **HKEY_CURRENT_USER\Software\Classes**. Somente as estruturas MFC e ATL são afetadas pelo redirecionamento.  
  
 A implementação padrão acessa o registro em **HKCR**.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxstat_.h    
  
##  <a name="a-nameafxsetresourcehandlea--afxsetresourcehandle"></a><a name="afxsetresourcehandle"></a>AfxSetResourceHandle  
 Use esta função para definir o `HINSTANCE` identificador que determina onde os recursos padrão do aplicativo são carregados.  
  
```  
 
void  
AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstResource`  
 O identificador de instância ou módulo para um. Arquivo EXE ou DLL do que os recursos do aplicativo são carregados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#135;](../../mfc/reference/codesnippet/cpp/application-information-and-management_12.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="a-nameafxsocketinita--afxsocketinit"></a><a name="afxsocketinit"></a>AfxSocketInit  
 Chamar essa função em seu `CWinApp::InitInstance` substituição para inicializar o Windows Sockets.  
  
```  
 
BOOL  
AfxSocketInit(WSADATA* lpwsaData = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpwsaData`  
 Um ponteiro para um [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura. Se `lpwsaData` não é igual a `NULL`, em seguida, o endereço do `WSADATA` estrutura é preenchida pela chamada para `WSAStartup`. Esta função garante que `WSACleanup` é chamado para você antes que o aplicativo é encerrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread primário.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxsock.h  
  
##  <a name="a-nameafxwininita--afxwininit"></a><a name="afxwininit"></a>AfxWinInit  
 Essa função é chamada, o MFC fornecido `WinMain` função, como parte do [CWinApp](../../mfc/reference/cwinapp-class.md) inicialização de um aplicativo baseado em GUI, inicializar MFC.  
  
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
 Um identificador para uma instância anterior do aplicativo. Para um aplicativo baseado no Win32, este parâmetro é sempre **nulo**.  
  
 `lpCmdLine`  
 Aponta para uma cadeia de caracteres terminada em nulo especificando a linha de comando para o aplicativo.  
  
 `nCmdShow`  
 Especifica como a janela principal do aplicativo de GUI deve ser mostrada.  
  
### <a name="remarks"></a>Comentários  
 Para um aplicativo de console que não usa o MFC fornecido `WinMain` função, você deve chamar `AfxWinInit` diretamente ao inicializar MFC.  
  
 Se você chamar `AfxWinInit` por conta própria, você deve declarar uma instância de um `CWinApp` classe. Para um aplicativo de console, você pode optar por não derivar sua própria classe de `CWinApp` e usar uma instância de `CWinApp` diretamente. Essa técnica é apropriada se você decidir deixar toda a funcionalidade do seu aplicativo em sua implementação de **principal**.  
  
> [!NOTE]
>  Quando cria um contexto de ativação para um assembly, o MFC usa um recurso de manifesto fornecido pelo módulo do usuário. O contexto de ativação é criado no `AfxWinInit`. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../../mfc/support-for-activation-contexts-in-the-mfc-module-state.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_AfxWinInit n º&1;](../../mfc/reference/codesnippet/cpp/application-information-and-management_13.cpp)]  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)

