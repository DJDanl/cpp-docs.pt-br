---
title: Classe CWinApp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
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
caps.latest.revision: "27"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 99e773dc7c5039574901c2a13433615f8a0c0aad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cwinapp-class"></a>Classe CWinApp
A classe base da qual você derivar um objeto de aplicativo do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWinApp : public CWinThread  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::CWinApp](#cwinapp)|Constrói um objeto `CWinApp`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::AddDocTemplate](#adddoctemplate)|Adiciona um modelo de documento à lista de modelos de documento disponíveis da aplicação.|  
|[CWinApp::AddToRecentFileList](#addtorecentfilelist)|Adiciona um nome de arquivo à lista de arquivos usada recentemente (MRU).|  
|[CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback)|Chamado pelo framework quando o aplicativo termina inesperadamente.|  
|[CWinApp::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos abertos.|  
|[CWinApp::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora.|  
|[CWinApp::DelRegTree](#delregtree)|Exclui uma chave especificada e todas as suas subchaves.|  
|[CWinApp::DoMessageBox](#domessagebox)|Implementa [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox) para o aplicativo.|  
|[CWinApp::DoWaitCursor](#dowaitcursor)|Ativa e desativa o cursor de espera.|  
|[CWinApp::EnableD2DSupport](#enabled2dsupport)|Permite que o aplicativo `D2D` suporte. Chame este método antes da janela principal é inicializada.|  
|[CWinApp::EnableHtmlHelp](#enablehtmlhelp)|Implementa Help para o aplicativo, em vez do WinHelp.|  
|[CWinApp::EnableTaskbarInteraction](#enabletaskbarinteraction)|Permite a interação de barra de tarefas.|  
|[CWinApp::ExitInstance](#exitinstance)|Substituição para a limpeza quando seu aplicativo termina.|  
|[CWinApp::GetApplicationRecoveryParameter](#getapplicationrecoveryparameter)|Recupera o parâmetro de entrada para o método de recuperação do aplicativo.|  
|[CWinApp::GetApplicationRecoveryPingInterval](#getapplicationrecoverypinginterval)|Retorna o período de tempo que o Gerenciador de reinicialização aguarda a função de retorno de chamada de recuperação retornar.|  
|[CWinApp::GetApplicationRestartFlags](#getapplicationrestartflags)|Retorna os sinalizadores para o Gerenciador de reinicialização.|  
|[CWinApp::GetAppRegistryKey](#getappregistrykey)|Chave HKEY_CURRENT_USER retorna\\\RegistryKey\ProfileName "Software".|  
|[CWinApp::GetDataRecoveryHandler](#getdatarecoveryhandler)|Obtém o manipulador de recuperação de dados para essa instância do aplicativo.|  
|[CWinApp::GetFirstDocTemplatePosition](#getfirstdoctemplateposition)|Recupera a posição do primeiro modelo de documento.|  
|[CWinApp::GetHelpMode](#gethelpmode)|Recupera o tipo de ajuda usadas pelo aplicativo.|  
|[CWinApp::GetNextDocTemplate](#getnextdoctemplate)|Recupera a posição de um modelo de documento. Pode ser usado repetidamente.|  
|[CWinApp::GetPrinterDeviceDefaults](#getprinterdevicedefaults)|Recupera os padrões de dispositivo de impressora.|  
|[CWinApp::GetProfileBinary](#getprofilebinary)|Recupera dados binários de uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::GetProfileInt](#getprofileint)|Recupera um número inteiro de uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::GetProfileString](#getprofilestring)|Recupera uma cadeia de caracteres de uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::GetSectionKey](#getsectionkey)|Chave HKEY_CURRENT_USER retorna\\\RegistryKey\AppName\lpszSection "Software".|  
|[CWinApp::HideApplication](#hideapplication)|Oculta o aplicativo antes de fechar todos os documentos.|  
|[CWinApp::HtmlHelp](#htmlhelp)|Chamadas de `HTMLHelp` função do Windows.|  
|[CWinApp::InitInstance](#initinstance)|Substituição para efetuar uma inicialização de instância do Windows, como a criação de seus objetos de janela.|  
|[CWinApp::IsTaskbarInteractionEnabled](#istaskbarinteractionenabled)|Indica se a interação de barra de tarefas do Windows 7 está habilitada.|  
|[CWinApp::LoadCursor](#loadcursor)|Carrega um recurso de cursor.|  
|[CWinApp::LoadIcon](#loadicon)|Carrega um recurso de ícone.|  
|[CWinApp::LoadOEMCursor](#loadoemcursor)|Carrega um Windows OEM predefinidos de cursor que o **OCR_** constantes especificam no WINDOWS. H.|  
|[CWinApp::LoadOEMIcon](#loadoemicon)|Carrega um ícone predefinido de OEM do Windows que o **OIC_** constantes especificam no WINDOWS. H.|  
|[CWinApp::LoadStandardCursor](#loadstandardcursor)|Carrega um Windows predefinida cursor que o **IDC _** constantes especificam no WINDOWS. H.|  
|[CWinApp::LoadStandardIcon](#loadstandardicon)|Carrega um ícone predefinido do Windows que o **IDI_** constantes especificam no WINDOWS. H.|  
|[CWinApp::OnDDECommand](#onddecommand)|Chamado pelo framework em resposta a um dinâmico de dados (DDE) do exchange executar o comando.|  
|[CWinApp::OnIdle](#onidle)|Substitua para executar o processamento de tempo ocioso específicas do aplicativo.|  
|[CWinApp::OpenDocumentFile](#opendocumentfile)|Chamado pelo framework para abrir um documento de um arquivo.|  
|[CWinApp::ParseCommandLine](#parsecommandline)|Analisa os parâmetros individuais e sinalizadores na linha de comando.|  
|[CWinApp::PreTranslateMessage](#pretranslatemessage)|Filtra as mensagens antes de serem distribuídos para as funções do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934).|  
|[CWinApp::ProcessMessageFilter](#processmessagefilter)|Interceptar determinadas mensagens antes que elas atinjam o aplicativo.|  
|[CWinApp::ProcessShellCommand](#processshellcommand)|Lida com sinalizadores e argumentos de linha de comando.|  
|[CWinApp::ProcessWndProcException](#processwndprocexception)|Intercepta todas as exceções sem tratamento lançadas por manipuladores de comando e de mensagens do aplicativo.|  
|[CWinApp::Register](#register)|Executa o registro personalizado.|  
|[CWinApp::RegisterWithRestartManager](#registerwithrestartmanager)|Registra o aplicativo com o Gerenciador de reinicialização.|  
|[CWinApp::ReopenPreviousFilesAtRestart](#reopenpreviousfilesatrestart)|Determina se o Gerenciador de reinicialização reaberto os arquivos que estavam abertos quando o aplicativo foi encerrado inesperadamente.|  
|[CWinApp::RestartInstance](#restartinstance)|Lida com uma reinicialização do aplicativo iniciada pelo Gerenciador de reinicialização.|  
|[CWinApp::RestoreAutosavedFilesAtRestart](#restoreautosavedfilesatrestart)|Determina se o Gerenciador de reinicialização restaura os arquivos de salva automaticamente quando ele reinicia o aplicativo.|  
|[CWinApp:: Run](#run)|Executa o loop de mensagem padrão. Substituição para personalizar o loop de mensagens.|  
|[CWinApp::RunAutomated](#runautomated)|Testes de linha de comando do aplicativo para o **/Automation** opção. Obsoleto. Em vez disso, use o valor em [CCommandLineInfo::m_bRunAutomated](../../mfc/reference/ccommandlineinfo-class.md#m_brunautomated) depois de chamar [ParseCommandLine](#parsecommandline).|  
|[CWinApp::RunEmbedded](#runembedded)|Testes de linha de comando do aplicativo para o **/inserção** opção. Obsoleto. Em vez disso, use o valor em [CCommandLineInfo::m_bRunEmbedded](../../mfc/reference/ccommandlineinfo-class.md#m_brunembedded) depois de chamar [ParseCommandLine](#parsecommandline).|  
|[CWinApp::SaveAllModified](#saveallmodified)|Solicita ao usuário para salvar os documentos modificados tudo.|  
|[CWinApp::SelectPrinter](#selectprinter)|Seleciona uma impressora indicada por um usuário por meio de uma caixa de diálogo de impressão.|  
|[CWinApp::SetHelpMode](#sethelpmode)|Define e inicializa o tipo de ajuda usadas pelo aplicativo.|  
|[CWinApp::SupportsApplicationRecovery](#supportsapplicationrecovery)|Determina se o Gerenciador de reinicialização recupera um aplicativo que foi encerrado inesperadamente.|  
|[CWinApp::SupportsAutosaveAtInterval](#supportsautosaveatinterval)|Determina se o salve do Gerenciador de reinicialização abre documentos em intervalos regulares.|  
|[CWinApp::SupportsAutosaveAtRestart](#supportsautosaveatrestart)|Determina se o salve do Gerenciador de reinicialização qualquer abra documentos quando o aplicativo for reiniciado.|  
|[CWinApp::SupportsRestartManager](#supportsrestartmanager)|Determina se o aplicativo dá suporte ao Gerenciador de reinicialização.|  
|[CWinApp::Unregister](#unregister)|Cancela o registro tudo conhecido para ser registrado o `CWinApp` objeto.|  
|[CWinApp::WinHelp](#winhelp)|Chamadas de `WinHelp` função do Windows.|  
|[CWinApp::WriteProfileBinary](#writeprofilebinary)|Grava dados binários em uma entrada do aplicativo. Arquivo INI.|  
|[CWinApp::WriteProfileInt](#writeprofileint)|Grava uma entrada no aplicativo de um número inteiro. Arquivo INI.|  
|[CWinApp::WriteProfileString](#writeprofilestring)|Grava uma cadeia de caracteres em uma entrada do aplicativo. Arquivo INI.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::EnableShellOpen](#enableshellopen)|Permite ao usuário abrir arquivos de dados do Gerenciador de arquivos do Windows.|  
|[CWinApp::LoadStdProfileSettings](#loadstdprofilesettings)|Padrão de carga. Configurações do arquivo INI e permite o MRU arquivo de recurso de lista.|  
|[CWinApp::OnContextHelp](#oncontexthelp)|Lida com SHIFT + F1 Ajuda dentro do aplicativo.|  
|[CWinApp::OnFileNew](#onfilenew)|Implementa o `ID_FILE_NEW` comando.|  
|[CWinApp::OnFileOpen](#onfileopen)|Implementa o `ID_FILE_OPEN` comando.|  
|[CWinApp::OnFilePrintSetup](#onfileprintsetup)|Implementa o `ID_FILE_PRINT_SETUP` comando.|  
|[CWinApp::OnHelp](#onhelp)|Manipula a Ajuda F1 dentro do aplicativo (usando o contexto atual).|  
|[CWinApp::OnHelpFinder](#onhelpfinder)|Manipula o `ID_HELP_FINDER` e `ID_DEFAULT_HELP` comandos.|  
|[CWinApp::OnHelpIndex](#onhelpindex)|Manipula o `ID_HELP_INDEX` de comando e fornece um tópico da Ajuda padrão.|  
|[CWinApp::OnHelpUsing](#onhelpusing)|Manipula o `ID_HELP_USING` comando.|  
|[CWinApp::RegisterShellFileTypes](#registershellfiletypes)|Registra tipos de documento de todos os do aplicativo com o Gerenciador de arquivos do Windows.|  
|[CWinApp::SetAppID](#setappid)|Define explicitamente o ID de modelo de usuário do aplicativo para o aplicativo. Este método deve ser chamado antes de qualquer interface de usuário é apresentada ao usuário (o melhor local é o construtor de aplicativo).|  
|[CWinApp::SetRegistryKey](#setregistrykey)|Faz com que as configurações de aplicativo a ser armazenado no registro em vez de. Arquivos INI.|  
|[CWinApp::UnregisterShellFileTypes](#unregistershellfiletypes)|Cancela o registro de tipos de documento de todos os do aplicativo com o Gerenciador de arquivos do Windows.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::m_bHelpMode](#m_bhelpmode)|Indica se o usuário está no modo de contexto de Ajuda (normalmente são invocado com SHIFT + F1).|  
|[CWinApp::m_eHelpType](#m_ehelptype)|Especifica o tipo de ajuda usadas pelo aplicativo.|  
|[CWinApp::m_hInstance](#m_hinstance)|Identifica a instância atual do aplicativo.|  
|[CWinApp::m_lpCmdLine](#m_lpcmdline)|Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo.|  
|[CWinApp::m_nCmdShow](#m_ncmdshow)|Especifica como a janela a ser exibido inicialmente.|  
|[CWinApp::m_pActiveWnd](#m_pactivewnd)|Ponteiro para a janela principal do aplicativo recipiente quando um servidor OLE está ativo no local.|  
|[CWinApp::m_pszAppID](#m_pszappid)|ID de modelo de usuário do aplicativo.|  
|[CWinApp::m_pszAppName](#m_pszappname)|Especifica o nome do aplicativo.|  
|[CWinApp::m_pszExeName](#m_pszexename)|O nome do módulo do aplicativo.|  
|[CWinApp::m_pszHelpFilePath](#m_pszhelpfilepath)|O caminho para o arquivo de Ajuda do aplicativo.|  
|[CWinApp::m_pszProfileName](#m_pszprofilename)|O aplicativo. Nome do arquivo INI.|  
|[CWinApp::m_pszRegistryKey](#m_pszregistrykey)|Usado para determinar a chave de registro completo para armazenar as configurações de perfil de aplicativo.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinApp::m_dwRestartManagerSupportFlags](#m_dwrestartmanagersupportflags)|Sinalizadores que determinam como o Gerenciador de reinicialização se comporta.|  
|[CWinApp::m_nAutosaveInterval](#m_nautosaveinterval)|O período de tempo em milissegundos, entre salve.|  
|[CWinApp::m_pDataRecoveryHandler](#m_pdatarecoveryhandler)|Ponteiro para o manipulador de recuperação de dados para o aplicativo.|  
  
## <a name="remarks"></a>Comentários  
 Um objeto de aplicativo fornece funções de membro para inicializar o aplicativo (e cada instância dele) e para executar o aplicativo.  
  
 Cada aplicativo que usa as Microsoft Foundation classes só pode conter um objeto derivado de `CWinApp`. Este objeto é construído quando outros objetos globais C++ são construídos e já está disponível quando o Windows chama o `WinMain` função, que é fornecida pela biblioteca Microsoft Foundation Class. Declarar derivada `CWinApp` objeto no nível global.  
  
 Quando você derivar uma classe de aplicativo de `CWinApp`, substituir o [InitInstance](#initinstance) função de membro para criar o objeto de janela principal do seu aplicativo.  
  
 Além de `CWinApp` funções de membro, a biblioteca Microsoft Foundation Class fornece as seguintes funções globais para acessar seu `CWinApp` objeto e outras informações globais:  
  
- [AfxGetApp](application-information-and-management.md#afxgetapp) obtém um ponteiro para o `CWinApp` objeto.  
  
- [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle) obtém um identificador para a instância atual do aplicativo.  
  
- [AfxGetResourceHandle](application-information-and-management.md#afxgetresourcehandle) obtém um identificador para os recursos do aplicativo.  
  
- [AfxGetAppName](application-information-and-management.md#afxgetappname) obtém um ponteiro para uma cadeia de caracteres que contém o nome do aplicativo. Como alternativa, se você tiver um ponteiro para o `CWinApp` de objeto, use `m_pszExeName` para obter o nome do aplicativo.  
  
 Consulte [CWinApp: A classe do aplicativo](../../mfc/cwinapp-the-application-class.md) para obter mais informações sobre o `CWinApp` classe, incluindo uma visão geral das seguintes opções:  
  
- `CWinApp`-derivado código escrito pelo Assistente de aplicativo.  
  
- `CWinApp`da função na sequência de execução do seu aplicativo.  
  
- `CWinApp`'s implementações padrão de função de membro.  
  
- `CWinApp`da chave sobre substituíveis.  
  
 O **m_hPrevInstance** membro de dados não existe mais. Para obter informações sobre como detectar uma instância anterior do `CWinApp`, consulte o artigo da Base de dados de Conhecimento "Como para identificar um anterior de um aplicativo de instância" (KB106385) em [http://support.microsoft.com/default.aspxscid=kb;en-us;106385](http://support.microsoft.com/default.aspxscid=kb;en-us;106385).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 `CWinApp`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="adddoctemplate"></a>CWinApp::AddDocTemplate  
 Chame essa função de membro para adicionar um modelo de documento para a lista de modelos de documento disponíveis que mantém o aplicativo.  
  
```  
void AddDocTemplate(CDocTemplate* pTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTemplate`  
 Um ponteiro para o `CDocTemplate` a ser adicionado.  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar a todos os modelos para um aplicativo de documento antes de chamar [RegisterShellFileTypes](#registershellfiletypes).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#35](../../mfc/reference/codesnippet/cpp/cwinapp-class_1.cpp)]  
  
##  <a name="addtorecentfilelist"></a>CWinApp::AddToRecentFileList  
 Chamar essa função de membro para adicionar `lpszPathName` à lista de arquivos MRU.  
  
```  
virtual void AddToRecentFileList(LPCTSTR lpszPathName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 O caminho do arquivo.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o [LoadStdProfileSettings](#loadstdprofilesettings) a função de membro para carregar a lista de arquivos MRU atual antes de usar essa função de membro.  
  
 O framework chama esta função de membro quando ele abre um arquivo ou executa o comando Salvar como para salvar um arquivo com um novo nome.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#36](../../mfc/reference/codesnippet/cpp/cwinapp-class_2.cpp)]  
  
##  <a name="applicationrecoverycallback"></a>CWinApp::ApplicationRecoveryCallback  
 Chamado pelo framework quando o aplicativo termina inesperadamente.  
  
```  
virtual DWORD ApplicationRecoveryCallback(LPVOID lpvParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpvParam`  
 Reservado para uso futuro.  
  
### <a name="return-value"></a>Valor de retorno  
 0 se esse método for bem-sucedida; diferente de zero se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo tiver suporte para o Gerenciador de reinicialização, o framework chama essa função quando seu aplicativo termina inesperadamente.  
  
 A implementação padrão de `ApplicationRecoveryCallback` usa o `CDataRecoveryHandler` para salvar a lista de documentos abertos no momento do registro. Esse método não não salvamento automático de todos os arquivos.  
  
 Para personalizar o comportamento, substitua essa função em um derivado [classe CWinApp](../../mfc/reference/cwinapp-class.md) ou passe o seu próprio método de recuperação do aplicativo como um parâmetro para [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager).  
  
##  <a name="closealldocuments"></a>CWinApp::CloseAllDocuments  
 Chame essa função de membro para fechar todos os documentos abertos antes de sair.  
  
```  
void CloseAllDocuments(BOOL bEndSession);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEndSession`  
 Especifica se a sessão do Windows está sendo encerrada. É **TRUE** se a sessão está sendo finalizado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Chamar [HideApplication](#hideapplication) antes de chamar `CloseAllDocuments`.  
  
##  <a name="createprinterdc"></a>CWinApp::CreatePrinterDC  
 Chame essa função de membro para criar um contexto de dispositivo de impressora (DC) da impressora selecionada.  
  
```  
BOOL CreatePrinterDC(CDC& dc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 Uma referência a um contexto de dispositivo de impressora.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contexto de dispositivo de impressora é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `CreatePrinterDC`inicializa o contexto de dispositivo que você passar por referência, para que possa ser usado para imprimir.  
  
 Se a função for bem-sucedida, quando você terminar de impressão, você deverá destruir o contexto de dispositivo. Você pode deixar o destruidor do [CDC](../../mfc/reference/cdc-class.md) objeto fazê-lo, ou você pode fazê-lo explicitamente chamando [CDC::DeleteDC](../../mfc/reference/cdc-class.md#deletedc).  
  
##  <a name="cwinapp"></a>CWinApp::CWinApp  
 Constrói um `CWinApp` objeto e passa `lpszAppName` a ser armazenado como o nome do aplicativo.  
  
```  
CWinApp(LPCTSTR lpszAppName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszAppName`  
 Uma cadeia terminada em nulo que contém o nome do aplicativo que usa o Windows. Se esse argumento não for fornecido ou está **nulo**, `CWinApp` usa a cadeia de caracteres de recurso **AFX_IDS_APP_TITLE** ou o nome do arquivo do arquivo executável.  
  
### <a name="remarks"></a>Comentários  
 Você deve construir um objeto global do seu `CWinApp`-classe derivada. Você pode ter apenas um `CWinApp` objeto em seu aplicativo. O construtor armazena um ponteiro para o `CWinApp` objeto para que `WinMain` pode chamar funções para inicializar e executar o aplicativo de membro do objeto.  
  
##  <a name="delregtree"></a>CWinApp::DelRegTree  
 Exclui uma chave de registro específicos e todas as suas subchaves.  
  
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
 Se a função tiver êxito, o valor de retorno é ERROR_SUCCESS. Se a função falhar, o valor de retorno é um código de erro diferente de zero definido no Winerror. h.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para excluir a chave especificada e suas subchaves.  
  
##  <a name="domessagebox"></a>CWinApp::DoMessageBox  
 O framework chama esta função de membro para implementar uma caixa de mensagem para a função global [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox).  
  
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
 A caixa de mensagem [estilo](../../mfc/reference/styles-used-by-mfc.md#message-box-styles).  
  
 `nIDPrompt`  
 Um índice para uma cadeia de caracteres de contexto de Ajuda.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna os mesmos valores `AfxMessageBox`.  
  
### <a name="remarks"></a>Comentários  
 Não chamar essa função de membro para abrir uma caixa de mensagem. Use `AfxMessageBox` em vez disso.  
  
 Substituir essa função de membro para personalizar o processamento de todo o aplicativo de `AfxMessageBox` chamadas.  
  
##  <a name="dowaitcursor"></a>CWinApp::DoWaitCursor  
 Essa função de membro é chamada pelo framework para implementar [CWaitCursor](../../mfc/reference/cwaitcursor-class.md), [CCmdTarget::BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor), [CCmdTarget::EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor), e [ CCmdTarget::RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).  
  
```  
virtual void DoWaitCursor(int nCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCode`  
 Se esse parâmetro for 1, será exibido um cursor de espera. Se for 0, o cursor de espera é restaurado sem incrementar a contagem de referência. Se-1, o cursor de espera será encerrada.  
  
### <a name="remarks"></a>Comentários  
 O padrão implementa um cursor ampulheta. `DoWaitCursor`mantém uma contagem de referência. Quando for positivo, o cursor de ampulheta é exibido.  
  
 Enquanto você não poderia chamar normalmente `DoWaitCursor` diretamente, você pode substituir essa função de membro para alterar o cursor de espera ou processamento adicional, enquanto o cursor de espera é exibido.  
  
 Para uma maneira mais fácil e mais simples implementar um cursor de espera, use `CWaitCursor`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#37](../../mfc/reference/codesnippet/cpp/cwinapp-class_3.cpp)]  
  
##  <a name="enabled2dsupport"></a>CWinApp::EnableD2DSupport  
 [!INCLUDE[dev10_sp1required](../../mfc/reference/includes/dev10_sp1required_md.md)]  
  
 Habilita o suporte do aplicativo D2D. Chame este método antes da janela principal é inicializada.  
  
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
 Retorna TRUE se D2D suporte foi habilitado, FALSE - caso contrário  
  
##  <a name="enablehtmlhelp"></a>CWinApp::EnableHtmlHelp  
 Chamar essa função de membro de dentro do construtor de seu `CWinApp`-derivado da classe para usar o Help para obter ajuda do seu aplicativo.  
  
```  
void EnableHtmlHelp();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enableshellopen"></a>CWinApp::EnableShellOpen  
 Chamar essa função, normalmente a partir de seu `InitInstance` substituição, para permitir que os usuários do seu aplicativo abrir arquivos de dados quando ele clicar duas vezes os arquivos no Gerenciador de arquivos Windows.  
  
```  
void EnableShellOpen();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o `RegisterShellFileTypes` membro funcionar em conjunto com esta função, ou forneça um. Arquivo REG com o seu aplicativo para o registro manual dos tipos de documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#38](../../mfc/reference/codesnippet/cpp/cwinapp-class_4.cpp)]  
  
##  <a name="enabletaskbarinteraction"></a>CWinApp::EnableTaskbarInteraction  
 Permite a interação de barra de tarefas.  
  
```  
BOOL EnableTaskbarInteraction(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se deve ser habilitada a interação com a barra de tarefas do Windows 7 ( `TRUE`), ou desabilitado ( `FALSE`).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se interação da barra de tarefas pode ser habilitada ou desabilitada.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado antes da criação da janela principal, caso contrário, ele declara e retorna `FALSE`.  
  
##  <a name="exitinstance"></a>CWinApp::ExitInstance  
 Chamado pelo framework de dentro do **executar** a função de membro para sair dessa instância do aplicativo.  
  
```  
virtual int ExitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Código de saída do aplicativo; 0 não indica que nenhum erro, e os valores maiores que 0 indicam um erro. Esse valor é usado como o valor de retorno `WinMain`.  
  
### <a name="remarks"></a>Comentários  
 Não chame a função de membro de qualquer lugar mas dentro do **executar** função de membro.  
  
 A implementação padrão dessa função grava opções do framework do aplicativo. Arquivo INI. Substitua esta função para limpar quando seu aplicativo é encerrado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#39](../../mfc/reference/codesnippet/cpp/cwinapp-class_5.cpp)]  
  
##  <a name="getapplicationrecoveryparameter"></a>CWinApp::GetApplicationRecoveryParameter  
 Recupera o parâmetro de entrada para o método de recuperação do aplicativo.  
  
```  
virtual LPVOID GetApplicationRecoveryParameter();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O parâmetro de entrada padrão para o método de recuperação do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Retorna o comportamento padrão dessa função `NULL`.  
  
 Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).  
  
##  <a name="getapplicationrecoverypinginterval"></a>CWinApp::GetApplicationRecoveryPingInterval  
 Retorna o período de tempo que o Gerenciador de reinicialização aguarda a função de retorno de chamada de recuperação retornar.  
  
```  
virtual DWORD GetApplicationRecoveryPingInterval();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O período de tempo em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 Quando um aplicativo que está registrado com o sai do Gerenciador de reinicialização inesperadamente, o aplicativo tenta salvar os documentos abertos e chama a função de retorno de chamada de recuperação. A função de retorno de chamada de recuperação padrão é [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).  
  
 O período de tempo que a estrutura de espera para a função de retorno de chamada de recuperação retornar é o intervalo de ping. Você pode personalizar o intervalo de ping, substituindo `CWinApp::GetApplicationRecoveryPingInterval` ou fornecendo um valor personalizado para `RegisterWithRestartManager`.  
  
##  <a name="getapplicationrestartflags"></a>CWinApp::GetApplicationRestartFlags  
 Retorna os sinalizadores para o Gerenciador de reinicialização.  
  
```  
virtual DWORD GetApplicationRestartFlags();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os sinalizadores para o Gerenciador de reinicialização. A implementação padrão retorna 0.  
  
### <a name="remarks"></a>Comentários  
 Os sinalizadores para o Gerenciador de reinicialização não têm nenhum efeito com a implementação padrão. Eles são fornecidos para uso futuro.  
  
 Defina os sinalizadores ao registrar o aplicativo com o Gerenciador de reinicialização, usando [CWinApp::RegisterWithRestartManager](#registerwithrestartmanager).  
  
 Os valores possíveis para os sinalizadores de Gerenciador de reinicialização são da seguinte maneira:  
  
- `RESTART_NO_CRASH`  
  
- `RESTART_NO_HANG`  
  
- `RESTART_NO_PATCH`  
  
- `RESTART_NO_REBOOT`  
  
##  <a name="getappregistrykey"></a>CWinApp::GetAppRegistryKey  
 Retorna a chave para HKEY_CURRENT_USER\\\RegistryKey\ProfileName "Software".  
  
```  
HKEY GetAppRegistryKey(CAtlTransactionManager* pTM = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTM`  
 Ponteiro para uma `CAtlTransactionManager` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Chave de aplicativo se a função for bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdatarecoveryhandler"></a>CWinApp::GetDataRecoveryHandler  
 Obtém o manipulador de recuperação de dados para essa instância do aplicativo.  
  
```  
virtual CDataRecoveryHandler *GetDataRecoveryHandler();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O manipulador de recuperação de dados para essa instância do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Cada aplicativo que usa o Gerenciador de reinicialização deve ter uma instância de [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md). Essa classe é responsável por monitorar os documentos abertos e arquivos de gravação automática. O comportamento do `CDataRecoveryHandler` depende da configuração do Gerenciador de reinicialização. Para obter mais informações, consulte [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md).  
  
 Este método retorna `NULL` em sistemas operacionais anteriores ao [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]. O Gerenciador de reinicialização não tem suporte em sistemas operacionais anteriores ao [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)].  
  
 Se o aplicativo não tiver um manipulador de recuperação de dados no momento, esse método cria um e retorna um ponteiro para ele.  
  
##  <a name="getfirstdoctemplateposition"></a>CWinApp::GetFirstDocTemplatePosition  
 Obtém a posição do primeiro modelo de documento no aplicativo.  
  
```  
POSITION GetFirstDocTemplatePosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iteração ou recuperação de ponteiro de objeto; **Nulo** se a lista está vazia.  
  
### <a name="remarks"></a>Comentários  
 Use o **posição** valor retornado em uma chamada para [GetNextDocTemplate](#getnextdoctemplate) para obter o primeiro [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto.  
  
##  <a name="gethelpmode"></a>CWinApp::GetHelpMode  
 Recupera o tipo de ajuda usadas pelo aplicativo.  
  
```  
AFX_HELP_TYPE GetHelpMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de Ajuda usado pelo aplicativo. Consulte [CWinApp::m_eHelpType](#m_ehelptype) para obter mais informações.  
  
##  <a name="getnextdoctemplate"></a>CWinApp::GetNextDocTemplate  
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
 Você pode usar `GetNextDocTemplate` em um loop de interação direta se estabelecer a posição inicial com uma chamada para `GetFirstDocTemplatePosition`.  
  
 Você deve garantir que seu **posição** valor é válido. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
 Se o modelo de documento recuperado é o último disponível, em seguida, o novo valor de `pos` é definido como **nulo**.  
  
##  <a name="getprinterdevicedefaults"></a>CWinApp::GetPrinterDeviceDefaults  
 Chame essa função de membro para preparar uma impressora contexto de dispositivo para impressão.  
  
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
 [!code-cpp[NVC_MFCWindowing#40](../../mfc/reference/codesnippet/cpp/cwinapp-class_6.cpp)]  
  
##  <a name="getprofilebinary"></a>CWinApp::GetProfileBinary  
 Chamar essa função de membro para recuperar dados binários de uma entrada em uma seção especificada do registro do aplicativo ou. Arquivo INI.  
  
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
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cujo valor é a ser recuperado.  
  
 *ppData*  
 Aponta para um ponteiro que receberá o endereço dos dados.  
  
 *Petabytes*  
 Aponta para um UINT que receberá o tamanho dos dados (em bytes).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não é diferencia maiusculas de minúsculas, portanto as cadeias de caracteres no *lpszSection* e *lpszEntry* parâmetros podem ser diferentes caso.  
  
> [!NOTE]
> **GetProfileBinary** aloca um buffer e retorna seu endereço em \* *ppData*. O chamador é responsável pela liberação de buffer usando **excluir []**.  
  
> [!IMPORTANT]
>  Os dados retornados por essa função não são necessariamente nulos terminada e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#41](../../mfc/reference/codesnippet/cpp/cwinapp-class_7.cpp)]  
  
 Para obter um exemplo adicional, consulte [CWinApp::WriteProfileBinary](#writeprofilebinary).  
  
##  <a name="getprofileint"></a>CWinApp::GetProfileInt  
 Chamar essa função de membro para recuperar o valor de um inteiro de uma entrada em uma seção especificada do registro do aplicativo ou. Arquivo INI.  
  
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
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada cujo valor é a ser recuperado.  
  
 `nDefault`  
 Especifica o valor padrão para retornar se a estrutura não é possível localizar a entrada.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de inteiro da cadeia de caracteres que segue a entrada especificada se a função for bem-sucedida. O valor de retorno é o valor da `nDefault` se a função não localizar a entrada de parâmetro. O valor de retorno será 0 se o valor que corresponde à entrada especificada não é um inteiro.  
  
 Essa função de membro oferece suporte a notação hexadecimal para o valor da. Arquivo INI. Quando você recupera um inteiro com sinal, você deve converter o valor em um `int`.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não é diferencia maiusculas de minúsculas, portanto as cadeias de caracteres no `lpszSection` e `lpszEntry` parâmetros podem ser diferentes caso.  
  
> [!IMPORTANT]
>  Os dados retornados por essa função não são necessariamente nulos terminada e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#42](../../mfc/reference/codesnippet/cpp/cwinapp-class_8.cpp)]  
  
 Para obter um exemplo adicional, consulte [CWinApp::WriteProfileInt](#writeprofileint).  
  
##  <a name="getprofilestring"></a>CWinApp::GetProfileString  
 Chamar essa função de membro para recuperar a cadeia de caracteres associada a uma entrada dentro da seção especificada no registro do aplicativo ou. Arquivo INI.  
  
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
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada é cuja cadeia de caracteres a ser recuperado. Esse valor não deve ser **nulo**.  
  
 `lpszDefault`  
 Aponta para o valor de cadeia de caracteres padrão para a entrada especificada se a entrada não pode ser encontrada no arquivo de inicialização.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno é a cadeia de caracteres a partir do aplicativo. O arquivo INI ou `lpszDefault` se a cadeia de caracteres não pode ser encontrada. O comprimento máximo da cadeia de caracteres com suporte do framework é `_MAX_PATH`. Se `lpszDefault` é **nulo**, o valor de retorno é uma cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
  
> [!IMPORTANT]
>  Os dados retornados por essa função não são necessariamente nulos terminada e o chamador deve executar a validação. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileInt](#getprofileint).  
  
##  <a name="getsectionkey"></a>CWinApp::GetSectionKey  
 Retorna a chave para HKEY_CURRENT_USER\\\RegistryKey\AppName\lpszSection "Software".  
  
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
 Chave da seção se a função for bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hideapplication"></a>CWinApp::HideApplication  
 Chame essa função de membro para ocultar um aplicativo antes de fechar os documentos abertos.  
  
```  
void HideApplication();
```  
  
##  <a name="htmlhelp"></a>CWinApp::HtmlHelp  
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
 Especifica o tipo de ajuda solicitado. Para obter uma lista de valores possíveis e como eles afetam o `dwData` parâmetro, consulte o `uCommand` parâmetro descrito em sobre o Help função de API no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 A estrutura também chama essa função para chamar o aplicativo Help.  
  
 A estrutura será fechada automaticamente o aplicativo Help ao seu aplicativo termina.  
  
##  <a name="initinstance"></a>CWinApp::InitInstance  
 O Windows permite que várias cópias do mesmo programa para ser executado ao mesmo tempo.  
  
```  
virtual BOOL InitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Conceitualmente, a inicialização de aplicativos é dividida em duas seções: inicialização de aplicativo único que é feita a primeira vez que as execuções de programa e tempo de inicialização de instância que executa uma cópia das execuções de programa, incluindo a primeira vez. A implementação da estrutura de `WinMain` chama esta função.  
  
 Substituir `InitInstance` para inicializar cada nova instância do seu aplicativo em execução no Windows. Normalmente, você substituir `InitInstance` para construir o objeto da janela principal e definir o `CWinThread::m_pMainWnd` membro de dados para apontar para essa janela. Para obter mais informações sobre essa função de membro de substituição, consulte [CWinApp: A classe do aplicativo](../../mfc/cwinapp-the-application-class.md).  
  
> [!NOTE]
>  Aplicativos MFC devem ser inicializados como apartment threaded único (STA). Se você chamar [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279) no seu `InitInstance` substituir, especifique `COINIT_APARTMENTTHREADED` (em vez de `COINIT_MULTITHREADED`). Para obter mais informações, consulte PRB: aplicativos MFC para de responder quando você inicializar o aplicativo como um Multi-Threaded Apartment (828643) em [http://support.microsoft.com/default.aspxscid=kb;en-us;828643](http://support.microsoft.com/default.aspxscid=kb;en-us;828643).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCListView#9](../../atl/reference/codesnippet/cpp/cwinapp-class_10.cpp)]  
  
##  <a name="istaskbarinteractionenabled"></a>CWinApp::IsTaskbarInteractionEnabled  
 Indica se a interação de barra de tarefas do Windows 7 está habilitada.  
  
```  
virtual BOOL IsTaskbarInteractionEnabled();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se `EnableTaskbarInteraction` foi chamado e o sistema operacional Windows 7 ou superior.  
  
### <a name="remarks"></a>Comentários  
 Interação de barra de tarefas significa que o aplicativo MDI exibe o conteúdo de filhos MDI em separado miniaturas com guias que aparecem quando o ponteiro do mouse está sobre o botão de barra de tarefas do aplicativo.  
  
##  <a name="loadcursor"></a>CWinApp::LoadCursor  
 Carrega o recurso de cursor nomeado pelo `lpszResourceName` ou especificado pelo `nIDResource` do arquivo executável atual.  
  
```  
HCURSOR LoadCursor(LPCTSTR lpszResourceName) const;  HCURSOR LoadCursor(UINT nIDResource) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso do cursor. Você pode usar um `CString` para esse argumento.  
  
 `nIDResource`  
 ID do recurso do cursor. Para obter uma lista de recursos, consulte [LoadCursor](http://msdn.microsoft.com/library/windows/desktop/ms648391) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um cursor se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 `LoadCursor`carrega o cursor na memória somente se ele não tenha sido previamente carregado; Caso contrário, ele recupera um identificador de recurso existente.  
  
 Use o [LoadStandardCursor](#loadstandardcursor) ou [LoadOEMCursor](#loadoemcursor) a função de membro para acessar os cursores Windows predefinidos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#44](../../mfc/reference/codesnippet/cpp/cwinapp-class_11.cpp)]  
  
##  <a name="loadicon"></a>CWinApp::LoadIcon  
 Carrega o recurso de ícone denominado por `lpszResourceName` ou especificado pelo `nIDResource` do arquivo executável.  
  
```  
HICON LoadIcon(LPCTSTR lpszResourceName) const;  HICON LoadIcon(UINT nIDResource) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de ícone. Você também pode usar um `CString` para esse argumento.  
  
 `nIDResource`  
 Número de identificação do recurso de ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 `LoadIcon`carrega o ícone somente se ele não tenha sido previamente carregado; Caso contrário, ele recupera um identificador de recurso existente.  
  
 Você pode usar o [LoadStandardIcon](#loadstandardicon) ou [LoadOEMIcon](#loadoemicon) a função de membro para acessar os ícones do Windows predefinidos.  
  
> [!NOTE]
>  Essa função de membro chama a função de API do Win32 [LoadIcon](http://msdn.microsoft.com/library/windows/desktop/ms648072), que só pode carregar um ícone cujo tamanho é compatível com o **SM_CXICON** e **SM_CYICON** valores de métricas do sistema.  
  
##  <a name="loadoemcursor"></a>CWinApp::LoadOEMCursor  
 Carrega o Windows predefinida recurso cursor especificado pela `nIDCursor`.  
  
```  
HCURSOR LoadOEMCursor(UINT nIDCursor) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDCursor`  
 Um **OCR_** manifesto constante identificador que especifica um cursor Windows predefinido. Você deve ter **#define OEMRESOURCE** antes de **#include \<afxwin.h >** para acessar o **OCR_** constantes no WINDOWS. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um cursor se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadOEMCursor` ou [LoadStandardCursor](#loadstandardcursor) a função de membro para acessar os cursores Windows predefinidos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#45](../../mfc/reference/codesnippet/cpp/cwinapp-class_12.h)]  
  
 [!code-cpp[NVC_MFCWindowing#46](../../mfc/reference/codesnippet/cpp/cwinapp-class_13.cpp)]  
  
##  <a name="loadoemicon"></a>CWinApp::LoadOEMIcon  
 Carrega o Windows predefinidos de recurso de ícone especificado pela `nIDIcon`.  
  
```  
HICON LoadOEMIcon(UINT nIDIcon) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDIcon`  
 Um **OIC_** manifesto constante identificador que especifica um ícone do Windows predefinido. Você deve ter **#define OEMRESOURCE** antes de **#include \<afxwin.h >** para acessar o **OIC_** constantes no WINDOWS. H.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadOEMIcon` ou [LoadStandardIcon](#loadstandardicon) a função de membro para acessar os ícones do Windows predefinidos.  
  
##  <a name="loadstandardcursor"></a>CWinApp::LoadStandardCursor  
 Carrega o Windows predefinidos de recursos de cursor que `lpszCursorName` especifica.  
  
```  
HCURSOR LoadStandardCursor(LPCTSTR lpszCursorName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszCursorName`  
 Um **IDC _** manifesto constante identificador que especifica um cursor Windows predefinido. Esses identificadores são definidos no WINDOWS. H. A lista a seguir mostra os possíveis valores predefinidos e significados `lpszCursorName`:  
  
- **IDC_ARROW** cursor seta padrão  
  
- **IDC_IBEAM** cursor de inserção de texto padrão  
  
- **IDC_WAIT** cursor ampulheta usado quando o Windows executa uma tarefa demorada  
  
- **IDC_CROSS** cursor cruz para seleção  
  
- **IDC_UPARROW** seta que aponta para cima  
  
- **IDC_SIZE** obsoleto e sem suporte; use **IDC_SIZEALL**  
  
- **IDC_SIZEALL** uma seta de quatro pontas. O cursor a ser usado para redimensionar a janela.  
  
- **IDC_ICON** obsoleto e sem suporte. Use **IDC_ARROW**.  
  
- **IDC_SIZENWSE** duas pontas de seta com termina na parte superior esquerda e inferior direita  
  
- **IDC_SIZENESW** seta de duas pontas com termina na parte superior esquerda inferior e direita  
  
- **IDC_SIZEWE** seta Horizontal com duas pontas  
  
- **IDC_SIZENS** seta de duas pontas Vertical  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um cursor se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadStandardCursor` ou [LoadOEMCursor](#loadoemcursor) a função de membro para acessar os cursores Windows predefinidos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#47](../../mfc/reference/codesnippet/cpp/cwinapp-class_14.cpp)]  
  
##  <a name="loadstandardicon"></a>CWinApp::LoadStandardIcon  
 Carrega o Windows predefinidos de recurso do ícone que `lpszIconName` especifica.  
  
```  
HICON LoadStandardIcon(LPCTSTR lpszIconName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIconName`  
 Um manifesto identificador constante que especifica um ícone do Windows predefinido. Esses identificadores são definidos no WINDOWS. H. Para obter uma lista dos possíveis valores predefinidos e suas descrições, consulte o *lpIconName* parâmetro em [LoadIcon](http://msdn.microsoft.com/library/windows/desktop/ms648072) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use o `LoadStandardIcon` ou [LoadOEMIcon](#loadoemicon) a função de membro para acessar os ícones do Windows predefinidos.  
  
##  <a name="loadstdprofilesettings"></a>CWinApp::LoadStdProfileSettings  
 Chamar essa função de membro de dentro do [InitInstance](#initinstance) função de membro para habilitar e carregar a lista de arquivos de usados recentemente (MRU) e o último estado de visualização.  
  
```  
void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxMRU`  
 O número de arquivos usados recentemente para rastrear.  
  
### <a name="remarks"></a>Comentários  
 Se `nMaxMRU` for 0, nenhuma lista MRU será mantida.  
  
##  <a name="m_bhelpmode"></a>CWinApp::m_bHelpMode  
 **TRUE** se o aplicativo estiver no modo de contexto de Ajuda (convencionalmente chamado com SHIFT + F1); caso contrário, **FALSE**.  
  
```  
BOOL m_bHelpMode;  
```  
  
### <a name="remarks"></a>Comentários  
 No modo de contexto de Ajuda, o cursor se torna um ponto de interrogação e o usuário pode movê-lo sobre a tela. Examine esse sinalizador se você deseja implementar um tratamento especial quando no modo de Ajuda. `m_bHelpMode`é uma variável pública do tipo **BOOL**.  
  
##  <a name="m_dwrestartmanagersupportflags"></a>CWinApp::m_dwRestartManagerSupportFlags  
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
|- `AFX_RESTART_MANAGER_SUPPORT_RECOVERY`|O aplicativo está registrado com o Gerenciador de reinicialização e o Gerenciador de reinicialização chama a função de retorno de chamada de recuperação ao reiniciar o aplicativo. A função de retorno de chamada de recuperação padrão é [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|  
|- `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART`|Salvamento automático esteja habilitado e o salve do Gerenciador de reinicialização qualquer abra documentos quando o aplicativo for reiniciado.|  
|- `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL`|Salvamento automático esteja habilitado e o salve do Gerenciador de reinicialização qualquer abrir documentos em intervalos regulares. O intervalo é definido pela [CWinApp::m_nAutosaveInterval](#m_nautosaveinterval).|  
|- `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`|O Gerenciador de reinicialização abre documentos abertos anteriormente depois de reiniciar o aplicativo de uma saída inesperado. O [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md) manipula armazenar a lista de documentos abertos e restaurá-los.|  
|- `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`|O Gerenciador de reinicialização solicita ao usuário para restaurar arquivos salva automaticamente depois de reiniciar o aplicativo. O `CDataRecoveryHandler` classe consulta o usuário.|  
|- `AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE`|A união de `AFX_RESTART_MANAGER_SUPPORT_RESTART`, `AFX_RESTART_MANAGER_SUPPORT_RECOVER`, e `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`.|  
|- `AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS`|A união de `AFX_RESTART_MANAGER_SUPPORT_NO_AUTOSAVE`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL`, e `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`.|  
|- `AFX_RESTART_MANAGER_SUPPORT_RESTART_ASPECTS`|A união de `AFX_RESTART_MANAGER_SUPPORT_RESTART`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART`, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`, e `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`.|  
|- `AFX_RESTART_MANAGER_SUPPORT_RECOVERY_ASPECTS`|A união de `AFX_RESTART_MANAGER_SUPPORT_RECOVERY`, `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL`, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES`, e `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES`.|  
  
##  <a name="m_ehelptype"></a>CWinApp::m_eHelpType  
 O tipo desse membro de dados é o tipo enumerado **AFX_HELP_TYPE**, que é definida dentro de `CWinApp` classe.  
  
```  
AFX_HELP_TYPE m_eHelpType;  
```  
  
### <a name="remarks"></a>Comentários  
 O **AFX_HELP_TYPE** enumeração é definida da seguinte maneira:  
  
```  
enum AFX_HELP_TYPE {  
    afxWinHelp = 0,
    afxHTMLHelp = 1
    };  
```  
  
-   Para definir a Ajuda do aplicativo para Ajuda em HTML, chame [SetHelpMode](#sethelpmode) e especifique **afxHTMLHelp**.  
  
-   Para definir a Ajuda do aplicativo para WinHelp, chame `SetHelpMode` e especifique **afxWinHelp**.  
  
##  <a name="m_hinstance"></a>CWinApp::m_hInstance  
 Corresponde do `hInstance` parâmetro passado pelo Windows para `WinMain`.  
  
```  
HINSTANCE m_hInstance;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_hInstance` membro de dados é um identificador para a instância atual do aplicativo em execução no Windows. Isto é retornado pela função global [AfxGetInstanceHandle](application-information-and-management.md#afxgetinstancehandle). `m_hInstance`é uma variável pública do tipo `HINSTANCE`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#55](../../mfc/reference/codesnippet/cpp/cwinapp-class_15.cpp)]  
  
##  <a name="m_lpcmdline"></a>CWinApp::m_lpCmdLine  
 Corresponde do `lpCmdLine` parâmetro passado pelo Windows para `WinMain`.  
  
```  
LPTSTR m_lpCmdLine;  
```  
  
### <a name="remarks"></a>Comentários  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para o aplicativo. Use `m_lpCmdLine` para acessar quaisquer argumentos de linha de comando que o usuário inserido quando o aplicativo foi iniciado. `m_lpCmdLine`é uma variável pública do tipo `LPTSTR`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#52](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]  
  
##  <a name="m_nautosaveinterval"></a>CWinApp::m_nAutosaveInterval  
 O período de tempo em milissegundos, entre salve.  
  
```  
int m_nAutosaveInterval;  
```  
  
### <a name="remarks"></a>Comentários  
 Você pode configurar o Gerenciador de reinicialização para documentos abertos de salvamento automático em intervalos definidos. Se seu aplicativo não os arquivos de salvamento automático, esse parâmetro não tem efeito.  
  
##  <a name="m_ncmdshow"></a>CWinApp::m_nCmdShow  
 Corresponde do `nCmdShow` parâmetro passado pelo Windows para `WinMain`.  
  
```  
int m_nCmdShow;  
```  
  
### <a name="remarks"></a>Comentários  
 Você deve passar `m_nCmdShow` como um argumento ao chamar [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow) para a janela principal do aplicativo. `m_nCmdShow`é uma variável pública do tipo `int`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#56](../../mfc/reference/codesnippet/cpp/cwinapp-class_17.cpp)]  
  
##  <a name="m_pactivewnd"></a>CWinApp::m_pActiveWnd  
 Use este membro de dados para armazenar um ponteiro para a janela principal do aplicativo de contêiner OLE com seu servidor aplicativo in-loco OLE ativado.  
  
### <a name="remarks"></a>Comentários  
 Se este membro de dados é **nulo**, o aplicativo não está ativo no local.  
  
 A estrutura define essa variável de membro quando a janela do quadro é ativado por um aplicativo de contêiner OLE no local.  
  
##  <a name="m_pdatarecoveryhandler"></a>CWinApp::m_pDataRecoveryHandler  
 Ponteiro para o manipulador de recuperação de dados para o aplicativo.  
  
```  
CDataRecoveryHandler* m_pDataRecoveryHandler;  
```  
  
### <a name="remarks"></a>Comentários  
 O manipulador de recuperação de dados de um aplicativo monitora os documentos abertos e salve-os. A estrutura usa o manipulador de recuperação de dados para restaurar arquivos salva automaticamente quando um aplicativo ser reiniciado depois que ela sai inesperadamente. Para obter mais informações, consulte [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md).  
  
##  <a name="m_pszappname"></a>CWinApp::m_pszAppName  
 Especifica o nome do aplicativo.  
  
```  
LPCTSTR m_pszAppName;  
```  
  
### <a name="remarks"></a>Comentários  
 O nome do aplicativo pode vir do parâmetro passado para o [CWinApp](#cwinapp) construtor, ou, se não especificado para a cadeia de caracteres de recurso com a ID de **AFX_IDS_APP_TITLE**. Se o nome do aplicativo não for encontrado no recurso, ela é proveniente do programa. Nome do arquivo EXE.  
  
 Retornado pela função global [AfxGetAppName](application-information-and-management.md#afxgetappname). `m_pszAppName`é uma variável pública do tipo **char const\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszAppName`, devem ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Convém usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro de atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#57](../../mfc/reference/codesnippet/cpp/cwinapp-class_18.cpp)]  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#65](../../mfc/reference/codesnippet/cpp/cwinapp-class_19.cpp)]  
  
##  <a name="m_pszexename"></a>CWinApp::m_pszExeName  
 Contém o nome do arquivo executável do aplicativo sem uma extensão.  
  
```  
LPCTSTR m_pszExeName;  
```  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [m_pszAppName](#m_pszappname), esse nome não pode conter espaços em branco. `m_pszExeName`é uma variável pública do tipo **char const\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszExeName`, devem ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Convém usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro de atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#58](../../mfc/reference/codesnippet/cpp/cwinapp-class_20.cpp)]  
  
##  <a name="m_pszhelpfilepath"></a>CWinApp::m_pszHelpFilePath  
 Contém o caminho para o arquivo de Ajuda do aplicativo.  
  
```  
LPCTSTR m_pszHelpFilePath;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o framework inicializa `m_pszHelpFilePath` para o nome do aplicativo com ". HLP"acrescentada. Para alterar o nome do arquivo de Ajuda, defina `m_pszHelpFilePath` para apontar para uma cadeia de caracteres que contém o nome completo do arquivo de Ajuda desejado. É um local conveniente para fazer isso no aplicativo de [InitInstance](#initinstance) função. `m_pszHelpFilePath`é uma variável pública do tipo **char const\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszHelpFilePath`, devem ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Convém usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro de atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#59](../../mfc/reference/codesnippet/cpp/cwinapp-class_21.cpp)]  
  
##  <a name="m_pszprofilename"></a>CWinApp::m_pszProfileName  
 Contém o nome do aplicativo. Arquivo INI.  
  
```  
LPCTSTR m_pszProfileName;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_pszProfileName`é uma variável pública do tipo **char const\***.  
  
> [!NOTE]
>  Se você atribuir um valor para `m_pszProfileName`, devem ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Convém usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro de atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#60](../../mfc/reference/codesnippet/cpp/cwinapp-class_22.cpp)]  
  
##  <a name="m_pszregistrykey"></a>CWinApp::m_pszRegistryKey  
 Usado para determinar onde, no registro ou arquivo INI, configurações de perfil de aplicativo são armazenadas.  
  
```  
LPCTSTR m_pszRegistryKey;  
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, este membro de dados é tratado como somente leitura.  
  
-   O valor é armazenado em uma chave do registro. O nome para a configuração de perfil de aplicativo é anexado a seguinte chave do registro: HKEY_CURRENT_USER/Software/LocalAppWizard-gerados /.  
  
 Se você atribuir um valor para `m_pszRegistryKey`, devem ser dinamicamente alocado no heap. O `CWinApp` chamadas de destruidor **livre**() com esse ponteiro. Convém usar o `_tcsdup`função de biblioteca de tempo de execução () para fazer a alocação. Além disso, libere a memória associada ao ponteiro de atual antes de atribuir um novo valor. Por exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#61](../../mfc/reference/codesnippet/cpp/cwinapp-class_23.cpp)]  
  
##  <a name="m_pszappid"></a>CWinApp::m_pszAppID  
 ID de modelo de usuário do aplicativo.  
  
```  
LPCTSTR m_pszAppID;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oncontexthelp"></a>CWinApp::OnContextHelp  
 Lida com SHIFT + F1 Ajuda dentro do aplicativo.  
  
```  
afx_msg void OnContextHelp();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_CONTEXT_HELP, OnContextHelp )` instrução para sua `CWinApp` classe mapa de mensagem e também adicionar uma entrada de tabela do acelerador, normalmente SHIFT + F1, para habilitar essa função de membro.  
  
 `OnContextHelp`coloca o aplicativo em modo de Ajuda. O cursor muda para uma seta e um ponto de interrogação e o usuário pode, em seguida, mova o ponteiro do mouse e pressione o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Essa função de membro recupera o contexto da Ajuda do objeto sob o cursor e chama a função do Windows WinHelp com esse contexto da Ajuda.  
  
##  <a name="onddecommand"></a>CWinApp::OnDDECommand  
 Chamado pelo framework quando a janela do quadro principal recebe um DDE executar mensagem.  
  
```  
virtual BOOL OnDDECommand(LPTSTR lpszCommand);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszCommand*  
 Aponta para uma cadeia de caracteres de comando DDE recebidas pelo aplicativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando é tratado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão verifica se o comando é uma solicitação para abrir um documento e, nesse caso, abre o documento especificado. O Gerenciador de arquivos do Windows geralmente envia essas cadeias de caracteres de comando DDE quando o usuário clica duas vezes em um arquivo de dados. Substituir essa função para lidar com outros DDE executar comandos, como o comando Imprimir.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#48](../../mfc/reference/codesnippet/cpp/cwinapp-class_24.cpp)]  
  
##  <a name="onfilenew"></a>CWinApp::OnFileNew  
 Implementa o `ID_FILE_NEW` comando.  
  
```  
afx_msg void OnFileNew();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_FILE_NEW, OnFileNew )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, essa função lida com a execução do comando novo arquivo.  
  
 Consulte [22 de observação técnica](../../mfc/tn022-standard-commands-implementation.md) para obter informações sobre o comportamento padrão e orientação sobre como substituir essa função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]  
  
##  <a name="onfileopen"></a>CWinApp::OnFileOpen  
 Implementa o `ID_FILE_OPEN` comando.  
  
```  
afx_msg void OnFileOpen();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_FILE_OPEN, OnFileOpen )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, essa função lida com a execução do comando Abrir arquivo.  
  
 Para obter informações sobre o comportamento padrão e orientação sobre como substituir essa função de membro, consulte [22 de observação técnica](../../mfc/tn022-standard-commands-implementation.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]  
  
##  <a name="onfileprintsetup"></a>CWinApp::OnFilePrintSetup  
 Implementa o **ID_FILE_PRINT_SETUP** comando.  
  
```  
afx_msg void OnFilePrintSetup();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_FILE_PRINT_SETUP, OnFilePrintSetup )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, essa função lida com a execução do comando Imprimir do arquivo.  
  
 Para obter informações sobre o comportamento padrão e orientação sobre como substituir essa função de membro, consulte [22 de observação técnica](../../mfc/tn022-standard-commands-implementation.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#49](../../mfc/reference/codesnippet/cpp/cwinapp-class_25.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing#50](../../mfc/reference/codesnippet/cpp/cwinapp-class_26.cpp)]  
  
##  <a name="onhelp"></a>CWinApp::OnHelp  
 Manipula a Ajuda F1 dentro do aplicativo (usando o contexto atual).  
  
```  
afx_msg void OnHelp();
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente você também adicionará uma entrada de tecla de atalho para a tecla F1. Habilitar a tecla F1 é apenas uma convenção, não é um requisito.  
  
 Você deve adicionar um `ON_COMMAND( ID_HELP, OnHelp )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, chamado pelo framework quando o usuário pressiona a tecla F1.  
  
 A implementação padrão desta função de manipulador de mensagens determina o contexto de Ajuda que corresponde ao item de menu, caixa de diálogo ou janela atual e, em seguida, chama WINHELP. EXE. Se nenhum contexto está disponível no momento, a função usa o contexto padrão.  
  
 Substitua esta função de membro para definir o contexto de ajuda para algo diferente de janela, caixa de diálogo, o item de menu ou botão de barra de ferramentas que tem o foco no momento. Chamar `WinHelp` com o ajudam a ID do contexto.  
  
##  <a name="onhelpfinder"></a>CWinApp::OnHelpFinder  
 Manipula o **ID_HELP_FINDER** e **ID_DEFAULT_HELP** comandos.  
  
```  
afx_msg void OnHelpFinder();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_HELP_FINDER, OnHelpFinder )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, o framework chama esta função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando Ajuda localizador para invocar `WinHelp` com o padrão **HELP_FINDER** tópico.  
  
##  <a name="onhelpindex"></a>CWinApp::OnHelpIndex  
 Manipula o **ID_HELP_INDEX** de comando e fornece um tópico da Ajuda padrão.  
  
```  
afx_msg void OnHelpIndex();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_HELP_INDEX, OnHelpIndex )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. Se habilitada, o framework chama esta função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando de índice da Ajuda para invocar `WinHelp` com o padrão **HELP_INDEX** tópico.  
  
##  <a name="onhelpusing"></a>CWinApp::OnHelpUsing  
 Manipula o **ID_HELP_USING** comando.  
  
```  
afx_msg void OnHelpUsing();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve adicionar um `ON_COMMAND( ID_HELP_USING, OnHelpUsing )` instrução para sua `CWinApp` mapa de mensagem de classe para ativar essa função de membro. O framework chama esta função de manipulador de mensagens quando o usuário do seu aplicativo seleciona o comando Ajuda usando para invocar o `WinHelp` aplicativo com o padrão **HELP_HELPONHELP** tópico.  
  
##  <a name="onidle"></a>CWinApp::OnIdle  
 Substitua essa função de membro para executar o processamento de tempo ocioso.  
  
```  
virtual BOOL OnIdle(LONG lCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lCount`  
 Um contador incrementado toda vez que `OnIdle` é chamado quando a fila de mensagens do aplicativo está vazia. Esse contador é redefinido para 0, sempre que uma nova mensagem é processada. Você pode usar o `lCount` parâmetro para determinar o tamanho relativo de tempo que o aplicativo estiver ocioso sem processar uma mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero para receber o tempo de processamento mais ocioso; 0 se não houver mais tempo ocioso é necessária.  
  
### <a name="remarks"></a>Comentários  
 `OnIdle`é chamado no loop de mensagem padrão quando a fila de mensagens do aplicativo está vazia. Use sua substituição para chamar seu próprio plano de fundo tarefas manipulador ocioso.  
  
 `OnIdle`deve retornar 0 para indicar que nenhum tempo de processamento ocioso é necessário. O `lCount` parâmetro é incrementado toda vez que `OnIdle` é chamado quando a fila de mensagens está vazia e redefine como 0, sempre que uma nova mensagem é processada. Você pode chamar suas rotinas ociosas diferentes com base nessa contagem.  
  
 A seguir resume o processamento de loop ocioso:  
  
1.  Se o loop de mensagem na biblioteca Microsoft Foundation Class verifica a fila de mensagens e não localiza as mensagens pendentes, ele chama `OnIdle` para o objeto de aplicativo e fornece 0 como o `lCount` argumento.  
  
2. `OnIdle`executa algum processamento e retorna um valor diferente de zero para indicar que ele deve ser chamado novamente para fazer processamento adicional.  
  
3.  O loop de mensagens verifica a fila de mensagens novamente. Se nenhuma mensagem estiver pendente, ele chama `OnIdle` novamente, incrementando o `lCount` argumento.  
  
4.  Por fim, `OnIdle` termina de processar todas as tarefas de ociosidade e retornará 0. Isso informa o loop de mensagem para interromper a chamada `OnIdle` até que a próxima mensagem é recebida da fila de mensagens, no ponto em que o ciclo ocioso é reiniciado com o argumento definido como 0.  
  
 Não execute tarefas demoradas durante `OnIdle` porque o aplicativo não pode processar a entrada do usuário até `OnIdle` retorna.  
  
> [!NOTE]
>  A implementação padrão de `OnIdle` atualizações de objetos de interface do usuário como itens de menu e botões de barra de ferramentas de comando e executa a limpeza de estrutura de dados interno. Portanto, se você substituir `OnIdle`, você deve chamar `CWinApp::OnIdle` com o `lCount` na sua versão substituída. Primeiro chamar processamento ocioso todas as classes base (ou seja, até que a classe base `OnIdle` retorna 0). Se você precisar executar o trabalho antes do processamento de classe base for concluída, examine a implementação de classe base para selecionar o próprio `lCount` durante o qual trabalhar.  
  
 Se você não quiser `OnIdle` para ser chamado sempre que uma mensagem é recuperada da fila de mensagens, você pode substituir o [CWinThreadIsIdleMessage](../../mfc/reference/cwinthread-class.md#isidlemessage). Se um aplicativo tiver definido um temporizador muito curto, ou se o sistema está enviando o **WM_SYSTIMER** mensagem, em seguida, `OnIdle` será chamado repetidamente e prejudicar o desempenho.  
  
### <a name="example"></a>Exemplo  
 Os exemplos a seguir mostram como usar `OnIdle`. O primeiro exemplo processa duas tarefas ociosas usando o `lCount` argumento para priorizar as tarefas. A primeira tarefa é alta prioridade, e você deve fazê-lo sempre que possível. A segunda tarefa é menos importante e deve ser feita apenas quando houver uma pausa longa na entrada do usuário. Observe a chamada para a versão da classe base do `OnIdle`. O segundo exemplo gerencia um grupo de tarefas ociosas com prioridades diferentes.  
  
 [!code-cpp[NVC_MFCWindowing#51](../../mfc/reference/codesnippet/cpp/cwinapp-class_27.cpp)]  
  
##  <a name="opendocumentfile"></a>CWinApp::OpenDocumentFile  
 O framework chama esse método para abrir o nomeado [CDocument](../../mfc/reference/cdocument-class.md) arquivo para o aplicativo.  
  
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
 Um ponteiro para um `CDocument` se bem-sucedido; caso contrário `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Se um documento que tem esse nome já está aberto, a primeira janela do quadro que contém o documento receberá o foco. Se um aplicativo oferece suporte a vários modelos de documento, a estrutura usa a extensão de nome de arquivo para localizar o modelo de documento apropriado para tentar carregar o documento. Se for bem-sucedido, o modelo de documento, em seguida, cria uma janela do quadro e o modo de exibição para o documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#52](../../mfc/reference/codesnippet/cpp/cwinapp-class_16.cpp)]  
  
##  <a name="parsecommandline"></a>CWinApp::ParseCommandLine  
 Chamar essa função de membro para analisar a linha de comando e envio de parâmetros, um de cada vez, para [CCommandLineInfo::ParseParam](../../mfc/reference/ccommandlineinfo-class.md#parseparam).  
  
```  
void ParseCommandLine(CCommandLineInfo& rCmdInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rCmdInfo`  
 Uma referência a um [CCommandLineInfo](../../mfc/reference/ccommandlineinfo-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Quando você inicia um novo projeto MFC usando o Assistente de aplicativo, o Assistente de aplicativo criará uma instância local do `CCommandLineInfo`e, em seguida, chame `ProcessShellCommand` e `ParseCommandLine` no [InitInstance](#initinstance) função de membro. Uma linha de comando a seguir, a rota descrita abaixo:  
  
1.  Após ter sido criado em `InitInstance`, o `CCommandLineInfo` objeto é passado para `ParseCommandLine`.  
  
2. `ParseCommandLine`em seguida, chama `CCommandLineInfo::ParseParam` repetidamente, uma vez para cada parâmetro.  
  
3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é então passado para [ProcessShellCommand](#processshellcommand).  
  
4. `ProcessShellCommand`lida com os argumentos de linha de comando e sinalizadores.  
  
 Observe que você pode chamar `ParseCommandLine` diretamente, conforme necessário.  
  
 Para obter uma descrição dos sinalizadores de linha de comando, consulte [CCommandLineInfo::m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand).  
  
##  <a name="pretranslatemessage"></a>CWinApp::PreTranslateMessage  
 Substituir esta função para filtrar mensagens de janela antes de serem distribuídos para as funções do Windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) a implementação padrão executa tecla de aceleração tradução, você deve chamar o `CWinApp::PreTranslateMessage` a função de membro na sua versão substituída.  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Um ponteiro para um [MSG](../../mfc/reference/msg-structure1.md) estrutura que contém a mensagem para processar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi totalmente processada em `PreTranslateMessage` e não devem ser processados adicional. Zero se a mensagem deve ser processada da maneira normal.  
  
##  <a name="processmessagefilter"></a>CWinApp::ProcessMessageFilter  
 Função de gancho do framework chama esta função de membro para filtrar e responder a determinadas mensagens do Windows.  
  
```  
virtual BOOL ProcessMessageFilter(
    int code,  
    LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `code`  
 Especifica um código de interceptação. Essa função de membro usa o código para determinar como processar`lpMsg.`  
  
 `lpMsg`  
 Um ponteiro para um Windows [MSG](../../mfc/reference/msg-structure1.md) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é processada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma função de gancho processa eventos antes de serem enviados para a mensagem normal do aplicativo de processamento.  
  
 Se você substituir este recurso avançado, certifique-se de chamar a versão da classe base para manter a estrutura de gancho de processamento.  
  
##  <a name="processshellcommand"></a>CWinApp::ProcessShellCommand  
 Essa função de membro é chamada pelo [InitInstance](#initinstance) para aceitar os parâmetros passados do `CCommandLineInfo` objeto identificado por `rCmdInfo`e execute a ação indicada.  
  
```  
BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rCmdInfo`  
 Uma referência a um [CCommandLineInfo](../../mfc/reference/ccommandlineinfo-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando do shell é processado com êxito. Se for 0, retornar **FALSE** de [InitInstance](#initinstance).  
  
### <a name="remarks"></a>Comentários  
 Quando você inicia um novo projeto MFC usando o Assistente de aplicativo, o Assistente de aplicativo criará uma instância local do `CCommandLineInfo`e, em seguida, chame `ProcessShellCommand` e [ParseCommandLine](#parsecommandline) no `InitInstance` função de membro. Uma linha de comando a seguir, a rota descrita abaixo:  
  
1.  Após ter sido criado em `InitInstance`, o `CCommandLineInfo` objeto é passado para `ParseCommandLine`.  
  
2. `ParseCommandLine`em seguida, chama [CCommandLineInfo::ParseParam](../../mfc/reference/ccommandlineinfo-class.md#parseparam) repetidamente, uma vez para cada parâmetro.  
  
3. `ParseParam`preenche o `CCommandLineInfo` objeto, que é então passado para `ProcessShellCommand`.  
  
4. `ProcessShellCommand`lida com os argumentos de linha de comando e sinalizadores.  
  
 Os membros de dados de `CCommandLineInfo` objeto, identificado por [CCommandLineInfo::m_nShellCommand](../../mfc/reference/ccommandlineinfo-class.md#m_nshellcommand), são do tipo enumerado seguinte, que é definido dentro de `CCommandLineInfo` classe.  
  
```  
enum {
    FileNew,
    FileOpen,
    FilePrint,
    FilePrintTo,
    FileDDE
    };  
```
  
 Para obter uma descrição breve de cada um desses valores, consulte `CCommandLineInfo::m_nShellCommand`.  
  
##  <a name="processwndprocexception"></a>CWinApp::ProcessWndProcException  
 O framework chama esta função de membro sempre que o manipulador não capturar uma exceção gerada em uma das mensagens do aplicativo ou manipuladores de comandos.  
  
```  
virtual LRESULT ProcessWndProcException(
    CException* e,  
    const MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *e*  
 Um ponteiro para uma exceção não tratada.  
  
 `pMsg`  
 Um [MSG](../../mfc/reference/msg-structure1.md) estrutura que contém informações sobre a mensagem do windows que causou a estrutura lançar uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor deve ser retornado para o Windows. Normalmente isso é 0L para mensagens do windows, L 1 ( **TRUE**) para mensagens de comando.  
  
### <a name="remarks"></a>Comentários  
 Não chame diretamente essa função de membro.  
  
 A implementação padrão desta função de membro cria uma caixa de mensagem. Se a exceção não percebida se origina de um menu, a barra de ferramentas ou a falha do comando de teclas aceleradoras, a caixa de mensagem exibe uma mensagem "Falha no comando". Caso contrário, ele exibe uma mensagem de "Erro interno do aplicativo".  
  
 Substitua essa função de membro para fornecer manipulação global de sua exceções. Somente é chame a funcionalidade de base se desejar que a caixa de mensagem a ser exibida.  
  
##  <a name="register"></a>CWinApp::Register  
 Executa as tarefas de registro não tratadas por `RegisterShellFileTypes`.  
  
```  
virtual BOOL Register();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de sucesso; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão simplesmente retorna TRUE. Substitua essa função para fornecer todas as etapas de registro personalizadas.  
  
##  <a name="registershellfiletypes"></a>CWinApp::RegisterShellFileTypes  
 Chame essa função de membro para registrar todos os tipos de documento do aplicativo com o Gerenciador de arquivos do Windows.  
  
```  
void RegisterShellFileTypes(BOOL bCompat = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCompat`  
 `TRUE`Adiciona entradas de registro para comandos do shell de impressão e imprimir para, permitindo que um usuário imprima arquivos diretamente do shell ou arrastando o arquivo para um objeto de impressora. Ele também adiciona uma chave DefaultIcon. Por padrão, esse parâmetro é `FALSE` para compatibilidade com versões anteriores.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que o usuário abrir um arquivo de dados criado pelo seu aplicativo clicando nele de dentro do Gerenciador de arquivos. Chamar `RegisterShellFileTypes` depois de chamar [AddDocTemplate](#adddoctemplate) para cada um dos modelos de documento em seu aplicativo. Também chamada de [EnableShellOpen](#enableshellopen) função de membro ao chamar `RegisterShellFileTypes`.  
  
 `RegisterShellFileTypes`itera através da lista de [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objetos que o aplicativo mantém e, para cada modelo de documento, adiciona entradas para o banco de dados de registro que o Windows mantém para associações de arquivos. Gerenciador de arquivos usa essas entradas para abrir um arquivo de dados quando o usuário clica duas vezes nela. Isso elimina a necessidade de enviar um. Arquivo REG com o seu aplicativo.  
  
> [!NOTE]
> `RegisterShellFileTypes`só funcionará se o usuário executa o programa com direitos de administrador. Se o programa não tem direitos de administrador, ele não é possível alterar as chaves do registro.  
  
 Se o banco de dados de registro já associa uma extensão de nome de arquivo fornecido com outro tipo de arquivo, nenhuma nova associação será criada. Consulte o `CDocTemplate` classe para o formato de cadeias de caracteres necessárias para registrar essas informações.  
  
##  <a name="registerwithrestartmanager"></a>CWinApp::RegisterWithRestartManager  
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
|[in] `bRegisterRecoveryCallback`|`TRUE`indica que esta instância do aplicativo usa uma função de retorno de chamada de recuperação; `FALSE` indica que não. O framework chama a função de retorno de chamada de recuperação quando o aplicativo termina inesperadamente. Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|  
|[in] `strRestartIdentifier`|A cadeia de caracteres exclusiva que identifica esta instância do Gerenciador de reinicialização. O identificador de Gerenciador de reinicialização é exclusivo para cada instância de um aplicativo.|  
|[in] `pwzCommandLineArgs`|Uma cadeia de caracteres que contém quaisquer argumentos adicionais na linha de comando.|  
|[in] `dwRestartFlags`|Sinalizadores opcionais para o Gerenciador de reinicialização. Para obter mais informações, consulte a seção Comentários.|  
|[in] `pRecoveryCallback`|A função de retorno de chamada de recuperação. Essa função deve utilizar uma `LPVOID` parâmetro como entrada e retornar um `DWORD`. A função de retorno de chamada de recuperação padrão é `CWinApp::ApplicationRecoveryCallback`.|  
|[in] `lpvParam`|O parâmetro de entrada para a função de retorno de chamada de recuperação. Para obter mais informações, consulte [CWinApp::ApplicationRecoveryCallback](#applicationrecoverycallback).|  
|[in] `dwPingInterval`|O período de tempo que o Gerenciador de reinicialização aguarda a função de retorno de chamada de recuperação retornar. Esse parâmetro é em milissegundos.|  
|[in] `dwCallbackFlags`|Sinalizadores passados para a função de retorno de chamada de recuperação. Reservado para uso futuro.|  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se o método for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo usa a implementação do MFC padrão para arquivos de gravação automática, você deve usar a versão simple do `RegisterWithRestartManager`. Use a versão complexas de `RegisterWithRestartManager` se você deseja personalizar o comportamento de salvamento automático do seu aplicativo.  
  
 Se você chamar esse método com uma cadeia de caracteres vazia para `strRestartIdentifier`, `RegisterWithRestartManager` cria uma cadeia de caracteres de identificador exclusivo para esta instância do reinício Gerenciador.  
  
 Quando um aplicativo termina inesperadamente, o Gerenciador de reinicialização reinicia o aplicativo de linha de comando e fornece que exclusivos reiniciar identificador como um argumento opcional. Nesse cenário, o framework chama `RegisterWithRestartManager` duas vezes. A primeira chamada vem [CWinApp::InitInstance](#initinstance) com uma cadeia de caracteres vazia para o identificador de cadeia de caracteres. Em seguida, o método [CWinApp::ProcessShellCommand](#processshellcommand) chamadas `RegisterWithRestartManager` com o identificador exclusivo de reinicialização.  
  
 Depois de registrar um aplicativo com o Gerenciador de reinicialização, o Gerenciador de reinicialização monitora o aplicativo. Se o aplicativo fechar inesperadamente, o Gerenciador de reinicialização chama a função de retorno de chamada de recuperação durante o processo de desligamento. As esperas de Gerenciador de reinicialização de `dwPingInterval` por uma resposta da função de retorno de chamada de recuperação. Se a função de retorno de chamada de recuperação não responder dentro desse período, o aplicativo será encerrado sem executar a função de retorno de chamada de recuperação.  
  
 Por padrão, os dwRestartFlags não têm suporte, mas são fornecidos para uso futuro. Os valores possíveis para `dwRestartFlags` são da seguinte maneira:  
  
- `RESTART_NO_CRASH`  
  
- `RESTART_NO_HANG`  
  
- `RESTART_NO_PATCH`  
  
- `RESTART_NO_REBOOT`  
  
##  <a name="reopenpreviousfilesatrestart"></a>CWinApp::ReopenPreviousFilesAtRestart  
 Determina se o Gerenciador de reinicialização reaberto os arquivos que estavam abertos quando o aplicativo foi encerrado inesperadamente.  
  
```  
virtual BOOL ReopenPreviousFilesAtRestart() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica o Gerenciador de reinicialização reabre os arquivos abertos anteriormente; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="restartinstance"></a>CWinApp::RestartInstance  
 Lida com uma reinicialização do aplicativo iniciada pelo Gerenciador de reinicialização.  
  
```  
virtual BOOL CWinApp::RestartInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o manipulador de recuperação de dados é aberto anteriormente abrir documentos; `FALSE` se o manipulador de recuperação de dados tem um erro ou se não há documentos abertos anteriormente.  
  
### <a name="remarks"></a>Comentários  
 Quando o Gerenciador de reinicialização reinicia um aplicativo, o framework chama esse método. Esse método recupera o manipulador de recuperação de dados e restaura os arquivos salva automaticamente. Este método chama [CDataRecoveryHandler::RestoreAutosavedDocuments](../../mfc/reference/cdatarecoveryhandler-class.md#restoreautosaveddocuments) para determinar se o usuário deseja restaurar os arquivos salva automaticamente.  
  
 Este método retorna `FALSE` se o [CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md) determina que não houve nenhuma documentos abertos. Se não houver nenhum documento aberto, o aplicativo é iniciado normalmente.  
  
##  <a name="restoreautosavedfilesatrestart"></a>CWinApp::RestoreAutosavedFilesAtRestart  
 Determina se o Gerenciador de reinicialização restaura os arquivos de salva automaticamente quando ele reinicia o aplicativo.  
  
```  
virtual BOOL RestoreAutosavedFilesAtRestart() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica os reinicialização manager restaura salva automaticamente arquivos; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="run"></a>CWinApp:: Run  
 Fornece um loop de mensagem padrão.  
  
```  
virtual int Run();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `int` valor retornado por `WinMain`.  
  
### <a name="remarks"></a>Comentários  
 **Executar** adquire e envia mensagens do Windows até que o aplicativo recebe um **WM_QUIT** mensagem. Se a fila de mensagens do aplicativo no momento não contenha mensagens, **executar** chamadas [OnIdle](#onidle) para executar o processamento de tempo ocioso. Mensagens de entrada acessem o [PreTranslateMessage](#pretranslatemessage) função de membro para processamento especial e, em seguida, a função do Windows **TranslateMessage** para conversão de teclado padrão; por fim, o  **DispatchMessage** é chamada de função do Windows.  
  
 **Executar** raramente é substituído, mas você pode substituí-lo para fornecer um comportamento especial.  
  
##  <a name="runautomated"></a>CWinApp::RunAutomated  
 Chamar esta função para determinar se o " **/Automation**"ou" **-automação**" opção está presente, o que indica se o aplicativo de servidor foi iniciado por um aplicativo cliente.  
  
```  
BOOL RunAutomated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a opção foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se estiver presente, a opção é removida da linha de comando. Para obter mais informações sobre a automação OLE, consulte o artigo [servidores de automação](../../mfc/automation-servers.md).  
  
##  <a name="runembedded"></a>CWinApp::RunEmbedded  
 Chamar esta função para determinar se o " **/inserção**"ou" **-incorporando**" opção está presente, o que indica se o aplicativo de servidor foi iniciado por um aplicativo cliente.  
  
```  
BOOL RunEmbedded();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a opção foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se estiver presente, a opção é removida da linha de comando. Para obter mais informações sobre como incorporar, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md).  
  
##  <a name="saveallmodified"></a>CWinApp::SaveAllModified  
 Chamado pelo framework para salvar todos os documentos quando a janela do quadro principal do aplicativo é fechado, ou por meio de um `WM_QUERYENDSESSION` mensagem.  
  
```  
virtual BOOL SaveAllModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se seguro para encerrar o aplicativo; 0 se não é seguro para encerrar o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desta função de membro chama o [CDocument::SaveModified](../../mfc/reference/cdocument-class.md#savemodified) a função de membro para todos os documentos modificados dentro do aplicativo.  
  
##  <a name="selectprinter"></a>CWinApp::SelectPrinter  
 Chamar essa função de membro para selecionar uma impressora específica e, em seguida, solte a impressora que foi previamente selecionada na caixa de diálogo de impressão.  
  
```  
void SelectPrinter(
    HANDLE hDevNames,  
    HANDLE hDevMode,  
    BOOL bFreeOld = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDevNames`  
 Um identificador para um [DEVNAMES](../../mfc/reference/devnames-structure.md) estrutura que identifica o driver, o dispositivo e nomes de porta de saída de uma impressora específica.  
  
 `hDevMode`  
 Um identificador para um [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura que especifica informações sobre o ambiente de uma impressora e de inicialização do dispositivo.  
  
 *bFreeOld*  
 Libera a impressora selecionada anteriormente.  
  
### <a name="remarks"></a>Comentários  
 Se ambos os `hDevMode` e `hDevNames` são **nulo**, `SelectPrinter` usa a impressora padrão atual.  
  
##  <a name="sethelpmode"></a>CWinApp::SetHelpMode  
 Define o tipo de Ajuda do aplicativo.  
  
```  
void SetHelpMode(AFX_HELP_TYPE eHelpType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `eHelpType`  
 Especifica o tipo de ajuda para usar. Consulte [CWinApp::m_eHelpType](#m_ehelptype) para obter mais informações.  
  
### <a name="remarks"></a>Comentários  
 Define o tipo de Ajuda do aplicativo.  
  
 Para definir o tipo de Ajuda do seu aplicativo para Help, você pode chamar [EnableHTMLHelp](#enablehtmlhelp). Depois de você chamar `EnableHTMLHelp`, seu aplicativo deve usar o Help como seu aplicativo de Ajuda. Se você deseja alterar para usar WinHelp, você pode chamar `SetHelpMode` e defina `eHelpType` para **afxWinHelp**.  
  
##  <a name="setregistrykey"></a>CWinApp::SetRegistryKey  
 Faz com que as configurações de aplicativo a ser armazenado no registro em vez de arquivos INI.  
  
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
 Esta função define *m_pszRegistryKey*, que é usado pelo `GetProfileInt`, `GetProfileString`, `WriteProfileInt`, e `WriteProfileString` funções membro de `CWinApp`. Se essa função foi chamada, a lista de arquivos usados mais recentemente (MRU) também é armazenada no registro. A chave do registro geralmente é o nome de uma empresa. Ela é armazenada em uma chave da seguinte forma: HKEY_CURRENT_USER\\Software\\< nome da empresa\>\\< nome do aplicativo\>\\< nome da seção\>\\< valor nome\>.  
  
##  <a name="supportsapplicationrecovery"></a>CWinApp::SupportsApplicationRecovery  
 Determina se o Gerenciador de reinicialização recupera um aplicativo que foi encerrado inesperadamente.  
  
```  
virtual BOOL SupportsApplicationRecovery() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica a recupera do Gerenciador de reinicialização do aplicativo. `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="supportsautosaveatinterval"></a>CWinApp::SupportsAutosaveAtInterval  
 Determina se o salve do Gerenciador de reinicialização abre documentos em intervalos regulares.  
  
```  
virtual BOOL SupportsAutosaveAtInterval() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o salve do Gerenciador de reinicialização abre documentos; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="supportsautosaveatrestart"></a>CWinApp::SupportsAutosaveAtRestart  
 Determina se o salve do Gerenciador de reinicialização qualquer abra documentos quando o aplicativo for reiniciado.  
  
```  
virtual BOOL SupportsAutosaveAtRestart() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o salve do Gerenciador de reinicialização para abrir documentos quando o aplicativo ser reiniciado; `FALSE` indica que o Gerenciador de reinicialização não.  
  
##  <a name="supportsrestartmanager"></a>CWinApp::SupportsRestartManager  
 Determina se o aplicativo dá suporte ao Gerenciador de reinicialização.  
  
```  
virtual BOOL SupportsRestartManager() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o aplicativo oferece suporte para o Gerenciador de reinicialização. `FALSE` indica que o aplicativo não.  
  
##  <a name="unregister"></a>CWinApp::Unregister  
 Cancela o registro de todos os arquivos registrados pelo objeto de aplicativo.  
  
```  
virtual BOOL Unregister();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de sucesso; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `Unregister` função desfaz o registro executado pelo objeto de aplicativo e o [registrar](#register) função. Normalmente, ambas as funções são chamadas implicitamente pelo MFC e, portanto, não aparecerão em seu código.  
  
 Substitua esta função para executar as etapas de cancelamento de registro personalizadas.  
  
##  <a name="unregistershellfiletypes"></a>CWinApp::UnregisterShellFileTypes  
 Chame essa função de membro para cancelar o registro de todos os tipos de documento do aplicativo com o Gerenciador de arquivos do Windows.  
  
```  
void UnregisterShellFileTypes();
```  
  
##  <a name="winhelp"></a>CWinApp::WinHelp  
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
  
 A estrutura será fechada automaticamente o aplicativo WinHelp quando seu aplicativo é encerrado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#53](../../mfc/reference/codesnippet/cpp/cwinapp-class_28.cpp)]  
  
##  <a name="writeprofilebinary"></a>CWinApp::WriteProfileBinary  
 Chamar essa função de membro para gravar dados binários na seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL WriteProfileBinary(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    LPBYTE pData,  
    UINT nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ele será criado. O nome da seção é o caso independente; a cadeia de caracteres pode ser qualquer combinação de letras maiusculas e minúsculas.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor é a serem gravados. Se a entrada não existe na seção especificada, ele será criado.  
  
 `pData`  
 Pontos de dados a serem gravados.  
  
 `nBytes`  
 Contém o número de bytes a serem gravados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 Este exemplo usa `CWinApp* pApp = AfxGetApp();` para obter a classe de CWinApp ilustrando uma maneira que `WriteProfileBinary` e `GetProfileBinary` pode ser usado em qualquer função em um aplicativo MFC.  
  
 [!code-cpp[NVC_MFCWindowing#54](../../mfc/reference/codesnippet/cpp/cwinapp-class_29.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileBinary](#getprofilebinary).  
  
##  <a name="writeprofileint"></a>CWinApp::WriteProfileInt  
 Chamar essa função de membro para gravar o valor especificado para a seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL WriteProfileInt(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    int nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ele será criado. O nome da seção é o caso independente; a cadeia de caracteres pode ser qualquer combinação de letras maiusculas e minúsculas.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor é a serem gravados. Se a entrada não existe na seção especificada, ele será criado.  
  
 `nValue`  
 Contém o valor a ser gravado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 Este exemplo usa `CWinApp* pApp = AfxGetApp();` para obter a classe de CWinApp ilustrando uma maneira que `WriteProfileString`, `WriteProfileInt`, `GetProfileString`, e `GetProfileInt` pode ser usado em qualquer função em um aplicativo MFC.  
  
 [!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileInt](#getprofileint).  
  
##  <a name="writeprofilestring"></a>CWinApp::WriteProfileString  
 Chamar essa função de membro para gravar a cadeia de caracteres especificada na seção especificada do registro do aplicativo ou. Arquivo INI.  
  
```  
BOOL WriteProfileString(
    LPCTSTR lpszSection,  
    LPCTSTR lpszEntry,  
    LPCTSTR lpszValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSection`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica a seção que contém a entrada. Se a seção não existir, ele será criado. O nome da seção é o caso independente; a cadeia de caracteres pode ser qualquer combinação de letras maiusculas e minúsculas.  
  
 `lpszEntry`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém a entrada na qual o valor é a serem gravados. Se a entrada não existe na seção especificada, ele será criado. Se esse parâmetro for `NULL`, a seção especificada pelo `lpszSection` é excluído.  
  
 `lpszValue`  
 Aponta para a cadeia de caracteres a ser gravado. Se esse parâmetro for `NULL`, a entrada especificada pelo `lpszEntry` parâmetro é excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#43](../../mfc/reference/codesnippet/cpp/cwinapp-class_9.cpp)]  
  
 Outro exemplo, consulte o exemplo para [CWinApp::GetProfileInt](#getprofileint).  
  
##  <a name="setappid"></a>CWinApp::SetAppID  
 Define explicitamente o ID de modelo de usuário do aplicativo para o aplicativo. Este método deve ser chamado antes de qualquer interface de usuário é apresentada ao usuário (o melhor local é o construtor de aplicativo).  
  
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
 [Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)



