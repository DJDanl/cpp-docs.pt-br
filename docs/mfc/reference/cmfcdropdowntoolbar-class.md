---
title: Classe CMFCDropDownToolBar
ms.date: 11/19/2018
f1_keywords:
- CMFCDropDownToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::AllowShowOnPaneMenu
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::LoadBitmap
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::LoadToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnLButtonUp
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnMouseMove
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnSendCommand
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolBar::OnUpdateCmdUI
helpviewer_keywords:
- CMFCDropDownToolBar [MFC], AllowShowOnPaneMenu
- CMFCDropDownToolBar [MFC], LoadBitmap
- CMFCDropDownToolBar [MFC], LoadToolBar
- CMFCDropDownToolBar [MFC], OnLButtonUp
- CMFCDropDownToolBar [MFC], OnMouseMove
- CMFCDropDownToolBar [MFC], OnSendCommand
- CMFCDropDownToolBar [MFC], OnUpdateCmdUI
ms.assetid: 78818ec5-83ce-42fa-a0d4-2d9d5ecc8770
ms.openlocfilehash: 68dd976471b39d7f50c2f0378b2fce99ad3feeca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367599"
---
# <a name="cmfcdropdowntoolbar-class"></a>Classe CMFCDropDownToolBar

Uma barra de ferramentas que aparece quando o usuário pressiona e segura um botão de barra de ferramentas de nível superior.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownToolBar : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolBar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|
|[CMFCDropDownToolBar::LoadBitmap](#loadbitmap)|(Substitui [cmfctoolbar:loadBitmap](../../mfc/reference/cmfctoolbar-class.md#loadbitmap).)|
|[CMFCDropDowntoolBar::LoadtoolBar](#loadtoolbar)|(Substitui [cmfctoolbar::LoadToolBar](../../mfc/reference/cmfctoolbar-class.md#loadtoolbar).)|
|[CMFCDropDownToolbar::Onlbuttonup](#onlbuttonup)||
|[CMFCDropDownToolbar::OnMouseMove](#onmousemove)||
|[CMFCDropDownToolbar::OnSendCommand](#onsendcommand)|(Substitui `CMFCToolBar::OnSendCommand`.)|
|[CMFCDropDownToolBar::OnUpdateCmdUI](#onupdatecmdui)|(Substitui [cmfctoolbar::OnUpdateCmdUI](cmfctoolbar-class.md).|

### <a name="remarks"></a>Comentários

Um `CMFCDropDownToolBar` objeto combina a aparência visual de uma barra de ferramentas com o comportamento de um menu pop-up. Quando um usuário pressiona e segura um botão de barra de ferramentas para baixo (consulte [CMFCDropDownToolbarButton Class](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)), uma barra de ferramentas parada aparece e o usuário pode selecionar um botão da barra de ferramentas para baixo, rolando até ele e soltando o botão do mouse. Depois que o usuário seleciona um botão na barra de ferramentas suspensa, esse botão é exibido como o botão atual na barra de ferramentas de nível superior.

Uma barra de ferramentas suspensa não pode ser personalizada ou encaixada, e não tem um estado de ruptura.

A ilustração `CMFCDropDownToolBar` a seguir mostra um objeto:

![Exemplo de CMFCDropDownToolbar](../../mfc/reference/media/cmfcdropdown.png "Exemplo de CMFCDropDownToolbar")

Você cria `CMFCDropDownToolBar` um objeto da mesma forma que cria uma barra de ferramentas comum (ver [CMFCToolBar Class](../../mfc/reference/cmfctoolbar-class.md)).

Para inserir a barra de ferramentas gota na barra de ferramentas dos pais:

1. Reserve um ID de recurso de boneco para o botão no recurso da barra de ferramentas pai.

2. Crie `CMFCDropDownToolBarButton` um objeto que contenha a barra de ferramentas para baixo (para obter mais informações, consulte [CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md#cmfcdropdowntoolbarbutton)).

3. Substitua o botão de `CMFCDropDownToolBarButton` boneco pelo objeto usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

Para obter mais informações sobre botões de barra de ferramentas, consulte [Passo a Passo: Colocando controles nas barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md). Para obter um exemplo de barra de ferramentas gotad, consulte o projeto de exemplo VisualStudioDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir `Create` demonstra como `CMFCDropDownToolBar` usar o método na classe. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#29](../../mfc/codesnippet/cpp/cmfcdropdowntoolbar-class_1.h)]
[!code-cpp[NVC_MFC_VisualStudioDemo#30](../../mfc/codesnippet/cpp/cmfcdropdowntoolbar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[Cmfctoolbar](../../mfc/reference/cmfctoolbar-class.md)

[Cmfcdropdowntoolbar](../../mfc/reference/cmfcdropdowntoolbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar.h

## <a name="cmfcdropdowntoolbarallowshowonpanemenu"></a><a name="allowshowonpanemenu"></a>CMFCDropDownToolBar::AllowShowOnPaneMenu

```
virtual BOOL AllowShowOnPaneMenu() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdropdowntoolbarloadbitmap"></a><a name="loadbitmap"></a>CMFCDropDownToolBar::LoadBitmap

Carrega imagens da barra de ferramentas dos recursos do aplicativo.

```
virtual BOOL LoadBitmap(
    UINT uiResID,
    UINT uiColdResID=0,
    UINT uiMenuResID=0,
    BOOL bLocked=FALSE,
    UINT uiDisabledResID=0,
    UINT uiMenuDisabledResID=0);
```

### <a name="parameters"></a>Parâmetros

*uiResID*<br/>
[em] O ID de recurso do bitmap que se refere às imagens da barra de ferramentas quente.

*uiColdResID*<br/>
[em] O ID de recurso do bitmap que se refere às imagens da barra de ferramentas frias.

*uiMenuResID*<br/>
[em] O ID de recurso do bitmap que se refere às imagens regulares do menu.

*Bloqueado*<br/>
[em] TRUE para bloquear a barra de ferramentas; caso contrário, FALSO.

*uiDisabledResID*<br/>
[em] O ID de recurso do bitmap que se refere às imagens da barra de ferramentas desativadas.

*uiMenuDisabledResID*<br/>
[em] O ID de recurso do bitmap que se refere às imagens do menu desativado.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O método [CMFCToolBar::LoadToolBarEx](../../mfc/reference/cmfctoolbar-class.md#loadtoolbarex) chama esse método para carregar as imagens associadas à barra de ferramentas. Substituir este método para executar o carregamento personalizado de recursos de imagem.

Chame `LoadBitmapEx` o método para carregar imagens adicionais depois de criar a barra de ferramentas.

## <a name="cmfcdropdowntoolbarloadtoolbar"></a><a name="loadtoolbar"></a>CMFCDropDowntoolBar::LoadtoolBar

```
virtual BOOL LoadToolBar(
    UINT uiResID,
    UINT uiColdResID = 0,
    UINT uiMenuResID = 0,
    BOOL = FALSE,
    UINT uiDisabledResID = 0,
    UINT uiMenuDisabledResID = 0,
    UINT uiHotResID = 0);
```

### <a name="parameters"></a>Parâmetros

[em] *uiResID*<br/>

[em] *uiColdResID*<br/>

[em] *uiMenuResID*<br/>

[em] *BOOL*<br/>

[em] *uiDisabledResID*<br/>

[em] *uiMenuDisabledResID*<br/>

[em] *uiHotResID*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdropdowntoolbaronlbuttonup"></a><a name="onlbuttonup"></a>CMFCDropDownToolbar::Onlbuttonup

```
afx_msg void OnLButtonUp(
    UINT nFlags,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

[em] *nBandeiras*<br/>

[em] *ponto*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdropdowntoolbaronmousemove"></a><a name="onmousemove"></a>CMFCDropDownToolbar::OnMouseMove

```
afx_msg void OnMouseMove(
    UINT nFlags,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

[em] *nBandeiras*<br/>

[em] *ponto*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdropdowntoolbaronsendcommand"></a><a name="onsendcommand"></a>CMFCDropDownToolbar::OnSendCommand

```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

[em] *botão p*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdropdowntoolbaronupdatecmdui"></a><a name="onupdatecmdui"></a>CMFCDropDownToolBar::OnUpdateCmdUI

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

[em] *pTarget*<br/>

[em] *bDisableIfNoHndler*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[CMFCToolBar::Criar](../../mfc/reference/cmfctoolbar-class.md#create)<br/>
[CMFCToolBar::Substituir botão](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
