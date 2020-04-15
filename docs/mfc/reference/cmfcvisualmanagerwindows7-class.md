---
title: Classe CMFCVisualManagerWindows7
ms.date: 03/27/2019
f1_keywords:
- CMFCVisualManagerWindows7
- AFXVISUALMANAGERWINDOWS7/CMFCVisualManagerWindows7
- AFXVISUALMANAGERWINDOWS7/CMFCVisualManagerWindows7::CMFCVisualManagerWindows7
- AFXVISUALMANAGERWINDOWS7/CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor
- AFXVISUALMANAGERWINDOWS7/CMFCVisualManagerWindows7::OnFillMenuImageRect
helpviewer_keywords:
- CMFCVisualManagerWindows7 Class [MFC]
ms.assetid: e8d87df1-0c09-4b58-8ade-4e911f796e42
ms.openlocfilehash: 6686afecc2b8ef97ea24ef45ff5225433677a954
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319841"
---
# <a name="cmfcvisualmanagerwindows7-class"></a>Classe CMFCVisualManagerWindows7

O `CMFCVisualManagerWindows7` aplicativo dá a um aplicativo a aparência de um aplicativo do Windows 7.

## <a name="syntax"></a>Sintaxe

```
class CMFCVisualManagerWindows7 : public CMFCVisualManagerWindows;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCVisualManagerWindows7:CMFCVisualManagerWindows7](#cmfcvisualmanagerwindows7)|Construtor padrão.|
|[CMFCVisualManagerWindows7::~CMFCVisualManagerWindows7](#_dtorcmfcvisualmanagerwindows7)|Destruidor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCVisualManagerWindows7::CleanStyle`|Limpa o estilo visual atual e redefine o estilo visual padrão.|
|`CMFCVisualManagerWindows7::CleanUp`|Limpa todos os objetos na interface do usuário e redefine os menus.|
|`CMFCVisualManagerWindows7::DrawNcBtn`|Desenha um botão na área não cliente no quadro. A estrutura usa este método para desenhar botões de minimizar, maximizar, fechar e restaurar no canto superior direito da janela. Este método só é chamado `Aero` quando o programa usa um tema.|
|`CMFCVisualManagerWindows7::DrawNcText`|Desenha texto na área não cliente no quadro. A estrutura usa este método para desenhar o título do aplicativo na barra de título na parte superior da janela do quadro.|
|`CMFCVisualManagerWindows7::DrawSeparator`|Desenha um separador na [classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).|
|`CMFCVisualManagerWindows7::GetRibbonBar`|Recupera a [Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) associada à interface do usuário.|
|[CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor](#getribboneditbackgroundcolor)|Obtém uma cor de fundo da caixa de edição Ribbon.|
|`CMFCVisualManagerWindows7::GetRibbonPopupBorderSize`|Substitui [cmfcvisualmanager::GetRibbonPopupBorderSize](../../mfc/reference/cmfcvisualmanager-class.md#getribbonpopupbordersize)|
|`CMFCVisualManagerWindows7::GetRibbonQuickAccessToolBarChevronOffset`|Substitui [cmfcvisualmanager::GetRibbonQuickAccessToolBarChevronOffset](../../mfc/reference/cmfcvisualmanager-class.md#getribbonquickaccesstoolbarchevronoffset)|
|`CMFCVisualManagerWindows7::GetRibbonQuickAccessToolBarRightMargin`|Substitui [cmfcvisualmanager::GetRibbonQuickAccessToolBarRightMarginMargem](../../mfc/reference/cmfcvisualmanager-class.md#getribbonquickaccesstoolbarrightmargin)|
|`CMFCVisualManagerWindows7::IsHighlightWholeMenuItem`|Substitui [cmfcvisualmanagerWindows::IsHighlightWholeMenuItem](../../mfc/reference/cmfcvisualmanagerwindows-class.md#ishighlightwholemenuitem)|
|`CMFCVisualManagerWindows7::IsOwnerDrawMenuCheck`|Substitui [o CMFCVisualManager::IsOwnerDrawMenuCheck](../../mfc/reference/cmfcvisualmanager-class.md#isownerdrawmenucheck)|
|`CMFCVisualManagerWindows7::IsRibbonPresent`|Determina se `CMFCRibbonBar` um está presente e visível.|
|`CMFCVisualManagerWindows7::OnDrawButtonBorder`|Substitui [cmfcvisualmanagerWindows:OnDrawButtonBorder](../../mfc/reference/cmfcvisualmanagerwindows-class.md#ondrawbuttonborder)|
|`CMFCVisualManagerWindows7::OnDrawCheckBoxEx`|Substitui [cmfcvisualmanagerWindows::OnDrawCheckBoxEx](../../mfc/reference/cmfcvisualmanagerwindows-class.md#ondrawcheckboxex)|
|`CMFCVisualManagerWindows7::OnDrawComboDropButton`|Substitui [cmfcvisualmanagerWindows:OnDrawComboDropButton](../../mfc/reference/cmfcvisualmanagerwindows-class.md#ondrawcombodropbutton)|
|`CMFCVisualManagerWindows7::OnDrawDefaultRibbonImage`|Substitui [cmfcvisualmanager::OnDrawDefaultRibbonImage](../../mfc/reference/cmfcvisualmanager-class.md#ondrawdefaultribbonimage)|
|`CMFCVisualManagerWindows7::OnDrawMenuBorder`|Substitui [cmfcvisualmanagerWindows:OnDrawMenuBorder](../../mfc/reference/cmfcvisualmanagerwindows-class.md#ondrawmenuborder)|
|`CMFCVisualManagerWindows7::OnDrawMenuCheck`|Substitui [cmfcvisualmanager::OnDrawMenuCheck](../../mfc/reference/cmfcvisualmanager-class.md#ondrawmenucheck)|
|`CMFCVisualManagerWindows7::OnDrawMenuLabel`|Substitui [cmfcvisualmanager::OnDrawMenuLabel](../../mfc/reference/cmfcvisualmanager-class.md#ondrawmenulabel)|
|`CMFCVisualManagerWindows7::OnDrawRadioButton`|Substitui `CMFCVisualManager::OnDrawRadioButton`|
|`CMFCVisualManagerWindows7::OnDrawRibbonApplicationButton`|Substitui [cmfcvisualmanager::OnDrawRibbonApp](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonapplicationbutton)|
|`CMFCVisualManagerWindows7::OnDrawRibbonButtonBorder`|Substitui [cmfcvisualmanager::OnDrawRibbonButtonBorder](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonbuttonborder)|
|`CMFCVisualManagerWindows7::OnDrawRibbonCaption`|Substitui [cmfcvisualmanager::OnDrawRibbonCaption](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribboncaption)|
|`CMFCVisualManagerWindows7::OnDrawRibbonCaptionButton`|Substitui [cmfcvisualmanager::OnDrawRibbonCaptionButton](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribboncaptionbutton)|
|`CMFCVisualManagerWindows7::OnDrawRibbonCategory`|Substitui [cmfcvisualmanager::OnDrawRibbonCategory](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribboncategory)|
|`CMFCVisualManagerWindows7::OnDrawRibbonCategoryTab`|Substitui [cmfcvisualmanager::OnDrawRibbonCategoryTab](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribboncategorytab)|
|`CMFCVisualManagerWindows7::OnDrawRibbonDefaultPaneButton`|Substitui [cmfcvisualmanager::OnDrawRibbonDefaultPaneButton](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbondefaultpanebutton)|
|`CMFCVisualManagerWindows7::OnDrawRibbonGalleryButton`|Substitui [cmfcvisualmanager::OnDrawRibbonGalleryButton](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbongallerybutton)|
|`CMFCVisualManagerWindows7::OnDrawRibbonLaunchButton`|Substitui `CMFCVisualManager::OnDrawRibbonLaunchButton`|
|`CMFCVisualManagerWindows7::OnDrawRibbonMenuCheckFrame`|Substitui [cmfcvisualmanager::OnDrawRibbonMenuCheckFrame](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonmenucheckframe)|
|`CMFCVisualManagerWindows7::OnDrawRibbonPanel`|Substitui [cmfcvisualmanager::OnDrawRibbonPanel](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonpanel)|
|`CMFCVisualManagerWindows7::OnDrawRibbonPanelCaption`|Substitui [cmfcvisualmanager::OnDrawRibbonPanelCaption](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonpanelcaption)|
|`CMFCVisualManagerWindows7::OnDrawRibbonProgressBar`|Substitui [cmfcvisualmanager::OnDrawRibbonProgressBar](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonprogressbar)|
|`CMFCVisualManagerWindows7::OnDrawRibbonRecentFilesFrame`|Substitui [cmfcvisualmanager::OnDrawRibbonRecentFilesFrame](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonrecentfilesframe)|
|`CMFCVisualManagerWindows7::OnDrawRibbonSliderChannel`|Substitui [cmfcvisualmanager::OnDrawRibbonSliderChannel](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonsliderchannel)|
|`CMFCVisualManagerWindows7::OnDrawRibbonSliderThumb`|Substitui [cmfcvisualmanager::OnDrawRibbonSliderThumb](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonsliderthumb)|
|`CMFCVisualManagerWindows7::OnDrawRibbonSliderZoomButton`|Substitui [cmfcvisualmanager::OnDrawRibbonSliderZoomButton](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonsliderzoombutton)|
|`CMFCVisualManagerWindows7::OnDrawRibbonStatusBarPane`|Substitui [cmfcvisualmanager::OnDrawRibbonStatusBarPane](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbonstatusbarpane)|
|`CMFCVisualManagerWindows7::OnDrawRibbonTabsFrame`|Substitui [cmfcvisualmanager::OnDrawRibbonTabsFrame](../../mfc/reference/cmfcvisualmanager-class.md#ondrawribbontabsframe)|
|`CMFCVisualManagerWindows7::OnDrawStatusBarSizeBox`|Substitui [cmfcVisualManagerWindows::OnDrawStatusBarSizeBox](../../mfc/reference/cmfcvisualmanagerwindows-class.md#ondrawstatusbarsizebox)|
|`CMFCVisualManagerWindows7::OnFillBarBackground`|Substitui [cmfcvisualmanagerWindows::OnFillBarBackground](../../mfc/reference/cmfcvisualmanagerwindows-class.md#onfillbarbackground)|
|`CMFCVisualManagerWindows7::OnFillButtonInterior`|Substitui [cmfcvisualmanagerWindows::OnFillButtonInterior](../../mfc/reference/cmfcvisualmanagerwindows-class.md#onfillbuttoninterior)|
|[CMFCVisualManagerWindows7:OnFillMenuImageRect](#onfillmenuimagerect)|A estrutura chama esse método quando preenche a área em torno de imagens de itens do menu.|
|`CMFCVisualManagerWindows7::OnFillRibbonButton`|Substitui [cmfcvisualmanager::OnFillRibbonButton](../../mfc/reference/cmfcvisualmanager-class.md#onfillribbonbutton)|
|`CMFCVisualManagerWindows7::OnFillRibbonQuickAccessToolBarPopup`|Substitui [cmfcvisualmanager::OnFillRibbonQuickAccessToolPopup](../../mfc/reference/cmfcvisualmanager-class.md#onfillribbonquickaccesstoolbarpopup)|
|`CMFCVisualManagerWindows7::OnHighlightMenuItem`|Substitui [cmfcvisualmanagerWindows::OnHighlightMenuItem](../../mfc/reference/cmfcvisualmanagerwindows-class.md#onhighlightmenuitem)|
|`CMFCVisualManagerWindows7::OnNcActivate`|Substitui [o CMFCVisualManager::OnNcActivate](../../mfc/reference/cmfcvisualmanager-class.md#onncactivate)|
|`CMFCVisualManagerWindows7::OnNcPaint`|Substitui [cmfcvisualmanager::OnNcPaint](../../mfc/reference/cmfcvisualmanager-class.md#onncpaint)|
|`CMFCVisualManagerWindows7::OnUpdateSystemColors`|Substitui [cmfcvisualmanagerWindows::OnUpdateSystemCores](../../mfc/reference/cmfcvisualmanagerwindows-class.md#onupdatesystemcolors)|
|`CMFCVisualManagerWindows7::SetResourceHandle`|Define o cabo de recurso que descreve os atributos do gerenciador visual.|
|`CMFCVisualManagerWindows7::SetStyle`|Define o esquema `CMFCVisualManagerWindows7` de cores da GUI.|

## <a name="remarks"></a>Comentários

Use `CMFCVisualManagerWindows7` a classe para alterar a aparência do seu aplicativo para imitar um aplicativo padrão do Windows 7. Esta classe pode não ser válida se o aplicativo estiver sendo executado em uma versão do Windows antes do Windows 7. Nesse cenário, o aplicativo usa o gerenciador visual padrão definido no [CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md).

O CMFCVisualManagerWindows7 herda vários métodos tanto da Classe `CMFCVisualManager` [CMFCVisualManagerWindows](../../mfc/reference/cmfcvisualmanagerwindows-class.md) quanto da classe. Os métodos listados na seção anterior `CMFCVisualManagerWindows7` são métodos novos para a classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcbasevisualmanager](../../mfc/reference/cmfcbasevisualmanager-class.md)

[Cmfcvisualmanager](../../mfc/reference/cmfcvisualmanager-class.md)

[Cmfcvisualmanagerofficexp](../../mfc/reference/cmfcvisualmanagerofficexp-class.md)

[Cmfcvisualmanagerwindows](../../mfc/reference/cmfcvisualmanagerwindows-class.md)

`CMFCVisualManagerWindows7`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvisualmanagerwindows7.h

## <a name="cmfcvisualmanagerwindows7cmfcvisualmanagerwindows7"></a><a name="_dtorcmfcvisualmanagerwindows7"></a>CMFCVisualManagerWindows7::~CMFCVisualManagerWindows7

Destruidor padrão.

```
virtual ~CMFCVisualManagerWindows7();
```

## <a name="cmfcvisualmanagerwindows7cmfcvisualmanagerwindows7"></a><a name="cmfcvisualmanagerwindows7"></a>CMFCVisualManagerWindows7:CMFCVisualManagerWindows7

Construtor padrão.

```
CMFCVisualManagerWindows7();
```

## <a name="cmfcvisualmanagerwindows7getribboneditbackgroundcolor"></a><a name="getribboneditbackgroundcolor"></a>CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor

Obtém a cor de fundo de uma caixa de edição de fita.

```
virtual COLORREF GetRibbonEditBackgroundColor (
    CMFCRibbonRichEditCtrl* pEdit,
    BOOL bIsHighlighted,
    BOOL bIsPaneHighlighted,
    BOOL bIsDisabled);
```

### <a name="parameters"></a>Parâmetros

*Pedit*<br/>
[em] Um ponteiro para o controle de edição. Este valor não pode ser NULO.

*bIshighlighted*<br/>
[fora] Retorna se a caixa de fita é destacada.

*bIsPaneHighlighted*<br/>
[fora] Retorna TRUE se o painel de fita que contém *pEdit* for destacado.

*bIsDisabled*<br/>
[fora] Retorna se *pEdit* está desativado.

### <a name="return-value"></a>Valor retornado

A cor de fundo da caixa de edição *pEdit*.

### <a name="remarks"></a>Comentários

## <a name="cmfcvisualmanagerwindows7onfillmenuimagerect"></a><a name="onfillmenuimagerect"></a>CMFCVisualManagerWindows7:OnFillMenuImageRect

A estrutura chama esse método quando preenche a área em torno de uma imagem do item do menu.

```
virtual void OnFillMenuImageRect(
    CDC* pDC,
    CMFCToolBarButton* pButton,
    CRect rectangle,
    CMFCVisualManager::AFX_BUTTON_STATE state);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para o contexto do dispositivo de um botão de menu.

*Pbutton*<br/>
[em] Um ponteiro `CMFCToolBarButton`para um. A estrutura preenche o plano de fundo para este botão.

*Retângulo*<br/>
[em] Um retângulo que especifica os limites da área de imagem do botão de menu.

*Estado*<br/>
[em] O estado do botão.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)<br/>
[CMFCVisualManagerWindows Class](../../mfc/reference/cmfcvisualmanagerwindows-class.md)
