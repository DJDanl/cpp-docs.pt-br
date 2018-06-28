---
title: Classe CMFCMenuBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCMenuBar
- AFXMENUBAR/CMFCMenuBar
- AFXMENUBAR/CMFCMenuBar::AdjustLocations
- AFXMENUBAR/CMFCMenuBar::AllowChangeTextLabels
- AFXMENUBAR/CMFCMenuBar::AllowShowOnPaneMenu
- AFXMENUBAR/CMFCMenuBar::CalcFixedLayout
- AFXMENUBAR/CMFCMenuBar::CalcLayout
- AFXMENUBAR/CMFCMenuBar::CalcMaxButtonHeight
- AFXMENUBAR/CMFCMenuBar::CanBeClosed
- AFXMENUBAR/CMFCMenuBar::CanBeRestored
- AFXMENUBAR/CMFCMenuBar::Create
- AFXMENUBAR/CMFCMenuBar::CreateEx
- AFXMENUBAR/CMFCMenuBar::CreateFromMenu
- AFXMENUBAR/CMFCMenuBar::EnableHelpCombobox
- AFXMENUBAR/CMFCMenuBar::EnableMenuShadows
- AFXMENUBAR/CMFCMenuBar::GetAvailableExpandSize
- AFXMENUBAR/CMFCMenuBar::GetColumnWidth
- AFXMENUBAR/CMFCMenuBar::GetDefaultMenu
- AFXMENUBAR/CMFCMenuBar::GetDefaultMenuResId
- AFXMENUBAR/CMFCMenuBar::GetFloatPopupDirection
- AFXMENUBAR/CMFCMenuBar::GetForceDownArrows
- AFXMENUBAR/CMFCMenuBar::GetHelpCombobox
- AFXMENUBAR/CMFCMenuBar::GetHMenu
- AFXMENUBAR/CMFCMenuBar::GetMenuFont
- AFXMENUBAR/CMFCMenuBar::GetMenuItem
- AFXMENUBAR/CMFCMenuBar::GetRowHeight
- AFXMENUBAR/CMFCMenuBar::GetSystemButton
- AFXMENUBAR/CMFCMenuBar::GetSystemButtonsCount
- AFXMENUBAR/CMFCMenuBar::GetSystemMenu
- AFXMENUBAR/CMFCMenuBar::HighlightDisabledItems
- AFXMENUBAR/CMFCMenuBar::IsButtonExtraSizeAvailable
- AFXMENUBAR/CMFCMenuBar::IsHighlightDisabledItems
- AFXMENUBAR/CMFCMenuBar::IsMenuShadows
- AFXMENUBAR/CMFCMenuBar::IsRecentlyUsedMenus
- AFXMENUBAR/CMFCMenuBar::IsShowAllCommands
- AFXMENUBAR/CMFCMenuBar::IsShowAllCommandsDelay
- AFXMENUBAR/CMFCMenuBar::LoadState
- AFXMENUBAR/CMFCMenuBar::OnChangeHot
- AFXMENUBAR/CMFCMenuBar::OnDefaultMenuLoaded
- AFXMENUBAR/CMFCMenuBar::OnSendCommand
- AFXMENUBAR/CMFCMenuBar::OnSetDefaultButtonText
- AFXMENUBAR/CMFCMenuBar::OnToolHitTest
- AFXMENUBAR/CMFCMenuBar::PreTranslateMessage
- AFXMENUBAR/CMFCMenuBar::RestoreOriginalstate
- AFXMENUBAR/CMFCMenuBar::SaveState
- AFXMENUBAR/CMFCMenuBar::SetDefaultMenuResId
- AFXMENUBAR/CMFCMenuBar::SetForceDownArrows
- AFXMENUBAR/CMFCMenuBar::SetMaximizeMode
- AFXMENUBAR/CMFCMenuBar::SetMenuButtonRTC
- AFXMENUBAR/CMFCMenuBar::SetMenuFont
- AFXMENUBAR/CMFCMenuBar::SetRecentlyUsedMenus
- AFXMENUBAR/CMFCMenuBar::SetShowAllCommands
dev_langs:
- C++
helpviewer_keywords:
- CMFCMenuBar [MFC], AdjustLocations
- CMFCMenuBar [MFC], AllowChangeTextLabels
- CMFCMenuBar [MFC], AllowShowOnPaneMenu
- CMFCMenuBar [MFC], CalcFixedLayout
- CMFCMenuBar [MFC], CalcLayout
- CMFCMenuBar [MFC], CalcMaxButtonHeight
- CMFCMenuBar [MFC], CanBeClosed
- CMFCMenuBar [MFC], CanBeRestored
- CMFCMenuBar [MFC], Create
- CMFCMenuBar [MFC], CreateEx
- CMFCMenuBar [MFC], CreateFromMenu
- CMFCMenuBar [MFC], EnableHelpCombobox
- CMFCMenuBar [MFC], EnableMenuShadows
- CMFCMenuBar [MFC], GetAvailableExpandSize
- CMFCMenuBar [MFC], GetColumnWidth
- CMFCMenuBar [MFC], GetDefaultMenu
- CMFCMenuBar [MFC], GetDefaultMenuResId
- CMFCMenuBar [MFC], GetFloatPopupDirection
- CMFCMenuBar [MFC], GetForceDownArrows
- CMFCMenuBar [MFC], GetHelpCombobox
- CMFCMenuBar [MFC], GetHMenu
- CMFCMenuBar [MFC], GetMenuFont
- CMFCMenuBar [MFC], GetMenuItem
- CMFCMenuBar [MFC], GetRowHeight
- CMFCMenuBar [MFC], GetSystemButton
- CMFCMenuBar [MFC], GetSystemButtonsCount
- CMFCMenuBar [MFC], GetSystemMenu
- CMFCMenuBar [MFC], HighlightDisabledItems
- CMFCMenuBar [MFC], IsButtonExtraSizeAvailable
- CMFCMenuBar [MFC], IsHighlightDisabledItems
- CMFCMenuBar [MFC], IsMenuShadows
- CMFCMenuBar [MFC], IsRecentlyUsedMenus
- CMFCMenuBar [MFC], IsShowAllCommands
- CMFCMenuBar [MFC], IsShowAllCommandsDelay
- CMFCMenuBar [MFC], LoadState
- CMFCMenuBar [MFC], OnChangeHot
- CMFCMenuBar [MFC], OnDefaultMenuLoaded
- CMFCMenuBar [MFC], OnSendCommand
- CMFCMenuBar [MFC], OnSetDefaultButtonText
- CMFCMenuBar [MFC], OnToolHitTest
- CMFCMenuBar [MFC], PreTranslateMessage
- CMFCMenuBar [MFC], RestoreOriginalstate
- CMFCMenuBar [MFC], SaveState
- CMFCMenuBar [MFC], SetDefaultMenuResId
- CMFCMenuBar [MFC], SetForceDownArrows
- CMFCMenuBar [MFC], SetMaximizeMode
- CMFCMenuBar [MFC], SetMenuButtonRTC
- CMFCMenuBar [MFC], SetMenuFont
- CMFCMenuBar [MFC], SetRecentlyUsedMenus
- CMFCMenuBar [MFC], SetShowAllCommands
ms.assetid: 8a3ce4c7-b012-4dc0-b4f8-53c10b4b86b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 63e7fd651cf8a5524f3dc6c521de742ced7741ac
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37039265"
---
# <a name="cmfcmenubar-class"></a>Classe CMFCMenuBar
Uma barra de menu que implementa o encaixe.  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCMenuBar : public CMFCToolbar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCMenuBar::AdjustLocations](#adjustlocations)|(Substitui `CMFCToolBar::AdjustLocations`.)|  
|[CMFCMenuBar::AllowChangeTextLabels](#allowchangetextlabels)|Especifica se os rótulos de texto podem ser mostrados em imagens de botões de barra de ferramentas. (Substitui [CMFCToolBar::AllowChangeTextLabels](../../mfc/reference/cmfctoolbar-class.md#allowchangetextlabels).)|  
|[CMFCMenuBar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|  
|[CMFCMenuBar::CalcFixedLayout](#calcfixedlayout)|Calcula o tamanho horizontal da barra de ferramentas. (Substitui [CMFCToolBar::CalcFixedLayout](../../mfc/reference/cmfctoolbar-class.md#calcfixedlayout).)|  
|[CMFCMenuBar::CalcLayout](#calclayout)|(Substitui `CMFCToolBar::CalcLayout`.)|  
|[CMFCMenuBar::CalcMaxButtonHeight](#calcmaxbuttonheight)|Calcula a altura máxima dos botões na barra de ferramentas. (Substitui [CMFCToolBar::CalcMaxButtonHeight](../../mfc/reference/cmfctoolbar-class.md#calcmaxbuttonheight).)|  
|[CMFCMenuBar::CanBeClosed](#canbeclosed)|Especifica se um usuário pode fechar a barra de ferramentas. (Substitui [CMFCToolBar::CanBeClosed](../../mfc/reference/cmfctoolbar-class.md#canbeclosed).)|  
|[CMFCMenuBar::CanBeRestored](#canberestored)|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização. (Substitui [CMFCToolBar::CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|  
|[CMFCMenuBar::Create](#create)|Cria um controle de menu e anexa-o para um `CMFCMenuBar` objeto.|  
|[CMFCMenuBar::CreateEx](#createex)|Cria um `CMFCMenuBar` objeto com opções de estilo adicionais.|  
|[CMFCMenuBar::CreateFromMenu](#createfrommenu)|Inicializa uma `CMFCMenuBar` objeto. Aceita um `HMENU` parâmetro que atua como um modelo para um preenchida `CMFCMenuBar`.|  
|[CMFCMenuBar::EnableHelpCombobox](#enablehelpcombobox)|Permite que um **ajuda** caixa de combinação que está localizada no lado direito da barra de menus.|  
|[CMFCMenuBar::EnableMenuShadows](#enablemenushadows)|Especifica se deve exibir sombras menus pop-up.|  
|[CMFCMenuBar::GetAvailableExpandSize](#getavailableexpandsize)|(Substitui [CPane::GetAvailableExpandSize](../../mfc/reference/cpane-class.md#getavailableexpandsize).)|  
|[CMFCMenuBar::GetColumnWidth](#getcolumnwidth)|Retorna a largura da barra de ferramentas. (Substitui [CMFCToolBar::GetColumnWidth](../../mfc/reference/cmfctoolbar-class.md#getcolumnwidth).)|  
|[CMFCMenuBar::GetDefaultMenu](#getdefaultmenu)|Retorna um identificador para o menu original no arquivo de recurso.|  
|[CMFCMenuBar::GetDefaultMenuResId](#getdefaultmenuresid)|Retorna o identificador de recurso do menu original no arquivo de recurso.|  
|[CMFCMenuBar::GetFloatPopupDirection](#getfloatpopupdirection)||  
|[CMFCMenuBar::GetForceDownArrows](#getforcedownarrows)||  
|[CMFCMenuBar::GetHelpCombobox](#gethelpcombobox)|Retorna um ponteiro para o **ajuda** caixa de combinação.|  
|[CMFCMenuBar::GetHMenu](#gethmenu)|Retorna o identificador de menu que é anexado ao `CMFCMenuBar` objeto.|  
|[CMFCMenuBar::GetMenuFont](#getmenufont)|Retorna a fonte atual global para objetos de menu.|  
|[CMFCMenuBar::GetMenuItem](#getmenuitem)|Retorna o botão de barra de ferramentas associado com o índice do item fornecido.|  
|[CMFCMenuBar::GetRowHeight](#getrowheight)|Retorna a altura dos botões da barra de ferramentas. (Substitui [CMFCToolBar::GetRowHeight](../../mfc/reference/cmfctoolbar-class.md#getrowheight).)|  
|[CMFCMenuBar::GetSystemButton](#getsystembutton)||  
|[CMFCMenuBar::GetSystemButtonsCount](#getsystembuttonscount)||  
|[CMFCMenuBar::GetSystemMenu](#getsystemmenu)||  
|[CMFCMenuBar::HighlightDisabledItems](#highlightdisableditems)|Indica se os itens de menu desativado são realçados.|  
|[CMFCMenuBar::IsButtonExtraSizeAvailable](#isbuttonextrasizeavailable)|Determina se a barra de ferramentas pode exibir botões que tem estendido bordas. (Substitui [CMFCToolBar::IsButtonExtraSizeAvailable](../../mfc/reference/cmfctoolbar-class.md#isbuttonextrasizeavailable).)|  
|[CMFCMenuBar::IsHighlightDisabledItems](#ishighlightdisableditems)|Indica se os itens são realçados.|  
|[CMFCMenuBar::IsMenuShadows](#ismenushadows)|Indica se as sombras são desenhadas para menus pop-up.|  
|[CMFCMenuBar::IsRecentlyUsedMenus](#isrecentlyusedmenus)|Indica se os comandos de menu usados recentemente são exibidos na barra de menus.|  
|[CMFCMenuBar::IsShowAllCommands](#isshowallcommands)|Indica se os menus pop-up exibem todos os comandos.|  
|[CMFCMenuBar::IsShowAllCommandsDelay](#isshowallcommandsdelay)|Indica se os menus de exibem todos os comandos após um pequeno atraso.|  
|[CMFCMenuBar::LoadState](#loadstate)|Carrega o estado do `CMFCMenuBar` objeto do registro.|  
|[CMFCMenuBar::OnChangeHot](#onchangehot)|Chamado pelo framework quando um usuário seleciona um botão na barra de ferramentas. (Substitui [CMFCToolBar::OnChangeHot](../../mfc/reference/cmfctoolbar-class.md#onchangehot).)|  
|[CMFCMenuBar::OnDefaultMenuLoaded](#ondefaultmenuloaded)|Chamado pelo framework quando uma janela do quadro carrega o menu padrão do arquivo de recurso.|  
|[CMFCMenuBar::OnSendCommand](#onsendcommand)|(Substitui `CMFCToolBar::OnSendCommand`.)|  
|[CMFCMenuBar::OnSetDefaultButtonText](#onsetdefaultbuttontext)|Chamado pelo framework quando um menu está no modo de personalização e o usuário altera o texto de um item de menu.|  
|[CMFCMenuBar::OnToolHitTest](#ontoolhittest)|(Substitui `CMFCToolBar::OnToolHitTest`.)|  
|[CMFCMenuBar::PreTranslateMessage](#pretranslatemessage)|(Substitui `CMFCToolBar::PreTranslateMessage`.)|  
|[CMFCMenuBar::RestoreOriginalstate](#restoreoriginalstate)|Chamado pelo framework quando um menu está no modo de personalização e o usuário seleciona **redefinir** para uma barra de menus.|  
|[CMFCMenuBar::SaveState](#savestate)|Salva o estado do `CMFCMenuBar` objeto no registro.|  
|[CMFCMenuBar::SetDefaultMenuResId](#setdefaultmenuresid)|Define o menu original no arquivo de recurso.|  
|[CMFCMenuBar::SetForceDownArrows](#setforcedownarrows)||  
|[CMFCMenuBar::SetMaximizeMode](#setmaximizemode)|Chamado pelo framework quando uma janela de filho MDI altera seu modo de exibição. Se a janela filho MDI é maximizada recentemente ou não é maximizada, este método atualizará a barra de menus.|  
|[CMFCMenuBar::SetMenuButtonRTC](#setmenubuttonrtc)|Define as informações de classe de tempo de execução são geradas quando o usuário cria dinamicamente os botões de menu.|  
|[CMFCMenuBar::SetMenuFont](#setmenufont)|Define a fonte para todos os menus no aplicativo.|  
|[CMFCMenuBar::SetRecentlyUsedMenus](#setrecentlyusedmenus)|Especifica se uma barra de menus exibe comandos de menu usados recentemente.|  
|[CMFCMenuBar::SetShowAllCommands](#setshowallcommands)|Especifica se a barra de menu mostra todos os comandos.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCMenuBar` classe é uma barra de menu que implementa a funcionalidade de encaixe. Ele é semelhante a uma barra de ferramentas, embora ele não pode ser fechado – ele sempre será exibido.  
  
 `CMFCMenuBar` oferece suporte a opção de exibir os objetos de item de menu usados recentemente. Se essa opção estiver habilitada, o `CMFCMenuBar` exibe somente um subconjunto dos comandos disponíveis na primeira exibição. Depois disso, os comandos usados recentemente são exibidos junto com o subconjunto original de comandos. Além disso, o usuário sempre pode expandir o menu para exibir todos os comandos disponíveis. Assim, cada comando disponível está configurado para exibir constantemente, ou para exibir somente se ele tiver sido selecionado recentemente.  
  
 Para usar um `CMFCMenuBar` de objeto, incorporá-lo no objeto de quadro de janela principal. Ao processar o `WM_CREATE` mensagem, chame `CMFCMenuBar::Create` ou `CMFCMenuBar::CreateEx`. Independentemente de qual criar a função que você use, transmitir um ponteiro para a janela do quadro principal. Em seguida, habilite o encaixe chamando [CFrameWndEx::EnableDocking](../../mfc/reference/cframewndex-class.md#enabledocking). Encaixar nesse menu chamando [CFrameWndEx::DockPane](../../mfc/reference/cframewndex-class.md#dockpane).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCMenuBar` classe. O exemplo mostra como definir o estilo do painel, habilitar o botão Personalizar, habilitar uma caixa de Ajuda, sombras menus pop-up e atualizar a barra de menus. Este trecho de código é parte do [exemplo de demonstração do IE](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo#3](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 `CMFCMenuBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmenubar.h  
  
##  <a name="adjustlocations"></a>  CMFCMenuBar::AdjustLocations  
 Ajusta as posições dos itens de menu na barra de menus.  
  
```  
virtual void AdjustLocations();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="allowchangetextlabels"></a>  CMFCMenuBar::AllowChangeTextLabels  
 Determina se os rótulos de texto são permitidos em imagens na barra de menus.  
  
```  
virtual BOOL AllowChangeTextLabels() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se o usuário pode optar por mostrar rótulos de texto em imagens.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="allowshowonpanemenu"></a>  CMFCMenuBar::AllowShowOnPaneMenu  

  
```  
virtual BOOL AllowShowOnPaneMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="calcfixedlayout"></a>  CMFCMenuBar::CalcFixedLayout  

  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bStretch*  
 [in] *bHorz*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="calclayout"></a>  CMFCMenuBar::CalcLayout  

  
```  
virtual CSize CalcLayout(
    DWORD dwMode,  
    int nLength = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *dwMode*  
 [in] *nLength*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="calcmaxbuttonheight"></a>  CMFCMenuBar::CalcMaxButtonHeight  

  
```  
virtual int CalcMaxButtonHeight();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="canbeclosed"></a>  CMFCMenuBar::CanBeClosed  

  
```  
virtual BOOL CanBeClosed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="canberestored"></a>  CMFCMenuBar::CanBeRestored  

  
```  
virtual BOOL CanBeRestored() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="create"></a>  CMFCMenuBar::Create  
 Cria um controle de menu e anexa-o para um [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle = AFX_DEFAULT_TOOLBAR_STYLE,  
    UINT nID = AFX_IDW_MENUBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pParentWnd*  
 Ponteiro para a janela pai do novo `CMFCMenuBar` objeto.  
  
 [in] *dwStyle*  
 O estilo da nova barra de menu.  
  
 [in] *nID*  
 A ID para a janela filho da barra de menus.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso bem-sucedido; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `CMFCMenuBar` do objeto, você deve chamar `Create`. Esse método cria a `CMFCMenuBar` controlar e anexa-o para o `CMFCMenuBar` objeto.  
  
 Para obter mais informações sobre estilos de barra de ferramentas, consulte [CBasePane::SetPaneStyle](../../mfc/reference/cbasepane-class.md#setpanestyle).  
  
##  <a name="createex"></a>  CMFCMenuBar::CreateEx  
 Cria um [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto com estilos estendidos especificados.  
  
```  
virtual BOOL CreateEx(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle = TBSTYLE_FLAT,  
    DWORD dwStyle = AFX_DEFAULT_TOOLBAR_STYLE,  
    CRect rcBorders = CRect(1,
    1,
    1,
    1),  
    UINT nID =AFX_IDW_MENUBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pParentWnd*  
 Ponteiro para a janela pai do novo `CMFCMenuBar` objeto.  
  
 [in] *dwCtrlStyle*  
 Estilos adicionais para a nova barra de menu.  
  
 [in] *dwStyle*  
 O estilo principal da nova barra de menu.  
  
 [in] *rcBorders*  
 Um `CRect` parâmetro que especifica os tamanhos para as bordas do `CMFCMenuBar` objeto.  
  
 [in] *nID*  
 A ID para a janela filho da barra de menus.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você deve usar essa função em vez de [CMFCMenuBar::Create](#create) quando quiser especificar estilos além do estilo de barra de ferramentas. Alguns estilos adicionais usados com frequência são `TBSTYLE_TRANSPARENT` e `CBRS_TOP`.  
  
 Para listas de estilos adicionais, consulte [controle de barra de ferramentas e os estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb760439), [estilos de controle comuns](http://msdn.microsoft.com/library/windows/desktop/bb775498), e [estilos de janela comuns](http://msdn.microsoft.com/library/windows/desktop/ms632600).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `CreateEx` método o `CMFCMenuBar` classe. Este trecho de código é parte do [exemplo de demonstração do IE](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo#2](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_3.cpp)]  
  
##  <a name="createfrommenu"></a>  CMFCMenuBar::CreateFromMenu  
 Inicializa um [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto. Modelos esse método de `CMFCMenuBar` objeto após um `HMENU` parâmetro.  
  
```  
virtual void CreateFromMenu(
    HMENU hMenu,  
    BOOL bDefaultMenu = FALSE,  
    BOOL bForceUpdate = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *hMenu*  
 Um identificador para um recurso de menu. `CreateFromMenu` usa esse recurso como um modelo para o `CMFCMenuBar`.  
  
 [in] *bDefaultMenu*  
 Um booliano que indica se o novo menu é o menu padrão.  
  
 [in] *bForceUpdate*  
 Um booliano que indica se esse método força uma atualização de menu.  
  
### <a name="remarks"></a>Comentários  
 Use esse método se você desejar um controle de menu para ter os mesmos itens de menu como um recurso de menu. Chame este método depois de chamar o [CMFCMenuBar::Create](#create) ou [CMFCMenuBar::CreateEx](#createex).  
  
##  <a name="enablehelpcombobox"></a>  CMFCMenuBar::EnableHelpCombobox  
 Permite que um **ajuda** caixa de combinação que está localizada no lado direito da barra de menus.  
  
```  
void EnableHelpCombobox(
    UINT uiID,  
    LPCTSTR lpszPrompt = NULL,  
    int nComboBoxWidth = 150);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uiID*  
 A ID de comando para o botão do **ajuda** caixa de combinação.  
  
 [in] *lpszPrompt*  
 Uma cadeia de caracteres que contém o texto que exibe a estrutura na caixa de combinação, se ele está vazio e não está ativo. Por exemplo, "Insira aqui o texto".  
  
 [in] *nComboBoxWidth*  
 A largura do botão da caixa de combinação em pixels.  
  
### <a name="remarks"></a>Comentários  
 O **ajuda** caixa de combinação é semelhante a **ajuda** caixa de combinação na barra de menu do [!INCLUDE[ofprword](../../mfc/reference/includes/ofprword_md.md)].  
  
 Quando você chama esse método com *uiID* definido como 0, esse método oculta a caixa de combinação. Caso contrário, esse método exibirá a caixa de combinação automaticamente no lado direito da barra de menus. Depois de chamar esse método, chame [CMFCMenuBar::GetHelpCombobox](#gethelpcombobox) para obter um ponteiro para os dados inseridos [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md) objeto.  
  
##  <a name="enablemenushadows"></a>  CMFCMenuBar::EnableMenuShadows  
 Ativa as sombras menus pop-up.  
  
```  
static void EnableMenuShadows(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bAtivar*  
 Um parâmetro booliano que indica se as sombras devem ser habilitadas para menus pop-up.  
  
### <a name="remarks"></a>Comentários  
 O algoritmo usa esse método é complexo e pode diminuir o desempenho do seu aplicativo em sistemas mais lentos.  
  
##  <a name="getavailableexpandsize"></a>  CMFCMenuBar::GetAvailableExpandSize  

  
```  
virtual int GetAvailableExpandSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcolumnwidth"></a>  CMFCMenuBar::GetColumnWidth  

  
```  
virtual int GetColumnWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdefaultmenu"></a>  CMFCMenuBar::GetDefaultMenu  
 Recupera um identificador para o menu original. A estrutura carrega menu original do arquivo de recurso.  
  
```  
HMENU GetDefaultMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um recurso de menu.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo personaliza um menu, você pode usar esse método para recuperar um identificador para o menu original.  
  
##  <a name="getdefaultmenuresid"></a>  CMFCMenuBar::GetDefaultMenuResId  
 Recupera o identificador de recurso de menu padrão.  
  
```  
UINT GetDefaultMenuResId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de recurso de menu.  
  
### <a name="remarks"></a>Comentários  
 A estrutura carrega o menu padrão para o `CMFCMenuBar` objeto do arquivo de recurso.  
  
##  <a name="getfloatpopupdirection"></a>  CMFCMenuBar::GetFloatPopupDirection  

  
```  
int GetFloatPopupDirection(CMFCToolBarMenuButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pButton*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getforcedownarrows"></a>  CMFCMenuBar::GetForceDownArrows  

  
```  
BOOL GetForceDownArrows();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethelpcombobox"></a>  CMFCMenuBar::GetHelpCombobox  
 Retorna um ponteiro para o **ajuda** caixa de combinação.  
  
```  
CMFCToolBarComboBoxButton* GetHelpCombobox();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o **ajuda** caixa de combinação. `NULL` Se o **ajuda** caixa de combinação está ocultada ou não habilitada.  
  
### <a name="remarks"></a>Comentários  
 O **ajuda** caixa de combinação está localizada no lado direito da barra de menus. Chame o método [CMFCMenuBar::EnableHelpCombobox](#enablehelpcombobox) para habilitar esta caixa de combinação.  
  
##  <a name="gethmenu"></a>  CMFCMenuBar::GetHMenu  
 Recupera o identificador para o menu anexado para o [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto.  
  
```  
HMENU GetHMenu() const;  
```  
  
##  <a name="getmenufont"></a>  CMFCMenuBar::GetMenuFont  
 Recupera a fonte do menu atual.  
  
```  
static const CFont& GetMenuFont(BOOL bHorz = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bHorz*  
 Um parâmetro booleano que especifica se deve retornar a fonte horizontal ou vertical. `TRUE` indica a fonte horizontal.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CFont](../../mfc/reference/cfont-class.md) parâmetro que contém a fonte de barra de menu atual.  
  
### <a name="remarks"></a>Comentários  
 A fonte retornada é um parâmetro global para o aplicativo. Duas fontes globais são mantidas para todas as `CMFCMenuBar` objetos. Essas fontes separadas são usados para barras de menus horizontal e vertical.  
  
##  <a name="getmenuitem"></a>  CMFCMenuBar::GetMenuItem  
 Recupera um [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) objeto em uma barra de menus com base no índice de item.  
  
```  
CMFCToolBarButton* GetMenuItem(int iItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *item*  
 O índice do item de menu para retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CMFCToolBarButton` que coincide com o índice especificado pelo objeto *item*. `NULL` Se o índice é inválido.  
  
##  <a name="getrowheight"></a>  CMFCMenuBar::GetRowHeight  

  
```  
virtual int GetRowHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsystembutton"></a>  CMFCMenuBar::GetSystemButton  

  
```  
CMFCToolBarMenuButtonsButton* GetSystemButton(
    UINT uiBtn,  
    BOOL bByCommand = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uiBtn*  
 [in] *bByCommand*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsystembuttonscount"></a>  CMFCMenuBar::GetSystemButtonsCount  

  
```  
int GetSystemButtonsCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsystemmenu"></a>  CMFCMenuBar::GetSystemMenu  

  
```  
CMFCToolBarSystemMenuButton* GetSystemMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="highlightdisableditems"></a>  CMFCMenuBar::HighlightDisabledItems  
 Controla se a estrutura realça os itens de menu desativado.  
  
```  
static void HighlightDisabledItems(BOOL bHighlight = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bHighlight*  
 Um parâmetro booliano que indica se a estrutura realça os itens de menu disponíveis.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a estrutura não realçar itens de menu não está disponível quando o usuário posiciona o ponteiro do mouse sobre eles.  
  
##  <a name="isbuttonextrasizeavailable"></a>  CMFCMenuBar::IsButtonExtraSizeAvailable  

  
```  
virtual BOOL IsButtonExtraSizeAvailable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ishighlightdisableditems"></a>  CMFCMenuBar::IsHighlightDisabledItems  
 Indica se a estrutura realça os itens de menu disponíveis.  
  
```  
static BOOL IsHighlightDisabledItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se os itens de menu disponíveis são realçadas. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a estrutura não realçar itens de menu não está disponível quando o usuário posiciona o ponteiro do mouse sobre eles. Use o [CMFCMenuBar::HighlightDisabledItems](#highlightdisableditems) método para habilitar esse recurso.  
  
##  <a name="ismenushadows"></a>  CMFCMenuBar::IsMenuShadows  
 Indica se a estrutura desenha sombras menus pop-up.  
  
```  
static BOOL IsMenuShadows();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a estrutura desenha sombras menu; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCMenuBar::EnableMenuShadows](#enablemenushadows) método para habilitar ou desabilitar esse recurso.  
  
##  <a name="isrecentlyusedmenus"></a>  CMFCMenuBar::IsRecentlyUsedMenus  
 Indica se os comandos de menu usados recentemente são exibidos na barra de menus.  
  
```  
static BOOL IsRecentlyUsedMenus();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CMFCMenuBar` objeto mostra usado recentemente comandos de menu; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use a função [CMFCMenuBar::SetRecentlyUsedMenus](#setrecentlyusedmenus) para controlar se a barra de menu mostra recentemente usados comandos de menu.  
  
##  <a name="isshowallcommands"></a>  CMFCMenuBar::IsShowAllCommands  
 Indica se os menus de exibem todos os comandos.  
  
```  
static BOOL IsShowAllCommands();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CMFCMenuBar` exibe todos os comandos; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um `CMFCMenuBar` objeto pode ser configurado para mostrar todos os comandos ou mostrar apenas um subconjunto de comandos. Para obter mais informações sobre esse recurso, consulte [CMFCMenuBar classe](../../mfc/reference/cmfcmenubar-class.md).  
  
 `IsShowAllCommands` Você será informado como esse recurso é configurado para o `CMFCMenuBar` objeto. Para controlar quais comandos de menu serão mostrados, use os métodos [CMFCMenuBar::SetShowAllCommands](#setshowallcommands) e [CMFCMenuBar::SetRecentlyUsedMenus](#setrecentlyusedmenus).  
  
##  <a name="isshowallcommandsdelay"></a>  CMFCMenuBar::IsShowAllCommandsDelay  
 Indica se o [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto exibe todos os comandos após um pequeno atraso.  
  
```  
static BOOL IsShowAllCommandsDelay();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de menus exibe menus completos após um pequeno atraso; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Quando você configura uma barra de menus para itens de exibição usada recentemente, a barra de menus exibe o menu completo em uma das duas maneiras:  
  
-   Exiba o menu completo após um atraso programado de quando o usuário passa o cursor sobre a seta na parte inferior do menu.  
  
-   Exiba o menu completo após o usuário clicar na seta na parte inferior do menu.  
  
 Por padrão, todos os `CMFCMenuBar` objetos usam a opção para exibir o menu completo após um pequeno atraso. Essa opção não pode ser alterada por meio de programação no `CMFCMenuBar` classe. No entanto, um usuário pode alterar o comportamento durante a personalização da barra de ferramentas usando o **personalizar** caixa de diálogo.  
  
##  <a name="loadstate"></a>  CMFCMenuBar::LoadState  
 Carrega o estado da barra de menus do registro do Windows.  
  
```  
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,  
    int nIndex = -1,  
    UINT uiID = (UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszProfileName*  
 Uma cadeia de caracteres que contém o caminho de uma chave de registro do Windows.  
  
 [in] *nIndex*  
 A identificação do controle de barra de menus.  
  
 [in] *uiID*  
 Um valor reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCMenuBar::SaveState](#savestate) método para salvar o estado da barra de menus no registro. As informações salvas incluem os itens de menu, o estado de encaixe e a posição da barra de menus.  
  
 Na maioria dos casos, seu aplicativo não chamar `LoadState`. O framework chama este método quando ele inicializa o espaço de trabalho.  
  
##  <a name="onchangehot"></a>  CMFCMenuBar::OnChangeHot  

  
```  
virtual void OnChangeHot(int iHot);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *iHot*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondefaultmenuloaded"></a>  CMFCMenuBar::OnDefaultMenuLoaded  
 O framework chama este método quando ele carrega o recurso de menu do arquivo de recurso.  
  
```  
virtual void OnDefaultMenuLoaded(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *hMenu*  
 O identificador do menu anexados para o `CMFCMenuBar` objeto.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua esta função para executar código personalizado depois que a estrutura de um recurso de menu é carregada do arquivo de recurso.  
  
##  <a name="onsendcommand"></a>  CMFCMenuBar::OnSendCommand  

  
```  
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pButton*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onsetdefaultbuttontext"></a>  CMFCMenuBar::OnSetDefaultButtonText  
 O framework chama esse método quando o usuário altera o texto de um item na barra de menus.  
  
```  
virtual BOOL OnSetDefaultButtonText(CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pButton*  
 Um ponteiro para o [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) objeto que o usuário deseja personalizar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a estrutura aplica as alterações do usuário para a barra de menus; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão para esse método altera o texto do botão para o texto que o usuário fornece.  
  
##  <a name="ontoolhittest"></a>  CMFCMenuBar::OnToolHitTest  

  
```  
virtual INT_PTR OnToolHitTest(
    CPoint point,  
    TOOLINFO* pTI) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *ponto*  
 [in] *pTI*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="pretranslatemessage"></a>  CMFCMenuBar::PreTranslateMessage  

  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pMsg*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="restoreoriginalstate"></a>  CMFCMenuBar::RestoreOriginalstate  
 Chamado pelo framework quando o usuário seleciona **redefinir** do **personalizar** caixa de diálogo.  
  
```  
virtual BOOL RestoreOriginalstate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado quando o usuário seleciona **redefinir** no menu de personalização. Manualmente, você pode chamar esse método para programaticamente redefinir o estado da barra de menus. Esse método carrega o estado original do arquivo de recurso.  
  
 Substitua este método se desejar fazer qualquer processamento quando o usuário seleciona o **redefinir** opção.  
  
##  <a name="savestate"></a>  CMFCMenuBar::SaveState  
 Salva o estado do [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto no registro do Windows.  
  
```  
virtual BOOL SaveState (
    LPCTSTR lpszProfileName = NULL,  
    int nIndex = -1,  
    UINT uiID = (UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszProfileName*  
 Uma cadeia de caracteres que contém o caminho de uma chave de registro do Windows.  
  
 [in] *nIndex*  
 A identificação do controle de barra de menus.  
  
 [in] *uiID*  
 Um valor reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se for bem-sucedida; Caso contrário, `FALSE`;  
  
### <a name="remarks"></a>Comentários  
 Normalmente, seu aplicativo não chamar `SaveState`. O framework chama esse método quando o espaço de trabalho é serializado. Para obter mais informações, consulte [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate).  
  
 As informações salvas incluem os itens de menu, o estado de encaixe e a posição da barra de menus.  
  
##  <a name="setdefaultmenuresid"></a>  CMFCMenuBar::SetDefaultMenuResId  
 Define o menu padrão para um [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) objeto com base na ID do recurso.  
  
```  
void SetDefaultMenuResId(UINT uiResId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uiResId*  
 A ID de recurso para o novo padrão.  
  
### <a name="remarks"></a>Comentários  
 O [CMFCMenuBar::RestoreOriginalstate](#restoreoriginalstate) método restaura o menu padrão do arquivo de recurso.  
  
 Use o [CMFCMenuBar::GetDefaultMenuResId](#getdefaultmenuresid) método para recuperar o menu padrão sem ser restaurado.  
  
##  <a name="setforcedownarrows"></a>  CMFCMenuBar::SetForceDownArrows  

  
```  
void SetForceDownArrows(BOOL bValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bDados do valor*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setmaximizemode"></a>  CMFCMenuBar::SetMaximizeMode  
 O framework chama este método quando um MDI altera seu modo de exibição e a barra de menus deve ser atualizada.  
  
```  
void SetMaximizeMode(
    BOOL bMax,  
    CWnd* pWnd = NULL,  
    BOOL bRecalcLayout = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bMax*  
 Um booliano que especifica o modo. Consulte a seção Comentários para obter mais informações.  
  
 [in] *pWnd*  
 Um ponteiro para a janela filho MDI que está sendo alterado.  
  
 [in] *bRecalcLayout*  
 Um valor booleano que especifica se o layout da barra de menu deve ser recalculado imediatamente.  
  
### <a name="remarks"></a>Comentários  
 Quando uma janela de filho MDI é maximizada, uma barra de menus anexada para a janela do quadro principal MDI exibe o menu do sistema e o **minimizar**, **maximizar** e **fechar** botões. Se *bMax* é `TRUE` e *pWnd* não é `NULL`, a janela filho MDI é maximizada, e a barra de menus deve incorporar os controles adicionais. Caso contrário, a barra de menus retorna ao seu estado normal.  
  
##  <a name="setmenubuttonrtc"></a>  CMFCMenuBar::SetMenuButtonRTC  
 Define as informações de classe de tempo de execução usado pelo framework quando o usuário cria botões de menu.  
  
```  
void SetMenuButtonRTC(CRuntimeClass* pMenuButtonRTC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pMenuButtonRTC*  
 O [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) informações para uma classe derivada do [CMFCMenuButton classe](../../mfc/reference/cmfcmenubutton-class.md).  
  
### <a name="remarks"></a>Comentários  
 Quando um usuário adiciona novos botões da barra de menus, o framework cria dinamicamente os botões. Por padrão, ele cria `CMFCMenuButton` objetos. Substitua este método para alterar o tipo de objetos de botão que cria a estrutura.  
  
##  <a name="setmenufont"></a>  CMFCMenuBar::SetMenuFont  
 Define a fonte para todas as barras de menu em seu aplicativo.  
  
```  
static BOOL SetMenuFont(
    LPLOGFONT lpLogFont,  
    BOOL bHorz = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpLogFont*  
 Um ponteiro para um [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/bb773327) estrutura que define a fonte a ser definido.  
  
 [in] *bHorz*  
 TRUE se você quiser que o *lpLogFont* parâmetro a ser usado para a fonte vertical, FALSE se você deseja que seja usado para a fonte horizontal.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Duas fontes são usadas para todos os `CMFCMenuBar` objetos. Essas fontes separadas são usados para barras de menus horizontal e vertical.  
  
 As configurações de fonte são variáveis globais e afetam todos os `CMFCMenuBar` objetos.  
  
##  <a name="setrecentlyusedmenus"></a>  CMFCMenuBar::SetRecentlyUsedMenus  
 Controla se uma barra de menus exibe recentemente usados comandos de menu.  
  
```  
static void SetRecentlyUsedMenus (BOOL bOn = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bOn*  
 Um valor booleano que controla se os comandos de menu usados recentemente são exibidos.  
  
##  <a name="setshowallcommands"></a>  CMFCMenuBar::SetShowAllCommands  
 Controla se um menu mostra todos os comandos disponíveis.  
  
```  
static void SetShowAllCommands(BOOL bShowAllCommands = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bShowAllCommands*  
 Um parâmetro booleano que especifica se o menu pop-up mostra todos os comandos de menu.  
  
### <a name="remarks"></a>Comentários  
 Se um menu não exibir todos os comandos de menu, ele oculta os comandos que raramente são usados. Para obter mais informações sobre como exibir comandos de menu, consulte [CMFCMenuBar classe](../../mfc/reference/cmfcmenubar-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
