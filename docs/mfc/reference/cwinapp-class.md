---
title: "Classe de CWinApp | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CWinApp"
  - "hInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativo objetos [C++]"
  - "Classe de CWinApp"
  - "HINSTANCE"
  - "objeto principal"
ms.assetid: e426a3cd-0d15-40d6-bd55-beaa5feb2343
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinApp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base que você deriva de um objeto de aplicativo do Windows.  
  
## Sintaxe  
  
```  
class CWinApp : public CWinThread  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinApp::CWinApp](../Topic/CWinApp::CWinApp.md)|Constrói um objeto de `CWinApp` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinApp::AddDocTemplate](../Topic/CWinApp::AddDocTemplate.md)|Adiciona um modelo de documento de aplicativo à lista de modelos disponíveis do documento.|  
|[CWinApp::AddToRecentFileList](../Topic/CWinApp::AddToRecentFileList.md)|Adiciona um nome de arquivo para a lista recentemente usada do arquivo de \(MRU\).|  
|[CWinApp::ApplicationRecoveryCallback](../Topic/CWinApp::ApplicationRecoveryCallback.md)|Chamado pela estrutura quando o aplicativo sair inesperado.|  
|[CWinApp::CloseAllDocuments](../Topic/CWinApp::CloseAllDocuments.md)|Fecha todos os documentos abertos.|  
|[CWinApp::CreatePrinterDC](../Topic/CWinApp::CreatePrinterDC.md)|Cria um contexto de dispositivos de impressão.|  
|[CWinApp::DelRegTree](../Topic/CWinApp::DelRegTree.md)|Excluir uma chave especificada e todas as suas subchaves.|  
|[CWinApp::DoMessageBox](../Topic/CWinApp::DoMessageBox.md)|Implementa [AfxMessageBox](../Topic/AfxMessageBox.md) para o aplicativo.|  
|[CWinApp::DoWaitCursor](../Topic/CWinApp::DoWaitCursor.md)|Desliga o cursor de espera em e.|  
|[CWinApp::EnableD2DSupport](../Topic/CWinApp::EnableD2DSupport.md)|Permite que o suporte de `D2D` do aplicativo.  Chamar este método antes que a janela principal é inicializada.|  
|[CWinApp::EnableHtmlHelp](../Topic/CWinApp::EnableHtmlHelp.md)|Implementa HTMLHelp para o aplicativo, em vez de WinHelp.|  
|[CWinApp::EnableTaskbarInteraction](../Topic/CWinApp::EnableTaskbarInteraction.md)|Permite que a interação da barra de tarefas.|  
|[CWinApp::ExitInstance](../Topic/CWinApp::ExitInstance.md)|Substituição a limpeza quando o aplicativo finaliza.|  
|[CWinApp::GetApplicationRecoveryParameter](../Topic/CWinApp::GetApplicationRecoveryParameter.md)|Recupera o parâmetro de entrada para o método de recuperação do aplicativo.|  
|[CWinApp::GetApplicationRecoveryPingInterval](../Topic/CWinApp::GetApplicationRecoveryPingInterval.md)|Retorna o intervalo de tempo que o gerenciador de reinicialização espera a função de retorno de chamada de recuperação para retornar.|  
|[CWinApp::GetApplicationRestartFlags](../Topic/CWinApp::GetApplicationRestartFlags.md)|Retorna os sinalizadores para o gerenciador de configuração.|  
|[CWinApp::GetAppRegistryKey](../Topic/CWinApp::GetAppRegistryKey.md)|Retorna chave para HKEY\_CURRENT\_USER\\"Software"\\RegistryKey\\ProfileName.|  
|[CWinApp::GetDataRecoveryHandler](../Topic/CWinApp::GetDataRecoveryHandler.md)|Obtém o manipulador de recuperação de dados para essa instância do aplicativo.|  
|[CWinApp::GetFirstDocTemplatePosition](../Topic/CWinApp::GetFirstDocTemplatePosition.md)|Retorna a posição do primeiro modelo do documento.|  
|[CWinApp::GetHelpMode](../Topic/CWinApp::GetHelpMode.md)|Recupera o tipo da ajuda usado pelo aplicativo.|  
|[CWinApp::GetNextDocTemplate](../Topic/CWinApp::GetNextDocTemplate.md)|Retorna a posição de um modelo do documento.  Pode ser usado recursivamente.|  
|[CWinApp::GetPrinterDeviceDefaults](../Topic/CWinApp::GetPrinterDeviceDefaults.md)|Recupera as opções de dispositivos de impressão.|  
|[CWinApp::GetProfileBinary](../Topic/CWinApp::GetProfileBinary.md)|Recupera dados binários de uma entrada no arquivo .ini do aplicativo.|  
|[CWinApp::GetProfileInt](../Topic/CWinApp::GetProfileInt.md)|Retorna um inteiro de uma entrada no arquivo .ini do aplicativo.|  
|[CWinApp::GetProfileString](../Topic/CWinApp::GetProfileString.md)|Recupera uma cadeia de caracteres de uma entrada no arquivo .ini do aplicativo.|  
|[CWinApp::GetSectionKey](../Topic/CWinApp::GetSectionKey.md)|Retorna chave para HKEY\_CURRENT\_USER\\"Software"\\RegistryKey\\AppName\\lpszSection.|  
|[CWinApp::HideApplication](../Topic/CWinApp::HideApplication.md)|Oculta o aplicativo antes de fechar todos os documentos.|  
|[CWinApp::HtmlHelp](../Topic/CWinApp::HtmlHelp.md)|Chama a função do windows de `HTMLHelp` .|  
|[CWinApp::InitInstance](../Topic/CWinApp::InitInstance.md)|Substituição para executar o windows ativa a inicialização, como a criação de seus objetos da janela.|  
|[CWinApp::IsTaskbarInteractionEnabled](../Topic/CWinApp::IsTaskbarInteractionEnabled.md)|Informa se a interação da barra de tarefas do Windows 7 está habilitada.|  
|[CWinApp::LoadCursor](../Topic/CWinApp::LoadCursor.md)|Carrega um recurso do cursor.|  
|[CWinApp::LoadIcon](../Topic/CWinApp::LoadIcon.md)|Carrega um ícone de recursos.|  
|[CWinApp::LoadOEMCursor](../Topic/CWinApp::LoadOEMCursor.md)|Carrega um cursor predefinido OEM do windows que as constantes de **OCR\_** especifiquem em. WINDOWS.H.|  
|[CWinApp::LoadOEMIcon](../Topic/CWinApp::LoadOEMIcon.md)|Carrega um ícone predefinido OEM do windows que as constantes de **OIC\_** especifiquem em. WINDOWS.H.|  
|[CWinApp::LoadStandardCursor](../Topic/CWinApp::LoadStandardCursor.md)|Carrega um cursor predefinido o windows que as constantes de **IDC\_** especifiquem em. WINDOWS.H.|  
|[CWinApp::LoadStandardIcon](../Topic/CWinApp::LoadStandardIcon.md)|Carrega um ícone predefinido o windows que as constantes de **IDI\_** especifiquem em. WINDOWS.H.|  
|[CWinApp::OnDDECommand](../Topic/CWinApp::OnDDECommand.md)|Chamado pela estrutura em resposta a um equilíbrio dinâmicas de dados \(DDE\) executar o comando.|  
|[CWinApp::OnIdle](../Topic/CWinApp::OnIdle.md)|Substituição para executar o processamento específicas do aplicativo de tempo ocioso.|  
|[CWinApp::OpenDocumentFile](../Topic/CWinApp::OpenDocumentFile.md)|Chamado pela estrutura para abrir um documento de um arquivo.|  
|[CWinApp::ParseCommandLine](../Topic/CWinApp::ParseCommandLine.md)|Analisa parâmetros individuais e sinalizadores na linha de comando.|  
|[CWinApp::PreTranslateMessage](../Topic/CWinApp::PreTranslateMessage.md)|Mensagens de filtro antes que elas sejam despachados funções do windows [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934).|  
|[CWinApp::ProcessMessageFilter](../Topic/CWinApp::ProcessMessageFilter.md)|Determinadas mensagens de intercepções antes que atingiu o aplicativo.|  
|[CWinApp::ProcessShellCommand](../Topic/CWinApp::ProcessShellCommand.md)|Argumentos de linha de comando e sinalizadores handles.|  
|[CWinApp::ProcessWndProcException](../Topic/CWinApp::ProcessWndProcException.md)|Intercepta todas as exceções não tratadas geradas por manipuladores de mensagem e de comando do aplicativo.|  
|[CWinApp::Register](../Topic/CWinApp::Register.md)|Performs personalizou o registro.|  
|[CWinApp::RegisterWithRestartManager](../Topic/CWinApp::RegisterWithRestartManager.md)|Registra o aplicativo com o gerenciador de configuração.|  
|[CWinApp::ReopenPreviousFilesAtRestart](../Topic/CWinApp::ReopenPreviousFilesAtRestart.md)|Determina se o gerenciador de reinicialização reabre os arquivos que foram abertos quando o aplicativo foi encerrado inesperado.|  
|[CWinApp::RestartInstance](../Topic/CWinApp::RestartInstance.md)|Trata a reinicialização do aplicativo iniciado pelo gerenciador de configuração.|  
|[CWinApp::RestoreAutosavedFilesAtRestart](../Topic/CWinApp::RestoreAutosavedFilesAtRestart.md)|Determina se o gerenciador de reinicialização restaurar os arquivos autosaved quando reiniciar o aplicativo.|  
|[CWinApp::Run](../Topic/CWinApp::Run.md)|Executa o loop de mensagem padrão.  Substituição para personalizar o loop de mensagens.|  
|[CWinApp::RunAutomated](../Topic/CWinApp::RunAutomated.md)|Testa a linha de comando do aplicativo para a opção de **\/Automation** .  Obsoleto.  Em vez de isso, use o valor em [CCommandLineInfo::m\_bRunAutomated](../Topic/CCommandLineInfo::m_bRunAutomated.md) após chamar [ParseCommandLine](../Topic/CWinApp::ParseCommandLine.md).|  
|[CWinApp::RunEmbedded](../Topic/CWinApp::RunEmbedded.md)|Testa a linha de comando do aplicativo para a opção de **\/Embedding** .  Obsoleto.  Em vez de isso, use o valor em [CCommandLineInfo::m\_bRunEmbedded](../Topic/CCommandLineInfo::m_bRunEmbedded.md) após chamar [ParseCommandLine](../Topic/CWinApp::ParseCommandLine.md).|  
|[CWinApp::SaveAllModified](../Topic/CWinApp::SaveAllModified.md)|Solicita ao usuário para salvar todos os documentos alterados.|  
|[CWinApp::SelectPrinter](../Topic/CWinApp::SelectPrinter.md)|Seleciona uma impressora indicada anteriormente pelo usuário através de uma caixa de diálogo.|  
|[CWinApp::SetHelpMode](../Topic/CWinApp::SetHelpMode.md)|Os conjuntos e inicializam o tipo da ajuda usado pelo aplicativo.|  
|[CWinApp::SupportsApplicationRecovery](../Topic/CWinApp::SupportsApplicationRecovery.md)|Determina se o gerenciador de reinicialização recupera um aplicativo de sair inesperado.|  
|[CWinApp::SupportsAutosaveAtInterval](../Topic/CWinApp::SupportsAutosaveAtInterval.md)|Determina se o gerenciador de reinicialização autosaves documentos abertos em um intervalo normal.|  
|[CWinApp::SupportsAutosaveAtRestart](../Topic/CWinApp::SupportsAutosaveAtRestart.md)|Determina se o gerenciador de reinicialização autosaves os documentos abertos quando o aplicativo for reiniciado.|  
|[CWinApp::SupportsRestartManager](../Topic/CWinApp::SupportsRestartManager.md)|Determina se o aplicativo suporta o gerenciador de configuração.|  
|[CWinApp::Unregister](../Topic/CWinApp::Unregister.md)|Desregistre todos conhecidos para ser registrado pelo objeto de `CWinApp` .|  
|[CWinApp::WinHelp](../Topic/CWinApp::WinHelp.md)|Chama a função do windows de `WinHelp` .|  
|[CWinApp::WriteProfileBinary](../Topic/CWinApp::WriteProfileBinary.md)|Grava dados binários a uma entrada no arquivo .ini do aplicativo.|  
|[CWinApp::WriteProfileInt](../Topic/CWinApp::WriteProfileInt.md)|Grava um inteiro para uma entrada no arquivo .ini do aplicativo.|  
|[CWinApp::WriteProfileString](../Topic/CWinApp::WriteProfileString.md)|Grava uma cadeia de caracteres a uma entrada no arquivo .ini do aplicativo.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinApp::EnableShellOpen](../Topic/CWinApp::EnableShellOpen.md)|Permite que o usuário abre arquivos de dados do gerenciador de arquivos do windows.|  
|[CWinApp::LoadStdProfileSettings](../Topic/CWinApp::LoadStdProfileSettings.md)|Carrega configurações padrão do arquivo .ini e permite que o recurso de lista do arquivo de MRU.|  
|[CWinApp::OnContextHelp](../Topic/CWinApp::OnContextHelp.md)|Ajuda handles SHIFT\+F1 dentro do aplicativo.|  
|[CWinApp::OnFileNew](../Topic/CWinApp::OnFileNew.md)|Implementa o comando de `ID_FILE_NEW` .|  
|[CWinApp::OnFileOpen](../Topic/CWinApp::OnFileOpen.md)|Implementa o comando de `ID_FILE_OPEN` .|  
|[CWinApp::OnFilePrintSetup](../Topic/CWinApp::OnFilePrintSetup.md)|Implementa o comando de `ID_FILE_PRINT_SETUP` .|  
|[CWinApp::OnHelp](../Topic/CWinApp::OnHelp.md)|F1 ajuda handles dentro do aplicativo \(que usa o contexto atual.\)|  
|[CWinApp::OnHelpFinder](../Topic/CWinApp::OnHelpFinder.md)|Trata os comandos de `ID_HELP_FINDER` e de `ID_DEFAULT_HELP` .|  
|[CWinApp::OnHelpIndex](../Topic/CWinApp::OnHelpIndex.md)|Trata o comando de `ID_HELP_INDEX` e fornece um tópico da Ajuda padrão.|  
|[CWinApp::OnHelpUsing](../Topic/CWinApp::OnHelpUsing.md)|Trata o comando de `ID_HELP_USING` .|  
|[CWinApp::RegisterShellFileTypes](../Topic/CWinApp::RegisterShellFileTypes.md)|Registrar os tipos de documento de qualquer aplicativo com o gerenciador de arquivos do windows.|  
|[CWinApp::SetAppID](../Topic/CWinApp::SetAppID.md)|Define explicitamente a identificação do modelo de usuário do aplicativo para o aplicativo.  Esse método deve ser chamado antes que qualquer interface de usuário seja projetada para o usuário \(melhor local é o construtor do aplicativo\).|  
|[CWinApp::SetRegistryKey](../Topic/CWinApp::SetRegistryKey.md)|Faz com que as configurações do aplicativo sejam armazenadas no Registro em vez dos arquivos de .INI.|  
|[CWinApp::UnregisterShellFileTypes](../Topic/CWinApp::UnregisterShellFileTypes.md)|Desregistre os tipos de documento de qualquer aplicativo com o gerenciador de arquivos do windows.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinApp::m\_bHelpMode](../Topic/CWinApp::m_bHelpMode.md)|Indica se o usuário está no modo de contexto da ajuda \(normalmente chamado com SHIFT\+F1\).|  
|[CWinApp::m\_eHelpType](../Topic/CWinApp::m_eHelpType.md)|Especifica o tipo da ajuda usado pelo aplicativo.|  
|[CWinApp::m\_hInstance](../Topic/CWinApp::m_hInstance.md)|Identifica a instância atual do aplicativo.|  
|[CWinApp::m\_lpCmdLine](../Topic/CWinApp::m_lpCmdLine.md)|Aponta para uma cadeia de caracteres NULL\- finalizada que especifica a linha de comando para o aplicativo.|  
|[CWinApp::m\_nCmdShow](../Topic/CWinApp::m_nCmdShow.md)|Especifica como a janela deve ser mostrada inicialmente.|  
|[CWinApp::m\_pActiveWnd](../Topic/CWinApp::m_pActiveWnd.md)|Ponteiro para a janela principal do aplicativo quando um contêiner de servidor OLE está no lugar.|  
|[CWinApp::m\_pszAppID](../Topic/CWinApp::m_pszAppID.md)|Identificação do modelo de usuário do aplicativo|  
|[CWinApp::m\_pszAppName](../Topic/CWinApp::m_pszAppName.md)|Especifica o nome do aplicativo.|  
|[CWinApp::m\_pszExeName](../Topic/CWinApp::m_pszExeName.md)|O nome do módulo do aplicativo.|  
|[CWinApp::m\_pszHelpFilePath](../Topic/CWinApp::m_pszHelpFilePath.md)|O caminho para o arquivo de ajuda do aplicativo.|  
|[CWinApp::m\_pszProfileName](../Topic/CWinApp::m_pszProfileName.md)|O nome de arquivo de .INI do aplicativo.|  
|[CWinApp::m\_pszRegistryKey](../Topic/CWinApp::m_pszRegistryKey.md)|Usado para determinar a chave do Registro completa para armazenar configurações de perfil do aplicativo.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinApp::m\_dwRestartManagerSupportFlags](../Topic/CWinApp::m_dwRestartManagerSupportFlags.md)|Sinalizadores que determinam como o gerenciador de reinicialização se comporta.|  
|[CWinApp::m\_nAutosaveInterval](../Topic/CWinApp::m_nAutosaveInterval.md)|O período de tempo em milissegundos entre autosaves.|  
|[CWinApp::m\_pDataRecoveryHandler](../Topic/CWinApp::m_pDataRecoveryHandler.md)|Ponteiro para o manipulador de recuperação de dados para o aplicativo.|  
  
## Comentários  
 Um objeto application fornece funções de membro para inicializar seu aplicativo \(e cada instância de ele\) e executar o aplicativo.  
  
 Cada aplicativo que usa as classes de base da Microsoft pode conter somente um objeto derivado de `CWinApp`.  Este objeto é construído quando outros objetos globais C\+\+ são construídos e já está disponível quando o chama a função de `WinMain` , que é fornecida pela biblioteca de classes da Microsoft foundation.  Declare o objeto derivado de `CWinApp` no nível global.  
  
 Quando você derivado de uma classe de aplicativo de `CWinApp`, substitua a função de membro de [InitInstance](../Topic/CWinApp::InitInstance.md) para criar o objeto da janela principal do seu aplicativo.  
  
 Além das funções de membro de `CWinApp` , a biblioteca de classes de base do Microsoft fornece as seguintes funções globais para acessar o objeto de `CWinApp` e outras informações globais:  
  
-   [AfxGetApp](../Topic/AfxGetApp.md) obtém um ponteiro para o objeto de `CWinApp` .  
  
-   [AfxGetInstanceHandle](../Topic/AfxGetInstanceHandle.md) obtém um identificador para a instância do aplicativo atual.  
  
-   [AfxGetResourceHandle](../Topic/AfxGetResourceHandle.md) obtém um identificador para recursos do aplicativo.  
  
-   [AfxGetAppName](../Topic/AfxGetAppName.md) obtém um ponteiro para uma cadeia de caracteres que contém o nome do aplicativo.  Como alternativa, se você tiver um ponteiro para o objeto de `CWinApp` , use `m_pszExeName` para obter o nome do aplicativo.  
  
 Consulte para obter mais [CWinApp: A classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md) na classe de `CWinApp` , incluindo uma visão geral do seguinte:  
  
-   `CWinApp`\- derivado código escrito pelo assistente do aplicativo.  
  
-   A função de `CWinApp` na seqüência de execução do seu aplicativo.  
  
-   Implementações padrão da função de membro de `CWinApp`.  
  
-   Os substituíveis chave de `CWinApp`.  
  
 O membro de dados de **m\_hPrevInstance** ainda não existir.  Para obter informações sobre como detectar uma instância anterior de `CWinApp`, consulte o artigo de Base de Dados de Conhecimento “como identificar uma instância anterior de um aplicativo KB106385 \(”\) em [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;106385](http://support.microsoft.com/default.aspx?scid=kb;en-us;106385).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 `CWinApp`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CWinThread](../../mfc/reference/cwinthread-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)