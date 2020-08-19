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
ms.openlocfilehash: d668a7bd2b5226de906ca146c7b7e882b97f4640
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88560979"
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
|[CMFCColorPopupMenu::CMFCColorPopupMenu](#cmfccolorpopupmenu)|Constrói um objeto `CMFCColorPopupMenu`.|
|`CMFCColorPopupMenu::~CMFCColorPopupMenu`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCColorPopupMenu::CreateTearOffBar](#createtearoffbar)|Cria uma barra de cores de encaixáveis. (Substitui [CMFCPopupMenu:: CreateTearOffBar](../../mfc/reference/cmfcpopupmenu-class.md#createtearoffbar).)|
|[CMFCColorPopupMenu:: GetMenuBar](#getmenubar)|Retorna o [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) inserido no menu pop-up. (Substitui [CMFCPopupMenu:: GetMenuBar](../../mfc/reference/cmfcpopupmenu-class.md#getmenubar).)|
|`CMFCColorPopupMenu::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCColorPopupMenu:: setproplist](#setproplist)|Define o objeto de controle de grade de Propriedade do `CMFCColorBar` objeto inserido.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|`m_bEnabledInCustomizeMode`|Um valor booliano que determina se a barra de cores deve ser mostrada.|
|`m_wndColorBar`|O `CMFCColorBar` objeto que fornece seleção de cores.|

### <a name="remarks"></a>Comentários

Essa classe herda a funcionalidade do menu pop-up da `CMFCPopupMenu` classe e gerencia um `CMFCColorBar` objeto que fornece seleção de cores. Quando a estrutura da barra de ferramentas está no modo de personalização e o `m_bEnabledInCustomizeMode` membro é definido como false, o objeto de barra de cores não é mostrado. Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar:: Iscustommode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)

Para obter mais informações sobre `CMFCColorBar` , consulte [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)

[CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)

[CMFCColorPopupMenu](../../mfc/reference/cmfccolorpopupmenu-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorpopupmenu. h

## <a name="cmfccolorpopupmenucmfccolorpopupmenu"></a><a name="cmfccolorpopupmenu"></a> CMFCColorPopupMenu::CMFCColorPopupMenu

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

*cores*<br/>
no Uma matriz de cores que a estrutura exibe no menu pop-up.

*color*<br/>
no A cor selecionada padrão.

*lpszAutoColor*<br/>
no O rótulo de texto do botão de cor *automático* (padrão) ou NULL.

O rótulo padrão do botão automático é **automático**.

*lpszOtherColor*<br/>
no O rótulo de texto do *outro* botão, que exibe mais opções de cor ou nulo.

O rótulo padrão para o outro botão é **mais cores...**

*lpszDocColors*<br/>
no O rótulo de texto do botão cores do documento. A paleta cores do documento lista todas as cores que o documento usa atualmente.

*lstDocColors*<br/>
no Uma lista de cores que o documento usa atualmente.

*nColumns*<br/>
no O número de colunas que a matriz de cores tem.

*nHorzDockRows*<br/>
no O número de linhas que a barra de cores tem quando é encaixada horizontalmente.

*nVertDockColumns*<br/>
no O número de colunas que a barra de cores tem quando é encaixada verticalmente.

*colorAutomatic*<br/>
no A cor padrão que a estrutura aplica quando você clica no botão automático.

*uiCommandID*<br/>
no A ID do comando de controle da barra de cores.

*bStdColorDlg*<br/>
no Um booliano que indica se a caixa de diálogo de cores do sistema padrão ou a caixa de diálogo [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) deve ser mostrada.

*pParentBtn*<br/>
no Um ponteiro para um botão pai.

*nID*<br/>
no A ID do comando.

### <a name="remarks"></a>Comentários

Cada construtor sobrecarregado define o `m_bEnabledInCustomizeMode` membro como false.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCColorPopupMenu` objeto.

[!code-cpp[NVC_MFC_RibbonApp#34](../../mfc/reference/codesnippet/cpp/cmfccolorpopupmenu-class_1.cpp)]

## <a name="cmfccolorpopupmenucreatetearoffbar"></a><a name="createtearoffbar"></a> CMFCColorPopupMenu::CreateTearOffBar

Cria uma barra de cores de encaixáveis.

```
virtual CPane* CreateTearOffBar(
    CFrameWnd* pWndMain,
    UINT uiID,
    LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*pWndMain*\
no Ponteiro para a janela pai da barra de desfazer.

*uiID*\
no A ID de comando da barra de desfazer.

*lpszName*\
no O texto da janela da barra de desfazer.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o novo objeto de barra de controle destacável.

### <a name="remarks"></a>Comentários

Esse método cria um objeto de [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) e o converte em um ponteiro de [Classe CPane](../../mfc/reference/cpane-class.md) . Você pode converter esse valor de volta em um ponteiro de [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) usando uma das macros de conversão descritas em [tipo de conversão de objetos de classe MFC](../../mfc/reference/type-casting-of-mfc-class-objects.md).

## <a name="cmfccolorpopupmenugetmenubar"></a><a name="getmenubar"></a> CMFCColorPopupMenu:: GetMenuBar

Retorna o [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) inserido no menu pop-up.

```
virtual CMFCPopupMenuBar* GetMenuBar();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o inserido `CMFCPopupMenuBar` .

### <a name="remarks"></a>Comentários

O menu pop-up cor tem um objeto de [classe CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) inserido. Substitua esse método em uma classe derivada se seu aplicativo usar um tipo inserido diferente.

## <a name="cmfccolorpopupmenusetproplist"></a><a name="setproplist"></a> CMFCColorPopupMenu:: setproplist

Define o objeto de controle de grade de Propriedade do `CMFCColorBar` objeto inserido.

```cpp
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```

### <a name="parameters"></a>Parâmetros

*pWndList*<br/>
no Ponteiro para um objeto de controle de grade de propriedade.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
