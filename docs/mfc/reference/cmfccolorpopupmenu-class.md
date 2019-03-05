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
ms.openlocfilehash: 0c2fed4aa239faa96abf692a46a27102ce9820a1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283391"
---
# <a name="cmfccolorpopupmenu-class"></a>Classe CMFCColorPopupMenu

Representa um menu pop-up que os usuários usam para selecionar cores em um documento ou aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorPopupMenu : public CMFCPopupMenu
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCColorPopupMenu::CMFCColorPopupMenu](#cmfccolorpopupmenu)|Constrói um objeto `CMFCColorPopupMenu`.|
|`CMFCColorPopupMenu::~CMFCColorPopupMenu`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCColorPopupMenu::CreateTearOffBar](#createtearoffbar)|Cria uma barra de cores destacáveis encaixável. (Substitui [CMFCPopupMenu::CreateTearOffBar](../../mfc/reference/cmfcpopupmenu-class.md#createtearoffbar).)|
|[CMFCColorPopupMenu::GetMenuBar](#getmenubar)|Retorna o [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) que é incorporado dentro do menu pop-up. (Substitui [CMFCPopupMenu::GetMenuBar](../../mfc/reference/cmfcpopupmenu-class.md#getmenubar).)|
|`CMFCColorPopupMenu::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCColorPopupMenu::SetPropList](#setproplist)|Define o objeto de controle de grade de propriedade da inserido `CMFCColorBar` objeto.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|Nome|Descrição|
|`m_bEnabledInCustomizeMode`|Um valor booliano que determina se é mostrar a barra de cores.|
|`m_wndColorBar`|O `CMFCColorBar` objeto que fornece uma seleção de cor.|

### <a name="remarks"></a>Comentários

Essa classe herda a funcionalidade do menu pop-up do `CMFCPopupMenu` de classe e gerencia um `CMFCColorBar` objeto que fornece uma seleção de cor. Quando a estrutura da barra de ferramentas estiver no modo de personalização e a `m_bEnabledInCustomizeMode` membro é definido como FALSE, o objeto de barra de cores não é mostrado. Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)

Para obter mais informações sobre `CMFCColorBar`, consulte [classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)

[CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)

[CMFCColorPopupMenu](../../mfc/reference/cmfccolorpopupmenu-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorpopupmenu.h

##  <a name="cmfccolorpopupmenu"></a>  CMFCColorPopupMenu::CMFCColorPopupMenu

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
[in] Uma matriz de cores que o framework exibe no menu pop-up.

*color*<br/>
[in] A cor padrão selecionado.

*lpszAutoColor*<br/>
[in] O rótulo de texto a *automática* botão de cor (padrão), ou nulo.

O rótulo padrão do botão automático estiver **automática**.

*lpszOtherColor*<br/>
[in] O rótulo de texto a *outros* botão, que exibe mais opções de cores, ou nulo.

É o rótulo padrão para o outro botão **mais cores...** .

*lpszDocColors*<br/>
[in] O rótulo de texto do botão de cores do documento. A paleta de cores do documento lista todas as cores que atualmente usa o documento.

*lstDocColors*<br/>
[in] Uma lista de cores que atualmente usa o documento.

*nColumns*<br/>
[in] O número de colunas que tem a matriz de cores.

*nHorzDockRows*<br/>
[in] O número de linhas que a barra de cores tem quando ela estiver encaixada horizontalmente.

*nVertDockColumns*<br/>
[in] O número de colunas que a barra de cores tem quando ela estiver encaixada verticalmente.

*colorAutomatic*<br/>
[in] A cor padrão que a estrutura se aplica quando você clicar no botão automático.

*uiCommandID*<br/>
[in] ID do comando de controle de barra de cores.

*bStdColorDlg*<br/>
[in] Um valor booliano que indica se deve mostrar a caixa de diálogo de cor padrão do sistema ou o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo.

*pParentBtn*<br/>
[in] Um ponteiro para um botão de pai.

*nID*<br/>
[in] A ID de comando.

### <a name="remarks"></a>Comentários

Cada sobrecarregado construtor define o `m_bEnabledInCustomizeMode` membro como FALSE.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCColorPopupMenu` objeto.

[!code-cpp[NVC_MFC_RibbonApp#34](../../mfc/reference/codesnippet/cpp/cmfccolorpopupmenu-class_1.cpp)]

##  <a name="createtearoffbar"></a>  CMFCColorPopupMenu::CreateTearOffBar

Cria uma barra de cores destacáveis encaixável.

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
|*pWndMain*|[in] Ponteiro para a janela pai da barra destacável.|
|*uiID*|[in] A ID de comando da barra destacável.|
|*lpszName*|[in] O texto da janela da barra destacável.|

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o novo objeto barra destacável controle.

### <a name="remarks"></a>Comentários

Esse método cria uma [classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) do objeto e a converte para um [classe CPane](../../mfc/reference/cpane-class.md) ponteiro. Você pode converter esse valor para um [classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) ponteiro usando uma das macros de conversão descritas em [tipo de conversão de objetos de classe MFC](../../mfc/reference/type-casting-of-mfc-class-objects.md).

##  <a name="getmenubar"></a>  CMFCColorPopupMenu::GetMenuBar

Retorna o [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) que é incorporado dentro do menu pop-up.

```
virtual CMFCPopupMenuBar* GetMenuBar();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o embedded `CMFCPopupMenuBar`.

### <a name="remarks"></a>Comentários

No menu pop-up de cor tem inserida [classe CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md) objeto. Substitua este método em uma classe derivada, se seu aplicativo usa um tipo diferente de inserido.

##  <a name="setproplist"></a>  CMFCColorPopupMenu::SetPropList

Define o objeto de controle de grade de propriedade da inserido `CMFCColorBar` objeto.

```
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```

### <a name="parameters"></a>Parâmetros

*pWndList*<br/>
[in] Ponteiro para um objeto de controle de grade de propriedade.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
