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
ms.openlocfilehash: 946de5768829330f84b826a1fc9b2f6278847357
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366830"
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
|[CWinApp::CWinApp](#cwinapp)|Constrói um objeto `CWinApp`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp::AddDocTemplate](#adddoctemplate)|Adiciona um modelo de documento à lista de modelos de documentos disponíveis do aplicativo.|
|[Cwinapp::AddToRecentFilelist](#addtorecentfilelist)|Adiciona um nome de arquivo à lista de arquivos mais recentemente usada (MRU).|
|[CWinApp::ApplicationRecuperação de aplicativosCallback](#applicationrecoverycallback)|Chamado pela estrutura quando o aplicativo sai inesperadamente.|
|[CwinApp::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos abertos.|
|[CWinApp::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora.|
|[CWinApp::DelRegTree](#delregtree)|Exclui uma chave especificada e todas as suas subchaves.|
|[CWinApp::DoMessageBox](#domessagebox)|Implementa [o AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para o aplicativo.|
|[CWinApp::DoWaitCursor](#dowaitcursor)|Liga e desliga o cursor de espera.|
|[CWinApp::EnableD2DSupport](#enabled2dsupport)|Habilita o suporte ao Aplicativo D2D. Chame este método antes que a janela principal seja inicializada.|
|[Cwinapp::EnablehtmlHelp](#enablehtmlhelp)|Implementa HTMLHelp para o aplicativo, em vez de WinHelp.|
|[CWinApp::Ativarbarradetarefainteração](#enabletaskbarinteraction)|Permite a interação da barra de tarefas.|
|[CWinApp::ExitInstance](#exitinstance)|Anular para limpar quando sua solicitação terminar.|
|[CWinApp::GetApplicationParameter de recuperação](#getapplicationrecoveryparameter)|Recupera o parâmetro de entrada para o método de recuperação do aplicativo.|
|[CWinApp::GetApplicationRecoveryPingInterval](#getapplicationrecoverypinginterval)|Retorna o tempo que o gerenciador de reinicialização espera para que a função de retorno de chamada de recuperação retorne.|
|[CWinApp::GetApplicationRestartFlags](#getapplicationrestartflags)|Devolve as bandeiras para o gerente de reinicialização.|
|[CwinApp::GetAppRegistryKey](#getappregistrykey)|A tecla\\de devolução para HKEY_CURRENT_USER "Software"\RegistryKey\ProfileName.|
|[CWinApp::GetDataRecoveryHandler](#getdatarecoveryhandler)|Obtém o manipulador de recuperação de dados para esta instância do aplicativo.|
|[CWinApp::GetFirstDocTemplatePosition](#getfirstdoctemplateposition)|Recupera a posição do primeiro modelo de documento.|
|[CWinApp::GetHelpMode](#gethelpmode)|Recupera o tipo de ajuda usada pelo aplicativo.|
|[CWinApp::GetNextDocTemplate](#getnextdoctemplate)|Recupera a posição de um modelo de documento. Pode ser usado recursivamente.|
|[CWinApp::GetPrinterDeviceDefaults](#getprinterdevicedefaults)|Recupera os padrões do dispositivo da impressora.|
|[CWinApp::GetProfileBinary](#getprofilebinary)|Recupera dados binários de uma entrada no aplicativo . Arquivo INI.|
|[CWinApp::GetProfileInt](#getprofileint)|Recupera um inteiro de uma entrada no aplicativo . Arquivo INI.|
|[CWinApp::GetProfileString](#getprofilestring)|Recupera uma seqüência de uma entrada no aplicativo . Arquivo INI.|
|[CWinApp::GetSectionKey](#getsectionkey)|A tecla\\retorna para HKEY_CURRENT_USER "Software"\RegistryKey\AppName\lpszSection.|
|[CWinApp::Ocultaraplicativo](#hideapplication)|Oculta o aplicativo antes de fechar todos os documentos.|
|[CwinApp::htmlHelp](#htmlhelp)|Chama `HTMLHelp` a função Windows.|
|[CWinApp::InitInstance](#initinstance)|Substituir para executar a inicialização da instância do Windows, como a criação de objetos de janela.|
|[CWinApp::IsTaskbarInteractionAtivadoativado](#istaskbarinteractionenabled)|Informa se a interação da barra de tarefas do Windows 7 está ativada.|
|[CWinApp::LoadCursor](#loadcursor)|Carrega um recurso do cursor.|
|[CWinApp::LoadIcon](#loadicon)|Carrega um recurso de ícone.|
|[CWinApp::LoadOEMCursor](#loadoemcursor)|Carrega um cursor predefinido do Windows OEM que **as** OCR_ constantes especificam no WINDOWS. H.|
|[CWinApp::LoadOEMIcon](#loadoemicon)|Carrega um ícone predefinido do Windows OEM que **OIC_** as constantes especificam no WINDOWS. H.|
|[CWinApp::LoadStandardCursor](#loadstandardcursor)|Carrega um cursor predefinido do Windows que **as** IDC_ constantes especificam no WINDOWS. H.|
|[CWinApp::LoadStandardIcon](#loadstandardicon)|Carrega um ícone predefinido do Windows que as constantes **IDI_** especificam no WINDOWS. H.|
|[CWinApp::OnDDECommand](#onddecommand)|Chamado pelo framework em resposta a um comando de execução dinâmica de troca de dados (DDE).|
|[CwinApp::Onidle](#onidle)|Substituir para executar o processamento de tempo ocioso específico do aplicativo.|
|[CWinApp::Abrir arquivo de documentos](#opendocumentfile)|Chamado pela estrutura para abrir um documento de um arquivo.|
|[CWinApp::ParseCommandLine](#parsecommandline)|Analisa parâmetros individuais e bandeiras na linha de comando.|
|[CWinApp::PreTraduzirmensagem](#pretranslatemessage)|Filtra mensagens antes de serem enviadas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).|
|[CWinApp::ProcessMessageFilter](#processmessagefilter)|Intercepta certas mensagens antes de chegar ao aplicativo.|
|[CWinApp::ProcessShellCommand](#processshellcommand)|Lida com argumentos e bandeiras de linha de comando.|
|[CWinApp::ProcessWndProcException](#processwndprocexception)|Intercepta todas as exceções não manuseadas lançadas pelos manipuladores de mensagens e comandos do aplicativo.|
|[CWinApp::Registrar](#register)|Realiza registro personalizado.|
|[CWinApp::RegistrarComReiniciarManager](#registerwithrestartmanager)|Registra o aplicativo com o gerenciador de reinicialização.|
|[Cwinapp::Reabrearquivos anterioresnareinicialização](#reopenpreviousfilesatrestart)|Determina se o gerenciador de reinicialização reabre os arquivos que estavam abertos quando o aplicativo saiu inesperadamente.|
|[CWinApp::ReinicializaçãoInstância](#restartinstance)|Lida com uma reinicialização de aplicativo iniciada pelo gerenciador de reinicialização.|
|[CWinApp::RestaurarArquivos salvos automáticosRereiniciar](#restoreautosavedfilesatrestart)|Determina se o gerenciador de reinicialização restaura os arquivos salvos automaticamente quando ele reinicia o aplicativo.|
|[CWinApp::Execução](#run)|Executa o loop de mensagem padrão. Substituir para personalizar o loop de mensagem.|
|[CWinApp::RunAutomated](#runautomated)|Testa a linha de comando do aplicativo para a opção **/Automação.** Obsoleto. Em vez disso, use o valor em [CCommandLineInfo::m_bRunAutomated](../../mfc/reference/ccommandlineinfo-class.md#m_brunautomated) depois de chamar [ParseCommandLine](#parsecommandline).|
|[CWinApp::RunEmbedded](#runembedded)|Testa a linha de comando do aplicativo para a opção **/Incorporação.** Obsoleto. Em vez disso, use o valor em [CCommandLineInfo::m_bRunEmbedded](../../mfc/reference/ccommandlineinfo-class.md#m_brunembedded) depois de chamar [ParseCommandLine](#parsecommandline).|
|[Cwinapp::SaveAllModified](#saveallmodified)|Solicita ao usuário que salve todos os documentos modificados.|
|[CWinApp::SelectPrinter](#selectprinter)|Seleciona uma impressora previamente indicada por um usuário através de uma caixa de diálogo de impressão.|
|[CWinApp::SetHelpMode](#sethelpmode)|Define e inicializa o tipo de ajuda usada pelo aplicativo.|
|[CWinApp::SupportsApplicationRecovery](#supportsapplicationrecovery)|Determina se o gerenciador de reinicialização recupera um aplicativo que saiu inesperadamente.|
|[CWinApp::SuportesAutosaveAtInterval](#supportsautosaveatinterval)|Determina se o gerenciador de reinicialização salva automaticamente documentos abertos em um intervalo regular.|
|[CWinApp::SuportesAutosaveAtRestart](#supportsautosaveatrestart)|Determina se o gerenciador de reinicialização salva automaticamente algum documento aberto quando o aplicativo é reiniciado.|
|[CWinApp::SupportsRestartManager](#supportsrestartmanager)|Determina se o aplicativo suporta o gerenciador de reinicialização.|
|[CWinApp::Unregister](#unregister)|Desregistra tudo o que se `CWinApp` sabe ser registrado pelo objeto.|
|[CWinApp::WinHelp](#winhelp)|Chama `WinHelp` a função Windows.|
|[CWinApp::WriteProfileBinary](#writeprofilebinary)|Grava dados binários em uma entrada no aplicativo . Arquivo INI.|
|[CWinApp::WriteProfileInt](#writeprofileint)|Escreve um inteiro para uma entrada no aplicativo. Arquivo INI.|
|[CWinApp::WriteProfileString](#writeprofilestring)|Escreve uma seqüência de entrada em uma entrada no aplicativo . Arquivo INI.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp::EnableShellOpen](#enableshellopen)|Permite que o usuário abra arquivos de dados do Gerenciador de Arquivos do Windows.|
|[CWinApp::Configurações de perfil loadStd](#loadstdprofilesettings)|Cargas padrão . Configurações do arquivo INI e habilita o recurso mru file list.|
|[CwinApp::OnContextHelp](#oncontexthelp)|Lida com shift+F1 Ajuda dentro do aplicativo.|
|[CWinApp::OnFileNew](#onfilenew)|Implementa o comando ID_FILE_NEW.|
|[CWinApp::OnFileOpen](#onfileopen)|Implementa o comando ID_FILE_OPEN.|
|[CWinApp::OnFilePrintSetup](#onfileprintsetup)|Implementa o comando ID_FILE_PRINT_SETUP.|
|[CwinApp::OnHelp](#onhelp)|Lida com a Ajuda f1 dentro do aplicativo (usando o contexto atual).|
|[CwinApp::OnHelpFinder](#onhelpfinder)|Cuida dos comandos ID_HELP_FINDER e ID_DEFAULT_HELP.|
|[CWinApp::OnHelpIndex](#onhelpindex)|Lida com o comando ID_HELP_INDEX e fornece um tópico de Ajuda padrão.|
|[CwinApp::OnHelpusing](#onhelpusing)|Controla o comando ID_HELP_USING.|
|[CWinApp::RegistrarshellArquivos de arquivos](#registershellfiletypes)|Registra todos os tipos de documentos do aplicativo com o Gerenciador de Arquivos do Windows.|
|[CwinApp::SetAppID](#setappid)|Define explicitamente o ID do modelo do usuário do aplicativo para o aplicativo. Este método deve ser chamado antes que qualquer interface de usuário seja apresentada ao usuário (o melhor lugar é o construtor do aplicativo).|
|[CWinApp::SetRegistryKey](#setregistrykey)|Faz com que as configurações do aplicativo sejam armazenadas no registro em vez de . Arquivos INI.|
|[CWinApp::UnregisterShellArquivos](#unregistershellfiletypes)|Desregistra todos os tipos de documentos do aplicativo com o Gerenciador de Arquivos do Windows.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinApp::m_bHelpMode](#m_bhelpmode)|Indica se o usuário está no modo de contexto de Ajuda (normalmente invocado com SHIFT+F1).|
|[CWinApp::m_eHelpType](#m_ehelptype)|Especifica o tipo de ajuda usada pelo aplicativo.|
|[CwinApp::m_hInstance](#m_hinstance)|Identifica a instância atual do aplicativo.|
|[CWinApp::m_lpCmdLine](#m_lpcmdline)|Aponta para uma seqüência de terminadas nula que especifica a linha de comando para o aplicativo.|
|[CWinApp::m_nCmdShow](#m_ncmdshow)|Especifica como a janela deve ser mostrada inicialmente.|
|[CWinApp::m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo de contêiner quando um servidor OLE estiver ativo no local.|
|[CWinApp::m_pszAppID](#m_pszappid)|ID do modelo do usuário do aplicativo.|
|[CWinApp::m_pszAppName](#m_pszappname)|Especifica o nome do aplicativo.|
|[CwinApp::m_pszExeName](#m_pszexename)|O nome do módulo da aplicação.|
|[CWinApp::m_pszHelpFilePath](#m_pszhelpfilepath)|O caminho para o arquivo de ajuda do aplicativo.|
|[CWinApp::m_pszProfileName](#m_pszprofilename)|A aplicação é. Nome de arquivo INI.|
|[CWinApp::m_pszRegistryKey](#m_pszregistrykey)|Usado para determinar a chave de registro completo para armazenar as configurações do perfil do aplicativo.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CwinApp::m_dwRestartManagerSupportFlags](#m_dwrestartmanagersupportflags)|Sinalizadores que determinam como o gerenciador de reinicialização se comporta.|
|[CWinApp::m_nAutosaveInterval](#m_nautosaveinterval)|O tempo entre os salvamentos automáticos.|
|[CwinApp::m_pDataRecoveryHandler](#m_pdatarecoveryhandler)|Ponteiro para o manipulador de recuperação de dados para o aplicativo.|

## <a name="remarks"></a>Comentários

Um objeto de aplicativo fornece funções de membro para inicializar seu aplicativo (e cada instância dele) e para executar o aplicativo.

Cada aplicativo que usa as classes microsoft foundation `CWinApp`só pode conter um objeto derivado de . Este objeto é construído quando outros objetos globais C++ são `WinMain` construídos e já estão disponíveis quando o Windows chama a função, que é fornecida pela Microsoft Foundation Class Library. Declare seu `CWinApp` objeto derivado em nível global.

Quando você deriva uma `CWinApp`classe de aplicativo de , substituir a função de membro [InitInstance](#initinstance) para criar o objeto de janela principal do aplicativo.

Além das `CWinApp` funções de membro, a Microsoft Foundation Class Library `CWinApp` fornece as seguintes funções globais para acessar seu objeto e outras informações globais:

- [AfxGetApp](application-information-and-management.md#afxgetapp) Obtém um ponteiro `CWinApp` para o objeto.

- [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle) Obtém uma alça para a instância atual do aplicativo.

- [AfxGetResourceHandle](application-information-and-management.md#afxgetresourcehandle) Obtém uma alça para os recursos da aplicação.

- [AfxGetAppName](application-information-and-management.md#afxgetappname) Obtém um ponteiro para uma seqüência contendo o nome do aplicativo. Alternativamente, se você tiver `CWinApp` um ponteiro `m_pszExeName` para o objeto, use para obter o nome do aplicativo.

Consulte [CWinApp: A classe de aplicativos](../../mfc/cwinapp-the-application-class.md) para obter mais informações sobre a `CWinApp` classe, incluindo uma visão geral do seguinte:

- `CWinApp`-código derivado escrito pelo Assistente de Aplicativo.

- `CWinApp`'papel na seqüência de execução de sua aplicação.

- `CWinApp`'implementações de função de membro padrão.

- `CWinApp`São os principais super-ridicularizados.

O `m_hPrevInstance` membro de dados não existe mais. Para determinar se outra instância do aplicativo está sendo executado, use um mutex chamado. Se a abertura do mutex falhar, não haverá outras instâncias do aplicativo em execução.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWinThread](../../mfc/reference/cwinthread-class.md)

`CWinApp`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cwinappadddoctemplate"></a><a name="adddoctemplate"></a>CWinApp::AddDocTemplate

Ligue para esta função de membro para adicionar um modelo de documento à lista de modelos de documentos disponíveis que o aplicativo mantém.

```
void AddDocTemplate(CDocTemplate* pTemplate);
```

### <a name="parameters"></a>Parâmetros

*pTemplate*<br/>
Um ponteiro `CDocTemplate` para o a ser adicionado.

### <a name="remarks"></a>Comentários

Você deve adicionar todos os modelos de documentos a um aplicativo antes de chamar [RegisterShellFileTypes](#registershellfiletypes).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#35](../../mfc/reference/codesnippet/cpp/cwinapp-class_1.cpp)]

## <a name="cwinappaddtorecentfilelist"></a><a name="addtorecentfilelist"></a>Cwinapp::AddToRecentFilelist

Chame esta função de membro para adicionar *lpszPathName* à lista de arquivos MRU.

```
virtual void AddToRecentFileList(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
O caminho do arquivo.

### <a name="remarks"></a>Comentários

Você deve chamar a função de membro [LoadStdProfileSettings](#loadstdprofilesettings) para carregar a lista de arquivos MRU atual antes de usar esta função de membro.

A estrutura chama essa função de membro quando abre um arquivo ou executa o comando Salvar como para salvar um arquivo com um novo nome.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#36](../../mfc/reference/codesnippet/cpp/cwinapp-class_2.cpp)]

## <a name="cwinappapplicationrecoverycallback"></a><a name="applicationrecoverycallback"></a>CWinApp::ApplicationRecuperação de aplicativosCallback

Chamado pela estrutura quando o aplicativo sai inesperadamente.

```
virtual DWORD ApplicationRecoveryCallback(LPVOID lpvParam);
```

### <a name="parameters"></a>Parâmetros

*lpvParam*<br/>
[em] Reservado para uso futuro.

### <a name="return-value"></a>Valor retornado

0 se este método for bem sucedido; não zero se ocorrer um erro.

### <a name="remarks"></a>Comentários

Se o aplicativo suportar o gerenciador de reinicialização, a estrutura chamará essa função quando seu aplicativo sair inesperadamente.

A implementação `ApplicationRecoveryCallback` padrão `CDataRecoveryHandler` do usa o para salvar a lista de documentos abertos no momento para o registro. Este método não salva automaticamente nenhum arquivo.

Para personalizar o comportamento, anular essa função em uma [classe CWinApp](../../mfc/reference/cwinapp-class.md) derivada ou passar seu próprio método de recuperação de aplicativos como parâmetro para [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager).

## <a name="cwinappclosealldocuments"></a><a name="closealldocuments"></a>CwinApp::CloseAllDocuments

Ligue para esta função de membro para fechar todos os documentos abertos antes de sair.

```
void CloseAllDocuments(BOOL bEndSession);
```

### <a name="parameters"></a>Parâmetros

*bEndSession*<br/>
Especifica se a sessão do Windows está sendo encerrada ou não. É VERDADE se a sessão está sendo encerrada; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chamada [Ocultaraplicativo](#hideapplication) antes de chamar `CloseAllDocuments`.

## <a name="cwinappcreateprinterdc"></a><a name="createprinterdc"></a>CWinApp::CreatePrinterDC

Chame esta função de membro para criar um contexto de dispositivo de impressora (DC) a partir da impressora selecionada.

```
BOOL CreatePrinterDC(CDC& dc);
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
Uma referência a um contexto de dispositivo de impressora.

### <a name="return-value"></a>Valor retornado

Não zero se o contexto do dispositivo da impressora for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

`CreatePrinterDC`inicializa o contexto do dispositivo que você passa por referência, para que você possa usá-lo para imprimir.

Se a função for bem sucedida, quando você terminar a impressão, você deve destruir o contexto do dispositivo. Você pode deixar o destrutor do objeto [CDC](../../mfc/reference/cdc-class.md) fazê-lo, ou você pode fazê-lo explicitamente chamando [CDC::DeleteDC](../../mfc/reference/cdc-class.md#deletedc).

## <a name="cwinappcwinapp"></a><a name="cwinapp"></a>CWinApp::CWinApp

Constrói um `CWinApp` objeto e passa *lpszAppName* para ser armazenado como o nome do aplicativo.

```
CWinApp(LPCTSTR lpszAppName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszAppName*<br/>
Uma seqüência de terminação nula que contém o nome do aplicativo que o Windows usa. Se esse argumento não for `CWinApp` fornecido ou for NULL, use a seqüência de recursos AFX_IDS_APP_TITLE ou o nome do arquivo do arquivo executável.

### <a name="remarks"></a>Comentários

Você deve construir um `CWinApp`objeto global de sua classe derivada. Você pode ter `CWinApp` apenas um objeto em sua aplicação. O construtor armazena um `CWinApp` ponteiro para `WinMain` o objeto para que possa chamar as funções do membro do objeto para inicializar e executar o aplicativo.

## <a name="cwinappdelregtree"></a><a name="delregtree"></a>CWinApp::DelRegTree

Exclui uma chave de registro específica e todas as suas subchaves.

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

*hParentkey*<br/>
Manuseie uma chave de registro.

*strKeyName*<br/>
O nome da chave de registro a ser excluído.

*Ptm*<br/>
Ponteiro para objeto CAtlTransactionManager.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será ERROR_SUCCESS. Se a função falhar, o valor de retorno será um código de erro não zero definido em Winerror.h.

### <a name="remarks"></a>Comentários

Chame esta função para excluir a chave especificada e suas subchaves.

## <a name="cwinappdomessagebox"></a><a name="domessagebox"></a>CWinApp::DoMessageBox

A estrutura chama essa função de membro para implementar uma caixa de mensagem para a função global [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox).

```
virtual int DoMessageBox(
    LPCTSTR lpszPrompt,
    UINT nType,
    UINT nIDPrompt);
```

### <a name="parameters"></a>Parâmetros

*lpszPrompt*<br/>
Endereço do texto na caixa de mensagens.

*nType*<br/>
O [estilo](../../mfc/reference/styles-used-by-mfc.md#message-box-styles)caixa de mensagem .

*nIDPrompt*<br/>
Um índice para uma seqüência de contexto de ajuda.

### <a name="return-value"></a>Valor retornado

Retorna os mesmos valores que `AfxMessageBox`.

### <a name="remarks"></a>Comentários

Não chame esta função de membro para abrir uma caixa de mensagem; usar `AfxMessageBox` em vez disso.

Substituir essa função de membro para personalizar `AfxMessageBox` o processamento de chamadas em todo o aplicativo.

## <a name="cwinappdowaitcursor"></a><a name="dowaitcursor"></a>CWinApp::DoWaitCursor

Essa função de membro é chamada pela framework para implementar [CWaitCursor,](../../mfc/reference/cwaitcursor-class.md) [CCmdTarget::BeginWaitCursor,](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor) [CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)e [CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).

```
virtual void DoWaitCursor(int nCode);
```

### <a name="parameters"></a>Parâmetros

*Ncode*<br/>
Se este parâmetro for 1, um cursor de espera aparecerá. Se 0, o cursor de espera é restaurado sem incrementar a contagem de referência. Se -1, o cursor de espera termina.

### <a name="remarks"></a>Comentários

O padrão implementa um cursor de ampulheta. `DoWaitCursor`mantém uma contagem de referência. Quando positivo, o cursor de ampulheta é exibido.

Embora você normalmente `DoWaitCursor` não ligue diretamente, você pode substituir essa função de membro para alterar o cursor de espera ou fazer processamento adicional enquanto o cursor de espera é exibido.

Para uma maneira mais fácil e simplificada de `CWaitCursor`implementar um cursor de espera, use .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#37](../../mfc/reference/codesnippet/cpp/cwinapp-class_3.cpp)]

## <a name="cwinappenabled2dsupport"></a><a name="enabled2dsupport"></a>CWinApp::EnableD2DSupport

O Visual Studio 2010 SP1 é necessário.

Habilita o suporte ao Aplicativo D2D. Chame este método antes que a janela principal seja inicializada.

```
BOOL EnableD2DSupport(
    D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED,
    DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);
```

### <a name="parameters"></a>Parâmetros

*d2dFactoryType*<br/>
O modelo de rosca da fábrica D2D e os recursos que ele cria.

*writeFactoryType*<br/>
Um valor que especifica se o objeto de fábrica de gravação será compartilhado ou isolado

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o suporte ao D2D foi ativado, FALSE - caso contrário

## <a name="cwinappenablehtmlhelp"></a><a name="enablehtmlhelp"></a>Cwinapp::EnablehtmlHelp

Chame esta função de membro de `CWinApp`dentro do construtor de sua classe derivada para usar HTMLHelp para a ajuda do seu aplicativo.

```
void EnableHtmlHelp();
```

### <a name="remarks"></a>Comentários

## <a name="cwinappenableshellopen"></a><a name="enableshellopen"></a>CWinApp::EnableShellOpen

Chame essa função, normalmente a partir de sua `InitInstance` substituição, para permitir que os usuários do aplicativo abram arquivos de dados quando clicarem duas vezes nos arquivos de dentro do Gerenciador de Arquivos do Windows.

```
void EnableShellOpen();
```

### <a name="remarks"></a>Comentários

Ligue `RegisterShellFileTypes` para a função do membro em conjunto com esta função, ou forneça um . Arquivo REG com seu pedido de registro manual de tipos de documentos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#38](../../mfc/reference/codesnippet/cpp/cwinapp-class_4.cpp)]

## <a name="cwinappenabletaskbarinteraction"></a><a name="enabletaskbarinteraction"></a>CWinApp::Ativarbarradetarefainteração

Permite a interação da barra de tarefas.

```
BOOL EnableTaskbarInteraction(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Especifica se a interação com a barra de tarefas do Windows 7 deve ser ativada (TRUE) ou desativada (FALSE).

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a interação da barra de tarefas puder ser ativada ou desativada.

### <a name="remarks"></a>Comentários

Este método deve ser chamado antes da criação da janela principal, caso contrário ele afirma e retorna FALSO.

## <a name="cwinappexitinstance"></a><a name="exitinstance"></a>CWinApp::ExitInstance

Chamado pelo framework de `Run` dentro da função membro para sair desta instância do aplicativo.

```
virtual int ExitInstance();
```

### <a name="return-value"></a>Valor retornado

O código de saída do aplicativo; 0 indica nenhum erro, e valores maiores que 0 indicam um erro. Este valor é usado como `WinMain`o valor de retorno de .

### <a name="remarks"></a>Comentários

Não chame esta função de membro `Run` de qualquer lugar, mas dentro da função membro.

A implementação padrão desta função grava opções de framework para o aplicativo . Arquivo INI. Anular esta função para limpar quando seu aplicativo terminar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#39](../../mfc/reference/codesnippet/cpp/cwinapp-class_5.cpp)]

## <a name="cwinappgetapplicationrecoveryparameter"></a><a name="getapplicationrecoveryparameter"></a>CWinApp::GetApplicationParameter de recuperação

Recupera o parâmetro de entrada para o método de recuperação do aplicativo.

```
virtual LPVOID GetApplicationRecoveryParameter();
```

### <a name="return-value"></a>Valor retornado

O parâmetro de entrada padrão para o método de recuperação do aplicativo.

### <a name="remarks"></a>Comentários

O comportamento padrão desta função retorna NULL.

Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).

## <a name="cwinappgetapplicationrecoverypinginterval"></a><a name="getapplicationrecoverypinginterval"></a>CWinApp::GetApplicationRecoveryPingInterval

Retorna o tempo que o gerenciador de reinicialização espera para que a função de retorno de chamada de recuperação retorne.

```
virtual DWORD GetApplicationRecoveryPingInterval();
```

### <a name="return-value"></a>Valor retornado

O tempo em milissegundos.

### <a name="remarks"></a>Comentários

Quando um aplicativo registrado no gerenciador de reinicialização sai inesperadamente, o aplicativo tenta salvar documentos abertos e chama a função de retorno de chamada de recuperação. A função de retorno de chamada de recuperação padrão é [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).

O tempo que a estrutura espera para que a função de retorno de chamada de recuperação seja o intervalo de ping. Você pode personalizar o intervalo `CWinApp::GetApplicationRecoveryPingInterval` de ping substituindo `RegisterWithRestartManager`ou fornecendo um valor personalizado para .

## <a name="cwinappgetapplicationrestartflags"></a><a name="getapplicationrestartflags"></a>CWinApp::GetApplicationRestartFlags

Devolve as bandeiras para o gerente de reinicialização.

```
virtual DWORD GetApplicationRestartFlags();
```

### <a name="return-value"></a>Valor retornado

As bandeiras para o gerente de reinicialização. A implementação padrão retorna 0.

### <a name="remarks"></a>Comentários

As bandeiras para o gerenciador de reinicialização não têm efeito com a implementação padrão. Eles são fornecidos para uso futuro.

Você define os sinalizadores quando registra o aplicativo com o gerenciador de reinicialização usando [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager).

Os valores possíveis para as bandeiras do gerenciador de reinicialização são os seguintes:

- RESTART_NO_CRASH

- RESTART_NO_HANG

- RESTART_NO_PATCH

- RESTART_NO_REBOOT

## <a name="cwinappgetappregistrykey"></a><a name="getappregistrykey"></a>CwinApp::GetAppRegistryKey

Retorna a chave\\para HKEY_CURRENT_USER "Software"\RegistryKey\ProfileName.

```
HKEY GetAppRegistryKey(CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

Chave de aplicação se a função for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cwinappgetdatarecoveryhandler"></a><a name="getdatarecoveryhandler"></a>CWinApp::GetDataRecoveryHandler

Obtém o manipulador de recuperação de dados para esta instância do aplicativo.

```
virtual CDataRecoveryHandler *GetDataRecoveryHandler();
```

### <a name="return-value"></a>Valor retornado

O manipulador de recuperação de dados para esta instância do aplicativo.

### <a name="remarks"></a>Comentários

Cada aplicativo que usa o gerenciador de reinicialização deve ter uma instância da [Classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md). Esta classe é responsável por monitorar documentos abertos e arquivos de salvamento automático. O comportamento `CDataRecoveryHandler` do depende da configuração do gerenciador de reinicialização. Para obter mais informações, consulte [CDataRecoveryHandler Class](../../mfc/reference/cdatarecoveryhandler-class.md).

Este método retorna NULL em sistemas operacionais antes do Windows Vista. O gerenciador de reinicialização não é suportado em sistemas operacionais antes do Windows Vista.

Se o aplicativo não tiver atualmente um manipulador de recuperação de dados, este método criará um e retorna um ponteiro para ele.

## <a name="cwinappgetfirstdoctemplateposition"></a><a name="getfirstdoctemplateposition"></a>CWinApp::GetFirstDocTemplatePosition

Obtém a posição do primeiro modelo de documento no aplicativo.

```
POSITION GetFirstDocTemplatePosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se a lista estiver vazia.

### <a name="remarks"></a>Comentários

Use o valor DE POSIÇÃO retornado em uma chamada para [GetNextDocTemplate](#getnextdoctemplate) para obter o primeiro objeto [CDocTemplate.](../../mfc/reference/cdoctemplate-class.md)

## <a name="cwinappgethelpmode"></a><a name="gethelpmode"></a>CWinApp::GetHelpMode

Recupera o tipo de ajuda usada pelo aplicativo.

```
AFX_HELP_TYPE GetHelpMode();
```

### <a name="return-value"></a>Valor retornado

O tipo de ajuda usado pelo aplicativo. Consulte [CWinApp::m_eHelpType](#m_ehelptype) para obter mais informações.

## <a name="cwinappgetnextdoctemplate"></a><a name="getnextdoctemplate"></a>CWinApp::GetNextDocTemplate

Obtém o modelo de documento identificado por *pos*e, em seguida, define *pos* para o valor DE POSIÇÃO.

```
CDocTemplate* GetNextDocTemplate(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Uma referência a um valor DE POSIÇÃO `GetNextDocTemplate` retornado por uma chamada anterior ou [GetFirstDocTemplatePosition](#getfirstdoctemplateposition). O valor é atualizado para a próxima posição por esta chamada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CDocTemplate.](../../mfc/reference/cdoctemplate-class.md)

### <a name="remarks"></a>Comentários

Você pode `GetNextDocTemplate` usar em um loop de iteração para `GetFirstDocTemplatePosition`frente se estabelecer a posição inicial com uma chamada para .

Você deve garantir que seu valor de POSIÇÃO seja válido. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o modelo de documento recuperado for o último disponível, então o novo valor do *pos* será definido como NULL.

## <a name="cwinappgetprinterdevicedefaults"></a><a name="getprinterdevicedefaults"></a>CWinApp::GetPrinterDeviceDefaults

Chame esta função de membro para preparar um contexto de dispositivo de impressora para impressão.

```
BOOL GetPrinterDeviceDefaults(struct tagPDA* pPrintDlg);
```

### <a name="parameters"></a>Parâmetros

*pPrintDlg*<br/>
Um ponteiro para uma estrutura [PRINTDLG.](/windows/win32/api/commdlg/ns-commdlg-printdlga)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Recupera os padrões atuais da impressora do Windows . Arquivo INI conforme necessário, ou usa a última configuração de impressora definida pelo usuário na Configuração de impressão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#40](../../mfc/reference/codesnippet/cpp/cwinapp-class_6.cpp)]

## <a name="cwinappgetprofilebinary"></a><a name="getprofilebinary"></a>CWinApp::GetProfileBinary

Chame esta função de membro para recuperar dados binários de uma entrada dentro de uma seção especificada do registro do aplicativo ou . Arquivo INI.

```
BOOL GetProfileBinary(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPBYTE* ppData,
    UINT* pBytes);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
Aponta para uma seqüência de terminadas nula que especifica a seção que contém a entrada.

*Lpszentry*<br/>
Aponta para uma seqüência de terminação nula que contém a entrada cujo valor deve ser recuperado.

*Ppdata*<br/>
Aponta para um ponteiro que receberá o endereço dos dados.

*pBytes*<br/>
Aponta para um UINT que receberá o tamanho dos dados (em bytes).

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro não é sensível a maiúsculas e minúsculas, portanto, as strings nos *parâmetros lpszSection* e *lpszEntry* podem diferir no caso.

> [!NOTE]
> `GetProfileBinary`aloca um buffer e retorna \* seu endereço em *ppData*. O chamador é responsável por liberar o buffer usando **excluir []**.

> [!IMPORTANT]
> Os dados retornados por esta função não são necessariamente nulos encerrados, e o chamador deve realizar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#41](../../mfc/reference/codesnippet/cpp/cwinapp-class_7.cpp)]

Para obter um exemplo adicional, consulte [CWinApp::WriteProfileBinary](#writeprofilebinary).

## <a name="cwinappgetprofileint"></a><a name="getprofileint"></a>CWinApp::GetProfileInt

Chame esta função de membro para recuperar o valor de um inteiro de uma entrada dentro de uma seção especificada do registro do aplicativo ou . Arquivo INI.

```
UINT GetProfileInt(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    int nDefault);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
Aponta para uma seqüência de terminadas nula que especifica a seção que contém a entrada.

*Lpszentry*<br/>
Aponta para uma seqüência de terminação nula que contém a entrada cujo valor deve ser recuperado.

*nDefault*<br/>
Especifica o valor padrão a ser retornado se a estrutura não encontrar a entrada.

### <a name="return-value"></a>Valor retornado

O valor inteiro da seqüência que segue a entrada especificada se a função for bem sucedida. O valor de retorno é o valor do parâmetro *nDefault* se a função não encontrar a entrada. O valor de retorno é 0 se o valor correspondente à entrada especificada não for um inteiro.

Esta função membro suporta notação hexadecimal para o valor no . Arquivo INI. Quando você recupera um inteiro assinado, você deve lançar o valor em um **inteiro**.

### <a name="remarks"></a>Comentários

Esta função de membro não é sensível a maiúsculas e minúsculas, portanto, as strings nos *parâmetros lpszSection* e *lpszEntry* podem diferir no caso.

> [!IMPORTANT]
> Os dados retornados por esta função não são necessariamente nulos encerrados, e o chamador deve realizar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#42](../../mfc/reference/codesnippet/cpp/cwinapp-class_8.cpp)]

Para obter um exemplo adicional, consulte [CWinApp::WriteProfileInt](#writeprofileint).

## <a name="cwinappgetprofilestring"></a><a name="getprofilestring"></a>CWinApp::GetProfileString

Chame esta função de membro para recuperar a seqüência associada a uma entrada dentro da seção especificada no registro do aplicativo ou . Arquivo INI.

```
CString GetProfileString(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPCTSTR lpszDefault = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
Aponta para uma seqüência de terminadas nula que especifica a seção que contém a entrada.

*Lpszentry*<br/>
Aponta para uma seqüência de terminação nula que contém a entrada cuja seqüência deve ser recuperada. Este valor não deve ser NULO.

*lpszDefault*<br/>
Aponta para o valor da seqüência padrão para a entrada dada se a entrada não puder ser encontrada no arquivo de inicialização.

### <a name="return-value"></a>Valor retornado

O valor de retorno é a string do aplicativo . Arquivo INI ou *lpszDefault* se a seqüência não puder ser encontrada. O comprimento máximo da corda suportado pelo quadro é _MAX_PATH. Se *lpszDefault* for NULL, o valor de retorno será uma seqüência de string vazia.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
> Os dados retornados por esta função não são necessariamente nulos encerrados, e o chamador deve realizar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]

Em outro exemplo, consulte o exemplo de [CWinApp::GetProfileInt](#getprofileint).

## <a name="cwinappgetsectionkey"></a><a name="getsectionkey"></a>CWinApp::GetSectionKey

Retorna a chave\\para HKEY_CURRENT_USER "Software"\RegistryKey\AppName\lpszSection.

```
HKEY GetSectionKey(
    LPCTSTR lpszSection,
    CAtlTransactionManager* pTM = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
O nome da chave a ser obtida.

*Ptm*<br/>
Ponteiro para `CAtlTransactionManager` um objeto.

### <a name="return-value"></a>Valor retornado

Chave de seção se a função for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cwinapphideapplication"></a><a name="hideapplication"></a>CWinApp::Ocultaraplicativo

Ligue para esta função de membro para ocultar um aplicativo antes de fechar os documentos abertos.

```
void HideApplication();
```

## <a name="cwinapphtmlhelp"></a><a name="htmlhelp"></a>CwinApp::htmlHelp

Chame esta função de membro para invocar o aplicativo HTMLHelp.

```
virtual void HtmlHelp(
    DWORD_PTR dwData,
    UINT nCmd = 0x000F);
```

### <a name="parameters"></a>Parâmetros

*Dwdata*<br/>
Especifica dados adicionais. O valor utilizado depende do valor do parâmetro *nCmd.* Inadimplência ao `0x000F` que significa [HH_HELP_CONTEXT](/previous-versions/windows/desktop/htmlhelp/hh-help-context-command).

*nCmd*<br/>
Especifica o tipo de ajuda solicitada. Para obter uma lista de valores possíveis e como eles afetam o parâmetro *dwData,* consulte o parâmetro *uCommand* descrito nas funções [htmlHelpW](/windows/win32/api/htmlhelp/nf-htmlhelp-htmlhelpw) ou [HtmlHelpA](/windows/win32/api/htmlhelp/nf-htmlhelp-htmlhelpa) API no Windows SDK.

### <a name="remarks"></a>Comentários

A estrutura também chama essa função para invocar o aplicativo HTMLHelp.

A estrutura fechará automaticamente o aplicativo HTMLHelp quando seu aplicativo terminar.

## <a name="cwinappinitinstance"></a><a name="initinstance"></a>CWinApp::InitInstance

O Windows permite que várias cópias do mesmo programa seja executadaao mesmo tempo.

```
virtual BOOL InitInstance();
```

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A inicialização do aplicativo é conceitualmente dividida em duas seções: inicialização de aplicativo única que é feita na primeira vez que o programa é executado, e inicialização de instância que é executada cada vez que uma cópia do programa é executada, incluindo a primeira vez. A implementação do `WinMain` quadro de chamadas esta função.

Substituir `InitInstance` para inicializar cada nova instância do seu aplicativo em execução no Windows. Normalmente, você `InitInstance` se sobreporá para construir `CWinThread::m_pMainWnd` seu objeto de janela principal e definir o membro de dados para apontar para essa janela. Para obter mais informações sobre a substituição desta função de membro, consulte [CWinApp: The Application Class](../../mfc/cwinapp-the-application-class.md).

> [!NOTE]
> As aplicações MFC devem ser inicializadas como apartamento com rosca única (STA). Se você chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) em sua `InitInstance` substituição, especifique COINIT_APARTMENTTHREADED (em vez de COINIT_MULTITHREADED).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCListView#9](../../atl/reference/codesnippet/cpp/cwinapp-class_10.cpp)]

## <a name="cwinappistaskbarinteractionenabled"></a><a name="istaskbarinteractionenabled"></a>CWinApp::IsTaskbarInteractionAtivadoativado

Informa se a interação da barra de tarefas do Windows 7 está ativada.

```
virtual BOOL IsTaskbarInteractionEnabled();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE `EnableTaskbarInteraction` se tiver sido chamado e o sistema operacional for Windows 7 ou superior.

### <a name="remarks"></a>Comentários

A interação da barra de tarefas significa que o aplicativo MDI exibe o conteúdo de crianças MDI em miniaturas separadas com guias que aparecem quando o ponteiro do mouse está sobre o botão da barra de tarefas do aplicativo.

## <a name="cwinapploadcursor"></a><a name="loadcursor"></a>CWinApp::LoadCursor

Carrega o recurso do cursor nomeado por *lpszResourceName* ou especificado por *nIDResource* a partir do arquivo executável atual.

```
HCURSOR LoadCursor(LPCTSTR lpszResourceName) const;  HCURSOR LoadCursor(UINT nIDResource) const;
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Aponta para uma seqüência de terminação nula que contém o nome do recurso do cursor. Você pode `CString` usar um para este argumento.

*Nidresource*<br/>
ID do recurso do cursor. Para obter uma lista de recursos, consulte [LoadCursor](/windows/win32/api/winuser/nf-winuser-loadcursorw) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Uma alça para um cursor se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

`LoadCursor`carrega o cursor na memória somente se ele não tiver sido carregado anteriormente; caso contrário, ele recupera uma alça do recurso existente.

Use a função de membro [LoadStandardCursor](#loadstandardcursor) ou [LoadOEMCursor](#loadoemcursor) para acessar os cursores predefinidos do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#44](../../mfc/reference/codesnippet/cpp/cwinapp-class_11.cpp)]

## <a name="cwinapploadicon"></a><a name="loadicon"></a>CWinApp::LoadIcon

Carrega o recurso de ícone nomeado por *lpszResourceName* ou especificado por *nIDResource* a partir do arquivo executável.

```
HICON LoadIcon(LPCTSTR lpszResourceName) const;  HICON LoadIcon(UINT nIDResource) const;
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Aponta para uma seqüência de terminação nula que contém o nome do recurso de ícone. Você também pode `CString` usar um para este argumento.

*Nidresource*<br/>
Número de id do recurso de ícone.

### <a name="return-value"></a>Valor retornado

Uma alça para um ícone se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

`LoadIcon`carrega o ícone somente se ele não tiver sido carregado anteriormente; caso contrário, ele recupera uma alça do recurso existente.

Você pode usar a função de membro [LoadStandardIcon](#loadstandardicon) ou [LoadOEMIcon](#loadoemicon) para acessar os ícones predefinidos do Windows.

> [!NOTE]
> Esta função de membro chama a função API Win32 [LoadIcon](/windows/win32/api/winuser/nf-winuser-loadiconw), que só pode carregar um ícone cujo tamanho esteja de acordo com os valores de métrica do sistema SM_CXICON e SM_CYICON.

## <a name="cwinapploadoemcursor"></a><a name="loadoemcursor"></a>CWinApp::LoadOEMCursor

Carrega o recurso de cursor predefinido do Windows especificado pelo *nIDCursor*.

```
HCURSOR LoadOEMCursor(UINT nIDCursor) const;
```

### <a name="parameters"></a>Parâmetros

*nIDCursor*<br/>
Um **OCR_** identificador constante manifesto que especifica um cursor do Windows predefinido. Você deve `#define OEMRESOURCE` `#include \<afxwin.h>` ter antes de ter acesso às constantes **OCR_** no WINDOWS. H.

### <a name="return-value"></a>Valor retornado

Uma alça para um cursor se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use `LoadOEMCursor` a função de membro [LoadStandardCursor](#loadstandardcursor) para acessar os cursores predefinidos do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#45](../../mfc/reference/codesnippet/cpp/cwinapp-class_12.h)]

[!code-cpp[NVC_MFCWindowing#46](../../mfc/reference/codesnippet/cpp/cwinapp-class_13.cpp)]

## <a name="cwinapploadoemicon"></a><a name="loadoemicon"></a>CWinApp::LoadOEMIcon

Carrega o recurso de ícone predefinido do Windows especificado pelo *nIDIcon*.

```
HICON LoadOEMIcon(UINT nIDIcon) const;
```

### <a name="parameters"></a>Parâmetros

*nIDIcon*<br/>
Um **OIC_** identificar constante manifesto que especifica um ícone predefinido do Windows. Você deve `#define OEMRESOURCE` `#include \<afxwin.h>` ter antes de acessar as constantes **de OIC_** no WINDOWS. H.

### <a name="return-value"></a>Valor retornado

Uma alça para um ícone se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use `LoadOEMIcon` a função de membro [loadStandardIcon](#loadstandardicon) para acessar os ícones predefinidos do Windows.

## <a name="cwinapploadstandardcursor"></a><a name="loadstandardcursor"></a>CWinApp::LoadStandardCursor

Carrega o recurso de cursor predefinido do Windows que *o lpszCursorName* especifica.

```
HCURSOR LoadStandardCursor(LPCTSTR lpszCursorName) const;
```

### <a name="parameters"></a>Parâmetros

*lpszCursorNome*<br/>
Um **IDC_** identificar constante mente que especifica um cursor do Windows predefinido. Esses identificadores são definidos no WINDOWS. H. A lista a seguir mostra os possíveis valores e significados predefinidos para *lpszCursorName*:

- cursor de seta padrão de IDC_ARROW

- cursor padrão de inserção de texto IDC_IBEAM

- IDC_WAIT cursor Ampulheta usado quando o Windows executa uma tarefa demorada

- IDC_CROSS cursor de cabelo cruzado para seleção

- IDC_UPARROW Seta que aponta para cima

- IDC_SIZE Obsoleto e sem suporte; usar IDC_SIZEALL

- IDC_SIZEALL uma flecha de quatro pontas. O cursor para usar para redimensionar uma janela.

- IDC_ICON Obsoleto e sem suporte. Use IDC_ARROW.

- IDC_SIZENWSE seta de duas cabeças com pontas no canto superior esquerdo e inferior direito

- IDC_SIZENESW seta de duas cabeças com pontas no canto superior direito e inferior esquerdo

- IDC_SIZEWE seta horizontal de duas cabeças

- IDC_SIZENS seta vertical de duas cabeças

### <a name="return-value"></a>Valor retornado

Uma alça para um cursor se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use `LoadStandardCursor` a função de membro [LoadOEMCursor](#loadoemcursor) para acessar os cursores predefinidos do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#47](../../mfc/reference/codesnippet/cpp/cwinapp-class_14.cpp)]

## <a name="cwinapploadstandardicon"></a><a name="loadstandardicon"></a>CWinApp::LoadStandardIcon

Carrega o recurso de ícone predefinido do Windows que *o lpszIconName* especifica.

```
HICON LoadStandardIcon(LPCTSTR lpszIconName) const;
```

### <a name="parameters"></a>Parâmetros

*lpszIconName*<br/>
Um identificador constante manifesto que especifica um ícone predefinido do Windows. Esses identificadores são definidos no WINDOWS. H. Para obter uma lista dos possíveis valores predefinidos e suas descrições, consulte o parâmetro *lpIconName* no [LoadIcon](/windows/win32/api/winuser/nf-winuser-loadiconw) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Uma alça para um ícone se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use `LoadStandardIcon` a função de membro [loadoemicon](#loadoemicon) para acessar os ícones predefinidos do Windows.

## <a name="cwinapploadstdprofilesettings"></a><a name="loadstdprofilesettings"></a>CWinApp::Configurações de perfil loadStd

Chame essa função de membro de dentro da função membro [InitInstance](#initinstance) para habilitar e carregar a lista dos arquivos MRU (Mais recentemente usados) e o último estado de visualização.

```
void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);
```

### <a name="parameters"></a>Parâmetros

*nMaxMRU*<br/>
O número de arquivos usados recentemente para rastrear.

### <a name="remarks"></a>Comentários

Se *nMaxMRU* for 0, nenhuma lista MRU será mantida.

## <a name="cwinappm_bhelpmode"></a><a name="m_bhelpmode"></a>CWinApp::m_bHelpMode

TRUE se o aplicativo estiver no modo de contexto de Ajuda (convencionalmente invocado com SHIFT + F1); caso contrário, FALSO.

```
BOOL m_bHelpMode;
```

### <a name="remarks"></a>Comentários

No modo de contexto de Ajuda, o cursor se torna um ponto de interrogação e o usuário pode movê-lo sobre a tela. Examine este sinalizador se quiser implementar um manuseio especial quando estiver no modo Ajuda. `m_bHelpMode`é uma variável pública do tipo BOOL.

## <a name="cwinappm_dwrestartmanagersupportflags"></a><a name="m_dwrestartmanagersupportflags"></a>CwinApp::m_dwRestartManagerSupportFlags

Sinalizadores que determinam como o gerenciador de reinicialização se comporta.

```
DWORD m_dwRestartManagerSupportFlags;
```

### <a name="remarks"></a>Comentários

Para ativar o gerenciador de reinicialização, defina `m_dwRestartManagerSupportFlags` o comportamento que deseja. A tabela a seguir mostra as bandeiras disponíveis.

|||
|-|-|
|Sinalizador|Descrição|
|AFX_RESTART_MANAGER_SUPPORT_RESTART|O aplicativo é registrado usando [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager). O gerenciador de reinicialização é responsável por reiniciar o aplicativo se ele sair inesperadamente.|
|- AFX_RESTART_MANAGER_SUPPORT_RECOVERY|O aplicativo é registrado no gerenciador de reinicialização e o gerenciador de reinicialização chama a função de retorno de chamada de recuperação quando ele reinicia o aplicativo. A função de retorno de chamada de recuperação padrão é [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|
|- AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART.|O save automático está ativado e o gerenciador de reinicialização salva automaticamente todos os documentos abertos quando o aplicativo é reiniciado.|
|AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL|O save automático está ativado e o gerenciador de reinicialização salva automaticamente quaisquer documentos abertos em um intervalo regular. O intervalo é definido por [CWinApp::m_nAutosaveInterval](#m_nautosaveinterval).|
|AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES|O gerenciador de reinicialização abre documentos previamente abertos depois de reiniciar o aplicativo a partir de uma saída inesperada. A [Classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md) lida com o armazenamento da lista de documentos abertos e restaurá-los.|
|AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES|O gerenciador de reinicialização solicita ao usuário que restaure arquivos salvos automaticamente após reiniciar o aplicativo. A `CDataRecoveryHandler` classe consulta o usuário.|
|- AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE|A união de AFX_RESTART_MANAGER_SUPPORT_RESTART, AFX_RESTART_MANAGER_SUPPORT_RECOVER e AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES.|
|AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS.|A união de AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART, AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL e AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES.|
|- AFX_RESTART_MANAGER_SUPPORT_RESTART_ASPECTS|A união de AFX_RESTART_MANAGER_SUPPORT_RESTART, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES e AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES.|
|- AFX_RESTART_MANAGER_SUPPORT_RECOVERY_ASPECTS|O sindicato ofAFX_RESTART_MANAGER_SUPPORT_RECOVERY, AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES e AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES.|

## <a name="cwinappm_ehelptype"></a><a name="m_ehelptype"></a>CWinApp::m_eHelpType

O tipo deste membro de dados é o tipo enumerado AFX_HELP_TYPE, que é definido dentro da `CWinApp` classe.

```
AFX_HELP_TYPE m_eHelpType;
```

### <a name="remarks"></a>Comentários

A enumeração AFX_HELP_TYPE é definida da seguinte forma:

```
enum AFX_HELP_TYPE {
    afxWinHelp = 0,
    afxHTMLHelp = 1
    };
```

- Para definir a ajuda do aplicativo como ajuda HTML, ligue para [SetHelpMode](#sethelpmode) e especifique `afxHTMLHelp`.

- Para definir a ajuda do aplicativo `SetHelpMode` no `afxWinHelp`WinHelp, ligue e especifique .

## <a name="cwinappm_hinstance"></a><a name="m_hinstance"></a>CwinApp::m_hInstance

Corresponde ao parâmetro *hInstance* passado pelo `WinMain`Windows para .

```
HINSTANCE m_hInstance;
```

### <a name="remarks"></a>Comentários

O `m_hInstance` membro de dados é um cabo para a instância atual do aplicativo em execução no Windows. Isso é retornado pela função global [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle). `m_hInstance`é uma variável pública do tipo HINSTANCE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#55](../../mfc/reference/codesnippet/cpp/cwinapp-class_15.cpp)]

## <a name="cwinappm_lpcmdline"></a><a name="m_lpcmdline"></a>CWinApp::m_lpCmdLine

Corresponde ao parâmetro *lpCmdLine* passado pelo `WinMain`Windows para .

```
LPTSTR m_lpCmdLine;
```

### <a name="remarks"></a>Comentários

Aponta para uma seqüência de terminadas nula que especifica a linha de comando para o aplicativo. Use `m_lpCmdLine` para acessar quaisquer argumentos de linha de comando que o usuário inseriu quando o aplicativo foi iniciado. `m_lpCmdLine`é uma variável pública do tipo LPTSTR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#52](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]

## <a name="cwinappm_nautosaveinterval"></a><a name="m_nautosaveinterval"></a>CWinApp::m_nAutosaveInterval

O tempo entre os salvamentos automáticos.

```
int m_nAutosaveInterval;
```

### <a name="remarks"></a>Comentários

Você pode configurar o gerenciador de reinicialização para salvar automaticamente documentos abertos em intervalos definidos. Se o aplicativo não salvar automaticamente os arquivos, este parâmetro não tem efeito.

## <a name="cwinappm_ncmdshow"></a><a name="m_ncmdshow"></a>CWinApp::m_nCmdShow

Corresponde ao parâmetro *nCmdShow* passado pelo `WinMain`Windows para .

```
int m_nCmdShow;
```

### <a name="remarks"></a>Comentários

Você deve `m_nCmdShow` passar como um argumento ao chamar [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow) para a janela principal do aplicativo. `m_nCmdShow`é uma variável pública de tipo **int**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#56](../../mfc/reference/codesnippet/cpp/cwinapp-class_17.cpp)]

## <a name="cwinappm_pactivewnd"></a><a name="m_pactivewnd"></a>CWinApp::m_pActiveWnd

Use este membro de dados para armazenar um ponteiro na janela principal do aplicativo de contêiner OLE que tem seu aplicativo de servidor OLE ativado no local.

### <a name="remarks"></a>Comentários

Se esse membro de dados for NULO, o aplicativo não estiver ativo no local.

O framework define essa variável de membro quando a janela do quadro está ativada por um aplicativo de contêiner OLE.

## <a name="cwinappm_pdatarecoveryhandler"></a><a name="m_pdatarecoveryhandler"></a>CwinApp::m_pDataRecoveryHandler

Ponteiro para o manipulador de recuperação de dados para o aplicativo.

```
CDataRecoveryHandler* m_pDataRecoveryHandler;
```

### <a name="remarks"></a>Comentários

O manipulador de recuperação de dados de um aplicativo monitora documentos abertos e os salva automaticamente. A estrutura usa o manipulador de recuperação de dados para restaurar arquivos salvos automaticamente quando um aplicativo é reiniciado depois que ele sai inesperadamente. Para obter mais informações, consulte [CDataRecoveryHandler Class](../../mfc/reference/cdatarecoveryhandler-class.md).

## <a name="cwinappm_pszappname"></a><a name="m_pszappname"></a>CWinApp::m_pszAppName

Especifica o nome do aplicativo.

```
LPCTSTR m_pszAppName;
```

### <a name="remarks"></a>Comentários

O nome do aplicativo pode vir do parâmetro passado para o construtor [CWinApp,](#cwinapp) ou, se não especificado, para a seqüência de recursos com o ID de AFX_IDS_APP_TITLE. Se o nome do aplicativo não for encontrado no recurso, ele vem do programa . Nome de arquivo EXE.

Retornado pela função global [AfxGetAppName](application-information-and-management.md#afxgetappname). `m_pszAppName`é uma variável pública de tipo **const char**<strong>\*</strong>.

> [!NOTE]
> Se você atribuir um `m_pszAppName`valor a , ele deve ser alocado dinamicamente no heap. O `CWinApp` destruidor liga **gratuitamente**( ) com este ponteiro. Vocês muitos querem `_tcsdup`usar a função de biblioteca de tempo de execução para fazer a alocação. Além disso, liberte a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#57](../../mfc/reference/codesnippet/cpp/cwinapp-class_18.cpp)]

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#65](../../mfc/reference/codesnippet/cpp/cwinapp-class_19.cpp)]

## <a name="cwinappm_pszexename"></a><a name="m_pszexename"></a>CwinApp::m_pszExeName

Contém o nome do arquivo executável do aplicativo sem uma extensão.

```
LPCTSTR m_pszExeName;
```

### <a name="remarks"></a>Comentários

Ao contrário [de m_pszAppName,](#m_pszappname)este nome não pode conter espaços em branco. `m_pszExeName`é uma variável pública de tipo **const char**<strong>\*</strong>.

> [!NOTE]
> Se você atribuir um `m_pszExeName`valor a , ele deve ser alocado dinamicamente no heap. O `CWinApp` destruidor liga **gratuitamente**( ) com este ponteiro. Vocês muitos querem `_tcsdup`usar a função de biblioteca de tempo de execução para fazer a alocação. Além disso, liberte a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#58](../../mfc/reference/codesnippet/cpp/cwinapp-class_20.cpp)]

## <a name="cwinappm_pszhelpfilepath"></a><a name="m_pszhelpfilepath"></a>CWinApp::m_pszHelpFilePath

Contém o caminho para o arquivo de ajuda do aplicativo.

```
LPCTSTR m_pszHelpFilePath;
```

### <a name="remarks"></a>Comentários

Por padrão, o framework `m_pszHelpFilePath` inicializa para o nome do aplicativo com ". HLP" anexado. Para alterar o nome do `m_pszHelpFilePath` arquivo de ajuda, defina para apontar para uma seqüência que contém o nome completo do arquivo de ajuda desejado. Um lugar conveniente para fazer isso está na função [InitInstance](#initinstance) do aplicativo. `m_pszHelpFilePath`é uma variável pública de tipo **const char**<strong>\*</strong>.

> [!NOTE]
> Se você atribuir um `m_pszHelpFilePath`valor a , ele deve ser alocado dinamicamente no heap. O `CWinApp` destruidor liga **gratuitamente**( ) com este ponteiro. Vocês muitos querem `_tcsdup`usar a função de biblioteca de tempo de execução para fazer a alocação. Além disso, liberte a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#59](../../mfc/reference/codesnippet/cpp/cwinapp-class_21.cpp)]

## <a name="cwinappm_pszprofilename"></a><a name="m_pszprofilename"></a>CWinApp::m_pszProfileName

Contém o nome do aplicativo. Arquivo INI.

```
LPCTSTR m_pszProfileName;
```

### <a name="remarks"></a>Comentários

`m_pszProfileName`é uma variável pública de tipo **const char**<strong>\*</strong>.

> [!NOTE]
> Se você atribuir um `m_pszProfileName`valor a , ele deve ser alocado dinamicamente no heap. O `CWinApp` destruidor liga **gratuitamente**( ) com este ponteiro. Vocês muitos querem `_tcsdup`usar a função de biblioteca de tempo de execução para fazer a alocação. Além disso, liberte a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#60](../../mfc/reference/codesnippet/cpp/cwinapp-class_22.cpp)]

## <a name="cwinappm_pszregistrykey"></a><a name="m_pszregistrykey"></a>CWinApp::m_pszRegistryKey

Usado para determinar onde, no registro ou no arquivo INI, as configurações do perfil do aplicativo são armazenadas.

```
LPCTSTR m_pszRegistryKey;
```

### <a name="remarks"></a>Comentários

Normalmente, esse membro de dados é tratado apenas como leitura.

- O valor é armazenado em uma chave de registro. O nome para a configuração do perfil do aplicativo é anexado à seguinte chave de registro: HKEY_CURRENT_USER/Software/LocalAppWizard-Gerado/.

Se você atribuir um `m_pszRegistryKey`valor a , ele deve ser alocado dinamicamente no heap. O `CWinApp` destruidor liga **gratuitamente**( ) com este ponteiro. Vocês muitos querem `_tcsdup`usar a função de biblioteca de tempo de execução para fazer a alocação. Além disso, liberte a memória associada ao ponteiro atual antes de atribuir um novo valor. Por exemplo:

[!code-cpp[NVC_MFCWindowing#61](../../mfc/reference/codesnippet/cpp/cwinapp-class_23.cpp)]

## <a name="cwinappm_pszappid"></a><a name="m_pszappid"></a>CWinApp::m_pszAppID

ID do modelo do usuário do aplicativo.

```
LPCTSTR m_pszAppID;
```

### <a name="remarks"></a>Comentários

## <a name="cwinapponcontexthelp"></a><a name="oncontexthelp"></a>CwinApp::OnContextHelp

Lida com shift+F1 Ajuda dentro do aplicativo.

```
afx_msg void OnContextHelp();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_CONTEXT_HELP, OnContextHelp )` adicionar uma `CWinApp` declaração ao seu mapa de mensagens de classe e também adicionar uma entrada de tabela do acelerador, normalmente SHIFT+F1, para habilitar essa função de membro.

`OnContextHelp`coloca o aplicativo no modo Ajuda. O cursor muda para uma seta e um ponto de interrogação, e o usuário pode mover o ponteiro do mouse e pressionar o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Esta função de membro recupera o contexto de ajuda do objeto sob o cursor e chama a função do Windows WinHelp com esse contexto de Ajuda.

## <a name="cwinapponddecommand"></a><a name="onddecommand"></a>CWinApp::OnDDECommand

Chamada pela estrutura quando a janela do quadro principal recebe uma mensagem de execução do DDE.

```
virtual BOOL OnDDECommand(LPTSTR lpszCommand);
```

### <a name="parameters"></a>Parâmetros

*lpszCommand*<br/>
Aponta para uma seqüência de comando DDE recebida pelo aplicativo.

### <a name="return-value"></a>Valor retornado

Não zero se o comando for manuseado; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão verifica se o comando é uma solicitação para abrir um documento e, se for o caso, abre o documento especificado. O Gerenciador de Arquivos do Windows geralmente envia essas seqüências de comando DDE quando o usuário clica duas vezes em um arquivo de dados. Substituir esta função para lidar com outros comandos de execução do DDE, como o comando a ser impresso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#48](../../mfc/reference/codesnippet/cpp/cwinapp-class_24.cpp)]

## <a name="cwinapponfilenew"></a><a name="onfilenew"></a>CWinApp::OnFileNew

Implementa o comando ID_FILE_NEW.

```
afx_msg void OnFileNew();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_FILE_NEW, OnFileNew )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. Se ativada, esta função lida com a execução do comando File New.

Consulte [a Nota Técnica 22](../../mfc/tn022-standard-commands-implementation.md) para obter informações sobre o comportamento padrão e orientações sobre como substituir essa função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]

[!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]

## <a name="cwinapponfileopen"></a><a name="onfileopen"></a>CWinApp::OnFileOpen

Implementa o comando ID_FILE_OPEN.

```
afx_msg void OnFileOpen();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_FILE_OPEN, OnFileOpen )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. Se ativada, esta função lida com a execução do comando File Open.

Para obter informações sobre comportamento padrão e orientação sobre como substituir essa função de membro, consulte [Nota Técnica 22](../../mfc/tn022-standard-commands-implementation.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]

[!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]

## <a name="cwinapponfileprintsetup"></a><a name="onfileprintsetup"></a>CWinApp::OnFilePrintSetup

Implementa o comando ID_FILE_PRINT_SETUP.

```
afx_msg void OnFilePrintSetup();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_FILE_PRINT_SETUP, OnFilePrintSetup )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. Se ativada, esta função manipula a execução do comando File Print.

Para obter informações sobre comportamento padrão e orientação sobre como substituir essa função de membro, consulte [Nota Técnica 22](../../mfc/tn022-standard-commands-implementation.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]

[!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]

## <a name="cwinapponhelp"></a><a name="onhelp"></a>CwinApp::OnHelp

Lida com a Ajuda f1 dentro do aplicativo (usando o contexto atual).

```
afx_msg void OnHelp();
```

### <a name="remarks"></a>Comentários

Normalmente você também adicionará uma entrada de chave de acelerador para a tecla F1. Habilitar a chave da F-1 é apenas uma convenção, não um requisito.

Você deve `ON_COMMAND( ID_HELP, OnHelp )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. Se ativado, chamado pelo framework quando o usuário pressionar a tecla F1.

A implementação padrão desta função de manipulador de mensagens determina o contexto de Ajuda que corresponde à janela atual, caixa de diálogo ou item de menu e, em seguida, chama WINHELP. Exe. Se não houver contexto disponível no momento, a função usará o contexto padrão.

Substituir essa função de membro para definir o contexto de Ajuda para algo que não seja a janela, caixa de diálogo, item do menu ou botão de barra de ferramentas que atualmente tem o foco. Ligue `WinHelp` com o ID de contexto de ajuda desejado.

## <a name="cwinapponhelpfinder"></a><a name="onhelpfinder"></a>CwinApp::OnHelpFinder

Cuida dos comandos ID_HELP_FINDER e ID_DEFAULT_HELP.

```
afx_msg void OnHelpFinder();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_HELP_FINDER, OnHelpFinder )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. Se ativado, a estrutura chama essa função de manipulador de mensagens quando `WinHelp` o usuário do aplicativo seleciona o comando Help Finder para invocar com o tópico **padrão HELP_FINDER.**

## <a name="cwinapponhelpindex"></a><a name="onhelpindex"></a>CWinApp::OnHelpIndex

Lida com o comando ID_HELP_INDEX e fornece um tópico de Ajuda padrão.

```
afx_msg void OnHelpIndex();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_HELP_INDEX, OnHelpIndex )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. Se ativado, o framework chama essa função de manipulador de mensagens quando `WinHelp` o usuário do aplicativo seleciona o comando Índice de ajuda para invocar com o tópico **padrão HELP_INDEX.**

## <a name="cwinapponhelpusing"></a><a name="onhelpusing"></a>CwinApp::OnHelpusing

Controla o comando ID_HELP_USING.

```
afx_msg void OnHelpUsing();
```

### <a name="remarks"></a>Comentários

Você deve `ON_COMMAND( ID_HELP_USING, OnHelpUsing )` adicionar uma `CWinApp` declaração ao seu mapa de mensagem de classe para ativar essa função de membro. A estrutura chama essa função de manipulador de mensagens quando o `WinHelp` usuário do seu aplicativo seleciona o comando Ajuda Usando para invocar o aplicativo com o tópico **padrão HELP_HELPONHELP.**

## <a name="cwinapponidle"></a><a name="onidle"></a>CwinApp::Onidle

Substituir essa função de membro para executar o processamento de tempo ocioso.

```
virtual BOOL OnIdle(LONG lCount);
```

### <a name="parameters"></a>Parâmetros

*Lcount*<br/>
Um contador incrementado cada vez `OnIdle` é chamado quando a fila de mensagens do aplicativo está vazia. Esta contagem é redefinida para 0 cada vez que uma nova mensagem é processada. Você pode usar o parâmetro *lCount* para determinar o tempo relativo que o aplicativo ficou ocioso sem processar uma mensagem.

### <a name="return-value"></a>Valor retornado

Não zero para receber mais tempo de processamento ocioso; 0 se não for necessário mais tempo ocioso.

### <a name="remarks"></a>Comentários

`OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do aplicativo está vazia. Use sua substituição para chamar suas próprias tarefas de manipulador ocioso de fundo.

`OnIdle`deve retornar 0 para indicar que não é necessário tempo de processamento ocioso. O parâmetro *iCount* é incrementado cada vez `OnIdle` que é chamado quando a fila de mensagens está vazia e reinicia para 0 cada vez que uma nova mensagem é processada. Você pode chamar suas diferentes rotinas ociosas com base nesta contagem.

O seguinte resume o processamento de loop ocioso:

1. Se o loop de mensagem na Biblioteca de Classes da Microsoft Foundation `OnIdle` verificar a fila de mensagens e não encontrar mensagens pendentes, ele solicitará o objeto do aplicativo e fornece 0 como o argumento *lCount.*

2. `OnIdle`realiza algum processamento e retorna um valor não zero para indicar que deve ser chamado novamente para fazer mais processamento.

3. O loop de mensagem verifica novamente a fila da mensagem. Se nenhuma mensagem estiver `OnIdle` pendente, ela liga novamente, incrementando o *argumento lCount.*

4. Eventualmente, `OnIdle` termina o processamento de todas as suas tarefas ociosas e retorna 0. Isso diz ao loop `OnIdle` de mensagem para parar de ligar até que a próxima mensagem seja recebida da fila de mensagens, momento em que o ciclo ocioso é reiniciado com o argumento definido como 0.

Não execute tarefas `OnIdle` longas durante porque seu `OnIdle` aplicativo não pode processar a entrada do usuário até que retorne.

> [!NOTE]
> A implementação `OnIdle` padrão de atualizações comanda objetos de interface do usuário, como itens de menu e botões de barra de ferramentas, e executa a limpeza da estrutura de dados internas. Portanto, se você `OnIdle`substituir, você `CWinApp::OnIdle` deve `lCount` ligar com a versão substituída. Primeiro chame todo o processamento ocioso da `OnIdle` classe base (isto é, até que a classe base retorne 0). Se você precisar executar o trabalho antes que o processamento da classe base seja concluído, revise a implementação da classe base para selecionar o *lCount* adequado durante o qual fazer seu trabalho.

Se você não `OnIdle` quiser ser chamado sempre que uma mensagem for recuperada da fila de mensagens, você pode substituir o [CWinThreadIsIdleMessage](../../mfc/reference/cwinthread-class.md#isidlemessage). Se um aplicativo tiver definido um temporizador muito curto, `OnIdle` ou se o sistema estiver enviando a mensagem WM_SYSTIMER, então será chamado repetidamente e degradará o desempenho.

### <a name="example"></a>Exemplo

Os dois exemplos a seguir `OnIdle`mostram como usar . O primeiro exemplo processa duas tarefas ociosas usando o argumento *lCount* para priorizar as tarefas. A primeira tarefa é de alta prioridade, e você deve fazê-lo sempre que possível. A segunda tarefa é menos importante e deve ser feita apenas quando houver uma longa pausa na entrada do usuário. Observe a chamada para a `OnIdle`versão de classe base de . O segundo exemplo gerencia um grupo de tarefas ociosas com diferentes prioridades.

[!code-cpp[NVC_MFCWindowing#51](../../mfc/reference/codesnippet/cpp/cwinapp-class_27.cpp)]

## <a name="cwinappopendocumentfile"></a><a name="opendocumentfile"></a>CWinApp::Abrir arquivo de documentos

A estrutura chama esse método para abrir o arquivo [CDocument](../../mfc/reference/cdocument-class.md) chamado para o aplicativo.

```
virtual CDocument* OpenDocumentFile(
    LPCTSTR lpszFileName
    BOOL bAddToMRU = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
[em] O nome do arquivo a ser aberto.

*bAddToMRU*<br/>
[em] TRUE indica que o documento é um dos arquivos mais recentes; FALSE indica que o documento não é um dos arquivos mais recentes.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CDocument` para um se bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se um documento que tiver esse nome já estiver aberto, a primeira janela de quadro que contenha esse documento terá o foco. Se um aplicativo suportar vários modelos de documento, a estrutura usará a extensão do nome do arquivo para encontrar o modelo de documento apropriado para tentar carregar o documento. Se for bem-sucedido, o modelo de documento cria uma janela de quadro e exibição para o documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#52](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]

## <a name="cwinappparsecommandline"></a><a name="parsecommandline"></a>CWinApp::ParseCommandLine

Ligue para esta função de membro para analisar a linha de comando e enviar os parâmetros, um de cada vez, para [CCommandLineInfo::ParseParam](../../mfc/reference/ccommandlineinfo-class.md#parseparam).

```
void ParseCommandLine(CCommandLineInfo& rCmdInfo);
```

### <a name="parameters"></a>Parâmetros

*rCmdInfo*<br/>
Uma referência a um objeto [CCommandLineInfo.](../../mfc/reference/ccommandlineinfo-class.md)

### <a name="remarks"></a>Comentários

Quando você inicia um novo projeto de MFC usando o Assistente `CCommandLineInfo`de aplicativo, o Assistente de aplicativo criará uma instância local de , e então chamará `ProcessShellCommand` e `ParseCommandLine` na função de membro [InitInstance.](#initinstance) Uma linha de comando segue a rota descrita abaixo:

1. Depois de ser `InitInstance`criado `CCommandLineInfo` em , `ParseCommandLine`o objeto é passado para .

2. `ParseCommandLine`em `CCommandLineInfo::ParseParam` seguida, chama repetidamente, uma vez para cada parâmetro.

3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é então passado para [ProcessShellCommand](#processshellcommand).

4. `ProcessShellCommand`lida com os argumentos e bandeiras da linha de comando.

Observe que você `ParseCommandLine` pode ligar diretamente conforme necessário.

Para obter uma descrição dos sinalizadores de linha de comando, consulte [CCommandLineInfo::m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand).

## <a name="cwinapppretranslatemessage"></a><a name="pretranslatemessage"></a>CWinApp::PreTraduzirmensagem

Anular essa função para filtrar mensagens de janela antes de serem enviadas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) A implementação padrão executa a tradução com chave do acelerador, portanto, você deve chamar a `CWinApp::PreTranslateMessage` função de membro em sua versão substituída.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Um ponteiro para uma estrutura [MSG](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser processada.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem `PreTranslateMessage` foi totalmente processada e não deve ser processada mais adiante. Zero se a mensagem deve ser processada da maneira normal.

## <a name="cwinappprocessmessagefilter"></a><a name="processmessagefilter"></a>CWinApp::ProcessMessageFilter

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
Um ponteiro para uma tructura [Windows MSG.](/windows/win32/api/winuser/ns-winuser-msg)

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem for processada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma função de gancho processa eventos antes de serem enviados para o processamento normal de mensagens do aplicativo.

Se você substituir esse recurso avançado, certifique-se de chamar a versão de classe base para manter o processamento de ganchos da estrutura.

## <a name="cwinappprocessshellcommand"></a><a name="processshellcommand"></a>CWinApp::ProcessShellCommand

Essa função de membro é chamada pelo [InitInstance](#initinstance) para aceitar os parâmetros passados do `CCommandLineInfo` objeto identificado pelo *rCmdInfo*e executar a ação indicada.

```
BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);
```

### <a name="parameters"></a>Parâmetros

*rCmdInfo*<br/>
Uma referência a um objeto [CCommandLineInfo.](../../mfc/reference/ccommandlineinfo-class.md)

### <a name="return-value"></a>Valor retornado

Não zero se o comando shell for processado com sucesso. Se 0, retorne FALSO de [InitInstance](#initinstance).

### <a name="remarks"></a>Comentários

Quando você inicia um novo projeto de MFC usando o Assistente `CCommandLineInfo`de Aplicativo, o Assistente de aplicativo criará uma instância local de , e então chamará `ProcessShellCommand` e [ParseCommandLine](#parsecommandline) na `InitInstance` função de membro. Uma linha de comando segue a rota descrita abaixo:

1. Depois de ser `InitInstance`criado `CCommandLineInfo` em , `ParseCommandLine`o objeto é passado para .

2. `ParseCommandLine`em seguida, chama [CCommandLineInfo::ParseParam](../../mfc/reference/ccommandlineinfo-class.md#parseparam) repetidamente, uma vez para cada parâmetro.

3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é `ProcessShellCommand`então passado para .

4. `ProcessShellCommand`lida com os argumentos e bandeiras da linha de comando.

Os membros de `CCommandLineInfo` dados do objeto, identificados por [CCommandLineInfo::m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand), são do `CCommandLineInfo` seguinte tipo enumerado, que é definido dentro da classe.

```
enum {
    FileNew,
    FileOpen,
    FilePrint,
    FilePrintTo,
    FileDDE
    };
```

Para uma breve descrição de cada `CCommandLineInfo::m_nShellCommand`um desses valores, consulte .

## <a name="cwinappprocesswndprocexception"></a><a name="processwndprocexception"></a>CWinApp::ProcessWndProcException

A estrutura chama essa função de membro sempre que o manipulador não captura uma exceção lançada em uma das mensagens ou manipuladores de comando do aplicativo.

```
virtual LRESULT ProcessWndProcException(
    CException* e,
    const MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*e*<br/>
Um ponteiro para uma exceção não capturada.

*pMsg*<br/>
Uma [tructura MSG](/windows/win32/api/winuser/ns-winuser-msg)que contém informações sobre a mensagem do windows que fez com que a estrutura lançasse uma exceção.

### <a name="return-value"></a>Valor retornado

O valor que deve ser devolvido ao Windows. Normalmente este é 0L para mensagens de windows, 1L ( TRUE) para mensagens de comando.

### <a name="remarks"></a>Comentários

Não chame essa função de membro diretamente.

A implementação padrão desta função membro cria uma caixa de mensagem. Se a exceção não capturada se originar com uma falha de menu, barra de ferramentas ou comando do acelerador, a caixa de mensagem exibirá uma mensagem "Falha de comando"; caso contrário, ele exibe uma mensagem "Erro interno do aplicativo".

Anular essa função de membro para fornecer o manuseio global de suas exceções. Ligue apenas para a funcionalidade base se desejar que a caixa de mensagens seja exibida.

## <a name="cwinappregister"></a><a name="register"></a>CWinApp::Registrar

Executa quaisquer tarefas `RegisterShellFileTypes`de registro não tratadas por .

```
virtual BOOL Register();
```

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão simplesmente retorna TRUE. Anular esta função para fornecer quaisquer etapas de registro personalizadas.

## <a name="cwinappregistershellfiletypes"></a><a name="registershellfiletypes"></a>CWinApp::RegistrarshellArquivos de arquivos

Ligue para esta função de membro para registrar todos os tipos de documentos do seu aplicativo com o Gerenciador de Arquivos do Windows.

```
void RegisterShellFileTypes(BOOL bCompat = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCompat*<br/>
[em] True adiciona entradas de registro para comandos shell Imprimir e imprimir para, permitindo que um usuário imprima arquivos diretamente do shell ou arrastando o arquivo para um objeto de impressora. Ele também adiciona uma chave DefaultIcon. Por padrão, este parâmetro é FALSO para compatibilidade retrógrada.

### <a name="remarks"></a>Comentários

Isso permite que o usuário abra um arquivo de dados criado pelo seu aplicativo clicando duas vezes nele dentro do Gerenciador de arquivos. Ligue `RegisterShellFileTypes` depois de chamar [AddDocTemplate](#adddoctemplate) para cada um dos modelos de documento em seu aplicativo. Também chame a função de membro `RegisterShellFileTypes` [EnableShellOpen](#enableshellopen) quando você chamar .

`RegisterShellFileTypes`itera através da lista de objetos [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) que o aplicativo mantém e, para cada modelo de documento, adiciona entradas ao banco de dados de registro que o Windows mantém para associações de arquivos. O Gerenciador de arquivos usa essas entradas para abrir um arquivo de dados quando o usuário clica duas vezes nele. Isso elimina a necessidade de enviar um . Arquivo REG com sua aplicação.

> [!NOTE]
> `RegisterShellFileTypes`só funciona se o usuário executa o programa com direitos de administrador. Se o programa não tiver direitos de administrador, ele não poderá alterar as chaves do registro.

Se o banco de dados de registro já associar uma determinada extensão de nome de arquivo com outro tipo de arquivo, nenhuma nova associação será criada. Consulte `CDocTemplate` a classe para o formato de strings necessáriopara registrar essas informações.

## <a name="cwinappregisterwithrestartmanager"></a><a name="registerwithrestartmanager"></a>CWinApp::RegistrarComReiniciarManager

Registra o aplicativo com o gerenciador de reinicialização.

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
|*bRegisterRecoveryCallback*|[em] TRUE indica que esta instância do aplicativo usa uma função de retorno de chamada de recuperação; FALSE indica que não. O framework chama a função de retorno de chamada de recuperação quando o aplicativo sai inesperadamente. Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|
|*strRestartIdentifier*|[em] A seqüência exclusiva que identifica esta instância do gerenciador de reinicialização. O identificador de gerenciador de reinicialização é único para cada instância de um aplicativo.|
|*pwzCommandLineArgs*|[em] Uma seqüência que contém quaisquer argumentos extras da linha de comando.|
|*dwRestartFlags*|[em] Sinalizadores opcionais para o gerenciador de reinicialização. Para obter mais informações, consulte a seção Comentários.|
|*pRecoveryCallback*|[em] A função de retorno de chamada de recuperação. Esta função deve tomar um parâmetro LPVOID como entrada e retornar um DWORD. A função de retorno `CWinApp::ApplicationRecoveryCallback`de chamada de recuperação padrão é .|
|*lpvParam*|[em] O parâmetro de entrada para a função de retorno de chamada de recuperação. Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|
|*dwPingInterval*|[em] O tempo que o gerenciador de reinicialização espera para que a função de retorno de chamada de recuperação retorne. Este parâmetro é em milissegundos.|
|*dwCallbackFlags*|[em] Os sinalizadores passaram para a função de retorno de chamada de recuperação. Reservado para uso futuro.|

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

Se o aplicativo usar a implementação padrão do MFC para `RegisterWithRestartManager`arquivos de salvamento automático, você deve usar a versão simples de . Use a versão `RegisterWithRestartManager` complexa de se você quiser personalizar o comportamento de salvamento automático do seu aplicativo.

Se você chamar esse método com uma seqüência vazia para *strRestartIdentifier,* `RegisterWithRestartManager` criará uma seqüência de identificador exclusiva para esta instância do gerenciador de reinicialização.

Quando um aplicativo sai inesperadamente, o gerenciador de reinicialização reinicia o aplicativo a partir da linha de comando e fornece o identificador de reinicialização exclusivo como um argumento opcional. Nesse cenário, o `RegisterWithRestartManager` quadro liga duas vezes. A primeira chamada vem de [CWinApp::InitInstance](#initinstance) com uma seqüência vazia para o identificador de string. Em seguida, o método [CWinApp::ProcessShellCommand](#processshellcommand) chama `RegisterWithRestartManager` com o identificador de reinicialização exclusivo.

Depois de registrar um aplicativo com o gerenciador de reinicialização, o gerenciador de reinicialização monitora o aplicativo. Se o aplicativo sair inesperadamente, o gerenciador de reinicialização chamará a função de retorno de chamada de recuperação durante o processo de desligamento. O gerenciador de reinicialização aguarda o *dwPingInterval* para obter uma resposta da função de retorno de chamada de recuperação. Se a função de retorno de chamada de recuperação não responder dentro desse tempo, o aplicativo sairá sem executar a função de retorno de chamada de recuperação.

Por padrão, os dwRestartFlags não são suportados, mas são fornecidos para uso futuro. Os valores possíveis para *dwRestartFlags* são os seguintes:

- RESTART_NO_CRASH

- RESTART_NO_HANG

- RESTART_NO_PATCH

- RESTART_NO_REBOOT

## <a name="cwinappreopenpreviousfilesatrestart"></a><a name="reopenpreviousfilesatrestart"></a>Cwinapp::Reabrearquivos anterioresnareinicialização

Determina se o gerenciador de reinicialização reabre os arquivos que estavam abertos quando o aplicativo saiu inesperadamente.

```
virtual BOOL ReopenPreviousFilesAtRestart() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o gerenciador de reinicialização reabre os arquivos abertos anteriormente; FALSE indica que o gerenciador de reinicialização não.

## <a name="cwinapprestartinstance"></a><a name="restartinstance"></a>CWinApp::ReinicializaçãoInstância

Lida com uma reinicialização de aplicativo iniciada pelo gerenciador de reinicialização.

```
virtual BOOL CWinApp::RestartInstance();
```

### <a name="return-value"></a>Valor retornado

TRUE se o manipulador de recuperação de dados abrir documentos previamente abertos; FALSO se o manipulador de recuperação de dados tiver um erro ou se não houver documentos abertos anteriormente.

### <a name="remarks"></a>Comentários

Quando o gerenciador de reinicialização reinicia um aplicativo, a estrutura chama esse método. Este método recupera o manipulador de recuperação de dados e restaura os arquivos salvos automaticamente. Este método chama [CDataRecoveryHandler::RestoreAutosavedDocuments](../../mfc/reference/cdatarecoveryhandler-class.md#restoreautosaveddocuments) para determinar se o usuário deseja restaurar os arquivos salvos automaticamente.

Este método retorna FALSO se o [CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md) determinar que não havia documentos abertos. Se não houver documentos abertos, a solicitação começa normalmente.

## <a name="cwinapprestoreautosavedfilesatrestart"></a><a name="restoreautosavedfilesatrestart"></a>CWinApp::RestaurarArquivos salvos automáticosRereiniciar

Determina se o gerenciador de reinicialização restaura os arquivos salvos automaticamente quando ele reinicia o aplicativo.

```
virtual BOOL RestoreAutosavedFilesAtRestart() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o gerenciador de reinicialização restaura arquivos salvos automaticamente; FALSE indica que o gerenciador de reinicialização não.

## <a name="cwinapprun"></a><a name="run"></a>CWinApp::Execução

Fornece um loop de mensagem padrão.

```
virtual int Run();
```

### <a name="return-value"></a>Valor retornado

Um valor **int** que `WinMain`é devolvido por .

### <a name="remarks"></a>Comentários

`Run`adquire e despacha mensagens do Windows até que o aplicativo receba uma mensagem WM_QUIT. Se a fila de mensagens do aplicativo `Run` não contiver mensagens no momento, ligue para [o OnIdle](#onidle) para realizar o processamento de tempo ocioso. As mensagens recebidas vão para a função de membro [PreTranslateMessage](#pretranslatemessage) para processamento especial e, em seguida, para a função `TranslateMessage` Windows para tradução padrão do teclado; finalmente, `DispatchMessage` a função Windows é chamada.

`Run`raramente é substituído, mas você pode substituí-lo para fornecer comportamento especial.

## <a name="cwinapprunautomated"></a><a name="runautomated"></a>CWinApp::RunAutomated

Ligue para esta função para determinar se a opção " **/Automação**" ou " **Automação**" está presente, o que indica se o aplicativo do servidor foi lançado por um aplicativo cliente.

```
BOOL RunAutomated();
```

### <a name="return-value"></a>Valor retornado

Não zero se a opção foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se estiver presente, a opção é removida da linha de comando. Para obter mais informações sobre a Automação OLE, consulte o artigo [Servidores de Automação](../../mfc/automation-servers.md).

## <a name="cwinapprunembedded"></a><a name="runembedded"></a>CWinApp::RunEmbedded

Ligue para esta função para determinar se a opção " **/Incorporando**" ou " **Incorporando**" está presente, o que indica se o aplicativo do servidor foi lançado por um aplicativo cliente.

```
BOOL RunEmbedded();
```

### <a name="return-value"></a>Valor retornado

Não zero se a opção foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se estiver presente, a opção é removida da linha de comando. Para obter mais informações sobre incorporação, consulte o artigo [Servidores: Implementando um Servidor](../../mfc/servers-implementing-a-server.md).

## <a name="cwinappsaveallmodified"></a><a name="saveallmodified"></a>Cwinapp::SaveAllModified

Chamado pela estrutura para salvar todos os documentos quando a janela principal do quadro do aplicativo deve ser fechada, ou através de uma mensagem WM_QUERYENDSESSION.

```
virtual BOOL SaveAllModified();
```

### <a name="return-value"></a>Valor retornado

Não zero se for seguro para encerrar a aplicação; 0 se não for seguro para encerrar a aplicação.

### <a name="remarks"></a>Comentários

A implementação padrão desta função membro chama a função [CDocument::SaveModified](../../mfc/reference/cdocument-class.md#savemodified) member, por sua vez, para todos os documentos modificados dentro do aplicativo.

## <a name="cwinappselectprinter"></a><a name="selectprinter"></a>CWinApp::SelectPrinter

Chame esta função de membro para selecionar uma impressora específica e libere a impressora que foi previamente selecionada na caixa Imprimir diálogo.

```
void SelectPrinter(
    HANDLE hDevNames,
    HANDLE hDevMode,
    BOOL bFreeOld = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Hdevnames*<br/>
Uma alça para uma tructure [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames)que identifica os nomes da porta de driver, dispositivo e saída de uma impressora específica.

*Hdevmode*<br/>
Uma alça para uma estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) que especifica informações sobre a inicialização do dispositivo e o ambiente de uma impressora.

*bFreeOld*<br/>
Libera a impressora previamente selecionada.

### <a name="remarks"></a>Comentários

Se *hDevMode* e *hDevNames* `SelectPrinter` forem NULL, use a impressora padrão atual.

## <a name="cwinappsethelpmode"></a><a name="sethelpmode"></a>CWinApp::SetHelpMode

Define o tipo de ajuda do aplicativo.

```
void SetHelpMode(AFX_HELP_TYPE eHelpType);
```

### <a name="parameters"></a>Parâmetros

*eHelpType*<br/>
Especifica o tipo de ajuda a ser usada. Consulte [CWinApp::m_eHelpType](#m_ehelptype) para obter mais informações.

### <a name="remarks"></a>Comentários

Define o tipo de ajuda do aplicativo.

Para definir o tipo de ajuda do aplicativo como HTMLHelp, você pode chamar [EnableHTMLHelp](#enablehtmlhelp). Uma vez `EnableHTMLHelp`chamada, seu aplicativo deve usar HTMLHelp como seu aplicativo de ajuda. Se você quiser mudar para usar o `SetHelpMode` WinHelp, você `afxWinHelp`pode ligar e definir *eHelpType* para .

## <a name="cwinappsetregistrykey"></a><a name="setregistrykey"></a>CWinApp::SetRegistryKey

Faz com que as configurações do aplicativo sejam armazenadas no registro em vez de arquivos INI.

```
void SetRegistryKey(LPCTSTR lpszRegistryKey);
void SetRegistryKey(UINT nIDRegistryKey);
```

### <a name="parameters"></a>Parâmetros

*lpszRegistryKey*<br/>
Ponteiro para uma seqüência contendo o nome da chave.

*nIDRegistryKey*<br/>
ID de um recurso de seqüência contendo o nome da chave de registro.

### <a name="remarks"></a>Comentários

Esta função define *m_pszRegistryKey*, que `GetProfileInt` `GetProfileString`é `WriteProfileInt`então `WriteProfileString` usado pelas `CWinApp`funções , e membros de . Se essa função tiver sido chamada, a lista de arquivos MRU (MRU) mais usados recentemente também será armazenada no registro. A chave de registro geralmente é o nome de uma empresa. Ele é armazenado em uma chave do\\ seguinte formulário: HKEY_CURRENT_USER\Software<nome da empresa<nome\> \\ \> \\ do aplicativo<nome\> \\ da seção<nome\>de valor .

## <a name="cwinappsupportsapplicationrecovery"></a><a name="supportsapplicationrecovery"></a>CWinApp::SupportsApplicationRecovery

Determina se o gerenciador de reinicialização recupera um aplicativo que saiu inesperadamente.

```
virtual BOOL SupportsApplicationRecovery() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o gerenciador de reinicialização recupera o aplicativo; FALSE indica que o gerenciador de reinicialização não.

## <a name="cwinappsupportsautosaveatinterval"></a><a name="supportsautosaveatinterval"></a>CWinApp::SuportesAutosaveAtInterval

Determina se o gerenciador de reinicialização salva automaticamente documentos abertos em um intervalo regular.

```
virtual BOOL SupportsAutosaveAtInterval() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o gerenciador de reinicialização salva automaticamente documentos abertos; FALSE indica que o gerenciador de reinicialização não.

## <a name="cwinappsupportsautosaveatrestart"></a><a name="supportsautosaveatrestart"></a>CWinApp::SuportesAutosaveAtRestart

Determina se o gerenciador de reinicialização salva automaticamente algum documento aberto quando o aplicativo é reiniciado.

```
virtual BOOL SupportsAutosaveAtRestart() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o gerenciador de reinicialização salva automaticamente documentos abertos quando o aplicativo é reiniciado; FALSE indica que o gerenciador de reinicialização não.

## <a name="cwinappsupportsrestartmanager"></a><a name="supportsrestartmanager"></a>CWinApp::SupportsRestartManager

Determina se o aplicativo suporta o gerenciador de reinicialização.

```
virtual BOOL SupportsRestartManager() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o aplicativo suporta o gerenciador de reinicialização; FALSE indica que a aplicação não.

## <a name="cwinappunregister"></a><a name="unregister"></a>CWinApp::Unregister

Desregistra todos os arquivos registrados pelo objeto do aplicativo.

```
virtual BOOL Unregister();
```

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `Unregister` função desfaz o registro realizado pelo objeto de aplicação e pela função [Registrar.](#register) Normalmente, ambas as funções são chamadas implicitamente por MFC e, portanto, não aparecerão em seu código.

Anular esta função para executar etapas personalizadas de descadastramento.

## <a name="cwinappunregistershellfiletypes"></a><a name="unregistershellfiletypes"></a>CWinApp::UnregisterShellArquivos

Chame esta função de membro para cancelar o registro de todos os tipos de documentos do aplicativo com o Gerenciador de Arquivos do Windows.

```
void UnregisterShellFileTypes();
```

## <a name="cwinappwinhelp"></a><a name="winhelp"></a>CWinApp::WinHelp

Ligue para esta função de membro para invocar o aplicativo WinHelp.

```
virtual void WinHelp(
    DWORD_PTR dwData,
    UINT nCmd = HELP_CONTEXT);
```

### <a name="parameters"></a>Parâmetros

*Dwdata*<br/>
Especifica dados adicionais. O valor utilizado depende do valor do parâmetro *nCmd.*

*nCmd*<br/>
Especifica o tipo de ajuda solicitada. Para obter uma lista de valores possíveis e como eles afetam o parâmetro *dwData,* consulte a função [WinHelp](/windows/win32/api/winuser/nf-winuser-winhelpw) Windows.

### <a name="remarks"></a>Comentários

A estrutura também chama essa função para invocar o aplicativo WinHelp.

A estrutura fechará automaticamente o aplicativo WinHelp quando seu aplicativo for encerrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#53](../../mfc/reference/codesnippet/cpp/cwinapp-class_28.cpp)]

## <a name="cwinappwriteprofilebinary"></a><a name="writeprofilebinary"></a>CWinApp::WriteProfileBinary

Chame esta função de membro para gravar dados binários na seção especificada do registro do aplicativo ou . Arquivo INI.

```
BOOL WriteProfileBinary(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPBYTE pData,
    UINT nBytes);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
Aponta para uma seqüência de terminadas nula que especifica a seção que contém a entrada. Se a seção não existe, ela é criada. O nome da seção é independente do caso; a seqüência pode ser qualquer combinação de letras maiúsculas e minúsculas.

*Lpszentry*<br/>
Aponta para uma seqüência de terminação nula que contém a entrada na qual o valor deve ser escrito. Se a entrada não existir na seção especificada, ela será criada.

*Pdata*<br/>
Aponta para os dados a serem escritos.

*Nbytes*<br/>
Contém o número de bytes a serem escritos.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

Este exemplo `CWinApp* pApp = AfxGetApp();` usa para chegar à classe CWinApp ilustrando uma maneira que `WriteProfileBinary` e `GetProfileBinary` pode ser usado a partir de qualquer função em um aplicativo MFC.

[!code-cpp[NVC_MFCWindowing#54](../../mfc/reference/codesnippet/cpp/cwinapp-class_29.cpp)]

Em outro exemplo, consulte o exemplo de [CWinApp::GetProfileBinary](#getprofilebinary).

## <a name="cwinappwriteprofileint"></a><a name="writeprofileint"></a>CWinApp::WriteProfileInt

Chame esta função de membro para escrever o valor especificado na seção especificada do registro do aplicativo ou . Arquivo INI.

```
BOOL WriteProfileInt(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    int nValue);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
Aponta para uma seqüência de terminadas nula que especifica a seção que contém a entrada. Se a seção não existe, ela é criada. O nome da seção é independente do caso; a seqüência pode ser qualquer combinação de letras maiúsculas e minúsculas.

*Lpszentry*<br/>
Aponta para uma seqüência de terminação nula que contém a entrada na qual o valor deve ser escrito. Se a entrada não existir na seção especificada, ela será criada.

*Nvalue*<br/>
Contém o valor a ser escrito.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

Este exemplo `CWinApp* pApp = AfxGetApp();` usa para chegar à classe CWinApp `WriteProfileInt` `GetProfileString`ilustrando `GetProfileInt` uma maneira que, `WriteProfileString`e pode ser usado a partir de qualquer função em um aplicativo MFC.

[!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]

Em outro exemplo, consulte o exemplo de [CWinApp::GetProfileInt](#getprofileint).

## <a name="cwinappwriteprofilestring"></a><a name="writeprofilestring"></a>CWinApp::WriteProfileString

Chame esta função de membro para escrever a seqüência especificada na seção especificada do registro do aplicativo ou . Arquivo INI.

```
BOOL WriteProfileString(
    LPCTSTR lpszSection,
    LPCTSTR lpszEntry,
    LPCTSTR lpszValue);
```

### <a name="parameters"></a>Parâmetros

*Lpszsection*<br/>
Aponta para uma seqüência de terminadas nula que especifica a seção que contém a entrada. Se a seção não existe, ela é criada. O nome da seção é independente do caso; a seqüência pode ser qualquer combinação de letras maiúsculas e minúsculas.

*Lpszentry*<br/>
Aponta para uma seqüência de terminação nula que contém a entrada na qual o valor deve ser escrito. Se a entrada não existir na seção especificada, ela será criada. Se este parâmetro for NULO, a seção especificada por *lpszSection* será excluída.

*Lpszvalue*<br/>
Aponta para a corda a ser escrita. Se este parâmetro for NULO, a entrada especificada pelo parâmetro *lpszEntry* será excluída.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]

Em outro exemplo, consulte o exemplo de [CWinApp::GetProfileInt](#getprofileint).

## <a name="cwinappsetappid"></a><a name="setappid"></a>CwinApp::SetAppID

Define explicitamente o ID do modelo do usuário do aplicativo para o aplicativo. Este método deve ser chamado antes de qualquer interface de usuário ser apresentada ao usuário (o melhor lugar é o construtor do aplicativo).

```
void SetAppID(LPCTSTR lpcszAppID);
```

### <a name="parameters"></a>Parâmetros

*LpcszAppID*<br/>
Especifica o ID do Modelo do Usuário do Aplicativo.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Classe CWinThread](../../mfc/reference/cwinthread-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)
