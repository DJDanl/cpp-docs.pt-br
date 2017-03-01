---
title: Classe CMDIFrameWndEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMDIFrameWndEx.AddDockSite
- CMDIFrameWndEx
- CMDIFrameWndEx::AddDockSite
dev_langs:
- C++
helpviewer_keywords:
- CMDIFrameWndEx class
ms.assetid: dbcafcb3-9a7a-4f11-9dfe-ba57565c81d0
caps.latest.revision: 42
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b9946f59b9ed789604ac6a02d2148188831bae56
ms.lasthandoff: 02/25/2017

---
# <a name="cmdiframewndex-class"></a>Classe CMDIFrameWndEx
Estende a funcionalidade do [CMDIFrameWnd](../../mfc/reference/cframewnd-class.md), uma janela de quadro de Interface de documentos múltiplos (MDI).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMDIFrameWndEx : public CMDIFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIFrameWndEx::ActiveItemRecalcLayout](#activeitemrecalclayout)|Recalcula o layout do item ativo.|  
|`CMDIFrameWndEx::AddDockSite`|Esse método não é usado.|  
|[CMDIFrameWndEx::AddPane](#addpane)|Registra um painel com o Gerenciador de encaixe.|  
|[CMDIFrameWndEx::AdjustClientArea](#adjustclientarea)|Reduz a área do cliente para permitir uma borda.|  
|[CMDIFrameWndEx::AdjustDockingLayout](#adjustdockinglayout)|Recalcula o layout de todos os painéis encaixados.|  
|[CMDIFrameWndEx::AreMDITabs](#aremditabs)|Determina se o recurso de guias MDI ou o recurso grupos de com guias MDI está habilitado.|  
|[CMDIFrameWndEx::CanCovertControlBarToMDIChild](#cancovertcontrolbartomdichild)|Chamado pela estrutura para determinar se a janela do quadro pode converter painéis de encaixe em documentos com guias.|  
|[CMDIFrameWndEx::ControlBarToTabbedDocument](#controlbartotabbeddocument)|Converte o painel de encaixe especificado em um documento com guias.|  
|[CMDIFrameWndEx::CreateDocumentWindow](#createdocumentwindow)|Cria uma janela de documento filho.|  
|[CMDIFrameWndEx::CreateNewWindow](#createnewwindow)|Chamado pela estrutura para criar uma nova janela.|  
|`CMDIFrameWndEx::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMDIFrameWndEx::DockPane](#dockpane)|Encaixa o painel especificado para a janela do quadro.|  
|[CMDIFrameWndEx::DockPaneLeftOf](#dockpaneleftof)|Encaixa um painel à esquerda do outro painel.|  
|[CMDIFrameWndEx::EnableAutoHidePanes](#enableautohidepanes)|Permite oculta automaticamente modo para painéis quando eles estão encaixados nos lados especificados da janela do quadro principal.|  
|[CMDIFrameWndEx::EnableDocking](#enabledocking)|Habilita o encaixe dos painéis que pertencem à janela de quadro MDI.|  
|[CMDIFrameWndEx::EnableFullScreenMainMenu](#enablefullscreenmainmenu)|Mostra ou oculta o menu principal no modo de tela inteira.|  
|[CMDIFrameWndEx::EnableFullScreenMode](#enablefullscreenmode)|Habilita o modo de tela inteira para a janela do quadro.|  
|[CMDIFrameWndEx::EnableLoadDockState](#enableloaddockstate)|Habilita ou desabilita o carregamento do estado de encaixe.|  
|[CMDIFrameWndEx::EnableMDITabbedGroups](#enablemditabbedgroups)|Habilita ou desabilita o recurso grupos de MDI com guias.|  
|[CMDIFrameWndEx::EnableMDITabs](#enablemditabs)|Habilita ou desabilita o recurso de guias MDI. Quando habilitada, a janela de quadro exibe uma guia para cada janela de filho MDI.|  
|[CMDIFrameWndEx::EnableMDITabsLastActiveActivation](#enablemditabslastactiveactivation)|Especifica se a última guia ativa deve ser ativada quando o usuário fecha a guia atual.|  
|[CMDIFrameWndEx::EnablePaneMenu](#enablepanemenu)|Habilita ou desabilita a criação automática e o gerenciamento de menu do painel pop-up, que exibe uma lista dos painéis do aplicativo.  .|  
|[CMDIFrameWndEx::EnableWindowsDialog](#enablewindowsdialog)|Insere um item de menu cuja ID de comando chama uma [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) caixa de diálogo.|  
|[CMDIFrameWndEx::GetActivePopup](#getactivepopup)|Retorna um ponteiro para o menu pop-up exibido atualmente.|  
|[CMDIFrameWndEx::GetPane](#getpane)|Retorna um ponteiro para o painel que possui a ID do controle especificado.|  
|[CMDIFrameWndEx::GetDefaultResId](#getdefaultresid)|Retorna a ID de recursos compartilhados da janela de quadro MDI.|  
|[CMDIFrameWndEx::GetMDITabGroups](#getmditabgroups)|Retorna que uma lista de MDI com guias windows.|  
|[CMDIFrameWndEx::GetMDITabs](#getmditabs)|Retorna uma referência à janela com guias sublinhada.|  
|[CMDIFrameWndEx::GetMDITabsContextMenuAllowedItems](#getmditabscontextmenualloweditems)|Retorna uma combinação de sinalizadores que determina quais itens de menu de contexto são válidos quando o recurso de grupos de com guias MDI está habilitado.|  
|[CMDIFrameWndEx::GetMenuBar](#getmenubar)|Retorna um ponteiro para um objeto de barra de menu anexado à janela de quadro.|  
|[CMDIFrameWndEx::GetRibbonBar](#getribbonbar)|Recupera o controle de barra de faixa de opções para o quadro.|  
|[CMDIFrameWndEx::GetTearOffBars](#gettearoffbars)|Retorna uma lista de [CPane](../../mfc/reference/cpane-class.md)-objetos que estão em um estado destacável derivados.|  
|`CMDIFrameWndEx::GetThisClass`|Chamado pela estrutura para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMDIFrameWndEx::GetToolbarButtonToolTipText](#gettoolbarbuttontooltiptext)|Chamado pela estrutura quando o aplicativo exibirá a dica de ferramenta para um botão da barra de ferramentas.|  
|[CMDIFrameWndEx::InsertPane](#insertpane)|Registra o painel especificado com o Gerenciador de encaixe.|  
|[CMDIFrameWndEx::IsFullScreen](#isfullscreen)|Determina se a janela do quadro está no modo de tela inteira.|  
|[CMDIFrameWndEx::IsMDITabbedGroup](#ismditabbedgroup)|Determina se o recurso de grupos de com guias MDI está habilitado.|  
|[CMDIFrameWndEx::IsMemberOfMDITabGroup](#ismemberofmditabgroup)|Determina se a janela com guias especificada está na lista de janelas que estão em grupos com guias MDI.|  
|[CMDIFrameWndEx::IsMenuBarAvailable](#ismenubaravailable)|Determina se a janela do quadro tem uma barra de menus.|  
|[CMDIFrameWndEx::IsPointNearDockSite](#ispointneardocksite)|Determina se um ponto especificado é o local de encaixe próximo.|  
|[CMDIFrameWndEx::IsPrintPreview](#isprintpreview)|Determina se a janela do quadro está no modo de visualização de impressão.|  
|[CMDIFrameWndEx::LoadFrame](#loadframe)|Cria uma janela de quadro de informações sobre o recurso. (Substitui `CMDIFrameWnd::LoadFrame`.)|  
|[CMDIFrameWndEx::LoadMDIState](#loadmdistate)|Carrega o layout especificado MDI com guias grupos e a lista de documentos abertos anteriormente.|  
|[CMDIFrameWndEx::MDITabMoveToNextGroup](#mditabmovetonextgroup)|Move a guia ativa da janela ativa no momento com guias para o grupo de guias anterior ou seguinte.|  
|[CMDIFrameWndEx::MDITabNewGroup](#mditabnewgroup)|Cria um novo grupo com guias que tem uma única janela.|  
|[CMDIFrameWndEx::NegotiateBorderSpace](#negotiateborderspace)|Negocia espaço de borda em uma janela de quadro durante a ativação no local de OLE.|  
|[CMDIFrameWndEx::OnCloseDockingPane](#onclosedockingpane)|Chamado pela estrutura quando o usuário clica o **fechar** botão em um painel acoplável.|  
|[CMDIFrameWndEx::OnCloseMiniFrame](#oncloseminiframe)|Chamado pela estrutura quando o usuário clica o **fechar** botão em uma janela de quadro mini flutuante.|  
|[CMDIFrameWndEx::OnClosePopupMenu](#onclosepopupmenu)|Chamado pela estrutura quando processa um menu pop-up ativa um `WM_DESTROY` mensagem.|  
|[CMDIFrameWndEx::OnCmdMsg](#oncmdmsg)|Chamado pela estrutura para rotear e distribuir mensagens de comando e atualizar objetos de interface do usuário do comando.|  
|[CMDIFrameWndEx::OnDrawMenuImage](#ondrawmenuimage)|Chamado pela estrutura quando a imagem associada a um item de menu é desenhada.|  
|[CMDIFrameWndEx::OnDrawMenuLogo](#ondrawmenulogo)|Chamado pela estrutura quando um [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)processos um `WM_PAINT` mensagem.|  
|[CMDIFrameWndEx::OnEraseMDIClientBackground](#onerasemdiclientbackground)|Chamado pela estrutura quando o MDI processos de janela de quadro um `WM_ERASEBKGND` mensagem.|  
|[CMDIFrameWndEx::OnMenuButtonToolHitTest](#onmenubuttontoolhittest)|Chamado pela estrutura quando um [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)objeto processos um `WM_NCHITTEST` mensagem.|  
|[CMDIFrameWndEx::OnMoveMiniFrame](#onmoveminiframe)|Chamado pela estrutura para mover uma janela de quadro simplificado.|  
|[CMDIFrameWndEx::OnSetPreviewMode](#onsetpreviewmode)|Define o modo de visualização de impressão de janela de quadro principal do aplicativo. (Substitui [CFrameWnd::OnSetPreviewMode](../../mfc/reference/cframewnd-class.md#onsetpreviewmode).)|  
|[CMDIFrameWndEx::OnShowCustomizePane](#onshowcustomizepane)|Chamado pela estrutura quando um painel Personalizar rápida é ativado.|  
|[CMDIFrameWndEx::OnShowMDITabContextMenu](#onshowmditabcontextmenu)|Chamado pela estrutura quando um menu de contexto deve ser exibido em uma das guias. (Válida para grupos com guias MDI somente).|  
|[CMDIFrameWndEx::OnShowPanes](#onshowpanes)|Chamado pela estrutura para mostrar ou ocultar painéis.|  
|[CMDIFrameWndEx::OnShowPopupMenu](#onshowpopupmenu)|Chamado pela estrutura quando um menu pop-up é ativado.|  
|[CMDIFrameWndEx::OnSizeMDIClient](#onsizemdiclient)|Chamado pela estrutura quando o tamanho da janela MDI do cliente está sendo alterado.|  
|[CMDIFrameWndEx::OnTearOffMenu](#ontearoffmenu)|Chamado pela estrutura quando um menu que tem uma barra destacável é ativado.|  
|[CMDIFrameWndEx::OnUpdateFrameMenu](#onupdateframemenu)|Chamado pela estrutura para atualizar o menu do quadro. (Substitui `CMDIFrameWnd::OnUpdateFrameMenu`.)|  
|[CMDIFrameWndEx::PaneFromPoint](#panefrompoint)|Retorna o painel de encaixe que contém o ponto especificado.|  
|`CMDIFrameWndEx::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows.  (Substitui `CMDIFrameWnd::PreTranslateMessage`.)|  
|[CMDIFrameWndEx::RecalcLayout](#recalclayout)|Chamado pela estrutura para recalcular o layout da janela do quadro. (Substitui [CFrameWnd::RecalcLayout](../../mfc/reference/cframewnd-class.md#recalclayout).)|  
|[CMDIFrameWndEx::RemovePaneFromDockManager](#removepanefromdockmanager)|Cancela o registro de um painel e a remove do Gerenciador de encaixe.|  
|[CMDIFrameWndEx::SaveMDIState](#savemdistate)|Salva o layout atual de MDI com guias grupos e a lista de documentos abertos anteriormente.|  
|[CMDIFrameWndEx::SetPrintPreviewFrame](#setprintpreviewframe)|Define a janela do quadro de visualização de impressão.|  
|[CMDIFrameWndEx::SetupToolbarMenu](#setuptoolbarmenu)|Modifica um objeto toolbar procurando itens fictícios e substituí-los com os itens definidos pelo usuário especificados.|  
|[CMDIFrameWndEx::ShowFullScreen](#showfullscreen)|Alterna o quadro principal do modo normal para o modo de tela inteira.|  
|[CMDIFrameWndEx::ShowPane](#showpane)|Mostra ou oculta o painel especificado.|  
|[CMDIFrameWndEx::ShowWindowsDialog](#showwindowsdialog)|Cria um [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) caixa e o abre.|  
|[CMDIFrameWndEx::TabbedDocumentToControlBar](#tabbeddocumenttocontrolbar)|Converte o documento com guias especificado em um painel de encaixe.|  
|[CMDIFrameWndEx::UpdateCaption](#updatecaption)|Chamado pela estrutura para atualizar a legenda do quadro de janela.|  
|[CMDIFrameWndEx::UpdateMDITabbedBarsIcons](#updatemditabbedbarsicons)|Define o ícone para cada painel com guias MDI.|  
|[CMDIFrameWndEx::WinHelp](#winhelp)|Chamado pela estrutura para iniciar a Ajuda de contexto ou aplicativo WinHelp. (Substitui [CWnd::WinHelp](../../mfc/reference/cwnd-class.md#winhelp).)|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIFrameWndEx::m_bCanCovertControlBarToMDIChild](#m_bcancovertcontrolbartomdichild)|Determina se os painéis de encaixe podem ser convertidos em janelas filho MDI.|  
|[CMDIFrameWndEx::m_bDisableSetRedraw](#m_bdisablesetredraw)|Habilita ou desabilita a otimização de redesenho de janelas filho MDI.|  
  
## <a name="remarks"></a>Comentários  
 Para tirar proveito dos recursos de personalização estendido em seu aplicativo MDI, derive a classe de janela de quadro MDI do aplicativo de `CMDIFrameWndEx` em vez de `CMDIFrameWnd`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir deriva uma classe de `CMDIFrameWndEx`. Este trecho de código é proveniente do [DrawClient exemplo: MFC Ribbon-Based OLE objeto aplicativo de desenho](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient n º&1;](../../mfc/reference/codesnippet/cpp/cmdiframewndex-class_1.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)  
  
 [CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxMDIFrameWndEx.h  
  
##  <a name="a-nameactiveitemrecalclayouta--cmdiframewndexactiveitemrecalclayout"></a><a name="activeitemrecalclayout"></a>CMDIFrameWndEx::ActiveItemRecalcLayout  
 Recalcula o layout do item ativo.  
  
```  
void ActiveItemRecalcLayout();
```  
  
##  <a name="a-nameaddpanea--cmdiframewndexaddpane"></a><a name="addpane"></a>CMDIFrameWndEx::AddPane  
 Registra um painel com o Gerenciador de encaixe.  
  
```  
BOOL AddPane(
    CBasePane* pControlBar,  
    BOOL bTail=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 Ponteiro para o painel para registrar.  
  
 [in] `bTail`  
 Especifica se deseja adicionar esse painel para o final da lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero se o painel foi registrado com êxito. Retorna 0 se o painel já está registrado com o Gerenciador de encaixe.  
  
### <a name="remarks"></a>Comentários  
 Cada painel deve ser registrado com o [CDockingManager classe](../../mfc/reference/cdockingmanager-class.md) para usar uma parte no layout do encaixe. Use esse método para notificar o Gerenciador de encaixe que você deseja encaixar um painel específico. Depois que esse painel é registrado, o Gerenciador de encaixe alinha com base em sua configuração de alinhamento e a posição na lista de painéis mantida pelo Gerenciador de encaixe.  
  
##  <a name="a-nameadjustclientareaa--cmdiframewndexadjustclientarea"></a><a name="adjustclientarea"></a>CMDIFrameWndEx::AdjustClientArea  
 Reduz a área do cliente para permitir uma borda.  
  
```  
virtual void AdjustClientArea();
```  
  
##  <a name="a-nameadjustdockinglayouta--cmdiframewndexadjustdockinglayout"></a><a name="adjustdockinglayout"></a>CMDIFrameWndEx::AdjustDockingLayout  
 Recalcula o layout de todos os painéis encaixados.  
  
```  
virtual void AdjustDockingLayout(HDWP hdwp=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hdwp`  
 Identifica a estrutura de posição da janela de múltiplos. Você pode obter esse valor chamando `BeginDeferWindowPos`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para recalcular o layout de todos os painéis encaixados na janela de quadro.  
  
##  <a name="a-namearemditabsa--cmdiframewndexaremditabs"></a><a name="aremditabs"></a>CMDIFrameWndEx::AreMDITabs  
 Determina se o recurso de guias MDI ou o recurso de grupos com guias MDI está habilitado.  
  
```  
BOOL AreMDITabs(int* pnMDITabsType=NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `pnMDITabsType`  
 Um ponteiro para uma variável de inteiro que indica quais recursos estão habilitados:  
  
-   0: todos os recursos estão desabilitados.  
  
-   1: guias MDI está habilitado.  
  
-   2: grupos MDI com guias está habilitada.  
  
### <a name="return-value"></a>Valor de retorno  
 `Returns TRUE`Se grupos com guias MDI ou guias MDI está habilitado.  
  
 `Returns FALSE`Se nenhum dos recursos acima está ativado.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para determinar se os guias MDI ou MDI com guias grupos é habilitada para a janela do quadro. Use [CMDIFrameWndEx::EnableMDITabs](#enablemditabs) para habilitar ou desabilitar o recurso de guias MDI.  
  
 Use [CMDIFrameWndEx::EnableMDITabbedGroups](#enablemditabbedgroups) para habilitar ou desabilitar o recurso de grupos com guias MDI.  
  
##  <a name="a-namecancovertcontrolbartomdichilda--cmdiframewndexcancovertcontrolbartomdichild"></a><a name="cancovertcontrolbartomdichild"></a>CMDIFrameWndEx::CanCovertControlBarToMDIChild  
 Chamado pela estrutura para determinar se a janela do quadro pode converter painéis de encaixe em documentos com guias  
  
```  
virtual BOOL CanCovertControlBarToMDIChild();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a janela do quadro pode converter painéis de encaixe em documentos com guias; caso contrário, retornará `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada e retornar `TRUE` para permitir a conversão dos painéis de encaixe para documentos com guias. Como alternativa, você pode definir [CMDIFrameWndEx::m_bCanCovertControlBarToMDIChild](#m_bcancovertcontrolbartomdichild) para `TRUE`.  
  
##  <a name="a-namecontrolbartotabbeddocumenta--cmdiframewndexcontrolbartotabbeddocument"></a><a name="controlbartotabbeddocument"></a>CMDIFrameWndEx::ControlBarToTabbedDocument  
 Converte o painel de encaixe especificado em um documento com guias.  
  
```  
virtual CMDIChildWndEx* ControlBarToTabbedDocument(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBar`  
 Um ponteiro para o painel de encaixe para converter.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a nova janela filho MDI que contém o painel de encaixe.  
  
### <a name="remarks"></a>Comentários  
 Esse método converte um painel de encaixe em um documento com guias. Quando você chamar esse método, o framework cria uma [CMDIChildWndEx classe](../../mfc/reference/cmdichildwndex-class.md) objeto, remove o painel de encaixe do Gerenciador de encaixe e adiciona o painel de encaixe para a nova janela filho MDI. A janela filho MDI redimensiona o painel de encaixe para cobrir toda a área cliente  
  
##  <a name="a-namecreatedocumentwindowa--cmdiframewndexcreatedocumentwindow"></a><a name="createdocumentwindow"></a>CMDIFrameWndEx::CreateDocumentWindow  
 Cria uma janela de documento filho.  
  
```  
virtual CMDIChildWndEx* CreateDocumentWindow(
    LPCTSTR lpcszDocName,  
    CObject* pObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpcszDocName`  
 Uma cadeia de caracteres de texto que contém um identificador de documento. Normalmente, é o caminho completo de um arquivo de documento.  
  
 [in] `pObj`  
 Um ponteiro para um objeto definido pelo usuário. Por exemplo, um desenvolvedor pode criar uma estrutura de dados específicos do aplicativo que descrevem o documento e informando como o documento deve ser inicializado na inicialização.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para `CMDIChildWndEx`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele carrega a lista de documentos salvos anteriormente no registro.  
  
 Substitua esse método para criar documentos quando estão sendo carregados do registro.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `CreateDocumentWindow` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 Neste exemplo, `g_strStartViewName` pode ser o nome de um "documento virtual" (por exemplo, "Página inicial") que, na verdade, não é carregado de um arquivo de disco. Portanto, precisamos processamento especial para lidar com esse caso.  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&13;](../../mfc/codesnippet/cpp/cmdiframewndex-class_2.cpp)]  
  
##  <a name="a-namecreatenewwindowa--cmdiframewndexcreatenewwindow"></a><a name="createnewwindow"></a>CMDIFrameWndEx::CreateNewWindow  
 Chamado pela estrutura para criar uma nova janela.  
  
```  
virtual CMDIChildWndEx* CreateNewWindow(
    LPCTSTR lpcszDocName,  
    CObject* pObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpcszDocName`  
 O nome do documento.  
  
 [in] `pObj`  
 Reservado para uso futuro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova janela.  
  
##  <a name="a-namedockpanea--cmdiframewndexdockpane"></a><a name="dockpane"></a>CMDIFrameWndEx::DockPane  
 Encaixa o painel especificado para a janela do quadro.  
  
```  
void DockPane(
    CBasePane* pBar,  
    UINT nDockBarID=0,  
    LPCRECT lpRect=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Ponteiro para o painel de encaixe.  
  
 [in] `nDockBarID`  
 Especifica que os lados da janela do quadro para encaixar.  
  
 [in] `lpRect`  
 Não usado.  
  
### <a name="remarks"></a>Comentários  
 Esse método encaixa especificado painel para um dos lados da janela do quadro que foi especificado quando [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking) e [CMDIFrameWndEx::EnableDocking](#enabledocking) foram chamados.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso do método `DockPane`. Este trecho de código é proveniente do [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&4;](../../mfc/codesnippet/cpp/cmdiframewndex-class_3.cpp)]  
  
##  <a name="a-namedockpaneleftofa--cmdiframewndexdockpaneleftof"></a><a name="dockpaneleftof"></a>CMDIFrameWndEx::DockPaneLeftOf  
 Encaixa um painel à esquerda do outro painel.  
  
```  
BOOL DockPaneLeftOf(
    CPane* pBar,  
    CPane* pLeftOf);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para o painel de encaixe.  
  
 [in] `pLeftOf`  
 Um ponteiro para o painel que serve como o local de encaixe. .  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a operação for bem-sucedida. Caso contrário, retornará `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para encaixar vários objetos de painel em uma ordem predefinida. Esse método encaixa o painel especificado por `pBar` à esquerda do painel especificado por `pLeftOf`.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como o `DockPaneLeftOf` método é usado o [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&5;](../../mfc/codesnippet/cpp/cmdiframewndex-class_4.cpp)]  
  
##  <a name="a-nameenableautohidepanesa--cmdiframewndexenableautohidepanes"></a><a name="enableautohidepanes"></a>CMDIFrameWndEx::EnableAutoHidePanes  
 Permite oculta automaticamente modo para painéis quando eles estão encaixados nos lados especificados da janela principal do quadro.  
  
```  
BOOL EnableAutoHidePanes(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwDockStyle`  
 Especifica os lados da janela do quadro principal será habilitado. Use um ou mais dos seguintes sinalizadores.  
  
- `CBRS_ALIGN_LEFT`  
  
- `CBRS_ALIGN_RIGHT`  
  
- `CBRS_ALIGN_TOP`  
  
- `CBRS_ALIGN_BOTTOM`  
  
### <a name="return-value"></a>Valor de retorno  
 Chame essa função para habilitar o modo de ocultar automaticamente para painéis quando eles estão encaixados nos lados especificados da janela principal do quadro.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como o `EnableAutoHidePanes` método é usado o [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&6;](../../mfc/codesnippet/cpp/cmdiframewndex-class_5.cpp)]  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenabledockinga--cmdiframewndexenabledocking"></a><a name="enabledocking"></a>CMDIFrameWndEx::EnableDocking  
 Habilita o encaixe dos painéis que pertencem à janela de quadro MDI.  
  
```  
BOOL EnableDocking(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwDockStyle`  
 Especifica o estilo de encaixe que você deseja aplicar.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para habilitar o encaixe de painéis que pertencem ao `CMDIFrameWndEx` objeto.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como o `EnableDocking` método é usado o [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#7;](../../mfc/codesnippet/cpp/cmdiframewndex-class_6.cpp)]  
  
##  <a name="a-nameenablefullscreenmainmenua--cmdiframewndexenablefullscreenmainmenu"></a><a name="enablefullscreenmainmenu"></a>CMDIFrameWndEx::EnableFullScreenMainMenu  
 Mostra ou oculta o menu principal no modo de tela inteira.  
  
```  
void EnableFullScreenMainMenu(BOOL bEnableMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnableMenu`  
 `TRUE`Para exibir o menu principal no modo de tela inteira, ou `FALSE` para ocultá-lo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenablefullscreenmodea--cmdiframewndexenablefullscreenmode"></a><a name="enablefullscreenmode"></a>CMDIFrameWndEx::EnableFullScreenMode  
 Habilita o modo de tela inteira para a janela do quadro.  
  
```  
void EnableFullScreenMode(UINT uiFullScreenCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiFullScreenCmd`  
 A ID de um comando que habilita ou desabilita o modo de tela inteira.  
  
### <a name="remarks"></a>Comentários  
 No modo de tela inteira, todas as barras de controle de encaixe, barras de ferramentas e menus são ocultas e o modo ativo é redimensionado para ocupar a tela inteira. Quando você habilita o modo de tela inteira, você deve especificar uma ID do comando que habilita ou desabilita. Você pode chamar `EnableFullScreenMode` partir do quadro principal `OnCreate` função. Quando uma janela de quadro está sendo alternada para o modo de tela cheia, o framework cria uma barra de ferramentas flutuante com um botão que tem a ID do comando especificado. Se você quiser manter o menu principal na tela, chame [CMDIFrameWndEx::EnableFullScreenMainMenu](#enablefullscreenmainmenu).  
  
##  <a name="a-nameenableloaddockstatea--cmdiframewndexenableloaddockstate"></a><a name="enableloaddockstate"></a>CMDIFrameWndEx::EnableLoadDockState  
 Habilita ou desabilita o carregamento do estado de encaixe.  
  
```  
void EnableLoadDockState(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar o carregamento do estado de encaixe, `FALSE` para desabilitar o carregamento do estado de encaixe.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenablemditabbedgroupsa--cmdiframewndexenablemditabbedgroups"></a><a name="enablemditabbedgroups"></a>CMDIFrameWndEx::EnableMDITabbedGroups  
 Habilita ou desabilita o recurso de grupos com guias MDI para a janela do quadro.  
  
```  
void EnableMDITabbedGroups(
    BOOL bEnable,  
    const CMDITabInfo& params);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Se `TRUE`, o recurso de grupos com guias MDI é habilitado; se `FALSE`, o recurso de grupos com guias MDI está desabilitado.  
  
 [in] `params`  
 Especifica os parâmetros que se aplica a estrutura para janelas filho que são criadas na área do cliente MDI.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para habilitar ou desabilitar o recurso de grupos com guias MDI. Esse recurso permite que aplicativos MDI exibir janelas filho, como janelas com guias que estão alinhadas vertical ou horizontalmente na área do cliente MDI. Grupos de janelas com guias são separados por separadores. O usuário pode redimensionar grupos com guias usando um divisor.  
  
-   O usuário pode:  
  
-   Arraste guias individuais entre grupos.  
  
-   Arraste guias individuais para a borda da janela para criar novos grupos.  
  
-   Mover guias ou criar novos grupos usando um menu de atalho.  
  
-   Seu aplicativo pode salvar o layout atual de janelas com guias e a lista de documentos abertos no momento.  
  
 Se você chamar esse método com `bEnable` definida como `FALSE`, `params` será ignorado.  
  
 Mesmo que grupos MDI com guias já estiver habilitado, você pode chamar esse método novamente para modificar as configurações de janelas filho. Chame o método com `bEnable` definida como `TRUE` e modificar os membros do `CMDITabInfo` objeto especificado pelo `params` parâmetro.  
  
 Para obter mais informações sobre como usar a MDI grupos com guias, consulte [grupos com guias MDI](../../mfc/mdi-tabbed-groups.md).  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `EnableMDITabbedGroups` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&8;](../../mfc/codesnippet/cpp/cmdiframewndex-class_7.cpp)]  
  
##  <a name="a-nameenablemditabsa--cmdiframewndexenablemditabs"></a><a name="enablemditabs"></a>CMDIFrameWndEx::EnableMDITabs  
 Habilita ou desabilita o recurso de guias MDI para a janela de quadro MDI. Quando habilitada, a janela de quadro exibe uma guia para cada janela de filho MDI.  
  
```  
void EnableMDITabs(
    BOOL bEnable=TRUE,  
    BOOL bIcons=TRUE,  
    CMFCTabCtrl::Location tabLocation=CMFCTabCtrl::LOCATION_BOTTOM,  
    BOOL bTabCloseButton=FALSE,  
    CMFCTabCtrl::Style style=CMFCTabCtrl::STYLE_3D_SCROLLED,  
    BOOL bTabCustomTooltips=FALSE,  
    BOOL bActiveTabCloseButton=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se o guias estão habilitadas.  
  
 `bIcons`  
 Especifica se ícones devem ser exibidos nas guias.  
  
 `tabLocation`  
 Especifica o local dos rótulos de guia.  
  
 `bTabCloseButton`  
 Especifica se deve exibir botões Fechar guia.  
  
 `style`  
 Especifica o estilo das guias. Use `STYLE_3D_SCROLLED` de guias normais ou `STYLE_3D_ONENOTE` para o Microsoft OneNote guias.  
  
 `bTabCustomTooltips`  
 Especifica se as dicas de ferramentas personalizadas estão habilitadas.  
  
 `bActiveTabCloseButton`  
 Se `TRUE`, um **fechar** botão será exibido na guia ativa em vez de no canto direito da área de guia.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para habilitar ou desabilitar o recurso de guias MDI para a janela de quadro MDI. Quando habilitada, todas as janelas filho são exibidas como guias.  
  
 Os rótulos de guia podem ser localizados na parte superior ou inferior do quadro, dependendo da configuração do parâmetro `tabLocation`. Você pode especificar um `CMFCTabCtrl::LOCATION_BOTTOM` (a configuração padrão) ou `CMFCTabCtrl::LOCATION_TOP`.  
  
 Se `bTabCustomTooltips` é `TRUE`, um `AFX_WM_ON_GET_TAB_TOOLTIP` mensagem será enviada para a janela do quadro principal. Seu código pode lidar com essa mensagem e fornecem a estrutura com dicas de ferramentas personalizadas para guias MDI.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `EnableMDITabs` é usado no [MDITabsDemo exemplo: aplicativo do MFC com guias MDI](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MDITabsDemo n º&3;](../../mfc/reference/codesnippet/cpp/cmdiframewndex-class_8.cpp)]  
  
##  <a name="a-nameenablemditabslastactiveactivationa--cmdiframewndexenablemditabslastactiveactivation"></a><a name="enablemditabslastactiveactivation"></a>CMDIFrameWndEx::EnableMDITabsLastActiveActivation  
 Especifica se a última guia active deve ser aberta quando o usuário fecha a guia atual.  
  
```  
void EnableMDITabsLastActiveActivation(BOOL bLastActiveTab=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bLastActiveTab`  
 Se `TRUE`, habilitar a ativação da última guia ativa. Se `FALSE`, desabilitar a ativação da última guia ativa.  
  
### <a name="remarks"></a>Comentários  
 Há duas maneiras de abrir uma guia quando a guia ativa é fechada:  
  
-   Ative a próxima guia.  
  
-   Ative a guia ativa anteriormente.  
  
 A implementação padrão usa a primeira forma.  
  
 Use `EnableMDITabsLastActiveActivation` para habilitar a segunda maneira de ativação de guia. Ele emula a maneira como o Windows abre janelas filho MDI.  
  
##  <a name="a-nameenablepanemenua--cmdiframewndexenablepanemenu"></a><a name="enablepanemenu"></a>CMDIFrameWndEx::EnablePaneMenu  
 Habilita ou desabilita a criação automática e o gerenciamento de menu do painel pop-up, que exibe uma lista dos painéis do aplicativo.  
  
```  
void EnablePaneMenu(
    BOOL bEnable,  
    UINT uiCustomizeCmd,  
    const CString& strCustomizeLabel,  
    UINT uiViewToolbarsMenuEntryID,  
    BOOL bContextMenuShowsToolbarsOnly=FALSE,  
    BOOL bViewMenuShowsToolbarsOnly=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Se `TRUE`, manipulação automática de menu do painel é habilitada; se `FALSE`, manipulação automática está desabilitada.  
  
 [in] `uiCustomizeCmd`  
 ID do comando de **personalizar** item de menu. Este item de menu geralmente é adicionado ao final da lista de painéis.  
  
 [in] `strCustomizeLabel`  
 O texto a ser exibido para o **personalizar** item de menu (para localização).  
  
 [in] `uiViewToolbarsMenuEntryID`  
 Especifica a ID de um item de menu da barra de ferramentas que abre o menu do painel. Geralmente isso é o **barras de ferramentas** submenu a **exibição** menu.  
  
 [in] `bContextMenuShowsToolbarsOnly`  
 Se `TRUE`, o menu do painel exibe apenas uma lista das barras de ferramentas. Se `FALSE`, o menu exibe uma lista de barras de ferramentas e barras de encaixe.  
  
 [in] `bViewMenuShowsToolbarsOnly`  
 Se `TRUE`, o menu do painel exibe apenas uma lista das barras de ferramentas. Se `FALSE`, o menu exibe uma lista de barras de ferramentas e barras de encaixe.  
  
### <a name="remarks"></a>Comentários  
 O menu do painel pop-up exibe a lista de painéis do aplicativo e permite que o usuário Mostrar ou ocultar painéis individuais.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `EnablePaneMenu` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&9;](../../mfc/codesnippet/cpp/cmdiframewndex-class_9.cpp)]  
  
##  <a name="a-nameenablewindowsdialoga--cmdiframewndexenablewindowsdialog"></a><a name="enablewindowsdialog"></a>CMDIFrameWndEx::EnableWindowsDialog  
 Insere um item de menu cuja ID de comando chama uma [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) caixa de diálogo.  
  
```  
void EnableWindowsDialog(
    UINT uiMenuId,  
    LPCTSTR lpszMenuText,  
    BOOL bShowAllways=FALSE,  
    BOOL bShowHelpButton=FALSE);

 
void EnableWindowsDialog(
    UINT uiMenuId,  
    UINT uiMenuTextResId,  
    BOOL bShowAllways=FALSE,  
    BOOL bShowHelpButton=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMenuId`  
 Especifica a ID de recurso de um menu.  
  
 [in] `lpszMenuText`  
 Especifica o texto do item.  
  
 [in] `bShowHelpButton`  
 Especifica se deve exibir uma **ajuda** botão na caixa de diálogo de gerenciamento do windows.  
  
 [in] `uiMenuTextResId`  
 O identificador do recurso de cadeia de caracteres que contém a cadeia de caracteres de texto do item.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para inserir um item de menu cujo comando chama uma caixa de diálogo de gerenciamento de janela do MDI filho ( [CMFCWindowsManagerDialog classe](../../mfc/reference/cmfcwindowsmanagerdialog-class.md)). O novo item é inserido no menu especificado por `uiMenuId`. Chamar `EnableWindowsDialog` ao processar o `WM_CREATE` mensagem.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `EnableWindowsDialog` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&10;](../../mfc/codesnippet/cpp/cmdiframewndex-class_10.cpp)]  
  
##  <a name="a-namegetactivepopupa--cmdiframewndexgetactivepopup"></a><a name="getactivepopup"></a>CMDIFrameWndEx::GetActivePopup  
 Retorna um ponteiro para o menu pop-up exibido atualmente.  
  
```  
CMFCPopupMenu* GetActivePopup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o menu pop-up ativa; `NULL` se nenhum menu pop-up estiver ativo.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para obter um ponteiro para o [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objeto que está sendo exibido.  
  
##  <a name="a-namegetdefaultresida--cmdiframewndexgetdefaultresid"></a><a name="getdefaultresid"></a>CMDIFrameWndEx::GetDefaultResId  
 Retorna a ID de recursos compartilhados da janela de quadro MDI.  
  
```  
UINT GetDefaultResId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de ID de recurso. 0 se a janela de quadro não possui nenhuma barra de menu.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna a ID de recurso que foi especificada quando a janela de quadro MDI foi carregada pelo [CFrameWnd::LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe).  
  
##  <a name="a-namegetmditabgroupsa--cmdiframewndexgetmditabgroups"></a><a name="getmditabgroups"></a>CMDIFrameWndEx::GetMDITabGroups  
 Retorna que uma lista de MDI com guias windows.  
  
```  
const CObList& GetMDITabGroups() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um [CObList classe](../../mfc/reference/coblist-class.md) objeto que contém uma lista de janelas com guias. Não armazenar ou modificar a lista.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para acessar a lista de janelas com guias. Ele pode ser útil se você deseja alterar ou consultar alguns parâmetros de janelas com guias individuais.  
  
##  <a name="a-namegetmditabsa--cmdiframewndexgetmditabs"></a><a name="getmditabs"></a>CMDIFrameWndEx::GetMDITabs  
 Retorna uma referência à janela com guias sublinhada.  
  
```  
CMFCTabCtrl& GetMDITabs();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência à janela com guias sublinhada.  
  
##  <a name="a-namegetmditabscontextmenualloweditemsa--cmdiframewndexgetmditabscontextmenualloweditems"></a><a name="getmditabscontextmenualloweditems"></a>CMDIFrameWndEx::GetMDITabsContextMenuAllowedItems  
 Retorna uma combinação de sinalizadores que determina quais operações são válidas quando o recurso de grupos de com guias MDI está habilitado.  
  
```  
DWORD GetMDITabsContextMenuAllowedItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação OR bit a bit dos sinalizadores a seguir:  
  
- `BCGP_MDI_CREATE_VERT_GROUP`-criar um grupo de tabulação vertical.  
  
- `BCGP_MDI_CREATE_HORZ_GROUP`-pode criar um grupo de guias horizontais.  
  
- `BCGP_MDI_CAN_MOVE_PREV`-pode mover uma guia ao grupo de guias anteriores.  
  
- `BCGP_MDI_CAN_MOVE_NEXT`-pode mover uma guia para o próximo grupo de guias.  
  
### <a name="remarks"></a>Comentários  
 Quando o recurso de grupos de com guias MDI é habilitado, você deve saber quais operações são permitidas nas guias de uma janela específica. Esse método analisa o layout atual de janelas com guias e retorna uma combinação de sinalizadores que podem ser usadas para criar, por exemplo, um menu de atalho.  
  
 Você pode criar um novo grupo de guias verticais quando todas as janelas com guias são alinhadas verticalmente, ou quando há apenas uma janela com guias.  
  
 Você pode criar um novo grupo de guias horizontais quando todas as janelas com guias são alinhadas horizontalmente, ou quando há apenas uma janela com guias.  
  
 Você pode mover uma guia para o grupo anterior somente se houver mais de uma guia em uma janela com guias.  
  
 Você pode mover uma guia para o próximo grupo somente se houver mais de uma guia em uma janela com guias.  
  
##  <a name="a-namegetmenubara--cmdiframewndexgetmenubar"></a><a name="getmenubar"></a>CMDIFrameWndEx::GetMenuBar  
 Retorna um ponteiro para um objeto de barra de menu anexado à janela de quadro.  
  
```  
const CMFCMenuBar* GetMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto de barra de menu.  
  
##  <a name="a-namegetpanea--cmdiframewndexgetpane"></a><a name="getpane"></a>CMDIFrameWndEx::GetPane  
 Retorna um ponteiro para o painel que possui a ID do controle especificado.  
  
```  
CBasePane* GetPane(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 A ID do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o painel com a ID do controle especificado, se ele existir. Caso contrário, `NULL`.  
  
##  <a name="a-namegetribbonbara--cmdiframewndexgetribbonbar"></a><a name="getribbonbar"></a>CMDIFrameWndEx::GetRibbonBar  
 Recupera o controle de barra de faixa de opções para o quadro.  
  
```  
CMFCRibbonBar* GetRibbonBar();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) do quadro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegettearoffbarsa--cmdiframewndexgettearoffbars"></a><a name="gettearoffbars"></a>CMDIFrameWndEx::GetTearOffBars  
 Retorna uma lista de menus destacável.  
  
```  
const CObList& GetTearOffBars() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um [CObList classe](../../mfc/reference/coblist-class.md) objeto que contém uma coleção de ponteiros para `CPane`-objetos que estão em um estado destacável derivados.  
  
### <a name="remarks"></a>Comentários  
 `CMDIFrameWndEx`mantém um conjunto de menus destacável. Use esse método para recuperar uma referência a essa lista.  
  
##  <a name="a-namegettoolbarbuttontooltiptexta--cmdiframewndexgettoolbarbuttontooltiptext"></a><a name="gettoolbarbuttontooltiptext"></a>CMDIFrameWndEx::GetToolbarButtonToolTipText  
 Chamado pela estrutura quando o aplicativo exibirá a dica de ferramenta para um botão da barra de ferramentas.  
  
```  
virtual BOOL GetToolbarButtonToolTipText(
    CMFCToolBarButton* pButton,  
    CString& strTTText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para um botão da barra de ferramentas.  
  
 [in] `strTTText`  
 O texto de dica de ferramenta a ser exibida para o botão.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a dica de ferramenta foi exibida. `FALSE`Caso contrário.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameinsertpanea--cmdiframewndexinsertpane"></a><a name="insertpane"></a>CMDIFrameWndEx::InsertPane  
 Registra o painel especificado com o Gerenciador de encaixe.  
  
```  
BOOL InsertPane(
    CBasePane* pControlBar,  
    CBasePane* pTarget,  
    BOOL bAfter=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 Um ponteiro para o painel a ser inserido.  
  
 [in] `pTarget`  
 Um ponteiro para o painel antes ou após o qual o painel.  
  
 [in] `bAfter`  
 Se `TRUE`, `pControlBar` inserida após `pTarget`. Se `FALSE`, `pControlBar` é inserida antes de `pTarget`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método foi registrado com êxito o painel, `FALSE` se o painel já foi registrado com o Gerenciador de encaixe.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para informar o Gerenciador do encaixe sobre um painel especificado por `pControlBar`. O Gerenciador de encaixe alinhará este painel de acordo com o alinhamento e a posição na lista interna do gerente de encaixe do painel.  
  
##  <a name="a-nameisfullscreena--cmdiframewndexisfullscreen"></a><a name="isfullscreen"></a>CMDIFrameWndEx::IsFullScreen  
 Determina se a janela do quadro está no modo de tela inteira.  
  
```  
BOOL IsFullScreen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela do quadro está em modo de tela inteira. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode definir o modo de tela cheia, chamando o [CMDIFrameWndEx::EnableFullScreenMode](#enablefullscreenmode) método.  
  
##  <a name="a-nameismditabbedgroupa--cmdiframewndexismditabbedgroup"></a><a name="ismditabbedgroup"></a>CMDIFrameWndEx::IsMDITabbedGroup  
 Especifica se o recurso grupos de MDI com guias está habilitado.  
  
```  
BOOL IsMDITabbedGroup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o recurso de grupos de com guias MDI estiver habilitado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Para determinar se o guias MDI normais ou o recurso grupos de com guias MDI está habilitado, use [CMDIFrameWndEx::AreMDITabs](#aremditabs).  
  
##  <a name="a-nameismemberofmditabgroupa--cmdiframewndexismemberofmditabgroup"></a><a name="ismemberofmditabgroup"></a>CMDIFrameWndEx::IsMemberOfMDITabGroup  
 Determina se a janela com guias especificada está na lista de janelas que estão em grupos com guias MDI.  
  
```  
BOOL IsMemberOfMDITabGroup(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Um ponteiro para a janela com guias.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela com guias especificada estiver na lista de janelas com guias que formam os grupos com guias MDI. Caso contrário, `FALSE`.  
  
##  <a name="a-nameismenubaravailablea--cmdiframewndexismenubaravailable"></a><a name="ismenubaravailable"></a>CMDIFrameWndEx::IsMenuBarAvailable  
 Determina se a janela do quadro tem uma barra de menus.  
  
```  
BOOL IsMenuBarAvailable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o ponteiro para o objeto de barra de menu não é `NULL`; caso contrário, `FALSE`.  
  
##  <a name="a-nameispointneardocksitea--cmdiframewndexispointneardocksite"></a><a name="ispointneardocksite"></a>CMDIFrameWndEx::IsPointNearDockSite  
 Determina se um ponto especificado é o local de encaixe próximo.  
  
```  
BOOL IsPointNearDockSite(
    CPoint point,  
    DWORD& dwBarAlignment,  
    BOOL& bOuterEdge) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto especificado em coordenadas de tela.  
  
 [in] `dwBarAlignment`  
 Especifica qual borda é o ponto de perto. Os valores possíveis são `CBRS_ALIGN_LEFT`, `CBRS_ALIGN_RIGHT`, `CBRS_ALIGN_TOP`, e`CBRS_ALIGN_BOTTOM`  
  
 [in] `bOuterEdge`  
 `TRUE`Se o ponto estiver próxima da borda externa do local do encaixe `FALSE` caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o ponto estiver perto do site de encaixe; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O ponto é o local de encaixe próximo quando ele está dentro da sensibilidade definida no Gerenciador de encaixe. O padrão de diferenciação é 15 pixels.  
  
##  <a name="a-nameisprintpreviewa--cmdiframewndexisprintpreview"></a><a name="isprintpreview"></a>CMDIFrameWndEx::IsPrintPreview  
 Determina se a janela do quadro está no modo de visualização de impressão.  
  
```  
BOOL IsPrintPreview();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela do quadro está no modo de visualização de impressão; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameloadframea--cmdiframewndexloadframe"></a><a name="loadframe"></a>CMDIFrameWndEx::LoadFrame  
 Cria uma janela de quadro de informações sobre o recurso.  
  
```  
virtual BOOL LoadFrame(
    UINT nIDResource,  
    DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,  
    CWnd* pParentWnd = NULL,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIDResource`  
 A ID de um recurso compartilhado associado à janela de quadro.  
  
 [in] `dwDefaultStyle`  
 O estilo da janela de quadro.  
  
 [in] `pParentWnd`  
 Um ponteiro para o pai do quadro.  
  
 [in] `pContext`  
 Um ponteiro para um [CCreateContext estrutura](../../mfc/reference/ccreatecontext-structure.md). Esse parâmetro pode ser `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido, caso contrário, `FALSE`.  
  
##  <a name="a-nameloadmdistatea--cmdiframewndexloadmdistate"></a><a name="loadmdistate"></a>CMDIFrameWndEx::LoadMDIState  
 Carrega o layout especificado MDI com guias grupos e a lista de documentos abertos anteriormente.  
  
```  
virtual BOOL LoadMDIState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Especifica o nome do perfil.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a carga for bem-sucedida; `FALSE` se a carga falhou ou que não há nenhum dado para carregar.  
  
### <a name="remarks"></a>Comentários  
 Para carregar ou salvar o estado de guias MDI e grupos e a lista de documentos abertos, faça o seguinte:  
  
-   Chamar [CMDIFrameWndEx::SaveMDIState](#savemdistate) quando o quadro principal está sendo fechado  
  
-   Chamar [CMDIFrameWndEx::LoadMDIState](#loadmdistate) quando o quadro principal está sendo criado. O local recomendado para essa chamada é antes que o quadro principal é exibido pela primeira vez. Adicionar `CWinAppEx::EnableLoadWindowPlacement` `(FALSE);` antes de `pMainFrame->LoadFrame (IDR_MAINFRAME);.` adicionar `CBCGPWorkspace::ReloadWindowPlacement` `(pMainFrame);` após a chamada para `LoadMDIState` para exibir o quadro principal na posição que foi armazenada no registro.  
  
-   Substituir `GetDocumentName` no `CMDIChildWndEx`-classe derivada se seu aplicativo exibe documentos que não são armazenados como arquivos. Cadeia de caracteres retornada será salva no registro como o identificador do documento. A implementação base de [CMDIChildWndEx::GetDocumentName](../../mfc/reference/cmdichildwndex-class.md#getdocumentname) retorna um valor obtido [CDocument::GetPathName](../../mfc/reference/cdocument-class.md#getpathname).  
  
-   Substituir [CMDIFrameWndEx::CreateDocumentWindow](#createdocumentwindow) criar documentos corretamente quando são carregados do registro. O primeiro parâmetro é a cadeia de caracteres que `GetDocumentName` retornado.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `LoadMDIState` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&11;](../../mfc/codesnippet/cpp/cmdiframewndex-class_11.cpp)]  
  
##  <a name="a-namemditabmovetonextgroupa--cmdiframewndexmditabmovetonextgroup"></a><a name="mditabmovetonextgroup"></a>CMDIFrameWndEx::MDITabMoveToNextGroup  
 Move a guia ativa da janela ativa no momento com guias para o grupo de guias anterior ou seguinte.  
  
```  
void MDITabMoveToNextGroup(BOOL bNext=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bNext`  
 Se `TRUE`, mova a guia para o próximo grupo de guias. Se `FALSE`, mova-o para o grupo de guias anterior.  
  
##  <a name="a-namemditabnewgroupa--cmdiframewndexmditabnewgroup"></a><a name="mditabnewgroup"></a>CMDIFrameWndEx::MDITabNewGroup  
 Cria um novo grupo com guias que tem uma única janela.  
  
```  
void MDITabNewGroup(BOOL bVert=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bVert`  
 Especifica o alinhamento de grupo novo. Se `TRUE`, o novo grupo é alinhado verticalmente. Se `FALSE`, o novo grupo é alinhado horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para criar um novo com guias de janela (novo grupo de guias) e adicione a primeira guia a ele.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `MDITabNewGroup` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#12;](../../mfc/codesnippet/cpp/cmdiframewndex-class_12.cpp)]  
  
##  <a name="a-namembcancovertcontrolbartomdichilda--cmdiframewndexmbcancovertcontrolbartomdichild"></a><a name="m_bcancovertcontrolbartomdichild"></a>CMDIFrameWndEx::m_bCanCovertControlBarToMDIChild  
 Especifica se os painéis de encaixe podem ser convertidos em janelas filho MDI.  
  
```  
BOOL m_bCanCovertControlBarToMDIChild;  
```  
  
### <a name="remarks"></a>Comentários  
 Indica se encaixe barras de controle podem ser convertidas em janelas filho MDI. Se o sinalizador for `TRUE`, a estrutura lida com a conversão automaticamente quando o usuário seleciona o **documento com guias** comando. O sinalizador é protegido e você deve habilitar explicitamente essa opção definindo `m_bCanCovertControlBarToMDIChild` em um construtor de uma `CMDIFrameWndEx`-classe derivada ou substituindo por `CanConvertControlBarToMDIChild`.  
  
 O valor padrão é `FALSE`.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `m_bCanCovertControlBarToMDIChild` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&13;](../../mfc/codesnippet/cpp/cmdiframewndex-class_2.cpp)]  
  
##  <a name="a-namembdisablesetredrawa--cmdiframewndexmbdisablesetredraw"></a><a name="m_bdisablesetredraw"></a>CMDIFrameWndEx::m_bDisableSetRedraw  
 Habilita ou desabilita a otimização de redesenho de janelas filho MDI.  
  
```  
AFX_IMPORT_DATA static BOOL m_bDisableSetRedraw;  
```  
  
### <a name="remarks"></a>Comentários  
 O valor padrão é `TRUE`.  
  
 Defina esse sinalizador como `FALSE` para otimizar o redesenho de filhos MDI. Nesse caso a estrutura chamará `SetRedraw (FALSE)` para o quadro principal quando o aplicativo está mudando a guia ativa.  
  
 Este sinalizador pode causar efeitos indesejados (como aplicativos de plano de fundo que se tornará visíveis). Portanto, recomendamos que você altere o padrão apenas se você experimentarão cintilações perceptível durante a ativação do guia MDI.  
  
##  <a name="a-namenegotiateborderspacea--cmdiframewndexnegotiateborderspace"></a><a name="negotiateborderspace"></a>CMDIFrameWndEx::NegotiateBorderSpace  
 Negocia espaço de borda em uma janela de quadro durante a ativação no local de OLE.  
  
```  
virtual BOOL NegotiateBorderSpace(
    UINT nBorderCmd,  
    LPRECT lpRectBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nBorderCmd`  
 Contém um dos seguintes valores da enumeração `CFrameWnd::BorderCmd`:  
  
- `borderGet` = 1  
  
- `borderRequest` = 2  
  
- `borderSet` = 3  
  
 [in, out] `lpRectBorder`  
 Ponteiro para uma [estrutura RECT](../../mfc/reference/rect-structure1.md) ou um [CRect classe](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as coordenadas da borda.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método é uma implementação de negociação de espaço de borda OLE.  
  
##  <a name="a-nameonclosedockingpanea--cmdiframewndexonclosedockingpane"></a><a name="onclosedockingpane"></a>CMDIFrameWndEx::OnCloseDockingPane  
 Chamado pela estrutura quando o usuário clica o **fechar** botão em um painel acoplável.  
  
```  
virtual BOOL OnCloseDockingPane(CDockablePane* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Ponteiro para o painel que está sendo fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel de encaixe pode ser fechado. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para manipular ocultar painéis de encaixe. Retornar `FALSE` se você quiser impedir que um painel de encaixe oculto.  
  
 A implementação padrão não faz nada e retorna `TRUE`.  
  
##  <a name="a-nameoncloseminiframea--cmdiframewndexoncloseminiframe"></a><a name="oncloseminiframe"></a>CMDIFrameWndEx::OnCloseMiniFrame  
 Chamado pela estrutura quando o usuário clica o **fechar** botão em uma janela de quadro mini flutuante.  
  
```  
virtual BOOL OnCloseMiniFrame(CPaneFrameWnd*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Ponteiro para a janela do quadro simplificado que está sendo fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela de quadro mini flutuante pode ser fechada. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para manipular ocultar janelas de quadro mini flutuantes. Retornar `FALSE` se você quiser impedir que uma janela de quadro mini flutuante oculto.  
  
 A implementação padrão não faz nada e retorna `TRUE`.  
  
##  <a name="a-nameonclosepopupmenua--cmdiframewndexonclosepopupmenu"></a><a name="onclosepopupmenu"></a>CMDIFrameWndEx::OnClosePopupMenu  
 Chamado pela estrutura quando processa um menu pop-up ativa um `WM_DESTROY` mensagem.  
  
```  
virtual void OnClosePopupMenu(CMFCPopupMenu* pMenuPopup);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuPopup`  
 Ponteiro para um menu pop-up.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se você quiser processar as notificações de [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objetos que pertencem à janela de quadro MDI quando processam esses objetos `WM_DESTROY` mensagens.  
  
##  <a name="a-nameoncmdmsga--cmdiframewndexoncmdmsg"></a><a name="oncmdmsg"></a>CMDIFrameWndEx::OnCmdMsg  
 Chamado pela estrutura para rotear e distribuir mensagens de comando e atualizar objetos de interface do usuário do comando.  
  
```  
virtual BOOL OnCmdMsg(
    UINT nID,  
    int nCode,  
    void* pExtra,  
    AFX_CMDHANDLERINFO* pHandlerInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 A ID do comando.  
  
 [in] `nCode`  
 Identifica o código de notificação de comando. Consulte [CCmdTarget::OnCmdMsg](../../mfc/reference/ccmdtarget-class.md#oncmdmsg) para obter mais informações sobre os valores para `nCode`.  
  
 [in] `pExtra`  
 Usadas de acordo com o valor de `nCode`. Consulte [CCmdTarget::OnCmdMsg](../../mfc/reference/ccmdtarget-class.md#oncmdmsg) para obter mais informações sobre `pExtra`.  
  
 [in, out] `pHandlerInfo`  
 Normalmente, esse parâmetro deve ser `NULL`. Se não `NULL`, `OnCmdMsg` preenche o `pTarget` e `pmf` membros a `pHandlerInfo` estrutura em vez de distribuir o comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem é lida; Caso contrário, 0.  
  
##  <a name="a-nameondrawmenuimagea--cmdiframewndexondrawmenuimage"></a><a name="ondrawmenuimage"></a>CMDIFrameWndEx::OnDrawMenuImage  
 Chamado pela estrutura quando a imagem associada a um item de menu é desenhada.  
  
```  
virtual BOOL OnDrawMenuImage(
    CDC* pDC,  
    const CMFCToolBarMenuButton* pMenuButton,  
    const CRect& rectImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo.  
  
 [in] `pMenuButton`  
 Ponteiro para o botão de menu.  
  
 [in] `rectImage`  
 Retângulo delimitador da imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método desenha a imagem. Retorna a implementação padrão `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substituir esse método se você desejar personalizar a renderização de imagem para os itens de menu que pertencem à barra de menus pertencente a `CMDIFrameWndEx`-objeto derivado. A implementação padrão não faz nada.  
  
##  <a name="a-nameondrawmenulogoa--cmdiframewndexondrawmenulogo"></a><a name="ondrawmenulogo"></a>CMDIFrameWndEx::OnDrawMenuLogo  
 Chamado pela estrutura quando um [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)processos um `WM_PAINT` mensagem.  
  
```  
virtual void OnDrawMenuLogo(
    CDC*, 
    CMFCPopupMenu*, 
    const CRect&);
```  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para exibir um logotipo no menu pop-up que pertence à barra de menus pertencente a `CMDIFrameWndEx`-objeto derivado. A implementação padrão não faz nada.  
  
##  <a name="a-nameonerasemdiclientbackgrounda--cmdiframewndexonerasemdiclientbackground"></a><a name="onerasemdiclientbackground"></a>CMDIFrameWndEx::OnEraseMDIClientBackground  
 Chamado pela estrutura quando o MDI processos de janela de quadro um `WM_ERASEBKGND` mensagem.  
  
```  
virtual BOOL OnEraseMDIClientBackground(CDC*);
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o aplicativo processa a mensagem e apaga o plano de fundo.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função de membro para processar o `WM_ERASEBKGND` de mensagem em uma `CMDIFrameWndEx`-classe derivada.  
  
##  <a name="a-nameonmenubuttontoolhittesta--cmdiframewndexonmenubuttontoolhittest"></a><a name="onmenubuttontoolhittest"></a>CMDIFrameWndEx::OnMenuButtonToolHitTest  
 Chamado pela estrutura quando um [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)objeto processos um `WM_NCHITTEST` mensagem.  
  
```  
virtual BOOL OnMenuButtonToolHitTest(
    CMFCToolBarButton* pButton,  
    TOOLINFO* pTI);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 O botão da barra de ferramentas.  
  
 [out] `pTI`  
 Ponteiro para uma [TOOLINFO](http://msdn.microsoft.com/library/windows/desktop/bb760256) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o aplicativo preenche o `pTI` parâmetro. Retorna a implementação padrão `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitui esse método para fornecer informações sobre itens de menu específicos a uma dica de ferramenta. A implementação padrão não faz nada.  
  
##  <a name="a-nameonmoveminiframea--cmdiframewndexonmoveminiframe"></a><a name="onmoveminiframe"></a>CMDIFrameWndEx::OnMoveMiniFrame  
 Chamado pela estrutura para mover uma janela de quadro simplificado.  
  
```  
virtual BOOL OnMoveMiniFrame(CWnd* pFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrame`  
 Um ponteiro para uma janela de quadro simplificado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido, caso contrário, `FALSE`.  
  
##  <a name="a-nameonsetpreviewmodea--cmdiframewndexonsetpreviewmode"></a><a name="onsetpreviewmode"></a>CMDIFrameWndEx::OnSetPreviewMode  
 Define o modo de visualização de impressão de janela de quadro principal do aplicativo.  
  
```  
virtual void OnSetPreviewMode(
    BOOL bPreview,  
    CPrintPreviewState* pState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bPreview`  
 Se `TRUE`, define o modo de visualização de impressão. Se `FALSE`, cancela o modo de visualização.  
  
 [in] `pState`  
 Um ponteiro para um `CPrintPreviewState` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Este método substitui [CFrameWnd::OnSetPreviewMode](../../mfc/reference/cframewnd-class.md#onsetpreviewmode).  
  
##  <a name="a-nameonshowcustomizepanea--cmdiframewndexonshowcustomizepane"></a><a name="onshowcustomizepane"></a>CMDIFrameWndEx::OnShowCustomizePane  
 Chamado pela estrutura quando um painel Personalizar rápida é ativado.  
  
```  
virtual BOOL OnShowCustomizePane(
    CMFCPopupMenu* pMenuPane,  
    UINT uiToolbarID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuPane`  
 Um ponteiro para o painel Personalizar rápida.  
  
 [in] `uiToolbarID`  
 ID de controle da barra de ferramentas para personalizar.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O painel Personalizar rápida é um menu que é aberto quando o usuário clica em **personalizar** na barra de ferramentas.  
  
 Substitua esse método em uma classe derivada para fazer alterações no painel Personalizar rápida.  
  
##  <a name="a-nameonshowmditabcontextmenua--cmdiframewndexonshowmditabcontextmenu"></a><a name="onshowmditabcontextmenu"></a>CMDIFrameWndEx::OnShowMDITabContextMenu  
 Chamado pela estrutura antes que um menu de atalho é exibido em uma das guias. Válido para grupos com guias MDI apenas.  
  
```  
virtual BOOL OnShowMDITabContextMenu(
    CPoint point,  
    DWORD dwAllowedItems,  
    BOOL bTabDrop);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O local do menu em coordenadas de tela.  
  
 [in] `dwAllowedItems`  
 Uma combinação OR bit a bit de sinalizadores que indica quais ações são permitidas para a guia atual:  
  
- `BCGP_MDI_CREATE_VERT_GROUP`-criar um grupo de tabulação vertical.  
  
- `BCGP_MDI_CREATE_HORZ_GROUP`-pode criar um grupo de guias horizontais.  
  
- `BCGP_MDI_CAN_MOVE_PREV`-pode mover uma guia ao grupo de guias anteriores.  
  
- `BCGP_MDI_CAN_MOVE_NEXT`-pode mover uma guia para o próximo grupo de guias.  
  
- `BCGP_MDI_CAN_BE_DOCKED`-alternar um documento com guias para o estado de ancoramento (relevante apenas documentos com guias).  
  
 [in] `bTabDrop`  
 `TRUE`Para exibir o menu como resultado de arrastar a guia para outro grupo com guias. `FALSE`Para exibir o menu como um menu de atalho na guia ativa no momento.  
  
### <a name="return-value"></a>Valor de retorno  
 Substitua esse método em um [CBCGPMDIFrameWnd](../../mfc/reference/cmdiframewndex-class.md)-classe derivada.  
  
### <a name="remarks"></a>Comentários  
 Se você não processar `OnShowMDITabContextMenu`, o menu de atalho não será exibido. Essa função é gerada pelo **MFC Application Wizard** quando você habilita o recurso grupos de MDI com guias.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `OnShowMDITabContextMenu` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#14;](../../mfc/codesnippet/cpp/cmdiframewndex-class_13.cpp)]  
  
##  <a name="a-nameonshowpanesa--cmdiframewndexonshowpanes"></a><a name="onshowpanes"></a>CMDIFrameWndEx::OnShowPanes  
 Chamado pela estrutura para mostrar ou ocultar painéis.  
  
```  
virtual BOOL OnShowPanes(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 `TRUE`Mostrar painéis, `FALSE` para ocultar painéis.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o estado dos painéis alterado como resultado de chamar esse método, `FALSE` se os painéis estiverem no estado especificado por `bShow`. Por exemplo, se os painéis ficam ocultos e `bShow` é `FALSE`, o valor de retorno é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão remove a barra de ferramentas da janela de quadro de nível superior.  
  
 Se [CDockingManager::m_bHideDockingBarsInContainerMode](../../mfc/reference/cdockingmanager-class.md#m_bhidedockingbarsincontainermode) é `TRUE` (o padrão), todos os painéis de encaixe ficará oculta.  
  
##  <a name="a-nameonshowpopupmenua--cmdiframewndexonshowpopupmenu"></a><a name="onshowpopupmenu"></a>CMDIFrameWndEx::OnShowPopupMenu  
 Chamado pela estrutura quando ele abre um menu pop-up.  
  
```  
virtual BOOL OnShowPopupMenu(CMFCPopupMenu*);
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o menu pop-up é exibida. Caso contrário, `FALSE`. Retorna a implementação padrão `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se você quiser implementar o processamento especial na ativação do menu pop-up. Por exemplo, se você quiser alterar itens de menu regular para botões de menu cor, configurar barras destacável e assim por diante.  
  
 A implementação padrão não faz nada.  
  
##  <a name="a-nameonsizemdiclienta--cmdiframewndexonsizemdiclient"></a><a name="onsizemdiclient"></a>CMDIFrameWndEx::OnSizeMDIClient  
 Chamado pela estrutura quando o tamanho da janela MDI do cliente está sendo alterado.  
  
```  
virtual void OnSizeMDIClient(
    const CRect& rectOld,  
    const CRect& rectNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectOld`  
 O tamanho atual da janela do cliente MDI.  
  
 [in] `rectNew`  
 O novo tamanho da janela do cliente MDI.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameontearoffmenua--cmdiframewndexontearoffmenu"></a><a name="ontearoffmenu"></a>CMDIFrameWndEx::OnTearOffMenu  
 Chamado pela estrutura quando um menu que tem uma barra destacável é ativado.  
  
```  
virtual BOOL OnTearOffMenu(
    CMFCPopupMenu* pMenuPopup,  
    CPane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuPopup`  
 Um ponteiro para o menu pop-up.  
  
 [in] `pBar`  
 Um ponteiro para a barra destacável.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`para permitir que o menu pop-up com a barra destacável fique ativar; Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função quando você deseja implementar uma configuração especial para a barra destacável. A implementação padrão não faz nada.  
  
##  <a name="a-nameonupdateframemenua--cmdiframewndexonupdateframemenu"></a><a name="onupdateframemenu"></a>CMDIFrameWndEx::OnUpdateFrameMenu  
 Chamado pela estrutura para atualizar o menu do quadro.  
  
```  
virtual void OnUpdateFrameMenu(HMENU hMenuAlt);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hMenuAlt`  
 Um identificador para um menu.  
  
##  <a name="a-namepanefrompointa--cmdiframewndexpanefrompoint"></a><a name="panefrompoint"></a>CMDIFrameWndEx::PaneFromPoint  
 Retorna o painel de encaixe que contém o ponto especificado.  
  
```  
CBasePane* PaneFromPoint(
    CPoint point,  
    int nSensitivity,  
    bool bExactBar,  
    CRuntimeClass* pRTCBarType) const;  
  
CBasePane* PaneFromPoint(
    CPoint point,  
    int nSensitivity,  
    DWORD& dwAlignment,  
    CRuntimeClass* pRTCBarType) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto (em coordenadas de tela).  
  
 [in] `nSensitivity`  
 O retângulo da janela de cada painel selecionado é aumentado em todas as direções por esse valor.  
  
 [in] `bExactBar`  
 Se `TRUE`, o `nSensitivity` parâmetro é ignorado.  
  
 [in] `pRTCBarType`  
 Se não `NULL`, o método itera apenas os painéis do tipo especificado.  
  
 [out] `dwAlignment`  
 Se um painel for encontrado, este parâmetro especificará qual lado do painel é próximo ao ponto especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um painel de encaixe, ou `NULL` se nenhum controle tiver o ponto especificado por `point`.  
  
### <a name="remarks"></a>Comentários  
 A chamada é redirecionada para o [CDockingManager classe](../../mfc/reference/cdockingmanager-class.md). Consulte [CDockingManager::ControlBarFromPoint](../../mfc/reference/cdockingmanager-class.md#panefrompoint) para obter mais informações.  
  
##  <a name="a-namerecalclayouta--cmdiframewndexrecalclayout"></a><a name="recalclayout"></a>CMDIFrameWndEx::RecalcLayout  
 Chamado pela estrutura para recalcular o layout da janela do quadro.  
  
```  
virtual void RecalcLayout(BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bNotify`  
 Determina se o item no local ativo para a janela do quadro recebe notificação de alteração de layout. Se `TRUE`, o item é notificado; caso contrário `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método substitui [CFrameWnd::RecalcLayout](../../mfc/reference/cframewnd-class.md#recalclayout).  
  
##  <a name="a-nameremovepanefromdockmanagera--cmdiframewndexremovepanefromdockmanager"></a><a name="removepanefromdockmanager"></a>CMDIFrameWndEx::RemovePaneFromDockManager  
 Cancela o registro de um painel e a remove do Gerenciador de encaixe.  
  
```  
void RemovePaneFromDockManager(
    CBasePane* pControlBar,  
    BOOL bDestroy,  
    BOOL bAdjustLayout,  
    BOOL bAutoHide,  
    CBasePane* pBarReplacement);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 Um ponteiro para um painel a ser removido.  
  
 [in] `bDestroy`  
 `TRUE`para destruir o painel removido. `FALSE`para não destruí-lo.  
  
 [in] `bAdjustLayout`  
 `TRUE`Para ajustar o layout de encaixe imediatamente. Se `FALSE`, o ajuste ocorrerá somente quando um evento de redesenho ocorre por outros motivos (o usuário redimensiona a janela, arrastar o quadro principal, etc.).  
  
 [in] `bAutoHide`  
 `TRUE`Para remover o painel da lista de painéis de ocultar automaticamente. `FALSE`Para remover o painel da lista de painéis regulares.  
  
 [in] `pBarReplacement`  
 Um ponteiro para um painel que substitui o painel removido.  
  
### <a name="remarks"></a>Comentários  
 Você deve registrar cada painel com o Gerenciador de encaixe para ajudar no layout do encaixe. Use [CMDIFrameWndEx::AddPane](#addpane) ou [CMDIFrameWndEx::InsertPane](#insertpane) para registrar os painéis.  
  
 Use este método quando um painel não faz parte do layout do encaixe da janela do quadro.  
  
##  <a name="a-namesavemdistatea--cmdiframewndexsavemdistate"></a><a name="savemdistate"></a>CMDIFrameWndEx::SaveMDIState  
 Salva o layout atual de MDI com guias grupos e a lista de documentos abertos anteriormente.  
  
```  
virtual BOOL SaveMDIState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Especifica o nome do perfil.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a gravação for bem-sucedida; `FALSE` se ocorreu falha ao salvar.  
  
### <a name="remarks"></a>Comentários  
 Para carregar ou salvar o estado de guias MDI e grupos e a lista de documentos abertos, faça o seguinte:  
  
-   Chamar `SaveMDIState` quando o quadro principal está sendo fechado  
  
-   Chamar [CMDIFrameWndEx::LoadMDIState](#loadmdistate) quando o quadro principal está sendo criado. O local recomendado para essa chamada é antes que o quadro principal é exibido pela primeira vez.  
  
-   Chame `CWinAppEx::EnableLoadWindowPlacement(FALSE);` antes de`pMainFrame->LoadFrame (IDR_MAINFRAME);`  
  
-   Chamar `CWinAppEx::ReloadWindowPlacement``(pMainFrame)` depois `LoadMDIState` para exibir o quadro principal na posição que foi armazenada no registro.  
  
-   Substituir `GetDocumentName` no `CMDIChildWndEx`-classe derivada se seu aplicativo exibe documentos que não são armazenados como arquivos. Cadeia de caracteres retornada será salva no registro como um identificador de documento. Para obter mais informações, consulte [CMDIChildWndEx::GetDocumentName](../../mfc/reference/cmdichildwndex-class.md#getdocumentname).  
  
-   Substituir [CMDIFrameWndEx::CreateDocumentWindow](#createdocumentwindow) criar documentos corretamente quando são carregados do registro. O parâmetro para `CreateDocumentWindow` é a cadeia de caracteres que `GetDocumentName` retornado anteriormente.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `SaveMDIState` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#15;](../../mfc/codesnippet/cpp/cmdiframewndex-class_14.cpp)]  
  
##  <a name="a-namesetprintpreviewframea--cmdiframewndexsetprintpreviewframe"></a><a name="setprintpreviewframe"></a>CMDIFrameWndEx::SetPrintPreviewFrame  
 Define a janela do quadro de visualização de impressão.  
  
```  
void SetPrintPreviewFrame(CFrameWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Ponteiro para uma janela de quadro de visualização de impressão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetuptoolbarmenua--cmdiframewndexsetuptoolbarmenu"></a><a name="setuptoolbarmenu"></a>CMDIFrameWndEx::SetupToolbarMenu  
 Modifica um objeto de barra de ferramentas, substituindo itens fictícios por itens definidos pelo usuário.  
  
```  
void SetupToolbarMenu(
    CMenu& menu,  
    const UINT uiViewUserToolbarCmdFirst,  
    const UINT uiViewUserToolbarCmdLast);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `menu`  
 Uma referência a um [classe CMenu](../../mfc/reference/cmenu-class.md) objeto a ser modificado.  
  
 [in] `uiViewUserToolbarCmdFirst`  
 Especifica o primeiro comando definidos pelo usuário.  
  
 [in] `uiViewUserToolbarCmdLast`  
 Especifica o último comando definidos pelo usuário.  
  
##  <a name="a-nameshowfullscreena--cmdiframewndexshowfullscreen"></a><a name="showfullscreen"></a>CMDIFrameWndEx::ShowFullScreen  
 Alterna o quadro principal do modo normal para o modo de tela inteira.  
  
```  
void ShowFullScreen();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameshowpanea--cmdiframewndexshowpane"></a><a name="showpane"></a>CMDIFrameWndEx::ShowPane  
 Mostra ou oculta o painel especificado.  
  
```  
void ShowPane(
    CBasePane* pBar,  
    BOOL bShow,  
    BOOL bDelay,  
    BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Ponteiro para o painel para ser mostrado ou ocultado.  
  
 [in] `bShow`  
 `TRUE`para mostrar o painel. `FALSE`Para ocultar o painel.  
  
 [in] `bDelay`  
 `TRUE`Para atrasar o recálculo do layout do encaixe. `FALSE`para recalcular o layout de encaixe imediatamente.  
  
 [in] `bActivate`  
 `TRUE`para mostrar o painel deve como ativa. `FALSE`para mostrar o painel como inativo.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para mostrar ou ocultar o painel. Não use `ShowWindow` para painéis de encaixe.  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `ShowPane` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&16;](../../mfc/codesnippet/cpp/cmdiframewndex-class_15.cpp)]  
  
##  <a name="a-nameshowwindowsdialoga--cmdiframewndexshowwindowsdialog"></a><a name="showwindowsdialog"></a>CMDIFrameWndEx::ShowWindowsDialog  
 Cria um [CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) caixa e o abre.  
  
```  
void ShowWindowsDialog();
```  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `ShowWindowsDialog` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo n º&18;](../../mfc/codesnippet/cpp/cmdiframewndex-class_16.cpp)]  
  
##  <a name="a-nametabbeddocumenttocontrolbara--cmdiframewndextabbeddocumenttocontrolbar"></a><a name="tabbeddocumenttocontrolbar"></a>CMDIFrameWndEx::TabbedDocumentToControlBar  
 Converte o documento com guias especificado em um painel de encaixe.  
  
```  
virtual BOOL TabbedDocumentToControlBar(CMDIChildWndEx* pMDIChildWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMDIChildWnd`  
 Um ponteiro para a janela filho MDI que contém um painel de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método teve êxito, `FALSE` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para converter um documento com guias em um painel de encaixe. O documento com guias deve ter sido criado usando [CMDIFrameWndEx::ControlBarToTabbedDocument](#controlbartotabbeddocument).  
  
### <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `TabbedDocumentToControlBar` é usado no [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[19 NVC_MFC_VisualStudioDemo](../../mfc/codesnippet/cpp/cmdiframewndex-class_17.cpp)]  
  
##  <a name="a-nameupdatecaptiona--cmdiframewndexupdatecaption"></a><a name="updatecaption"></a>CMDIFrameWndEx::UpdateCaption  
 Chamado pela estrutura para atualizar a legenda do quadro de janela.  
  
```  
void UpdateCaption();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameupdatemditabbedbarsiconsa--cmdiframewndexupdatemditabbedbarsicons"></a><a name="updatemditabbedbarsicons"></a>CMDIFrameWndEx::UpdateMDITabbedBarsIcons  
 Define o ícone para cada painel com guias MDI.  
  
```  
void UpdateMDITabbedBarsIcons();
```  
  
##  <a name="a-namewinhelpa--cmdiframewndexwinhelp"></a><a name="winhelp"></a>CMDIFrameWndEx::WinHelp  
 Chamado pela estrutura para iniciar a Ajuda de contexto ou aplicativo WinHelp.  
  
```  
virtual void WinHelp(
    DWORD dwData,  
    UINT nCmd = HELP_CONTEXT);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Especifica os dados conforme necessário para o tipo de ajuda especificado por `nCmd`.  
  
 [in] `nCmd`  
 Especifica o tipo de ajuda solicitado. Para obter uma lista de valores possíveis e como eles afetam o `dwData` parâmetro, consulte o [função WinHelp](http://msdn.microsoft.com/library/windows/desktop/bb762267) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Este método substitui [CWnd::WinHelp](../../mfc/reference/cwnd-class.md#winhelp).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [CMDIFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe CMDIChildWndEx](../../mfc/reference/cmdichildwndex-class.md)

