---
title: "Classe de CHtmlView | Microsoft Docs"
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
  - "CHtmlView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "navegadores, Suporte para MFC"
  - "Classe de CHtmlView"
  - "Controle da web browser"
  - "Controle da web browser, Suporte MFC"
ms.assetid: 904976af-73de-4aba-84ac-cfae8e2be09a
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHtmlView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle da web browser dentro do contexto do documento MFC\/arquitetura de exibição.  
  
## Sintaxe  
  
```  
class CHtmlView : public CFormView  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHtmlView::Create](../Topic/CHtmlView::Create.md)|Cria o controle da web browser.|  
|[CHtmlView::CreateControlSite](../Topic/CHtmlView::CreateControlSite.md)|Overridable usado para criar uma instância do site do controle para hospedar um controle no formulário.|  
|[CHtmlView::ExecFormsCommand](../Topic/CHtmlView::ExecFormsCommand.md)|Executa o comando especificado usando o método de `IOleCommandTarget::Exec` .|  
|[CHtmlView::ExecWB](../Topic/CHtmlView::ExecWB.md)|Executa um comando.|  
|[CHtmlView::GetAddressBar](../Topic/CHtmlView::GetAddressBar.md)|Determina se a barra de endereços do objeto do Internet Explorer é visível.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::GetApplication](../Topic/CHtmlView::GetApplication.md)|Recupera um objeto de aplicativo que representa o aplicativo que contém a instância atual do aplicativo do Internet Explorer.|  
|[CHtmlView::GetBusy](../Topic/CHtmlView::GetBusy.md)|Obtém um valor indicando se um download ou outra atividade é ainda em andamento.|  
|[CHtmlView::GetContainer](../Topic/CHtmlView::GetContainer.md)|Recupera o contêiner do controle da web browser.|  
|[CHtmlView::GetFullName](../Topic/CHtmlView::GetFullName.md)|Retorna o nome completo, incluindo o caminho de recurso, exibido no navegador da web.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::GetFullScreen](../Topic/CHtmlView::GetFullScreen.md)|Indica se o controle da web browser está funcionando no modo de tela cheia ou no modo normal da janela.|  
|[CHtmlView::GetHeight](../Topic/CHtmlView::GetHeight.md)|Recupera a altura da janela principal do Internet Explorer.|  
|[CHtmlView::GetHtmlDocument](../Topic/CHtmlView::GetHtmlDocument.md)|Recupera o documento ativo HTML.|  
|[CHtmlView::GetLeft](../Topic/CHtmlView::GetLeft.md)|Recupera a coordenada da tela da borda esquerda da janela principal do Internet Explorer.|  
|[CHtmlView::GetLocationName](../Topic/CHtmlView::GetLocationName.md)|Recupera o nome do recurso navegador da web que está exibindo atualmente|  
|[CHtmlView::GetLocationURL](../Topic/CHtmlView::GetLocationURL.md)|Recupera o URL de recurso que navegador da web está exibindo atualmente.|  
|[CHtmlView::GetMenuBar](../Topic/CHtmlView::GetMenuBar.md)|Retorna um valor que determina se a barra de menu é visível.|  
|[CHtmlView::GetOffline](../Topic/CHtmlView::GetOffline.md)|Retorna um valor que determina se o controle está off\-line.|  
|[CHtmlView::GetParentBrowser](../Topic/CHtmlView::GetParentBrowser.md)|Recupera um ponteiro para a interface de `IDispatch` .  Para mais informações, consulte [Implementing the IDispatch Interface](http://msdn.microsoft.com/pt-br/0e171f7f-0022-4e9b-ac8e-98192828e945).|  
|[CHtmlView::GetProperty](../Topic/CHtmlView::GetProperty.md)|Recupera o valor atual de uma propriedade associada com o dado objeto.|  
|[CHtmlView::GetReadyState](../Topic/CHtmlView::GetReadyState.md)|Recupera o estado pronto do navegador da web.|  
|[CHtmlView::GetRegisterAsBrowser](../Topic/CHtmlView::GetRegisterAsBrowser.md)|Indica se o controle da web browser está registrado como um navegador de nível superior para o resolução de destino do.|  
|[CHtmlView::GetRegisterAsDropTarget](../Topic/CHtmlView::GetRegisterAsDropTarget.md)|Indica se o controle da web browser está registrado como um destino alvo para navegação.|  
|[CHtmlView::GetSilent](../Topic/CHtmlView::GetSilent.md)|Indica se alguma caixa de diálogo pode ser exibida.|  
|[CHtmlView::GetSource](../Topic/CHtmlView::GetSource.md)|O código de código HTML da página.|  
|[CHtmlView::GetStatusBar](../Topic/CHtmlView::GetStatusBar.md)|Indica se a barra de status da Internet Explorer é visível.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::GetTheaterMode](../Topic/CHtmlView::GetTheaterMode.md)|Indica se o controle da web browser está no modo de produtor.|  
|[CHtmlView::GetToolBar](../Topic/CHtmlView::GetToolBar.md)|Retorna um valor que determina se a barra de ferramentas é visível.|  
|[CHtmlView::GetTop](../Topic/CHtmlView::GetTop.md)|Recupera a coordenada da tela da borda superior da janela principal do Internet Explorer.|  
|[CHtmlView::GetTopLevelContainer](../Topic/CHtmlView::GetTopLevelContainer.md)|Obtém um valor indicando se o objeto atual é o recipiente de nível superior do controle da web browser.|  
|[CHtmlView::GetType](../Topic/CHtmlView::GetType.md)|Recupera o nome do tipo de objeto de documento.|  
|[CHtmlView::GetVisible](../Topic/CHtmlView::GetVisible.md)|Obtém um valor indicando se o objeto é visível ou oculto.|  
|[CHtmlView::GetWidth](../Topic/CHtmlView::GetWidth.md)|Obtém a largura da janela principal do Internet Explorer.|  
|[CHtmlView::GoBack](../Topic/CHtmlView::GoBack.md)|Navega para o item anterior na lista histórico.|  
|[CHtmlView::GoForward](../Topic/CHtmlView::GoForward.md)|Navega para o próximo item na lista histórico.|  
|[CHtmlView::GoHome](../Topic/CHtmlView::GoHome.md)|Navega para o início ou à página inicial atual.|  
|[CHtmlView::GoSearch](../Topic/CHtmlView::GoSearch.md)|Navega para a página atual de pesquisa.|  
|[CHtmlView::LoadFromResource](../Topic/CHtmlView::LoadFromResource.md)|Carrega um recurso no controle da web browser.|  
|[CHtmlView::Navigate](../Topic/CHtmlView::Navigate.md)|Navega para o recurso identificado por um URL.|  
|[CHtmlView::Navigate2](../Topic/CHtmlView::Navigate2.md)|Navega para o recurso identificado por um URL, ou o arquivo identificado por um caminho completo.|  
|[CHtmlView::OnBeforeNavigate2](../Topic/CHtmlView::OnBeforeNavigate2.md)|Chamado antes de uma navegação ocorre no navegador da web \(determinado em uma janela ou no elemento do frameset\).|  
|[CHtmlView::OnCommandStateChange](../Topic/CHtmlView::OnCommandStateChange.md)|Chamado para notificar um aplicativo que o estado habilitado de comando da web browser foi alterado.|  
|[CHtmlView::OnDocumentComplete](../Topic/CHtmlView::OnDocumentComplete.md)|Chamado para notificar um aplicativo que um documento alcançar o estado de `READYSTATE_COMPLETE` .|  
|[CHtmlView::OnDocWindowActivate](../Topic/CHtmlView::OnDocWindowActivate.md)|Chamado da Internet Explorer ou implementação de MSHTML de [IOleInPlaceActiveObject::OnDocWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms687281), que notifica o objeto no lugar ativa quando a janela do documento de contêiner está ativado ou desativada.|  
|[CHtmlView::OnDownloadBegin](../Topic/CHtmlView::OnDownloadBegin.md)|Chamado para notificar um aplicativo que uma operação de navegação é inicial.|  
|[CHtmlView::OnDownloadComplete](../Topic/CHtmlView::OnDownloadComplete.md)|Chamado quando uma operação de navegação concluída, foi interrompida, ou falha.|  
|[CHtmlView::OnEnableModeless](../Topic/CHtmlView::OnEnableModeless.md)|Chamado para ativar ou desativar caixas de diálogo sem\-modo quando o contêiner criar ou destruir uma caixa de diálogo modal.|  
|[CHtmlView::OnFilterDataObject](../Topic/CHtmlView::OnFilterDataObject.md)|Chamou o host pelo Internet Explorer ou por MSHTML para permitir que o host substitui o Internet Explorer ou objeto de dados de MSHTML.|  
|[CHtmlView::OnFrameWindowActivate](../Topic/CHtmlView::OnFrameWindowActivate.md)|Chamado de [IOleInPlaceActiveObject::OnFrameWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms683969) para notificar o objeto quando a janela de nível superior do quadro do recipiente é ativada ou desativada.|  
|[CHtmlView::OnFullScreen](../Topic/CHtmlView::OnFullScreen.md)|Chamado quando a propriedade FullScreen alterar.|  
|[CHtmlView::OnGetDropTarget](../Topic/CHtmlView::OnGetDropTarget.md)|Chamado pelo Internet Explorer ou por MSHTML quando é usado como um destino alvo para permitir que o host fornecer [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679)alternativo.|  
|[CHtmlView::OnGetExternal](../Topic/CHtmlView::OnGetExternal.md)|Chamado pelo Internet Explorer ou por MSHTML para obter a interface de `IDispatch` host.|  
|[CHtmlView::OnGetHostInfo](../Topic/CHtmlView::OnGetHostInfo.md)|Recupera os recursos de interface do usuário host do Internet Explorer ou de MSHTML.|  
|[CHtmlView::OnGetOptionKeyPath](../Topic/CHtmlView::OnGetOptionKeyPath.md)|Retorna a chave de Registro em que o Internet Explorer ou MSHTML armazenam preferências do usuário.|  
|[CHtmlView::OnHideUI](../Topic/CHtmlView::OnHideUI.md)|Chamado quando o Internet Explorer ou MSHTML removerem os menus e barras de ferramentas.|  
|[CHtmlView::OnMenuBar](../Topic/CHtmlView::OnMenuBar.md)|Chamado quando a propriedade do MenuBar alterar.|  
|[CHtmlView::OnNavigateComplete2](../Topic/CHtmlView::OnNavigateComplete2.md)|Chamado após uma navegação a um hiperlink concluída \(em uma janela ou no elemento do frameset\).|  
|[CHtmlView::OnNavigateError](../Topic/CHtmlView::OnNavigateError.md)|Chamado pela estrutura se a navegação a um hiperlink falhar.|  
|[CHtmlView::OnNewWindow2](../Topic/CHtmlView::OnNewWindow2.md)|Chamado quando uma nova janela deve ser criada exibindo um recurso.|  
|[CHtmlView::OnProgressChange](../Topic/CHtmlView::OnProgressChange.md)|Chamado para notificar um aplicativo que o progresso de uma operação de download foi atualizado.|  
|[CHtmlView::OnPropertyChange](../Topic/CHtmlView::OnPropertyChange.md)|Chamado para notificar um aplicativo que o método de [PutProperty](../Topic/CHtmlView::PutProperty.md) alterou o valor de uma propriedade.|  
|[CHtmlView::OnQuit](../Topic/CHtmlView::OnQuit.md)|Chamado para notificar um aplicativo que o aplicativo do Internet Explorer está pronto para parar.  \(Se aplica somente a Internet Explorer\)|  
|[CHtmlView::OnResizeBorder](../Topic/CHtmlView::OnResizeBorder.md)|Chamado da Internet Explorer ou implementação de MSHTML de [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053), que alertam o objeto que precisam redimensionar o espaço da borda.|  
|[CHtmlView::OnShowContextMenu](../Topic/CHtmlView::OnShowContextMenu.md)|Chamada da Internet Explorer ou de MSHTML quando é o ponto de exibir seu menu de contexto.|  
|[CHtmlView::OnShowUI](../Topic/CHtmlView::OnShowUI.md)|Chamado antes da Internet Explorer ou de MSHTML exibe os menus e barras de ferramentas.|  
|[CHtmlView::OnStatusBar](../Topic/CHtmlView::OnStatusBar.md)|Chamado quando a propriedade StatusBar alterar.|  
|[CHtmlView::OnStatusTextChange](../Topic/CHtmlView::OnStatusTextChange.md)|Chamado para notificar um aplicativo que o texto da barra de status associado com o controle da web browser foi alterado.|  
|[CHtmlView::OnTheaterMode](../Topic/CHtmlView::OnTheaterMode.md)|Chamado quando a propriedade de TheaterMode alterar.|  
|[CHtmlView::OnTitleChange](../Topic/CHtmlView::OnTitleChange.md)|Chamado para notificar um aplicativo se o título de um documento no controle da web browser se torna disponível ou muda.|  
|[CHtmlView::OnToolBar](../Topic/CHtmlView::OnToolBar.md)|Chamado quando a propriedade da barra de ferramentas alterar.|  
|[CHtmlView::OnTranslateAccelerator](../Topic/CHtmlView::OnTranslateAccelerator.md)|Chamado pelo Internet Explorer ou por MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693360) ou [IOleControlSite::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693756) são chamados para processar mensagens de tecla aceleradora de menu de fila de mensagens do recipiente.|  
|[CHtmlView::OnTranslateUrl](../Topic/CHtmlView::OnTranslateUrl.md)|Chamado pelo Internet Explorer ou por MSHTML para permitir ao host uma oportunidade para alterar o URL a ser carregado.|  
|[CHtmlView::OnUpdateUI](../Topic/CHtmlView::OnUpdateUI.md)|Notifica o host que o estado de comando foi alterado.|  
|[CHtmlView::OnVisible](../Topic/CHtmlView::OnVisible.md)|Chamado quando a janela para o controle da web browser deve ser mostrada\/oculto.|  
|[CHtmlView::PutProperty](../Topic/CHtmlView::PutProperty.md)|Defina o valor de uma propriedade associada com o dado objeto.|  
|[CHtmlView::QueryFormsCommand](../Topic/CHtmlView::QueryFormsCommand.md)|Consultas para o status de um ou mais comandos gerados por eventos da interface do usuário.|  
|[CHtmlView::QueryStatusWB](../Topic/CHtmlView::QueryStatusWB.md)|Consulta o status de um comando que está sendo processado pelo controle da web browser.|  
|[CHtmlView::Refresh](../Topic/CHtmlView::Refresh.md)|Recarrega o arquivo atual.|  
|[CHtmlView::Refresh2](../Topic/CHtmlView::Refresh2.md)|Recarrega o arquivo atual e opcionalmente impede que o cabeçalho de `pragma:nocache` ser enviado.|  
|[CHtmlView::SetAddressBar](../Topic/CHtmlView::SetAddressBar.md)|Mostra ou oculta a barra de endereços do objeto do Internet Explorer.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::SetFullScreen](../Topic/CHtmlView::SetFullScreen.md)|Define um valor para determinar se o controle está funcionando no modo de tela cheia ou no modo normal da janela.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::SetHeight](../Topic/CHtmlView::SetHeight.md)|Defina a altura da janela principal do Internet Explorer.|  
|[CHtmlView::SetLeft](../Topic/CHtmlView::SetLeft.md)|Define a posição horizontal da janela principal do Internet Explorer.|  
|[CHtmlView::SetMenuBar](../Topic/CHtmlView::SetMenuBar.md)|Define um valor para determinar se a barra de menus do controle é visível.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::SetOffline](../Topic/CHtmlView::SetOffline.md)|Define um valor para determinar se o controle está off\-line.|  
|[CHtmlView::SetRegisterAsBrowser](../Topic/CHtmlView::SetRegisterAsBrowser.md)|Define um valor indicando se o controle da web browser está registrado como um navegador de nível superior para o resolução de destino do.|  
|[CHtmlView::SetRegisterAsDropTarget](../Topic/CHtmlView::SetRegisterAsDropTarget.md)|Define um valor indicando se o controle da web browser está registrado como um destino alvo para navegação.|  
|[CHtmlView::SetSilent](../Topic/CHtmlView::SetSilent.md)|Define um valor para determinar se o controle exibirá caixas de diálogo.|  
|[CHtmlView::SetStatusBar](../Topic/CHtmlView::SetStatusBar.md)|Define um valor para determinar se a barra de status da Internet Explorer é visível.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::SetTheaterMode](../Topic/CHtmlView::SetTheaterMode.md)|Define um valor indicando se o controle da web browser está no modo de produtor.|  
|[CHtmlView::SetToolBar](../Topic/CHtmlView::SetToolBar.md)|Define um valor para determinar se a barra de ferramentas de controle é visível.  \(O controle da web browser ignora; Somente o Internet Explorer.\)|  
|[CHtmlView::SetTop](../Topic/CHtmlView::SetTop.md)|Define a posição vertical da janela principal do Internet Explorer.|  
|[CHtmlView::SetVisible](../Topic/CHtmlView::SetVisible.md)|Define um valor indicando se o objeto é visível ou oculto.|  
|[CHtmlView::SetWidth](../Topic/CHtmlView::SetWidth.md)|Defina a largura da janela principal do Internet Explorer.|  
|[CHtmlView::Stop](../Topic/CHtmlView::Stop.md)|Paradas que abre um arquivo.|  
  
## Comentários  
 O controle da web browser é uma janela em que o usuário pode procurar sites no World Wide Web, bem como pastas no sistema de arquivos local e em uma rede.  O controle oferece suporte ao navegador da web hipervínculo, navegação de \(URL\) do localizador recursos uniforme, e mantém uma lista histórico.  
  
## Usando a classe de CHtmlView em um aplicativo MFC  
 Estrutura do aplicativo MFC de padrão \(SDI ou baseado MDI\), o objeto de visualização geralmente é derivado de um especializado conjunto de classes.  Essas classes, qualquer derivados de `CView`, fornecem funcionalidades especializadas além do fornecido por `CView`.  
  
 Basear a classe de visualização do aplicativo em `CHtmlView` fornece a exibição com o controle da web browser.  Isso é verdade para o aplicativo um navegador da web.  O método preferido de criar um aplicativo no estilo de navegador da Web é usar o assistente de aplicativo MFC, e especifica `CHtmlView` porque a classe de exibição.  Para obter mais informações sobre como implementar e usar navegador da web controle em aplicativos MFC, consulte [Criando um aplicativo com Estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md).  
  
> [!NOTE]
>  O controle ActiveX da web browser \(e portanto `CHtmlView`\) estão disponíveis somente para programas que executam sob as versões do Windows NT 4,0 ou posterior, em que foram instalados Internet Explorer 4.0 ou posterior.  
  
 `CHtmlView` é projetado para aplicativos que acessam Web \(e\/ou documentos HTML\).  As seguintes funções de membro de `CHtmlView` aplicam a Internet Explorer o aplicativo somente.  Essas funções sucederão no controle da web browser, mas não terão efeito visível.  
  
-   [GetAddressBar](../Topic/CHtmlView::GetAddressBar.md)  
  
-   [GetFullName](../Topic/CHtmlView::GetFullName.md)  
  
-   [GetStatusBar](../Topic/CHtmlView::GetStatusBar.md)  
  
-   [SetAddressBar](../Topic/CHtmlView::SetAddressBar.md)  
  
-   [SetFullScreen](../Topic/CHtmlView::SetFullScreen.md)  
  
-   [SetMenuBar](../Topic/CHtmlView::SetMenuBar.md)  
  
-   [SetStatusBar](../Topic/CHtmlView::SetStatusBar.md)  
  
-   [SetToolBar](../Topic/CHtmlView::SetToolBar.md)  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 [CFormView](../../mfc/reference/cformview-class.md)  
  
 `CHtmlView`  
  
## Requisitos  
 **Cabeçalho:** afxhtml.h  
  
## Consulte também  
 [Exemplo MFCIE MFC](../../top/visual-cpp-samples.md)   
 [Classe de CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [IWebBrowser2](https://msdn.microsoft.com/en-us/library/aa752127.aspx)