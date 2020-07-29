---
title: Classe CWinApp
ms.date: 07/15/2019
f1_keywords:
- CWinApp
- AFXWIN/CWinApp
- AFXWIN/CWinApp::CWinApp
- AFXWIN/CWinApp::AddDocTemplate
- AFXWIN/CWinApp::AddToRecentFileList
- AFXWIN/CWinApp::ApplicationRecoveryCallback
- AFXWIN/CWinApp::CloseAllDocuments
- AFXWIN/CWinApp::CreatePrinterDC
- AFXWIN/CWinApp::DelRegTree
- AFXWIN/CWinApp::DoMessageBox
- AFXWIN/CWinApp::DoWaitCursor
- AFXWIN/CWinApp::EnableD2DSupport
- AFXWIN/CWinApp::EnableHtmlHelp
- AFXWIN/CWinApp::EnableTaskbarInteraction
- AFXWIN/CWinApp::ExitInstance
- AFXWIN/CWinApp::GetApplicationRecoveryParameter
- AFXWIN/CWinApp::GetApplicationRecoveryPingInterval
- AFXWIN/CWinApp::GetApplicationRestartFlags
- AFXWIN/CWinApp::GetAppRegistryKey
- AFXWIN/CWinApp::GetDataRecoveryHandler
- AFXWIN/CWinApp::GetFirstDocTemplatePosition
- AFXWIN/CWinApp::GetHelpMode
- AFXWIN/CWinApp::GetNextDocTemplate
- AFXWIN/CWinApp::GetPrinterDeviceDefaults
- AFXWIN/CWinApp::GetProfileBinary
- AFXWIN/CWinApp::GetProfileInt
- AFXWIN/CWinApp::GetProfileString
- AFXWIN/CWinApp::GetSectionKey
- AFXWIN/CWinApp::HideApplication
- AFXWIN/CWinApp::HtmlHelp
- AFXWIN/CWinApp::InitInstance
- AFXWIN/CWinApp::IsTaskbarInteractionEnabled
- AFXWIN/CWinApp::LoadCursor
- AFXWIN/CWinApp::LoadIcon
- AFXWIN/CWinApp::LoadOEMCursor
- AFXWIN/CWinApp::LoadOEMIcon
- AFXWIN/CWinApp::LoadStandardCursor
- AFXWIN/CWinApp::LoadStandardIcon
- AFXWIN/CWinApp::OnDDECommand
- AFXWIN/CWinApp::OnIdle
- AFXWIN/CWinApp::OpenDocumentFile
- AFXWIN/CWinApp::ParseCommandLine
- AFXWIN/CWinApp::PreTranslateMessage
- AFXWIN/CWinApp::ProcessMessageFilter
- AFXWIN/CWinApp::ProcessShellCommand
- AFXWIN/CWinApp::ProcessWndProcException
- AFXWIN/CWinApp::Register
- AFXWIN/CWinApp::RegisterWithRestartManager
- AFXWIN/CWinApp::ReopenPreviousFilesAtRestart
- AFXWIN/CWinApp::RestartInstance
- AFXWIN/CWinApp::RestoreAutosavedFilesAtRestart
- AFXWIN/CWinApp::Run
- AFXWIN/CWinApp::RunAutomated
- AFXWIN/CWinApp::RunEmbedded
- AFXWIN/CWinApp::SaveAllModified
- AFXWIN/CWinApp::SelectPrinter
- AFXWIN/CWinApp::SetHelpMode
- AFXWIN/CWinApp::SupportsApplicationRecovery
- AFXWIN/CWinApp::SupportsAutosaveAtInterval
- AFXWIN/CWinApp::SupportsAutosaveAtRestart
- AFXWIN/CWinApp::SupportsRestartManager
- AFXWIN/CWinApp::Unregister
- AFXWIN/CWinApp::WinHelp
- AFXWIN/CWinApp::WriteProfileBinary
- AFXWIN/CWinApp::WriteProfileInt
- AFXWIN/CWinApp::WriteProfileString
- AFXWIN/CWinApp::EnableShellOpen
- AFXWIN/CWinApp::LoadStdProfileSettings
- AFXWIN/CWinApp::OnContextHelp
- AFXWIN/CWinApp::OnFileNew
- AFXWIN/CWinApp::OnFileOpen
- AFXWIN/CWinApp::OnFilePrintSetup
- AFXWIN/CWinApp::OnHelp
- AFXWIN/CWinApp::OnHelpFinder
- AFXWIN/CWinApp::OnHelpIndex
- AFXWIN/CWinApp::OnHelpUsing
- AFXWIN/CWinApp::RegisterShellFileTypes
- AFXWIN/CWinApp::SetAppID
- AFXWIN/CWinApp::SetRegistryKey
- AFXWIN/CWinApp::UnregisterShellFileTypes
- AFXWIN/CWinApp::m_bHelpMode
- AFXWIN/CWinApp::m_eHelpType
- AFXWIN/CWinApp::m_hInstance
- AFXWIN/CWinApp::m_lpCmdLine
- AFXWIN/CWinApp::m_nCmdShow
- AFXWIN/CWinApp::m_pActiveWnd
- AFXWIN/CWinApp::m_pszAppID
- AFXWIN/CWinApp::m_pszAppName
- AFXWIN/CWinApp::m_pszExeName
- AFXWIN/CWinApp::m_pszHelpFilePath
- AFXWIN/CWinApp::m_pszProfileName
- AFXWIN/CWinApp::m_pszRegistryKey
- AFXWIN/CWinApp::m_dwRestartManagerSupportFlags
- AFXWIN/CWinApp::m_nAutosaveInterval
- AFXWIN/CWinApp::m_pDataRecoveryHandler
helpviewer_keywords:
- CWinApp [MFC], CWinApp
- CWinApp [MFC], AddDocTemplate
- CWinApp [MFC], AddToRecentFileList
- CWinApp [MFC], ApplicationRecoveryCallback
- CWinApp [MFC], CloseAllDocuments
- CWinApp [MFC], CreatePrinterDC
- CWinApp [MFC], DelRegTree
- CWinApp [MFC], DoMessageBox
- CWinApp [MFC], DoWaitCursor
- CWinApp [MFC], EnableD2DSupport
- CWinApp [MFC], EnableHtmlHelp
- CWinApp [MFC], EnableTaskbarInteraction
- CWinApp [MFC], ExitInstance
- CWinApp [MFC], GetApplicationRecoveryParameter
- CWinApp [MFC], GetApplicationRecoveryPingInterval
- CWinApp [MFC], GetApplicationRestartFlags
- CWinApp [MFC], GetAppRegistryKey
- CWinApp [MFC], GetDataRecoveryHandler
- CWinApp [MFC], GetFirstDocTemplatePosition
- CWinApp [MFC], GetHelpMode
- CWinApp [MFC], GetNextDocTemplate
- CWinApp [MFC], GetPrinterDeviceDefaults
- CWinApp [MFC], GetProfileBinary
- CWinApp [MFC], GetProfileInt
- CWinApp [MFC], GetProfileString
- CWinApp [MFC], GetSectionKey
- CWinApp [MFC], HideApplication
- CWinApp [MFC], HtmlHelp
- CWinApp [MFC], InitInstance
- CWinApp [MFC], IsTaskbarInteractionEnabled
- CWinApp [MFC], LoadCursor
- CWinApp [MFC], LoadIcon
- CWinApp [MFC], LoadOEMCursor
- CWinApp [MFC], LoadOEMIcon
- CWinApp [MFC], LoadStandardCursor
- CWinApp [MFC], LoadStandardIcon
- CWinApp [MFC], OnDDECommand
- CWinApp [MFC], OnIdle
- CWinApp [MFC], OpenDocumentFile
- CWinApp [MFC], ParseCommandLine
- CWinApp [MFC], PreTranslateMessage
- CWinApp [MFC], ProcessMessageFilter
- CWinApp [MFC], ProcessShellCommand
- CWinApp [MFC], ProcessWndProcException
- CWinApp [MFC], Register
- CWinApp [MFC], RegisterWithRestartManager
- CWinApp [MFC], ReopenPreviousFilesAtRestart
- CWinApp [MFC], RestartInstance
- CWinApp [MFC], RestoreAutosavedFilesAtRestart
- CWinApp [MFC], Run
- CWinApp [MFC], RunAutomated
- CWinApp [MFC], RunEmbedded
- CWinApp [MFC], SaveAllModified
- CWinApp [MFC], SelectPrinter
- CWinApp [MFC], SetHelpMode
- CWinApp [MFC], SupportsApplicationRecovery
- CWinApp [MFC], SupportsAutosaveAtInterval
- CWinApp [MFC], SupportsAutosaveAtRestart
- CWinApp [MFC], SupportsRestartManager
- CWinApp [MFC], Unregister
- CWinApp [MFC], WinHelp
- CWinApp [MFC], WriteProfileBinary
- CWinApp [MFC], WriteProfileInt
- CWinApp [MFC], WriteProfileString
- CWinApp [MFC], EnableShellOpen
- CWinApp [MFC], LoadStdProfileSettings
- CWinApp [MFC], OnContextHelp
- CWinApp [MFC], OnFileNew
- CWinApp [MFC], OnFileOpen
- CWinApp [MFC], OnFilePrintSetup
- CWinApp [MFC], OnHelp
- CWinApp [MFC], OnHelpFinder
- CWinApp [MFC], OnHelpIndex
- CWinApp [MFC], OnHelpUsing
- CWinApp [MFC], RegisterShellFileTypes
- CWinApp [MFC], SetAppID
- CWinApp [MFC], SetRegistryKey
- CWinApp [MFC], UnregisterShellFileTypes
- CWinApp [MFC], m_bHelpMode
- CWinApp [MFC], m_eHelpType
- CWinApp [MFC], m_hInstance
- CWinApp [MFC], m_lpCmdLine
- CWinApp [MFC], m_nCmdShow
- CWinApp [MFC], m_pActiveWnd
- CWinApp [MFC], m_pszAppID
- CWinApp [MFC], m_pszAppName
- CWinApp [MFC], m_pszExeName
- CWinApp [MFC], m_pszHelpFilePath
- CWinApp [MFC], m_pszProfileName
- CWinApp [MFC], m_pszRegistryKey
- CWinApp [MFC], m_dwRestartManagerSupportFlags
- CWinApp [MFC], m_nAutosaveInterval
- CWinApp [MFC], m_pDataRecoveryHandler
ms.assetid: e426a3cd-0d15-40d6-bd55-beaa5feb2343
ms.openlocfilehash: 580ed06f82d0341bddb959df99f68c5fc244a3df
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182922"
---
# <a name="cwinapp-class"></a>Classe CWinApp

A classe base da qual você deriva um objeto de aplicativo do Windows.

## <a name="syntax"></a>Sintaxe

```
class CWinApp : public CWinThread
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp:: CWinApp](#cwinapp)|Constrói um objeto `CWinApp`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp:: AddDocTemplate](#adddoctemplate)|Adiciona um modelo de documento à lista de modelos de documentos disponíveis do aplicativo.|
|[CWinApp:: AddToRecentFileList](#addtorecentfilelist)|Adiciona um nome de arquivo à lista de arquivos MRU (usados mais recentemente).|
|[CWinApp:: ApplicationRecoveryCallback](#applicationrecoverycallback)|Chamado pelo Framework quando o aplicativo é encerrado inesperadamente.|
|[CWinApp:: CloseAllDocuments](#closealldocuments)|Fecha todos os documentos abertos.|
|[CWinApp:: CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora.|
|[CWinApp::D elRegTree](#delregtree)|Exclui uma chave especificada e todas as suas subchaves.|
|[CWinApp::D oMessageBox](#domessagebox)|Implementa [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para o aplicativo.|
|[CWinApp::D oWaitCursor](#dowaitcursor)|Ativa e desativa o cursor de espera.|
|[CWinApp:: EnableD2DSupport](#enabled2dsupport)|Habilita o suporte do Application D2D. Chame esse método antes que a janela principal seja inicializada.|
|[CWinApp:: EnableHtmlHelp](#enablehtmlhelp)|Implementa HTMLHelp para o aplicativo, em vez de WinHelp.|
|[CWinApp:: EnableTaskbarInteraction](#enabletaskbarinteraction)|Habilita a interação da barra de tarefas.|
|[CWinApp:: ExitInstance](#exitinstance)|Substitua para limpar quando o aplicativo for encerrado.|
|[CWinApp:: GetApplicationRecoveryParameter](#getapplicationrecoveryparameter)|Recupera o parâmetro de entrada para o método de recuperação do aplicativo.|
|[CWinApp:: GetApplicationRecoveryPingInterval](#getapplicationrecoverypinginterval)|Retorna o período de tempo que o Gerenciador de reinicialização aguarda para que a função de retorno de chamada de recuperação seja retornada.|
|[CWinApp:: GetApplicationRestartFlags](#getapplicationrestartflags)|Retorna os sinalizadores para o Gerenciador de reinicialização.|
|[CWinApp:: GetAppRegistryKey](#getappregistrykey)|Retorna a chave para HKEY_CURRENT_USER \\ "software" \RegistryKey\ProfileName.|
|[CWinApp:: GetDataRecoveryHandler](#getdatarecoveryhandler)|Obtém o manipulador de recuperação de dados para esta instância do aplicativo.|
|[CWinApp:: GetFirstDocTemplatePosition](#getfirstdoctemplateposition)|Recupera a posição do primeiro modelo de documento.|
|[CWinApp:: gethelpmode](#gethelpmode)|Recupera o tipo de ajuda usado pelo aplicativo.|
|[CWinApp:: GetNextDocTemplate](#getnextdoctemplate)|Recupera a posição de um modelo de documento. Pode ser usado recursivamente.|
|[CWinApp:: GetPrinterDeviceDefaults](#getprinterdevicedefaults)|Recupera os padrões do dispositivo de impressora.|
|[CWinApp:: GetProfileBinary](#getprofilebinary)|Recupera dados binários de uma entrada no aplicativo. Arquivo INI.|
|[CWinApp:: GetProfileInt](#getprofileint)|Recupera um inteiro de uma entrada no aplicativo. Arquivo INI.|
|[CWinApp:: GetProfileString](#getprofilestring)|Recupera uma cadeia de caracteres de uma entrada no aplicativo. Arquivo INI.|
|[CWinApp:: GetSectionKey](#getsectionkey)|Retorna a chave para HKEY_CURRENT_USER \\ "software" \RegistryKey\AppName\lpszSection.|
|[CWinApp:: HideApplication](#hideapplication)|Oculta o aplicativo antes de fechar todos os documentos.|
|[CWinApp:: HtmlHelp](#htmlhelp)|Chama a `HTMLHelp` função do Windows.|
|[CWinApp:: InitInstance](#initinstance)|Substitua para executar a inicialização da instância do Windows, como a criação de objetos de janela.|
|[CWinApp:: IsTaskbarInteractionEnabled](#istaskbarinteractionenabled)|Informa se a interação da barra de tarefas do Windows 7 está habilitada.|
|[CWinApp:: LoadCursor](#loadcursor)|Carrega um recurso de cursor.|
|[CWinApp:: LoadIcon](#loadicon)|Carrega um recurso de ícone.|
|[CWinApp:: LoadOEMCursor](#loadoemcursor)|Carrega um cursor predefinido OEM do Windows que as constantes do **OCR_** especificam no Windows. T.|
|[CWinApp:: LoadOEMIcon](#loadoemicon)|Carrega um ícone de OEM do Windows predefinido que as constantes de **OIC_** especificam no Windows. T.|
|[CWinApp:: LoadStandardCursor](#loadstandardcursor)|Carrega um cursor predefinido do Windows que as constantes de **IDC_** especificam no Windows. T.|
|[CWinApp:: LoadStandardIcon](#loadstandardicon)|Carrega um ícone predefinido do Windows que as constantes do **IDI_** especificam no Windows. T.|
|[CWinApp:: OnDDECommand](#onddecommand)|Chamado pelo Framework em resposta a um comando de execução de intercâmbio de dados dinâmico (DDE).|
|[CWinApp:: OnIdle](#onidle)|Substitua para executar o processamento de tempo ocioso específico do aplicativo.|
|[CWinApp:: OpenDocumentfile](#opendocumentfile)|Chamado pelo Framework para abrir um documento a partir de um arquivo.|
|[CWinApp::P arseCommandLine](#parsecommandline)|Analisa parâmetros e sinalizadores individuais na linha de comando.|
|[CWinApp::P reTranslateMessage](#pretranslatemessage)|Filtra mensagens antes que elas sejam expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).|
|[CWinApp::P rocessMessageFilter](#processmessagefilter)|Intercepta determinadas mensagens antes que elas cheguem ao aplicativo.|
|[CWinApp::P rocessShellCommand](#processshellcommand)|Manipula argumentos de linha de comando e sinalizadores.|
|[CWinApp::P rocessWndProcException](#processwndprocexception)|Intercepta todas as exceções sem tratamento lançadas pelos manipuladores de mensagem e comando do aplicativo.|
|[CWinApp:: Register](#register)|Executa o registro personalizado.|
|[CWinApp:: RegisterWithRestartManager](#registerwithrestartmanager)|Registra o aplicativo com o Gerenciador de reinicialização.|
|[CWinApp:: ReopenPreviousFilesAtRestart](#reopenpreviousfilesatrestart)|Determina se o Gerenciador de reinicialização reabrirá os arquivos que estavam abertos quando o aplicativo foi encerrado inesperadamente.|
|[CWinApp:: RestartInstance](#restartinstance)|Manipula uma reinicialização do aplicativo iniciada pelo Gerenciador de reinicialização.|
|[CWinApp:: RestoreAutosavedFilesAtRestart](#restoreautosavedfilesatrestart)|Determina se o Gerenciador de reinicialização restaura os arquivos salvos novamente quando reinicia o aplicativo.|
|[CWinApp:: Run](#run)|Executa o loop de mensagem padrão. Substitua para personalizar o loop de mensagem.|
|[CWinApp:: RunAutomated](#runautomated)|Testa a linha de comando do aplicativo para a opção **/Automation** . Obsoleto. Em vez disso, use o valor em [CCommandLineInfo:: m_bRunAutomated](../../mfc/reference/ccommandlineinfo-class.md#m_brunautomated) depois de chamar [ParseCommandLine](#parsecommandline).|
|[CWinApp:: RunEmbedded](#runembedded)|Testa a linha de comando do aplicativo para a opção **/Embedding** . Obsoleto. Em vez disso, use o valor em [CCommandLineInfo:: m_bRunEmbedded](../../mfc/reference/ccommandlineinfo-class.md#m_brunembedded) depois de chamar [ParseCommandLine](#parsecommandline).|
|[CWinApp:: SaveAllModified](#saveallmodified)|Solicita que o usuário salve todos os documentos modificados.|
|[CWinApp:: SelectPrinter](#selectprinter)|Seleciona uma impressora indicada anteriormente por um usuário por meio de uma caixa de diálogo Imprimir.|
|[CWinApp:: SetHelpMode](#sethelpmode)|Define e inicializa o tipo de ajuda usado pelo aplicativo.|
|[CWinApp:: SupportsApplicationRecovery](#supportsapplicationrecovery)|Determina se o Gerenciador de reinicialização recupera um aplicativo que foi encerrado inesperadamente.|
|[CWinApp:: SupportsAutosaveAtInterval](#supportsautosaveatinterval)|Determina se o Gerenciador de reinicialização salva novamente os documentos abertos em intervalos regulares.|
|[CWinApp:: SupportsAutosaveAtRestart](#supportsautosaveatrestart)|Determina se o Gerenciador de reinicialização salva o salvamento automática de todos os documentos abertos quando o aplicativo é reiniciado.|
|[CWinApp:: SupportsRestartManager](#supportsrestartmanager)|Determina se o aplicativo dá suporte ao Gerenciador de reinicialização.|
|[CWinApp:: cancelar registro](#unregister)|Cancela o registro de tudo o que é conhecido como registrado pelo `CWinApp` objeto.|
|[CWinApp:: WinHelp](#winhelp)|Chama a `WinHelp` função do Windows.|
|[CWinApp:: WriteProfileBinary](#writeprofilebinary)|Grava dados binários em uma entrada no do aplicativo. Arquivo INI.|
|[CWinApp:: WriteProfileInt](#writeprofileint)|Grava um inteiro em uma entrada no aplicativo. Arquivo INI.|
|[CWinApp:: WriteProfileString](#writeprofilestring)|Grava uma cadeia de caracteres em uma entrada no aplicativo. Arquivo INI.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp:: EnableShellOpen](#enableshellopen)|Permite que o usuário abra arquivos de dados do Gerenciador de arquivos do Windows.|
|[CWinApp:: LoadStdProfileSettings](#loadstdprofilesettings)|Carrega o padrão. Configurações de arquivo INI e habilita o recurso de lista de arquivos MRU.|
|[CWinApp:: OnContextHelp](#oncontexthelp)|Manipula a ajuda do SHIFT + F1 dentro do aplicativo.|
|[CWinApp:: OnFileNew](#onfilenew)|Implementa o comando ID_FILE_NEW.|
|[CWinApp:: OnFileOpen](#onfileopen)|Implementa o comando ID_FILE_OPEN.|
|[CWinApp:: OnFilePrintSetup](#onfileprintsetup)|Implementa o comando ID_FILE_PRINT_SETUP.|
|[CWinApp:: OnHelp](#onhelp)|Manipula a ajuda F1 dentro do aplicativo (usando o contexto atual).|
|[CWinApp:: OnHelpFinder](#onhelpfinder)|Manipula os comandos ID_HELP_FINDER e ID_DEFAULT_HELP.|
|[CWinApp:: OnHelpIndex](#onhelpindex)|Manipula o comando ID_HELP_INDEX e fornece um tópico de ajuda padrão.|
|[CWinApp:: OnHelpUsing](#onhelpusing)|Manipula o comando ID_HELP_USING.|
|[CWinApp:: RegisterShellFileTypes](#registershellfiletypes)|Registra todos os tipos de documento do aplicativo com o Gerenciador de arquivos do Windows.|
|[CWinApp:: setappid](#setappid)|Define explicitamente a ID do modelo de usuário do aplicativo para o aplicativo. Esse método deve ser chamado antes que qualquer interface do usuário seja apresentada ao usuário (o melhor lugar é o construtor do aplicativo).|
|[CWinApp:: SetRegistryKey](#setregistrykey)|Faz com que as configurações do aplicativo sejam armazenadas no registro em vez de. Arquivos INI.|
|[CWinApp:: UnregisterShellFileTypes](#unregistershellfiletypes)|Cancela o registro de todos os tipos de documento do aplicativo com o Gerenciador de arquivos do Windows.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp:: m_bHelpMode](#m_bhelpmode)|Indica se o usuário está no modo de contexto de ajuda (normalmente invocado com SHIFT + F1).|
|[CWinApp:: m_eHelpType](#m_ehelptype)|Especifica o tipo de ajuda usado pelo aplicativo.|
|[CWinApp:: m_hInstance](#m_hinstance)|Identifica a instância atual do aplicativo.|
|[CWinApp:: m_lpCmdLine](#m_lpcmdline)|Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo.|
|[CWinApp:: m_nCmdShow](#m_ncmdshow)|Especifica como a janela deve ser mostrada inicialmente.|
|[CWinApp:: m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo de contêiner quando um servidor OLE está ativo no local.|
|[CWinApp:: m_pszAppID](#m_pszappid)|ID do modelo de usuário do aplicativo.|
|[CWinApp:: m_pszAppName](#m_pszappname)|Especifica o nome do aplicativo.|
|[CWinApp:: m_pszExeName](#m_pszexename)|O nome do módulo do aplicativo.|
|[CWinApp:: m_pszHelpFilePath](#m_pszhelpfilepath)|O caminho para o arquivo de ajuda do aplicativo.|
|[CWinApp:: m_pszProfileName](#m_pszprofilename)|O aplicativo. Nome de arquivo INI.|
|[CWinApp:: m_pszRegistryKey](#m_pszregistrykey)|Usado para determinar a chave do registro completa para armazenar as configurações do perfil de aplicativo.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp:: m_dwRestartManagerSupportFlags](#m_dwrestartmanagersupportflags)|Sinalizadores que determinam a forma como o Gerenciador de reinicialização se comporta.|
|[CWinApp:: m_nAutosaveInterval](#m_nautosaveinterval)|O período de tempo em milissegundos entre os salvamentos autosalvos.|
|[CWinApp:: m_pDataRecoveryHandler](#m_pdatarecoveryhandler)|Ponteiro para o manipulador de recuperação de dados do aplicativo.|

## <a name="remarks"></a>Comentários

Um objeto de aplicativo fornece funções de membro para inicializar seu aplicativo (e cada instância dele) e para executar o aplicativo.

Cada aplicativo que usa as classes do Microsoft Foundation pode conter apenas um objeto derivado de `CWinApp` . Esse objeto é construído quando outros objetos globais do C++ são construídos e já estão disponíveis quando o Windows chama a `WinMain` função, que é fornecida pelo biblioteca MFC. Declare o `CWinApp` objeto derivado no nível global.

Quando você deriva uma classe de aplicativo de `CWinApp` , substitua a função de membro [InitInstance](#initinstance) para criar o objeto de janela principal do seu aplicativo.

Além das funções de `CWinApp` membro, o biblioteca MFC fornece as seguintes funções globais para acessar seu `CWinApp` objeto e outras informações globais:

- [AfxGetApp](application-information-and-management.md#afxgetapp) Obtém um ponteiro para o `CWinApp` objeto.

- [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle) Obtém um identificador para a instância do aplicativo atual.

- [AfxGetResourceHandle](application-information-and-management.md#afxgetresourcehandle) Obtém um identificador para os recursos do aplicativo.

- [AfxGetAppName](application-information-and-management.md#afxgetappname) Obtém um ponteiro para uma cadeia de caracteres que contém o nome do aplicativo. Como alternativa, se você tiver um ponteiro para o `CWinApp` objeto, use `m_pszExeName` para obter o nome do aplicativo.

Consulte [CWinApp: a classe Application](../../mfc/cwinapp-the-application-class.md) para saber mais sobre a `CWinApp` classe, incluindo uma visão geral do seguinte:

- `CWinApp`-código derivado escrito pelo assistente de aplicativo.

- `CWinApp`função do na sequência de execução do seu aplicativo.

- `CWinApp`implementações de função de membro padrão.

- `CWinApp`chave substituíveis do.

O `m_hPrevInstance` membro de dados não existe mais. Para determinar se outra instância do aplicativo está em execução, use um mutex nomeado. Se a abertura do mutex falhar, não haverá nenhuma outra instância do aplicativo em execução.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWinThread](../../mfc/reference/cwinthread-class.md)

`CWinApp`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="cwinappadddoctemplate"></a><a name="adddoctemplate"></a>CWinApp:: AddDocTemplate

Chame essa função de membro para adicionar um modelo de documento à lista de modelos de documentos disponíveis que o aplicativo mantém.

```cpp
void AddDocTemplate(CDocTemplate* pTemplate);
```

### <a name="parameters"></a>parâmetros

*pTemplate*<br/>
Um ponteiro para o `CDocTemplate` a ser adicionado.

### <a name="remarks"></a>Comentários

Você deve adicionar todos os modelos de documento a um aplicativo antes de chamar [RegisterShellFileTypes](#registershellfiletypes).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#35](../../mfc/reference/codesnippet/cpp/cwinapp-class_1.cpp)]

## <a name="cwinappaddtorecentfilelist"></a><a name="addtorecentfilelist"></a>CWinApp:: AddToRecentFileList

Chame essa função de membro para adicionar *lpszPathName* à lista de arquivos MRU.

```
virtual void AddToRecentFileList(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>parâmetros

*lpszPathName*<br/>
O caminho do arquivo.

### <a name="remarks"></a>Comentários

Você deve chamar a função de membro [LoadStdProfileSettings](#loadstdprofilesettings) para carregar a lista de arquivos MRU atual antes de usar essa função de membro.

A estrutura chama essa função de membro quando abre um arquivo ou executa o comando Salvar como para salvar um arquivo com um novo nome.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#36](../../mfc/reference/codesnippet/cpp/cwinapp-class_2.cpp)]

## <a name="cwinappapplicationrecoverycallback"></a><a name="applicationrecoverycallback"></a>CWinApp:: ApplicationRecoveryCallback

Chamado pelo Framework quando o aplicativo é encerrado inesperadamente.

```
virtual DWORD ApplicationRecoveryCallback(LPVOID lpvParam);
```

### <a name="parameters"></a>parâmetros

*lpvParam*<br/>
no Reservado para uso futuro.

### <a name="return-value"></a>Valor retornado

0 se esse método for bem-sucedido; diferente de zero se ocorrer um erro.

### <a name="remarks"></a>Comentários

Se seu aplicativo der suporte ao Gerenciador de reinicialização, a estrutura chamará essa função quando seu aplicativo for encerrado inesperadamente.

A implementação padrão do `ApplicationRecoveryCallback` usa o `CDataRecoveryHandler` para salvar a lista de documentos abertos no momento no registro. Esse método não salva arquivos em salvamento automático.

Para personalizar o comportamento, substitua essa função em uma [classe CWinApp](../../mfc/reference/cwinapp-class.md) derivada ou passe seu próprio método de recuperação de aplicativo como um parâmetro para [CWinApp:: RegisterWithRestartManager](#registerwithrestartmanager).

## <a name="cwinappclosealldocuments"></a><a name="closealldocuments"></a>CWinApp:: CloseAllDocuments

Chame essa função de membro para fechar todos os documentos abertos antes de sair.

```cpp
void CloseAllDocuments(BOOL bEndSession);
```

### <a name="parameters"></a>parâmetros

*bEndSession*<br/>
Especifica se a sessão do Windows está sendo finalizada ou não. Será verdadeiro se a sessão estiver sendo encerrada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame [HideApplication](#hideapplication) antes de chamar `CloseAllDocuments` .

## <a name="cwinappcreateprinterdc"></a><a name="createprinterdc"></a>CWinApp:: CreatePrinterDC

Chame essa função de membro para criar um DC (contexto de dispositivo de impressora) da impressora selecionada.

```
BOOL CreatePrinterDC(CDC& dc);
```

### <a name="parameters"></a>parâmetros

*origem*<br/>
Uma referência a um contexto de dispositivo de impressora.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o contexto do dispositivo de impressora for criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

`CreatePrinterDC`Inicializa o contexto do dispositivo que você passa por referência, para que você possa usá-lo para impressão.

Se a função for bem-sucedida, quando terminar de imprimir, você deverá destruir o contexto do dispositivo. Você pode permitir que o destruidor do objeto [CDC](../../mfc/reference/cdc-class.md) faça isso, ou pode fazê-lo explicitamente chamando [CDC::D eletedc](../../mfc/reference/cdc-class.md#deletedc).

## <a name="cwinappcwinapp"></a><a name="cwinapp"></a>CWinApp:: CWinApp

Constrói um `CWinApp` objeto e passa *lpszAppName* para ser armazenado como o nome do aplicativo.

```
CWinApp(LPCTSTR lpszAppName = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszAppName*<br/>
Uma cadeia de caracteres terminada em nulo que contém o nome do aplicativo que o Windows usa. Se esse argumento não for fornecido ou for nulo, `CWinApp` o usará a cadeia de caracteres de recurso AFX_IDS_APP_TITLE ou o nome do arquivo executável.

### <a name="remarks"></a>Comentários

Você deve construir um objeto global da sua `CWinApp` classe derivada. Você pode ter apenas um `CWinApp` objeto em seu aplicativo. O Construtor armazena um ponteiro para o `CWinApp` objeto para que `WinMain` possa chamar as funções de membro do objeto para inicializar e executar o aplicativo.

## <a name="cwinappdelregtree"></a><a name="delregtree"></a>CWinApp::D elRegTree

Exclui uma chave de Registro específica e todas as suas subchaves.

```
LONG DelRegTree(
    HKEY hParentKey,
    const CString& strKeyName);

LONG DelRegTree(
    HKEY hParentKey,
    const CString& strKeyName,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*hParentKey*<br/>
Identificador para uma chave do registro.

*strKeyName*<br/>
O nome da chave do registro a ser excluída.

*pTM*<br/>
Ponteiro para objeto CAtlTransactionManager.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro diferente de zero definido em Winerror. h.

### <a name="remarks"></a>Comentários

Chame essa função para excluir a chave especificada e suas subchaves.

## <a name="cwinappdomessagebox"></a><a name="domessagebox"></a>CWinApp::D oMessageBox

A estrutura chama essa função de membro para implementar uma caixa de mensagem para a função global [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox).

```
virtual int DoMessageBox(
    LPCTSTR lpszPrompt,
    UINT nType,
    UINT nIDPrompt);
```

### <a name="parameters"></a>parâmetros

*lpszPrompt*<br/>
Endereço do texto na caixa de mensagem.

*nType*<br/>
O [estilo](../../mfc/reference/styles-used-by-mfc.md#message-box-styles)da caixa de mensagem.

*nIDPrompt*<br/>
Um índice para uma cadeia de caracteres de contexto de ajuda.

### <a name="return-value"></a>Valor retornado

Retorna os mesmos valores de `AfxMessageBox` .

### <a name="remarks"></a>Comentários

Não chame essa função de membro para abrir uma caixa de mensagem; Use `AfxMessageBox` em vez disso.

Substitua essa função de membro para personalizar o processamento de chamadas em todo o aplicativo `AfxMessageBox` .

## <a name="cwinappdowaitcursor"></a><a name="dowaitcursor"></a>CWinApp::D oWaitCursor

Essa função de membro é chamada pelo Framework para implementar [CWaitCursor](../../mfc/reference/cwaitcursor-class.md), [CCmdTarget:: BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor), [CCmdTarget:: EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)e [CCmdTarget:: RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).

```
virtual void DoWaitCursor(int nCode);
```

### <a name="parameters"></a>parâmetros

*nCode*<br/>
Se esse parâmetro for 1, um cursor de espera será exibido. Se for 0, o cursor de espera será restaurado sem incrementar a contagem de referência. Se-1, o cursor de espera terminará.

### <a name="remarks"></a>Comentários

O padrão implementa um cursor de ampulheta. `DoWaitCursor`mantém uma contagem de referência. Quando positivo, o cursor de ampulheta é exibido.

Embora você normalmente não chame `DoWaitCursor` diretamente, poderia substituir essa função de membro para alterar o cursor de espera ou fazer processamento adicional enquanto o cursor de espera é exibido.

Para uma maneira mais fácil e simplificada de implementar um cursor de espera, use `CWaitCursor` .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#37](../../mfc/reference/codesnippet/cpp/cwinapp-class_3.cpp)]

## <a name="cwinappenabled2dsupport"></a><a name="enabled2dsupport"></a>CWinApp:: EnableD2DSupport

O Visual Studio 2010 SP1 é necessário.

Habilita o suporte do Application D2D. Chame esse método antes que a janela principal seja inicializada.

```
BOOL EnableD2DSupport(
    D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED,
    DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);
```

### <a name="parameters"></a>parâmetros

*d2dFactoryType*<br/>
O modelo de Threading da fábrica D2D e os recursos que ele cria.

*writeFactoryType*<br/>
Um valor que especifica se o objeto de fábrica de gravação será compartilhado ou isolado

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o suporte a D2D foi habilitado; caso contrário, FALSE

## <a name="cwinappenablehtmlhelp"></a><a name="enablehtmlhelp"></a>CWinApp:: EnableHtmlHelp

Chame essa função de membro de dentro do construtor de sua `CWinApp` classe derivada para usar HTMLHelp para a ajuda do seu aplicativo.

```cpp
void EnableHtmlHelp();
```

### <a name="remarks"></a>Comentários

## <a name="cwinappenableshellopen"></a><a name="enableshellopen"></a>CWinApp:: EnableShellOpen

Chame essa função, normalmente de sua `InitInstance` substituição, para permitir que os usuários do aplicativo abram arquivos de dados ao clicarem duas vezes nos arquivos de dentro do Gerenciador de arquivos do Windows.

```cpp
void EnableShellOpen();
```

### <a name="remarks"></a>Comentários

Chame a `RegisterShellFileTypes` função de membro em conjunto com essa função ou forneça um. REG arquivo com seu aplicativo para o registro manual de tipos de documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#38](../../mfc/reference/codesnippet/cpp/cwinapp-class_4.cpp)]

## <a name="cwinappenabletaskbarinteraction"></a><a name="enabletaskbarinteraction"></a>CWinApp:: EnableTaskbarInteraction

Habilita a interação da barra de tarefas.

```
BOOL EnableTaskbarInteraction(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>parâmetros

*bEnable*<br/>
Especifica se a interação com a barra de tarefas do Windows 7 deve ser habilitada (TRUE) ou desabilitada (FALSE).

### <a name="return-value"></a>Valor retornado

Retornará TRUE se a interação da barra de tarefas puder ser habilitada ou desabilitada.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado antes da criação da janela principal, caso contrário, ele é declarado e retorna FALSE.

## <a name="cwinappexitinstance"></a><a name="exitinstance"></a>CWinApp:: ExitInstance

Chamado pelo Framework de dentro da `Run` função de membro para sair desta instância do aplicativo.

```
virtual int ExitInstance();
```

### <a name="return-value"></a>Valor retornado

O código de saída do aplicativo; 0 indica que não há erros e valores maiores que 0 indicam um erro. Esse valor é usado como o valor de retorno de `WinMain` .

### <a name="remarks"></a>Comentários

Não chame essa função de membro de qualquer lugar, mas dentro da `Run` função de membro.

A implementação padrão dessa função grava as opções de estrutura para o aplicativo. Arquivo INI. Substitua essa função para limpar quando o aplicativo for encerrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#39](../../mfc/reference/codesnippet/cpp/cwinapp-class_5.cpp)]

## <a name="cwinappgetapplicationrecoveryparameter"></a><a name="getapplicationrecoveryparameter"></a>CWinApp:: GetApplicationRecoveryParameter

Recupera o parâmetro de entrada para o método de recuperação do aplicativo.

```
virtual LPVOID GetApplicationRecoveryParameter();
```

### <a name="return-value"></a>Valor retornado

O parâmetro de entrada padrão para o método de recuperação do aplicativo.

### <a name="remarks"></a>Comentários

O comportamento padrão dessa função retorna NULL.

Para obter mais informações, consulte [CWinApp:: ApplicationRecoveryCallback](#applicationrecoverycallback).

## <a name="cwinappgetapplicationrecoverypinginterval"></a><a name="getapplicationrecoverypinginterval"></a>CWinApp:: GetApplicationRecoveryPingInterval

Retorna o período de tempo que o Gerenciador de reinicialização aguarda para que a função de retorno de chamada de recuperação seja retornada.

```
virtual DWORD GetApplicationRecoveryPingInterval();
```

### <a name="return-value"></a>Valor retornado

O período de tempo em milissegundos.

### <a name="remarks"></a>Comentários

Quando um aplicativo registrado com o Gerenciador de reinicialização sai inesperadamente, o aplicativo tenta salvar documentos abertos e chama a função de retorno de chamada de recuperação. A função de retorno de chamada de recuperação padrão é [CWinApp:: ApplicationRecoveryCallback](#applicationrecoverycallback).

O período de tempo que a estrutura aguarda para a função de retorno de chamada de recuperação retornar é o intervalo de ping. Você pode personalizar o intervalo de ping substituindo `CWinApp::GetApplicationRecoveryPingInterval` ou fornecendo um valor personalizado para `RegisterWithRestartManager` .

## <a name="cwinappgetapplicationrestartflags"></a><a name="getapplicationrestartflags"></a>CWinApp:: GetApplicationRestartFlags

Retorna os sinalizadores para o Gerenciador de reinicialização.

```
virtual DWORD GetApplicationRestartFlags();
```

### <a name="return-value"></a>Valor retornado

Os sinalizadores para o Gerenciador de reinicialização. A implementação padrão retorna 0.

### <a name="remarks"></a>Comentários

Os sinalizadores para o Gerenciador de reinicialização não têm nenhum efeito com a implementação padrão. Eles são fornecidos para uso futuro.

Você define os sinalizadores ao registrar o aplicativo com o Gerenciador de reinicialização usando [CWinApp:: RegisterWithRestartManager](#registerwithrestartmanager).

Os valores possíveis para os sinalizadores do Gerenciador de reinicialização são os seguintes:

- RESTART_NO_CRASH

- RESTART_NO_HANG

- RESTART_NO_PATCH

- RESTART_NO_REBOOT

## <a name="cwinappgetappregistrykey"></a><a name="getappregistrykey"></a>CWinApp:: GetAppRegistryKey

Retorna a chave para HKEY_CURRENT_USER \\ "software" \RegistryKey\ProfileName.

```
HKEY GetAppRegistryKey(CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*pTM*<br/>
Ponteiro para um `CAtlTransactionManager` objeto.

### <a name="return-value"></a>Valor retornado

Chave do aplicativo se a função tiver sucesso; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cwinappgetdatarecoveryhandler"></a><a name="getdatarecoveryhandler"></a>CWinApp:: GetDataRecoveryHandler

Obtém o manipulador de recuperação de dados para esta instância do aplicativo.

```
virtual CDataRecoveryHandler *GetDataRecoveryHandler();
```

### <a name="return-value"></a>Valor retornado

O manipulador de recuperação de dados para esta instância do aplicativo.

### <a name="remarks"></a>Comentários

Cada aplicativo que usa o Gerenciador de reinicialização deve ter uma instância da [classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md). Essa classe é responsável por monitorar documentos abertos e salvar arquivos automaticamente. O comportamento do `CDataRecoveryHandler` depende da configuração do Gerenciador de reinicialização. Para obter mais informações, consulte [classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md).

Esse método retorna nulo em sistemas operacionais anteriores ao Windows Vista. Não há suporte para o Gerenciador de reinicialização em sistemas operacionais anteriores ao Windows Vista.

Se o aplicativo não tiver atualmente um manipulador de recuperação de dados, esse método criará um e retornará um ponteiro para ele.

## <a name="cwinappgetfirstdoctemplateposition"></a><a name="getfirstdoctemplateposition"></a>CWinApp:: GetFirstDocTemplatePosition

Obtém a posição do primeiro modelo de documento no aplicativo.

```
POSITION GetFirstDocTemplatePosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se a lista estiver vazia.

### <a name="remarks"></a>Comentários

Use o valor de posição retornado em uma chamada para [GetNextDocTemplate](#getnextdoctemplate) para obter o primeiro objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) .

## <a name="cwinappgethelpmode"></a><a name="gethelpmode"></a>CWinApp:: gethelpmode

Recupera o tipo de ajuda usado pelo aplicativo.

```
AFX_HELP_TYPE GetHelpMode();
```

### <a name="return-value"></a>Valor retornado

O tipo de ajuda usado pelo aplicativo. Consulte [CWinApp:: m_eHelpType](#m_ehelptype) para obter mais informações.

## <a name="cwinappgetnextdoctemplate"></a><a name="getnextdoctemplate"></a>CWinApp:: GetNextDocTemplate

Obtém o modelo de documento identificado pelo *PDV*e, em seguida, define *pos* como o valor da posição.

```
CDocTemplate* GetNextDocTemplate(POSITION& pos) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Uma referência a um valor de posição retornado por uma chamada anterior para `GetNextDocTemplate` ou [GetFirstDocTemplatePosition](#getfirstdoctemplateposition). O valor é atualizado para a próxima posição por essa chamada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) .

### <a name="remarks"></a>Comentários

Você pode usar `GetNextDocTemplate` em um loop de iteração progressiva se estabelecer a posição inicial com uma chamada para `GetFirstDocTemplatePosition` .

Você deve garantir que seu valor de posição seja válido. Se for inválido, a versão de depuração do biblioteca MFC afirma.

Se o modelo de documento recuperado for o último disponível, o novo valor de *pos* será definido como NULL.

## <a name="cwinappgetprinterdevicedefaults"></a><a name="getprinterdevicedefaults"></a>CWinApp:: GetPrinterDeviceDefaults

Chame essa função de membro para preparar um contexto de dispositivo de impressora para impressão.

```
BOOL GetPrinterDeviceDefaults(struct tagPDA* pPrintDlg);
```

### <a name="parameters"></a>parâmetros

*pPrintDlg*<br/>
Um ponteiro para uma estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) .

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Recupera os padrões de impressora atuais do Windows. INI, conforme necessário, ou usa a última configuração de impressora definida pelo usuário na configuração de impressão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#40](../../mfc/reference/codesnippet/cpp/cwinapp-class_6.cpp)]

## <a name="cwinappgetprofilebinary"></a><a name="getprofilebinary"></a>CWinApp:: GetProfileBinary

Chame essa função de membro para recuperar dados binários de uma entrada dentro de uma seção especificada do registro do aplicativo ou. Arquivo INI.

```
BOOL GetProfileBinary(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPBYTE* ppData,
    UINT* pBytes);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada.

*lpszEntry*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cujo valor deve ser recuperado.

*ppData*<br/>
Aponta para um ponteiro que receberá o endereço dos dados.

*pBytes*<br/>
Aponta para um UINT que receberá o tamanho dos dados (em bytes).

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro não diferencia maiúsculas de minúsculas e, portanto, as cadeias de caracteres nos parâmetros *lpszSection* e *lpszEntry* podem ser diferentes no caso.

> [!NOTE]
> `GetProfileBinary`aloca um buffer e retorna seu endereço em \* *ppData*. O chamador é responsável por liberar o buffer usando **delete []**.

> [!IMPORTANT]
> Os dados retornados por essa função não são necessariamente terminações nulas e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#41](../../mfc/reference/codesnippet/cpp/cwinapp-class_7.cpp)]

Para obter um exemplo adicional, consulte [CWinApp:: WriteProfileBinary](#writeprofilebinary).

## <a name="cwinappgetprofileint"></a><a name="getprofileint"></a>CWinApp:: GetProfileInt

Chame essa função de membro para recuperar o valor de um inteiro de uma entrada dentro de uma seção especificada do registro do aplicativo ou. Arquivo INI.

```
UINT GetProfileInt(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    int nDefault);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada.

*lpszEntry*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cujo valor deve ser recuperado.

*nDefault*<br/>
Especifica o valor padrão a ser retornado se a estrutura não conseguir localizar a entrada.

### <a name="return-value"></a>Valor retornado

O valor inteiro da cadeia de caracteres que segue a entrada especificada se a função for bem-sucedida. O valor de retorno é o valor do parâmetro *nDefault* se a função não encontrar a entrada. O valor de retorno será 0 se o valor que corresponde à entrada especificada não for um inteiro.

Essa função de membro dá suporte à notação hexadecimal para o valor no. Arquivo INI. Quando você recupera um inteiro assinado, você deve converter o valor em um **`int`** .

### <a name="remarks"></a>Comentários

Essa função de membro não diferencia maiúsculas de minúsculas e, portanto, as cadeias de caracteres nos parâmetros *lpszSection* e *lpszEntry* podem ser diferentes no caso.

> [!IMPORTANT]
> Os dados retornados por essa função não são necessariamente terminações nulas e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#42](../../mfc/reference/codesnippet/cpp/cwinapp-class_8.cpp)]

Para obter um exemplo adicional, consulte [CWinApp:: WriteProfileInt](#writeprofileint).

## <a name="cwinappgetprofilestring"></a><a name="getprofilestring"></a>CWinApp:: GetProfileString

Chame essa função de membro para recuperar a cadeia de caracteres associada a uma entrada dentro da seção especificada no registro do aplicativo ou. Arquivo INI.

```
CString GetProfileString(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPCTSTR lpszDefault = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada.

*lpszEntry*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cuja cadeia de caracteres deve ser recuperada. Esse valor não deve ser nulo.

*lpszDefault*<br/>
Aponta para o valor de cadeia de caracteres padrão para a entrada fornecida se a entrada não puder ser encontrada no arquivo de inicialização.

### <a name="return-value"></a>Valor retornado

O valor de retorno é a cadeia de caracteres do aplicativo. Arquivo INI ou *lpszDefault* se a cadeia de caracteres não puder ser encontrada. O comprimento máximo de cadeia de caracteres suportado pelo Framework é _MAX_PATH. Se *lpszDefault* for NULL, o valor de retorno será uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
> Os dados retornados por essa função não são necessariamente terminações nulas e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]

Para obter outro exemplo, consulte o exemplo de [CWinApp:: GetProfileInt](#getprofileint).

## <a name="cwinappgetsectionkey"></a><a name="getsectionkey"></a>CWinApp:: GetSectionKey

Retorna a chave para HKEY_CURRENT_USER \\ "software" \RegistryKey\AppName\lpszSection.

```
HKEY GetSectionKey(
    LPCTSTR lpszSection,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
O nome da chave a ser obtida.

*pTM*<br/>
Ponteiro para um `CAtlTransactionManager` objeto.

### <a name="return-value"></a>Valor retornado

Chave de seção se a função for realizada com sucesso; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cwinapphideapplication"></a><a name="hideapplication"></a>CWinApp:: HideApplication

Chame essa função de membro para ocultar um aplicativo antes de fechar os documentos abertos.

```cpp
void HideApplication();
```

## <a name="cwinapphtmlhelp"></a><a name="htmlhelp"></a>CWinApp:: HtmlHelp

Chame essa função de membro para invocar o aplicativo HTMLHelp.

```
virtual void HtmlHelp(
    DWORD_PTR dwData,
    UINT nCmd = 0x000F);
```

### <a name="parameters"></a>parâmetros

*dwData*<br/>
Especifica dados adicionais. O valor usado depende do valor do parâmetro *nCmd* . O padrão é `0x000F` o que significa [HH_HELP_CONTEXT](/previous-versions/windows/desktop/htmlhelp/hh-help-context-command).

*nCmd*<br/>
Especifica o tipo de ajuda solicitada. Para obter uma lista de valores possíveis e como eles afetam o parâmetro *dwData* , consulte o parâmetro *uCommand* descrito nas funções de API [HtmlHelpW](/windows/win32/api/htmlhelp/nf-htmlhelp-htmlhelpw) ou [htmlhelpa](/windows/win32/api/htmlhelp/nf-htmlhelp-htmlhelpa) na SDK do Windows.

### <a name="remarks"></a>Comentários

A estrutura também chama essa função para invocar o aplicativo HTMLHelp.

A estrutura fechará automaticamente o aplicativo HTMLHelp quando o aplicativo for encerrado.

## <a name="cwinappinitinstance"></a><a name="initinstance"></a>CWinApp:: InitInstance

O Windows permite que várias cópias do mesmo programa sejam executadas ao mesmo tempo.

```
virtual BOOL InitInstance();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a inicialização for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A inicialização do aplicativo é dividida conceitualmente em duas seções: inicialização de aplicativo única que é feita na primeira vez em que o programa é executado e inicialização de instância que é executada cada vez que uma cópia do programa é executada, incluindo a primeira vez. A implementação da estrutura de `WinMain` chama essa função.

Substitua `InitInstance` para inicializar cada nova instância do aplicativo em execução no Windows. Normalmente, você substitui o `InitInstance` para construir o objeto de janela principal e define o `CWinThread::m_pMainWnd` membro de dados para apontar para essa janela. Para obter mais informações sobre como substituir essa função de membro, consulte [CWinApp: a classe Application](../../mfc/cwinapp-the-application-class.md).

> [!NOTE]
> Os aplicativos MFC devem ser inicializados como STA (single-threaded apartment). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua `InitInstance` substituição, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCListView#9](../../atl/reference/codesnippet/cpp/cwinapp-class_10.cpp)]

## <a name="cwinappistaskbarinteractionenabled"></a><a name="istaskbarinteractionenabled"></a>CWinApp:: IsTaskbarInteractionEnabled

Informa se a interação da barra de tarefas do Windows 7 está habilitada.

```
virtual BOOL IsTaskbarInteractionEnabled();
```

### <a name="return-value"></a>Valor retornado

Retornará TRUE se `EnableTaskbarInteraction` tiver sido chamado e o sistema operacional for Windows 7 ou superior.

### <a name="remarks"></a>Comentários

Interação da barra de tarefas significa que o aplicativo MDI exibe o conteúdo de filhos MDI em miniaturas com guias separadas que aparecem quando o ponteiro do mouse está sobre o botão da barra de tarefas do aplicativo.

## <a name="cwinapploadcursor"></a><a name="loadcursor"></a>CWinApp:: LoadCursor

Carrega o recurso de cursor chamado por *lpszResourceName* ou especificado pelo *nIDResource* do arquivo executável atual.

```
HCURSOR LoadCursor(LPCTSTR lpszResourceName) const;  HCURSOR LoadCursor(UINT nIDResource) const;
```

### <a name="parameters"></a>parâmetros

*lpszResourceName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de cursor. Você pode usar um `CString` para este argumento.

*nIDResource*<br/>
ID do recurso de cursor. Para obter uma lista de recursos, consulte [LoadCursor](/windows/win32/api/winuser/nf-winuser-loadcursorw) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Um identificador para um cursor se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

`LoadCursor`carrega o cursor na memória somente se ele não tiver sido carregado anteriormente; caso contrário, ele recupera um identificador do recurso existente.

Use a função de membro [LoadStandardCursor](#loadstandardcursor) ou [LoadOEMCursor](#loadoemcursor) para acessar os cursores predefinidos do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#44](../../mfc/reference/codesnippet/cpp/cwinapp-class_11.cpp)]

## <a name="cwinapploadicon"></a><a name="loadicon"></a>CWinApp:: LoadIcon

Carrega o recurso de ícone nomeado por *lpszResourceName* ou especificado pelo *nIDResource* do arquivo executável.

```
HICON LoadIcon(LPCTSTR lpszResourceName) const;  HICON LoadIcon(UINT nIDResource) const;
```

### <a name="parameters"></a>parâmetros

*lpszResourceName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de ícone. Você também pode usar um `CString` para esse argumento.

*nIDResource*<br/>
Número de ID do recurso de ícone.

### <a name="return-value"></a>Valor retornado

Um identificador para um ícone se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

`LoadIcon`carrega o ícone somente se ele não tiver sido carregado anteriormente; caso contrário, ele recupera um identificador do recurso existente.

Você pode usar a função de membro [LoadStandardIcon](#loadstandardicon) ou [LoadOEMIcon](#loadoemicon) para acessar os ícones predefinidos do Windows.

> [!NOTE]
> Essa função de membro chama o [ícone LoadIcon](/windows/win32/api/winuser/nf-winuser-loadiconw)da função da API do Win32, que só pode carregar um ícone cujo tamanho esteja de acordo com os SM_CXICON e SM_CYICON valores de métrica do sistema.

## <a name="cwinapploadoemcursor"></a><a name="loadoemcursor"></a>CWinApp:: LoadOEMCursor

Carrega o recurso de cursor predefinido do Windows especificado por *nIDCursor*.

```
HCURSOR LoadOEMCursor(UINT nIDCursor) const;
```

### <a name="parameters"></a>parâmetros

*nIDCursor*<br/>
Um identificador de constante de manifesto **OCR_** que especifica um cursor do Windows predefinido. Você deve ter `#define OEMRESOURCE` antes `#include \<afxwin.h>` de obter acesso às constantes de **OCR_** no Windows. T.

### <a name="return-value"></a>Valor retornado

Um identificador para um cursor se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use a `LoadOEMCursor` função de membro ou [LoadStandardCursor](#loadstandardcursor) para acessar os cursores predefinidos do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#45](../../mfc/reference/codesnippet/cpp/cwinapp-class_12.h)]

[!code-cpp[NVC_MFCWindowing#46](../../mfc/reference/codesnippet/cpp/cwinapp-class_13.cpp)]

## <a name="cwinapploadoemicon"></a><a name="loadoemicon"></a>CWinApp:: LoadOEMIcon

Carrega o recurso de ícone predefinido do Windows especificado por *nIDIcon*.

```
HICON LoadOEMIcon(UINT nIDIcon) const;
```

### <a name="parameters"></a>parâmetros

*nIDIcon*<br/>
Um identificador de constante de manifesto **OIC_** que especifica um ícone predefinido do Windows. Você deve ter `#define OEMRESOURCE` antes `#include \<afxwin.h>` de acessar as constantes de **OIC_** no Windows. T.

### <a name="return-value"></a>Valor retornado

Um identificador para um ícone se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use a `LoadOEMIcon` função de membro ou [LoadStandardIcon](#loadstandardicon) para acessar os ícones predefinidos do Windows.

## <a name="cwinapploadstandardcursor"></a><a name="loadstandardcursor"></a>CWinApp:: LoadStandardCursor

Carrega o recurso de cursor predefinido do Windows que o *lpszCursorName* especifica.

```
HCURSOR LoadStandardCursor(LPCTSTR lpszCursorName) const;
```

### <a name="parameters"></a>parâmetros

*lpszCursorName*<br/>
Um identificador de constante de manifesto **IDC_** que especifica um cursor do Windows predefinido. Esses identificadores são definidos no WINDOWS. T. A lista a seguir mostra os possíveis valores predefinidos e significados para *lpszCursorName*:

- IDC_ARROW Cursor de seta padrão

- IDC_IBEAM cursor de inserção de texto padrão

- IDC_WAIT cursor de ampulheta usado quando o Windows executa uma tarefa demorada

- IDC_CROSS cursor de cruz para seleção

- IDC_UPARROW Seta que aponta diretamente para cima

- IDC_SIZE obsoleto e sem suporte; usar IDC_SIZEALL

- IDC_SIZEALL uma seta de quatro pontas. O cursor a ser usado para redimensionar uma janela.

- IDC_ICON obsoleto e sem suporte. Use IDC_ARROW.

- IDC_SIZENWSE seta de duas pontas com extremidades no canto superior esquerdo e inferior direito

- IDC_SIZENESW Seta de duas pontas com extremidades no canto superior direito e inferior esquerdo

- Seta de duas pontas horizontal IDC_SIZEWE

- Seta de duas pontas vertical IDC_SIZENS

### <a name="return-value"></a>Valor retornado

Um identificador para um cursor se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use a `LoadStandardCursor` função de membro ou [LoadOEMCursor](#loadoemcursor) para acessar os cursores predefinidos do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#47](../../mfc/reference/codesnippet/cpp/cwinapp-class_14.cpp)]

## <a name="cwinapploadstandardicon"></a><a name="loadstandardicon"></a>CWinApp:: LoadStandardIcon

Carrega o recurso de ícone predefinido do Windows que o *lpszIconName* especifica.

```
HICON LoadStandardIcon(LPCTSTR lpszIconName) const;
```

### <a name="parameters"></a>parâmetros

*lpszIconName*<br/>
Um identificador de constante de manifesto que especifica um ícone predefinido do Windows. Esses identificadores são definidos no WINDOWS. T. Para obter uma lista dos possíveis valores predefinidos e suas descrições, consulte o parâmetro *lpIconName* em [loadicon](/windows/win32/api/winuser/nf-winuser-loadiconw) na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Um identificador para um ícone se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use a `LoadStandardIcon` função de membro ou [LoadOEMIcon](#loadoemicon) para acessar os ícones predefinidos do Windows.

## <a name="cwinapploadstdprofilesettings"></a><a name="loadstdprofilesettings"></a>CWinApp:: LoadStdProfileSettings

Chame essa função de membro de dentro da função de membro [InitInstance](#initinstance) para habilitar e carregar a lista de arquivos MRU (usados mais recentemente) e o último estado de visualização.

```cpp
void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);
```

### <a name="parameters"></a>parâmetros

*nMaxMRU*<br/>
O número de arquivos usados recentemente a serem controlados.

### <a name="remarks"></a>Comentários

Se *nMaxMRU* for 0, nenhuma lista MRU será mantida.

## <a name="cwinappm_bhelpmode"></a><a name="m_bhelpmode"></a>CWinApp:: m_bHelpMode

TRUE se o aplicativo estiver no modo de contexto de ajuda (chamado em convenção com SHIFT + F1); caso contrário, FALSE.

```
BOOL m_bHelpMode;
```

### <a name="remarks"></a>Comentários

No modo de contexto da ajuda, o cursor se torna um ponto de interrogação e o usuário pode movê-lo sobre a tela. Examine esse sinalizador se desejar implementar um tratamento especial no modo de ajuda. `m_bHelpMode`é uma variável pública do tipo BOOL.

## <a name="cwinappm_dwrestartmanagersupportflags"></a><a name="m_dwrestartmanagersupportflags"></a>CWinApp:: m_dwRestartManagerSupportFlags

Sinalizadores que determinam a forma como o Gerenciador de reinicialização se comporta.

```
DWORD m_dwRestartManagerSupportFlags;
```

### <a name="remarks"></a>Comentários

Para habilitar o Gerenciador de reinicialização, defina `m_dwRestartManagerSupportFlags` para o comportamento desejado. A tabela a seguir mostra os sinalizadores que estão disponíveis.

|||
|-|-|
|Sinalizador|Descrição|
|AFX_RESTART_MANAGER_SUPPORT_RESTART|O aplicativo é registrado usando [CWinApp:: RegisterWithRestartManager](#registerwithrestartmanager). O Gerenciador de reinicialização é responsável por reiniciar o aplicativo se ele for encerrado inesperadamente.|
|-AFX_RESTART_MANAGER_SUPPORT_RECOVERY|O aplicativo é registrado com o Gerenciador de reinicialização e o Gerenciador de reinicialização chama a função de retorno de chamada de recuperação quando reinicia o aplicativo. A função de retorno de chamada de recuperação padrão é [CWinApp:: ApplicationRecoveryCallback](#applicationrecoverycallback).|
|-AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART|O salvamento automático está habilitado e o Gerenciador de reinicialização salva automaticamente todos os documentos abertos quando o aplicativo é reiniciado.|
|-AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL|O salvamento automático está habilitado e o Gerenciador de reinicialização salva automaticamente todos os documentos abertos em intervalos regulares. O intervalo é definido por [CWinApp:: m_nAutosaveInterval](#m_nautosaveinterval).|
|-AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES|O Gerenciador de reinicialização abre documentos abertos anteriormente depois de reiniciar o aplicativo de uma saída inesperada. A [classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md) lida com o armazenamento da lista de documentos abertos e sua restauração.|
|-AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES|O Gerenciador de reinicialização solicita que o usuário restaure arquivos salvos novamente após reiniciar o aplicativo. A `CDataRecoveryHandler` classe consulta o usuário.|
|-AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE|A União de AFX_RESTART_MANAGER_SUPPORT_RESTART, AFX_RESTART_MANAGER_SUPPORT_RECOVER e AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES.|
|-AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS|A União de AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART, AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL e AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES.|
|-AFX_RESTART_MANAGER_SUPPORT_RESTART_ASPECTS|A União de AFX_RESTART_MANAGER_SUPPORT_RESTART, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES e AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES.|
|-AFX_RESTART_MANAGER_SUPPORT_RECOVERY_ASPECTS|O ofAFX_RESTART_MANAGER_SUPPORT_RECOVERY de União, AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES e AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES.|

## <a name="cwinappm_ehelptype"></a><a name="m_ehelptype"></a>CWinApp:: m_eHelpType

O tipo desse membro de dados é o tipo enumerado AFX_HELP_TYPE, que é definido dentro da `CWinApp` classe.

```
AFX_HELP_TYPE m_eHelpType;
```

### <a name="remarks"></a>Comentários

A enumeração AFX_HELP_TYPE é definida da seguinte maneira:

```
enum AFX_HELP_TYPE {
    afxWinHelp = 0,
    afxHTMLHelp = 1
    };
```

- Para definir a ajuda do aplicativo como HTML, chame [SetHelpMode](#sethelpmode) e especifique `afxHTMLHelp` .

- Para definir a ajuda do aplicativo para o WinHelp, chame `SetHelpMode` e especifique `afxWinHelp` .

## <a name="cwinappm_hinstance"></a><a name="m_hinstance"></a>CWinApp:: m_hInstance

Corresponde ao parâmetro *HINSTANCE* passado pelo Windows para `WinMain` .

```
HINSTANCE m_hInstance;
```

### <a name="remarks"></a>Comentários

O `m_hInstance` membro de dados é um identificador para a instância atual do aplicativo em execução no Windows. Isso é retornado pela função global [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle). `m_hInstance`é uma variável pública do tipo HINSTANCE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#55](../../mfc/reference/codesnippet/cpp/cwinapp-class_15.cpp)]

## <a name="cwinappm_lpcmdline"></a><a name="m_lpcmdline"></a>CWinApp:: m_lpCmdLine

Corresponde ao parâmetro *lpCmdLine* passado pelo Windows para `WinMain` .

```
LPTSTR m_lpCmdLine;
```

### <a name="remarks"></a>Comentários

Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo. Use `m_lpCmdLine` para acessar qualquer argumento de linha de comando que o usuário inseriu quando o aplicativo foi iniciado. `m_lpCmdLine`é uma variável pública do tipo LPTSTR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#52](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]

## <a name="cwinappm_nautosaveinterval"></a><a name="m_nautosaveinterval"></a>CWinApp:: m_nAutosaveInterval

O período de tempo em milissegundos entre os salvamentos autosalvos.

```
int m_nAutosaveInterval;
```

### <a name="remarks"></a>Comentários

Você pode configurar o Gerenciador de reinicialização para salvar documentos automaticamente em intervalos definidos. Se o seu aplicativo não salvar arquivos automaticamente, esse parâmetro não terá nenhum efeito.

## <a name="cwinappm_ncmdshow"></a><a name="m_ncmdshow"></a>CWinApp:: m_nCmdShow

Corresponde ao parâmetro *nCmdShow* passado pelo Windows para `WinMain` .

```
int m_nCmdShow;
```

### <a name="remarks"></a>Comentários

Você deve passar `m_nCmdShow` como um argumento ao chamar [CWnd:: sawindow](../../mfc/reference/cwnd-class.md#showwindow) para a janela principal do seu aplicativo. `m_nCmdShow`é uma variável pública do tipo **`int`** .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#56](../../mfc/reference/codesnippet/cpp/cwinapp-class_17.cpp)]

## <a name="cwinappm_pactivewnd"></a><a name="m_pactivewnd"></a>CWinApp:: m_pActiveWnd

Use este membro de dados para armazenar um ponteiro para a janela principal do aplicativo de contêiner OLE que tem o aplicativo de servidor OLE ativado no local.

### <a name="remarks"></a>Comentários

Se esse membro de dados for nulo, o aplicativo não será ativo no local.

A estrutura define essa variável de membro quando a janela do quadro está no local ativada por um aplicativo de contêiner OLE.

## <a name="cwinappm_pdatarecoveryhandler"></a><a name="m_pdatarecoveryhandler"></a>CWinApp:: m_pDataRecoveryHandler

Ponteiro para o manipulador de recuperação de dados do aplicativo.

```
CDataRecoveryHandler* m_pDataRecoveryHandler;
```

### <a name="remarks"></a>Comentários

O manipulador de recuperação de dados de um aplicativo monitora documentos abertos e os salva. A estrutura usa o manipulador de recuperação de dados para restaurar arquivos salvos novamente quando um aplicativo é reiniciado após ele sair inesperadamente. Para obter mais informações, consulte [classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md).

## <a name="cwinappm_pszappname"></a><a name="m_pszappname"></a>CWinApp:: m_pszAppName

Especifica o nome do aplicativo.

```
LPCTSTR m_pszAppName;
```

### <a name="remarks"></a>Comentários

O nome do aplicativo pode vir do parâmetro passado para o construtor [CWinApp](#cwinapp) ou, se não for especificado, para a cadeia de caracteres de recurso com a ID de AFX_IDS_APP_TITLE. Se o nome do aplicativo não for encontrado no recurso, ele virá do programa. Nome do arquivo EXE.

Retornado pela função global [AfxGetAppName](application-information-and-management.md#afxgetappname). `m_pszAppName`é uma variável pública do tipo **const char** <strong>\*</strong> .

> [!NOTE]
> Se você atribuir um valor a `m_pszAppName` , ele deverá ser alocado dinamicamente no heap. O `CWinApp` destruidor chama **Free**() com esse ponteiro. Muitos querem usar a função de `_tcsdup` biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#57](../../mfc/reference/codesnippet/cpp/cwinapp-class_18.cpp)]

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#65](../../mfc/reference/codesnippet/cpp/cwinapp-class_19.cpp)]

## <a name="cwinappm_pszexename"></a><a name="m_pszexename"></a>CWinApp:: m_pszExeName

Contém o nome do arquivo executável do aplicativo sem uma extensão.

```
LPCTSTR m_pszExeName;
```

### <a name="remarks"></a>Comentários

Ao contrário de [m_pszAppName](#m_pszappname), esse nome não pode conter espaços em branco. `m_pszExeName`é uma variável pública do tipo **const char** <strong>\*</strong> .

> [!NOTE]
> Se você atribuir um valor a `m_pszExeName` , ele deverá ser alocado dinamicamente no heap. O `CWinApp` destruidor chama **Free**() com esse ponteiro. Muitos querem usar a função de `_tcsdup` biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#58](../../mfc/reference/codesnippet/cpp/cwinapp-class_20.cpp)]

## <a name="cwinappm_pszhelpfilepath"></a><a name="m_pszhelpfilepath"></a>CWinApp:: m_pszHelpFilePath

Contém o caminho para o arquivo de ajuda do aplicativo.

```
LPCTSTR m_pszHelpFilePath;
```

### <a name="remarks"></a>Comentários

Por padrão, a estrutura Inicializa `m_pszHelpFilePath` para o nome do aplicativo com ". HLP "acrescentado. Para alterar o nome do arquivo de ajuda, defina `m_pszHelpFilePath` para apontar para uma cadeia de caracteres que contém o nome completo do arquivo de ajuda desejado. Um local conveniente para fazer isso é na função [InitInstance](#initinstance) do aplicativo. `m_pszHelpFilePath`é uma variável pública do tipo **const char** <strong>\*</strong> .

> [!NOTE]
> Se você atribuir um valor a `m_pszHelpFilePath` , ele deverá ser alocado dinamicamente no heap. O `CWinApp` destruidor chama **Free**() com esse ponteiro. Muitos querem usar a função de `_tcsdup` biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#59](../../mfc/reference/codesnippet/cpp/cwinapp-class_21.cpp)]

## <a name="cwinappm_pszprofilename"></a><a name="m_pszprofilename"></a>CWinApp:: m_pszProfileName

Contém o nome do aplicativo. Arquivo INI.

```
LPCTSTR m_pszProfileName;
```

### <a name="remarks"></a>Comentários

`m_pszProfileName`é uma variável pública do tipo **const char** <strong>\*</strong> .

> [!NOTE]
> Se você atribuir um valor a `m_pszProfileName` , ele deverá ser alocado dinamicamente no heap. O `CWinApp` destruidor chama **Free**() com esse ponteiro. Muitos querem usar a função de `_tcsdup` biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#60](../../mfc/reference/codesnippet/cpp/cwinapp-class_22.cpp)]

## <a name="cwinappm_pszregistrykey"></a><a name="m_pszregistrykey"></a>CWinApp:: m_pszRegistryKey

Usado para determinar onde, no arquivo de registro ou INI, as configurações de perfil de aplicativo são armazenadas.

```
LPCTSTR m_pszRegistryKey;
```

### <a name="remarks"></a>Comentários

Normalmente, esse membro de dados é tratado como somente leitura.

- O valor é armazenado em uma chave do registro. O nome da configuração do perfil de aplicativo é anexado à seguinte chave do registro: HKEY_CURRENT_USER/Software/LocalAppWizard-Generated/.

Se você atribuir um valor a `m_pszRegistryKey` , ele deverá ser alocado dinamicamente no heap. O `CWinApp` destruidor chama **Free**() com esse ponteiro. Muitos querem usar a função de `_tcsdup` biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#61](../../mfc/reference/codesnippet/cpp/cwinapp-class_23.cpp)]

## <a name="cwinappm_pszappid"></a><a name="m_pszappid"></a>CWinApp:: m_pszAppID

ID do modelo de usuário do aplicativo.

```
LPCTSTR m_pszAppID;
```

### <a name="remarks"></a>Comentários

## <a name="cwinapponcontexthelp"></a><a name="oncontexthelp"></a>CWinApp:: OnContextHelp

Manipula a ajuda do SHIFT + F1 dentro do aplicativo.

```
afx_msg void OnContextHelp();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_CONTEXT_HELP, OnContextHelp )` instrução ao seu `CWinApp` mapa de mensagens de classe e também adicionar uma entrada de tabela de acelerador, normalmente Shift + F1, para habilitar essa função de membro.

`OnContextHelp`coloca o aplicativo no modo de ajuda. O cursor muda para uma seta e um ponto de interrogação, e o usuário pode mover o ponteiro do mouse e pressionar o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Essa função de membro recupera o contexto de ajuda do objeto sob o cursor e chama o WinHelp da função do Windows com esse contexto de ajuda.

## <a name="cwinapponddecommand"></a><a name="onddecommand"></a>CWinApp:: OnDDECommand

Chamado pelo Framework quando a janela do quadro principal recebe uma mensagem de execução DDE.

```
virtual BOOL OnDDECommand(LPTSTR lpszCommand);
```

### <a name="parameters"></a>parâmetros

*lpszCommand*<br/>
Aponta para uma cadeia de caracteres de comando DDE recebida pelo aplicativo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o comando for manipulado; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão verifica se o comando é uma solicitação para abrir um documento e, em caso afirmativo, abre o documento especificado. O Gerenciador de arquivos do Windows geralmente envia essas cadeias de caracteres de comando DDE quando o usuário clica duas vezes em um arquivo de dados. Substitua essa função para lidar com outros comandos de execução DDE, como o comando a ser impresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#48](../../mfc/reference/codesnippet/cpp/cwinapp-class_24.cpp)]

## <a name="cwinapponfilenew"></a><a name="onfilenew"></a>CWinApp:: OnFileNew

Implementa o comando ID_FILE_NEW.

```
afx_msg void OnFileNew();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_FILE_NEW, OnFileNew )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. Se habilitada, essa função manipula a execução do comando arquivo novo.

Consulte a [Nota técnica 22](../../mfc/tn022-standard-commands-implementation.md) para obter informações sobre o comportamento padrão e diretrizes sobre como substituir essa função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]

[!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]

## <a name="cwinapponfileopen"></a><a name="onfileopen"></a>CWinApp:: OnFileOpen

Implementa o comando ID_FILE_OPEN.

```
afx_msg void OnFileOpen();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_FILE_OPEN, OnFileOpen )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. Se habilitada, essa função lida com a execução do comando File Open.

Para obter informações sobre o comportamento padrão e diretrizes sobre como substituir essa função de membro, consulte a [Nota técnica 22](../../mfc/tn022-standard-commands-implementation.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]

[!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]

## <a name="cwinapponfileprintsetup"></a><a name="onfileprintsetup"></a>CWinApp:: OnFilePrintSetup

Implementa o comando ID_FILE_PRINT_SETUP.

```
afx_msg void OnFilePrintSetup();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_FILE_PRINT_SETUP, OnFilePrintSetup )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. Se habilitada, essa função lida com a execução do comando File Print.

Para obter informações sobre o comportamento padrão e diretrizes sobre como substituir essa função de membro, consulte a [Nota técnica 22](../../mfc/tn022-standard-commands-implementation.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]

[!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]

## <a name="cwinapponhelp"></a><a name="onhelp"></a>CWinApp:: OnHelp

Manipula a ajuda F1 dentro do aplicativo (usando o contexto atual).

```
afx_msg void OnHelp();
```

### <a name="remarks"></a>Comentários

Normalmente, você também adicionará uma entrada de chave de acelerador para a tecla F1. A habilitação da tecla F1 é apenas uma convenção, não um requisito.

Você deve adicionar uma `ON_COMMAND( ID_HELP, OnHelp )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. Se habilitado, chamado pelo Framework quando o usuário pressiona a tecla F1.

A implementação padrão dessa função de manipulador de mensagens determina o contexto de ajuda que corresponde à janela atual, caixa de diálogo ou item de menu e, em seguida, chama WINHELP.EXE. Se nenhum contexto estiver disponível no momento, a função usará o contexto padrão.

Substitua essa função de membro para definir o contexto de ajuda para algo diferente da janela, caixa de diálogo, item de menu ou botão da barra de ferramentas que tem o foco no momento. Chame `WinHelp` com a ID de contexto de ajuda desejada.

## <a name="cwinapponhelpfinder"></a><a name="onhelpfinder"></a>CWinApp:: OnHelpFinder

Manipula os comandos ID_HELP_FINDER e ID_DEFAULT_HELP.

```
afx_msg void OnHelpFinder();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_HELP_FINDER, OnHelpFinder )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. Se habilitada, a estrutura chamará essa função de manipulador de mensagens quando o usuário do seu aplicativo selecionar o comando do localizador da ajuda para invocar `WinHelp` com o tópico de **HELP_FINDER** padrão.

## <a name="cwinapponhelpindex"></a><a name="onhelpindex"></a>CWinApp:: OnHelpIndex

Manipula o comando ID_HELP_INDEX e fornece um tópico de ajuda padrão.

```
afx_msg void OnHelpIndex();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_HELP_INDEX, OnHelpIndex )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. Se habilitada, a estrutura chama essa função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando de índice da ajuda para invocar `WinHelp` com o tópico de **HELP_INDEX** padrão.

## <a name="cwinapponhelpusing"></a><a name="onhelpusing"></a>CWinApp:: OnHelpUsing

Manipula o comando ID_HELP_USING.

```
afx_msg void OnHelpUsing();
```

### <a name="remarks"></a>Comentários

Você deve adicionar uma `ON_COMMAND( ID_HELP_USING, OnHelpUsing )` instrução ao `CWinApp` mapa de mensagens de classe para habilitar essa função de membro. A estrutura chama essa função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando help using para invocar o `WinHelp` aplicativo com o tópico de **HELP_HELPONHELP** padrão.

## <a name="cwinapponidle"></a><a name="onidle"></a>CWinApp:: OnIdle

Substitua essa função de membro para executar o processamento em tempo ocioso.

```
virtual BOOL OnIdle(LONG lCount);
```

### <a name="parameters"></a>parâmetros

*lCount*<br/>
Um contador incrementado A cada vez `OnIdle` é chamado quando a fila de mensagens do aplicativo está vazia. Essa contagem é redefinida como 0 sempre que uma nova mensagem é processada. Você pode usar o parâmetro *lCount* para determinar o período de tempo relativo que o aplicativo esteve ocioso sem processar uma mensagem.

### <a name="return-value"></a>Valor retornado

Diferente de zero para receber mais tempo de processamento ocioso; 0 se não for necessário mais tempo ocioso.

### <a name="remarks"></a>Comentários

`OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do aplicativo está vazia. Use sua substituição para chamar suas próprias tarefas de manipulador ocioso de segundo plano.

`OnIdle`deve retornar 0 para indicar que nenhum tempo de processamento ocioso é necessário. O parâmetro *lCount* é incrementado cada vez `OnIdle` que é chamado quando a fila de mensagens está vazia e é redefinido como 0 sempre que uma nova mensagem é processada. Você pode chamar suas diferentes rotinas ociosas com base nessa contagem.

O seguinte resume o processamento de loops ociosos:

1. Se o loop de mensagem no biblioteca MFC verificar a fila de mensagens e não encontrar mensagens pendentes, ele chamará `OnIdle` o objeto de aplicativo e fornecerá 0 como o argumento *lCount* .

2. `OnIdle`executa algum processamento e retorna um valor diferente de zero para indicar que ele deve ser chamado novamente para realizar o processamento adicional.

3. O loop de mensagem verifica a fila de mensagens novamente. Se nenhuma mensagem estiver pendente, ela chamará `OnIdle` novamente, incrementando o argumento *lCount* .

4. Eventualmente, `OnIdle` termina o processamento de todas as suas tarefas ociosas e retorna 0. Isso informa ao loop de mensagem para parar de chamar `OnIdle` até que a próxima mensagem seja recebida da fila de mensagens; nesse ponto, o ciclo de ociosidade é reiniciado com o argumento definido como 0.

Não execute tarefas demoradas durante `OnIdle` o porque seu aplicativo não pode processar a entrada do usuário até `OnIdle` retornar.

> [!NOTE]
> A implementação padrão dos `OnIdle` objetos de interface do usuário do comando de atualizações, como itens de menu e botões da barra de ferramentas, e executa a limpeza da estrutura de dados interna. Portanto, se você substituir `OnIdle` , deverá chamar `CWinApp::OnIdle` com o `lCount` em sua versão substituída. Primeiro, chame todo o processamento ocioso de classe base (ou seja, até que a classe base `OnIdle` retorne 0). Se você precisar executar o trabalho antes que o processamento da classe base seja concluído, examine a implementação da classe base para selecionar o *lCount* apropriado durante o qual fazer seu trabalho.

Se você não quiser `OnIdle` ser chamado sempre que uma mensagem for recuperada da fila de mensagens, você poderá substituir o [CWinThreadIsIdleMessage](../../mfc/reference/cwinthread-class.md#isidlemessage). Se um aplicativo tiver definido um temporizador muito curto ou se o sistema estiver enviando a mensagem de WM_SYSTIMER, `OnIdle` será chamado repetidamente e degradará o desempenho.

### <a name="example"></a>Exemplo

Os dois exemplos a seguir mostram como usar `OnIdle` . O primeiro exemplo processa duas tarefas ociosas usando o argumento *lCount* para priorizar as tarefas. A primeira tarefa é de prioridade alta e você deve fazer isso sempre que possível. A segunda tarefa é menos importante e deve ser feita somente quando há uma longa pausa na entrada do usuário. Observe a chamada para a versão de classe base do `OnIdle` . O segundo exemplo gerencia um grupo de tarefas ociosas com prioridades diferentes.

[!code-cpp[NVC_MFCWindowing#51](../../mfc/reference/codesnippet/cpp/cwinapp-class_27.cpp)]

## <a name="cwinappopendocumentfile"></a><a name="opendocumentfile"></a>CWinApp:: OpenDocumentfile

A estrutura chama esse método para abrir o arquivo [CDocument](../../mfc/reference/cdocument-class.md) nomeado para o aplicativo.

```
virtual CDocument* OpenDocumentFile(
    LPCTSTR lpszFileName
    BOOL bAddToMRU = TRUE);
```

### <a name="parameters"></a>parâmetros

*lpszFileName*<br/>
no O nome do arquivo a ser aberto.

*bAddToMRU*<br/>
no VERDADEIRO indica que o documento é um dos arquivos mais recentes; FALSE indica que o documento não é um dos arquivos mais recentes.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `CDocument` se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um documento com esse nome já estiver aberto, a primeira janela do quadro que contém esse documento terá o foco. Se um aplicativo oferecer suporte a vários modelos de documento, a estrutura usará a extensão de nome de arquivo para localizar o modelo de documento apropriado para tentar carregar o documento. Se for bem-sucedido, o modelo de documento criará uma janela de quadro e exibirá o documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#52](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]

## <a name="cwinappparsecommandline"></a><a name="parsecommandline"></a>CWinApp::P arseCommandLine

Chame essa função de membro para analisar a linha de comando e enviar os parâmetros, um de cada vez, para [CCommandLineInfo::P arseparam](../../mfc/reference/ccommandlineinfo-class.md#parseparam).

```cpp
void ParseCommandLine(CCommandLineInfo& rCmdInfo);
```

### <a name="parameters"></a>parâmetros

*rCmdInfo*<br/>
Uma referência a um objeto [CCommandLineInfo](../../mfc/reference/ccommandlineinfo-class.md) .

### <a name="remarks"></a>Comentários

Quando você inicia um novo projeto MFC usando o assistente de aplicativo, o assistente de aplicativo criará uma instância local do `CCommandLineInfo` e, em seguida, chamará `ProcessShellCommand` e `ParseCommandLine` na função de membro [InitInstance](#initinstance) . Uma linha de comando segue a rota descrita abaixo:

1. Depois de ser criado no `InitInstance` , o `CCommandLineInfo` objeto é passado para `ParseCommandLine` .

2. `ParseCommandLine`em seguida `CCommandLineInfo::ParseParam` , o chama repetidamente, uma vez para cada parâmetro.

3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é passado para [ProcessShellCommand](#processshellcommand).

4. `ProcessShellCommand`manipula os argumentos de linha de comando e os sinalizadores.

Observe que você pode chamar `ParseCommandLine` diretamente conforme necessário.

Para obter uma descrição dos sinalizadores de linha de comando, consulte [CCommandLineInfo:: m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand).

## <a name="cwinapppretranslatemessage"></a><a name="pretranslatemessage"></a>CWinApp::P reTranslateMessage

Substitua essa função para filtrar as mensagens de janela antes que elas sejam expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) a implementação padrão executa a conversão de teclas de aceleração, portanto, você deve chamar a `CWinApp::PreTranslateMessage` função de membro na sua versão substituída.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>parâmetros

*pMsg*<br/>
Um ponteiro para uma estrutura de [msg](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser processada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem foi totalmente processada em `PreTranslateMessage` e não deve ser processada ainda mais. Zero se a mensagem deve ser processada da maneira normal.

## <a name="cwinappprocessmessagefilter"></a><a name="processmessagefilter"></a>CWinApp::P rocessMessageFilter

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
Um ponteiro para um trutura de [msg](/windows/win32/api/winuser/ns-winuser-msg)do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem for processada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma função de Hook processa eventos antes que eles sejam enviados para o processamento de mensagem normal do aplicativo.

Se você substituir esse recurso avançado, certifique-se de chamar a versão de classe base para manter o processamento de gancho da estrutura.

## <a name="cwinappprocessshellcommand"></a><a name="processshellcommand"></a>CWinApp::P rocessShellCommand

Essa função de membro é chamada por [InitInstance](#initinstance) para aceitar os parâmetros passados do `CCommandLineInfo` objeto identificado por *rCmdInfo*e executar a ação indicada.

```
BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);
```

### <a name="parameters"></a>parâmetros

*rCmdInfo*<br/>
Uma referência a um objeto [CCommandLineInfo](../../mfc/reference/ccommandlineinfo-class.md) .

### <a name="return-value"></a>Valor retornado

Diferente de zero se o comando do Shell for processado com êxito. Se for 0, retornará FALSE de [InitInstance](#initinstance).

### <a name="remarks"></a>Comentários

Quando você inicia um novo projeto MFC usando o assistente de aplicativo, o assistente de aplicativo cria uma instância local do `CCommandLineInfo` e, em seguida, chama `ProcessShellCommand` e [ParseCommandLine](#parsecommandline) na `InitInstance` função membro. Uma linha de comando segue a rota descrita abaixo:

1. Depois de ser criado no `InitInstance` , o `CCommandLineInfo` objeto é passado para `ParseCommandLine` .

2. `ParseCommandLine`em seguida, chama [CCommandLineInfo::P arseparam](../../mfc/reference/ccommandlineinfo-class.md#parseparam) repetidamente, uma vez para cada parâmetro.

3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é passado para `ProcessShellCommand` .

4. `ProcessShellCommand`manipula os argumentos de linha de comando e os sinalizadores.

Os membros de dados do `CCommandLineInfo` objeto, identificados por [CCommandLineInfo:: m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand), são do seguinte tipo enumerado, que é definido dentro da `CCommandLineInfo` classe.

```
enum {
    FileNew,
    FileOpen,
    FilePrint,
    FilePrintTo,
    FileDDE
    };
```

Para obter uma breve descrição de cada um desses valores, consulte `CCommandLineInfo::m_nShellCommand` .

## <a name="cwinappprocesswndprocexception"></a><a name="processwndprocexception"></a>CWinApp::P rocessWndProcException

A estrutura chama essa função de membro sempre que o manipulador não captura uma exceção lançada em um dos manipuladores de comando ou de mensagem do seu aplicativo.

```
virtual LRESULT ProcessWndProcException(
    CException* e,
    const MSG* pMsg);
```

### <a name="parameters"></a>parâmetros

*Oriental*<br/>
Um ponteiro para uma exceção não percebida.

*pMsg*<br/>
Uma [msg](/windows/win32/api/winuser/ns-winuser-msg)trutura que contém informações sobre a mensagem do Windows que fez com que a estrutura lançasse uma exceção.

### <a name="return-value"></a>Valor retornado

O valor que deve ser retornado para o Windows. Normalmente, isso é 0L para mensagens do Windows, 1L (TRUE) para mensagens de comando.

### <a name="remarks"></a>Comentários

Não chame essa função de membro diretamente.

A implementação padrão dessa função de membro cria uma caixa de mensagem. Se a exceção não detectada se originar em uma falha de comando de menu, barra de ferramentas ou acelerador, a caixa de mensagem exibirá uma mensagem de "falha no comando"; caso contrário, ele exibirá uma mensagem "erro interno do aplicativo".

Substitua essa função de membro para fornecer manipulação global de suas exceções. Só chame a funcionalidade base se desejar que a caixa de mensagem seja exibida.

## <a name="cwinappregister"></a><a name="register"></a>CWinApp:: Register

Executa qualquer tarefa de registro não tratada pelo `RegisterShellFileTypes` .

```
virtual BOOL Register();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão simplesmente retorna TRUE. Substitua essa função para fornecer quaisquer etapas de registro personalizadas.

## <a name="cwinappregistershellfiletypes"></a><a name="registershellfiletypes"></a>CWinApp:: RegisterShellFileTypes

Chame essa função de membro para registrar todos os tipos de documento do seu aplicativo com o Gerenciador de arquivos do Windows.

```cpp
void RegisterShellFileTypes(BOOL bCompat = FALSE);
```

### <a name="parameters"></a>parâmetros

*bCompat*<br/>
no VERDADEIRO adiciona entradas de registro para comandos do Shell imprimir e imprimir no, permitindo que um usuário imprima arquivos diretamente do Shell ou arrastando o arquivo para um objeto de impressora. Ele também adiciona uma tecla DefaultIcon. Por padrão, esse parâmetro é FALSE para compatibilidade com versões anteriores.

### <a name="remarks"></a>Comentários

Isso permite que o usuário abra um arquivo de dados criado pelo seu aplicativo clicando duas vezes nele no Gerenciador de arquivos. Chame `RegisterShellFileTypes` depois de chamar [AddDocTemplate](#adddoctemplate) para cada um dos modelos de documento em seu aplicativo. Chame também a função de membro [EnableShellOpen](#enableshellopen) quando você chamar `RegisterShellFileTypes` .

`RegisterShellFileTypes`itera na lista de objetos [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) que o aplicativo mantém e, para cada modelo de documento, adiciona entradas ao banco de dados de registro que o Windows mantém para as associações de arquivo. O Gerenciador de arquivos usa essas entradas para abrir um arquivo de dados quando o usuário clica duas vezes nele. Isso elimina a necessidade de enviar um. REG arquivo com seu aplicativo.

> [!NOTE]
> `RegisterShellFileTypes`funcionará somente se o usuário executar o programa com direitos de administrador. Se o programa não tiver direitos de administrador, ele não poderá alterar as chaves do registro.

Se o banco de dados de registro já associar uma determinada extensão de nome de arquivo a outro tipo, nenhuma nova associação será criada. Consulte a `CDocTemplate` classe para o formato de cadeias de caracteres necessárias para registrar essas informações.

## <a name="cwinappregisterwithrestartmanager"></a><a name="registerwithrestartmanager"></a>CWinApp:: RegisterWithRestartManager

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
|*bRegisterRecoveryCallback*|no VERDADEIRO indica que essa instância do aplicativo usa uma função de retorno de chamada de recuperação; FALSE indica que ele não faz isso. A estrutura chama a função de retorno de chamada de recuperação quando o aplicativo sai inesperadamente. Para obter mais informações, consulte [CWinApp:: ApplicationRecoveryCallback](#applicationrecoverycallback).|
|*strRestartIdentifier*|no A cadeia de caracteres exclusiva que identifica essa instância do Gerenciador de reinicialização. O identificador do Gerenciador de reinicialização é exclusivo para cada instância de um aplicativo.|
|*pwzCommandLineArgs*|no Uma cadeia de caracteres que contém argumentos extras da linha de comando.|
|*dwRestartFlags*|no Sinalizadores opcionais para o Gerenciador de reinicialização. Para obter mais informações, consulte a seção Comentários.|
|*pRecoveryCallback*|no A função de retorno de chamada de recuperação. Essa função deve usar um parâmetro LPVOID como entrada e retornar um DWORD. A função de retorno de chamada de recuperação padrão é `CWinApp::ApplicationRecoveryCallback` .|
|*lpvParam*|no O parâmetro de entrada para a função de retorno de chamada de recuperação. Para obter mais informações, consulte [CWinApp:: ApplicationRecoveryCallback](#applicationrecoverycallback).|
|*dwPingInterval*|no O período de tempo que o Gerenciador de reinicialização aguarda pela função de retorno de chamada de recuperação retornar. Esse parâmetro está em milissegundos.|
|*dwCallbackFlags*|no Sinalizadores passados para a função de retorno de chamada de recuperação. Reservado para uso futuro.|

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem-sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

Se seu aplicativo usar a implementação padrão do MFC para salvar arquivos automaticamente, você deverá usar a versão simples do `RegisterWithRestartManager` . Use a versão complexa do `RegisterWithRestartManager` se você quiser personalizar o comportamento de salvamento automático do seu aplicativo.

Se você chamar esse método com uma cadeia de caracteres vazia para *strRestartIdentifier*, o `RegisterWithRestartManager` criará uma cadeia de caracteres de identificador exclusivo para essa instância do Gerenciador de reinicialização.

Quando um aplicativo sai inesperadamente, o Gerenciador de reinicialização reinicia o aplicativo da linha de comando e fornece o identificador exclusivo de reinicialização como um argumento opcional. Nesse cenário, a estrutura chama `RegisterWithRestartManager` duas vezes. A primeira chamada vem de [CWinApp:: InitInstance](#initinstance) com uma cadeia de caracteres vazia para o identificador da cadeia de caracteres. Em seguida, o método [CWinApp::P rocessshellcommand](#processshellcommand) chama `RegisterWithRestartManager` com o identificador de reinicialização exclusivo.

Depois de registrar um aplicativo com o Gerenciador de reinicialização, o Gerenciador de reinicialização monitora o aplicativo. Se o aplicativo sair inesperadamente, o Gerenciador de reinicialização chamará a função de retorno de chamada de recuperação durante o processo de desligamento. O Gerenciador de reinicialização aguarda o *dwPingInterval* para uma resposta da função de retorno de chamada de recuperação. Se a função de retorno de chamada de recuperação não responder dentro desse tempo, o aplicativo será encerrado sem executar a função de retorno de chamada de recuperação.

Por padrão, os dwRestartFlags não têm suporte, mas são fornecidos para uso futuro. Os valores possíveis para *dwRestartFlags* são os seguintes:

- RESTART_NO_CRASH

- RESTART_NO_HANG

- RESTART_NO_PATCH

- RESTART_NO_REBOOT

## <a name="cwinappreopenpreviousfilesatrestart"></a><a name="reopenpreviousfilesatrestart"></a>CWinApp:: ReopenPreviousFilesAtRestart

Determina se o Gerenciador de reinicialização reabrirá os arquivos que estavam abertos quando o aplicativo foi encerrado inesperadamente.

```
virtual BOOL ReopenPreviousFilesAtRestart() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o Gerenciador de reinicialização reabrirá os arquivos abertos anteriormente; FALSO indica que o Gerenciador de reinicialização não faz isso.

## <a name="cwinapprestartinstance"></a><a name="restartinstance"></a>CWinApp:: RestartInstance

Manipula uma reinicialização do aplicativo iniciada pelo Gerenciador de reinicialização.

```
virtual BOOL CWinApp::RestartInstance();
```

### <a name="return-value"></a>Valor retornado

TRUE se o manipulador de recuperação de dados abrir documentos abertos anteriormente; FALSE se o manipulador de recuperação de dados tiver um erro ou se não houver nenhum documento aberto anteriormente.

### <a name="remarks"></a>Comentários

Quando o Restart Manager reinicia um aplicativo, a estrutura chama esse método. Esse método recupera o manipulador de recuperação de dados e restaura os arquivos salvos novamente. Esse método chama [CDataRecoveryHandler:: RestoreAutosavedDocuments](../../mfc/reference/cdatarecoveryhandler-class.md#restoreautosaveddocuments) para determinar se o usuário deseja restaurar os arquivos salvos novamente.

Esse método retornará FALSE se o [CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md) determinar que não havia nenhum documento aberto. Se não houver nenhum documento aberto, o aplicativo será iniciado normalmente.

## <a name="cwinapprestoreautosavedfilesatrestart"></a><a name="restoreautosavedfilesatrestart"></a>CWinApp:: RestoreAutosavedFilesAtRestart

Determina se o Gerenciador de reinicialização restaura os arquivos salvos novamente quando reinicia o aplicativo.

```
virtual BOOL RestoreAutosavedFilesAtRestart() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o Gerenciador de reinicialização restaura arquivos salvos novamente; FALSO indica que o Gerenciador de reinicialização não faz isso.

## <a name="cwinapprun"></a><a name="run"></a>CWinApp:: Run

Fornece um loop de mensagem padrão.

```
virtual int Run();
```

### <a name="return-value"></a>Valor retornado

Um **`int`** valor que é retornado por `WinMain` .

### <a name="remarks"></a>Comentários

`Run`adquire e envia mensagens do Windows até que o aplicativo receba uma mensagem de WM_QUIT. Se a fila de mensagens do aplicativo não contiver mensagens no momento, o `Run` chamará [OnIdle](#onidle) para executar o processamento em tempo ocioso. Mensagens de entrada acessam a função membro [PreTranslateMessage](#pretranslatemessage) para processamento especial e, em seguida, para a função do Windows `TranslateMessage` para tradução de teclado padrão; por fim, a `DispatchMessage` função do Windows é chamada.

`Run`raramente é substituído, mas você pode substituí-lo para fornecer um comportamento especial.

## <a name="cwinapprunautomated"></a><a name="runautomated"></a>CWinApp:: RunAutomated

Chame essa função para determinar se a opção " **/Automation**" ou " **-Automation**" está presente, que indica se o aplicativo de servidor foi iniciado por um aplicativo cliente.

```
BOOL RunAutomated();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a opção foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se estiver presente, a opção será removida da linha de comando. Para obter mais informações sobre a automação OLE, consulte o artigo [servidores de automação](../../mfc/automation-servers.md).

## <a name="cwinapprunembedded"></a><a name="runembedded"></a>CWinApp:: RunEmbedded

Chame essa função para determinar se a opção " **/Embedding**" ou " **-incorporando**" está presente, que indica se o aplicativo de servidor foi iniciado por um aplicativo cliente.

```
BOOL RunEmbedded();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a opção foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se estiver presente, a opção será removida da linha de comando. Para obter mais informações sobre inserção, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md).

## <a name="cwinappsaveallmodified"></a><a name="saveallmodified"></a>CWinApp:: SaveAllModified

Chamado pelo Framework para salvar todos os documentos quando a janela do quadro principal do aplicativo é fechada, ou por meio de uma mensagem de WM_QUERYENDSESSION.

```
virtual BOOL SaveAllModified();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for seguro para encerrar o aplicativo; 0 se não for seguro encerrar o aplicativo.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função de membro chama a função de membro [CDocument:: SaveModified](../../mfc/reference/cdocument-class.md#savemodified) , por sua vez, para todos os documentos modificados dentro do aplicativo.

## <a name="cwinappselectprinter"></a><a name="selectprinter"></a>CWinApp:: SelectPrinter

Chame essa função de membro para selecionar uma impressora específica e solte a impressora que foi selecionada anteriormente na caixa de diálogo Imprimir.

```cpp
void SelectPrinter(
    HANDLE hDevNames,
    HANDLE hDevMode,
    BOOL bFreeOld = TRUE);
```

### <a name="parameters"></a>parâmetros

*hDevNames*<br/>
Um identificador para um [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames)trutura que identifica o driver, o dispositivo e os nomes de porta de saída de uma impressora específica.

*hDevMode*<br/>
Um identificador para uma estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) que especifica informações sobre a inicialização do dispositivo e o ambiente de uma impressora.

*bFreeOld*<br/>
Libera a impressora selecionada anteriormente.

### <a name="remarks"></a>Comentários

Se *hDevMode* e *hDevNames* forem nulos, `SelectPrinter` o usará a impressora padrão atual.

## <a name="cwinappsethelpmode"></a><a name="sethelpmode"></a>CWinApp:: SetHelpMode

Define o tipo de ajuda do aplicativo.

```cpp
void SetHelpMode(AFX_HELP_TYPE eHelpType);
```

### <a name="parameters"></a>parâmetros

*eHelpType*<br/>
Especifica o tipo de ajuda a ser usado. Consulte [CWinApp:: m_eHelpType](#m_ehelptype) para obter mais informações.

### <a name="remarks"></a>Comentários

Define o tipo de ajuda do aplicativo.

Para definir o tipo de ajuda do aplicativo como HTMLHelp, você pode chamar [EnableHTMLHelp](#enablehtmlhelp). Depois de chamar `EnableHTMLHelp` , seu aplicativo deve usar HTMLHelp como seu aplicativo de ajuda. Se você quiser alterar para usar o WinHelp, poderá chamar `SetHelpMode` e definir *eHelpType* como `afxWinHelp` .

## <a name="cwinappsetregistrykey"></a><a name="setregistrykey"></a>CWinApp:: SetRegistryKey

Faz com que as configurações do aplicativo sejam armazenadas no registro em vez de arquivos INI.

```cpp
void SetRegistryKey(LPCTSTR lpszRegistryKey);
void SetRegistryKey(UINT nIDRegistryKey);
```

### <a name="parameters"></a>parâmetros

*lpszRegistryKey*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome da chave.

*nIDRegistryKey*<br/>
ID de um recurso de cadeia de caracteres que contém o nome da chave do registro.

### <a name="remarks"></a>Comentários

Essa função define *m_pszRegistryKey*, que é usada pelas `GetProfileInt` `GetProfileString` `WriteProfileInt` funções de membro,, e `WriteProfileString` do `CWinApp` . Se essa função tiver sido chamada, a lista de arquivos MRU (usados mais recentemente) também será armazenada no registro. A chave do registro geralmente é o nome de uma empresa. Ele é armazenado em uma chave do seguinte formato: HKEY_CURRENT_USER \Software \\<nome da empresa \> \\<nome do aplicativo \> \\<nome da seção<nome do \> \\ valor \> .

## <a name="cwinappsupportsapplicationrecovery"></a><a name="supportsapplicationrecovery"></a>CWinApp:: SupportsApplicationRecovery

Determina se o Gerenciador de reinicialização recupera um aplicativo que foi encerrado inesperadamente.

```
virtual BOOL SupportsApplicationRecovery() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o Gerenciador de reinicializações recupera o aplicativo; FALSO indica que o Gerenciador de reinicialização não faz isso.

## <a name="cwinappsupportsautosaveatinterval"></a><a name="supportsautosaveatinterval"></a>CWinApp:: SupportsAutosaveAtInterval

Determina se o Gerenciador de reinicialização salva novamente os documentos abertos em intervalos regulares.

```
virtual BOOL SupportsAutosaveAtInterval() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o Gerenciador de reinicialização salva novamente os documentos abertos; FALSO indica que o Gerenciador de reinicialização não faz isso.

## <a name="cwinappsupportsautosaveatrestart"></a><a name="supportsautosaveatrestart"></a>CWinApp:: SupportsAutosaveAtRestart

Determina se o Gerenciador de reinicialização salva o salvamento automática de todos os documentos abertos quando o aplicativo é reiniciado.

```
virtual BOOL SupportsAutosaveAtRestart() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o Gerenciador de reinicialização salva novamente os documentos abertos quando o aplicativo é reiniciado; FALSO indica que o Gerenciador de reinicialização não faz isso.

## <a name="cwinappsupportsrestartmanager"></a><a name="supportsrestartmanager"></a>CWinApp:: SupportsRestartManager

Determina se o aplicativo dá suporte ao Gerenciador de reinicialização.

```
virtual BOOL SupportsRestartManager() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o aplicativo dá suporte ao Gerenciador de reinicialização; FALSE indica que o aplicativo não.

## <a name="cwinappunregister"></a><a name="unregister"></a>CWinApp:: cancelar registro

Cancela o registro de todos os arquivos registrados pelo objeto de aplicativo.

```
virtual BOOL Unregister();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `Unregister` função desfaz o registro executado pelo objeto Application e a função [Register](#register) . Normalmente, ambas as funções são chamadas implicitamente pelo MFC e, portanto, não aparecerão no seu código.

Substitua essa função para executar etapas personalizadas de cancelamento de registro.

## <a name="cwinappunregistershellfiletypes"></a><a name="unregistershellfiletypes"></a>CWinApp:: UnregisterShellFileTypes

Chame essa função de membro para cancelar o registro de todos os tipos de documento do seu aplicativo com o Gerenciador de arquivos do Windows.

```cpp
void UnregisterShellFileTypes();
```

## <a name="cwinappwinhelp"></a><a name="winhelp"></a>CWinApp:: WinHelp

Chame essa função de membro para invocar o aplicativo WinHelp.

```
virtual void WinHelp(
    DWORD_PTR dwData,
    UINT nCmd = HELP_CONTEXT);
```

### <a name="parameters"></a>parâmetros

*dwData*<br/>
Especifica dados adicionais. O valor usado depende do valor do parâmetro *nCmd* .

*nCmd*<br/>
Especifica o tipo de ajuda solicitada. Para obter uma lista de valores possíveis e como eles afetam o parâmetro *dwData* , consulte a função [WinHelp](/windows/win32/api/winuser/nf-winuser-winhelpw) do Windows.

### <a name="remarks"></a>Comentários

A estrutura também chama essa função para invocar o aplicativo WinHelp.

A estrutura fechará automaticamente o aplicativo WinHelp quando o aplicativo for encerrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#53](../../mfc/reference/codesnippet/cpp/cwinapp-class_28.cpp)]

## <a name="cwinappwriteprofilebinary"></a><a name="writeprofilebinary"></a>CWinApp:: WriteProfileBinary

Chame essa função de membro para gravar dados binários na seção especificada do registro do aplicativo ou. Arquivo INI.

```
BOOL WriteProfileBinary(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPBYTE pData,
    UINT nBytes);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ela será criada. O nome da seção diferencia maiúsculas de minúsculas; a cadeia de caracteres pode ser qualquer combinação de letras maiúsculas e minúsculas.

*lpszEntry*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor deve ser gravado. Se a entrada não existir na seção especificada, ela será criada.

*pData*<br/>
Aponta para os dados a serem gravados.

*nBytes*<br/>
Contém o número de bytes a serem gravados.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

Este exemplo usa `CWinApp* pApp = AfxGetApp();` para obter a classe CWinApp que ilustra uma maneira que `WriteProfileBinary` `GetProfileBinary` pode ser usada em qualquer função em um aplicativo MFC.

[!code-cpp[NVC_MFCWindowing#54](../../mfc/reference/codesnippet/cpp/cwinapp-class_29.cpp)]

Para obter outro exemplo, consulte o exemplo de [CWinApp:: GetProfileBinary](#getprofilebinary).

## <a name="cwinappwriteprofileint"></a><a name="writeprofileint"></a>CWinApp:: WriteProfileInt

Chame essa função de membro para gravar o valor especificado na seção especificada do registro do aplicativo ou. Arquivo INI.

```
BOOL WriteProfileInt(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    int nValue);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ela será criada. O nome da seção diferencia maiúsculas de minúsculas; a cadeia de caracteres pode ser qualquer combinação de letras maiúsculas e minúsculas.

*lpszEntry*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor deve ser gravado. Se a entrada não existir na seção especificada, ela será criada.

*nvalor*<br/>
Contém o valor a ser gravado.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

Este exemplo usa `CWinApp* pApp = AfxGetApp();` para obter a classe CWinApp que ilustra uma maneira que `WriteProfileString` , `WriteProfileInt` , `GetProfileString` e `GetProfileInt` pode ser usada em qualquer função em um aplicativo MFC.

[!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]

Para obter outro exemplo, consulte o exemplo de [CWinApp:: GetProfileInt](#getprofileint).

## <a name="cwinappwriteprofilestring"></a><a name="writeprofilestring"></a>CWinApp:: WriteProfileString

Chame essa função de membro para gravar a cadeia de caracteres especificada na seção especificada do registro do aplicativo ou. Arquivo INI.

```
BOOL WriteProfileString(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPCTSTR lpszValue);
```

### <a name="parameters"></a>parâmetros

*lpszSection*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ela será criada. O nome da seção diferencia maiúsculas de minúsculas; a cadeia de caracteres pode ser qualquer combinação de letras maiúsculas e minúsculas.

*lpszEntry*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor deve ser gravado. Se a entrada não existir na seção especificada, ela será criada. Se esse parâmetro for NULL, a seção especificada por *lpszSection* será excluída.

*lpszValue*<br/>
Aponta para a cadeia de caracteres a ser gravada. Se esse parâmetro for NULL, a entrada especificada pelo parâmetro *lpszEntry* será excluída.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]

Para obter outro exemplo, consulte o exemplo de [CWinApp:: GetProfileInt](#getprofileint).

## <a name="cwinappsetappid"></a><a name="setappid"></a>CWinApp:: setappid

Define explicitamente a ID do modelo de usuário do aplicativo para o aplicativo. Esse método deve ser chamado antes que qualquer interface do usuário seja apresentada ao usuário (o melhor lugar é o construtor do aplicativo).

```cpp
void SetAppID(LPCTSTR lpcszAppID);
```

### <a name="parameters"></a>parâmetros

*lpcszAppID*<br/>
Especifica a ID do modelo de usuário do aplicativo.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Classe CWinThread](../../mfc/reference/cwinthread-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Como: Adicionar o suporte do Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)
