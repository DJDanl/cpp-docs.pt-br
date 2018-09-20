---
title: Classe CMFCDropDownToolBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CMFCDropDownToolBar [MFC], AllowShowOnPaneMenu
- CMFCDropDownToolBar [MFC], LoadBitmap
- CMFCDropDownToolBar [MFC], LoadToolBar
- CMFCDropDownToolBar [MFC], OnLButtonUp
- CMFCDropDownToolBar [MFC], OnMouseMove
- CMFCDropDownToolBar [MFC], OnSendCommand
- CMFCDropDownToolBar [MFC], OnUpdateCmdUI
ms.assetid: 78818ec5-83ce-42fa-a0d4-2d9d5ecc8770
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 675a155c8f19ca9c0ab30d15da9be7f5b3b40e7a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392314"
---
# <a name="cmfcdropdowntoolbar-class"></a>Classe CMFCDropDownToolBar

Uma barra de ferramentas que aparece quando o usuário pressiona e mantém um botão de barra de ferramentas de nível superior.

   Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.
## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownToolBar : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolBar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|
|[CMFCDropDownToolBar::LoadBitmap](#loadbitmap)|(Substitui [CMFCToolBar::LoadBitmap](../../mfc/reference/cmfctoolbar-class.md#loadbitmap).)|
|[CMFCDropDownToolBar::LoadToolBar](#loadtoolbar)|(Substitui [CMFCToolBar::LoadToolBar](../../mfc/reference/cmfctoolbar-class.md#loadtoolbar).)|
|[CMFCDropDownToolBar::OnLButtonUp](#onlbuttonup)||
|[CMFCDropDownToolBar::OnMouseMove](#onmousemove)||
|[CMFCDropDownToolBar::OnSendCommand](#onsendcommand)|(Substitui `CMFCToolBar::OnSendCommand`.)|
|[CMFCDropDownToolBar::OnUpdateCmdUI](#onupdatecmdui)|(Substitui [CMFCToolBar::OnUpdateCmdUI](cmfctoolbar-class.md).|

### <a name="remarks"></a>Comentários

Um `CMFCDropDownToolBar` objeto combina a aparência visual de uma barra de ferramentas com o comportamento de um menu pop-up. Quando um usuário pressiona e mantém um botão de barra de ferramentas da lista suspensa (consulte [classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)), uma lista suspensa de barra de ferramentas é exibida e o usuário pode selecionar um botão da barra de ferramentas suspensa rolando até ele e liberando o mouse botão. Depois que o usuário seleciona um botão na barra de ferramentas lista suspensa, esse botão é exibido como o botão atual na barra de ferramentas de nível superior.

Uma lista suspensa de barra de ferramentas não pode ser personalizada ou encaixada, e não tem um estado destacáveis.

A ilustração a seguir mostra um `CMFCDropDownToolBar` objeto:

![Exemplo de CMFCDropDownToolbar](../../mfc/reference/media/cmfcdropdown.png "cmfcdropdown")

Você cria um `CMFCDropDownToolBar` da mesma maneira que você cria uma barra de ferramentas comum do objeto (veja [classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)).

Para inserir a barra de ferramentas da lista suspensa em uma barra de ferramentas pai:

1. Reserve uma ID de recurso fictício para o botão no recurso da barra de ferramentas pai.

2. Criar uma `CMFCDropDownToolBarButton` objeto que contém a barra de ferramentas da lista suspensa (para obter mais informações, consulte [CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md#cmfcdropdowntoolbarbutton)).

3. Substitua o botão fictício com a `CMFCDropDownToolBarButton` objeto por meio [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

Para obter mais informações sobre os botões de barra de ferramentas, consulte [instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md). Para obter um exemplo de uma lista suspensa de barra de ferramentas, consulte o projeto de exemplo VisualStudioDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `Create` método no `CMFCDropDownToolBar` classe. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#29](../../mfc/codesnippet/cpp/cmfcdropdowntoolbar-class_1.h)]
[!code-cpp[NVC_MFC_VisualStudioDemo#30](../../mfc/codesnippet/cpp/cmfcdropdowntoolbar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

[CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar.h

##  <a name="allowshowonpanemenu"></a>  CMFCDropDownToolBar::AllowShowOnPaneMenu


```
virtual BOOL AllowShowOnPaneMenu() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="loadbitmap"></a>  CMFCDropDownToolBar::LoadBitmap

Carrega imagens da barra de ferramentas de recursos do aplicativo.

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
[in] A ID de recurso do bitmap que se refere às imagens da barra de ferramentas ativa.

*uiColdResID*<br/>
[in] A ID de recurso do bitmap que se refere às imagens da barra de ferramentas frio.

*uiMenuResID*<br/>
[in] A ID de recurso do bitmap que se refere às imagens do menu comum.

*Bloqueado*<br/>
[in] TRUE para bloquear a barra de ferramentas. Caso contrário, FALSE.

*uiDisabledResID*<br/>
[in] A ID de recurso do bitmap que se refere às imagens da barra de ferramentas desabilitado.

*uiMenuDisabledResID*<br/>
[in] A ID de recurso do bitmap que se refere às imagens de menu desabilitados.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método for bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O [CMFCToolBar::LoadToolBarEx](../../mfc/reference/cmfctoolbar-class.md#loadtoolbarex) método chama esse método para carregar as imagens que estão associadas com a barra de ferramentas. Substitua este método para executar o carregamento de recursos de imagem personalizado.

Chamar o `LoadBitmapEx` método para carregar imagens adicionais depois de criar a barra de ferramentas.

##  <a name="loadtoolbar"></a>  CMFCDropDownToolBar::LoadToolBar


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

*uiResID*<br/>
[in] [in] *uiColdResID*
*uiMenuResID*<br/>
[in] [in] *BOOL*
*uiDisabledResID*<br/>
[in] [in] *uiMenuDisabledResID* [in] *uiHotResID*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onlbuttonup"></a>  CMFCDropDownToolBar::OnLButtonUp


```
afx_msg void OnLButtonUp(
    UINT nFlags,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*nFlags*<br/>
[in] [in] *ponto*

### <a name="remarks"></a>Comentários

##  <a name="onmousemove"></a>  CMFCDropDownToolBar::OnMouseMove


```
afx_msg void OnMouseMove(
    UINT nFlags,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*nFlags*<br/>
[in] [in] *ponto*

### <a name="remarks"></a>Comentários

##  <a name="onsendcommand"></a>  CMFCDropDownToolBar::OnSendCommand


```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

[in] *pButton*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onupdatecmdui"></a>  CMFCDropDownToolBar::OnUpdateCmdUI


```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler);
```

### <a name="parameters"></a>Parâmetros

*pTarget*<br/>
[in] [in] *bDisableIfNoHndler*

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[CMFCToolBar::Create](../../mfc/reference/cmfctoolbar-class.md#create)<br/>
[CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Classe CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)



