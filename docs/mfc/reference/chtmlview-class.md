---
title: Classe CHtmlView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHtmlView
- AFXHTML/CHtmlView
- AFXHTML/CHtmlView::Create
- AFXHTML/CHtmlView::CreateControlSite
- AFXHTML/CHtmlView::ExecFormsCommand
- AFXHTML/CHtmlView::ExecWB
- AFXHTML/CHtmlView::GetAddressBar
- AFXHTML/CHtmlView::GetApplication
- AFXHTML/CHtmlView::GetBusy
- AFXHTML/CHtmlView::GetContainer
- AFXHTML/CHtmlView::GetFullName
- AFXHTML/CHtmlView::GetFullScreen
- AFXHTML/CHtmlView::GetHeight
- AFXHTML/CHtmlView::GetHtmlDocument
- AFXHTML/CHtmlView::GetLeft
- AFXHTML/CHtmlView::GetLocationName
- AFXHTML/CHtmlView::GetLocationURL
- AFXHTML/CHtmlView::GetMenuBar
- AFXHTML/CHtmlView::GetOffline
- AFXHTML/CHtmlView::GetParentBrowser
- AFXHTML/CHtmlView::GetProperty
- AFXHTML/CHtmlView::GetReadyState
- AFXHTML/CHtmlView::GetRegisterAsBrowser
- AFXHTML/CHtmlView::GetRegisterAsDropTarget
- AFXHTML/CHtmlView::GetSilent
- AFXHTML/CHtmlView::GetSource
- AFXHTML/CHtmlView::GetStatusBar
- AFXHTML/CHtmlView::GetTheaterMode
- AFXHTML/CHtmlView::GetToolBar
- AFXHTML/CHtmlView::GetTop
- AFXHTML/CHtmlView::GetTopLevelContainer
- AFXHTML/CHtmlView::GetType
- AFXHTML/CHtmlView::GetVisible
- AFXHTML/CHtmlView::GetWidth
- AFXHTML/CHtmlView::GoBack
- AFXHTML/CHtmlView::GoForward
- AFXHTML/CHtmlView::GoHome
- AFXHTML/CHtmlView::GoSearch
- AFXHTML/CHtmlView::LoadFromResource
- AFXHTML/CHtmlView::Navigate
- AFXHTML/CHtmlView::Navigate2
- AFXHTML/CHtmlView::OnBeforeNavigate2
- AFXHTML/CHtmlView::OnCommandStateChange
- AFXHTML/CHtmlView::OnDocumentComplete
- AFXHTML/CHtmlView::OnDocWindowActivate
- AFXHTML/CHtmlView::OnDownloadBegin
- AFXHTML/CHtmlView::OnDownloadComplete
- AFXHTML/CHtmlView::OnEnableModeless
- AFXHTML/CHtmlView::OnFilterDataObject
- AFXHTML/CHtmlView::OnFrameWindowActivate
- AFXHTML/CHtmlView::OnFullScreen
- AFXHTML/CHtmlView::OnGetDropTarget
- AFXHTML/CHtmlView::OnGetExternal
- AFXHTML/CHtmlView::OnGetHostInfo
- AFXHTML/CHtmlView::OnGetOptionKeyPath
- AFXHTML/CHtmlView::OnHideUI
- AFXHTML/CHtmlView::OnMenuBar
- AFXHTML/CHtmlView::OnNavigateComplete2
- AFXHTML/CHtmlView::OnNavigateError
- AFXHTML/CHtmlView::OnNewWindow2
- AFXHTML/CHtmlView::OnProgressChange
- AFXHTML/CHtmlView::OnPropertyChange
- AFXHTML/CHtmlView::OnQuit
- AFXHTML/CHtmlView::OnResizeBorder
- AFXHTML/CHtmlView::OnShowContextMenu
- AFXHTML/CHtmlView::OnShowUI
- AFXHTML/CHtmlView::OnStatusBar
- AFXHTML/CHtmlView::OnStatusTextChange
- AFXHTML/CHtmlView::OnTheaterMode
- AFXHTML/CHtmlView::OnTitleChange
- AFXHTML/CHtmlView::OnToolBar
- AFXHTML/CHtmlView::OnTranslateAccelerator
- AFXHTML/CHtmlView::OnTranslateUrl
- AFXHTML/CHtmlView::OnUpdateUI
- AFXHTML/CHtmlView::OnVisible
- AFXHTML/CHtmlView::PutProperty
- AFXHTML/CHtmlView::QueryFormsCommand
- AFXHTML/CHtmlView::QueryStatusWB
- AFXHTML/CHtmlView::Refresh
- AFXHTML/CHtmlView::Refresh2
- AFXHTML/CHtmlView::SetAddressBar
- AFXHTML/CHtmlView::SetFullScreen
- AFXHTML/CHtmlView::SetHeight
- AFXHTML/CHtmlView::SetLeft
- AFXHTML/CHtmlView::SetMenuBar
- AFXHTML/CHtmlView::SetOffline
- AFXHTML/CHtmlView::SetRegisterAsBrowser
- AFXHTML/CHtmlView::SetRegisterAsDropTarget
- AFXHTML/CHtmlView::SetSilent
- AFXHTML/CHtmlView::SetStatusBar
- AFXHTML/CHtmlView::SetTheaterMode
- AFXHTML/CHtmlView::SetToolBar
- AFXHTML/CHtmlView::SetTop
- AFXHTML/CHtmlView::SetVisible
- AFXHTML/CHtmlView::SetWidth
- AFXHTML/CHtmlView::Stop
dev_langs: C++
helpviewer_keywords:
- CHtmlView [MFC], Create
- CHtmlView [MFC], CreateControlSite
- CHtmlView [MFC], ExecFormsCommand
- CHtmlView [MFC], ExecWB
- CHtmlView [MFC], GetAddressBar
- CHtmlView [MFC], GetApplication
- CHtmlView [MFC], GetBusy
- CHtmlView [MFC], GetContainer
- CHtmlView [MFC], GetFullName
- CHtmlView [MFC], GetFullScreen
- CHtmlView [MFC], GetHeight
- CHtmlView [MFC], GetHtmlDocument
- CHtmlView [MFC], GetLeft
- CHtmlView [MFC], GetLocationName
- CHtmlView [MFC], GetLocationURL
- CHtmlView [MFC], GetMenuBar
- CHtmlView [MFC], GetOffline
- CHtmlView [MFC], GetParentBrowser
- CHtmlView [MFC], GetProperty
- CHtmlView [MFC], GetReadyState
- CHtmlView [MFC], GetRegisterAsBrowser
- CHtmlView [MFC], GetRegisterAsDropTarget
- CHtmlView [MFC], GetSilent
- CHtmlView [MFC], GetSource
- CHtmlView [MFC], GetStatusBar
- CHtmlView [MFC], GetTheaterMode
- CHtmlView [MFC], GetToolBar
- CHtmlView [MFC], GetTop
- CHtmlView [MFC], GetTopLevelContainer
- CHtmlView [MFC], GetType
- CHtmlView [MFC], GetVisible
- CHtmlView [MFC], GetWidth
- CHtmlView [MFC], GoBack
- CHtmlView [MFC], GoForward
- CHtmlView [MFC], GoHome
- CHtmlView [MFC], GoSearch
- CHtmlView [MFC], LoadFromResource
- CHtmlView [MFC], Navigate
- CHtmlView [MFC], Navigate2
- CHtmlView [MFC], OnBeforeNavigate2
- CHtmlView [MFC], OnCommandStateChange
- CHtmlView [MFC], OnDocumentComplete
- CHtmlView [MFC], OnDocWindowActivate
- CHtmlView [MFC], OnDownloadBegin
- CHtmlView [MFC], OnDownloadComplete
- CHtmlView [MFC], OnEnableModeless
- CHtmlView [MFC], OnFilterDataObject
- CHtmlView [MFC], OnFrameWindowActivate
- CHtmlView [MFC], OnFullScreen
- CHtmlView [MFC], OnGetDropTarget
- CHtmlView [MFC], OnGetExternal
- CHtmlView [MFC], OnGetHostInfo
- CHtmlView [MFC], OnGetOptionKeyPath
- CHtmlView [MFC], OnHideUI
- CHtmlView [MFC], OnMenuBar
- CHtmlView [MFC], OnNavigateComplete2
- CHtmlView [MFC], OnNavigateError
- CHtmlView [MFC], OnNewWindow2
- CHtmlView [MFC], OnProgressChange
- CHtmlView [MFC], OnPropertyChange
- CHtmlView [MFC], OnQuit
- CHtmlView [MFC], OnResizeBorder
- CHtmlView [MFC], OnShowContextMenu
- CHtmlView [MFC], OnShowUI
- CHtmlView [MFC], OnStatusBar
- CHtmlView [MFC], OnStatusTextChange
- CHtmlView [MFC], OnTheaterMode
- CHtmlView [MFC], OnTitleChange
- CHtmlView [MFC], OnToolBar
- CHtmlView [MFC], OnTranslateAccelerator
- CHtmlView [MFC], OnTranslateUrl
- CHtmlView [MFC], OnUpdateUI
- CHtmlView [MFC], OnVisible
- CHtmlView [MFC], PutProperty
- CHtmlView [MFC], QueryFormsCommand
- CHtmlView [MFC], QueryStatusWB
- CHtmlView [MFC], Refresh
- CHtmlView [MFC], Refresh2
- CHtmlView [MFC], SetAddressBar
- CHtmlView [MFC], SetFullScreen
- CHtmlView [MFC], SetHeight
- CHtmlView [MFC], SetLeft
- CHtmlView [MFC], SetMenuBar
- CHtmlView [MFC], SetOffline
- CHtmlView [MFC], SetRegisterAsBrowser
- CHtmlView [MFC], SetRegisterAsDropTarget
- CHtmlView [MFC], SetSilent
- CHtmlView [MFC], SetStatusBar
- CHtmlView [MFC], SetTheaterMode
- CHtmlView [MFC], SetToolBar
- CHtmlView [MFC], SetTop
- CHtmlView [MFC], SetVisible
- CHtmlView [MFC], SetWidth
- CHtmlView [MFC], Stop
ms.assetid: 904976af-73de-4aba-84ac-cfae8e2be09a
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a855100aaab28e5fead062d4a0941741742cf1a0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chtmlview-class"></a>Classe CHtmlView
Fornece a funcionalidade do controle WebBrowser dentro do contexto de arquitetura de documento/exibição do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHtmlView : public CFormView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlView::Create](#create)|Cria o controle WebBrowser.|  
|[CHtmlView::CreateControlSite](#createcontrolsite)|Overridable usado para criar uma instância de controle de site para hospedar um controle no formulário.|  
|[CHtmlView::ExecFormsCommand](#execformscommand)|Executa o comando especificado usando o `IOleCommandTarget::Exec` método.|  
|[CHtmlView::ExecWB](#execwb)|Executa um comando.|  
|[CHtmlView::GetAddressBar](#getaddressbar)|Determina se a barra de endereços do objeto do Internet Explorer está visível. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::GetApplication](#getapplication)|Recupera um objeto de aplicativo que representa o aplicativo que contém a instância atual do aplicativo do Internet Explorer.|  
|[CHtmlView::GetBusy](#getbusy)|Recupera um valor que indica se um download ou outra atividade está em andamento.|  
|[CHtmlView::GetContainer](#getcontainer)|Recupera o contêiner do controle WebBrowser.|  
|[CHtmlView::GetFullName](#getfullname)|Recupera o nome completo, incluindo o caminho do recurso exibido no navegador da web. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::GetFullScreen](#getfullscreen)|Indica se o controle WebBrowser está operando no modo de tela inteira ou no modo de janela normal.|  
|[CHtmlView::GetHeight](#getheight)|Recupera a altura da janela principal do Internet Explorer.|  
|[CHtmlView::GetHtmlDocument](#gethtmldocument)|Recupera o documento HTML ativo.|  
|[CHtmlView::GetLeft](#getleft)|Recupera a coordenada da tela da borda esquerda da janela principal do Internet Explorer.|  
|[CHtmlView::GetLocationName](#getlocationname)|Recupera o nome do recurso que WebBrowser está exibindo no momento|  
|[CHtmlView::GetLocationURL](#getlocationurl)|Recupera a URL do recurso que WebBrowser está exibindo no momento.|  
|[CHtmlView::GetMenuBar](#getmenubar)|Recupera um valor que determina se a barra de menu é visível.|  
|[CHtmlView::GetOffline](#getoffline)|Recupera um valor que determina se o controle está offline.|  
|[CHtmlView::GetParentBrowser](#getparentbrowser)|Recupera um ponteiro para o `IDispatch` interface. Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945).|  
|[CHtmlView::GetProperty](#getproperty)|Recupera o valor atual de uma propriedade associada ao objeto especificado.|  
|[CHtmlView::GetReadyState](#getreadystate)|Recupera o estado pronto do objeto de navegador da web.|  
|[CHtmlView::GetRegisterAsBrowser](#getregisterasbrowser)|Indica se o controle WebBrowser está registrado como um navegador de nível superior para a resolução de nome de destino.|  
|[CHtmlView::GetRegisterAsDropTarget](#getregisterasdroptarget)|Indica se o controle WebBrowser está registrado como um destino de navegação.|  
|[CHtmlView::GetSilent](#getsilent)|Indica se todas as caixas de diálogo podem ser mostradas.|  
|[CHtmlView::GetSource](#getsource)|O código-fonte HTML da página da web.|  
|[CHtmlView::GetStatusBar](#getstatusbar)|Indica se a barra de status do Internet Explorer está visível. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::GetTheaterMode](#gettheatermode)|Indica se o controle WebBrowser está no modo de teatro.|  
|[CHtmlView::GetToolBar](#gettoolbar)|Recupera um valor que determina se a barra de ferramentas está visível.|  
|[CHtmlView::GetTop](#gettop)|Recupera a coordenada da tela da borda superior da janela principal do Internet Explorer.|  
|[CHtmlView::GetTopLevelContainer](#gettoplevelcontainer)|Recupera um valor que indica se o objeto atual é o contêiner de nível superior do controle WebBrowser.|  
|[CHtmlView::GetType](#gettype)|Recupera o nome do tipo de objeto do documento.|  
|[CHtmlView::GetVisible](#getvisible)|Recupera um valor que indica se o objeto está visível ou oculto.|  
|[CHtmlView::GetWidth](#getwidth)|Recupera a largura da janela principal do Internet Explorer.|  
|[CHtmlView::GoBack](#goback)|Navega para o item anterior na lista de histórico.|  
|[CHtmlView::GoForward](#goforward)|Navega para o próximo item na lista de histórico.|  
|[CHtmlView::GoHome](#gohome)|Navega para o início atual ou a página inicial.|  
|[CHtmlView::GoSearch](#gosearch)|Navega para a página de pesquisa atual.|  
|[CHtmlView::LoadFromResource](#loadfromresource)|Carrega um recurso no controle WebBrowser.|  
|[CHtmlView::Navigate](#navigate)|Navega para o recurso identificado por uma URL.|  
|[CHtmlView::Navigate2](#navigate2)|Navega para o recurso identificado por uma URL, ou para o arquivo identificado por um caminho completo.|  
|[CHtmlView::OnBeforeNavigate2](#onbeforenavigate2)|Chamado antes que ocorra uma navegação no WebBrowser fornecido (em uma janela ou conjunto de quadros elemento).|  
|[CHtmlView::OnCommandStateChange](#oncommandstatechange)|Chamado para notificar um aplicativo que foi alterado o estado ativado de um comando do navegador da web.|  
|[CHtmlView::OnDocumentComplete](#ondocumentcomplete)|Chamado para notificar um aplicativo que um documento tenha atingido o `READYSTATE_COMPLETE` estado.|  
|[CHtmlView::OnDocWindowActivate](#ondocwindowactivate)|Chamada da implementação do Internet Explorer ou MSHTML de [IOleInPlaceActiveObject::OnDocWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms687281), que notifica o objeto no local ativo quando a janela de documento do contêiner é ativada ou desativada.|  
|[CHtmlView::OnDownloadBegin](#ondownloadbegin)|Chamado para notificar um aplicativo de uma operação de navegação está começando.|  
|[CHtmlView::OnDownloadComplete](#ondownloadcomplete)|Chamado quando uma operação de navegação concluída, interrompida ou falha.|  
|[CHtmlView::OnEnableModeless](#onenablemodeless)|Chamado para habilitar ou desabilitar as caixas de diálogo sem janela restrita quando o contêiner cria ou destrói a caixa de diálogo modal.|  
|[CHtmlView::OnFilterDataObject](#onfilterdataobject)|Chamado no host pelo Internet Explorer ou MSHTML para permitir que o host substituir o Internet Explorer ou o objeto de dados do MSHTML.|  
|[CHtmlView::OnFrameWindowActivate](#onframewindowactivate)|Chamado a partir do [IOleInPlaceActiveObject::OnFrameWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms683969) para notificar o objeto do nível superior do contêiner a janela do quadro é ativada ou desativada.|  
|[CHtmlView::OnFullScreen](#onfullscreen)|Chamado quando a propriedade FullScreen é alterada.|  
|[CHtmlView::OnGetDropTarget](#ongetdroptarget)|Chamado pelo Internet Explorer ou MSHTML quando ele está sendo usado como um destino para permitir que o host fornecer uma alternativa [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679).|  
|[CHtmlView::OnGetExternal](#ongetexternal)|Chamado pelo Internet Explorer ou MSHTML para obter o host `IDispatch` interface.|  
|[CHtmlView::OnGetHostInfo](#ongethostinfo)|Recupera os recursos de interface do usuário do host do Internet Explorer ou MSHTML.|  
|[CHtmlView::OnGetOptionKeyPath](#ongetoptionkeypath)|Retorna a chave do registro sob a qual o Internet Explorer ou MSHTML armazena as preferências do usuário.|  
|[CHtmlView::OnHideUI](#onhideui)|Chamado quando o Internet Explorer ou MSHTML remove seus menus e barras de ferramentas.|  
|[CHtmlView::OnMenuBar](#onmenubar)|Chamado quando a propriedade MenuBar é alterada.|  
|[CHtmlView::OnNavigateComplete2](#onnavigatecomplete2)|Chamado depois que a navegação a um hiperlink é concluída (em uma janela ou um conjunto de quadros elemento).|  
|[CHtmlView::OnNavigateError](#onnavigateerror)|Chamado pelo framework se falhar de navegação a um hiperlink.|  
|[CHtmlView::OnNewWindow2](#onnewwindow2)|Chamado quando uma nova janela será criado para exibir um recurso.|  
|[CHtmlView::OnProgressChange](#onprogresschange)|Chamado para notificar um aplicativo que o progresso de uma operação de download foi atualizado.|  
|[CHtmlView::OnPropertyChange](#onpropertychange)|Chamado para notificar um aplicativo que o [PutProperty](#putproperty) método alterou o valor de uma propriedade.|  
|[CHtmlView::OnQuit](#onquit)|Chamado para notificar um aplicativo que o aplicativo do Internet Explorer está pronto para sair. (Aplica-se somente para o Internet Explorer)|  
|[CHtmlView::OnResizeBorder](#onresizeborder)|Chamada da implementação do Internet Explorer ou MSHTML de [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053), que o objeto que ele precisa redimensionar seu espaço de borda de alertas.|  
|[CHtmlView::OnShowContextMenu](#onshowcontextmenu)|Chamado a partir do Internet Explorer ou MSHTML quando ele está prestes a exibir o menu de contexto.|  
|[CHtmlView::OnShowUI](#onshowui)|Chamado antes do Internet Explorer ou MSHTML exibe seus menus e barras de ferramentas.|  
|[CHtmlView::OnStatusBar](#onstatusbar)|Chamado quando a propriedade StatusBar é alterada.|  
|[CHtmlView::OnStatusTextChange](#onstatustextchange)|Chamado para notificar um aplicativo que o texto da barra de status associado ao controle WebBrowser foi alterado.|  
|[CHtmlView::OnTheaterMode](#ontheatermode)|Chamado quando a propriedade TheaterMode é alterada.|  
|[CHtmlView::OnTitleChange](#ontitlechange)|Chamado para notificar um aplicativo se o título de um documento no controle do WebBrowser estiver disponível ou as alterações.|  
|[CHtmlView::OnToolBar](#ontoolbar)|Chamado quando a propriedade ToolBar é alterada.|  
|[CHtmlView::OnTranslateAccelerator](#ontranslateaccelerator)|Chamado pelo Internet Explorer ou MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693360) ou [IOleControlSite::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693756) é chamado para processar mensagens de tecla de aceleração de menu do fila de mensagens do contêiner.|  
|[CHtmlView::OnTranslateUrl](#ontranslateurl)|Chamado pelo Internet Explorer ou MSHTML para permitir que o host a oportunidade de modificar a URL a ser carregado.|  
|[CHtmlView::OnUpdateUI](#onupdateui)|Notifica o host que o estado do comando foi alterado.|  
|[CHtmlView::OnVisible](#onvisible)|Chamado quando a janela para o controle WebBrowser deve ser exibida/ocultada.|  
|[CHtmlView::PutProperty](#putproperty)|Define o valor de uma propriedade associada ao objeto especificado.|  
|[CHtmlView::QueryFormsCommand](#queryformscommand)|Consulta o status de um ou mais comandos gerados pelos eventos de interface do usuário.|  
|[CHtmlView::QueryStatusWB](#querystatuswb)|Consulta o status de um comando que está sendo processado pelo controle WebBrowser.|  
|[CHtmlView::Refresh](#refresh)|Recarrega o arquivo atual.|  
|[CHtmlView::Refresh2](#refresh2)|Recarrega o arquivo atual e, opcionalmente, impede que o `pragma:nocache` cabeçalho seja enviado.|  
|[CHtmlView::SetAddressBar](#setaddressbar)|Mostra ou oculta a barra de endereços do objeto do Internet Explorer. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::SetFullScreen](#setfullscreen)|Define um valor para determinar se o controle está operando no modo de tela inteira ou no modo de janela normal. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::SetHeight](#setheight)|Define a altura da janela principal do Internet Explorer.|  
|[CHtmlView::SetLeft](#setleft)|Define a posição horizontal da janela principal do Internet Explorer.|  
|[CHtmlView::SetMenuBar](#setmenubar)|Define um valor para determinar se a barra de menus do controle está visível. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::SetOffline](#setoffline)|Define um valor para determinar se o controle está offline.|  
|[CHtmlView::SetRegisterAsBrowser](#setregisterasbrowser)|Define um valor que indica se o controle WebBrowser está registrado como um navegador de nível superior para a resolução de nome de destino.|  
|[CHtmlView::SetRegisterAsDropTarget](#setregisterasdroptarget)|Define um valor que indica se o controle WebBrowser está registrado como um destino de navegação.|  
|[CHtmlView::SetSilent](#setsilent)|Define um valor para determinar se o controle exibirá caixas de diálogo.|  
|[CHtmlView::SetStatusBar](#setstatusbar)|Define um valor para determinar se a barra de status do Internet Explorer está visível. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::SetTheaterMode](#settheatermode)|Define um valor que indica se o controle WebBrowser está no modo de teatro.|  
|[CHtmlView::SetToolBar](#settoolbar)|Define um valor para determinar se a barra de ferramentas do controle está visível. (O controle WebBrowser ignora; Somente para Internet Explorer.)|  
|[CHtmlView::SetTop](#settop)|Define a posição vertical da janela principal do Internet Explorer.|  
|[CHtmlView::SetVisible](#setvisible)|Define um valor que indica se o objeto está visível ou oculto.|  
|[CHtmlView::SetWidth](#setwidth)|Define a largura da janela principal do Internet Explorer.|  
|[CHtmlView::Stop](#stop)|Interrompe a abertura de um arquivo.|  
  
## <a name="remarks"></a>Comentários  
 O controle WebBrowser é uma janela em que o usuário pode procurar os sites na World Wide Web, bem como pastas no sistema de arquivos local e em uma rede. O controle WebBrowser suporta hyperlink, navegação de URL Uniform Resource Locator () e mantém uma lista de histórico.  
  
## <a name="using-the-chtmlview-class-in-an-mfc-application"></a>Usando a classe CHtmlView em um aplicativo MFC  
 No padrão MFC framework aplicativo (SDI ou MDI com base em), o objeto de exibição normalmente é derivado de um conjunto especializado de classes. Essas classes derivadas de `CView`, oferecem funções especializadas além do fornecido por `CView`.  
  
 Baseando a classe de exibição do aplicativo em `CHtmlView` fornece a exibição com o controle WebBrowser. Isso efetivamente torna o aplicativo em um navegador da web. O método preferencial de criação de um aplicativo de estilo de navegador da web é usar o Assistente de aplicativo MFC e especificar `CHtmlView` como a classe de exibição. Para obter mais informações sobre como implementar e usar o controle WebBrowser dentro de aplicativos MFC, consulte [criar um aplicativo de estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md).  
  
> [!NOTE]
>  O controle WebBrowser ActiveX (e, portanto, `CHtmlView`) está disponível apenas para programas em execução em versões do Windows NT 4.0 ou posteriores, no qual o Internet Explorer 4.0 ou posterior foi instalado.  
  
 `CHtmlView`foi projetado para aplicativos que acessam a Web (e/ou documentos HTML). O seguinte `CHtmlView` aplicam funções de membro para o aplicativo de Internet Explorer apenas. Essas funções funcionará no controle WebBrowser, mas eles terão nenhum efeito visível.  
  
- [GetAddressBar](#getaddressbar)  
  
- [GetFullName](#getfullname)  
  
- [GetStatusBar](#getstatusbar)  
  
- [SetAddressBar](#setaddressbar)  
  
- [SetFullScreen](#setfullscreen)  
  
- [SetMenuBar](#setmenubar)  
  
- [SetStatusBar](#setstatusbar)  
  
- [SetToolBar](#settoolbar)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 [CFormView](../../mfc/reference/cformview-class.md)  
  
 `CHtmlView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxhtml.h  
  
##  <a name="create"></a>CHtmlView::Create  
 Chame essa função de membro para criar um controle WebBrowser ou um contêiner para o Internet Explorer executável.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszClassName,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClassName`  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com o [AfxRegisterWndClass](../../mfc/reference/application-information-and-management.md#afxregisterwndclass) função global ou **RegisterClass** função do Windows. Se **nulo**, usa o padrão predefinido [CFrameWnd](../../mfc/reference/cframewnd-class.md) atributos.  
  
 `lpszWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que representa o nome da janela.  
  
 `dwStyle`  
 Especifica os atributos de estilo de janela. Por padrão, o **WS_VISIBLE** e **WS_CHILD** estilos do Windows são definidos.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando o tamanho e a posição da janela. O `rectDefault` valor permite que o Windows especificar o tamanho e a posição da nova janela.  
  
 `pParentWnd`  
 Um ponteiro para a janela pai do controle.  
  
 `nID`  
 O número de identificação do modo de exibição. Por padrão, definido como **AFX_IDW_PANE_FIRST**.  
  
 `pContext`  
 Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md). **NULO** por padrão.  
  
##  <a name="createcontrolsite"></a>CHtmlView::CreateControlSite  
 Overridable usado para criar uma instância de controle de site para hospedar um controle no formulário.  
  
```  
virtual BOOL CreateControlSite(
    COleControlContainer* pContainer,  
    COleControlSite** ppSite,  
    UINT nID,  
    REFCLSID clsid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContainer`  
 Um ponteiro para um [COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md) objeto que contém o controle.  
  
 `ppSite`  
 Um ponteiro para um ponteiro para um [COleControlSite](../../mfc/reference/colecontrolsite-class.md) objeto, fornecendo o site para o controle.  
  
 `nID`  
 O identificador do controle a ser hospedado.  
  
 `clsid`  
 O CLSID do controle a ser hospedado  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituir essa função de membro para retornar uma instância de seu próprio site de controle.  
  
##  <a name="execformscommand"></a>CHtmlView::ExecFormsCommand  
 Executa o comando especificado usando o `IOleCommandTarget::Exec` método.  
  
```  
HRESULT ExecFormsCommand(
    DWORD dwCommandID,  
    VARIANT* pVarIn,  
    VARIANT* pVarOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCommandID`  
 O comando a ser executado. Este comando deve pertencer ao **CMDSETID3_Forms3** grupo.  
  
 *pVarIn*  
 Ponteiro para um **VARIANT** estrutura que contém argumentos de entrada. Pode ser **nulo**.  
  
 *pVarOut*  
 Ponteiro para um **VARIANT** estrutura para receber a saída do comando. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Para obter uma lista completa de valores possíveis, consulte [IOleCommandTarget::Exec](http://msdn.microsoft.com/library/windows/desktop/ms690300) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 **ExecFormsCommand** implementa o comportamento de [IOleCommandTarget::Exec](http://msdn.microsoft.com/library/windows/desktop/ms690300) método.  
  
##  <a name="execwb"></a>CHtmlView::ExecWB  
 Chame essa função de membro para executar um comando no WebBrowser ou Internet Explorer.  
  
```  
void ExecWB(
    OLECMDID cmdID,  
    OLECMDEXECOPT cmdexecopt,  
    VARIANT* pvaIn,  
    VARIANT* pvaOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 O comando a ser executado.  
  
 *cmdexecopt*  
 As opções definidas para executar o comando.  
  
 `pvaIn`  
 Uma variante usada para especificar argumentos de entrada de comando.  
  
 *pvaOut*  
 Uma variante usada para especificar argumentos de saída do comando.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IWebBrowser2::ExecWB](https://msdn.microsoft.com/library/aa752117.aspx) no SDK do Windows.  
  
##  <a name="getaddressbar"></a>CHtmlView::GetAddressBar  
 Chame essa função de membro para recuperar a barra de endereços do Internet Explorer.  
  
```  
BOOL GetAddressBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de endereços estiver visível; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="getapplication"></a>CHtmlView::GetApplication  
 Chame essa função de membro para recuperar o objeto de automação com suporte do aplicativo que contém o controle WebBrowser.  
  
```  
LPDISPATCH GetApplication() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `IDispatch` interface do objeto de documento ativo. Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945).  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getbusy"></a>CHtmlView::GetBusy  
 Chame essa função de membro para determinar se o controle WebBrowser está envolvido em uma operação de carregamento ou de navegação.  
  
```  
BOOL GetBusy() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o navegador da web estiver ocupado; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getcontainer"></a>CHtmlView::GetContainer  
 Chame essa função de membro para recuperar um objeto que é avaliada para o contêiner do navegador da web.  
  
```  
LPDISPATCH GetContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `IDispatch` interface do objeto de documento ativo.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getfullname"></a>CHtmlView::GetFullName  
 Chame essa função de membro para recuperar o caminho completo do arquivo que o Internet Explorer está exibindo no momento.  
  
```  
CString GetFullName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o caminho e o nome do arquivo exibido no momento. Se nenhum caminho e nome de arquivo existirem, `GetFullName` retorna vazio `CString`.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="getfullscreen"></a>CHtmlView::GetFullScreen  
 Chame essa função de membro para determinar se o controle WebBrowser está operando no modo de tela inteira ou no modo de janela normal.  
  
```  
BOOL GetFullScreen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o WebBrowser estiver operando em modo de tela inteira; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 No modo de tela inteira, a janela principal do Internet Explorer é maximizada e a barra de status, barra de ferramentas, barra de menus e barras de título estão ocultos.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getheight"></a>CHtmlView::GetHeight  
 Chame essa função de membro para recuperar a altura, em pixels, da janela do quadro do controle WebBrowser.  
  
```  
long GetHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do controle quadro janela, em pixels.  
  
##  <a name="gethtmldocument"></a>CHtmlView::GetHtmlDocument  
 Chame essa função de membro para recuperar o documento HTML para o documento ativo.  
  
```  
LPDISPATCH GetHtmlDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `IDispatch` interface do objeto de documento ativo.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getleft"></a>CHtmlView::GetLeft  
 Chame essa função de membro para recuperar a distância entre a borda esquerda interna do controle WebBrowser e a borda esquerda de seu contêiner.  
  
```  
long GetLeft() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A distância da borda esquerda, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getlocationname"></a>CHtmlView::GetLocationName  
 Chame essa função de membro para obter o nome do recurso que está sendo exibido no WebBrowser.  
  
```  
CString GetLocationName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o nome do recurso exibido atualmente no WebBrowser.  
  
### <a name="remarks"></a>Comentários  
 Se o recurso for uma página HTML na World Wide Web, o nome é o título da página. Se o recurso for uma pasta ou arquivo na rede ou no computador local, o nome é o UNC ou um caminho completo da pasta ou arquivo.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getlocationurl"></a>CHtmlView::GetLocationURL  
 Chame essa função de membro para recuperar a URL do recurso que o controle WebBrowser está exibindo no momento.  
  
```  
CString GetLocationURL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém a URL do recurso exibido atualmente no WebBrowser.  
  
### <a name="remarks"></a>Comentários  
 Se o recurso for uma pasta ou arquivo na rede ou no computador local, o nome é o UNC ou um caminho completo da pasta ou arquivo.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getmenubar"></a>CHtmlView::GetMenuBar  
 Chame essa função de membro para determinar se a barra de menu está visível.  
  
```  
BOOL GetMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de menu estiver visível; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getoffline"></a>CHtmlView::GetOffline  
 Chame essa função de membro para determinar se o navegador da web está funcionando offline.  
  
```  
BOOL GetOffline() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o navegador da web está offline; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getparentbrowser"></a>CHtmlView::GetParentBrowser  
 Chame essa função de membro para recuperar um ponteiro para o objeto pai do controle WebBrowser.  
  
```  
LPDISPATCH GetParentBrowser() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `IDispatch` interface do objeto que é o pai do controle WebBrowser.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getproperty"></a>CHtmlView::GetProperty  
 Chame essa função de membro para obter o valor da propriedade associada atualmente com o controle.  
  
```  
BOOL GetProperty(
    LPCTSTR lpszProperty,  
    CString& strValue);  
  
COleVariant GetProperty(LPCTSTR lpszProperty);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProperty`  
 Um ponteiro para uma cadeia de caracteres que contém a propriedade a recuperar.  
  
 `strValue`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que recebe o valor atual da propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira versão, diferente de zero se foi concluída com êxito; Caso contrário, zero. Na segunda versão, uma [COleVariant](../../mfc/reference/colevariant-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getreadystate"></a>CHtmlView::GetReadyState  
 Chame essa função de membro para recuperar o estado pronto do objeto WebBrowser.  
  
```  
READYSTATE GetReadyState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [estado de prontidão é](https://msdn.microsoft.com/library/aa768362.aspx) valor, conforme descrito no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getregisterasbrowser"></a>CHtmlView::GetRegisterAsBrowser  
 Chame essa função de membro para determinar se o objeto de WebBrowser está registrado como um navegador de nível superior para a resolução de nome de destino.  
  
```  
BOOL GetRegisterAsBrowser() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o navegador estiver registrado como um navegador de nível superior; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getregisterasdroptarget"></a>CHtmlView::GetRegisterAsDropTarget  
 Chame essa função de membro para determinar se o controle WebBrowser está registrado como um destino de navegação.  
  
```  
BOOL GetRegisterAsDropTarget() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o navegador estiver registrado como um destino de soltar; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getsilent"></a>CHtmlView::GetSilent  
 Chame essa função de membro para determinar se as caixas de diálogo podem ser mostradas no controle WebBrowser.  
  
```  
BOOL GetSilent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se caixas de diálogo não podem ser exibidas no controle WebBrowser; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getsource"></a>CHtmlView::GetSource  
 Chame essa função de membro para recuperar o código-fonte HTML da página da web.  
  
```  
BOOL GetSource(CString& strRef);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="parameters"></a>Parâmetros  
 `refString`  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que conterá o código-fonte.  
  
### <a name="remarks"></a>Comentários  
 Essa função é equivalente ao comando "Exibir fonte" no Internet Explorer, exceto que o código-fonte é retornado em um `CString`.  
  
##  <a name="getstatusbar"></a>CHtmlView::GetStatusBar  
 Chame essa função de membro para determinar se o controle WebBrowser exibe uma barra de status.  
  
```  
BOOL GetStatusBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de status pode ser exibida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="gettheatermode"></a>CHtmlView::GetTheaterMode  
 Chame essa função de membro para determinar se o navegador da web está em modo de teatro.  
  
```  
BOOL GetTheaterMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o navegador da web está no modo de teatro; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Quando o navegador da web está no modo de teatro, a janela principal do navegador ocupa a tela inteira, é exibida uma barra de ferramentas com um conjunto mínimo de ferramentas de navegação e barra de status aparece no canto superior direito da tela.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="gettoolbar"></a>CHtmlView::GetToolBar  
 Chame essa função de membro para determinar se a barra de ferramentas está visível.  
  
```  
int GetToolBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica se a barra de ferramentas está visível. Diferente de zero se a barra de ferramentas estiver visível; Caso contrário, zero.  
  
##  <a name="gettop"></a>CHtmlView::GetTop  
 Chame essa função de membro para recuperar a coordenada da tela da borda superior da janela principal do controle WebBrowser.  
  
```  
long GetTop() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Endereço de uma variável que recebe a coordenada da borda superior da janela principal da tela.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="gettoplevelcontainer"></a>CHtmlView::GetTopLevelContainer  
 Chame essa função de membro para determinar se o Internet Explorer é o contêiner de nível superior do controle WebBrowser.  
  
```  
BOOL GetTopLevelContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O contêiner diferente de zero é o contêiner de nível superior; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="gettype"></a>CHtmlView::GetType  
 Chame essa função de membro para recuperar o nome do tipo do documento ativo independente.  
  
```  
CString GetType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o nome do tipo do documento ativo independente.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getvisible"></a>CHtmlView::GetVisible  
 Chame essa função de membro para determinar se o objeto contido é visível.  
  
```  
BOOL GetVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto estiver visível; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="getwidth"></a>CHtmlView::GetWidth  
 Recupera a largura da janela principal do Internet Explorer.  
  
```  
long GetWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura atual da janela, em pixels.  
  
##  <a name="goback"></a>CHtmlView::GoBack  
 Navega para trás um item da lista de histórico.  
  
```  
void GoBack();
```  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="goforward"></a>CHtmlView::GoForward  
 Navega encaminhar um item da lista de histórico.  
  
```  
void GoForward();
```  
  
##  <a name="gohome"></a>CHtmlView::GoHome  
 Navega para a página inicial atual ou página de início especificada na caixa de diálogo Opções da Internet do Internet Explorer ou a caixa de diálogo Propriedades da Internet, acessado a partir do painel de controle.  
  
```  
void GoHome();
```  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="gosearch"></a>CHtmlView::GoSearch  
 Navega para a pesquisa página atual, conforme especificado na caixa de diálogo Opções da Internet do Internet Explorer ou a caixa de diálogo Propriedades da Internet, acessada a partir do painel de controle.  
  
```  
void GoSearch();
```  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="loadfromresource"></a>CHtmlView::LoadFromResource  
 Chame essa função de membro para carregar o recurso especificado para o controle WebBrowser.  
  
```  
BOOL LoadFromResource(LPCTSTR lpszResource);  
BOOL LoadFromResource(UINT nRes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResource`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do recurso para carregar.  
  
 `nRes`  
 A ID do buffer que contém o nome do recurso para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="navigate"></a>CHtmlView::Navigate  
 Chame essa função de membro para navegar para o recurso identificado por uma URL.  
  
```  
void Navigate(
    LPCTSTR URL,  
    DWORD dwFlags = 0,  
    LPCTSTR lpszTargetFrameName = NULL,  
    LPCTSTR lpszHeaders = NULL,  
    LPVOID lpvPostData = NULL,  
    DWORD dwPostDataLen = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *URL*  
 Uma cadeia de caracteres alocada pelo chamador que contém a URL de navegação, ou o caminho completo do arquivo para exibir.  
  
 `dwFlags`  
 Os sinalizadores de uma variável que especifica se é para adicionar o recurso para a lista de histórico, devem ser lidos para ou do cache de gravação e se deseja exibir o recurso em uma nova janela. A variável pode ser uma combinação de valores definidos pelo [BrowserNavConstants](https://msdn.microsoft.com/library/aa768360.aspx) enumeração.  
  
 `lpszTargetFrameName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do quadro no qual exibir o recurso.  
  
 `lpszHeaders`  
 Um ponteiro para um valor que especifica os cabeçalhos HTTP para enviar para o servidor. Esses cabeçalhos são adicionados aos cabeçalhos padrão do Internet Explorer. Os cabeçalhos podem especificar essas coisas como a ação necessária do servidor, o tipo de dados que está sendo passados para o servidor ou um código de status. Esse parâmetro é ignorado se *URL* não é uma URL HTTP.  
  
 `lpvPostData`  
 Um ponteiro para os dados a serem enviados com a transação HTTP POST. Por exemplo, a transação de POST é usada para enviar os dados coletados por um formulário HTML. Se esse parâmetro não especificar os dados de postagem, **navegar** emite uma transação HTTP GET. Esse parâmetro é ignorado se *URL* não é uma URL HTTP.  
  
 `dwPostDataLen`  
 Dados a serem enviados com a transação HTTP POST. Por exemplo, a transação de POST é usada para enviar os dados coletados por um formulário HTML. Se esse parâmetro não especificar os dados de postagem, **navegar** emite uma transação HTTP GET. Esse parâmetro é ignorado se *URL* não é uma URL HTTP.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="navigate2"></a>CHtmlView::Navigate2  
 Chame essa função de membro para navegar para o recurso identificado por uma URL, ou para o arquivo identificado por um caminho completo.  
  
```  
void Navigate2(
    LPITEMIDLIST pIDL,  
    DWORD dwFlags = 0,  
    LPCTSTR lpszTargetFrameName = NULL);

 
void Navigate2(
    LPCTSTR lpszURL,  
    DWORD dwFlags = 0,  
    LPCTSTR lpszTargetFrameName = NULL,  
    LPCTSTR lpszHeaders = NULL,  
    LPVOID lpvPostData = NULL,  
    DWORD dwPostDataLen = 0);

 
void Navigate2(
    LPCTSTR lpszURL,  
    DWORD dwFlags,  
    CByteArray& baPostedData,  
    LPCTSTR lpszTargetFrameName = NULL,  
    LPCTSTR lpszHeader = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pIDL*  
 Um ponteiro para um [ITEMIDLIST](http://msdn.microsoft.com/library/windows/desktop/bb773321) estrutura.  
  
 `dwFlags`  
 Os sinalizadores de uma variável que especifica se é para adicionar o recurso para a lista de histórico, devem ser lidos para ou do cache de gravação e se deseja exibir o recurso em uma nova janela. A variável pode ser uma combinação de valores definidos pelo [BrowserNavConstants](https://msdn.microsoft.com/library/aa768360.aspx) enumeração.  
  
 `lpszTargetFrameName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do quadro no qual exibir o recurso.  
  
 `lpszURL`  
 Um ponteiro para uma cadeia de caracteres que contém a URL.  
  
 `lpvPostData`  
 Dados a serem enviados com a transação HTTP POST. Por exemplo, a transação de POST é usada para enviar os dados coletados por um formulário HTML. Se esse parâmetro não especificar os dados de postagem, `Navigate2` emite uma transação HTTP GET. Esse parâmetro é ignorado se *URL* não é uma URL HTTP ou HTTPS.  
  
 `dwPostDataLen`  
 Comprimento em bytes dos dados apontada pelo `lpvPostData` parâmetro.  
  
 `lpszHeaders`  
 Um ponteiro para um valor que especifica os cabeçalhos HTTP ou HTTPS para enviar para o servidor. Esses cabeçalhos são adicionados aos cabeçalhos padrão do Internet Explorer. Os cabeçalhos podem especificar essas coisas como a ação necessária do servidor, o tipo de dados que está sendo passados para o servidor ou um código de status. Esse parâmetro é ignorado se *URL* não é uma URL HTTP ou HTTPS.  
  
 `baPostedData`  
 Uma referência a um [CByteArray](../../mfc/reference/cbytearray-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro estende o **navegar** a função de membro com o suporte à navegação em pastas especiais, como a área de trabalho e meu computador, são representadas pelo parâmetro *pIDL*.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCHtmlHttp#7](../../mfc/reference/codesnippet/cpp/chtmlview-class_1.cpp)]  
  
##  <a name="onbeforenavigate2"></a>CHtmlView::OnBeforeNavigate2  
 Essa função de membro é chamada pelo framework para fazer com que um evento acionado antes que ocorra uma navegação no navegador da web.  
  
```  
virtual void OnBeforeNavigate2(
    LPCTSTR lpszURL,  
    DWORD nFlags,  
    LPCTSTR lpszTargetFrameName,  
    CByteArray& baPostedData,  
    LPCTSTR lpszHeaders,  
    BOOL* pbCancel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszURL`  
 Ponteiro para uma cadeia de caracteres que contém a URL de navegação.  
  
 `nFlags`  
 Reservado para uso futuro.  
  
 `lpszTargetFrameName`  
 Uma cadeia de caracteres que contém o nome do quadro no qual exibir o recurso, ou **nulo** se nenhum quadro nomeado destina-se para o recurso.  
  
 `baPostedData`  
 Uma referência a um `CByteArray` objeto que contém os dados para enviar para o servidor se a transação HTTP POST estiver sendo usada.  
  
 `lpszHeaders`  
 Um ponteiro para uma cadeia de caracteres que contém os cabeçalhos HTTP adicionais para enviar para o servidor (HTTP URLs somente). Os cabeçalhos podem especificar essas coisas como a ação necessária do servidor, o tipo de dados que está sendo passados para o servidor ou um código de status.  
  
 `pbCancel`  
 Um ponteiro para um sinalizador de cancelamento. Um aplicativo pode definir esse parâmetro como diferente de zero para cancelar a operação de navegação ou zero para permitir que ele continue.  
  
##  <a name="oncommandstatechange"></a>CHtmlView::OnCommandStateChange  
 Essa função de membro é chamada pelo framework para notificar um aplicativo de que o estado ativado de um comando do navegador da web foi alterado.  
  
```  
virtual void OnCommandStateChange(
    long nCommand,  
    BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 *n Ncomando*  
 Identificador do comando cujo estado habilitado foi alterado.  
  
 `bEnable`  
 Estado habilitado. Esse parâmetro é diferente de zero se o comando é habilitado, ou zero se ele estiver desabilitado.  
  
##  <a name="ondocumentcomplete"></a>CHtmlView::OnDocumentComplete  
 Essa função de membro é chamada pelo framework para notificar um aplicativo que um documento tenha atingido o `READYSTATE_COMPLETE` estado.  
  
```  
virtual void OnDocumentComplete(LPCTSTR lpszURL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszURL`  
 Um ponteiro para uma cadeia de caracteres que é avaliada para a URL, UNC arquivo o nome, ou um PIDL (um ponteiro para uma lista de identificadores de item), o qual foi direcionada.  
  
### <a name="remarks"></a>Comentários  
 Nem todos os quadros serão acionado esse evento, mas cada quadro que dispara um [OnDownloadBegin](#ondownloadbegin) evento será acionado correspondente `OnDocumentComplete` eventos.  
  
 A URL é indicado pelo `lpszURL` pode ser diferente da URL que o navegador foi instruído para navegar, porque essa URL é a URL de conversão em formato canônico e qualificada. Por exemplo, se um aplicativo especifica uma URL de "www.microsoft.com" em uma chamada para [navegar](#navigate) ou [Navigate2](#navigate2), a URL passada `OnNavigateComplete2` será "http://www.microsoft.com/". Além disso, se o servidor redirecionado o navegador para uma URL diferente, a URL de redirecionamento aparecerá aqui.  
  
##  <a name="ondocwindowactivate"></a>CHtmlView::OnDocWindowActivate  
 Chamada da implementação do Internet Explorer ou MSHTML de **IOleInPlaceActiveObject::OnDocWindowActivate**, que notifica o objeto no local ativo quando a janela de documento do contêiner é ativada ou desativada.  
  
```  
virtual HRESULT OnDocWindowActivate(BOOL fActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fActivate`  
 Indica o estado da janela do documento. Se esse valor for diferente de zero, a janela está sendo ativada. Se esse valor for zero, a janela está sendo desativada.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnDocWindowActivate` para reagir ao `OnDocWindowActivate` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::OnDocWindowActivate](https://msdn.microsoft.com/library/aa753261.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="ondownloadbegin"></a>CHtmlView::OnDownloadBegin  
 Essa função de membro é chamada pelo framework para iniciar o download de um documento.  
  
```  
virtual void OnDownloadBegin();
```  
  
### <a name="remarks"></a>Comentários  
 Esse evento é acionado logo após o [OnBeforeNavigate2](#onbeforenavigate2) evento, a menos que a navegação é cancelada. Nenhuma animação ou "ocupada" indica que o contêiner precisa exibir deve ser conectada a este evento.  
  
##  <a name="ondownloadcomplete"></a>CHtmlView::OnDownloadComplete  
 Essa função de membro é chamada pelo framework para indicar que uma operação de navegação concluída, interrompida ou falha.  
  
```  
virtual void OnDownloadComplete();
```  
  
##  <a name="onenablemodeless"></a>CHtmlView::OnEnableModeless  
 Chamado quando o Internet Explorer ou MSHTML exibe interface modal.  
  
```  
virtual HRESULT OnEnableModeless(BOOL fEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fEnable`  
 Indica se caixas de diálogo sem janela restrita do host estão habilitadas ou desabilitadas. Se esse valor for diferente de zero, caixas de diálogo sem janela restrita estão habilitadas. Se esse valor for zero, caixas de diálogo sem janela restrita estão desabilitadas.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Habilita ou desabilita as caixas de diálogo sem janela restrita quando o contêiner cria ou destrói a caixa de diálogo modal. Substituir `OnEnableModeless` para reagir ao `EnableModeless` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::EnableModeless](https://msdn.microsoft.com/library/aa753253.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onfilterdataobject"></a>CHtmlView::OnFilterDataObject  
 Chamado no host pelo Internet Explorer ou MSHTML para permitir que o host substituir o Internet Explorer ou o objeto de dados do MSHTML.  
  
```  
virtual HRESULT OnFilterDataObject(
    LPDATAOBJECT pDataObject,  
    LPDATAOBJECT* ppDataObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Endereço do [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) interface fornecida pelo Internet Explorer ou MSHTML.  
  
 *ppDataObject*  
 O endereço que recebe o `IDataObject` ponteiro de interface fornecida pelo host. O conteúdo desse parâmetro sempre deve ser inicializado para **nulo**, mesmo se o método falhar.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se o objeto de dados for substituído, **S_FALSE** se o objeto de dados não for substituído, ou um código de erro definidas pelo OLE se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnFilterDataObject` para reagir ao `FilterDataObject` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::FilterDataObject](https://msdn.microsoft.com/library/aa753254.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onframewindowactivate"></a>CHtmlView::OnFrameWindowActivate  
 Chamado a partir do [IOleInPlaceActiveObject::OnFrameWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms683969) para notificar o objeto do nível superior do contêiner a janela do quadro é ativada ou desativada.  
  
```  
virtual HRESULT OnFrameWindowActivate(BOOL fActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fActivate`  
 Indica o estado da janela do quadro de nível superior do contêiner. Se esse valor for diferente de zero, a janela está sendo ativada. Se esse valor for zero, a janela está sendo desativada.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnFrameWindowActivate` para reagir ao `OnFrameWindowActivate` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::OnFrameWindowActivate](https://msdn.microsoft.com/library/aa753262.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onfullscreen"></a>CHtmlView::OnFullScreen  
 Essa função de membro é chamada pelo framework quando o [FullScreen](https://msdn.microsoft.com/library/aa752119.aspx) propriedade foi alterada.  
  
```  
virtual void OnFullScreen(BOOL bFullScreen);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bFullScreen*  
 Diferente de zero se o Internet Explorer está no modo de tela inteira. Caso contrário de zero.  
  
##  <a name="ongetdroptarget"></a>CHtmlView::OnGetDropTarget  
 Chamado pelo Internet Explorer ou MSHTML quando ele está sendo usado como um destino para permitir que o host fornecer uma alternativa `IDropTarget`.  
  
```  
virtual HRESULT OnGetDropTarget(
    LPDROPTARGET pDropTarget,  
    LPDROPTARGET* ppDropTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDropTarget`  
 [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) Internet Explorer ou MSHTML propõe usar.  
  
 `ppDropTarget`  
 Endereço do `IDropTarget` que recebe o `IDropTarget` host deseja fornecer o ponteiro de interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte [IDocHostUIHandler::GetDropTarget](https://msdn.microsoft.com/library/aa753255.aspx) no SDK do Windows para obter uma lista de códigos de retorno.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnGetDropTarget` para reagir ao `GetDropTarget` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::GetDropTarget](https://msdn.microsoft.com/library/aa753255.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="ongetexternal"></a>CHtmlView::OnGetExternal  
 Chamado pelo Internet Explorer ou MSHTML para obter o host `IDispatch` interface.  
  
```  
virtual HRESULT OnGetExternal(LPDISPATCH* lppDispatch);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lppDispatch*  
 Um ponteiro para o endereço que recebe o `IDispatch` ponteiro de interface do aplicativo host. Se o host expõe uma interface de automação, ele pode fornecer uma referência para o Internet Explorer ou MSHTML por esse parâmetro. O conteúdo desse parâmetro sempre deve ser inicializado para **nulo**, mesmo se o método falhar.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnGetExternal` para reagir ao `GetExternal` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::GetExternal](https://msdn.microsoft.com/library/aa753256.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="ongethostinfo"></a>CHtmlView::OnGetHostInfo  
 Recupera os recursos de interface do usuário do host do Internet Explorer ou MSHTML.  
  
```  
virtual HRESULT OnGetHostInfo(DOCHOSTUIINFO* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInfo`  
 Endereço de um [DOCHOSTUIINFO](https://msdn.microsoft.com/library/aa770044.aspx) estrutura que recebe recursos de interface do usuário do host.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnGetHostInfo` para reagir ao `GetHostInfo` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::GetHostInfo](https://msdn.microsoft.com/library/aa753257.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="ongetoptionkeypath"></a>CHtmlView::OnGetOptionKeyPath  
 Chame essa função de membro para obter a chave do registro sob a qual o Internet Explorer ou MSHTML armazena as preferências do usuário.  
  
```  
virtual HRESULT OnGetOptionKeyPath(
    LPOLESTR* pchKey,  
    DWORD dwReserved);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pchKey`  
 Endereço de um `LPOLESTR` que recebe a cadeia de subchaves de registro em que o host armazena suas opções padrão. Essa subchave será na chave HKEY_CURRENT_USER. Alocar usando essa memória [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727). O aplicativo de chamada é responsável por liberar essa memória usando [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722). Esse parâmetro sempre deve ser inicializado para **nulo**, mesmo se o método falhar.  
  
 `dwReserved`  
 Reservado para uso futuro. Não usado no momento.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou **S_FALSE** caso contrário. Se **S_FALSE**, Internet Explorer ou MSHTML padrão será suas próprias opções de usuário.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnGetOptionKeyPath` para reagir ao `GetOptionKeyPath` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::GetOptionKeyPath](https://msdn.microsoft.com/library/aa753258.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onhideui"></a>CHtmlView::OnHideUI  
 Essa função de membro é chamada pelo framework quando o Internet Explorer ou MSHTML remove seus menus e barras de ferramentas.  
  
```  
virtual HRESULT OnHideUI();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnHideUI` para reagir ao `HideUI` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::HideUI](https://msdn.microsoft.com/library/aa753259.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onmenubar"></a>CHtmlView::OnMenuBar  
 Essa função de membro é chamada pelo framework quando o [MenuBar](https://msdn.microsoft.com/library/aa752131.aspx) propriedade foi alterada.  
  
```  
virtual void OnMenuBar(BOOL bMenuBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bMenuBar*  
 Diferente de zero se a barra de menus do Internet Explorer estiver visível; Caso contrário de zero.  
  
##  <a name="onnavigatecomplete2"></a>CHtmlView::OnNavigateComplete2  
 Essa função de membro é chamada pelo framework depois que a navegação a um hiperlink é concluída (em uma janela ou um conjunto de quadros elemento).  
  
```  
virtual void OnNavigateComplete2(LPCTSTR strURL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *strURL*  
 Uma expressão de cadeia de caracteres que é avaliada para a URL, UNC nome de arquivo, ou PIDL (um ponteiro para uma lista de identificadores de item), o qual foi direcionada.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro de URL pode ser um PIDL no caso de uma entidade de espaço de nome do shell para o qual não há nenhuma representação de URL.  
  
 Observe que a URL contida no *strURL* pode ser diferente da URL que o navegador foi instruído para navegar, porque essa URL é a URL de conversão em formato canônico e qualificada. Por exemplo, se um aplicativo especifica uma URL de "www.microsoft.com" em uma chamada para [navegar](#navigate) ou [Navigate2](#navigate2), a URL passada `OnNavigateComplete2` será "http://www.microsoft.com/". Além disso, se o servidor redirecionado o navegador para uma URL diferente, a URL de redirecionamento aparecerá aqui.  
  
##  <a name="onnavigateerror"></a>CHtmlView::OnNavigateError  
 Chamado pelo framework se falhar de navegação a um hiperlink.  
  
```  
virtual void OnNavigateError(
    LPCTSTR lpszURL,  
    LPCTSTR lpszFrame,  
    DWORD dwError,  
    BOOL* pbCancel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszURL`  
 A URL para o qual a navegação falhou.  
  
 *lpszFrame*  
 O nome do quadro no qual o recurso está ser exibido ou nulo se nenhum quadro nomeado foi direcionado para o recurso.  
  
 `dwError`  
 Um código de status erro, se disponível. Para obter uma lista dos possíveis códigos de status HTTP e HRESULT, consulte [NavigateError códigos de Status de evento.](https://msdn.microsoft.com/library/aa768365.aspx)  
  
 `pbCancel`  
 Especifica se deseja cancelar a navegação para uma página de erro ou qualquer outra pesquisa de automática. Se **TRUE** (o padrão), continue com a navegação para uma página de erro ou busca automática; se **FALSE**, cancelar a navegação para uma página de erro ou busca automática.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para fornecer tratamento de erros de navegação personalizada.  
  
 Para obter mais informações, consulte [DWebBrowserEvents2::NavigateError](https://msdn.microsoft.com/library/aa768286.aspx)  
  
##  <a name="onnewwindow2"></a>CHtmlView::OnNewWindow2  
 Essa função de membro é chamada pelo framework quando uma nova janela será criado para exibir um recurso.  
  
```  
virtual void OnNewWindow2(
    LPDISPATCH* ppDisp,  
    BOOL* Cancel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppDisp`  
 Um ponteiro para um ponteiro de interface que, opcionalmente, recebe o `IDispatch` ponteiro de interface de um novo objeto WebBrowser ou Internet Explorer.  
  
 `Cancel`  
 Um ponteiro para um sinalizador de cancelamento. Um aplicativo pode definir esse parâmetro como diferente de zero para cancelar a operação de navegação ou zero para permitir que ele continue.  
  
### <a name="remarks"></a>Comentários  
 Esse evento precede a criação de uma nova janela de dentro de WebBrowser.  
  
##  <a name="onprogresschange"></a>CHtmlView::OnProgressChange  
 Essa função de membro é chamada pelo framework para notificar um aplicativo de que o progresso de uma operação de download foi atualizado.  
  
```  
virtual void OnProgressChange(
    long nProgress,  
    long nProgressMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nProgress*  
 Quantidade de progresso total para mostrar ou -1 quando andamento for concluído.  
  
 *nProgressMax*  
 Valor máximo de andamento.  
  
### <a name="remarks"></a>Comentários  
 O contêiner pode usar as informações fornecidas por esse evento para exibir o número de bytes baixados até o momento ou para atualizar um indicador de progresso.  
  
##  <a name="onpropertychange"></a>CHtmlView::OnPropertyChange  
 Essa função de membro é chamada pelo framework para notificar um aplicativo que [PutProperty](#putproperty) alterou o valor de uma propriedade.  
  
```  
virtual void OnPropertyChange(LPCTSTR lpszProperty);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProperty`  
 Um ponteiro para uma cadeia de caracteres que contém o nome da propriedade.  
  
##  <a name="onquit"></a>CHtmlView::OnQuit  
 Essa função de membro é chamada pelo framework para notificar um aplicativo que o aplicativo do Internet Explorer está pronto para sair.  
  
```  
virtual void OnQuit();
```  
  
##  <a name="onresizeborder"></a>CHtmlView::OnResizeBorder  
 Chamada da implementação do Internet Explorer ou MSHTML de [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053), que o objeto que ele precisa redimensionar seu espaço de borda de alertas.  
  
```  
virtual HRESULT OnResizeBorder(
    LPCRECT prcBorder,  
    LPOLEINPLACEUIWINDOW pUIWindow,  
    BOOL fFrameWindow);
```  
  
### <a name="parameters"></a>Parâmetros  
 `prcBorder`  
 Novo retângulo exterior para espaço de borda.  
  
 `pUIWindow`  
 Um ponteiro para a interface para o objeto de janela de quadro ou um documento cuja borda foi alterado.  
  
 `fFrameWindow`  
 **TRUE** se a janela do quadro está chamando [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053), caso contrário, **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnResizeBorder` para reagir ao `ResizeBorder` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::ResizeBorder](https://msdn.microsoft.com/library/aa753263.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onshowcontextmenu"></a>CHtmlView::OnShowContextMenu  
 Chamado a partir do Internet Explorer ou MSHTML quando ele está prestes a exibir o menu de contexto.  
  
```  
virtual HRESULT OnShowContextMenu(
    DWORD dwID,  
    LPPOINT ppt,  
    LPUNKNOWN pcmdtReserved,  
    LPDISPATCH pdispReserved);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwID`  
 Identificador do menu de contexto a ser exibido. Consulte **IDocHostUIHandler::ShowContextMenu** no SDK do Windows para obter uma lista de valores.  
  
 `ppt`  
 Coordenadas da tela do menu.  
  
 `pcmdtReserved`  
 [IOleCommandTarget](http://msdn.microsoft.com/library/windows/desktop/ms683797) interface usada para consultar o status do comando e executar comandos nesse objeto.  
  
 `pdispReserved`  
 Interface IDispatch do objeto na tela de coordenadas. Isso permite que um host diferenciar objetos específicos para fornecer contexto mais específico.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte [IDocHostUIHandler::ShowContextMenu](https://msdn.microsoft.com/library/aa753264.aspx) no SDK do Windows para obter uma lista de valores.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnShowContextMenu` para reagir ao `ShowContextMenu` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::ShowContextMenu](https://msdn.microsoft.com/library/aa753264.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onshowui"></a>CHtmlView::OnShowUI  
 Chamado antes do Internet Explorer ou MSHTML exibe seus menus e barras de ferramentas.  
  
```  
virtual HRESULT OnShowUI(
    DWORD dwID,  
    LPOLEINPLACEACTIVEOBJECT pActiveObject,  
    LPOLECOMMANDTARGET pCommandTarget,  
    LPOLEINPLACEFRAME pFrame,  
    LPOLEINPLACEUIWINDOW pDoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwID`  
 Reservado para uso futuro.  
  
 `pActiveObject`  
 [IOleInPlaceActiveObject](http://msdn.microsoft.com/library/windows/desktop/ms691299) interface do objeto ativo no momento.  
  
 `pCommandTarget`  
 [IOleCommandTarget](http://msdn.microsoft.com/library/windows/desktop/ms683797) interface do objeto.  
  
 `pFrame`  
 [IOleInPlaceFrame](http://msdn.microsoft.com/library/windows/desktop/ms692770) interface do objeto. Isso é necessário para os menus e barras de ferramentas.  
  
 `pDoc`  
 [IOleInPlaceUIWindow](http://msdn.microsoft.com/library/windows/desktop/ms680716) interface para o objeto. Isso é necessário para barras de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Consulte [IDocHostUIHandler::ShowUI](https://msdn.microsoft.com/library/aa753265.aspx) no SDK do Windows para obter uma lista de valores.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnShowUI` para reagir ao `ShowUI` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::ShowUI](https://msdn.microsoft.com/library/aa753265.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onstatusbar"></a>CHtmlView::OnStatusBar  
 Essa função de membro é chamada pelo framework quando o [StatusBar](https://msdn.microsoft.com/library/aa768270.aspx) propriedade foi alterada.  
  
```  
virtual void OnStatusBar(BOOL bStatusBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bStatusBar*  
 Diferente de zero se a barra de status do Internet Explorer está visível ou zero caso contrário.  
  
##  <a name="onstatustextchange"></a>CHtmlView::OnStatusTextChange  
 Essa função de membro é chamada pelo framework para notificar um aplicativo de que o texto da barra de status associado ao controle WebBrowser foi alterado.  
  
```  
virtual void OnStatusTextChange(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Uma cadeia de caracteres que contém o novo texto da barra de status.  
  
##  <a name="ontheatermode"></a>CHtmlView::OnTheaterMode  
 Essa função de membro é chamada pelo framework quando o [TheaterMode](https://msdn.microsoft.com/library/aa768273.aspx) propriedade foi alterada.  
  
```  
virtual void OnTheaterMode(BOOL bTheaterMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bTheaterMode*  
 Diferente de zero se o Internet Explorer está no modo de teatro; Caso contrário de zero.  
  
##  <a name="ontitlechange"></a>CHtmlView::OnTitleChange  
 Essa função de membro é chamada pelo framework para notificar um aplicativo se o título de um documento no controle do WebBrowser estiver disponível ou as alterações.  
  
```  
virtual void OnTitleChange(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 O novo título do documento.  
  
### <a name="remarks"></a>Comentários  
 Para HTML, o título pode ser alterado; enquanto ainda está sendo baixado HTML, a URL do documento é definida como o título. Depois que o título real (se houver) é analisado do HTML, o título é alterado para refletir o título real.  
  
##  <a name="ontoolbar"></a>CHtmlView::OnToolBar  
 Essa função de membro é chamada pelo framework quando o [barra de ferramentas](https://msdn.microsoft.com/library/aa768274.aspx) propriedade foi alterada.  
  
```  
virtual void OnToolBar(BOOL bToolBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bToolBar*  
 Diferente de zero se a barra de ferramentas do Internet Explorer está visível ou zero caso contrário.  
  
##  <a name="ontranslateaccelerator"></a>CHtmlView::OnTranslateAccelerator  
 Chamado pelo Internet Explorer ou MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693360) ou [IOleControlSite::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693756) é chamado para processar mensagens de tecla de aceleração de menu do fila de mensagens do contêiner.  
  
```  
virtual HRESULT OnTranslateAccelerator(
    LPMSG lpMsg,  
    const GUID* pguidCmdGroup,  
    DWORD nCmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMsg`  
 Aponta para a mensagem que talvez precisem ser convertido.  
  
 `pguidCmdGroup`  
 Identificador de grupo do comando.  
  
 `nCmdID`  
 Identificador do comando.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou **S_FALSE** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnTranslateAccelerator` para reagir ao `TranslateAccelerator` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::TranslateAccelerator](https://msdn.microsoft.com/library/aa753266.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="ontranslateurl"></a>CHtmlView::OnTranslateUrl  
 Chamado pelo Internet Explorer ou MSHTML para permitir que o host a oportunidade de modificar a URL a ser carregado.  
  
```  
virtual HRESULT OnTranslateUrl(
    DWORD dwTranslate,  
    OLECHAR* pchURLIn,  
    OLECHAR** ppchURLOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwTranslate`  
 Reservado para uso futuro.  
  
 `pchURLIn`  
 Endereço de uma cadeia de caracteres fornecida pelo Internet Explorer ou MSHTML que representa a URL a ser convertido.  
  
 `ppchURLOut`  
 Endereço de um ponteiro de cadeia de caracteres que recebe o endereço da URL traduzido. O host aloca o buffer usando o alocador de memória da tarefa. O conteúdo desse parâmetro sempre deve ser inicializado para **nulo**, mesmo se a URL não é convertida ou o método falhar.  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se a URL foi convertida, **S_FALSE** se a URL não foi convertida, ou um código de erro definidas pelo OLE se ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 Substituir `OnTranslateUrl` para reagir ao `TranslateUrl` notificação do controle de navegador da Web da Microsoft. Consulte [IDocHostUIHandler::TranslateUrl](https://msdn.microsoft.com/library/aa753267.aspx) no SDK do Windows para obter mais informações.  
  
##  <a name="onupdateui"></a>CHtmlView::OnUpdateUI  
 Notifica o host que o estado do comando foi alterado.  
  
```  
virtual HRESULT OnUpdateUI();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `S_OK`Se for bem-sucedido, ou caso contrário, um código de erro definido pelo OLE.  
  
### <a name="remarks"></a>Comentários  
 O host deve atualizar o estado dos botões da barra de ferramentas. Este método é chamado, independentemente do valor de retorno de `ShowUI`. Substituir `OnUpdateUI` para reagir ao `UpdateUI` notificação do controle de navegador da Web da Microsoft.  
  
##  <a name="onvisible"></a>CHtmlView::OnVisible  
 Essa função de membro é chamada pelo framework quando a janela para o WebBrowser deve ser mostrada ou ocultada.  
  
```  
virtual void OnVisible(BOOL bVisible);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bVisible`  
 Diferente de zero se o objeto está visível ou zero caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Isso permite que a janela do host do controle de objeto se comporta da mesma forma que se comportem de janela do Internet Explorer.  
  
##  <a name="putproperty"></a>CHtmlView::PutProperty  
 Chame essa função de membro para definir a propriedade associada a um determinado objeto.  
  
```  
void PutProperty(
    LPCTSTR lpszProperty,  
    const VARIANT& vtValue);

 
void PutProperty(
    LPCTSTR lpszPropertyName,  
    double dValue);

 
void PutProperty(
    LPCTSTR lpszPropertyName,  
    long lValue);

 
void PutProperty(
    LPCTSTR lpszPropertyName,  
    LPCTSTR lpszValue);

 
void PutProperty(
    LPCTSTR lpszPropertyName,  
    short nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProperty`  
 Uma cadeia de caracteres que contém a propriedade definida.  
  
 *vtValue*  
 O novo valor da propriedade indicado pelo `lpszProperty`.  
  
 *lpszPropertyName*  
 Um ponteiro para uma cadeia de caracteres que contém o nome da propriedade a ser definido.  
  
 *dValue*  
 O novo valor da propriedade.  
  
 `lValue`  
 O novo valor da propriedade.  
  
 `lpszValue`  
 Um ponteiro para uma cadeia de caracteres que contém o novo valor da propriedade.  
  
 `nValue`  
 O novo valor da propriedade.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="queryformscommand"></a>CHtmlView::QueryFormsCommand  
 Consulta o status de um ou mais comandos gerados pelos eventos de interface do usuário.  
  
```  
HRESULT QueryFormsCommand(
    DWORD dwCommandID,  
    BOOL* pbSupported,  
    BOOL* pbEnabled,  
    BOOL* pbChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCommandID`  
 O identificador do comando que está sendo consultado.  
  
 *pbSupported*  
 Um ponteiro para um **BOOL** especificando se o comando (identificada pelo `dwCommandID`) é suportado. Se for TRUE, o comando é suportado; Caso contrário, FALSE.  
  
 `pbEnabled`  
 Um ponteiro para um **BOOL** especificando se o comando (identificada pelo `dwCommandID`) está habilitado. Se for TRUE, o comando é suportado; Caso contrário, FALSE.  
  
 *pbChecked*  
 Um ponteiro para um **BOOL** especificando se o comando (identificada pelo `dwCommandID`) é verificada. Se for TRUE, o comando é suportado; Caso contrário, FALSE.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Para obter uma lista completa de valores possíveis, consulte [IOleCommandTarget::QueryStatus](http://msdn.microsoft.com/library/windows/desktop/ms688491) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 `QueryFormsCommand`implementa o comportamento de [IOleCommandTarget::QueryStatus](http://msdn.microsoft.com/library/windows/desktop/ms688491) método.  
  
##  <a name="querystatuswb"></a>CHtmlView::QueryStatusWB  
 Chame essa função de membro para consultar um status de comando.  
  
```  
OLECMDF QueryStatusWB(OLECMDID cmdID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 O [OLECMDID](http://msdn.microsoft.com/library/windows/desktop/ms691264) valor do comando para o qual o chamador precisa das informações de status.  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do [OLECMDF](http://msdn.microsoft.com/library/windows/desktop/ms695237) valor que recebe o status do comando.  
  
### <a name="remarks"></a>Comentários  
 `QueryStatusWB`implementa o comportamento de [IOleCommandTarget::QueryStatus](http://msdn.microsoft.com/library/windows/desktop/ms688491) método.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="refresh"></a>CHtmlView::Refresh  
 Recarrega a URL ou o arquivo que o navegador da web está exibindo no momento.  
  
```  
void Refresh();
```  
  
### <a name="remarks"></a>Comentários  
 **Atualizar** não contém parâmetros para definir o nível de atualização.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="refresh2"></a>CHtmlView::Refresh2  
 Recarrega o arquivo que o Internet Explorer está exibindo no momento.  
  
```  
void Refresh2(int nLevel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLevel`  
 O endereço da variável que especificam o nível de atualização. As variáveis de possíveis são definidas em [RefreshConstants](https://msdn.microsoft.com/library/aa768363.aspx), no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [atualizar](#refresh), `Refresh2` contém um parâmetro que especifica o nível de atualização.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setaddressbar"></a>CHtmlView::SetAddressBar  
 Chame essa função de membro para mostrar ou ocultar a barra de endereço do objeto do Internet Explorer.  
  
```  
void SetAddressBar(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero para mostrar a barra de endereços. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="setfullscreen"></a>CHtmlView::SetFullScreen  
 Chame essa função de membro para configurar o Internet Explorer para o modo de janela de tela inteira ou normal.  
  
```  
void SetFullScreen(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero para o modo de tela inteira; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 No modo de tela inteira, a janela principal do Internet Explorer é maximizada e a barra de status, barra de ferramentas, barra de menus e barras de título estão ocultos.  
  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="setheight"></a>CHtmlView::SetHeight  
 Chame essa função de membro para definir a altura da janela principal do Internet Explorer.  
  
```  
void SetHeight(long nNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewValue`  
 A altura, em pixels, da janela principal.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setleft"></a>CHtmlView::SetLeft  
 Define a posição horizontal da janela principal do Internet Explorer.  
  
```  
void SetLeft(long nNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewValue`  
 A coordenada da borda esquerda da janela principal da tela.  
  
##  <a name="setmenubar"></a>CHtmlView::SetMenuBar  
 Chame essa função de membro para mostrar ou ocultar a barra de menus do Internet Explorer.  
  
```  
void SetMenuBar(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero para mostrar a barra de menus; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="setoffline"></a>CHtmlView::SetOffline  
 Chame essa função de membro para definir um valor que indica se o controle WebBrowser no momento está operando no modo offline.  
  
```  
void SetOffline(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero para ler do cache local; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 No modo offline, o navegador lê páginas HTML do cache local em vez do documento de origem.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setregisterasbrowser"></a>CHtmlView::SetRegisterAsBrowser  
 Chame essa função de membro para definir um valor que indica se o controle WebBrowser está registrado como um navegador de nível superior para a resolução de nome de destino.  
  
```  
void SetRegisterAsBrowser(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Determina se o Internet Explorer está registrado como um navegador de nível superior. Se for diferente de zero, o navegador da web está registrado como um navegador de nível superior; Se for zero, não é um navegador de nível superior. O valor padrão é zero.  
  
### <a name="remarks"></a>Comentários  
 Um navegador de nível superior é o navegador definido no registro como navegador padrão.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setregisterasdroptarget"></a>CHtmlView::SetRegisterAsDropTarget  
 Chame essa função de membro para definir um valor que indica se o controle WebBrowser está registrado como um destino de navegação.  
  
```  
void SetRegisterAsDropTarget(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Determina se o controle WebBrowser é registrado como um destino de navegação. Se for diferente de zero, o objeto é registrado como um destino de soltar; Se for zero, não é um destino de soltar.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setsilent"></a>CHtmlView::SetSilent  
 Chame essa função de membro para definir um valor que indica se as caixas de diálogo podem ser mostradas.  
  
```  
void SetSilent(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Se for diferente de zero, caixas de diálogo não serão exibidas; Se for zero, caixas de diálogo serão exibidas. O valor padrão é zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setstatusbar"></a>CHtmlView::SetStatusBar  
 Chame essa função de membro para exibir a barra de status.  
  
```  
void SetStatusBar(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero se a barra de status estiver visível; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="settheatermode"></a>CHtmlView::SetTheaterMode  
 Chame essa função de membro para definir um valor que indica se o controle WebBrowser está no modo de teatro.  
  
```  
void SetTheaterMode(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero para definir o controle WebBrowser como modo de teatro; Caso contrário, zero. O valor padrão é zero.  
  
### <a name="remarks"></a>Comentários  
 Quando o navegador da web está no modo de teatro, a janela principal do navegador ocupa a tela inteira, é exibida uma barra de ferramentas com um conjunto mínimo de ferramentas de navegação e barra de status aparece no canto superior direito da tela.  
  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="settoolbar"></a>CHtmlView::SetToolBar  
 Chame essa função de membro para mostrar ou ocultar a barra de ferramentas do Internet Explorer.  
  
```  
void SetToolBar(int nNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewValue`  
 Indica se deve exibir a barra de ferramentas. Diferente de zero se a barra de ferramentas a ser exibido. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se ao Internet Explorer. Se você usar essa chamada com um controle WebBrowser, nenhum erro será retornado, mas ele irá ignorar essa chamada.  
  
##  <a name="settop"></a>CHtmlView::SetTop  
 Chamar essa função de membro para definir a distância entre a borda superior interna do controle WebBrowser e a borda superior de seu contêiner  
  
```  
void SetTop(long nNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewValue`  
 A coordenada da borda superior da janela principal da tela.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setvisible"></a>CHtmlView::SetVisible  
 Chame essa função de membro para definir o estado de visibilidade do controle WebBrowser.  
  
```  
void SetVisible(BOOL bNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNewValue`  
 Diferente de zero se o controle está visível; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
##  <a name="setwidth"></a>CHtmlView::SetWidth  
 Define a largura da janela principal do Internet Explorer.  
  
```  
void SetWidth(long nNewValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewValue`  
 A largura, em pixels, da janela principal do Internet Explorer.  
  
##  <a name="stop"></a>CHtmlView::Stop  
 Chame essa função de membro para cancelar qualquer navegação pendente ou operação de download e parar qualquer elemento de página dinâmica, como sons em segundo plano e animações.  
  
```  
void Stop();
```  
  
### <a name="remarks"></a>Comentários  
 Aplica-se a WebBrowser e do Internet Explorer.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [IWebBrowser2](https://msdn.microsoft.com/library/aa752127.aspx)

