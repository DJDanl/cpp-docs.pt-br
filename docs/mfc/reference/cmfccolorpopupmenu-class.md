---
title: Classe CMFCColorPopupMenu
ms.date: 11/04/2016
f1_keywords:
- CMFCColorPopupMenu
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::CMFCColorPopupMenu
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::CreateTearOffBar
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::GetMenuBar
- AFXCOLORPOPUPMENU/CMFCColorPopupMenu::SetPropList
helpviewer_keywords:
- CMFCColorPopupMenu [MFC], CMFCColorPopupMenu
- CMFCColorPopupMenu [MFC], CreateTearOffBar
- CMFCColorPopupMenu [MFC], GetMenuBar
- CMFCColorPopupMenu [MFC], SetPropList
ms.assetid: 0bf9efe8-aed5-4ab7-b23b-eb284b4668be
ms.openlocfilehash: bcdf60c974ecdc437b90891d2b46a5eec94859d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367675"
---
# <a name="cmfccolorpopupmenu-class"></a>Classe CMFCColorPopupMenu

Representa um menu pop-up que os usuários usam para selecionar cores em um documento ou aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorPopupMenu : public CMFCPopupMenu
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCColorPopupMenu:CMFCColorPopupMenu](#cmfccolorpopupmenu)|Constrói um objeto `CMFCColorPopupMenu`.|
|`CMFCColorPopupMenu::~CMFCColorPopupMenu`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCColorPopupMenu::CreateTearOffBar](#createtearoffbar)|Cria uma barra de cor de tear-off dockable. (Substitui [cmfcpopupmenu::CreateTearOffBar](../../mfc/reference/cmfcpopupmenu-class.md#createtearoffbar).)|
|[CMFCColorPopupMenu::GetMenuBar](#getmenubar)|Retorna a [BARRA CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) que está incorporada dentro do menu pop-up. (Substitui [cmfcpopupmenu::GetMenuBar](../../mfc/reference/cmfcpopupmenu-class.md#getmenubar).)|
|`CMFCColorPopupMenu::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCColorPopupMenu::SetPropList](#setproplist)|Define o objeto de controle `CMFCColorBar` da grade de propriedade do objeto incorporado.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|`m_bEnabledInCustomizeMode`|Um valor booleano que determina se deve mostrar a barra de cores.|
|`m_wndColorBar`|O `CMFCColorBar` objeto que fornece seleção de cores.|

### <a name="remarks"></a>Comentários

Essa classe herda a funcionalidade do `CMFCPopupMenu` menu pop-up `CMFCColorBar` da classe e gerencia um objeto que fornece seleção de cores. Quando a estrutura da barra de `m_bEnabledInCustomizeMode` ferramentas estiver no modo de personalização e o membro estiver definido como FALSE, o objeto da barra de cor não será mostrado. Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)

Para obter `CMFCColorBar`mais informações sobre , consulte [CMFCColorBar Class](../../mfc/reference/cmfccolorbar-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[Cminiframewnd](../../mfc/reference/cminiframewnd-class.md)

[Cmfcpopupmenu](../../mfc/reference/cmfcpopupmenu-class.md)

[CMFCColorPopupMenu](../../mfc/reference/cmfccolorpopupmenu-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorpopupmenu.h

## <a name="cmfccolorpopupmenucmfccolorpopupmenu"></a><a name="cmfccolorpopupmenu"></a>CMFCColorPopupMenu:CMFCColorPopupMenu

Constrói um objeto `CMFCColorPopupMenu`.

```
CMFCColorPopupMenu(
    const CArray<COLORREF, COLORREF>& colors,
    COLORREF color,
    LPCTSTR lpszAutoColor,
    LPCTSTR lpszOtherColor,
    LPCTSTR lpszDocColors, CList<COLORREF, COLORREF>& lstDocColors,
    int nColumns,
    int nHorzDockRows,
    int nVertDockColumns,
    COLORREF colorAutomatic,
    UINT uiCommandID,
    BOOL bStdColorDlg = FALSE);

CMFCColorPopupMenu(
    CMFCColorButton* pParentBtn,
    const CArray<COLORREF, COLORREF>& colors,
    COLORREF color,
    LPCTSTR lpszAutoColor,
    LPCTSTR lpszOtherColor,
    LPCTSTR lpszDocColors, CList<COLORREF, COLORREF>& lstDocColors,
    int nColumns,
    COLORREF colorAutomatic);

CMFCColorPopupMenu(
    CMFCRibbonColorButton* pParentBtn,
    const CArray<COLORREF, COLORREF>& colors,
    COLORREF color,
    LPCTSTR lpszAutoColor,
    LPCTSTR lpszOtherColor,
    LPCTSTR lpszDocColors, CList<COLORREF, COLORREF>& lstDocColors,
    int nColumns,
    COLORREF colorAutomatic,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Cores*<br/>
[em] Uma matriz de cores que a estrutura exibe no menu pop-up.

*cor*<br/>
[em] A cor selecionada padrão.

*lpszAutoColor*<br/>
[em] A etiqueta de texto do botão de cor *automático* (padrão) ou NULL.

A etiqueta padrão para o botão automático é **Automatic**.

*lpszOtherColor*<br/>
[em] O rótulo de texto do *outro* botão, que exibe mais opções de cores, ou NULL.

A etiqueta padrão para o outro botão é **Mais Cores...**.

*lpszDocCores*<br/>
[em] O rótulo de texto do botão de cores do documento. A paleta de cores do documento lista todas as cores que o documento usa atualmente.

*LstDocCores*<br/>
[em] Uma lista de cores que o documento usa atualmente.

*nColumns*<br/>
[em] O número de colunas que a matriz de cores tem.

*nHorzDockRows*<br/>
[em] O número de linhas que a barra de cores tem quando está ancorada horizontalmente.

*nVertDockColumns*<br/>
[em] O número de colunas que a barra de cores tem quando está encaixada verticalmente.

*corAutomático*<br/>
[em] A cor padrão que a estrutura se aplica quando você clica no botão automático.

*uiCommandID*<br/>
[em] O iD do comando de controle da barra de cores.

*bStdColorDlg*<br/>
[em] Um booleano que indica se deve mostrar a caixa de diálogo de cor padrão do sistema ou a caixa de diálogo [CMFCColorDialog.](../../mfc/reference/cmfccolordialog-class.md)

*pParentBtn*<br/>
[em] Um ponteiro para um botão pai.

*nID*<br/>
[em] O id de comando.

### <a name="remarks"></a>Comentários

Cada construtor sobrecarregado define `m_bEnabledInCustomizeMode` o membro como FALSO.

### <a name="example"></a>Exemplo

O exemplo a seguir `CMFCColorPopupMenu` demonstra como construir um objeto.

[!code-cpp[NVC_MFC_RibbonApp#34](../../mfc/reference/codesnippet/cpp/cmfccolorpopupmenu-class_1.cpp)]

## <a name="cmfccolorpopupmenucreatetearoffbar"></a><a name="createtearoffbar"></a>CMFCColorPopupMenu::CreateTearOffBar

Cria uma barra de cor de tear-off dockable.

```
virtual CPane* CreateTearOffBar(
    CFrameWnd* pWndMain,
    UINT uiID,
    LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pWndMain*|[em] Ponteiro para a janela dos pais da barra de rasgos.|
|*Uiid*|[em] O comando id da barra de rasgos.|
|*lpszName*|[em] O texto da janela da barra de rasgos.|

### <a name="return-value"></a>Valor retornado

Um ponteiro para o novo objeto da barra de controle de ruptura.

### <a name="remarks"></a>Comentários

Este método cria um objeto [CMFCColorBar Class](../../mfc/reference/cmfccolorbar-class.md) e o lança para um ponteiro [CPane Class.](../../mfc/reference/cpane-class.md) Você pode lançar esse valor de volta para um ponteiro [CMFCColorBar Class](../../mfc/reference/cmfccolorbar-class.md) usando uma das macros de fundição descritas no [Tipo de Casting de Objetos de Classe MFC](../../mfc/reference/type-casting-of-mfc-class-objects.md).

## <a name="cmfccolorpopupmenugetmenubar"></a><a name="getmenubar"></a>CMFCColorPopupMenu::GetMenuBar

Retorna a [BARRA CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) que está incorporada dentro do menu pop-up.

```
virtual CMFCPopupMenuBar* GetMenuBar();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `CMFCPopupMenuBar`o incorporado .

### <a name="remarks"></a>Comentários

O menu pop-up de cores tem um objeto [CMFCPopupMenuBar Class](../../mfc/reference/cmfcpopupmenubar-class.md) incorporado. Anular este método em uma classe derivada se o aplicativo usar um tipo incorporado diferente.

## <a name="cmfccolorpopupmenusetproplist"></a><a name="setproplist"></a>CMFCColorPopupMenu::SetPropList

Define o objeto de controle `CMFCColorBar` da grade de propriedade do objeto incorporado.

```
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```

### <a name="parameters"></a>Parâmetros

*pWndList*<br/>
[em] Ponteiro para um objeto de controle da rede de propriedades.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
