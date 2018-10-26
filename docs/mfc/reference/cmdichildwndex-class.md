---
title: Classe CMDIChildWndEx | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMDIChildWndEx
- AFXMDICHILDWNDEX/CMDIChildWndEx
- AFXMDICHILDWNDEX/CMDIChildWndEx::ActivateTopLevelFrame
- AFXMDICHILDWNDEX/CMDIChildWndEx::AddPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::AddTabbedPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::AdjustDockingLayout
- AFXMDICHILDWNDEX/CMDIChildWndEx::CanShowOnMDITabs
- AFXMDICHILDWNDEX/CMDIChildWndEx::CanShowOnTaskBarTabs
- AFXMDICHILDWNDEX/CMDIChildWndEx::CanShowOnWindowsList
- AFXMDICHILDWNDEX/CMDIChildWndEx::DockPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::DockPaneLeftOf
- AFXMDICHILDWNDEX/CMDIChildWndEx::EnableAutoHidePanes
- AFXMDICHILDWNDEX/CMDIChildWndEx::EnableDocking
- AFXMDICHILDWNDEX/CMDIChildWndEx::EnableTaskbarThumbnailClipRect
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetDockingManager
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetDocumentName
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetFrameIcon
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetFrameText
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetRelatedTabGroup
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetTabbedPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetTabProxyWnd
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetTaskbarPreviewWnd
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetTaskbarThumbnailClipRect
- AFXMDICHILDWNDEX/CMDIChildWndEx::GetToolbarButtonToolTipText
- AFXMDICHILDWNDEX/CMDIChildWndEx::InsertPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::InvalidateIconicBitmaps
- AFXMDICHILDWNDEX/CMDIChildWndEx::IsPointNearDockSite
- AFXMDICHILDWNDEX/CMDIChildWndEx::IsReadOnly
- AFXMDICHILDWNDEX/CMDIChildWndEx::IsRegisteredWithTaskbarTabs
- AFXMDICHILDWNDEX/CMDIChildWndEx::IsTabbedPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::IsTaskbarTabsSupportEnabled
- AFXMDICHILDWNDEX/CMDIChildWndEx::IsTaskbarThumbnailClipRectEnabled
- AFXMDICHILDWNDEX/CMDIChildWndEx::m_dwDefaultTaskbarTabPropertyFlags
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnGetIconicLivePreviewBitmap
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnGetIconicThumbnail
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnMoveMiniFrame
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnPressTaskbarThmbnailCloseButton
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnSetPreviewMode
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnTaskbarTabThumbnailActivate
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnTaskbarTabThumbnailStretch
- AFXMDICHILDWNDEX/CMDIChildWndEx::OnUpdateFrameTitle
- AFXMDICHILDWNDEX/CMDIChildWndEx::PaneFromPoint
- AFXMDICHILDWNDEX/CMDIChildWndEx::RecalcLayout
- AFXMDICHILDWNDEX/CMDIChildWndEx::RegisterTaskbarTab
- AFXMDICHILDWNDEX/CMDIChildWndEx::RemovePaneFromDockManager
- AFXMDICHILDWNDEX/CMDIChildWndEx::SetRelatedTabGroup
- AFXMDICHILDWNDEX/CMDIChildWndEx::SetTaskbarTabActive
- AFXMDICHILDWNDEX/CMDIChildWndEx::SetTaskbarTabOrder
- AFXMDICHILDWNDEX/CMDIChildWndEx::SetTaskbarTabProperties
- AFXMDICHILDWNDEX/CMDIChildWndEx::SetTaskbarThumbnailClipRect
- AFXMDICHILDWNDEX/CMDIChildWndEx::ShowPane
- AFXMDICHILDWNDEX/CMDIChildWndEx::UnregisterTaskbarTab
- AFXMDICHILDWNDEX/CMDIChildWndEx::UpdateTaskbarTabIcon
dev_langs:
- C++
helpviewer_keywords:
- CMDIChildWndEx [MFC], ActivateTopLevelFrame
- CMDIChildWndEx [MFC], AddPane
- CMDIChildWndEx [MFC], AddTabbedPane
- CMDIChildWndEx [MFC], AdjustDockingLayout
- CMDIChildWndEx [MFC], CanShowOnMDITabs
- CMDIChildWndEx [MFC], CanShowOnTaskBarTabs
- CMDIChildWndEx [MFC], CanShowOnWindowsList
- CMDIChildWndEx [MFC], DockPane
- CMDIChildWndEx [MFC], DockPaneLeftOf
- CMDIChildWndEx [MFC], EnableAutoHidePanes
- CMDIChildWndEx [MFC], EnableDocking
- CMDIChildWndEx [MFC], EnableTaskbarThumbnailClipRect
- CMDIChildWndEx [MFC], GetDockingManager
- CMDIChildWndEx [MFC], GetDocumentName
- CMDIChildWndEx [MFC], GetFrameIcon
- CMDIChildWndEx [MFC], GetFrameText
- CMDIChildWndEx [MFC], GetPane
- CMDIChildWndEx [MFC], GetRelatedTabGroup
- CMDIChildWndEx [MFC], GetTabbedPane
- CMDIChildWndEx [MFC], GetTabProxyWnd
- CMDIChildWndEx [MFC], GetTaskbarPreviewWnd
- CMDIChildWndEx [MFC], GetTaskbarThumbnailClipRect
- CMDIChildWndEx [MFC], GetToolbarButtonToolTipText
- CMDIChildWndEx [MFC], InsertPane
- CMDIChildWndEx [MFC], InvalidateIconicBitmaps
- CMDIChildWndEx [MFC], IsPointNearDockSite
- CMDIChildWndEx [MFC], IsReadOnly
- CMDIChildWndEx [MFC], IsRegisteredWithTaskbarTabs
- CMDIChildWndEx [MFC], IsTabbedPane
- CMDIChildWndEx [MFC], IsTaskbarTabsSupportEnabled
- CMDIChildWndEx [MFC], IsTaskbarThumbnailClipRectEnabled
- CMDIChildWndEx [MFC], m_dwDefaultTaskbarTabPropertyFlags
- CMDIChildWndEx [MFC], OnGetIconicLivePreviewBitmap
- CMDIChildWndEx [MFC], OnGetIconicThumbnail
- CMDIChildWndEx [MFC], OnMoveMiniFrame
- CMDIChildWndEx [MFC], OnPressTaskbarThmbnailCloseButton
- CMDIChildWndEx [MFC], OnSetPreviewMode
- CMDIChildWndEx [MFC], OnTaskbarTabThumbnailActivate
- CMDIChildWndEx [MFC], OnTaskbarTabThumbnailMouseActivate
- CMDIChildWndEx [MFC], OnTaskbarTabThumbnailStretch
- CMDIChildWndEx [MFC], OnUpdateFrameTitle
- CMDIChildWndEx [MFC], PaneFromPoint
- CMDIChildWndEx [MFC], RecalcLayout
- CMDIChildWndEx [MFC], RegisterTaskbarTab
- CMDIChildWndEx [MFC], RemovePaneFromDockManager
- CMDIChildWndEx [MFC], SetRelatedTabGroup
- CMDIChildWndEx [MFC], SetTaskbarTabActive
- CMDIChildWndEx [MFC], SetTaskbarTabOrder
- CMDIChildWndEx [MFC], SetTaskbarTabProperties
- CMDIChildWndEx [MFC], SetTaskbarThumbnailClipRect
- CMDIChildWndEx [MFC], ShowPane
- CMDIChildWndEx [MFC], UnregisterTaskbarTab
- CMDIChildWndEx [MFC], UpdateTaskbarTabIcon
ms.assetid: d39fec06-0bd6-4271-917d-35aae3b24d8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 64e8b62f79a6294810fc30b1796958c6ca4a153a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50073858"
---
# <a name="cmdichildwndex-class"></a>Classe CMDIChildWndEx

O `CMDIChildWndEx` classe fornece a funcionalidade de um Windows vários janela filho da MDI (interface MDI) documento. Ela estende a funcionalidade do [classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md). A estrutura exige essa classe quando um aplicativo MDI usa determinadas classes do MFC.

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMDIChildWndEx : public CMDIChildWnd
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIChildWndEx::ActivateTopLevelFrame](#activatetoplevelframe)|Chamado internamente pela estrutura para ativar o quadro de nível superior quando o aplicativo deve ser ativado de uma guia na barra de tarefas.|
|`CMDIChildWndEx::AddDockSite`|Esse método não é usado ou implementado.|
|[CMDIChildWndEx::AddPane](#addpane)|Adiciona um painel.|
|[CMDIChildWndEx::AddTabbedPane](#addtabbedpane)|Adiciona um painel com guias.|
|[CMDIChildWndEx::AdjustDockingLayout](#adjustdockinglayout)|Ajusta o layout de encaixe.|
|[CMDIChildWndEx::CanShowOnMDITabs](#canshowonmditabs)||
|[CMDIChildWndEx::CanShowOnTaskBarTabs](#canshowontaskbartabs)|Informa a estrutura se esse filho MDI pode ser exibido nas guias de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::CanShowOnWindowsList](#canshowonwindowslist)|Retorna VERDADEIRO se o nome da janela MDI filho pode ser exibido na [classe CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) caixa de diálogo. Caso contrário, retornará FALSE.|
|`CMDIChildWndEx::CreateObject`|Chamado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMDIChildWndEx::DockPane](#dockpane)|Encaixa um painel.|
|[CMDIChildWndEx::DockPaneLeftOf](#dockpaneleftof)|Encaixa um painel à esquerda de outro painel.|
|[CMDIChildWndEx::EnableAutoHidePanes](#enableautohidepanes)|Permite oculta automaticamente modo para painéis quando eles são encaixados nas laterais da janela especificadas.|
|[CMDIChildWndEx::EnableDocking](#enabledocking)|Habilita de encaixe da janela filho para o quadro principal.|
|[CMDIChildWndEx::EnableTaskbarThumbnailClipRect](#enabletaskbarthumbnailcliprect)|Habilita ou desabilita a seleção automática de uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas.|
|[CMDIChildWndEx::GetDockingManager](#getdockingmanager)||
|[CMDIChildWndEx::GetDocumentName](#getdocumentname)|Retorna o nome do documento que é exibido na janela filho MDI.|
|[CMDIChildWndEx::GetFrameIcon](#getframeicon)|Chamado pelo framework para recuperar o ícone da janela filho MDI.|
|[CMDIChildWndEx::GetFrameText](#getframetext)|Chamado pelo framework para recuperar o texto para a janela filho MDI.|
|[CMDIChildWndEx::GetPane](#getpane)|Localiza um painel pela ID do controle especificado.|
|[CMDIChildWndEx::GetRelatedTabGroup](#getrelatedtabgroup)||
|[CMDIChildWndEx::GetTabbedPane](#gettabbedpane)|Retorna um ponteiro para um painel de encaixe incorporado que foi convertido em um documento com guias.|
|[CMDIChildWndEx::GetTabProxyWnd](#gettabproxywnd)|Retorna a janela de proxy na realidade registrada com guias de barra de tarefas do Windows 7 da guia.|
|[CMDIChildWndEx::GetTaskbarPreviewWnd](#gettaskbarpreviewwnd)|Chamado pelo framework quando ele precisa obter uma janela filho (normalmente, uma janela do modo de exibição ou separador) a ser exibida na miniatura de guia de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::GetTaskbarThumbnailClipRect](#gettaskbarthumbnailcliprect)|Chamado pelo framework quando ele precisa selecionar uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas.|
|`CMDIChildWndEx::GetThisClass`|Chamado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMDIChildWndEx::GetToolbarButtonToolTipText](#gettoolbarbuttontooltiptext)|Chamado pelo framework para recuperar uma dica de ferramenta para um botão de barra de ferramentas.|
|[CMDIChildWndEx::InsertPane](#insertpane)|Registra o painel especificado com o Gerenciador de encaixe.|
|[CMDIChildWndEx::InvalidateIconicBitmaps](#invalidateiconicbitmaps)|Invalida a representação de bitmap icônico do filho MDI.|
|[CMDIChildWndEx::IsPointNearDockSite](#ispointneardocksite)|Determina se um ponto especificado está perto o local de encaixe.|
|[CMDIChildWndEx::IsReadOnly](#isreadonly)|Retornará TRUE se o documento que é exibido na janela filho é somente leitura. Caso contrário, retornará FALSE.|
|[CMDIChildWndEx::IsRegisteredWithTaskbarTabs](#isregisteredwithtaskbartabs)|Retornará TRUE se o filho MDI foi registrado com êxito com guias de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::IsTabbedPane](#istabbedpane)|Retornará TRUE se a janela filho MDI contém um painel de encaixe. Caso contrário, retornará FALSE.|
|[CMDIChildWndEx::IsTaskbarTabsSupportEnabled](#istaskbartabssupportenabled)|Informa se o filho MDI pode aparecer nas guias de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::IsTaskbarThumbnailClipRectEnabled](#istaskbarthumbnailcliprectenabled)|Informa se a seleção automática de uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas está habilitada ou desabilitada.|
|[CMDIChildWndEx::m_dwDefaultTaskbarTabPropertyFlags](#m_dwdefaulttaskbartabpropertyflags)|Uma combinação de sinalizadores, que é passada pelo framework para o método SetTaskbarTabProperties, quando uma guia (filho MDI) está sendo registrada com guias de barra de tarefas do Windows 7. A combinação de padrão é STPF_USEAPPTHUMBNAILWHENACTIVE &#124; STPF_USEAPPPEEKWHENACTIVE.|
|[CMDIChildWndEx::OnGetIconicLivePreviewBitmap](#ongeticoniclivepreviewbitmap)|Chamado pelo framework quando ele precisa obter um bitmap para a visualização dinâmica do filho MDI.|
|[CMDIChildWndEx::OnGetIconicThumbnail](#ongeticonicthumbnail)|Chamado pelo framework quando ele precisa obter um bitmap para icônico miniatura do filho MDI.|
|[CMDIChildWndEx::OnMoveMiniFrame](#onmoveminiframe)|Chamado pelo framework para mover uma janela com minimoldura.|
|[CMDIChildWndEx::OnPressTaskbarThmbnailCloseButton](#onpresstaskbarthmbnailclosebutton)|Chamado pelo framework quando o usuário pressiona o botão Fechar na miniatura de guia na barra de tarefas...|
|[CMDIChildWndEx::OnSetPreviewMode](#onsetpreviewmode)|Chamado pelo framework para entrar ou sair do modo de visualização de impressão.|
|[CMDIChildWndEx::OnTaskbarTabThumbnailActivate](#ontaskbartabthumbnailactivate)|Chamado pelo framework quando a miniatura de guia na barra de tarefas deve processar a mensagem WM_ACTIVATE.|
|[CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate](#ontaskbartabthumbnailmouseactivate)|Chamado pelo framework quando a miniatura de guia na barra de tarefas deve processar a mensagem WM_MOUSEACTIVATE.|
|[CMDIChildWndEx::OnTaskbarTabThumbnailStretch](#ontaskbartabthumbnailstretch)|Chamado pelo framework quando ele precisa ampliar um bitmap para Windows 7 na barra de tarefas guia Visualização de miniatura do filho MDI.|
|[CMDIChildWndEx::OnUpdateFrameTitle](#onupdateframetitle)|Chamado pelo framework para atualizar o título do quadro. (Substitui `CMDIChildWnd::OnUpdateFrameTitle`.)|
|[CMDIChildWndEx::PaneFromPoint](#panefrompoint)|Retorna o painel que contém o ponto especificado.|
|`CMDIChildWndEx::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMDIChildWndEx::RecalcLayout](#recalclayout)|Recalcula o layout da janela.|
|[CMDIChildWndEx::RegisterTaskbarTab](#registertaskbartab)|Registra o filho MDI com guias de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::RemovePaneFromDockManager](#removepanefromdockmanager)|Remove um painel do Gerenciador de encaixe.|
|[CMDIChildWndEx::SetRelatedTabGroup](#setrelatedtabgroup)||
|[CMDIChildWndEx::SetTaskbarTabActive](#settaskbartabactive)|Ativa a guia de barra de tarefas correspondente do Windows 7.|
|[CMDIChildWndEx::SetTaskbarTabOrder](#settaskbartaborder)|Insere o filho MDI antes da janela especificada nas guias de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::SetTaskbarTabProperties](#settaskbartabproperties)|Define propriedades para uma guia na barra de tarefas do Windows 7.|
|[CMDIChildWndEx::SetTaskbarThumbnailClipRect](#settaskbarthumbnailcliprect)|Chamado internamente pela estrutura para definir o retângulo de recorte para selecionar uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas.|
|[CMDIChildWndEx::ShowPane](#showpane)||
|[CMDIChildWndEx::UnregisterTaskbarTab](#unregistertaskbartab)|Remove o filho MDI de guias de barra de tarefas do Windows 7.|
|[CMDIChildWndEx::UpdateTaskbarTabIcon](#updatetaskbartabicon)|Atualiza o ícone de guia de barra de tarefas do Windows 7.|

## <a name="remarks"></a>Comentários

Para tirar proveito dos recursos estendidos de encaixe em aplicativos MDI, derive a classe de janela filho MDI do seu aplicativo da `CMDIChildWndEx` em vez de [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir deriva uma classe de `CMDIChildWndEx`. Este trecho de código é proveniente de [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#3](../../mfc/codesnippet/cpp/cmdichildwndex-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)

[CMDIChildWndEx](../../mfc/reference/cmdichildwndex-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxMDIChildWndEx.h

##  <a name="addpane"></a>  CMDIChildWndEx::AddPane

Adiciona um painel.

```
BOOL AddPane(
    CBasePane* pControlBar,
    BOOL bTail = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pControlBar*<br/>
[in] Um ponteiro para o painel.

*bTail*<br/>
[in] TRUE para adicionar o painel ao final da lista de painéis para o Gerenciador de encaixe; Caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

TRUE se o painel foi registrado com êxito com o Gerenciador do encaixe. Caso contrário, FALSE.

##  <a name="addtabbedpane"></a>  CMDIChildWndEx::AddTabbedPane

Adiciona um painel com guias.

```
void AddTabbedPane(CDockablePane* pControlBar);
```

### <a name="parameters"></a>Parâmetros

*pControlBar*<br/>
[in] Um ponteiro para o painel.

##  <a name="adjustdockinglayout"></a>  CMDIChildWndEx::AdjustDockingLayout

Ajusta o layout de encaixe.

```
virtual void AdjustDockingLayout(HDWP hdwp = NULL);
```

### <a name="parameters"></a>Parâmetros

*hdwp*<br/>
[in] Identificador para uma estrutura de posição da janela adiada.

##  <a name="canshowonmditabs"></a>  CMDIChildWndEx::CanShowOnMDITabs

```
virtual BOOL CanShowOnMDITabs();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="canshowonwindowslist"></a>  CMDIChildWndEx::CanShowOnWindowsList

Especifica se o nome da janela MDI filho pode ser exibido na [classe CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md) caixa de diálogo.

```
virtual BOOL CanShowOnWindowsList();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a janela pode ser exibida na **Windows** caixa de diálogo; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada e retornar FALSE se a janela não deve ser exibida na **Windows** caixa de diálogo. Essa função é chamada de `CMFCWindowsManagerDialog`.

##  <a name="dockpane"></a>  CMDIChildWndEx::DockPane

Encaixa um painel.

```
void DockPane(
    CBasePane* pBar,
    UINT nDockBarID = 0,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
[in] Um ponteiro para o painel.

*nDockBarID*<br/>
[in] A ID do painel.

*lpRect*<br/>
[in] Um ponteiro para um retângulo.

### <a name="remarks"></a>Comentários

O *lpRect* parâmetro não for usado.

##  <a name="dockpaneleftof"></a>  CMDIChildWndEx::DockPaneLeftOf

Encaixa um painel à esquerda de outro painel.

```
BOOL DockPaneLeftOf(
    CPane* pBar,
    CPane* pLeftOf);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Um ponteiro para o painel que deve ser encaixado.

*pLeftOf*<br/>
Um ponteiro para o painel que serve como o ponto de referência.

### <a name="return-value"></a>Valor de retorno

True se for bem-sucedido, retornará FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Esse método usa o painel especificado por *pBar* e encaixa-lo no lado esquerdo do painel especificado por *pLeftOf*.

Chame esse método quando você deseja encaixar vários painéis em ordem predefinida.

##  <a name="enableautohidepanes"></a>  CMDIChildWndEx::EnableAutoHidePanes

Permite oculta automaticamente modo para painéis quando eles são encaixados nas laterais da janela especificadas.

```
BOOL EnableAutoHidePanes(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
[in] Especifica os lados da janela do quadro principal que está habilitado. Use um ou mais dos seguintes sinalizadores.

- CBRS_ALIGN_LEFT

- CBRS_ALIGN_RIGHT

- CBRS_ALIGN_TOP

- CBRS_ALIGN_BOTTOM

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

##  <a name="enabledocking"></a>  CMDIChildWndEx::EnableDocking

Habilita de encaixe da janela filho para o quadro principal.

```
BOOL EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
[in] Especifica o alinhamento de encaixe para habilitar.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame esse método para permitir o alinhamento de encaixe para o quadro principal. Você pode passar uma combinação de sinalizadores CBRS_ALIGN_ (para obter mais informações, consulte [CControlBar::EnableDocking](../../mfc/reference/ccontrolbar-class.md#enabledocking)).

##  <a name="getdockingmanager"></a>  CMDIChildWndEx::GetDockingManager

```
CDockingManager* GetDockingManager();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getdocumentname"></a>  CMDIChildWndEx::GetDocumentName

Retorna o nome do documento que é exibido na janela filho MDI.

```
virtual LPCTSTR GetDocumentName(CObject** pObj);
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma cadeia de caracteres que contém o nome de um documento.

### <a name="remarks"></a>Comentários

Um documento é o que exibe a janela filho MDI. Em geral, a janela exibe dados que são carregados de ou salvos em um arquivo. Portanto, o nome do documento é o nome do arquivo. A implementação padrão de `GetDocumentName` retorna uma cadeia de caracteres obtida do `CDocument::GetPathName`.

Se a janela exibe um documento que não é carregado de um arquivo, substitua este método em uma classe derivada e retornar um identificador exclusivo do documento.

`GetDocumentName` é chamado pelo framework quando ele salva o estado de todos os documentos abertos. A cadeia de caracteres retornada é gravada no registro.

Quando o framework está restaurando o estado mais tarde, o nome do documento é lido do registro e passado para [CMDIFrameWndEx::CreateDocumentWindow](../../mfc/reference/cmdiframewndex-class.md#createdocumentwindow). Substitua este método em um [CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)-classe derivada e criar ou abrir um documento que tem esse nome e ler o arquivo que tem esse nome. Se o documento não é baseado em um arquivo, crie o documento com base no identificador de documento em si. Você deve fazer as ações descritas acima somente se você pretende salvar e restaurar os documentos.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso do método `GetDocumentName`. Este trecho de código é proveniente de [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#17](../../mfc/codesnippet/cpp/cmdichildwndex-class_2.cpp)]

##  <a name="getframeicon"></a>  CMDIChildWndEx::GetFrameIcon

Chamado pelo framework para recuperar o ícone da janela filho MDI.

```
virtual HICON GetFrameIcon() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o ícone de janela.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo framework para determinar qual ícone deve ser exibido na guia MDI que contém a janela do quadro MDI filho.

Por padrão, esse método retorna o ícone de janela. Substituir `GetFrameIcon` em um `CMDIChildWndEx`-derivado da classe para personalizar esse comportamento.

##  <a name="getframetext"></a>  CMDIChildWndEx::GetFrameText

Chamado pelo framework para recuperar o texto para a janela filho MDI.

```
virtual CString GetFrameText() const;
```

### <a name="return-value"></a>Valor de retorno

Uma cadeia de caracteres que contém o texto da janela de quadro.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo framework para determinar o texto a ser exibido na guia MDI que contém a janela do quadro MDI filho.

Por padrão, esse método retorna o texto da janela. Substituir `GetFrameText` em um `CMDIChildWndEx`-derivado da classe para personalizar esse comportamento.

##  <a name="getpane"></a>  CMDIChildWndEx::GetPane

Localiza um painel pela ID do controle especificado.

```
CBasePane* GetPane(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[in] A ID do painel de controle para localizar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o painel, se encontrado, caso contrário, nulo.

##  <a name="getrelatedtabgroup"></a>  CMDIChildWndEx::GetRelatedTabGroup

```
CMFCTabCtrl* GetRelatedTabGroup();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="gettabbedpane"></a>  CMDIChildWndEx::GetTabbedPane

Retorna um ponteiro para um painel de encaixe que faz parte de um grupo de MDI com guias de documentos.

```
CDockablePane* GetTabbedPane() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um painel de encaixe que faz parte de um grupo de MDI com guias de documentos.

##  <a name="gettoolbarbuttontooltiptext"></a>  CMDIChildWndEx::GetToolbarButtonToolTipText

Chamado pelo framework para recuperar uma dica de ferramenta para um botão de barra de ferramentas.

```
virtual BOOL GetToolbarButtonToolTipText(
    CMFCToolBarButton*,
    CString&);
```

### <a name="return-value"></a>Valor de retorno

TRUE se a dica de ferramenta foi exibida. A implementação padrão retorna falso.

### <a name="remarks"></a>Comentários

Substitua este método se você quiser exibir dicas de ferramenta personalizada para botões da barra de ferramentas.

##  <a name="insertpane"></a>  CMDIChildWndEx::InsertPane

Registra o painel especificado com o Gerenciador de encaixe.

```
BOOL InsertPane(
    CBasePane* pControlBar,
    CBasePane* pTarget,
    BOOL bAfter = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pControlBar*<br/>
[in] Um ponteiro para o painel a ser inserido.

*pTarget*<br/>
[in] Um ponteiro para o painel adjacente.

*bDepois*<br/>
[in] Se for TRUE, *pControlBar* é inserido após *pTarget*. Se for FALSE, *pControlBar* é inserido antes *pTarget*.

### <a name="return-value"></a>Valor de retorno

TRUE se o método tiver êxito, FALSE caso contrário.

##  <a name="ispointneardocksite"></a>  CMDIChildWndEx::IsPointNearDockSite

Determina se um ponto especificado está perto o local de encaixe.

```
BOOL IsPointNearDockSite(
    CPoint point,
    DWORD& dwBarAlignment,
    BOOL& bOuterEdge) const;
```

### <a name="parameters"></a>Parâmetros

*ponto*<br/>
[in] O ponto especificado.

*dwBarAlignment*<br/>
[in] Especifica que o ponto está próximo de borda. Os valores possíveis são CBRS_ALIGN_LEFT, CBRS_ALIGN_RIGHT, CBRS_ALIGN_TOP e CBRS_ALIGN_BOTTOM

*bOuterEdge*<br/>
[in] TRUE se o ponto está próximo a borda externa do local de encaixe; FALSE caso contrário.

### <a name="return-value"></a>Valor de retorno

TRUE se o ponto é quase o local de encaixe; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O ponto é quase o local de encaixe quando ele estiver dentro a sensibilidade definida no Gerenciador de encaixe. A sensibilidade de padrão é 15 pixels.

##  <a name="isreadonly"></a>  CMDIChildWndEx::IsReadOnly

Especifica se o documento que é exibido na janela filho é somente leitura.

```
virtual BOOL IsReadOnly();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o documento é somente leitura; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função é usada para evitar salvar documentos como somente leitura.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra substituindo o `IsReadOnly` método. Este trecho de código é proveniente de [VisualStudioDemo exemplo: aplicativo MFC do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#2](../../mfc/codesnippet/cpp/cmdichildwndex-class_3.cpp)]

##  <a name="istabbedpane"></a>  CMDIChildWndEx::IsTabbedPane

Especifica se a janela filho MDI contém um painel de encaixe.

```
BOOL IsTabbedPane() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a janela filho MDI contém um painel de encaixe que foi convertido em um documento com guias. Caso contrário, FALSE.

##  <a name="onmoveminiframe"></a>  CMDIChildWndEx::OnMoveMiniFrame

Chamado pelo framework para mover uma janela com minimoldura.

```
virtual BOOL OnMoveMiniFrame(CWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
[in] Um ponteiro para uma janela com minimoldura.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido, caso contrário, FALSE.

##  <a name="onsetpreviewmode"></a>  CMDIChildWndEx::OnSetPreviewMode

Chamado pelo framework para entrar ou sair do modo de visualização de impressão.

```
virtual void OnSetPreviewMode(
    BOOL bPreview,
    CPrintPreviewState* pState);
```

### <a name="parameters"></a>Parâmetros

*bPreview*<br/>
[in] Se for TRUE, entre no modo de visualização de impressão. Se for FALSE, sair do modo de visualização de impressão.

*pState*<br/>
[in] Um ponteiro para a estrutura de estado de visualização de impressão.

##  <a name="onupdateframetitle"></a>  CMDIChildWndEx::OnUpdateFrameTitle

Chamado pelo framework para atualizar o título do quadro.

```
virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
```

### <a name="parameters"></a>Parâmetros

*bAddToTitle*<br/>
[in] Se for TRUE, adicione o nome do documento ao título.

##  <a name="panefrompoint"></a>  CMDIChildWndEx::PaneFromPoint

Retorna o painel que contém o ponto especificado.

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

*ponto*<br/>
[in] Especifica o ponto em coordenadas da tela, para verificar.

*nSensitivity*<br/>
[in] Aumente a área de pesquisa, essa quantidade. Um painel satisfaz os critérios de pesquisa se o determinado ponto está na área de aumento.

*bExactBar*<br/>
[in] TRUE para ignorar a *nSensitivity* parâmetro; caso contrário, FALSE.

*pRTCBarType*<br/>
[in] Se não for NULL, o método procura apenas os painéis do tipo especificado.

*dwAlignment*<br/>
[in] Se um painel for encontrado no ponto especificado, este parâmetro conterá o lado do painel que foi mais próximo ao ponto especificado. Para obter mais informações, consulte a seção Comentários.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CBasePane`-objeto derivado que contém o ponto especificado ou nulo se nenhum painel foi encontrado.

### <a name="remarks"></a>Comentários

Chame esse método para determinar se um painel que contém o ponto especificado de acordo com as condições especificadas como classe de tempo de execução e visibilidade.

Quando a função retornará e um painel foi encontrado, *dwAlignment* contém o alinhamento do ponto especificado. Por exemplo, se o ponto fosse mais próximo à parte superior do painel de *dwAlignment* é definido como CBRS_ALIGN_TOP.

##  <a name="recalclayout"></a>  CMDIChildWndEx::RecalcLayout

Recalcula o layout da janela.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bNotify*<br/>
[in] Se for TRUE, o item ativo in-loco para a janela recebe notificação de alteração de layout.

##  <a name="removepanefromdockmanager"></a>  CMDIChildWndEx::RemovePaneFromDockManager

Remove um painel do Gerenciador de encaixe.

```
void RemovePaneFromDockManager(
    CBasePane* pControlBar,
    BOOL bDestroy,
    BOOL bAdjustLayout,
    BOOL bAutoHide,
    CBasePane* pBarReplacement);
```

### <a name="parameters"></a>Parâmetros

*pControlBar*<br/>
[in] Um ponteiro para o painel a ser removido.

*bDestroy*<br/>
[in] Se for TRUE, o painel removido é destruído.

*bAdjustLayout*<br/>
[in] Se for TRUE, ajuste o layout de encaixe imediatamente.

*bAutoHide*<br/>
[in] Se for TRUE, o layout de encaixe está relacionado à lista de barras de ocultar automaticamente. Se for FALSE, o layout de encaixe está relacionado à lista de painéis regulares.

*pBarReplacement*<br/>
[in] Um ponteiro para um painel que substitui o painel removido.

##  <a name="setrelatedtabgroup"></a>  CMDIChildWndEx::SetRelatedTabGroup

```
void SetRelatedTabGroup(CMFCTabCtrl* p);
```

### <a name="parameters"></a>Parâmetros

[in] *p*<br/>

### <a name="remarks"></a>Comentários

##  <a name="showpane"></a>  CMDIChildWndEx::ShowPane

```
void ShowPane(
    CBasePane* pBar,
    BOOL bShow,
    BOOL bDelay,
    BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

[in] *bMostrar*<br/>

[in] *bDelay*<br/>

[in] *bActivate*<br/>

### <a name="remarks"></a>Comentários

##  <a name="updatetaskbartabicon"></a>  CMDIChildWndEx::UpdateTaskbarTabIcon

Atualiza o ícone de guia de barra de tarefas do Windows 7.

```
virtual void UpdateTaskbarTabIcon(HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*hIcon*<br/>
Um identificador para um ícone a ser exibido na guia na barra de tarefas do Windows 7.

### <a name="remarks"></a>Comentários

##  <a name="unregistertaskbartab"></a>  CMDIChildWndEx::UnregisterTaskbarTab

Remove o filho MDI de guias de barra de tarefas do Windows 7.

```
void UnregisterTaskbarTab(BOOL bCheckRegisteredMDIChildCount = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bCheckRegisteredMDIChildCount*<br/>
Especifica se essa função precisa verificar o número de filhos MDI registrado com guias MDI. Se esse número for 0, esta função remove o retângulo de recorte de miniatura de barra de tarefas do aplicativo.

### <a name="remarks"></a>Comentários

##  <a name="settaskbarthumbnailcliprect"></a>  CMDIChildWndEx::SetTaskbarThumbnailClipRect

Chamado pelo framework para definir o retângulo de recorte para selecionar uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas.

```
virtual BOOL SetTaskbarThumbnailClipRect(CRect rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Especifica o novo retângulo de recorte. Se o retângulo está vazio ou nulo, o corte é removido.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="settaskbartabproperties"></a>  CMDIChildWndEx::SetTaskbarTabProperties

Define propriedades para uma guia na barra de tarefas do Windows 7.

```
void SetTaskbarTabProperties(DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Uma combinação de valores STPFLAG. Para obter mais informações, consulte [ITaskbarList4::SetTabProperties](/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist4-settabproperties).

### <a name="remarks"></a>Comentários

##  <a name="settaskbartaborder"></a>  CMDIChildWndEx::SetTaskbarTabOrder

Insere o filho MDI antes da janela especificada nas guias de barra de tarefas do Windows 7.

```
void SetTaskbarTabOrder(CMDIChildWndEx* pWndBefore = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWndBefore*<br/>
Um ponteiro para a janela filho da MDI cuja miniatura é inserida à esquerda. Esta janela já deve estar registrada por meio de `RegisterTaskbarTab`. Se esse valor for NULL, a miniatura do novo é adicionada ao final da lista.

### <a name="remarks"></a>Comentários

##  <a name="settaskbartabactive"></a>  CMDIChildWndEx::SetTaskbarTabActive

Ativa a guia correspondente de na barra de tarefas do Windows 7.

```
void SetTaskbarTabActive();
```

### <a name="remarks"></a>Comentários

##  <a name="registertaskbartab"></a>  CMDIChildWndEx::RegisterTaskbarTab

Registra o filho MDI com guias de barra de tarefas do Windows 7.

```
virtual void RegisterTaskbarTab(CMDIChildWndEx* pWndBefore = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWndBefore*<br/>
Um ponteiro para a janela filho da MDI cuja miniatura é inserida à esquerda. Esta janela já deve estar registrada por meio de `RegisterTaskbarTab`. Se esse valor for NULL, a miniatura do novo é adicionada ao final da lista.

### <a name="remarks"></a>Comentários

##  <a name="ontaskbartabthumbnailstretch"></a>  CMDIChildWndEx::OnTaskbarTabThumbnailStretch

Chamado pelo framework quando ele precisa ampliar um bitmap para uma visualização de miniatura de guia de na barra de tarefas de Windows 7 do filho MDI.

```
virtual BOOL OnTaskbarTabThumbnailStretch(
    HBITMAP hBmpDst,
    const CRect& rectDst,
    HBITMAP hBmpSrc,
    const CRect& rectSrc);
```

### <a name="parameters"></a>Parâmetros

*hBmpDst*<br/>
Um identificador para um bitmap de destino.

*rectDst*<br/>
Especifica o retângulo de destino.

*hBmpSrc*<br/>
Um identificador para um bitmap de origem.

*rectSrc*<br/>
Especifica o retângulo de origem.

### <a name="remarks"></a>Comentários

Requisito: afxmdichildwndex.h

##  <a name="ontaskbartabthumbnailmouseactivate"></a>  CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate

Chamado pelo framework quando a miniatura de guia na barra de tarefas deve processar a mensagem WM_MOUSEACTIVATE.

```
virtual int OnTaskbarTabThumbnailMouseActivate(
    CWnd* pDesktopWnd,
    UINT nHitTest,
    UINT message);
```

### <a name="parameters"></a>Parâmetros

*pDesktopWnd*<br/>
Especifica um ponteiro para a janela pai de nível superior da janela que está sendo ativada. O ponteiro pode ser temporário e não deve ser armazenado.

*nHitTest*<br/>
Especifica o código de área de teste de clique. Um teste de clique é um teste que determina o local do cursor.

*message*<br/>
Especifica o número de mensagens de mouse.

### <a name="remarks"></a>Comentários

A implementação padrão ativa o relacionados quadro filho MDI.

##  <a name="ontaskbartabthumbnailactivate"></a>  CMDIChildWndEx::OnTaskbarTabThumbnailActivate

Chamado pelo framework quando a miniatura de guia na barra de tarefas deve processar a mensagem WM_ACTIVATE.

```
virtual void OnTaskbarTabThumbnailActivate(
    UINT nState,
    CWnd* pWndOther,
    BOOL bMinimized);
```

### <a name="parameters"></a>Parâmetros

*nState*<br/>
Especifica se o `CWnd` está sendo ativada ou desativada.

*pWndOther*<br/>
Ponteiro para o `CWnd` sendo ativada ou desativada. O ponteiro pode ser NULL e pode ser temporária.

*bMinimized*<br/>
Especifica o estado minimizado do `CWnd` sendo ativada ou desativada. Um valor TRUE indica que a janela é minimizada.

### <a name="remarks"></a>Comentários

A implementação padrão ativa o relacionados quadro filho MDI.

##  <a name="onpresstaskbarthmbnailclosebutton"></a>  CMDIChildWndEx::OnPressTaskbarThmbnailCloseButton

Chamado pelo framework quando o usuário pressiona o botão Fechar na miniatura de guia na barra de tarefas.

```
virtual void OnPressTaskbarThmbnailCloseButton();
```

### <a name="remarks"></a>Comentários

##  <a name="ongeticonicthumbnail"></a>  CMDIChildWndEx::OnGetIconicThumbnail

Chamado pelo framework quando ele precisa obter um bitmap para a miniatura icônico do filho MDI.

```
virtual HBITMAP OnGetIconicThumbnail(
    int nWidth,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
Especifica a largura do bitmap necessário.

*nHeight*<br/>
Especifica a altura do bitmap necessário.

### <a name="remarks"></a>Comentários

##  <a name="ongeticoniclivepreviewbitmap"></a>  CMDIChildWndEx::OnGetIconicLivePreviewBitmap

Chamado pelo framework quando ele precisa obter um bitmap para a visualização dinâmica do filho MDI.

```
virtual HBITMAP OnGetIconicLivePreviewBitmap(
    BOOL bIsMDIChildActive,
    CPoint& ptLocation);
```

### <a name="parameters"></a>Parâmetros

*bIsMDIChildActive*<br/>
Esse parâmetro será TRUE se o bitmap é solicitado para o filho MDI, que está ativo no momento e a janela principal não é minimizada. O padrão de processamento nesse caso, tira um instantâneo da janela principal.

*ptLocation*<br/>
Especifica o local do bitmap no principal (de nível superior) coordenadas de cliente da janela. Esse ponto deve ser fornecido pelo receptor.

### <a name="return-value"></a>Valor de retorno

Se processados, retorna um identificador para um bitmap de 32 bpp válido, caso contrário, nulo.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada e retornar um bitmap de 32 bpp válido para a visualização dinâmica do filho MDI. Esse método é chamado somente quando o filho MDI é exibido nas guias de barra de tarefas do Windows 7. Se você retornar NULL, MFC chama os manipuladores padrão e obtenha usando bitmaps `PrintClient` ou `PrintWindow`.

##  <a name="m_dwdefaulttaskbartabpropertyflags"></a>  CMDIChildWndEx::m_dwDefaultTaskbarTabPropertyFlags

Uma combinação de sinalizadores, que é passada pelo framework para o `SetTaskbarTabProperties` método, quando uma guia (filho MDI) está sendo registrada com guias de barra de tarefas do Windows 7.

```
AFX_IMPORT_DATA static DWORD m_dwDefaultTaskbarTabPropertyFlags;
```

### <a name="remarks"></a>Comentários

A combinação de padrão é STPF_USEAPPTHUMBNAILWHENACTIVE &#124; STPF_USEAPPPEEKWHENACTIVE.

##  <a name="istaskbarthumbnailcliprectenabled"></a>  CMDIChildWndEx::IsTaskbarThumbnailClipRectEnabled

Informa se a seleção automática de uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas está habilitada ou desabilitada.

```
BOOL IsTaskbarThumbnailClipRectEnabled() const;
```

### <a name="return-value"></a>Valor de retorno

Seleção de retorna TRUE se automática de uma parte da área de cliente de uma janela para exibir estiver habilitada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="istaskbartabssupportenabled"></a>  CMDIChildWndEx::IsTaskbarTabsSupportEnabled

Informa se o filho MDI pode aparecer nas guias de barra de tarefas do Windows 7.

```
BOOL IsTaskbarTabsSupportEnabled();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o filho MDI pode aparecer nas guias de barra de tarefas do Windows 7; FALSE se o filho MDI não pode aparecer em guias de barra de tarefas do Windows 7.

### <a name="remarks"></a>Comentários

##  <a name="isregisteredwithtaskbartabs"></a>  CMDIChildWndEx::IsRegisteredWithTaskbarTabs

Retornará TRUE se o filho MDI foi registrado com êxito com guias de barra de tarefas do Windows 7.

```
BOOL IsRegisteredWithTaskbarTabs();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o filho MDI for registrado com guias de barra de tarefas do Windows 7; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="invalidateiconicbitmaps"></a>  CMDIChildWndEx::InvalidateIconicBitmaps

Invalida uma representação icônica de bitmap de um filho MDI.

```
BOOL InvalidateIconicBitmaps();
```

### <a name="return-value"></a>Valor de retorno

Retorna FALSE se o suporte de barra de tarefas do Windows 7 está desabilitado ou o filho MDI não está registrado com guias de barra de tarefas do Windows 7; Caso contrário, retornará TRUE.

### <a name="remarks"></a>Comentários

Deve ser chamado quando o conteúdo ao vivo ou o tamanho de um filho MDI foi alterado.

##  <a name="gettaskbarthumbnailcliprect"></a>  CMDIChildWndEx::GetTaskbarThumbnailClipRect

Chamado pelo framework quando ele precisa selecionar uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas.

```
virtual CRect GetTaskbarThumbnailClipRect() const;
```

### <a name="return-value"></a>Valor de retorno

Um retângulo, nas coordenadas do windows. Esse retângulo é mapeado para a área de cliente do quadro de nível superior. O retângulo deve estar vazio para limpar o retângulo de recorte.

### <a name="remarks"></a>Comentários

##  <a name="gettaskbarpreviewwnd"></a>  CMDIChildWndEx::GetTaskbarPreviewWnd

Chamado pelo framework quando ele precisa obter uma janela filho (normalmente, uma janela do modo de exibição ou separador) a ser exibido em uma miniatura de guia de barra de tarefas do Windows 7.

```
virtual CWnd* GetTaskbarPreviewWnd();
```

### <a name="return-value"></a>Valor de retorno

Deve retornar um ponteiro válido para um `CWnd` objeto, cuja visualização deve ser exibida em uma guia de barra de tarefas do Windows 7 relacionados a esse filho MDI. A implementação padrão retorna uma janela filho desse filho MDI com a ID de controle AFX_IDW_PANE_FIRST (que é geralmente um `CView`-classe derivada).

### <a name="remarks"></a>Comentários

##  <a name="gettabproxywnd"></a>  CMDIChildWndEx::GetTabProxyWnd

Retorna a janela de proxy de guia registrada com guias de barra de tarefas do Windows 7.

```
CMDITabProxyWnd* GetTabProxyWnd();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CMDITabProxyWnd` objeto, que está registrado com guias de barra de tarefas do Windows 7.

### <a name="remarks"></a>Comentários

##  <a name="enabletaskbarthumbnailcliprect"></a>  CMDIChildWndEx::EnableTaskbarThumbnailClipRect

Habilita ou desabilita a seleção automática de uma parte da área de cliente de uma janela para exibir como a miniatura da janela na barra de tarefas.

```
void EnableTaskbarThumbnailClipRect(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se deve ser habilitado (TRUE) ou desabilitar (FALSE) a seleção automática de uma parte da área de cliente de uma janela para exibir.

### <a name="remarks"></a>Comentários

##  <a name="canshowontaskbartabs"></a>  CMDIChildWndEx::CanShowOnTaskBarTabs

Informa a estrutura se esse filho MDI pode ser exibido nas guias de barra de tarefas do Windows 7.

```
virtual BOOL CanShowOnTaskBarTabs();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o conteúdo do filho MDI que pode ser exibido nas miniaturas de barra de tarefas do Windows 7.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada e retornar FALSE para desabilitar a aparência desse filho MDI em guias de barra de tarefas do Windows 7.

##  <a name="activatetoplevelframe"></a>  CMDIChildWndEx::ActivateTopLevelFrame

Chamado pelo framework para ativar o quadro de nível superior quando o aplicativo é ativado a partir de uma guia na barra de tarefas.

```
virtual void ActivateTopLevelFrame();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)<br/>
[Classe CMFCWindowsManagerDialog](../../mfc/reference/cmfcwindowsmanagerdialog-class.md)<br/>
[Classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)
