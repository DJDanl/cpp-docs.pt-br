---
title: Classe CAutoHideDockSite
ms.date: 11/04/2016
f1_keywords:
- CAutoHideDockSite
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::CanAcceptPane
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::DockPane
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::GetAlignRect
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::RepositionPanes
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::SetOffsetLeft
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::SetOffsetRight
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::UnSetAutoHideMode
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::m_nExtraSpace
helpviewer_keywords:
- CAutoHideDockSite [MFC], CanAcceptPane
- CAutoHideDockSite [MFC], DockPane
- CAutoHideDockSite [MFC], GetAlignRect
- CAutoHideDockSite [MFC], RepositionPanes
- CAutoHideDockSite [MFC], SetOffsetLeft
- CAutoHideDockSite [MFC], SetOffsetRight
- CAutoHideDockSite [MFC], UnSetAutoHideMode
- CAutoHideDockSite [MFC], m_nExtraSpace
ms.assetid: 2a0f6bec-c369-4ab7-977d-564e7946ebad
ms.openlocfilehash: 2779e643b15179b0017535fbfbb144f94e1aedbe
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562006"
---
# <a name="cautohidedocksite-class"></a>Classe CAutoHideDockSite

O `CAutoHideDockSite` estende a [Classe CDockSite](../../mfc/reference/cdocksite-class.md) para implementar painéis de encaixe de ocultar automaticamente.

## <a name="syntax"></a>Sintaxe

```
class CAutoHideDockSite : public CDockSite
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CAutoHideDockSite::CAutoHideDockSite`|Constrói um objeto `CAutoHideDockSite`.|
|`CAutoHideDockSite::~CAutoHideDockSite`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|`CAutoHideDockSite::AllowShowOnPaneMenu`|Indica se o `CAutoHideDockSite` é mostrado no menu do painel.|
|[CAutoHideDockSite::CanAcceptPane](#canacceptpane)|Determina se um objeto de painel base é derivado da [classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md).|
|[CAutoHideDockSite::D ockPane](#dockpane)|Encaixa um painel neste `CAuotHideDockSite` objeto.|
|[CAutoHideDockSite::GetAlignRect](#getalignrect)|Recupera o tamanho do site de encaixe em coordenadas da tela.|
|[CAutoHideDockSite::RepositionPanes](#repositionpanes)|Redesenha o painel no `CAutoHideDockSite` com as margens globais e o espaçamento de botão.|
|[CAutoHideDockSite::SetOffsetLeft](#setoffsetleft)|Define a margem no lado esquerdo da barra de encaixe.|
|[CAutoHideDockSite::SetOffsetRight](#setoffsetright)|Define a margem no lado direito da barra de encaixe.|
|[CAutoHideDockSite::UnSetAutoHideMode](#unsetautohidemode)|Chama [CMFCAutoHideBar:: UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos no `CAutoHideDockSite` .|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|[CAutoHideDockSite:: m_nExtraSpace](#m_nextraspace)|Define o tamanho do espaço entre as barras de ferramentas e a borda da barra de encaixe. Esse espaço é medido a partir da borda esquerda ou da borda superior, dependendo do alinhamento do espaço de encaixe.|

## <a name="remarks"></a>Comentários

Quando você chama [CFrameWndEx:: EnableAutoHidePanes](../../mfc/reference/cframewndex-class.md#enableautohidepanes), a estrutura cria um `CAutoHideDockSite` objeto automaticamente. Na maioria dos casos, você não deve ter que instanciar ou usar essa classe diretamente.

A barra de encaixe é a lacuna entre o lado esquerdo do painel Dock e o lado esquerdo da [Classe CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CDockSite](../../mfc/reference/cdocksite-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar um `CAutoHideDockSite` objeto de um `CMFCAutoHideBar` objeto e como definir as margens esquerda e direita da barra de encaixe.

[!code-cpp[NVC_MFC_RibbonApp#29](../../mfc/reference/codesnippet/cpp/cautohidedocksite-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxautohidedocksite. h

## <a name="cautohidedocksitecanacceptpane"></a><a name="canacceptpane"></a> CAutoHideDockSite::CanAcceptPane

Determina se um painel base é um objeto [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) ou derivado de `CMFCAutoHideBar` .

```
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;
```

### <a name="parameters"></a>Parâmetros

*pBar*\
no O painel base que o Framework testa.

### <a name="return-value"></a>Valor retornado

TRUE se *pBar* for derivado de `CMFCAutoHideBar` ; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se um objeto do painel base for derivado de `CMFCAutoHideBar` , ele poderá conter um `CAutoHideDockSite` .

## <a name="cautohidedocksitedockpane"></a><a name="dockpane"></a> CAutoHideDockSite::D ockPane

Encaixa um painel neste objeto [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) .

```
virtual void DockPane(
    CPane* pWnd,
    AFX_DOCK_METHOD dockMethod,
    LPRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWnd*\
no O painel que a estrutura encaixa.

*dockMethod*\
no Opções de encaixe para o painel.

*lpRect*\
no Um retângulo que especifica os limites para o painel encaixado.

### <a name="remarks"></a>Comentários

A implementação padrão não usa o parâmetro *dockMethod*, que é fornecido para uso futuro.

Se *lpRect* for NULL, a estrutura colocará o painel no local padrão no site de encaixe. Se o site de encaixe for horizontal, o local padrão estará na extrema esquerda do site de encaixe. Caso contrário, o local padrão estará na parte superior do site de encaixe.

## <a name="cautohidedocksitegetalignrect"></a><a name="getalignrect"></a> CAutoHideDockSite::GetAlignRect

Recupera o tamanho do site de encaixe em coordenadas da tela.

```cpp
void GetAlignRect(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

*Rect*\
no Uma referência a um retângulo. O método armazena o tamanho do site de encaixe neste retângulo.

### <a name="remarks"></a>Comentários

O retângulo é ajustado para as margens de deslocamento para que elas não sejam incluídas.

## <a name="cautohidedocksitem_nextraspace"></a><a name="m_nextraspace"></a> CAutoHideDockSite:: m_nExtraSpace

O tamanho do espaço entre as bordas da [classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) e os objetos da [classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) .

```
static int m_nExtraSpace;
```

### <a name="remarks"></a>Comentários

Quando um `CMFCAutoHideBar` é encaixado em um `CAutoHideDockSite` , ele não deve ocupar o site de encaixe inteiro. Essa variável global controla o espaço extra entre a borda esquerda ou superior do `CMFCAutoHideBar` e a borda correspondente `CAutoHideDockSite` . Se a borda superior ou esquerda é usada depende do alinhamento atual.

## <a name="cautohidedocksitesetoffsetleft"></a><a name="setoffsetleft"></a> CAutoHideDockSite::SetOffsetLeft

Define a margem no lado esquerdo da barra de encaixe.

```cpp
void SetOffsetLeft(int nOffset);
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
no O novo deslocamento.

### <a name="remarks"></a>Comentários

Os objetos [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) são posicionados estaticamente no `CAutoHideDockSite` objeto. Isso significa que o usuário não pode alterar manualmente o local dos `CMFCAutoHideBar` objetos. O `SetOffsetLeft` método controla o espaçamento entre o lado esquerdo da extrema esquerda `CMFCAutoHideBar` e o lado esquerdo do `CAutoHideDockSite` .

## <a name="cautohidedocksitesetoffsetright"></a><a name="setoffsetright"></a> CAutoHideDockSite::SetOffsetRight

Define a margem no lado direito da barra de encaixe.

```cpp
void SetOffsetRight(int nOffset);
```

### <a name="parameters"></a>Parâmetros

*nOffset*<br/>
no O novo deslocamento.

### <a name="remarks"></a>Comentários

Os objetos [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) são posicionados estaticamente no `CAutoHideDockSite` objeto. Isso significa que o usuário não pode alterar manualmente o local dos `CMFCAutoHideBar` objetos. O `SetOffsetRight` método controla o espaçamento entre o lado direito da mais à direita `CMFCAutoHideBar` e o lado direito do `CAutoHideDockSite` .

## <a name="cautohidedocksiterepositionpanes"></a><a name="repositionpanes"></a> CAutoHideDockSite::RepositionPanes

Redesenha os painéis no [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md).

```
virtual void RepositionPanes(CRect& rectNewClientArea);
```

### <a name="parameters"></a>Parâmetros

*rectNewClientArea*\
no Um valor reservado.

### <a name="remarks"></a>Comentários

A implementação padrão não usa *rectNewClientArea*. Ele redesenha os painéis com as margens da barra de ferramentas global e o espaçamento do botão.

## <a name="cautohidedocksiteunsetautohidemode"></a><a name="unsetautohidemode"></a> CAutoHideDockSite::UnSetAutoHideMode

Chama [CMFCAutoHideBar:: UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos no site Dock.

```cpp
void UnSetAutoHideMode(CMFCAutoHideBar* pAutoHideToolbar);
```

### <a name="parameters"></a>Parâmetros

*pAutoHideToolbar*\
no Um ponteiro para um painel de objeto [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) localizado no `CAutoHideDockSite` .

### <a name="remarks"></a>Comentários

Esse método pesquisa a linha que contém *pAutoHideToolbar*. Ele chama `CMFCAutoHideBar.UnSetAutoHideMode` todos os `CMFCAutoHideBar` objetos nessa linha. Se *pAutoHideToolbar* não for encontrado ou for nulo, esse método chamará `CMFCAutoHideBar.UnSetAutoHideMode` todos os `CMFCAutoHideBar` objetos no `CAutoHideDockSite` .

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockSite](../../mfc/reference/cdocksite-class.md)
