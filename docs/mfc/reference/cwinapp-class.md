---
title: Classe CWinApp | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWinApp
- hInstance
dev_langs:
- C++
helpviewer_keywords:
- CWinApp class
- application objects [C++]
- HINSTANCE
- main object
ms.assetid: e426a3cd-0d15-40d6-bd55-beaa5feb2343
caps.latest.revision: 27
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
ms.openlocfilehash: 292816c8f753a7b47b563a3fcd0fa336e08acd6a
ms.lasthandoff: 02/25/2017

---
# <a name="cwinapp-class"></a>Classe CWinApp
A classe base da qual você derivar um objeto de aplicativo do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWinApp : public CWinThread  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::CWinApp](#cwinapp)|Constrói um objeto `CWinApp`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::AddDocTemplate](#adddoctemplate)|Adiciona um modelo de documento lista do aplicativo de modelos de documento disponíveis.|  
|[CWinApp::AddToRecentFileList](#addtorecentfilelist)|Adiciona um nome de arquivo à lista de arquivos usada mais recentemente (MRU).|  
|[CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback)|Chamado pela estrutura quando o aplicativo é encerrado inesperadamente.|  
|[CWinApp::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos abertos.|  
|[CWinApp::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo da impressora.|  
|[CWinApp::DelRegTree](#delregtree)|Exclui uma chave especificada e todas as suas subchaves.|  
|[CWinApp::DoMessageBox](#domessagebox)|Implementa [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para o aplicativo.|  
|[CWinApp::DoWaitCursor](#dowaitcursor)|Ativa e desativa o cursor de espera.|  
|[CWinApp::EnableD2DSupport](#enabled2dsupport)|Permite que o aplicativo `D2D` suporte. Chame esse método antes da janela principal é inicializada.|  
|[CWinApp::EnableHtmlHelp](#enablehtmlhelp)|Implementa Help para o aplicativo, em vez de WinHelp.|  
|[CWinApp::EnableTaskbarInteraction](#enabletaskbarinteraction)|Habilita a interação de barra de tarefas.|  
|[CWinApp::ExitInstance](#exitinstance)|Substituição para a limpeza quando seu aplicativo terminar.|  
|[CWinApp::GetApplicationRecoveryParameter](#getapplicationrecoveryparameter)|Recupera o parâmetro de entrada para o método de recuperação do aplicativo.|  
|[CWinApp::GetApplicationRecoveryPingInterval](#getapplicationrecoverypinginterval)|Retorna o período de tempo que o Gerenciador de reinicialização aguarda que a função de retorno de chamada de recuperação retornar.|  
|[CWinApp::GetApplicationRestartFlags](#getapplicationrestartflags)|Retorna os sinalizadores para o Gerenciador de reinicialização.|  
|[CWinApp::GetAppRegistryKey](#getappregistrykey)|Chave HKEY_CURRENT_USER retorna\\\RegistryKey\ProfileName "Software".|  
|[CWinApp::GetDataRecoveryHandler](#getdatarecoveryhandler)|Obtém o manipulador de recuperação de dados para essa instância do aplicativo.|  
|[CWinApp::GetFirstDocTemplatePosition](#getfirstdoctemplateposition)|Recupera a posição do primeiro modelo de documento.|  
|[CWinApp::GetHelpMode](#gethelpmode)|Recupera o tipo de Ajuda usado pelo aplicativo.|  
|[CWinApp::GetNextDocTemplate](#getnextdoctemplate)|Recupera a posição de um modelo de documento. Pode ser usado repetidamente.|  
|[CWinApp::GetPrinterDeviceDefaults](#getprinterdevicedefaults)|Recupera os padrões de dispositivo da impressora.|  
|[CWinApp::GetProfileBinary](#getprofilebinary)|Recupera dados binários de uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::GetProfileInt](#getprofileint)|Recupera um número inteiro de uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::GetProfileString](#getprofilestring)|Recupera uma cadeia de caracteres de uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::GetSectionKey](#getsectionkey)|Chave HKEY_CURRENT_USER retorna\\\RegistryKey\AppName\lpszSection "Software".|  
|[CWinApp::HideApplication](#hideapplication)|Oculta o aplicativo antes de fechar todos os documentos.|  
|[CWinApp::HtmlHelp](#htmlhelp)|Chamadas de `HTMLHelp` função do Windows.|  
|[CWinApp::InitInstance](#initinstance)|Substitua para efetuar uma inicialização de instância do Windows, como a criação de seus objetos de janela.|  
|[CWinApp::IsTaskbarInteractionEnabled](#istaskbarinteractionenabled)|Informa se a interação da barra de tarefas do Windows 7 está habilitada.|  
|[CWinApp::LoadCursor](#loadcursor)|Carrega um recurso de cursor.|  
|[CWinApp::LoadIcon](#loadicon)|Carrega um recurso de ícone.|  
|[CWinApp::LoadOEMCursor](#loadoemcursor)|Carrega um OEM Windows predefinidos de cursor que o **OCR_** especificar constantes no WINDOWS. H.|  
|[CWinApp::LoadOEMIcon](#loadoemicon)|Carrega um ícone predefinido de OEM do Windows que o **OIC_** especificar constantes no WINDOWS. H.|  
|[CWinApp::LoadStandardCursor](#loadstandardcursor)|Carrega um Windows predefinidos de cursor que o **IDC _** especificar constantes no WINDOWS. H.|  
|[CWinApp::LoadStandardIcon](#loadstandardicon)|Carrega um ícone predefinido do Windows que o **IDI_** especificar constantes no WINDOWS. H.|  
|[CWinApp::OnDDECommand](#onddecommand)|Chamado pela estrutura em resposta a um dynamic data exchange (DDE) execute o comando.|  
|[CWinApp::OnIdle](#onidle)|Substitua para executar o processamento de tempo ocioso específicas do aplicativo.|  
|[CWinApp::OpenDocumentFile](#opendocumentfile)|Chamado pela estrutura para abrir um documento de um arquivo.|  
|[CWinApp::ParseCommandLine](#parsecommandline)|Analisa os parâmetros individuais e sinalizadores na linha de comando.|  
|[CWinApp::PreTranslateMessage](#pretranslatemessage)|Filtra as mensagens antes de serem distribuídos para as funções do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934).|  
|[CWinApp::ProcessMessageFilter](#processmessagefilter)|Intercepta determinadas mensagens antes que elas atinjam o aplicativo.|  
|[CWinApp::ProcessShellCommand](#processshellcommand)|Lida com sinalizadores e argumentos de linha de comando.|  
|[CWinApp::ProcessWndProcException](#processwndprocexception)|Intercepta todas as exceções sem tratamento lançadas por manipuladores de comandos e de mensagem do aplicativo.|  
|[CWinApp::Register](#register)|Executa o registro personalizado.|  
|[CWinApp::RegisterWithRestartManager](#registerwithrestartmanager)|Registra o aplicativo com o Gerenciador de reinicialização.|  
|[CWinApp::ReopenPreviousFilesAtRestart](#reopenpreviousfilesatrestart)|Determina se o Gerenciador de reinicialização reabre os arquivos que estavam abertos quando o aplicativo foi encerrado inesperadamente.|  
|[CWinApp::RestartInstance](#restartinstance)|Lida com uma reinicialização do aplicativo iniciada pelo Gerenciador de reinicialização.|  
|[CWinApp::RestoreAutosavedFilesAtRestart](#restoreautosavedfilesatrestart)|Determina se o Gerenciador de reinicialização restaura os arquivos de salva automaticamente quando o aplicativo for reiniciado.|  
|[CWinApp:: Run](#run)|Executa o loop de mensagem padrão. Substituição para personalizar o loop de mensagem.|  
|[CWinApp::RunAutomated](#runautomated)|Testes de linha de comando do aplicativo para o **/Automation** opção. Obsoleto. Em vez disso, use o valor em [CCommandLineInfo::m_bRunAutomated](../../mfc/reference/ccommandlineinfo-class.md#m_brunautomated) depois de chamar [ParseCommandLine](#parsecommandline).|  
|[CWinApp::RunEmbedded](#runembedded)|Testes de linha de comando do aplicativo para o **/incorporação** opção. Obsoleto. Em vez disso, use o valor em [CCommandLineInfo::m_bRunEmbedded](../../mfc/reference/ccommandlineinfo-class.md#m_brunembedded) depois de chamar [ParseCommandLine](#parsecommandline).|  
|[CWinApp::SaveAllModified](#saveallmodified)|Solicita ao usuário para salvar os documentos modificados tudo.|  
|[CWinApp::SelectPrinter](#selectprinter)|Seleciona uma impressora indicada por um usuário através de uma caixa de diálogo de impressão.|  
|[CWinApp::SetHelpMode](#sethelpmode)|Define e inicializa o tipo de Ajuda usado pelo aplicativo.|  
|[CWinApp::SupportsApplicationRecovery](#supportsapplicationrecovery)|Determina se o Gerenciador de reinicialização recupera um aplicativo que foi encerrado inesperadamente.|  
|[CWinApp::SupportsAutosaveAtInterval](#supportsautosaveatinterval)|Determina se o restart manager salve abre documentos em intervalos regulares.|  
|[CWinApp::SupportsAutosaveAtRestart](#supportsautosaveatrestart)|Determina se o restart manager Salve quaisquer documentos abertos quando o aplicativo for reiniciado.|  
|[CWinApp::SupportsRestartManager](#supportsrestartmanager)|Determina se o aplicativo suporta o Gerenciador de reinicialização.|  
|[CWinApp::Unregister](#unregister)|Cancela o registro tudo conhecido por ser registrado, o `CWinApp` objeto.|  
|[CWinApp::WinHelp](#winhelp)|Chamadas de `WinHelp` função do Windows.|  
|[CWinApp::WriteProfileBinary](#writeprofilebinary)|Grava dados binários em uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::WriteProfileInt](#writeprofileint)|Grava uma entrada no aplicativo de um número inteiro. Arquivo INI.|  
|[CWinApp::WriteProfileString](#writeprofilestring)|Grava uma cadeia de caracteres em uma entrada do aplicativo. Arquivo INI.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::EnableShellOpen](#enableshellopen)|Permite que o usuário abra arquivos de dados do Gerenciador de arquivos do Windows.|  
|[CWinApp::LoadStdProfileSettings](#loadstdprofilesettings)|Padrão de carga. Configurações do arquivo INI e permite que o MRU arquivo recurso de lista.|  
|[CWinApp::OnContextHelp](#oncontexthelp)|Lida com SHIFT + F1 Ajuda dentro do aplicativo.|  
|[CWinApp::OnFileNew](#onfilenew)|Implementa o `ID_FILE_NEW` comando.|  
|[CWinApp::OnFileOpen](#onfileopen)|Implementa o `ID_FILE_OPEN` comando.|  
|[CWinApp::OnFilePrintSetup](#onfileprintsetup)|Implementa o `ID_FILE_PRINT_SETUP` comando.|  
|[CWinApp::OnHelp](#onhelp)|Manipula a Ajuda F1 dentro do aplicativo (usando o contexto atual).|  
|[CWinApp::OnHelpFinder](#onhelpfinder)|Manipula o `ID_HELP_FINDER` e `ID_DEFAULT_HELP` comandos.|  
|[CWinApp::OnHelpIndex](#onhelpindex)|Manipula o `ID_HELP_INDEX` de comando e fornece um tópico da Ajuda padrão.|  
|[CWinApp::OnHelpUsing](#onhelpusing)|Manipula o `ID_HELP_USING` comando.|  
|[CWinApp::RegisterShellFileTypes](#registershellfiletypes)|Registra tipos de documento do todos os aplicativos com o Gerenciador de arquivos do Windows.|  
|[CWinApp::SetAppID](#setappid)|Define explicitamente o ID de modelo de usuário do aplicativo para o aplicativo. Esse método deve ser chamado antes de qualquer interface do usuário é apresentado ao usuário (o melhor local é o construtor de aplicativo).|  
|[CWinApp::SetRegistryKey](#setregistrykey)|Faz com que as configurações de aplicativo a ser armazenado no registro, em vez de. Arquivos INI.|  
|[CWinApp::UnregisterShellFileTypes](#unregistershellfiletypes)|Cancela o registro de tipos de documento do todos os aplicativos com o Gerenciador de arquivos do Windows.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::m_bHelpMode](#m_bhelpmode)|Indica se o usuário está no modo de contexto de Ajuda (normalmente chamado com SHIFT + F1).|  
|[CWinApp::m_eHelpType](#m_ehelptype)|Especifica o tipo de Ajuda usado pelo aplicativo.|  
|[CWinApp::m_hInstance](#m_hinstance)|Identifica a instância atual do aplicativo.|  
|[CWinApp::m_lpCmdLine](#m_lpcmdline)|Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo.|  
|[CWinApp::m_nCmdShow](#m_ncmdshow)|Especifica como a janela é exibido inicialmente.|  
|[CWinApp::m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo de contêiner quando um servidor OLE está ativo no local.|  
|[CWinApp::m_pszAppID](#m_pszappid)|ID do modelo de usuário do aplicativo.|  
|[CWinApp::m_pszAppName](#m_pszappname)|Especifica o nome do aplicativo.|  
|[CWinApp::m_pszExeName](#m_pszexename)|O nome do módulo do aplicativo.|  
|[CWinApp::m_pszHelpFilePath](#m_pszhelpfilepath)|O caminho para o arquivo de Ajuda do aplicativo.|  
|[CWinApp::m_pszProfileName](#m_pszprofilename)|O aplicativo. Nome do arquivo INI.|  
|[CWinApp::m_pszRegistryKey](#m_pszregistrykey)|Usado para determinar a chave de registro completo para armazenar configurações de perfil de aplicativo.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::m_dwRestartManagerSupportFlags](#m_dwrestartmanagersupportflags)|Sinalizadores que determinam como o Gerenciador de reinicialização se comporta.|  
|[CWinApp::m_nAutosaveInterval](#m_nautosaveinterval)|O período de tempo em milissegundos entre salve.|  
|[CWinApp::m_pDataRecoveryHandler](#m_pdatarecoveryhandler)|Ponteiro para o manipulador de recuperação de dados para o aplicativo.|  
  
## <a name="remarks"></a>Comentários  
 Um objeto de aplicativo fornece funções de membro para inicializar seu aplicativo (e cada instância dele) e executar o aplicativo.  
  
 Cada aplicativo que usa as Microsoft Foundation classes só pode conter um objeto derivado de `CWinApp`. Esse objeto é construído quando outros objetos globais do C++ são construídos e já está disponível quando o Windows chama o `WinMain` função, que é fornecida pelo Microsoft Foundation Class Library. Declarar derivada `CWinApp` objeto no nível global.  
  
 Quando você derivar uma classe de aplicativo de `CWinApp`, substituir o [InitInstance](#initinstance) função de membro para criar o objeto de janela principal do seu aplicativo.  
  
 Além de `CWinApp` funções de membro, a biblioteca Microsoft Foundation Class fornece as seguintes funções globais para acessar seu `CWinApp` objeto e outras informações globais:  
  
- [AfxGetApp](application-information-and-management.md#afxgetapp) obtém um ponteiro para o `CWinApp` objeto.  
  
- [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle) obtém um identificador para a instância atual do aplicativo.  
  
- [AfxGetResourceHandle](application-information-and-management.md#afxgetresourcehandle) obtém um identificador para os recursos do aplicativo.  
  
- [AfxGetAppName](application-information-and-management.md#afxgetappname) obtém um ponteiro para uma cadeia de caracteres que contém o nome do aplicativo. Como alternativa, se você tiver um ponteiro para o `CWinApp` de objeto, use `m_pszExeName` para obter o nome do aplicativo.  
  
 Consulte [CWinApp: A classe de aplicativo](../../mfc/cwinapp-the-application-class.md) para saber mais sobre o `CWinApp` classe, incluindo uma visão geral dos seguintes:  
  
- `CWinApp`-derivado código escrito pelo Assistente de aplicativo.  
  
- `CWinApp`da função na sequência de execução do seu aplicativo.  
  
- `CWinApp`está implementações de função de membro padrão.  
  
- `CWinApp`da chave sobre substituíveis.  
  
 O **m_hPrevInstance** membro de dados não existe mais. Para obter informações sobre como detectar uma instância anterior do `CWinApp`, consulte o artigo da Base de Conhecimento "Como identificar um anterior instância de um aplicativo" (KB106385) em [http://support.microsoft.com/default.aspxscid=kb;en-us;106385](http://support.microsoft.com/default.aspxscid=kb;en-us;106385).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 `CWinApp`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameadddoctemplatea--cwinappadddoctemplate"></a><a name="adddoctemplate"></a>CWinApp::AddDocTemplate  
 Chame essa função de membro para adicionar um modelo de documento à lista de modelos de documento disponíveis que mantém o aplicativo.  
  
```  
void AddDocTemplate(CDocTemplate* pTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTemplate`  
 Um ponteiro para o `CDocTemplate` a ser adicionado.  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar todos os modelos para um aplicativo de documento antes de chamar [RegisterShellFileTypes](#registershellfiletypes).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#35;](../../mfc/reference/codesnippet/cpp/cwinapp-class_1.cpp)]  
  
##  <a name="a-nameaddtorecentfilelista--cwinappaddtorecentfilelist"></a><a name="addtorecentfilelist"></a>CWinApp::AddToRecentFileList  
 Chame essa função de membro para adicionar `lpszPathName` à lista de arquivos MRU.  
  
```  
virtual void AddToRecentFileList(LPCTSTR lpszPathName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 O caminho do arquivo.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o [LoadStdProfileSettings](#loadstdprofilesettings) a função de membro para carregar a lista de arquivos MRU atual antes de usar essa função de membro.  
  
 O framework chama essa função membro quando ele abre um arquivo ou executa o comando Salvar como para salvar um arquivo com um novo nome.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#36;](../../mfc/reference/codesnippet/cpp/cwinapp-class_2.cpp)]  
  
##  <a name="a-nameapplicationrecoverycallbacka--cwinappapplicationrecoverycallback"></a><a name="applicationrecoverycallback"></a>CWinApp::ApplicationRecoveryCallback  
 Chamado pela estrutura quando o aplicativo é encerrado inesperadamente.  
  
```  
virtual DWORD ApplicationRecoveryCallback(LPVOID lpvParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpvParam`  
 Reservado para uso futuro.  
  
### <a name="return-value"></a>Valor de retorno  
 0 se esse método for bem-sucedida; diferente de zero se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo suporta o Gerenciador de reinicialização, o framework chama essa função quando seu aplicativo for encerrado inesperadamente.  
  
 A implementação padrão de `ApplicationRecoveryCallback` usa o `CDataRecoveryHandler` para salvar a lista de documentos abertos no registro. Esse método não não salvar automaticamente todos os arquivos.  
  
 Para personalizar o comportamento, substitua essa função em um derivado [classe CWinApp](../../mfc/reference/cwinapp-class.md) ou passar seu próprio método de recuperação do aplicativo como um parâmetro para [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager).  
  
##  <a name="a-nameclosealldocumentsa--cwinappclosealldocuments"></a><a name="closealldocuments"></a>CWinApp::CloseAllDocuments  
 Chame essa função de membro para fechar todos os documentos abertos antes de sair.  
  
```  
void CloseAllDocuments(BOOL bEndSession);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEndSession`  
 Especifica se a sessão do Windows está sendo encerrada. É **TRUE** se a sessão está sendo encerrada; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Chamar [HideApplication](#hideapplication) antes de chamar `CloseAllDocuments`.  
  
##  <a name="a-namecreateprinterdca--cwinappcreateprinterdc"></a><a name="createprinterdc"></a>CWinApp::CreatePrinterDC  
 Chame essa função de membro para criar um contexto de dispositivo da impressora (DC) da impressora selecionada.  
  
```  
BOOL CreatePrinterDC(CDC& dc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 Uma referência a um contexto de dispositivo da impressora.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contexto de dispositivo da impressora é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `CreatePrinterDC`inicializa o contexto de dispositivo que você passar por referência, para que possa ser usado para imprimir.  
  
 Se a função for bem-sucedida, quando você tiver terminado de impressão, você deve destruir o contexto do dispositivo. Você pode permitir que o destruidor do [CDC](../../mfc/reference/cdc-class.md) objeto fazê-lo, ou você pode fazê-lo explicitamente chamando [CDC::DeleteDC](../../mfc/reference/cdc-class.md#deletedc).  
  
##  <a name="a-namecwinappa--cwinappcwinapp"></a><a name="cwinapp"></a>CWinApp::CWinApp  
 Constrói uma `CWinApp` objeto e passa `lpszAppName` seja armazenado como o nome do aplicativo.  
  
```  
CWinApp(LPCTSTR lpszAppName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszAppName`  
 Uma cadeia terminada em nulo que contém o nome do aplicativo que usa o Windows. Se esse argumento não for fornecido ou for **nulo**, `CWinApp` usa a cadeia de caracteres **AFX_IDS_APP_TITLE** ou o nome do arquivo do arquivo executável.  
  
### <a name="remarks"></a>Comentários  
 Você deve construir um objeto global da sua `CWinApp`-classe derivada. Você pode ter apenas uma `CWinApp` objeto em seu aplicativo. O construtor armazena um ponteiro para o `CWinApp` objeto para que `WinMain` pode chamar funções para inicializar e executar o aplicativo de membro do objeto.  
  
##  <a name="a-namedelregtreea--cwinappdelregtree"></a><a name="delregtree"></a>CWinApp::DelRegTree  
 Exclui uma chave do registro específica e todas as suas subchaves.  
  
```  
LONG DelRegTree(
    HKEY hParentKey,  
    const CString& strKeyName);

 
LONG DelRegTree(
    HKEY hParentKey,
    const CString& strKeyName,
    CAtlTransactionManager* pTM = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hParentKey*  
 Identificador para uma chave do registro.  
  
 *strKeyName*  
 O nome da chave do registro a ser excluído.  
  
 *pTM*  
 Ponteiro para objeto CAtlTransactionManager.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido no Winerror. h.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para excluir a chave especificada e suas subchaves.  
  
##  <a name="a-namedomessageboxa--cwinappdomessagebox"></a><a name="domessagebox"></a>CWinApp::DoMessageBox  
 O framework chama essa função de membro para implementar uma caixa de mensagem para a função global [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox).  
  
```  
virtual int DoMessageBox(
    LPCTSTR lpszPrompt,  
    UINT nType,  
    UINT nIDPrompt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszPrompt*  
 Endereço do texto na caixa de mensagem.  
  
 `nType`  
 A caixa de mensagem [estilo](../../mfc/reference/message-box-styles.md).  
  
 `nIDPrompt`  
 Um índice para uma cadeia de caracteres de contexto de Ajuda.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna os mesmos valores `AfxMessageBox`.  
  
### <a name="remarks"></a>Comentários  
 Não chame essa função de membro para abrir uma caixa de mensagem. Use `AfxMessageBox` em vez disso.  
  
 Substituir essa função de membro para personalizar seu processamento de todo o aplicativo de `AfxMessageBox` chamadas.  
  
##  <a name="a-namedowaitcursora--cwinappdowaitcursor"></a><a name="dowaitcursor"></a>CWinApp::DoWaitCursor  
 Essa função de membro é chamada pela estrutura para implementar [CWaitCursor](../../mfc/reference/cwaitcursor-class.md), [CCmdTarget::BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor), [CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor), e [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).  
  
```  
virtual void DoWaitCursor(int nCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCode`  
 Se esse parâmetro for 1, será exibido um cursor de espera. Se for 0, o cursor de espera é restaurado sem incrementando a contagem de referência. Se –&1;, o cursor de espera é encerrado.  
  
### <a name="remarks"></a>Comentários  
 O padrão implementa um cursor ampulheta. `DoWaitCursor`mantém uma contagem de referência. Quando for positivo, o cursor de ampulheta é exibido.  
  
 Embora você normalmente não chama `DoWaitCursor` diretamente, você pode substituir essa função de membro para alterar o cursor de espera ou fazer o processamento adicional enquanto o cursor de espera é exibido.  
  
 Para uma maneira fácil e mais simples de implementar um cursor de espera, use `CWaitCursor`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#37;](../../mfc/reference/codesnippet/cpp/cwinapp-class_3.cpp)]  
  
##  <a name="a-nameenabled2dsupporta--cwinappenabled2dsupport"></a><a name="enabled2dsupport"></a>CWinApp::EnableD2DSupport  
 [!INCLUDE[dev10_sp1required](../../mfc/reference/includes/dev10_sp1required_md.md)]  
  
 Habilita o suporte de D2D do aplicativo. Chame esse método antes da janela principal é inicializada.  
  
```  
BOOL EnableD2DSupport(
D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED,  
DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);
```  
  
### <a name="parameters"></a>Parâmetros  
 `d2dFactoryType`  
 O modelo de threading de fábrica D2D e os recursos que ele cria.  
  
 `writeFactoryType`  
 Um valor que especifica se o objeto de fábrica de gravação será compartilhado ou isolado  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se D2D suporte foi habilitado, FALSO - caso contrário  
  
##  <a name="a-nameenablehtmlhelpa--cwinappenablehtmlhelp"></a><a name="enablehtmlhelp"></a>CWinApp::EnableHtmlHelp  
 Chame essa função de membro de dentro do construtor de seu `CWinApp`-derivado da classe para usar Help para obter ajuda do seu aplicativo.  
  
```  
void EnableHtmlHelp();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenableshellopena--cwinappenableshellopen"></a><a name="enableshellopen"></a>CWinApp::EnableShellOpen  
 Chame essa função, geralmente de seu `InitInstance` substituição, para permitir que os usuários do seu aplicativo abrir arquivos de dados quando eles clicar duas vezes os arquivos dentro do Gerenciador de arquivos do Windows.  
  
```  
void EnableShellOpen();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o `RegisterShellFileTypes` membro funcionam em conjunto com essa função, ou fornecer um. Arquivo REG com o seu aplicativo para o registro manual dos tipos de documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&38;](../../mfc/reference/codesnippet/cpp/cwinapp-class_4.cpp)]  
  
##  <a name="a-nameenabletaskbarinteractiona--cwinappenabletaskbarinteraction"></a><a name="enabletaskbarinteraction"></a>CWinApp::EnableTaskbarInteraction  
 Habilita a interação de barra de tarefas.  
  
```  
BOOL EnableTaskbarInteraction(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se deve ser habilitada a interação com a barra de tarefas do Windows 7 ( `TRUE`), ou desabilitado ( `FALSE`).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a interação da barra de tarefas pode ser habilitada ou desabilitada.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado antes da criação da janela principal, caso contrário, ele declara e retorna `FALSE`.  
  
##  <a name="a-nameexitinstancea--cwinappexitinstance"></a><a name="exitinstance"></a>CWinApp::ExitInstance  
 Chamado pela estrutura de dentro do **executar** função de membro para sair dessa instância do aplicativo.  
  
```  
virtual int ExitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Código de saída do aplicativo; 0 não indica que nenhum erro, e valores maiores que 0 indicam um erro. Esse valor é usado como o valor de retorno `WinMain`.  
  
### <a name="remarks"></a>Comentários  
 Não chame essa função de membro de qualquer lugar mas dentro do **executar** função de membro.  
  
 A implementação padrão dessa função grava opções de estrutura do aplicativo. Arquivo INI. Substitua essa função para a limpeza quando seu aplicativo terminar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#39;](../../mfc/reference/codesnippet/cpp/cwinapp-class_5.cpp)]  
  
##  <a name="a-namegetapplicationrecoveryparametera--cwinappgetapplicationrecoveryparameter"></a><a name="getapplicationrecoveryparameter"></a>CWinApp::GetApplicationRecoveryParameter  
 Recupera o parâmetro de entrada para o método de recuperação do aplicativo.  
  
```  
virtual LPVOID GetApplicationRecoveryParameter();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O parâmetro de entrada padrão para o método de recuperação do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Retorna o comportamento padrão dessa função `NULL`.  
  
 Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).  
  
##  <a name="a-namegetapplicationrecoverypingintervala--cwinappgetapplicationrecoverypinginterval"></a><a name="getapplicationrecoverypinginterval"></a>CWinApp::GetApplicationRecoveryPingInterval  
 Retorna o período de tempo que o Gerenciador de reinicialização aguarda que a função de retorno de chamada de recuperação retornar.  
  
```  
virtual DWORD GetApplicationRecoveryPingInterval();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O período de tempo em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 Quando um aplicativo que está registrado com o restart manager sai inesperadamente, o aplicativo tenta salvar documentos abertos e chama a função de retorno de chamada de recuperação. A função de retorno de chamada de recuperação padrão é [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).  
  
 O período de tempo que a estrutura de espera para a função de retorno de chamada de recuperação retornar é o intervalo de ping. Você pode personalizar o intervalo de ping, substituindo `CWinApp::GetApplicationRecoveryPingInterval` ou fornecendo um valor personalizado para `RegisterWithRestartManager`.  
  
##  <a name="a-namegetapplicationrestartflagsa--cwinappgetapplicationrestartflags"></a><a name="getapplicationrestartflags"></a>CWinApp::GetApplicationRestartFlags  
 Retorna os sinalizadores para o Gerenciador de reinicialização.  
  
```  
virtual DWORD GetApplicationRestartFlags();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os sinalizadores para o Gerenciador de reinicialização. A implementação padrão retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Os sinalizadores para o Gerenciador de reinicialização não têm nenhum efeito com a implementação padrão. Eles são fornecidos para uso futuro.  
  
 Definir os sinalizadores ao registrar o aplicativo com o Gerenciador de reinicialização usando [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager).  
  
 Os valores possíveis para os sinalizadores de Gerenciador de reinicialização são da seguinte maneira:  
  
- `RESTART_NO_CRASH`  
  
- `RESTART_NO_HANG`  
  
- `RESTART_NO_PATCH`  
  
- `RESTART_NO_REBOOT`  
  
##  <a name="a-namegetappregistrykeya--cwinappgetappregistrykey"></a><a name="getappregistrykey"></a>CWinApp::GetAppRegistryKey  
 Retorna a chave de HKEY_CURRENT_USER\\\RegistryKey\ProfileName "Software".  
  
```  
HKEY GetAppRegistryKey(CAtlTransactionManager* pTM = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Chave do aplicativo se a função for bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetdatarecoveryhandlera--cwinappgetdatarecoveryhandler"></a><a name="getdatarecoveryhandler"></a>CWinApp::GetDataRecoveryHandler  
 Obtém o manipulador de recuperação de dados para essa instância do aplicativo.  
  
```  
virtual CDataRecoveryHandler *GetDataRecoveryHandler();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O manipulador de recuperação de dados para essa instância do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Cada aplicativo que usa o Gerenciador de reinicialização deve ter uma instância de [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md). Essa classe é responsável por monitorar arquivos de gravação automática e documentos abertos. O comportamento do `CDataRecoveryHandler` depende da configuração do Gerenciador de reinicialização. Para obter mais informações, consulte [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md).  
  
 Esse método retorna `NULL` em sistemas operacionais anteriores ao [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]. O Gerenciador de reinicialização não tem suporte em sistemas operacionais anteriores ao [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)].  
  
 Se o aplicativo não tem um manipulador de recuperação de dados, esse método cria um e retorna um ponteiro para ele.  
  
##  <a name="a-namegetfirstdoctemplatepositiona--cwinappgetfirstdoctemplateposition"></a><a name="getfirstdoctemplateposition"></a>CWinApp::GetFirstDocTemplatePosition  
 Obtém a posição do primeiro modelo de documento no aplicativo.  
  
```  
POSITION GetFirstDocTemplatePosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se a lista está vazia.  
  
### <a name="remarks"></a>Comentários  
 Use o **posição** valor retornado em uma chamada para [GetNextDocTemplate](#getnextdoctemplate) para obter o primeiro [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto.  
  
##  <a name="a-namegethelpmodea--cwinappgethelpmode"></a><a name="gethelpmode"></a>CWinApp::GetHelpMode  
 Recupera o tipo de Ajuda usado pelo aplicativo.  
  
```  
AFX_HELP_TYPE GetHelpMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de Ajuda usado pelo aplicativo. Consulte [CWinApp::m_eHelpType](#m_ehelptype) para obter mais informações.  
  
##  <a name="a-namegetnextdoctemplatea--cwinappgetnextdoctemplate"></a><a name="getnextdoctemplate"></a>CWinApp::GetNextDocTemplate  
 Obtém o modelo de documento identificado por `pos`, em seguida, define `pos` para o **posição** valor.  
  
```  
CDocTemplate* GetNextDocTemplate(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Uma referência a um **posição** valor retornado por uma chamada anterior a `GetNextDocTemplate` ou [GetFirstDocTemplatePosition](#getfirstdoctemplateposition). O valor é atualizado para a próxima posição por essa chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `GetNextDocTemplate` em um loop de iteração direta se estabelecer a posição inicial com uma chamada para `GetFirstDocTemplatePosition`.  
  
 Você deve garantir que seu **posição** valor é válido. Se for inválido, a versão de depuração da Microsoft Foundation Class Library declara.  
  
 Se o modelo de documento recuperado é o último disponível, em seguida, o novo valor de `pos` é definido como **nulo**.  
  
##  <a name="a-namegetprinterdevicedefaultsa--cwinappgetprinterdevicedefaults"></a><a name="getprinterdevicedefaults"></a>CWinApp::GetPrinterDeviceDefaults  
 Chame essa função de membro para preparar uma impressora contexto de dispositivo de impressão.  
  
```  
BOOL GetPrinterDeviceDefaults(struct tagPDA* pPrintDlg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pPrintDlg*  
 Um ponteiro para um [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Recupera os padrões atuais de impressora do Windows. INI arquivo conforme necessário, ou usa a última configuração de impressora definida pelo usuário na configuração de impressão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_6.cpp)]  
  
##  <a name="a-namegetprofilebinarya--cwinappgetprofilebinary"></a><a name="getprofilebinary"></a>CWinApp::GetProfileBinary  
 Chame essa função de membro para recuperar dados binários de uma entrada em uma seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL GetProfileBinary(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    LPBYTE* ppData,  
    UINT* pBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszSection*  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada.  
  
 *lpszEntry*  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cujo valor deve ser recuperado.  
  
 *ppData*  
 Aponta para um ponteiro que receberá o endereço dos dados.  
  
 *Petabytes*  
 Aponta para um UINT que receberá o tamanho dos dados (em bytes).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não é diferencia maiusculas de minúsculas, portanto as sequências de caracteres de *lpszSection* e *lpszEntry* parâmetros podem diferir em caso.  
  
> [!NOTE]
> **GetProfileBinary** aloca um buffer e retorna seu endereço no \* *ppData*. O chamador é responsável por liberar o buffer usando **delete []**.  
  
> [!IMPORTANT]
>  Os dados retornados por essa função não são necessariamente nulos terminada e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[41 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_7.cpp)]  
  
 Para obter um exemplo adicional, consulte [CWinApp::WriteProfileBinary](#writeprofilebinary).  
  
##  <a name="a-namegetprofileinta--cwinappgetprofileint"></a><a name="getprofileint"></a>CWinApp::GetProfileInt  
 Chame essa função de membro para recuperar o valor de um número inteiro de uma entrada em uma seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
UINT GetProfileInt(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    int nDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cujo valor deve ser recuperado.  
  
 `nDefault`  
 Especifica o valor padrão para retornar se a estrutura não é possível localizar a entrada.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de inteiro da cadeia de caracteres que segue a entrada especificada se a função for bem-sucedida. O valor de retorno é o valor de `nDefault` parâmetro se a função não localizar a entrada. O valor de retorno será 0 se o valor que corresponde à entrada especificada não é um inteiro.  
  
 Essa função de membro oferece suporte a notação hexadecimal para o valor da. Arquivo INI. Quando você recupera um inteiro assinado, você deve converter o valor em um `int`.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não é diferencia maiusculas de minúsculas, portanto as sequências de caracteres de `lpszSection` e `lpszEntry` parâmetros podem diferir em caso.  
  
> [!IMPORTANT]
>  Os dados retornados por essa função não são necessariamente nulos terminada e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&42;](../../mfc/reference/codesnippet/cpp/cwinapp-class_8.cpp)]  
  
 Para obter um exemplo adicional, consulte [CWinApp::WriteProfileInt](#writeprofileint).  
  
##  <a name="a-namegetprofilestringa--cwinappgetprofilestring"></a><a name="getprofilestring"></a>CWinApp::GetProfileString  
 Chame essa função de membro para recuperar a cadeia de caracteres associada a uma entrada na seção especificada no registro do aplicativo ou. Arquivo INI.  
  
```  
CString GetProfileString(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    LPCTSTR lpszDefault = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cuja sequência de caracteres deve ser recuperado. Esse valor não deve ser **nulo**.  
  
 `lpszDefault`  
 Aponta para o valor de cadeia de caracteres padrão para a entrada especificada se a entrada não pode ser encontrada no arquivo de inicialização.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno é a cadeia de caracteres a partir do aplicativo. Arquivo INI ou `lpszDefault` se a cadeia de caracteres não pode ser encontrada. O tamanho máximo suportado pelo framework é `_MAX_PATH`. Se `lpszDefault` é **nulo**, o valor de retorno é uma cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
  
> [!IMPORTANT]
>  Os dados retornados por essa função não são necessariamente nulos terminada e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#43;](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileInt](#getprofileint).  
  
##  <a name="a-namegetsectionkeya--cwinappgetsectionkey"></a><a name="getsectionkey"></a>CWinApp::GetSectionKey  
 Retorna a chave de HKEY_CURRENT_USER\\\RegistryKey\AppName\lpszSection "Software".  
  
```  
HKEY GetSectionKey(
LPCTSTR lpszSection,  
CAtlTransactionManager* pTM = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 O nome da chave a ser obtido.  
  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Chave de seção se a função for bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehideapplicationa--cwinapphideapplication"></a><a name="hideapplication"></a>CWinApp::HideApplication  
 Chame essa função de membro para ocultar um aplicativo antes de fechar os documentos abertos.  
  
```  
void HideApplication();
```  
  
##  <a name="a-namehtmlhelpa--cwinapphtmlhelp"></a><a name="htmlhelp"></a>CWinApp::HtmlHelp  
 Chame essa função de membro para invocar o aplicativo Help.  
  
```  
virtual void HtmlHelp(
    DWORD_PTR dwData,  
    UINT nCmd = 0x000F);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwData`  
 Especifica os dados adicionais. O valor usado depende do valor da `nCmd` parâmetro.  
  
 `nCmd`  
 Especifica o tipo de ajuda solicitado. Para obter uma lista de valores possíveis e como eles afetam o `dwData` parâmetro, consulte o `uCommand` parâmetro descrito em sobre o Help função de API no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 A estrutura também chama essa função para invocar o aplicativo Help.  
  
 A estrutura de fechar automaticamente o aplicativo Help quando seu aplicativo terminar.  
  
##  <a name="a-nameinitinstancea--cwinappinitinstance"></a><a name="initinstance"></a>CWinApp::InitInstance  
 O Windows permite que várias cópias do mesmo programa para ser executado ao mesmo tempo.  
  
```  
virtual BOOL InitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Inicialização do aplicativo é conceitualmente dividida em duas seções: executa o programa de tempo de inicialização de aplicativo único que é feita o primeiro e tempo de inicialização de instância que executa uma cópia das execuções de programa, incluindo a primeira vez. A implementação da estrutura de `WinMain` chama essa função.  
  
 Substituir `InitInstance` para inicializar cada nova instância do aplicativo em execução no Windows. Normalmente, você substituir `InitInstance` para construir o objeto de janela principal e definir o `CWinThread::m_pMainWnd` membro de dados para apontar para essa janela. Para obter mais informações sobre essa função de membro de substituição, consulte [CWinApp: A classe de aplicativo](../../mfc/cwinapp-the-application-class.md).  
  
> [!NOTE]
>  Aplicativos MFC devem ser inicializados como compartimento de único thread (STA). Se você chamar [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279) em seu `InitInstance` substituir, especifique `COINIT_APARTMENTTHREADED` (em vez de `COINIT_MULTITHREADED`). Para obter mais informações, consulte PRB: aplicativo MFC para de responder quando você inicializar o aplicativo como um Multithreaded Apartment (828643) em [http://support.microsoft.com/default.aspxscid=kb;en-us;828643](http://support.microsoft.com/default.aspxscid=kb;en-us;828643).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCListView n º&9;](../../atl/reference/codesnippet/cpp/cwinapp-class_10.cpp)]  
  
##  <a name="a-nameistaskbarinteractionenableda--cwinappistaskbarinteractionenabled"></a><a name="istaskbarinteractionenabled"></a>CWinApp::IsTaskbarInteractionEnabled  
 Informa se a interação da barra de tarefas do Windows 7 está habilitada.  
  
```  
virtual BOOL IsTaskbarInteractionEnabled();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se `EnableTaskbarInteraction` foi chamado e o sistema operacional Windows 7 ou superior.  
  
### <a name="remarks"></a>Comentários  
 Interação de barra de tarefas significa que o aplicativo MDI exibe o conteúdo de filhos MDI nas miniaturas com guias separadas que aparecem quando o ponteiro do mouse estiver sobre o botão da barra de tarefas do aplicativo.  
  
##  <a name="a-nameloadcursora--cwinapploadcursor"></a><a name="loadcursor"></a>CWinApp::LoadCursor  
 Carrega o recurso de cursor nomeado pelo `lpszResourceName` ou especificado pelo `nIDResource` do arquivo executável atual.  
  
```  
HCURSOR LoadCursor(LPCTSTR lpszResourceName) const;  HCURSOR LoadCursor(UINT nIDResource) const;  ```  
  
### Parameters  
 `lpszResourceName`  
 Points to a null-terminated string that contains the name of the cursor resource. You can use a `CString` for this argument.  
  
 `nIDResource`  
 ID of the cursor resource. For a list of resources, see [LoadCursor](http://msdn.microsoft.com/library/windows/desktop/ms648391) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Return Value  
 A handle to a cursor if successful; otherwise **NULL**.  
  
### Remarks  
 `LoadCursor` loads the cursor into memory only if it has not been previously loaded; otherwise, it retrieves a handle of the existing resource.  
  
 Use the [LoadStandardCursor](#loadstandardcursor) or [LoadOEMCursor](#loadoemcursor) member function to access the predefined Windows cursors.  
  
### Example  
 [!code-cpp[NVC_MFCWindowing#44](../../mfc/reference/codesnippet/cpp/cwinapp-class_11.cpp)]  
  
##  <a name="loadicon"></a>  CWinApp::LoadIcon  
 Loads the icon resource named by `lpszResourceName` or specified by `nIDResource` from the executable file.  
  
```  
HICON LoadIcon(LPCTSTR lpszResourceName) const;  HICON LoadIcon(UINT nIDResource) const;  ```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de ícone. Você também pode usar um `CString` para esse argumento.  
  
 `nIDResource`  
 Número de ID do recurso de ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 `LoadIcon`carrega o ícone somente se ele não tenha sido previamente carregado; Caso contrário, ele recupera um identificador de recurso existente.  
  
 Você pode usar o [LoadStandardIcon](#loadstandardicon) ou [LoadOEMIcon](#loadoemicon) a função de membro para acessar os ícones do Windows predefinidos.  
  
> [!NOTE]
>  Essa função de membro chama a função de API do Win32 [LoadIcon](http://msdn.microsoft.com/library/windows/desktop/ms648072), que só pode carregar um ícone cujo tamanho está em conformidade com a **SM_CXICON** e **SM_CYICON** valores de métricas do sistema.  
  
##  <a name="a-nameloadoemcursora--cwinapploadoemcursor"></a><a name="loadoemcursor"></a>CWinApp::LoadOEMCursor  
 Carrega o Windows predefinidas recurso cursor especificado por `nIDCursor`.  
  
```  
HCURSOR LoadOEMCursor(UINT nIDCursor) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDCursor`  
 Um **OCR_** identificador constante que especifica um cursor Windows predefinido de manifesto. Você deve ter **#define OEMRESOURCE** antes de **#include \<afxwin. h >** para acessar o **OCR_** constantes no WINDOWS. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um cursor se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadOEMCursor` ou [LoadStandardCursor](#loadstandardcursor) a função de membro para acessar os cursores predefinidos do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[45 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_12.h)]  
  
 [!code-cpp[46 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_13.cpp)]  
  
##  <a name="a-nameloadoemicona--cwinapploadoemicon"></a><a name="loadoemicon"></a>CWinApp::LoadOEMIcon  
 Carrega o Windows predefinidas recurso de ícone especificado por `nIDIcon`.  
  
```  
HICON LoadOEMIcon(UINT nIDIcon) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDIcon`  
 Um **OIC_** manifesto constante identificador que especifica um ícone predefinido do Windows. Você deve ter **#define OEMRESOURCE** antes de **#include \<afxwin. h >** para acessar o **OIC_** constantes no WINDOWS. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadOEMIcon` ou [LoadStandardIcon](#loadstandardicon) a função de membro para acessar os ícones do Windows predefinidos.  
  
##  <a name="a-nameloadstandardcursora--cwinapploadstandardcursor"></a><a name="loadstandardcursor"></a>CWinApp::LoadStandardCursor  
 Carrega o Windows predefinidos de recursos de cursor que `lpszCursorName` especifica.  
  
```  
HCURSOR LoadStandardCursor(LPCTSTR lpszCursorName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszCursorName`  
 Um **IDC _** manifesto constante identificador que especifica um cursor predefinido do Windows. Esses identificadores são definidos no WINDOWS. H. A lista a seguir mostra os possíveis valores predefinidos e os significados para `lpszCursorName`:  
  
- **IDC_ARROW** cursor de seta padrão  
  
- **IDC_IBEAM** o cursor de inserção de texto padrão  
  
- **IDC_WAIT** cursor ampulheta usado quando o Windows executa uma tarefa demorada  
  
- **IDC_CROSS** cursor de fios para seleção  
  
- **IDC_UPARROW** seta que aponta para cima  
  
- **IDC_SIZE** obsoleto e sem suporte; use **IDC_SIZEALL**  
  
- **IDC_SIZEALL** uma seta de quatro pontas. O cursor a usar para redimensionar a janela.  
  
- **IDC_ICON** obsoleto e sem suporte. Use **IDC_ARROW**.  
  
- **IDC_SIZENWSE** seta de duas pontas com extremidades superior esquerda e inferior à direita  
  
- **IDC_SIZENESW** seta de duas pontas com as extremidades esquerda superior direita e inferior  
  
- **IDC_SIZEWE** seta Horizontal com duas pontas  
  
- **IDC_SIZENS** seta de duas pontas Vertical  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um cursor se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadStandardCursor` ou [LoadOEMCursor](#loadoemcursor) a função de membro para acessar os cursores predefinidos do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[47 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_14.cpp)]  
  
##  <a name="a-nameloadstandardicona--cwinapploadstandardicon"></a><a name="loadstandardicon"></a>CWinApp::LoadStandardIcon  
 O Windows carrega predefinidas recurso de ícone que `lpszIconName` especifica.  
  
```  
HICON LoadStandardIcon(LPCTSTR lpszIconName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIconName`  
 Um manifesto identificador constante que especifica um ícone predefinido do Windows. Esses identificadores são definidos no WINDOWS. H. Para obter uma lista dos possíveis valores predefinidos e suas descrições, consulte o *lpIconName* parâmetro em [LoadIcon](http://msdn.microsoft.com/library/windows/desktop/ms648072) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadStandardIcon` ou [LoadOEMIcon](#loadoemicon) a função de membro para acessar os ícones do Windows predefinidos.  
  
##  <a name="a-nameloadstdprofilesettingsa--cwinapploadstdprofilesettings"></a><a name="loadstdprofilesettings"></a>CWinApp::LoadStdProfileSettings  
 Chame essa função de membro de dentro do [InitInstance](#initinstance) função de membro para habilitar e carregar a lista de arquivos de usados mais recentemente (MRU) e o último estado de visualização.  
  
```  
void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxMRU`  
 O número de arquivos usados recentemente para rastrear.  
  
### <a name="remarks"></a>Comentários  
 Se `nMaxMRU` for 0, nenhuma lista MRU será mantida.  
  
##  <a name="a-namembhelpmodea--cwinappmbhelpmode"></a><a name="m_bhelpmode"></a>CWinApp::m_bHelpMode  
 **TRUE** se o aplicativo estiver no modo de contexto de Ajuda (convencionalmente invocado com SHIFT + F1); caso contrário, **FALSE**.  
  
```  
BOOL m_bHelpMode;  
```  
  
### <a name="remarks"></a>Comentários  
 No modo de contexto de Ajuda, o cursor se transforma em um ponto de interrogação e o usuário poderá movê-lo sobre a tela. Examine esse sinalizador se você quiser implementar um tratamento especial quando no modo de Ajuda. `m_bHelpMode`é uma variável pública do tipo **BOOL**.  
  
##  <a name="a-namemdwrestartmanagersupportflagsa--cwinappmdwrestartmanagersupportflags"></a><a name="m_dwrestartmanagersupportflags"></a>CWinApp::m_dwRestartManagerSupportFlags  
 Sinalizadores que determinam como o Gerenciador de reinicialização se comporta.  
  
```  
DWORD m_dwRestartManagerSupportFlags;  
```  
  
### <a name="remarks"></a>Comentários  
 Para habilitar o Gerenciador de reinicialização, defina `m_dwRestartManagerSupportFlags` para o comportamento que você deseja. A tabela a seguir mostra os sinalizadores que estão disponíveis.  
  
|||  
|-|-|  
|Sinalizador|Descrição|  
|`AFX_RESTART_MANAGER_SUPPORT_RESTART`|O aplicativo está registrado usando [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager). O Gerenciador de reinicialização é responsável para reiniciar o aplicativo se ele termina inesperadamente.|  
|- `AFX_RESTART_MANAGER_SUPPORT_RECOVERY`|O aplicativo está registrado com o Gerenciador de reinicialização e o Gerenciador de reinicialização chama a função de retorno de chamada de recuperação quando o aplicativo for reiniciado. A função de retorno de chamada de recuperação padrão é [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|  
|- `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART`|Salvamento automático esteja habilitado e o restart manager Salve quaisquer documentos abertos quando o aplicativo for reiniciado.|  
|- `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL`|Salvamento automático esteja habilitado e o salve do Gerenciador de reinicialização qualquer abrir documentos em intervalos regulares. O intervalo é definido por [CWinApp::m_nAutosaveInterval](#m_nautosaveinterval).|  
|- `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`|O Gerenciador de reinicialização abre documentos anteriormente abertos após reiniciar o aplicativo a partir de uma saída inesperado. O [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md) manipula armazenar a lista de documentos abertos e restaurá-los.|  
|- `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`|O Gerenciador de reinicialização solicita ao usuário para restaurar arquivos salva automaticamente após reiniciar o aplicativo. O `CDataRecoveryHandler` classe consulta o usuário.|  
|- `AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE`|A união de `AFX_RESTART_MANAGER_SUPPORT_RESTART`, `AFX_RESTART_MANAGER_SUPPORT_RECOVER`, e `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`.|  
|- `AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS`|The union of `AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL`, and `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`.|  
|- `AFX_RESTART_MANAGER_SUPPORT_RESTART_ASPECTS`|The union of `AFX_RESTART_MANAGER_SUPPORT_RESTART`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART`, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`, and `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`.|  
|- `AFX_RESTART_MANAGER_SUPPORT_RECOVERY_ASPECTS`|The union of `AFX_RESTART_MANAGER_SUPPORT_RECOVERY`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL`, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`, and `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`.|  
  
##  <a name="a-namemehelptypea--cwinappmehelptype"></a><a name="m_ehelptype"></a>CWinApp::m_eHelpType  
 O tipo desse membro de dados é o tipo enumerado **AFX_HELP_TYPE**, que é definido dentro de `CWinApp` classe.  
  
```  
AFX_HELP_TYPE m_eHelpType;  
```  
  
### <a name="remarks"></a>Comentários  
 O **AFX_HELP_TYPE** enumeração é definida da seguinte maneira:  
  
 `enum AFX_HELP_TYPE`  
  
 `{`  
  
 `afxWinHelp = 0,`  
  
 `afxHTMLHelp = 1`  
  
 `};`  
  
-   Para definir a Ajuda do aplicativo para ajuda HTML, chame [SetHelpMode](#sethelpmode) e especifique **afxHTMLHelp**.  
  
-   Para definir a Ajuda do aplicativo para WinHelp, chame `SetHelpMode` e especifique **afxWinHelp**.  
  
##  <a name="a-namemhinstancea--cwinappmhinstance"></a><a name="m_hinstance"></a>CWinApp::m_hInstance  
 Corresponde do `hInstance` parâmetro passado pelo Windows para `WinMain`.  
  
```  
HINSTANCE m_hInstance;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_hInstance` membro de dados é um identificador para a instância atual do aplicativo em execução no Windows. Isto é retornado pela função global [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle). `m_hInstance`é uma variável pública do tipo `HINSTANCE`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#55;](../../mfc/reference/codesnippet/cpp/cwinapp-class_15.cpp)]  
  
##  <a name="a-namemlpcmdlinea--cwinappmlpcmdline"></a><a name="m_lpcmdline"></a>CWinApp::m_lpCmdLine  
 Corresponde do `lpCmdLine` parâmetro passado pelo Windows para `WinMain`.  
  
```  
LPTSTR m_lpCmdLine;  
```  
  
### <a name="remarks"></a>Comentários  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo. Use `m_lpCmdLine` para acessar argumentos de linha de comando inserido quando o aplicativo foi iniciado pelo usuário. `m_lpCmdLine`é uma variável pública do tipo `LPTSTR`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#52;](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]  
  
##  <a name="a-namemnautosaveintervala--cwinappmnautosaveinterval"></a><a name="m_nautosaveinterval"></a>CWinApp::m_nAutosaveInterval  
 O período de tempo em milissegundos entre salve.  
  
```  
int m_nAutosaveInterval;  
```  
  
### <a name="remarks"></a>Comentários  
 Você pode configurar o Gerenciador de reinicialização para salvamento automático abrir documentos em intervalos definidos. Se seu aplicativo não salvar arquivos, esse parâmetro não terá efeito.  
  
##  <a name="a-namemncmdshowa--cwinappmncmdshow"></a><a name="m_ncmdshow"></a>CWinApp::m_nCmdShow  
 Corresponde do `nCmdShow` parâmetro passado pelo Windows para `WinMain`.  
  
```  
int m_nCmdShow;  
```  
  
### <a name="remarks"></a>Comentários  
 Você deve passar `m_nCmdShow` como um argumento ao chamar [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow) para a janela principal do aplicativo. `m_nCmdShow`é uma variável pública do tipo `int`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[56 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_17.cpp)]  
  
##  <a name="a-namempactivewnda--cwinappmpactivewnd"></a><a name="m_pactivewnd"></a>CWinApp::m_pActiveWnd  
 Use este membro de dados para armazenar um ponteiro para a janela principal do aplicativo de contêiner OLE com seu servidor aplicativo in-loco OLE ativado.  
  
### <a name="remarks"></a>Comentários  
 Se este membro de dados é **nulo**, o aplicativo não está ativo no local.  
  
 A estrutura define essa variável de membro quando a janela do quadro é ativado por um aplicativo de contêiner OLE no local.  
  
##  <a name="a-namempdatarecoveryhandlera--cwinappmpdatarecoveryhandler"></a><a name="m_pdatarecoveryhandler"></a>CWinApp::m_pDataRecoveryHandler  
 Ponteiro para o manipulador de recuperação de dados para o aplicativo.  
  
```  
CDataRecoveryHandler* m_pDataRecoveryHandler;  
```  
  
### <a name="remarks"></a>Comentários  
 O manipulador de recuperação de dados de um aplicativo monitora documentos abertos e salve-os. A estrutura usa o manipulador de recuperação de dados para restaurar arquivos salva automaticamente quando um aplicativo for reiniciado depois que ele é encerrado inesperadamente. Para obter mais informações, consulte [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md).  
  
##  <a name="a-namempszappnamea--cwinappmpszappname"></a><a name="m_pszappname"></a>CWinApp::m_pszAppName  
 Especifica o nome do aplicativo.  
  
```  
LPCTSTR m_pszAppName;  
```  
  
### <a name="remarks"></a>Comentários  
 O nome do aplicativo pode vir do parâmetro passado para o [CWinApp](#cwinapp) construtor, ou, se não especificado para a cadeia de caracteres de recurso com a ID de **AFX_IDS_APP_TITLE**. Se o nome do aplicativo não for encontrado no recurso, ele é proveniente do programa. Nome do arquivo EXE.  
  
 Retornado pela função global [AfxGetAppName](application-information-and-management.md#afxgetappname). `m_pszAppName`é uma variável pública do tipo **const char\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszAppName`, ele deve ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Muitos deseja usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada do ponteiro atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#57;](../../mfc/reference/codesnippet/cpp/cwinapp-class_18.cpp)]  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#65;](../../mfc/reference/codesnippet/cpp/cwinapp-class_19.cpp)]  
  
##  <a name="a-namempszexenamea--cwinappmpszexename"></a><a name="m_pszexename"></a>CWinApp::m_pszExeName  
 Contém o nome do arquivo executável do aplicativo sem uma extensão.  
  
```  
LPCTSTR m_pszExeName;  
```  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [m_pszAppName](#m_pszappname), esse nome não pode conter espaços em branco. `m_pszExeName`é uma variável pública do tipo **const char\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszExeName`, ele deve ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Muitos deseja usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada do ponteiro atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#58;](../../mfc/reference/codesnippet/cpp/cwinapp-class_20.cpp)]  
  
##  <a name="a-namempszhelpfilepatha--cwinappmpszhelpfilepath"></a><a name="m_pszhelpfilepath"></a>CWinApp::m_pszHelpFilePath  
 Contém o caminho para o arquivo de Ajuda do aplicativo.  
  
```  
LPCTSTR m_pszHelpFilePath;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o framework inicializa `m_pszHelpFilePath` para o nome do aplicativo com ". HLP"acrescentada. Para alterar o nome do arquivo de Ajuda, defina `m_pszHelpFilePath` para apontar para uma cadeia de caracteres que contém o nome completo do arquivo de Ajuda desejado. É um local conveniente para fazer isso no aplicativo de [InitInstance](#initinstance) função. `m_pszHelpFilePath`é uma variável pública do tipo **const char\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszHelpFilePath`, ele deve ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Muitos deseja usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada do ponteiro atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#59;](../../mfc/reference/codesnippet/cpp/cwinapp-class_21.cpp)]  
  
##  <a name="a-namempszprofilenamea--cwinappmpszprofilename"></a><a name="m_pszprofilename"></a>CWinApp::m_pszProfileName  
 Contém o nome do aplicativo. Arquivo INI.  
  
```  
LPCTSTR m_pszProfileName;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_pszProfileName`é uma variável pública do tipo **const char\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszProfileName`, ele deve ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Muitos deseja usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada do ponteiro atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#60;](../../mfc/reference/codesnippet/cpp/cwinapp-class_22.cpp)]  
  
##  <a name="a-namempszregistrykeya--cwinappmpszregistrykey"></a><a name="m_pszregistrykey"></a>CWinApp::m_pszRegistryKey  
 Usado para determinar onde, no registro ou no arquivo INI, configurações de perfil de aplicativo estão armazenadas.  
  
```  
LPCTSTR m_pszRegistryKey;  
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, este membro de dados é tratado como somente leitura.  
  
-   O valor é armazenado em uma chave do registro. O nome para a configuração de perfil de aplicativo é anexado a seguinte chave do registro: HKEY_CURRENT_USER/Software/LocalAppWizard-gerados /.  
  
 Se você atribuir um valor para `m_pszRegistryKey`, ele deve ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Muitos deseja usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada do ponteiro atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#61;](../../mfc/reference/codesnippet/cpp/cwinapp-class_23.cpp)]  
  
##  <a name="a-namempszappida--cwinappmpszappid"></a><a name="m_pszappid"></a>CWinApp::m_pszAppID  
 ID do modelo de usuário do aplicativo.  
  
```  
LPCTSTR m_pszAppID;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameoncontexthelpa--cwinapponcontexthelp"></a><a name="oncontexthelp"></a>CWinApp::OnContextHelp  
 Lida com SHIFT + F1 Ajuda dentro do aplicativo.  
  
```  
afx_msg void OnContextHelp();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_CONTEXT_HELP, OnContextHelp )` instrução seu `CWinApp` classe mapa da mensagem e também adicionar uma entrada de tabela de teclas aceleradoras, normalmente SHIFT + F1, para ativar essa função de membro.  
  
 `OnContextHelp`coloca o aplicativo em modo de Ajuda. O cursor muda para uma seta e um ponto de interrogação e o usuário pode, em seguida, mova o ponteiro do mouse e pressione o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Essa função de membro recupera o contexto do objeto sob o cursor e chama a função Windows WinHelp com esse contexto de Ajuda.  
  
##  <a name="a-nameonddecommanda--cwinapponddecommand"></a><a name="onddecommand"></a>CWinApp::OnDDECommand  
 Chamado pela estrutura quando a janela do quadro principal recebe DDE executar mensagem.  
  
```  
virtual BOOL OnDDECommand(LPTSTR lpszCommand);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszCommand*  
 Aponta para uma cadeia de caracteres de comando DDE recebidas pelo aplicativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando é tratado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão verifica se o comando é uma solicitação para abrir um documento e, em caso afirmativo, abre o documento especificado. O Gerenciador de arquivos do Windows geralmente envia como cadeias de caracteres de comando DDE quando o usuário clica duas vezes em um arquivo de dados. Substituir essa função para lidar com outro DDE executar comandos, como o comando Imprimir.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[48 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_24.cpp)]  
  
##  <a name="a-nameonfilenewa--cwinapponfilenew"></a><a name="onfilenew"></a>CWinApp::OnFileNew  
 Implementa o `ID_FILE_NEW` comando.  
  
```  
afx_msg void OnFileNew();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_FILE_NEW, OnFileNew )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, essa função lida com a execução do comando novo arquivo.  
  
 Consulte [22 de nota técnica](../../mfc/tn022-standard-commands-implementation.md) para obter informações sobre o comportamento padrão e orientações sobre como substituir essa função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[49 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing&#50;](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]  
  
##  <a name="a-nameonfileopena--cwinapponfileopen"></a><a name="onfileopen"></a>CWinApp::OnFileOpen  
 Implementa o `ID_FILE_OPEN` comando.  
  
```  
afx_msg void OnFileOpen();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_FILE_OPEN, OnFileOpen )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, essa função lida com a execução do comando Abrir arquivo.  
  
 Para obter informações sobre o comportamento padrão e orientação sobre como substituir essa função de membro, consulte [22 de nota técnica](../../mfc/tn022-standard-commands-implementation.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[49 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing&#50;](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]  
  
##  <a name="a-nameonfileprintsetupa--cwinapponfileprintsetup"></a><a name="onfileprintsetup"></a>CWinApp::OnFilePrintSetup  
 Implementa o **ID_FILE_PRINT_SETUP** comando.  
  
```  
afx_msg void OnFilePrintSetup();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_FILE_PRINT_SETUP, OnFilePrintSetup )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, essa função lida com a execução do comando Imprimir do arquivo.  
  
 Para obter informações sobre o comportamento padrão e orientação sobre como substituir essa função de membro, consulte [22 de nota técnica](../../mfc/tn022-standard-commands-implementation.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[49 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing&#50;](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]  
  
##  <a name="a-nameonhelpa--cwinapponhelp"></a><a name="onhelp"></a>CWinApp::OnHelp  
 Manipula a Ajuda F1 dentro do aplicativo (usando o contexto atual).  
  
```  
afx_msg void OnHelp();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente você também adicionará uma entrada de tecla de aceleração para a tecla F1. Habilitar a tecla F1 é apenas uma convenção, não é um requisito.  
  
 Você deve adicionar uma `ON_COMMAND( ID_HELP, OnHelp )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, chamado pela estrutura quando o usuário pressiona a tecla F1.  
  
 A implementação padrão dessa função de manipulador de mensagens determina o contexto de Ajuda que corresponde ao item de menu, caixa de diálogo ou janela atual e, em seguida, chama WINHELP. EXE. Se nenhum contexto está disponível no momento, a função usa o contexto padrão.  
  
 Substitua essa função de membro para definir o contexto de ajuda para algo diferente de janela, caixa de diálogo, o item de menu ou botão de barra de ferramentas que atualmente tem o foco. Chamar `WinHelp` com a ajudar a ID do contexto.  
  
##  <a name="a-nameonhelpfindera--cwinapponhelpfinder"></a><a name="onhelpfinder"></a>CWinApp::OnHelpFinder  
 Manipula o **ID_HELP_FINDER** e **ID_DEFAULT_HELP** comandos.  
  
```  
afx_msg void OnHelpFinder();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_HELP_FINDER, OnHelpFinder )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, a estrutura chama essa função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando de ajuda Finder para invocar `WinHelp` com o padrão **HELP_FINDER** tópico.  
  
##  <a name="a-nameonhelpindexa--cwinapponhelpindex"></a><a name="onhelpindex"></a>CWinApp::OnHelpIndex  
 Manipula o **ID_HELP_INDEX** de comando e fornece um tópico da Ajuda padrão.  
  
```  
afx_msg void OnHelpIndex();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_HELP_INDEX, OnHelpIndex )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, a estrutura chama essa função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando de índice da Ajuda para invocar `WinHelp` com o padrão **HELP_INDEX** tópico.  
  
##  <a name="a-nameonhelpusinga--cwinapponhelpusing"></a><a name="onhelpusing"></a>CWinApp::OnHelpUsing  
 Manipula o **ID_HELP_USING** comando.  
  
```  
afx_msg void OnHelpUsing();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar uma `ON_COMMAND( ID_HELP_USING, OnHelpUsing )` instrução seu `CWinApp` mapa de mensagem de classe para ativar essa função de membro. O framework chama essa função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando para invocar ajuda usando o `WinHelp` aplicativo com o padrão **HELP_HELPONHELP** tópico.  
  
##  <a name="a-nameonidlea--cwinapponidle"></a><a name="onidle"></a>CWinApp::OnIdle  
 Substitua essa função de membro para executar o processamento de tempo ocioso.  
  
```  
virtual BOOL OnIdle(LONG lCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lCount`  
 Um contador incrementado toda vez que `OnIdle` é chamado quando a fila de mensagens do aplicativo está vazia. Essa contagem é redefinida como 0, sempre que uma nova mensagem é processada. Você pode usar o `lCount` parâmetro para determinar o tamanho relativo de tempo que o aplicativo esteve ocioso sem processamento de uma mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero para receber o tempo de processamento mais ocioso; 0 se não há mais tempo ocioso é necessária.  
  
### <a name="remarks"></a>Comentários  
 `OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do aplicativo está vazia. Use sua substituição para chamar seu próprio plano de fundo tarefas manipulador ocioso.  
  
 `OnIdle`deve retornar 0 para indicar que nenhum processamento de tempo ocioso é necessário. O `lCount` parâmetro é incrementado toda vez que `OnIdle` é chamado quando a fila de mensagens está vazia e redefinido como 0, sempre que uma nova mensagem é processada. Você pode chamar suas rotinas de ociosas diferentes com base nessa contagem.  
  
 A seguir resume o processamento de loop ocioso:  
  
1.  Se o loop de mensagem no Microsoft Foundation Class Library verifica a fila de mensagens e não localiza as mensagens pendentes, ele chama `OnIdle` para o objeto de aplicativo e fontes 0 como o `lCount` argumento.  
  
2. `OnIdle`executa algum processamento e retorna um valor diferente de zero para indicar que ele deve ser chamado novamente para fazer processamento adicional.  
  
3.  O loop de mensagens verifica a fila de mensagem novamente. Se nenhuma mensagem estiver pendente, ele chama `OnIdle` novamente, incrementando o `lCount` argumento.  
  
4.  Por fim, `OnIdle` termina de processar todas as suas tarefas ociosas e retornará 0. Isso informa o loop de mensagem para interromper a chamar `OnIdle` até que seja recebida a próxima mensagem da fila de mensagens, no ponto em que o ciclo ocioso é reiniciado com o argumento definido como 0.  
  
 Não execute tarefas demoradas durante `OnIdle` porque o aplicativo não pode processar a entrada do usuário até `OnIdle` retorna.  
  
> [!NOTE]
>  A implementação padrão de `OnIdle` atualizações de objetos de interface do usuário, como itens de menu e botões da barra de comando, e ele realiza a limpeza de estrutura de dados internos. Portanto, se você substituir `OnIdle`, você deve chamar `CWinApp::OnIdle` com o `lCount` na sua versão substituída. Primeiro chamar processamento ocioso todas as classes base (ou seja, até que a classe base `OnIdle` retorna 0). Se você precisar executar o trabalho antes de concluir o processamento da classe base, analise a implementação de classe base para selecionar o próprio `lCount` durante o qual deseja trabalhar.  
  
 Se você não quiser `OnIdle` para ser chamado sempre que uma mensagem é recuperada da fila de mensagens, você pode substituir o [CWinThreadIsIdleMessage](../../mfc/reference/cwinthread-class.md#isidlemessage). Se um aplicativo definiu um timer muito curto, ou se o sistema está enviando o **WM_SYSTIMER** mensagem, em seguida, `OnIdle` é chamado repetidamente e prejudicar o desempenho.  
  
### <a name="example"></a>Exemplo  
 Os exemplos a seguir mostram como usar `OnIdle`. O primeiro exemplo processa duas tarefas ociosas usando o `lCount` argumento para priorizar as tarefas. A primeira tarefa é alta prioridade, e você deve fazê-lo sempre que possível. A segunda tarefa é menos importante e deve ser feita somente quando há uma longa pausa na entrada do usuário. Observe a chamada para a versão da classe base do `OnIdle`. O segundo exemplo gerencia um grupo de tarefas ociosas com prioridades diferentes.  
  
 [!code-cpp[NVC_MFCWindowing&#51;](../../mfc/reference/codesnippet/cpp/cwinapp-class_27.cpp)]  
  
##  <a name="a-nameopendocumentfilea--cwinappopendocumentfile"></a><a name="opendocumentfile"></a>CWinApp::OpenDocumentFile  
 O framework chama esse método para abrir nomeado [CDocument](../../mfc/reference/cdocument-class.md) arquivo para o aplicativo.  
  
```  
virtual CDocument* OpenDocumentFile(
LPCTSTR lpszFileName  
BOOL bAddToMRU = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszFileName`  
 O nome do arquivo a ser aberto.  
  
 [in] `bAddToMRU`  
 `TRUE`indica que o documento é um dos arquivos mais recentes; `FALSE` indica que o documento não é um dos arquivos mais recentes.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CDocument` se bem-sucedido; caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Se um documento que tem esse nome já estiver aberto, a primeira janela de quadro que contém o documento receberá o foco. Se um aplicativo oferecer suporte a vários modelos de documento, a estrutura usa a extensão de nome de arquivo para localizar o modelo de documento apropriado para tentar carregar o documento. Se for bem-sucedido, o modelo de documento, em seguida, cria uma janela de quadro e o modo de exibição para o documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#52;](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]  
  
##  <a name="a-nameparsecommandlinea--cwinappparsecommandline"></a><a name="parsecommandline"></a>CWinApp::ParseCommandLine  
 Chame essa função de membro para analisar a linha de comando e enviar os parâmetros, um de cada vez, para [CCommandLineInfo::ParseParam](../../mfc/reference/ccommandlineinfo-class.md#parseparam).  
  
```  
void ParseCommandLine(CCommandLineInfo& rCmdInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rCmdInfo`  
 Uma referência a um [CCommandLineInfo](../../mfc/reference/ccommandlineinfo-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Quando você inicia um novo projeto do MFC usando o Assistente de aplicativo, o Assistente de aplicativo criará uma instância local do `CCommandLineInfo`e, em seguida, chame `ProcessShellCommand` e `ParseCommandLine` no [InitInstance](#initinstance) função de membro. Uma linha de comando a seguir a rota descrita abaixo:  
  
1.  Após ser criada em `InitInstance`, o `CCommandLineInfo` objeto é passado para `ParseCommandLine`.  
  
2. `ParseCommandLine`em seguida, chama `CCommandLineInfo::ParseParam` repetidamente, uma vez para cada parâmetro.  
  
3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é então passado para [ProcessShellCommand](#processshellcommand).  
  
4. `ProcessShellCommand`lida com os argumentos de linha de comando e sinalizadores.  
  
 Observe que você pode chamar `ParseCommandLine` diretamente, conforme necessário.  
  
 Para obter uma descrição dos sinalizadores de linha de comando, consulte [CCommandLineInfo::m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand).  
  
##  <a name="a-namepretranslatemessagea--cwinapppretranslatemessage"></a><a name="pretranslatemessage"></a>CWinApp::PreTranslateMessage  
 Substituir essa função para filtrar mensagens de janela antes de serem distribuídos para as funções do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) a implementação padrão executa a conversão de tecla de aceleração, portanto você deve chamar o `CWinApp::PreTranslateMessage` função de membro em sua versão substituída.  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Um ponteiro para um [MSG](../../mfc/reference/msg-structure1.md) estrutura que contém a mensagem para processar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi totalmente processada em `PreTranslateMessage` e não devem ser processadas ainda mais. Zero se a mensagem deve ser processada da maneira normal.  
  
##  <a name="a-nameprocessmessagefiltera--cwinappprocessmessagefilter"></a><a name="processmessagefilter"></a>CWinApp::ProcessMessageFilter  
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
 Um ponteiro para um Windows [MSG](../../mfc/reference/msg-structure1.md) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é processada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma função de gancho processa os eventos antes de serem enviados à mensagem normal do aplicativo de processamento.  
  
 Se você substituir este recurso avançado, certifique-se de chamar a versão da classe base para manter a estrutura de gancho de processamento.  
  
##  <a name="a-nameprocessshellcommanda--cwinappprocessshellcommand"></a><a name="processshellcommand"></a>CWinApp::ProcessShellCommand  
 Essa função de membro é chamada pelo [InitInstance](#initinstance) para aceitar os parâmetros passados do `CCommandLineInfo` objeto identificado por `rCmdInfo`e execute a ação indicada.  
  
```  
BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rCmdInfo`  
 Uma referência a um [CCommandLineInfo](../../mfc/reference/ccommandlineinfo-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando do shell é processado com êxito. Se for 0, retorne **FALSE** de [InitInstance](#initinstance).  
  
### <a name="remarks"></a>Comentários  
 Quando você inicia um novo projeto do MFC usando o Assistente de aplicativo, o Assistente de aplicativo criará uma instância local do `CCommandLineInfo`e, em seguida, chame `ProcessShellCommand` e [ParseCommandLine](#parsecommandline) no `InitInstance` função de membro. Uma linha de comando a seguir a rota descrita abaixo:  
  
1.  Após ser criada em `InitInstance`, o `CCommandLineInfo` objeto é passado para `ParseCommandLine`.  
  
2. `ParseCommandLine`em seguida, chama [CCommandLineInfo::ParseParam](../../mfc/reference/ccommandlineinfo-class.md#parseparam) repetidamente, uma vez para cada parâmetro.  
  
3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é então passado para `ProcessShellCommand`.  
  
4. `ProcessShellCommand`lida com os argumentos de linha de comando e sinalizadores.  
  
 Os membros de dados de `CCommandLineInfo` objeto, identificado por [CCommandLineInfo::m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand), têm o seguinte tipo enumerado, que é definido dentro de `CCommandLineInfo` classe.  
  
 `enum {`  
  
 `FileNew,`  
  
 `FileOpen,`  
  
 `FilePrint,`  
  
 `FilePrintTo,`  
  
 `FileDDE,`  
  
 `};`  
  
 Para obter uma descrição de cada um desses valores, consulte `CCommandLineInfo::m_nShellCommand`.  
  
##  <a name="a-nameprocesswndprocexceptiona--cwinappprocesswndprocexception"></a><a name="processwndprocexception"></a>CWinApp::ProcessWndProcException  
 O framework chama essa função membro sempre que o manipulador não capturar uma exceção lançada em um dos manipuladores de comando ou de mensagens do aplicativo.  
  
```  
virtual LRESULT ProcessWndProcException(
    CException* e,  
    const MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *e*  
 Um ponteiro para uma exceção não tratada.  
  
 `pMsg`  
 A [MSG](../../mfc/reference/msg-structure1.md) estrutura que contém informações sobre a mensagem do windows que causou a estrutura lançar uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor deve ser retornado para o Windows. Geralmente, isso é L 0 para mensagens do windows, 1l ( **TRUE**) para as mensagens de comando.  
  
### <a name="remarks"></a>Comentários  
 Não chame essa função membro diretamente.  
  
 A implementação padrão dessa função de membro cria uma caixa de mensagem. Se origina a exceção não tratada com um menu, a barra de ferramentas ou a falha de comando do acelerador, a caixa de mensagem exibe uma mensagem "Falha no comando"; Caso contrário, ele exibe uma mensagem "Erro interno do aplicativo".  
  
 Substitua essa função de membro para fornecer tratamento global de suas exceções. Chame apenas a funcionalidade básica se desejar que a caixa de mensagem a ser exibida.  
  
##  <a name="a-nameregistera--cwinappregister"></a><a name="register"></a>CWinApp::Register  
 Executa as tarefas de registro não tratadas por `RegisterShellFileTypes`.  
  
```  
virtual BOOL Register();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão simplesmente retorna TRUE. Substitua essa função para fornecer as etapas de registro personalizado.  
  
##  <a name="a-nameregistershellfiletypesa--cwinappregistershellfiletypes"></a><a name="registershellfiletypes"></a>CWinApp::RegisterShellFileTypes  
 Chame essa função de membro para registrar todos os tipos de documento do aplicativo com o Gerenciador de arquivos do Windows.  
  
```  
void RegisterShellFileTypes(BOOL bCompat = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCompat`  
 `TRUE`Adiciona entradas de registro para comandos do shell de impressão e imprimir para, permitindo que um usuário imprimir arquivos diretamente do shell ou arrastando o arquivo para um objeto de impressora. Ele também adiciona uma chave DefaultIcon. Por padrão, esse parâmetro é `FALSE` para compatibilidade com versões anteriores.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que o usuário abra um arquivo de dados criado pelo seu aplicativo clicando nele de dentro do Gerenciador de arquivos. Chamar `RegisterShellFileTypes` depois de você chamar [AddDocTemplate](#adddoctemplate) para cada um dos modelos de documento em seu aplicativo. Também chamada de [EnableShellOpen](#enableshellopen) função de membro ao chamar `RegisterShellFileTypes`.  
  
 `RegisterShellFileTypes`percorre a lista de [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objetos que o aplicativo mantém e, para cada modelo de documento, adiciona entradas para o banco de dados de registro que o Windows mantém para associações de arquivo. Gerenciador de arquivos usa essas entradas para abrir um arquivo de dados quando o usuário clica duas vezes nela. Isso elimina a necessidade de enviar um. Arquivo REG com seu aplicativo.  
  
> [!NOTE]
> `RegisterShellFileTypes`só funciona se o usuário executar o programa com direitos de administrador. Se o programa não tem direitos de administrador, ele não é possível alterar as chaves do registro.  
  
 Se o banco de dados de registro já associa uma extensão de nome de arquivo fornecido com outro tipo de arquivo, nenhuma nova associação será criada. Consulte o `CDocTemplate` classe para o formato de cadeias de caracteres necessárias para registrar essas informações.  
  
##  <a name="a-nameregisterwithrestartmanagera--cwinappregisterwithrestartmanager"></a><a name="registerwithrestartmanager"></a>CWinApp::RegisterWithRestartManager  
 Registra o aplicativo com o Gerenciador de reinicialização.  
  
```  
virtual HRESULT RegisterWithRestartManager(
BOOL bRegisterRecoveryCallback,  
const CString& strRestartIdentifier);

 
virtual HRESULT RegisterWithRestartManager(
LPCWSTR pwzCommandLineArgs,  
DWORD dwRestartFlags,  
APPLICATION_RECOVERY_CALLBACK pRecoveryCallback,  
LPVOID lpvParam,  
DWORD dwPingInterval,  
DWORD dwCallbackFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `bRegisterRecoveryCallback`|`TRUE`indica que esta instância do aplicativo usa uma função de retorno de chamada de recuperação; `FALSE` indica que não. O framework chama a função de retorno de chamada de recuperação quando o aplicativo é encerrado inesperadamente. Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|  
|[in] `strRestartIdentifier`|A cadeia de caracteres exclusiva que identifica esta instância do Gerenciador de reinicialização. O identificador de Gerenciador de reinicialização é exclusivo para cada instância de um aplicativo.|  
|[in] `pwzCommandLineArgs`|Uma cadeia de caracteres que contém quaisquer argumentos adicionais na linha de comando.|  
|[in] `dwRestartFlags`|Sinalizadores opcionais para o Gerenciador de reinicialização. Para obter mais informações, consulte a seção Comentários.|  
|[in] `pRecoveryCallback`|A função de retorno de chamada de recuperação. Essa função deve conter um `LPVOID` parâmetro como entrada e retornar um `DWORD`. A função de retorno de chamada de recuperação padrão é `CWinApp::ApplicationRecoveryCallback`.|  
|[in] `lpvParam`|O parâmetro de entrada para a função de retorno de chamada de recuperação. Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|  
|[in] `dwPingInterval`|O período de tempo que o Gerenciador de reinicialização aguarda que a função de retorno de chamada de recuperação retornar. Esse parâmetro é em milissegundos.|  
|[in] `dwCallbackFlags`|Sinalizadores passados para a função de retorno de chamada de recuperação. Reservado para uso futuro.|  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se o método for bem-sucedido; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo usa a implementação do MFC padrão para arquivos de gravação automática, você deve usar a versão simple do `RegisterWithRestartManager`. Use a versão complexa de `RegisterWithRestartManager` se desejar personalizar o comportamento de salvamento automático do seu aplicativo.  
  
 Se você chamar esse método com uma cadeia de caracteres vazia para `strRestartIdentifier`, `RegisterWithRestartManager` cria uma cadeia de caracteres de identificador exclusivo para esta instância do reinício manager.  
  
 Quando um aplicativo é fechado inesperadamente, o Gerenciador de reinicialização reinicia o aplicativo da linha de comando e fornece que o exclusivo reiniciar identificador como um argumento opcional. Nesse cenário, a estrutura chama `RegisterWithRestartManager` duas vezes. A primeira chamada vem [CWinApp::InitInstance](#initinstance) com uma cadeia de caracteres vazia para o identificador de cadeia de caracteres. Em seguida, o método [CWinApp::ProcessShellCommand](#processshellcommand) chamadas `RegisterWithRestartManager` com o identificador exclusivo de reinicialização.  
  
 Depois de registrar um aplicativo com o Gerenciador de reinicialização, o Gerenciador de reinicialização monitora o aplicativo. Se o aplicativo for fechado inesperadamente, o Gerenciador de reinicialização chama a função de retorno de chamada de recuperação durante o processo de desligamento. As esperas de Gerenciador de reinicialização de `dwPingInterval` por uma resposta da função de retorno de chamada de recuperação. Se a função de retorno de chamada de recuperação não responder dentro desse período, o aplicativo será encerrado sem executar a função de retorno de chamada de recuperação.  
  
 Por padrão, os dwRestartFlags não têm suporte, mas são fornecidos para uso futuro. Os valores possíveis para `dwRestartFlags` são os seguintes:  
  
- `RESTART_NO_CRASH`  
  
- `RESTART_NO_HANG`  
  
- `RESTART_NO_PATCH`  
  
- `RESTART_NO_REBOOT`  
  
##  <a name="a-namereopenpreviousfilesatrestarta--cwinappreopenpreviousfilesatrestart"></a><a name="reopenpreviousfilesatrestart"></a>CWinApp::ReopenPreviousFilesAtRestart  
 Determina se o Gerenciador de reinicialização reabre os arquivos que estavam abertos quando o aplicativo foi encerrado inesperadamente.  
  
```  
virtual BOOL ReopenPreviousFilesAtRestart() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica o restart manager for reaberto arquivos anteriormente abertos; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="a-namerestartinstancea--cwinapprestartinstance"></a><a name="restartinstance"></a>CWinApp::RestartInstance  
 Lida com uma reinicialização do aplicativo iniciada pelo Gerenciador de reinicialização.  
  
```  
virtual BOOL CWinApp::RestartInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o manipulador de recuperação de dados é aberto anteriormente abrir documentos; `FALSE` se o manipulador de recuperação de dados tem um erro ou se não há documentos anteriormente abertos.  
  
### <a name="remarks"></a>Comentários  
 Quando o Gerenciador de reinicialização reinicia um aplicativo, o framework chama esse método. Esse método recupera o manipulador de recuperação de dados e restaura os arquivos salva automaticamente. Esse método chama [CDataRecoveryHandler::RestoreAutosavedDocuments](../../mfc/reference/cdatarecoveryhandler-class.md#restoreautosaveddocuments) para determinar se o usuário deseja restaurar os arquivos salva automaticamente.  
  
 Esse método retorna `FALSE` se o [CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md) determina que não havia nenhum documento aberto. Se não houver nenhum documento aberto, o aplicativo é iniciado normalmente.  
  
##  <a name="a-namerestoreautosavedfilesatrestarta--cwinapprestoreautosavedfilesatrestart"></a><a name="restoreautosavedfilesatrestart"></a>CWinApp::RestoreAutosavedFilesAtRestart  
 Determina se o Gerenciador de reinicialização restaura os arquivos de salva automaticamente quando o aplicativo for reiniciado.  
  
```  
virtual BOOL RestoreAutosavedFilesAtRestart() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica os restart manager restaura salva automaticamente arquivos; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="a-nameruna--cwinapprun"></a><a name="run"></a>CWinApp:: Run  
 Fornece um loop de mensagem padrão.  
  
```  
virtual int Run();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `int` valor retornado por `WinMain`.  
  
### <a name="remarks"></a>Comentários  
 **Executar** adquire e envia mensagens do Windows até que o aplicativo recebe um **WM_QUIT** mensagem. Se a fila de mensagens do aplicativo no momento não contenha mensagens, **executar** chamadas [OnIdle](#onidle) para executar o processamento de tempo ocioso. Mensagens de entrada acessem o [PreTranslateMessage](#pretranslatemessage) função de membro para processamento especial e, em seguida, a função do Windows **TranslateMessage** para a tradução de teclado padrão; por fim, o **DispatchMessage** é chamada de função do Windows.  
  
 **Executar** raramente é substituído, mas você pode substituí-lo para fornecer um comportamento especial.  
  
##  <a name="a-namerunautomateda--cwinapprunautomated"></a><a name="runautomated"></a>CWinApp::RunAutomated  
 Chame essa função para determinar se o " **/Automation**"ou" **-automação**" opção está presente, o que indica se o aplicativo de servidor foi iniciado por um aplicativo cliente.  
  
```  
BOOL RunAutomated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a opção foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se estiver presente, a opção é removida da linha de comando. Para obter mais informações sobre a automação OLE, consulte o artigo [servidores de automação](../../mfc/automation-servers.md).  
  
##  <a name="a-namerunembeddeda--cwinapprunembedded"></a><a name="runembedded"></a>CWinApp::RunEmbedded  
 Chame essa função para determinar se o " **/incorporação**"ou" **-incorporando**" opção está presente, o que indica se o aplicativo de servidor foi iniciado por um aplicativo cliente.  
  
```  
BOOL RunEmbedded();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a opção foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se estiver presente, a opção é removida da linha de comando. Para obter mais informações sobre como incorporar, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md).  
  
##  <a name="a-namesaveallmodifieda--cwinappsaveallmodified"></a><a name="saveallmodified"></a>CWinApp::SaveAllModified  
 Chamado pela estrutura para salvar todos os documentos quando a janela do quadro principal do aplicativo deve ser fechado ou por meio de um `WM_QUERYENDSESSION` mensagem.  
  
```  
virtual BOOL SaveAllModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se seguro para encerrar o aplicativo; 0 se não é seguro para encerrar o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função de membro chama o [CDocument::SaveModified](../../mfc/reference/cdocument-class.md#savemodified) a função de membro para todos os documentos modificados dentro do aplicativo.  
  
##  <a name="a-nameselectprintera--cwinappselectprinter"></a><a name="selectprinter"></a>CWinApp::SelectPrinter  
 Chame essa função de membro para selecionar uma impressora específica e, em seguida, solte a impressora que anteriormente foi selecionada na caixa de diálogo Imprimir.  
  
```  
void SelectPrinter(
    HANDLE hDevNames,  
    HANDLE hDevMode,  
    BOOL bFreeOld = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDevNames`  
 Um identificador para um [DEVNAMES](../../mfc/reference/devnames-structure.md) estrutura que identifica o driver, dispositivos e nomes de porta de saída de uma impressora específica.  
  
 `hDevMode`  
 Um identificador para um [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura que especifica informações sobre o ambiente de uma impressora e inicialização do dispositivo.  
  
 *bFreeOld*  
 Libera a impressora selecionada anteriormente.  
  
### <a name="remarks"></a>Comentários  
 Se ambos os `hDevMode` e `hDevNames` são **nulo**, `SelectPrinter` usa a impressora padrão atual.  
  
##  <a name="a-namesethelpmodea--cwinappsethelpmode"></a><a name="sethelpmode"></a>CWinApp::SetHelpMode  
 Define o tipo de Ajuda do aplicativo.  
  
```  
void SetHelpMode(AFX_HELP_TYPE eHelpType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `eHelpType`  
 Especifica o tipo de ajuda para usar. Consulte [CWinApp::m_eHelpType](#m_ehelptype) para obter mais informações.  
  
### <a name="remarks"></a>Comentários  
 Define o tipo de Ajuda do aplicativo.  
  
 Para definir o tipo de Ajuda do aplicativo a Help, você pode chamar [EnableHTMLHelp](#enablehtmlhelp). Depois de você chamar `EnableHTMLHelp`, seu aplicativo deve usar Help como seu aplicativo de Ajuda. Se você deseja alterar para usar WinHelp, você pode chamar `SetHelpMode` e defina `eHelpType` para **afxWinHelp**.  
  
##  <a name="a-namesetregistrykeya--cwinappsetregistrykey"></a><a name="setregistrykey"></a>CWinApp::SetRegistryKey  
 Faz com que as configurações do aplicativo a ser armazenado no registro em vez de arquivos INI.  
  
```  
void SetRegistryKey(LPCTSTR lpszRegistryKey);  
void SetRegistryKey(UINT nIDRegistryKey);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszRegistryKey*  
 Ponteiro para uma cadeia de caracteres que contém o nome da chave.  
  
 *nIDRegistryKey*  
 ID de um recurso de cadeia de caracteres que contém o nome da chave do registro.  
  
### <a name="remarks"></a>Comentários  
 Essa função define *m_pszRegistryKey*, que é usado pelo `GetProfileInt`, `GetProfileString`, `WriteProfileInt`, e `WriteProfileString` funções de membro `CWinApp`. Se essa função foi chamada, a lista de arquivos usados mais recentemente (MRU) também é armazenada no registro. A chave do registro é geralmente o nome de uma empresa. Ele é armazenado em uma chave da seguinte forma: HKEY_CURRENT_USER\\Software\\<company></company>\>\\<application></application>\>\\<section></section>\>\\<value></value>\>.  
  
##  <a name="a-namesupportsapplicationrecoverya--cwinappsupportsapplicationrecovery"></a><a name="supportsapplicationrecovery"></a>CWinApp::SupportsApplicationRecovery  
 Determina se o Gerenciador de reinicialização recupera um aplicativo que foi encerrado inesperadamente.  
  
```  
virtual BOOL SupportsApplicationRecovery() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica a restart manager recupera o aplicativo; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="a-namesupportsautosaveatintervala--cwinappsupportsautosaveatinterval"></a><a name="supportsautosaveatinterval"></a>CWinApp::SupportsAutosaveAtInterval  
 Determina se o restart manager salve abre documentos em intervalos regulares.  
  
```  
virtual BOOL SupportsAutosaveAtInterval() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o restart manager salve abre documentos; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="a-namesupportsautosaveatrestarta--cwinappsupportsautosaveatrestart"></a><a name="supportsautosaveatrestart"></a>CWinApp::SupportsAutosaveAtRestart  
 Determina se o restart manager Salve quaisquer documentos abertos quando o aplicativo for reiniciado.  
  
```  
virtual BOOL SupportsAutosaveAtRestart() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o restart manager salve documentos abertos quando o aplicativo for reiniciado; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="a-namesupportsrestartmanagera--cwinappsupportsrestartmanager"></a><a name="supportsrestartmanager"></a>CWinApp::SupportsRestartManager  
 Determina se o aplicativo suporta o Gerenciador de reinicialização.  
  
```  
virtual BOOL SupportsRestartManager() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o aplicativo oferece suporte para o Gerenciador de reinicialização; `FALSE` indica que o aplicativo não.  
  
##  <a name="a-nameunregistera--cwinappunregister"></a><a name="unregister"></a>CWinApp::Unregister  
 Cancela o registro de todos os arquivos registrados pelo objeto de aplicativo.  
  
```  
virtual BOOL Unregister();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `Unregister` função desfaz o registro executado pelo objeto de aplicativo e o [registrar](#register) função. Normalmente, ambas as funções são chamadas implicitamente pelo MFC e, portanto, não serão exibidos em seu código.  
  
 Substitua essa função para executar etapas de cancelamento de registro personalizado.  
  
##  <a name="a-nameunregistershellfiletypesa--cwinappunregistershellfiletypes"></a><a name="unregistershellfiletypes"></a>CWinApp::UnregisterShellFileTypes  
 Chame essa função de membro para cancelar o registro de todos os tipos de documento do aplicativo com o Gerenciador de arquivos do Windows.  
  
```  
void UnregisterShellFileTypes();
```  
  
##  <a name="a-namewinhelpa--cwinappwinhelp"></a><a name="winhelp"></a>CWinApp::WinHelp  
 Chame essa função de membro para acionar o aplicativo WinHelp.  
  
```  
virtual void WinHelp(
    DWORD_PTR dwData,  
    UINT nCmd = HELP_CONTEXT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwData`  
 Especifica os dados adicionais. O valor usado depende do valor da `nCmd` parâmetro.  
  
 `nCmd`  
 Especifica o tipo de ajuda solicitado. Para obter uma lista de valores possíveis e como eles afetam o `dwData` parâmetro, consulte o [WinHelp](http://msdn.microsoft.com/library/windows/desktop/bb762267) função do Windows.  
  
### <a name="remarks"></a>Comentários  
 A estrutura também chama essa função para acionar o aplicativo WinHelp.  
  
 O framework fechará automaticamente o aplicativo WinHelp quando seu aplicativo terminar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#53;](../../mfc/reference/codesnippet/cpp/cwinapp-class_28.cpp)]  
  
##  <a name="a-namewriteprofilebinarya--cwinappwriteprofilebinary"></a><a name="writeprofilebinary"></a>CWinApp::WriteProfileBinary  
 Chame essa função de membro para gravar dados binários na seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL WriteProfileBinary(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    LPBYTE pData,  
    UINT nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ele será criado. O nome da seção for independentes. a cadeia de caracteres pode ser qualquer combinação de letras maiusculas e minúsculas.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor é a serem gravados. Se a entrada não existir na seção especificada, ele será criado.  
  
 `pData`  
 Pontos de dados a serem gravados.  
  
 `nBytes`  
 Contém o número de bytes a serem gravados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 Este exemplo usa `CWinApp* pApp = AfxGetApp();` para obter a classe CWinApp ilustrando uma maneira que `WriteProfileBinary` e `GetProfileBinary` pode ser usado em qualquer função em um aplicativo MFC.  
  
 [!code-cpp[NVC_MFCWindowing&#54;](../../mfc/reference/codesnippet/cpp/cwinapp-class_29.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileBinary](#getprofilebinary).  
  
##  <a name="a-namewriteprofileinta--cwinappwriteprofileint"></a><a name="writeprofileint"></a>CWinApp::WriteProfileInt  
 Chame essa função de membro para gravar o valor especificado na seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL WriteProfileInt(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    int nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ele será criado. O nome da seção for independentes. a cadeia de caracteres pode ser qualquer combinação de letras maiusculas e minúsculas.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor é a serem gravados. Se a entrada não existir na seção especificada, ele será criado.  
  
 `nValue`  
 Contém o valor a ser gravado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 Este exemplo usa `CWinApp* pApp = AfxGetApp();` para obter a classe CWinApp ilustrando uma maneira que `WriteProfileString`, `WriteProfileInt`, `GetProfileString`, e `GetProfileInt` pode ser usado em qualquer função em um aplicativo MFC.  
  
 [!code-cpp[NVC_MFCWindowing&#43;](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileInt](#getprofileint).  
  
##  <a name="a-namewriteprofilestringa--cwinappwriteprofilestring"></a><a name="writeprofilestring"></a>CWinApp::WriteProfileString  
 Chame essa função de membro para gravar a cadeia de caracteres especificada na seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL WriteProfileString(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    LPCTSTR lpszValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ele será criado. O nome da seção for independentes. a cadeia de caracteres pode ser qualquer combinação de letras maiusculas e minúsculas.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor é a serem gravados. Se a entrada não existir na seção especificada, ele será criado. Se esse parâmetro for `NULL`, a seção especificada pelo `lpszSection` é excluído.  
  
 `lpszValue`  
 Aponta para a cadeia de caracteres a serem gravados. Se esse parâmetro for `NULL`, a entrada especificada pelo `lpszEntry` parâmetro é excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#43;](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileInt](#getprofileint).  
  
##  <a name="a-namesetappida--cwinappsetappid"></a><a name="setappid"></a>CWinApp::SetAppID  
 Define explicitamente o ID de modelo de usuário do aplicativo para o aplicativo. Esse método deve ser chamado antes de qualquer interface do usuário é apresentado ao usuário (o melhor local é o construtor de aplicativo).  
  
```  
void SetAppID(LPCTSTR lpcszAppID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcszAppID`  
 Especifica a ID de modelo de usuário de aplicativo.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWinThread](../../mfc/reference/cwinthread-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Como: adicionar suporte ao Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)




